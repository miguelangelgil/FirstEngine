#include "headers\Component.hpp"
#include "headers\Entity.hpp"

engine::Component::Component(Entity* parent) : parent(parent)
{
}

engine::Component::~Component()
{
}
