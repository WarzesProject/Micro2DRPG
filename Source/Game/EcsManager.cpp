#include "stdafx.h"
#include "EcsManager.h"

//-----------------------------------------------------------------------------
EcsManager::EcsManager() 
	: m_entityManager{ std::make_unique<EntityManager>() }
	, m_systemManager{ std::make_unique<SystemManager>(*m_entityManager) }
{
	valid() = true;
}
//-----------------------------------------------------------------------------
void EcsManager::Frame(float delta)
{
	m_systemManager->Frame(delta);
}
//-----------------------------------------------------------------------------