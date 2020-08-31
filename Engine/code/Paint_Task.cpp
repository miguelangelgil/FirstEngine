#include <Paint_Task.hpp>
#include <Scene.hpp>
#include <Transform_Component.hpp>
#include <Camera.hpp>
#include <Kernel.hpp>
#include <glad/glad.h>
#include <Model_Component.hpp>


namespace engine 
{
    Paint_Task::Paint_Task(Scene* scene, int priority) : Task(scene, priority)
    {
        renderer.reset(new Render_Node);

    }
    void Paint_Task::add_Component(string name, Model_Component* component)
    {
        renderer->add(name, component->get_model());
    }
    bool Paint_Task::initialize()
    {
        scan_components();
        active = true;
        return false;

    }
    bool Paint_Task::finalize()
    {
        active = false;
        for (auto& component : components) {
            component->initialize();
        }
        return false;
    }
    bool Paint_Task::step(double time)
    {
        // Se ajusta el viewport por si el tamaño de la ventana ha cambiado:
        GLsizei width = GLsizei(kernel->get_window().get_width());
        GLsizei height = GLsizei(kernel->get_window().get_height());
        renderer->get_active_camera()->set_aspect_ratio(float(width)/height);
        glViewport(0, 0, width, height);
        kernel->get_window().clear();
        renderer->render();

        kernel->get_window().swap_buffers();
        return false;
    }

    void Paint_Task::add_Component(std::shared_ptr<Component> new_Component)
    {
        components.push_back(new_Component);
    }

    void Paint_Task::scan_components()
    {
        typedef shared_ptr<Component> component_ptr;
        map<string, component_ptr> ::iterator iterator_components;

        map<ID, Entity*>* scene_entities = scene->get_entities();
        map<ID, Entity*> ::iterator iterator_entities = scene_entities->begin();
        for (; iterator_entities != scene_entities->end(); iterator_entities++)
        {
            iterator_components = iterator_entities->second->get_components()->begin();
            for (; iterator_components != iterator_entities->second->get_components()->end(); iterator_components++)
            {
                if (iterator_components->second->get_type_component() == "light")
                {
                    components.push_back(iterator_components->second);
                    renderer->add(iterator_entities->second->get_name() + iterator_components->second->get_type_component(), iterator_components->second->get_light());
                }
                else if (iterator_components->second->get_type_component() == "camera")
                {
                    components.push_back(iterator_components->second);
                    renderer->add(iterator_entities->second->get_name() + iterator_components->second->get_type_component(), iterator_components->second->get_camera());
                }
                else if (iterator_components->second->get_type_component() == "model")
                {
                    components.push_back(iterator_components->second);
                    renderer->add(iterator_entities->second->get_name() + iterator_components->second->get_type_component(), iterator_components->second->get_model());
                }
            }
        }

    }
}