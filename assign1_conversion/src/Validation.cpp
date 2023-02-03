/*
 * author: amir kamalian
 * date:   27 jan 2O23
 *
 */

#include "../inc/Validation.hpp"

/* returns true if the filePattern matches the regexPattern;
 * Usage:
 *      - regexPattern would be the correct pattern you
 *        want the filePattern to be
 *      - if the two do not match then the filePattern
 *        is considered invalid */
bool Validation::validateInput(const std::string& filePattern, const std::string& regexPattern) {
    return std::regex_match(filePattern, std::regex(regexPattern));
};




