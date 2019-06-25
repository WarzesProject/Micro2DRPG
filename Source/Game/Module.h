#pragma once

#include "NonCopyable.h"

template <typename T>
class Module : NonCopyable
{
public:
	template<class ...Args>
	static bool Create(Args&& ...args)
	{
		if (IsValid())
			throw std::runtime_error("Trying to create an already created Module.");

		instance() = new T(std::forward<Args>(args)...);
		return IsValid();
	}

	static void Destroy()
	{
		delete instance(); instance() = nullptr;
		valid() = false;
	}

	static T& Get()
	{
		if (!IsValid())
			throw std::runtime_error("Trying to access a Module but it hasn't been created up yet.");

		return *instance();
	}

	static const bool IsValid()
	{
		return valid();
	}

protected:
	Module() = default;
	~Module() = default;

	static T*& instance()
	{
		static T *inst = nullptr;
		return inst;
	}

	static bool& valid()
	{
		static bool inst = false;
		return inst;
	}
};

template <typename T>
T& GetModule()
{
	return T::Get();
}