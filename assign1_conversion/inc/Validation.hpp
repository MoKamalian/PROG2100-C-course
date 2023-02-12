/*
 * author: amir kamalian
 * date:   27 jan 2O23
 *
 */

/*
 * This validation class is used to validate
 * a specific file pattern depending on the given regex
 *
 * Note: cannot instantiate from this class
 *
 */

#ifndef VALIDATION
#define VALIDATION


#include <iostream>
#include <regex>


class Validation {
public:
    Validation() = delete;

    /* validates the filePattern against regexPattern passed in */
    static bool validateInput(const std::string& filePattern, const std::string& regexPattern);

};


#endif

