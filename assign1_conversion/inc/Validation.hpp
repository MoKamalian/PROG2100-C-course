/*
 * author: amir kamalian
 * date:   27 jan 2O23
 *
 */

/*
 * This is the validation class used to ensure a valid Windows .cpp
 * source file is given as the input.
 *
 */

#ifndef VALIDATION
#define VALIDATION

#include <iostream>
#include <regex>


class Validation {
public:
    Validation() = delete;

    static bool validateInput(const std::string& filePattern, const std::string& regexPattern);

};





#endif

