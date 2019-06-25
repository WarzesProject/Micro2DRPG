#include "stdafx.h"
#include "SystemManager.h"

//-----------------------------------------------------------------------------
SystemManager::SystemManager(const EntityManager& entityManager)
	: m_entityManager{ entityManager }
{
}
//-----------------------------------------------------------------------------
void SystemManager::AddEntity(Entity entity)
{
	auto& components = m_entityManager.GetEntity(entity);

	const auto lambda = [&](System &system)
	{
		system.addEntity(entity, components);
	};

	m_systems.Apply(lambda);
}
//-----------------------------------------------------------------------------
void SystemManager::RemoveEntity(Entity entity, bool checkComponents)
{
	const auto lambda = [&](System &system)
	{
		system.removeEntity(entity, checkComponents);
	};

	m_systems.Apply(lambda);
}
//-----------------------------------------------------------------------------
void SystemManager::Frame(float delta)
{
	const auto lambda = [&delta](System &system)
	{
		system.frame(delta);
		system.clean();
	};

	m_systems.Apply(lambda);
}
//-----------------------------------------------------------------------------