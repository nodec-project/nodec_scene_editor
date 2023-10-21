#ifndef NODEC_SCENE_EDITOR__COMPONENT_EDITOR_HPP_
#define NODEC_SCENE_EDITOR__COMPONENT_EDITOR_HPP_

#include <nodec_scene/scene.hpp>

#include "scene_gizmo.hpp"

namespace nodec_scene_editor {

struct InspectorGuiContext {
    nodec_scene::SceneEntity entity;
    nodec_scene::SceneRegistry &registry;
};
struct SceneGuiContext {
    nodec_scene::SceneRegistry &registry;
};

class BaseComponentEditor {
public:
    virtual ~BaseComponentEditor() {}

    virtual void on_inspector_gui_opaque(void *component, const InspectorGuiContext &) = 0;
    virtual void on_scene_gui(SceneGizmo &, const SceneGuiContext &) = 0;
};

template<typename Component>
class BasicComponentEditor : public BaseComponentEditor {
public:
    virtual ~BasicComponentEditor() {}

    void on_inspector_gui_opaque(void *component, const InspectorGuiContext &context) final {
        on_inspector_gui(*static_cast<Component *>(component), context);
    }

    virtual void on_inspector_gui(Component &, const InspectorGuiContext &) {}
    virtual void on_scene_gui(SceneGizmo &, const SceneGuiContext &) {}
};
} // namespace nodec_scene_editor

#endif