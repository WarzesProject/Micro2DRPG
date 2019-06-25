#pragma once

template<typename TBase>
class HeterogeneousCollection
{
public:
	template<typename TItem>
	TItem* Get() const;

	template<typename TItem>
	bool Any() const;

	template<typename TItem, typename ...Args>
	TItem* Add(Args&& ...args);

	template<typename TItem>
	void Remove();

	template<typename TItem>
	void Enable(bool enable);

	template<typename TFunction>
	void Apply(TFunction function);

private:
	template<typename TItem>
	std::pair<bool, std::unique_ptr<TBase>>& find();

	template<typename TItem>
	const std::pair<bool, std::unique_ptr<TBase>>& find() const;

	std::unordered_map<size_t, std::pair<bool, std::unique_ptr<TBase>>> m_collection;
};

template<typename TBase>
template<typename TItem>
TItem* HeterogeneousCollection<TBase>::Get() const
{
	static_assert(std::is_base_of<TBase, TItem>::value);

	const auto&[enabled, item] = find<TItem>();
	if (!enabled)
		throw std::runtime_error(std::string("Item is disabled: ") + std::string(GET_TYPE_NAME(TItem)));

	return dynamic_cast<TItem*>(item.get());
}

template<typename TBase>
template<typename TItem>
bool HeterogeneousCollection<TBase>::Any() const
{
	static_assert(std::is_base_of<TBase, TItem>::value);

	const auto typeId = GET_TYPE_ID(TItem);
	const auto it = m_collection.find(typeId);

	return it != m_collection.end() && it->second.first;
}

template<typename TBase>
template<typename TItem, typename ...Args>
TItem *HeterogeneousCollection<TBase>::Add(Args&& ...args)
{
	static_assert(std::is_base_of<TBase, TItem>::value);

	if (Any<TItem>())
		throw std::runtime_error(std::string("Item already exists: ") + std::string(GET_TYPE_NAME(TItem)));

	const auto typeId = GET_TYPE_ID(TItem);

	m_collection[typeId] = std::make_tuple(
		true,
		std::make_unique<TItem>(std::forward<Args>(args)...)
	);

	return get<TItem>();
}

template<typename TBase>
template<typename TItem>
void HeterogeneousCollection<TBase>::Remove()
{
	static_assert(std::is_base_of<TBase, TItem>::value);
	const auto typeId = GET_TYPE_ID(TItem);
	m_collection.erase(typeId);
}

template<typename TBase>
template<typename TItem>
void HeterogeneousCollection<TBase>::Enable(bool enable)
{
	static_assert(std::is_base_of<TBase, TItem>::value);
	auto& pair = find<TItem>();
	pair.first = enable;
}

template<typename TBase>
template<typename TFunction>
void HeterogeneousCollection<TBase>::Apply(TFunction function)
{
	for (auto&[type, item] : m_collection)
	{
		auto&[enabled, value] = item;

		if (!enabled)
			continue;

		function(value);
	}
}

template<typename TBase>
template<typename TItem>
std::pair<bool, std::unique_ptr<TBase>>& HeterogeneousCollection<TBase>::find()
{
	const auto typeId = GET_TYPE_ID(TItem);
	const auto it = m_collection.find(typeId);

	if (it == m_collection.end())
		throw std::runtime_error(std::string("Item does not exist: ") + std::string(GET_TYPE_NAME(TItem)));

	return it->second;
}

template<typename TBase>
template<typename TItem>
const std::pair<bool, std::unique_ptr<TBase>>& HeterogeneousCollection<TBase>::find() const
{
	const auto typeId = GET_TYPE_ID(TItem);
	const auto it = m_collection.find(typeId);

	if (it == m_collection.end())
		throw std::runtime_error(std::string("Item does not exist: ") + std::string(GET_TYPE_NAME(TItem)));

	return it->second;
}