#include "stdafx.h"
#include "EntityManager.h"

//-----------------------------------------------------------------------------
Entity EntityManager::AddEntity()
{
	static size_t entityCounter = 0;

	m_entities[++entityCounter] = std::make_pair(
		true,
		std::make_unique<ComponentCollection>()
	);

	return entityCounter;
}
//-----------------------------------------------------------------------------
void EntityManager::RemoveEntity(Entity entity)
{
	m_entities.erase(entity);
}
//-----------------------------------------------------------------------------
bool EntityManager::IsEntityEnabled(Entity entity) const
{
	const auto&[enabled, _] = findEntity(entity);

	return enabled;
}
//-----------------------------------------------------------------------------
void EntityManager::EnableEntity(Entity entity, bool enable)
{
	std::get<0>(findEntity(entity)) = enable;
}
//-----------------------------------------------------------------------------
ComponentCollection& EntityManager::GetEntity(Entity entity) const
{
	auto&[_, components] = findEntity(entity);

	return *components;
}
//-----------------------------------------------------------------------------
std::pair<bool, std::unique_ptr<ComponentCollection>>& EntityManager::findEntity(Entity entity)
{
	return findEntity(*this, entity);
}
//-----------------------------------------------------------------------------
const std::pair<bool, std::unique_ptr<ComponentCollection>>& EntityManager::findEntity(Entity entity) const
{
	return findEntity(*this, entity);
}
//-----------------------------------------------------------------------------