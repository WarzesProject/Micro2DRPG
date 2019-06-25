#pragma once

#include "System.h"
#include "HeterogeneousCollection.h"

class SystemManager
{
public:
	SystemManager() = delete;
	explicit SystemManager(const EntityManager& entityManager);
	~SystemManager() = default;

	template<typename TSystem, typename ...Args>
	void AddSystem(Args&& ...args);

	template<typename TSystem>
	TSystem* GetSystem();

	template<typename TSystem>
	void EnableSystem(bool enable);

	void AddEntity(Entity entity);
	void RemoveEntity(Entity entity, bool checkComponents);

	void Frame(float delta);

private:
	const EntityManager& m_entityManager;

	OrderedHeterogeneousCollection<System> m_systems;
};

template<typename TSystem, typename ...Args>
void SystemManager::AddSystem(Args&& ...args)
{
	m_systems.Add<TSystem>(std::forward<Args>(args)...);
}

template<typename TSystem>
TSystem *SystemManager::GetSystem()
{
	return m_systems.Get<TSystem>();
}

template<typename TSystem>
void SystemManager::EnableSystem(bool enable)
{
	m_systems.Enable<TSystem>(enable);
}