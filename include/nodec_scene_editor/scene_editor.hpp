#ifndef NODEC_SCENE_EDITOR__SCENE_EDITOR_HPP_
#define NODEC_SCENE_EDITOR__SCENE_EDITOR_HPP_

#include <nodec/macros.hpp>

#include <imessentials/window.hpp>

#include "component_registry.hpp"

namespace nodec_scene_editor {

class SceneEditor {
public:
    SceneEditor() {}
    virtual ~SceneEditor() {}

    virtual imessentials::WindowManager &window_manager() = 0;
    virtual ComponentRegistry::RegistryInterface component_registry() = 0;

private:
    NODEC_DISABLE_COPY(SceneEditor)
};

} // namespace nodec_scene_editor

#endif