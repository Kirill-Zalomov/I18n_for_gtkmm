#ifndef FILE_READER_HPP
#define FILE_READER_HPP


#include <list>
#include <glibmm/ustring.h>


class FileReader {

    public:
        void read_all_content(std::list<Glib::ustring> buffer, const std::string &path_to_file);

}


#endif // FILE_READER_HPP

