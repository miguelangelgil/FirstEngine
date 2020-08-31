#include <Transform_Component.hpp>
#include <Entity.hpp>
#include "headers/Entity.hpp"

namespace engine
{
    Transform_Component::Transform_Component(Entity* parent, Vector3 position, Vector3 rotation, Vector3 scale) : Component(parent)
    {
     
        transform = std::shared_ptr<glt::Node>(new glt::Node());
        this->position.x = position[0]; this->position.y = position[1]; this->position.z = position[2];
        this->rotation.x = rotation[0]; this->rotation.y = rotation[1]; this->rotation.z = rotation[2];
        this->scale.x = scale[0];       this->scale.y = scale[1];       this->scale.z = scale[2];
        translation.x = this->position.x; translation.y = this->position.y; translation.z = this->position.z;
    }

    bool Transform_Component::initialize()
    {
        
        return true;
    }
    void Transform_Component::set_position(glm::vec3 new_position)
    {
        position = new_position;
        translation = new_position;
        transform->reset_transformation();
       
    }

    void Transform_Component::set_rotation(float x, float y, float z)
    {
        rotation.x = x; rotation.y = y; rotation.z = z;
    }
    void Transform_Component::set_scale(float x, float y, float z)
    {
        scale.x = x; scale.y = z; scale.z = z;
    }
    glm::vec3* Transform_Component::get_position()
    {
        return &position;
    }
    glm::vec3* Transform_Component::get_rotation()
    {
        return &rotation;
    }
    glm::vec3* Transform_Component::get_scale()
    {
        return &scale;
    }
    void Transform_Component::set_traslate(glm::vec3 new_traslate)
    {
        translation = new_traslate;
        position += new_traslate;
    }
    bool Transform_Component::parse_property(const string& name, const string& value)
    {
        return false;
    }
    void Transform_Component::set_Transform(std::shared_ptr<glt::Node> node) 
    {
        transform->set_transformation( node->get_transformation());
        
    }
    
    void Transform_Component::apply_Transform() 
    {


        transform->translate(glt::Vector3(translation));
        transform->rotate_around_x(rotation.x);
        transform->rotate_around_y(rotation.y);
        transform->rotate_around_z(rotation.z);
        transform->scale(scale.x, scale.y, scale.z);
       
        translation.x = 0;
        translation.y = 0;
        translation.z = 0;

    }
    glt::Matrix44 Transform_Component::get_transformation()
    {
        return transform->get_transformation();
    }
}