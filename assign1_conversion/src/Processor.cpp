

/*
 * implementation for processing and writing to file
 */

#include "../inc/Processor.hpp"

/* regex_pattern is what will be replaced by replacement
 *      - the lines from fileStruct are converted
 *        one at a time
 *      - original fileStruct is manipulated (not copied) */
void Processor::replace(File& fileStruct, const std::string& regex_pattern, const std::string& replacement) {
    for(std::string& line : fileStruct.getFileStruct()) {
        line = std::regex_replace(line, std::regex(regex_pattern), replacement);
    }
};

/* ideally handler is html file but not necessary
 *      - validation of handler is not done here so
 *        handler file does not exist then file may not be written to */
void Processor::writeContentToFile(File& fileStruct, std::ofstream& handler) {
    handler << "\\<PRE>";
    for(std::string& line : fileStruct.getFileStruct()) {
        handler << line;
        handler << "\n";
    }
    handler << "\\</PRE>";
};



