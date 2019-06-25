#include "stdafx.h"
#include "StateMachine.h"

//-----------------------------------------------------------------------------
StateMachine::~StateMachine()
{
	if (nullptr != m_currentState)
	{
		m_currentState->Exit();
	}
}
//-----------------------------------------------------------------------------
void StateMachine::Start()
{
	if (m_states.empty())
		throw std::runtime_error("No state defined");

	m_currentState = m_states[m_firstStateTypeId].get();
	m_currentState->Enter();
}
//-----------------------------------------------------------------------------
void StateMachine::Frame(float delta)
{
	m_currentState->Frame(delta);
}
//-----------------------------------------------------------------------------