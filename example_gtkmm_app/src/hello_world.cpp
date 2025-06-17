#include "hello_world.hpp"


HelloWorld::HelloWorld() {
    main_container_ = Gtk::manage(new Gtk::Box(Gtk::Orientation::VERTICAL, 10));
    button_ = Gtk::manage(new Gtk::Button());
    label_ = Gtk::manage(new Gtk::Label());
    language_selection_ = Gtk::manage(new Gtk::DropDown());

    set_title("Application \"i18n\"");
    set_default_size(300, 200);
    set_resizable(false);

    button_->set_label("Button");
    button_->signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));
    button_->set_margin_start(10);
    button_->set_margin_end(10);

    label_->set_text("The button has not been pressed");
    label_->set_margin_top(10);

    const std::vector<Glib::ustring> languages {
        "English",
        "French",
        "Russian",
        "Chinese (Simplified)"
    };
    list_of_languages_ = Gtk::StringList::create(languages);
    language_selection_->set_model(list_of_languages_);
    language_selection_->set_selected(0);
    language_selection_->set_margin_start(10);
    language_selection_->set_margin_end(10);
    language_selection_->set_margin_top(10);

    main_container_->append(*language_selection_);
    main_container_->append(*label_);
    main_container_->append(*button_);

    set_child(*main_container_);
}


HelloWorld::~HelloWorld() {}


void HelloWorld::on_button_clicked() {
    label_->set_text("The button was pressed");
}
