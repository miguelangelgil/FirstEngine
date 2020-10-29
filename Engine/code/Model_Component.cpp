#include "headers/Model_Component.hpp"
#include "headers/Transform_Component.hpp"
#include "headers/Entity.hpp"

namespace engine 
{
    engine::Model_Component::Model_Component(Entity* parent, const string path) : Component(parent), model(new glt::Model_Obj(path))
    {
        
        initialize();
    }

    engine::Model_Component::Model_Component(Entity* parent) : Component(parent), model1(new glt::Model)
    {
        model1->add(shared_ptr< Drawable >(new Cube), Material::default_material());
        initialize();
    }

    bool engine::Model_Component::initialize()
    {
        Transform_Component* transform = dynamic_cast<Transform_Component*>(parent->get_component("transform").get());
        transform->set_Transform(model);
        transform->apply_Transform();
        return false;
    }
    std::shared_ptr<glt::Node> Model_Component::get_node_component()
    {
        return model;
    }
    std::shared_ptr<Model> Model_Component::get_model()
    {
        return model;
    }
    std::shared_ptr<Light> Model_Component::get_light()
    {
        return std::shared_ptr<Light>();
    }
    std::shared_ptr<Camera> Model_Component::get_camera()
    {
        return std::shared_ptr<Camera>();
    }
}

