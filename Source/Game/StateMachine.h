#pragma once

#include "State.h"

class StateMachine
{
public:
	~StateMachine();

	void Start();
	void Frame(float delta);

	template<typename TState, typename ...Args>
	void AddState(Args&& ...args);

	template<typename TState>
	void GoToState();

private:
	size_t m_firstStateTypeId{ 0 };
	State *m_currentState{ nullptr };

	std::unordered_map<size_t, std::unique_ptr<State>> m_states;
};

template<typename TState, typename ...Args>
void StateMachine::AddState(Args&& ...args)
{
	static_assert(std::is_base_of<State, TState>::value);

	const auto typeId = GET_TYPE_ID(TState);
	if (m_states.find(typeId) != m_states.end())
		throw std::runtime_error("State already exists: " + std::string(GET_TYPE_NAME(TState)));

	m_states[typeId] = std::make_unique<TState>(*this, std::forward<Args>(args)...);

	if (1 == m_states.size())
		m_firstStateTypeId = typeId;
}

template<typename TState>
void StateMachine::GoToState()
{
	static_assert(std::is_base_of<State, TState>::value);

	const auto typeId = GET_TYPE_ID(TState);
	const auto it = m_states.find(typeId);
	if (it == m_states.end())
		throw std::runtime_error("State does not exist: " + std::string(GET_TYPE_NAME(TState)));

	m_currentState->Exit();
	m_currentState = it->second.get();
	m_currentState->Enter();
}