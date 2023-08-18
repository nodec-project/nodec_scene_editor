#ifndef NODEC_SCENE_EDITOR__SCENE_GIZMO_HPP_
#define NODEC_SCENE_EDITOR__SCENE_GIZMO_HPP_

#include <nodec/array_view.hpp>
#include <nodec/vector3.hpp>
#include <nodec/vector4.hpp>

namespace nodec_scene_editor {

class SceneGizmo {
public:
    virtual void draw_poly_line(nodec::ArrayView<nodec::Vector3f> points,
                                const nodec::Vector4f &color) = 0;
};

} // namespace nodec_scene_editor

#endif