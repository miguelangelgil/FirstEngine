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
#include <Player_Script.hpp>
#include <Enemy_Script.hpp>
using namespace engine;
using namespace glt;

int main()
{
    //Se crea la ventana
    Window m_window("MAGMA", 1000, 800);
    //Se crea la escena
    Scene my_scene(m_window);
   
    //Entidades de la escena
    Entity player("player", &my_scene,  Vector3(0.0f,0.0f,0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f));
    Entity camera("camera", &my_scene,  Vector3(0.0f, 0.0f, 10.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f));
    Entity light("light", &my_scene,    Vector3(2.0f, 3.0f, 5.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f));
    Entity enemy1("enemy1", &my_scene,  Vector3(-3.0f, 3.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f));
    Entity enemy2("enemy2", &my_scene,  Vector3(3.0f, 3.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f));
    Entity enemy3("enemy3", &my_scene,  Vector3(3.0f, -3.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f));
    Entity enemy4("enemy4", &my_scene,  Vector3(-3.0f, -3.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f));


    //Componente de camara
    component camera_component(new Camera_Component(&camera));
    //componente de luz
    component light_component(new Light_Component(&light));
    //componente de scripting
    component player_script(new Player_Script(&player));
    //enemy script 
    component enemy_script(new Enemy_Script(&enemy1));
    component enemy_script2(new Enemy_Script(&enemy2));
    component enemy_script3(new Enemy_Script(&enemy3));
    component enemy_script4(new Enemy_Script(&enemy4));



   //se añaden los componentes a la entidad de luz
    light.add_component("light", light_component);

    //se le añaden los componentes a la entidad de camara
    camera.add_component("camera", camera_component);
    //Sele añade el script al player
    player.add_component("script", player_script);
    enemy1.add_component("script", enemy_script);
    enemy2.add_component("script", enemy_script2);
    enemy3.add_component("script", enemy_script3);
    enemy4.add_component("script", enemy_script4);

    
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