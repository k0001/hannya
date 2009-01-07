#include "hannya/application.hh"

void print_usage(const char *prog_name) {
    std::cout << "Usage: " << prog_name << " CONF_DIR" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    std::string conf_dir(argv[1]);
    try {
        Hannya::Application app(conf_dir);
        app.go();
    }
    catch(Ogre::Exception &e)
    {
        std::cerr << "An exception has occurred: " << e.getFullDescription()
                  << std::endl;
        return 1;
    }
    return 0;
}

