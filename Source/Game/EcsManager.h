#pragma once

#include "EntityManager.h"
#include "SystemManager.h"

class EcsManager : public Module<EcsManager>
{
public:
	EcsManager();

	void Frame(float delta);

private:
	std::unique_ptr<EntityManager> m_entityManager;
	std::unique_ptr<SystemManager> m_systemManager;
};
