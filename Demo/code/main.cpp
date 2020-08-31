// Author: Miguel Ángel Gil Martín
// © Copyright (C) 2019  Miguel Ángel Gil Martín (MAGM_a)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
#pragma once
#include <MEngine.h>
using namespace engine;
using namespace glt;


int main()
{
    typedef shared_ptr <Component> component;
    //Se crea la ventana
    Window m_window("MAGMA", 1000, 800);
    //Se crea la escena
    Scene my_scene(m_window);
    //Coordenadas, scala y rotación de los elementos de la escena
    Vector3 coord = { 0.0f,0.0f,0.0f };
    Vector3 scale = { 1.0f,1.0f,1.0f };
    Vector3 camera_coord = { 0.0,0,10.0f };
    Vector3 light_coord = { 2.0,3.0,5.0f };
    Vector3 enemy1_coord = { -3.0,3.0,0.0f };
    Vector3 enemy2_coord = { 3.0,3.0,0.0f };
    Vector3 enemy3_coord = { 3.0,-3.0,0.0f };
    Vector3 enemy4_coord = { -3.0,-3.0,0.0f };
    //Entidades de la escena
    Entity player("player", &my_scene, coord, coord, scale);
    Entity camera("camera", &my_scene, camera_coord, coord, scale);
    Entity light("light", &my_scene, light_coord, coord, scale);
    Entity enemy1("enemy1", &my_scene,enemy1_coord, coord, scale);
    Entity enemy2("enemy2", &my_scene,enemy2_coord, coord, scale);
    Entity enemy3("enemy3", &my_scene,enemy3_coord, coord, scale);
    Entity enemy4("enemy4", &my_scene,enemy4_coord, coord, scale);

    //Componente de camara
    component camera_component(new Camera_Component(&camera));
    //componente de luz
    component light_component(new Light_Component(&light));
    //componente de modelo del jugador
    component model_component(new Model_Component(&player, "..\\..\\sources\\models\\head.obj"));
    //componente de input
    component input_component(new Input_Component(&player));
    //componente de control del jugador
    component control_component(new Control_Component(&player));

    //Componentes de IA de los enemigos
    component ia1_component(new IA_Component(&player, &enemy1));
    component ia2_component(new IA_Component(&player, &enemy2));
    component ia3_component(new IA_Component(&player, &enemy3));
    component ia4_component(new IA_Component(&player, &enemy4));

    //componentes de modelo de los enemigos
    component model1_ia_component(new Model_Component(&enemy1, "..\\..\\sources\\models\\bunny.obj"));
    component model2_ia_component(new Model_Component(&enemy2, "..\\..\\sources\\models\\bunny.obj"));
    component model3_ia_component(new Model_Component(&enemy3, "..\\..\\sources\\models\\bunny.obj"));
    component model4_ia_component(new Model_Component(&enemy4, "..\\..\\sources\\models\\bunny.obj"));

    //componentes de colision del jugador y los enemigos
    component collider_player(new Sphere_Collider_Component(&player, 1.f));
    component collider_enemy1(new Sphere_Collider_Component(&enemy1, 1.f));
    component collider_enemy2(new Sphere_Collider_Component(&enemy2, 1.f));
    component collider_enemy3(new Sphere_Collider_Component(&enemy3, 1.f));
    component collider_enemy4(new Sphere_Collider_Component(&enemy4, 1.f));

    //componente de audio para el jugador
    component audio_choque_component(new Sound_Component(&player, "..\\..\\sources\\sound\\choque.mp3"));

   //se añaden los componentes a la entidad de luz
    light.add_component("light", light_component);

    //se le añaden los componentes a la entidad de camara
    camera.add_component("camera", camera_component);

    //se le añande los componentes al player
    player.add_component("model", model_component);
    player.add_component("input", input_component);
    player.add_component("control", control_component);
    player.add_component("collider", collider_player);
    player.add_component("choque_sound", audio_choque_component);

    //se le añaden los diferentes componentes a los enemigos
    enemy1.add_component("ia", ia1_component);
    enemy2.add_component("ia", ia2_component);
    enemy3.add_component("ia", ia3_component);
    enemy4.add_component("ia", ia4_component);

    enemy1.add_component("model_ia", model1_ia_component);
    enemy2.add_component("model_ia", model2_ia_component);
    enemy3.add_component("model_ia", model3_ia_component);
    enemy4.add_component("model_ia", model4_ia_component);
    
    enemy1.add_component("collider", collider_enemy1);
    enemy2.add_component("collider", collider_enemy2);
    enemy3.add_component("collider", collider_enemy3);
    enemy4.add_component("collider", collider_enemy4);
    
    //se añaden todas las entidades creadas a la escena
    my_scene.add_entity(camera);
    my_scene.add_entity(light);
    my_scene.add_entity(player);

    my_scene.add_entity(enemy1);
    my_scene.add_entity(enemy2);
    my_scene.add_entity(enemy3);
    my_scene.add_entity(enemy4);
   
    //se arranca la escena
    my_scene.run();

   
    return 0;
}