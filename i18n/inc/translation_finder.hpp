#ifndef TRANSLATION_FINDER_HPP
#define TRANSLATION_FINDER_HPP


#include <list>
#include <filesystem>
#include <glibmm/ustring.h>


// TODO: Сделать для описания элементов класса для DOxygen
class TranslationFinder {
    Glib::ustring path_to_translation_folder_;


    public:
        TranslationFinder(const Glib::ustring &path_to_translation_folder = "translations/");

    public:
        void
        set_path_to_translation_folder(const Glib::ustring &path_to_translation_folder);

    public:
        Glib::ustring
        get_path_to_translation_folder() const noexcept;

    public:
        std::list<Glib::ustring>
        get_translation_paths();
}


#endif // TRANSLATION_FINDER_HPP
