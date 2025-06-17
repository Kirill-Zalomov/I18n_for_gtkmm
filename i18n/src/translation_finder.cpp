#include "translation_finder.hpp"


TranslationFinder::TranslationFinder(const Glib::ustring &path_to_translation_folder = "translations/") {
    path_to_translation_folder_ = path_to_translation_folder;
}


void
TranslationFinder::set_path_to_translation_folder(const Glib::ustring &path_to_translation_folder) {
    path_to_translation_folder_ = path_to_translation_folder;
}


Glib::ustring
TranslationFinder::get_path_to_translation_folder() const noexcept {
    return path_to_translation_folder_;
}


// TODO: Дописать реализацию функции поиска файлов перевода
std::list<Glib::ustring>
TranslationFinder::get_translation_paths() {
    if(path_to_translation_folder_.empty()) {
        // TODO: Дописать, какое исключение должно быть выброшено
    }

    std::list<Glib::ustring> traslations;
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << entry.path() << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}
