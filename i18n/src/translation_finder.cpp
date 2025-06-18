#include "translation_finder.hpp"


TranslationFinder::TranslationFinder() {}


std::list<std::string>
TranslationFinder::get_paths_to_translation_files(const std::string &path_to_folder) {

    std::list<std::string> translation_files;
    std::error_code ec;

    if (!std::filesystem::exists(path_to_folder)) {
        throw std::runtime_error("directory \"" + path_to_folder + "\" does not exist");
    }

    if (!std::filesystem::is_directory(path_to_folder, ec)) {
        throw std::runtime_error("\"" + path_to_folder + "\" is not a directory");
    }

    for (const auto& entry : std::filesystem::directory_iterator(path_to_folder)) {
        if (entry.is_regular_file() && entry.path().extension() == ".translation") {
            translation_files.push_back(entry.path().string());
        }
    }

    return translation_files;
}
