#pragma once

#include <iostream>
#include <bitset>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 10;

using ComponentType = std::uint32_t;
const ComponentType MAX_COMPONENTS = 10;

using Signature = std::bitset<MAX_COMPONENTS>;

