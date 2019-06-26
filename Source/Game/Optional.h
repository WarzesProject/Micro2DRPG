#pragma once

#include <optional>

template<typename T>
using Optional = std::optional<T>;

using BadOptionalAccess = std::bad_optional_access;

constexpr std::nullopt_t NullOpt = std::nullopt;