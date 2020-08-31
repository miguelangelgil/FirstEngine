#include "headers\Player.hpp"

Player::Player(Scene& my_scene, Vector3 coord, Vector3 rotation, Vector3 scale)
    :
    Entities_In_Game_Update(),
    player("player",&my_scene, coord, rotation, scale),
    model_component(new Model_Component(&player, "..\\..\\sources\\models\\bunny.obj")),
    input_component(new Input_Component(&player)),
    control_component(new Control_Component(&player))
{
    speed = 1.1f;
    player.add_component("model", model_component);
    player.add_component("input", input_component);
    player.add_component("control", control_component);



}

void Player::Update(double deltaTime)
{

    /*if (player.get_scene()->get_input()->get_SDLKey(ARROW_UP)) {

        player.get_scene()->get_message_handle()->multicast(move_Up);
        Enviar mensaje de mover a arriba
    }
    else if (player.get_scene()->get_input()->get_SDLKey(ARROW_DOWN)) {


        player.get_scene()->get_message_handle()->multicast(move_Down);
        Enviar mensaje de mover a abajo
    }
    else if (player.get_scene()->get_input()->get_SDLKey(ARROW_LEFT)) {


        player.get_scene()->get_message_handle()->multicast(move_Left);
        Enviar mensaje de mover a la izquierda
    }
    else if (player.get_scene()->get_input()->get_SDLKey(ARROW_RIGHT)) {


        player.get_scene()->get_message_handle()->multicast(move_Right);
        Enviar mensaje de mover a la derecha
    }*/
}

Entity* Player::get_entity()
{
    return &player;
}

ID Player::get_id()
{
    return id;
}

void Player::set_id(ID id)
{
    this->id = id;
}
