

/*
 * implementation for processing and writing to file
 */

#include "../inc/Processor.hpp"


void Processor::replace(File& fileStruct, const std::string& regex_pattern, const std::string& replacement) {
    for(std::string& line : fileStruct.getFileStruct()) {
        line = std::regex_replace(line, std::regex(regex_pattern), replacement);
    }
};

void Processor::writeContentToFile(File& fileStruct, std::fstream handler) {

};



