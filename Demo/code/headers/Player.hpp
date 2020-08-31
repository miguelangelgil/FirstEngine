#pragma once
#include<MEngine.h>
using namespace engine;
using namespace glt;
class Player : Entities_In_Game_Update
{
private:
    typedef shared_ptr <Component> component;
    ID id;
    Entity player;
    float speed;
    component model_component;
    component input_component;
    component control_component;
 
public:
    Player(Scene& my_scene, Vector3 coord, Vector3 rotation, Vector3 scale);
    void Update(double deltaTime) override;
   
    Entity* get_entity();

    ID get_id();

    void set_id(ID id);

  
};
