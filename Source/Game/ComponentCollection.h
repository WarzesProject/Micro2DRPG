#pragma once

#include "Component.h"
#include "HeterogeneousCollection.h"

class ComponentCollection
{
public:
	template<typename TComponent, typename ...Args>
	TComponent* Add(Args&& ...args);

	template<typename TComponent>
	TComponent* Get() const;

	template<typename TComponent>
	bool Any() const;

	template<typename TComponent>
	void Enable(bool enable);

private:
	HeterogeneousCollection<Component> m_components;
};

template<typename TComponent, typename ...Args>
TComponent* ComponentCollection::Add(Args&& ...args)
{
	return m_components.Add<TComponent>(std::forward<Args>(args)...);
}

template<typename TComponent>
TComponent* ComponentCollection::Get() const
{
	return m_components.Get<TComponent>();
}

template<typename TComponent>
bool ComponentCollection::Any() const
{
	return m_components.Any<TComponent>();
}

template<typename TComponent>
void ComponentCollection::Enable(bool enable)
{
	m_components.Enable<TComponent>(enable);
}