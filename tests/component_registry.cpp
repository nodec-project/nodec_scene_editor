#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <nodec_scene_editor/component_registry.hpp>

TEST_CASE("Testing register_component") {
    using namespace nodec_scene_editor;

    SUBCASE("using BasicComponentEditor") {
        struct UserComponent {};

        ComponentRegistry registry;
        registry.registry_interface().register_component<UserComponent>("User Component");
        auto handler = registry.get_handler(nodec::type_id<UserComponent>());
        CHECK(handler != nullptr);
    }

    SUBCASE("using CustomComponentEditor") {
        struct UserComponent {};
        class UserComponentEditor : public BasicComponentEditor<UserComponent> {
        public:
            UserComponentEditor(int arg) {}
        };

        ComponentRegistry registry;
        registry.registry_interface().register_component<UserComponent, UserComponentEditor>("User Component", 1);
        auto handler = registry.get_handler(nodec::type_id<UserComponent>());
        CHECK(handler != nullptr);
    }
}