#include "hannya/application.hh"

namespace Hannya {

Application::Application(const std::string conf_dir)
    : _conf_dir(conf_dir)
{
}

Application::~Application(void)
{
    delete _root;
}

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
    _root = new Ogre::Root();
}

void Application::define_resources(void)
{
    /*
    String sec_name, type_name, arch_name;
    ConfigFile cf;
    cf.load("resources.cfg");
    */
    std::cout << "Would load resources from: " << _conf_dir << "/resources.cfg"
              << std::endl;
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
