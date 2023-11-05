#ifndef NODEC_SCENE_EDITOR__SCENE_GIZMO_HPP_
#define NODEC_SCENE_EDITOR__SCENE_GIZMO_HPP_

#include <nodec/array_view.hpp>
#include <nodec/vector3.hpp>
#include <nodec/vector4.hpp>

#include <nodec_scene/scene_entity.hpp>

namespace nodec_scene_editor {

class SceneGizmo {
public:
    // virtual void draw_poly_line(nodec::ArrayView<nodec::Vector3f> points,
    //                             const nodec::Vector4f &color) = 0;

    virtual void draw_wire_cube(const nodec::Vector3f &center,
                                const nodec::Vector3f &size = nodec::Vector3f::ones,
                                const nodec::Quaternionf &rotation = nodec::Quaternionf::identity) = 0;

    virtual void draw_wire_sphere(const nodec::Vector3f &center,
                                  float radius = 1.0f) = 0;
};

} // namespace nodec_scene_editor

#endif