
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
 * respectively, ideally; however, other conversion
 * are permitted.
 *
 * Once processing is complete, the changed
 * contents are written to the specified file.
 *
 * Note: you cannot instantiate from this class as
 * the functionality provided dosnt require an object.
 *
 */

#include <iostream>
#include <regex>
#include <fstream>
#include "File.hpp"

class Processor {
public:
    Processor() = delete;

    /* for replacement; fileStruct must be a type that implements File */
    static void replace(File& fileStruct, const std::string& regex_pattern, const std::string& replacement);

    /* writes the contents of filesStruct to handler; note that there is no check
     * done here to ensure whether the filesStruct was processed or not; the contents
     * are simply written to handler, with '<PRE>' and '</PRE>' at the beginning
     * and end of writing respectively.  */
    static void writeContentToFile(File& fileStruct, std::ofstream& handler);

};

#endif
