#include "Enemy_Script.hpp"

Enemy_Script::Enemy_Script(Entity* parent) 
    : Script_Component(parent), model_component(new Model_Component(parent, "..\\..\\sources\\models\\cube.obj")), collider(new Sphere_Collider_Component(parent, 1.f))
{
    parent->add_component("model", model_component);
    parent->add_component("collider", collider);
}

void Enemy_Script::Start()
{
    init_position = static_cast<Vector3>(*dynamic_cast<Transform_Component*>(parent->get_component("transform").get())->get_position());
}

void Enemy_Script::Update(float deltaTime)
{
}

void Enemy_Script::OnCollision(Entity* other, COLLISION_STATE state)
{
}
