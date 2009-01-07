#include "hannya/application.hh"

namespace Hannya {

Application::Application(const std::string conf_dir)
    : _conf_dir(conf_dir)
{
    if (_conf_dir[_conf_dir.length() - 1] != '/')
        _conf_dir += '/';
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
    std::string sec_name, type_name, arch_name;
    Ogre::ConfigFile cf;
    cf.load(_conf_dir + "resources.cfg");
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
    while (seci.hasMoreElements()) {
        sec_name = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i) {
            type_name = i->first;
            arch_name = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                    arch_name, type_name, sec_name);
        }
    }

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
