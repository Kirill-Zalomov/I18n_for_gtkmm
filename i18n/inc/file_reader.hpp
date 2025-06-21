#ifndef FILE_READER_HPP
#define FILE_READER_HPP


#include <list>
#include <glibmm/ustring.h>
#include <glibmm/iochannel.h>


class FileReader {

    public:
        void read_all_lines(const std::string &path_to_file, std::list<Glib::ustring> &buffer);

};


#endif // FILE_READER_HPP

