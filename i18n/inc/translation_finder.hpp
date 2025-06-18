#ifndef TRANSLATION_FINDER_HPP
#define TRANSLATION_FINDER_HPP


#include <list>
#include <filesystem>


// TODO: Сделать для описания элементов класса для DOxygen
class TranslationFinder {

    public:
        TranslationFinder();

    public:
        std::list<std::string>
        get_paths_to_translation_files(const std::string &path_to_folder = "translations");
};


#endif // TRANSLATION_FINDER_HPP
