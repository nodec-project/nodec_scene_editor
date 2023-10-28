#ifndef NODEC_SCENE_EDITOR__COMPONENT_REGISTRY_HPP_
#define NODEC_SCENE_EDITOR__COMPONENT_REGISTRY_HPP_

#include <memory>
#include <string>
#include <type_traits>
#include <unordered_map>

#include <nodec/type_info.hpp>
#include <nodec_scene/scene_entity.hpp>
#include <nodec_scene/scene_registry.hpp>

#include "component_editor.hpp"

namespace nodec_scene_editor {

class ComponentRegistry {
public:
    class BaseComponentHandler {
    public:
        BaseComponentHandler(const std::string &component_name, std::unique_ptr<BaseComponentEditor> editor)
            : component_name_(component_name), editor_(std::move(editor)) {}
        virtual ~BaseComponentHandler() {}

        const std::string &component_name() const noexcept {
            return component_name_;
        }

        BaseComponentEditor &editor() const noexcept {
            return *editor_;
        }

        virtual void emplace_component(nodec_scene::SceneRegistry &registry, nodec_scene::SceneEntity entity) const = 0;
        virtual void remove_component(nodec_scene::SceneRegistry &registry, nodec_scene::SceneEntity entity) const = 0;

    private:
        const std::string component_name_;
        std::unique_ptr<BaseComponentEditor> editor_;
    };

    template<class Component>
    class ComponentHandler : public BaseComponentHandler {
    public:
        using BaseComponentHandler::BaseComponentHandler;

        void emplace_component(nodec_scene::SceneRegistry &registry, nodec_scene::SceneEntity entity) const override {
            registry.emplace_component<Component>(entity);
        }
        void remove_component(nodec_scene::SceneRegistry &registry, nodec_scene::SceneEntity entity) const override {
            registry.remove_component<Component>(entity);
        }
    };

    class RegistryInterface {
    public:
        RegistryInterface(ComponentRegistry *registry)
            : registry_(registry) {}

        template<class Component, class ComponentEditor, typename... Args,
                 std::enable_if_t<std::is_base_of<BaseComponentEditor, ComponentEditor>::value> * = nullptr>
        void register_component(const std::string &name, Args &&...args) {
            auto &handlers = registry_->handlers_;

            auto iter = handlers.find(nodec::type_id<Component>());
            if (iter != handlers.end()) return;

            auto editor = std::make_unique<ComponentEditor>(std::forward<Args>(args)...);
            auto handler = std::make_unique<ComponentHandler<Component>>(name, std::move(editor));
            handlers.emplace(nodec::type_id<Component>(), std::move(handler));
        }

        template<class Component>
        void register_component(const std::string &name) {
            register_component<Component, BasicComponentEditor<Component>>(name);
        }

    private:
        ComponentRegistry *registry_;
    };

    BaseComponentHandler *get_handler(const nodec::type_info &info) const {
        auto iter = handlers_.find(info);
        if (iter == handlers_.end()) return nullptr;
        return iter->second.get();
    }

    RegistryInterface registry_interface() {
        return {this};
    }

    decltype(auto) begin() {
        return handlers_.begin();
    }

    decltype(auto) end() {
        return handlers_.end();
    }

    decltype(auto) size() const noexcept {
        return handlers_.size();
    }

private:
    std::unordered_map<nodec::type_info, std::unique_ptr<BaseComponentHandler>> handlers_;
};

} // namespace nodec_scene_editor

#endif