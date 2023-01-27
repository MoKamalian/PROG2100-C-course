/*
 * author: amir kamalian
 * date:   25 jan 2O23
 *
 */

#ifndef WINDOWS_EXCEPTION
#define WINDOWS_EXCEPTION

/*
 * This is the custom exception thrown if user
 * specifies a non-valid Windows file as the
 * input file for reading
 *
 */


#include <exception>


class WindowsFileException : public std::exception {

public:
    WindowsFileException() = default;

    [[nodiscard]] const char* what() const noexcept override {
        return "[non-valid Windows file given]";
    };

};



#endif
