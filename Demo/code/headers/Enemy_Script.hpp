#pragma once
#include <MEngine.h>

using namespace engine;

class Enemy_Script : public Script_Component 
{
private:
    //componentes de modelo de los enemigos
    component model_component;
    // component collider
    component collider;
    //posicion iniciales
    Vector3 init_position;
public:

    Enemy_Script(Entity * parent);

    // Heredado vía Script_Component
    virtual void Start() override;
    virtual void Update(float deltaTime) override;
    virtual void OnCollision(Entity* other, COLLISION_STATE state) override;
};