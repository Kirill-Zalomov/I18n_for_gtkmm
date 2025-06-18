#include "translation_finder.hpp"
#include <catch2/catch_all.hpp>


#include <list>
#include <fstream>
#include <algorithm>
#include <filesystem>


TEST_CASE("Test get_paths_to_translation_files exceptions", "[TranslationFinder]") {
    // Создание объекта TranslationFinder, общего для всех секций ниже
    TranslationFinder translation_finder;

    SECTION("Throws when directory doesn't exist") {
        // Проверка типа и сообщения исключения
        REQUIRE_THROWS_MATCHES(
            translation_finder.get_paths_to_translation_files("/nonexistent/path"),
            std::runtime_error,
            Catch::Matchers::Message("directory \"/nonexistent/path\" does not exist")
        );
    }

    SECTION("Throws when path is not a directory") {
        // Создание временного файла для теста
        std::ofstream tmpfile("not_a_directory.tmp");
        tmpfile.close();

        // Проверка типа и сообщения исключения
        REQUIRE_THROWS_MATCHES(
            translation_finder.get_paths_to_translation_files("not_a_directory.tmp"),
            std::runtime_error,
            Catch::Matchers::Message("\"not_a_directory.tmp\" is not a directory")
        );

        // Удаление временного файла для теста
        std::filesystem::remove("not_a_directory.tmp");
    }
}


TEST_CASE("Test get_paths_to_translation_files correct behavior", "[TranslationFinder]") {
    // Создание объекта TranslationFinder, общего для всех секций ниже
    TranslationFinder translation_finder;

    // Создание тестовой директории с файлами
    std::filesystem::create_directory("translations");
    std::ofstream("translations/ru.translation").close();
    std::ofstream("translations/fr.translation").close();
    std::ofstream("translations/other_file.txt").close();

    SECTION("Returns only *.translation files") {
        std::list<std::string> files = translation_finder.get_paths_to_translation_files("translations");

        // Проверка, что найдены 2 файла с расширением *.translation
        REQUIRE(files.size() == 2);
        REQUIRE(std::find(files.begin(), files.end(), "translations/ru.translation") != files.end());
        REQUIRE(std::find(files.begin(), files.end(), "translations/fr.translation") != files.end());
    }

    // Удаляем тестовую директорию
    std::filesystem::remove_all("translations");
}
