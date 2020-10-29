#pragma once
#include <Component.hpp>
#include <Sphere_Collider_Component.hpp>

namespace engine 
{
    class Script_Component : public Component
    {
    public:

        Script_Component(Entity* parent);
        
        virtual void Start() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void OnCollision(Entity* other, COLLISION_STATE state) = 0;

        // Heredado vía Component
        virtual bool initialize() override;

        virtual bool parse_property(const string& name, const string& value) override;

        virtual string get_type_component() override;

        virtual std::shared_ptr<glt::Node> get_node_component() override;
                                                                        
        virtual std::shared_ptr<glt::Model> get_model() override;
                                                                        
        virtual std::shared_ptr<glt::Light> get_light() override;
                                                                        
        virtual std::shared_ptr<glt::Camera> get_camera() override;

    };
}

