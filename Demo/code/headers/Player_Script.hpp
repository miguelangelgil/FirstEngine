#pragma once
#include <MEngine.h>

using namespace engine;

class Player_Script : public Script_Component 
{
private:
    typedef shared_ptr <Component> component;
    Vector3 init_position;
private:
    //componente de modelo del jugador
    component model_component;
    //componente de input
    component input_component;
    //componente de control del jugador
    component control_component;
    //componentes de colision del jugador y los enemigos
    component collider_player;
    //componente de audio para el jugador
    component audio_choque_component;
public:
    Player_Script(Entity* parent);

    // Heredado vía Script_Component
    virtual void Start() override;
    virtual void Update(float deltaTime) override;
    virtual void OnCollision(Entity* other, COLLISION_STATE state) override;
};