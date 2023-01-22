

/*
 * implementation for processing and writing to file
 */

#include "../inc/Processor.hpp"


void Processor::replace(File& fileStruct) {
    for(std::string& line : fileStruct.getFileStruct()) {
        for(char& c : line) {
            if(c == '>') {
                // replace with &gt
            } else if(c == '<') {
                // replace with &lt
            }
        } /* next char in line */
    } /* next line */
};

void Processor::writeContentToFile(File& fileStruct, std::fstream handler) {

};



