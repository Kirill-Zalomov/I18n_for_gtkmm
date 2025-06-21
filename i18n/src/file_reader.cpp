#include "file_reader.hpp"


// TODO: Реализация не соответствует тестам (доработать исключения [проверка прав чтения, существование файла и т.д.])
void
FileReader::read_all_lines(const std::string &path_to_file, std::list<Glib::ustring> &buffer) {
    Glib::RefPtr<Glib::IOChannel> file_channel = Glib::IOChannel::create_from_file ( path_to_file, "r" );

    Glib::ustring line;
    Glib::IOStatus status;

    while ( true ) {
        status = file_channel->read_line ( line );
        if ( status == Glib::IOStatus::NORMAL ) {
            if ( !line.empty() && line[line.length()-1] == '\n' ) {
                line.erase ( line.length()-1 );
                }
            buffer.push_back ( line );
            line.clear();
        }
        else if ( status == Glib::IOStatus::ENDOFFILE ) {
            break;
        }
        else {
            throw std::runtime_error ( "can cot read file \"" + path_to_file + "\"" );
        }
    }
}
