#ifndef TRANSLATION_VALIDATOR_HPP
#define TRANSLATION_VALIDATOR_HPP


#include <list>
#include <glibmm/ustring.h>



class ValidatorOfTranslationFile {

    public:
        bool
        validate(const std::list<Glib::ustring> &content_of_translation_file);

    private:
        bool
        validate_header(const std::list<Glib::ustring> &content_of_translation_file);

    private:
        bool
        validate_translations(const std::list<Glib::ustring> &content_of_translation_file);

};


#endif // TRANSLATION_VALIDATOR_HPP

