#pragma once

class StateMachine;

class State : NonCopyable
{
public:
	State() = delete;
	explicit State(StateMachine &stateMachine) : m_stateMachine{ stateMachine }{}
	virtual ~State() = default;

	virtual void Enter(){}
	virtual void Frame(float){}
	virtual void Exit(){}

protected:
	StateMachine& stateMachine() const
	{
		return m_stateMachine;
	}

private:
	StateMachine &m_stateMachine;
};