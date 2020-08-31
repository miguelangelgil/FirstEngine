#pragma once
#include <Component.hpp>
#include <memory>
#include <Render_Node.hpp>
namespace engine
{
    class Renderer_Component : public Component
    {
        std::unique_ptr<glt::Render_Node> renderer;

    public:
        Renderer_Component(Entity* parent) : Component(parent)
        {
        }

        bool initialize() override
        {
            renderer = nullptr;
        }
        void init_renderer(glt::Render_Node& node)
        {
            *renderer = node;
        }
        bool parse_property(const string& name, const string& value) override
        {
            // ...
        }

    };
}