/*
 * author: amir kamalian
 * date:   27 jan 2O23
 *
 */

#include "../inc/Validation.hpp"


bool Validation::validateInput(const std::string& filePattern, const std::string& regexPattern) {
    return std::regex_match(filePattern, std::regex(regexPattern));
};




