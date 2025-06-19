#include "translation_finder.hpp"
#include <catch2/catch_all.hpp>


#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <stdexcept>


TEST_CASE("Test get_paths_to_translation_files exceptions", "[TranslationFinder]") {
    TranslationFinder translation_finder;

    SECTION("Throws when directory doesn't exist") {
        std::string directory_path = "/translations/nonexistent_dir";

        REQUIRE_THROWS_MATCHES(
            translation_finder.get_paths_to_translation_files(directory_path),
            std::runtime_error,
            Catch::Matchers::Message("directory \"" + directory_path + "\" does not exist")
        );
    }

    SECTION("Throws when path is not a directory") {
        std::string   file_path = "not_a_directory.tmp";
        std::ofstream tmpfile(file_path).close();

        REQUIRE_THROWS_MATCHES(
            translation_finder.get_paths_to_translation_files(file_path),
            std::runtime_error,
            Catch::Matchers::Message("\"" + file_path + "\" is not a directory")
        );

        std::filesystem::remove(file_path);
    }
}


TEST_CASE("Test get_paths_to_translation_files correct behavior", "[TranslationFinder]") {
    TranslationFinder translation_finder;

    std::filesystem::create_directory("translations");
    std::ofstream("translations/ru.translation").close();
    std::ofstream("translations/fr.translation").close();
    std::ofstream("translations/other_file.txt").close();

    SECTION("Returns only *.translation files") {
        std::list<std::string> files = translation_finder.get_paths_to_translation_files("translations");

        REQUIRE(files.size() == 2);
        REQUIRE(std::find(files.cbegin(), files.cend(), "translations/ru.translation") != files.cend());
        REQUIRE(std::find(files.cbegin(), files.cend(), "translations/fr.translation") != files.cend());
    }

    std::filesystem::remove_all("translations");
}
