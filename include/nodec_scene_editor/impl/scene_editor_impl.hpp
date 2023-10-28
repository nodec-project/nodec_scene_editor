#ifndef NODEC_SCENE_EDITOR__IMPL__SCENE_EDITOR_IMPL_HPP_
#define NODEC_SCENE_EDITOR__IMPL__SCENE_EDITOR_IMPL_HPP_

#include <imessentials/impl/menu_impl.hpp>
#include <imessentials/impl/window_impl.hpp>

#include "../scene_editor.hpp"

namespace nodec_scene_editor {
namespace impl {

class SceneEditorImpl : public SceneEditor {
public:
    SceneEditorImpl() {}

    imessentials::WindowManager &window_manager() override {
        return window_manager_impl_;
    }

    imessentials::impl::WindowManagerImpl &window_manager_impl() {
        return window_manager_impl_;
    }

    ComponentRegistry::RegistryInterface component_registry() override {
        return component_registry_.registry_interface();
    }

    ComponentRegistry &component_registry_impl() {
        return component_registry_;
    }

private:
    imessentials::impl::WindowManagerImpl window_manager_impl_;
    ComponentRegistry component_registry_;
};

} // namespace impl
} // namespace nodec_scene_editor

#endif