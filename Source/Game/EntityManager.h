#pragma once

#include "ComponentCollection.h"

using Entity = size_t;

class EntityManager
{
public:
	Entity AddEntity();
	void RemoveEntity(Entity entity);
	bool IsEntityEnabled(Entity entity) const;
	void EnableEntity(Entity entity, bool enable);
	ComponentCollection& GetEntity(Entity entity) const;

	template<typename TComponent, typename ...Args>
	TComponent* AddComponent(Entity entity, Args&& ...args);

	template<typename TComponent>
	TComponent* GetComponent(Entity entity) const;

	template<typename TComponent>
	bool HasComponent(Entity entity);

	template<typename TComponent>
	void EnableComponent(Entity entity, bool enable);

private:
	std::pair<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity entity);
	const std::pair<bool, std::unique_ptr<ComponentCollection>>& findEntity(Entity entity) const;

	template<typename T>
	static auto findEntity(T& t, Entity entity) -> decltype(t.findEntity(entity));

	std::map<Entity, std::pair<bool, std::unique_ptr<ComponentCollection>>> m_entities;
};

template<typename TComponent, typename ...Args>
TComponent* EntityManager::AddComponent(Entity entity, Args&& ...args)
{
	auto&[_, components] = findEntity(entity);

	return components->Add<TComponent>(std::forward<Args>(args)...);
}

template<typename TComponent>
TComponent* EntityManager::GetComponent(Entity entity) const
{
	auto&[_, components] = findEntity(entity);

	return components->Get<TComponent>();
}

template<typename TComponent>
bool EntityManager::HasComponent(Entity entity)
{
	auto&[_, components] = findEntity(entity);

	return components->Any<TComponent>();
}

template<typename TComponent>
void EntityManager::EnableComponent(Entity entity, bool enable)
{
	auto&[_, components] = findEntity(entity);

	components->Enable<TComponent>(enable);
}

template<typename T>
auto EntityManager::findEntity(T& t, Entity entity) -> decltype(t.findEntity(entity))
{
	auto it = t.m_entities.find(entity);
	if (it == t.m_entities.end())
		throw std::runtime_error("Entity does not exist: " + std::to_string(entity));

	return it->second;
}