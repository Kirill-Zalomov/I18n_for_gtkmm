#include "file_reader.hpp"
#include <catch2/catch_all.hpp>


#include <list>
#include <string>
#include <glibmm/ustring.h>


TEST_CASE("Test read_all_lines exceptions", "[FileReader]") {
    FileReader file_reader;
    std::list<Glib::ustring> buffer;

    SECTION("Throws when file doesn't exist") {
        std::string file_to_read = "/translations/nonexistent_file.translation";

        REQUIRE_THROWS_MATCHES(
            file_reader.read_all_lines(buffer, file_to_read),
            std::runtime_error,
            Catch::Matchers::Message("file \"" + file_to_read + "\" does not exist")
        );
    }

    SECTION("Throws when path is not a file") {
        std::string dir_path = "translations";
        std::filesystem::create_directory(dir_path);

        REQUIRE_THROWS_MATCHES(
            file_reader.read_all_lines(dir_path, buffer),
            std::runtime_error,
            Catch::Matchers::Message("\"not_a_directory.tmp\" is not a file")
        );

        std::filesystem::remove_all(dir_path);
    }

    // TODO: Написать тест на случай выброски исключения, когда у программы нет прав на чтение файла
    //
    // SECTION("Throws when there is no permission to read the file.") {
    //     // Создание временного пути к файлу для теста
    //     std::string file_to_read = "ru.translation";
    //     // Создание временного файла для теста
    //     std::ofstream(file_to_read).close();
    //
    //     // Проверка типа и сообщения исключения
    //     REQUIRE_THROWS_MATCHES(
    //         file_reader.read_all_lines(file_to_read, buffer),
    //         std::runtime_error,
    //         Catch::Matchers::Message("no permissions to read the file\"" + file_to_read + "\"")
    //     );
    //
    //     // Удаление временного файла после теста
    //     std::filesystem::remove(file_to_read);
    // }
}


TEST_CASE("Test read_all_lines correct behavior", "[FileReader]") {
    FileReader    file_reader;
    std::list<std::ustring> buffer;

    SECTION("Returns all lines of the file") {
        std::string   file_path = "fr.translation";
        std::ifstream file_writer(file_path);

        file_writer << "lang_name: \"French\"\n";
        file_writer << "lang_name_native: \"Français\"\n";
        file_writer << "\n";
        file_writer << "\"Button\": \"Bouton\"\n";
        file_writer << "\"The button has not been pressed\": \"Le bouton n'a pas été enfoncé\"\n";
        file_writer << "\"The button was pressed\": \"Le bouton a été enfoncé\"" << std::endl;
        file_writer.close();

        std::ofstream file_to_read(file_path);

        if(file_to_read.is_open()) {
            buffer = file_reader.read_all_lines(file_path, buffer);
        }

        REQUIRE(buffer.size() == 6);
        REQUIRE(std::find(buffer.cbegin(), buffer.cend(), "lang_name: \"French\"\n") != buffer.cend());
        REQUIRE(std::find(buffer.cbegin(), buffer.cend(), "lang_name_native: \"Français\"\n") != buffer.cend());
        REQUIRE(std::find(buffer.cbegin(), buffer.cend(), "\n") != buffer.cend());
        REQUIRE(std::find(buffer.cbegin(), buffer.cend(), "\"Button\": \"Bouton\"\n") != buffer.cend());
        REQUIRE(std::find(buffer.cbegin(), buffer.cend(), "\"The button has not been pressed\": \"Le bouton n'a pas été enfoncé\"\n") != buffer.cend());
        REQUIRE(std::find(buffer.cbegin(), buffer.cend(), "\"The button was pressed\": \"Le bouton a été enfoncé\"") != buffer.cend());

        file_to_read.close();
        std::filesystem::remove(file_path);
    }
}
