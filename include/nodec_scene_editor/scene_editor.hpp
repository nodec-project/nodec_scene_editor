#ifndef NODEC_SCENE_EDITOR__SCENE_EDITOR_HPP_
#define NODEC_SCENE_EDITOR__SCENE_EDITOR_HPP_

#include <nodec/macros.hpp>

#include <imessentials/window.hpp>

#include "entity_inspector_window.hpp"
#include "selection.hpp"

namespace nodec_scene_editor {

class SceneEditor {
public:
    SceneEditor() = default;

public:
    virtual imessentials::WindowManager &window_manager() = 0;
    virtual Selection &selection() = 0;
    virtual EntityInspectorWindow::ComponentRegistry::RegistryInterface inspector_component_registry() = 0;

private:
    NODEC_DISABLE_COPY(SceneEditor)
};

} // namespace nodec_scene_editor

#endif