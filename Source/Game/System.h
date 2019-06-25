#pragma once

#include "EntityManager.h"
#include "OrderedHeterogeneousCollection.h"

enum class SystemOrder
{
	Motion = 10000,
	MouseEventTrigger = 20000,
	AABBCollision = 30000,
	SpriteRender = 40000,
	SpriteDebug = 40001,
	TextRender = 50000,
	TextDebug = 50001,
	FramerateDebug = 60000,
};

class System : public OrderableItem
{
	friend class SystemManager;
public:
	System() = default;
	virtual ~System() = default;

protected:
	inline const auto& entities()
	{
		return m_entities;
	}

	void sort(
		std::function<bool(
			std::pair<Entity, ComponentCollection *>,
			std::pair<Entity, ComponentCollection *>
			)> comparison
	);

private:
	enum class EntityStatus
	{
		Enabled = 1,
		ToRemove = 2,
	};

	virtual void frame(float delta) = 0;
	virtual bool hasRequiredComponents(ComponentCollection& components) const = 0;

	void addEntity(Entity entity, ComponentCollection& components);
	void removeEntity(Entity entity, bool checkComponents);
	bool doesEntityExists(Entity entity) const;

	void clean();

	std::list<std::pair<Entity, ComponentCollection *>> m_entities{};
	std::unordered_map<Entity, EntityStatus> m_entityStatuses{};
};
