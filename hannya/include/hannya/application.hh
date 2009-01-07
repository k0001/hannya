#include <Ogre.h>
#include <OIS/OIS.h>

namespace Hannya {

class Application
{
    public:
        Application(const std::string conf_dir);
        Application(void);
        ~Application(void);
        void go(void);

    private:
        std::string _conf_dir;
        Ogre::Root *_root;
        Ogre::RenderWindow *_win;
        OIS::Keyboard *_keyboard;
        OIS::Mouse *_mouse;
        OIS::InputManager *_input_manager;

        void create_root(void);
        void define_resources(void);
        void setup_render_system(void);
        void create_render_window(void);
        void initialize_resource_groups(void);
        void setup_scene(void);
        void setup_input_system(void);
        void create_frame_listeners(void);
        void start_render_loop(void);
};

}
