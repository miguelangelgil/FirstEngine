#include "headers\Input_Component.hpp"
#include <Entity.hpp>
#include <Variant.hpp>
#include <Input.hpp>

namespace engine 
{
    engine::Input_Component::Input_Component(Entity* parent) : Component(parent),keyboard(new Input())
    {
         parent->get_scene()->get_message_handle()->add(*this, "Keyboard");      
    }

    bool engine::Input_Component::initialize()
    {
        return true;
    }

    bool engine::Input_Component::parse_property(const string& name, const string& value)
    {
        return true;
    }

    void engine::Input_Component::handle(const Message& message)
    {

        for (auto&& param : message.parameters) 
        {
            if (param.first == "KeyDown") 
            {
                keyboard->set_key_down(param.second);
            }
            else if (param.first == "KeyUp") 
            {
                keyboard->set_key_up(param.second);
            }
        }
        
         
    }

    string engine::Input_Component::get_type_component()
    {
        return "input";
    }

    std::shared_ptr<glt::Node> engine::Input_Component::get_node_component()
    {
        return std::shared_ptr<Model>();
    }

    std::shared_ptr<Model> engine::Input_Component::get_model()
    {
        return std::shared_ptr<Model>();
    }

    std::shared_ptr<Light> engine::Input_Component::get_light()
    {
        return std::shared_ptr<Light>();
    }


    std::shared_ptr<Camera> engine::Input_Component::get_camera()
    {
        return std::shared_ptr<Camera>();
    }

}
