#include "headers\Player_Script.hpp"

Player_Script::Player_Script(Entity* parent)
    : Script_Component(parent), model_component(new Model_Component(parent, "..\\..\\sources\\models\\bunny.obj")), input_component(new Input_Component(parent)),
    control_component(new Control_Component(parent)), collider_player(new Sphere_Collider_Component(parent, 1.f)), audio_choque_component(new Sound_Component(parent, "..\\..\\sources\\sound\\choque.mp3"))
{
    parent->add_component("model", model_component);
    parent->add_component("input", input_component);
    parent->add_component("control", control_component);
    parent->add_component("collider", collider_player);
    parent->add_component("choque_sound", audio_choque_component);
}

void Player_Script::Start()
{
    init_position = static_cast<Vector3>(*dynamic_cast<Transform_Component*>(parent->get_component("transform").get())->get_position());
}

void Player_Script::Update(float deltaTime)
{

}

void Player_Script::OnCollision(Entity* other, COLLISION_STATE state)
{
    if (state == COLLISION_STATE::ON_COLLISION_ENTER) 
    {
        dynamic_cast<Sound_Component*>(audio_choque_component.get())->play(100, 1);
        
    }
}
