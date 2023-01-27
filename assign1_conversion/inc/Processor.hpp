
#ifndef PROCESSOR
#define PROCESSOR

/*
 * author: amir kamalian
 * date:   22 jan 2O23
 *
 */

/*
 * The Processor class is used to conduct the
 * conversion of '<' and '>' to &lt and &gt
 * respectively.
 *
 * Once processing is complete, the changed
 * contents are written to the specified file.
 *
 */

#include <iostream>
#include <regex>
#include <fstream>
#include "File.hpp"

class Processor {
public:
    Processor() = delete;

    static void replace(File& fileStruct, const std::string& regex_pattern, const std::string& replacement);
    static void writeContentToFile(File& fileStruct, std::fstream handler);

};

#endif
