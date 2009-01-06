#include "hannya/application.hh"

namespace Hannya {

void Application::go(void)
{
    create_root();
    define_resources();
    setup_render_system();
    create_render_window();
    initialize_resource_groups();
    setup_scene();
    setup_input_system();
    create_frame_listeners();
    start_render_loop();
}

void Application::create_root(void)
{
}

void Application::define_resources(void)
{
}

void Application::setup_render_system(void)
{
}

void Application::create_render_window(void)
{
}

void Application::initialize_resource_groups(void)
{
}

void Application::setup_scene(void)
{
}

void Application::setup_input_system(void)
{
}

void Application::create_frame_listeners(void)
{
}

void Application::start_render_loop(void)
{
}

}
