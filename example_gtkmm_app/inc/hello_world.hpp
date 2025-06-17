#ifndef GTKMM_EXAMPLE_HELLOWORLD_HPP
#define GTKMM_EXAMPLE_HELLOWORLD_HPP


#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/dropdown.h>
#include <gtkmm/stringlist.h>
#include <gtkmm/window.h>
#include <vector>


class HelloWorld : public Gtk::Window {

    // Обработчики событий
    void on_button_clicked();

    // Виджеты
    Gtk::Box* main_container_;
    Gtk::DropDown* language_selection_;
    Gtk::Button* button_;
    Gtk::Label* label_;

    // Модели
    Glib::RefPtr<Gtk::StringList> list_of_languages_;

public:
    HelloWorld();
    ~HelloWorld() override;

};


#endif // GTKMM_EXAMPLE_HELLOWORLD_HPP

