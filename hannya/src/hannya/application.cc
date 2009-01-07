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
    _input_manager->destroyInputObject(_mouse);
    _input_manager->destroyInputObject(_keyboard);
    OIS::InputManager::destroyInputSystem(_input_manager);

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
    _root = new Ogre::Root(_conf_dir + "plugins.cfg", _conf_dir + "ogre.cfg",
            "ogre.log");
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
    if (!_root->restoreConfig() && !_root->showConfigDialog())
        throw Ogre::Exception(52, "User canceled the config dialog!",
                "Application::setupRenderSystem()");
}

void Application::create_render_window(void)
{
    _win = _root->initialise(true, "Hannya");
}

void Application::initialize_resource_groups(void)
{
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void Application::setup_scene(void)
{
    Ogre::SceneManager *smgr = _root->createSceneManager(Ogre::ST_GENERIC,
            "default");
    Ogre::Camera *cam = smgr->createCamera("default");
    Ogre::Viewport *vp = _win->addViewport(cam);
}

void Application::setup_input_system(void)
{
    size_t window_hnd = 0;
    std::ostringstream window_hnd_str;
    OIS::ParamList pl;
    _win->getCustomAttribute("WINDOW", &window_hnd);
    window_hnd_str << window_hnd;
    pl.insert(std::make_pair(std::string("WINDOW"), window_hnd_str.str()));
    _input_manager = OIS::InputManager::createInputSystem(pl);

    try {
        _keyboard = static_cast<OIS::Keyboard*>(
                _input_manager->createInputObject(OIS::OISKeyboard, true));
        _mouse = static_cast<OIS::Mouse*>(
                _input_manager->createInputObject(OIS::OISMouse, true));
    }
    catch (const OIS::Exception &e) {
        throw Ogre::Exception(42, e.eText, "Application::setup_input_system");
    }

}

void Application::create_frame_listeners(void)
{
}

void Application::start_render_loop(void)
{
    _root->startRendering();
}

}
