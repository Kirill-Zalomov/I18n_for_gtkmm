#include "hello_world.hpp"
#include <gtkmm/application.h>


int main(int argc, char* argv[]) {
    auto application = Gtk::Application::create();
    return application->make_window_and_run<HelloWorld>(argc, argv);
}
