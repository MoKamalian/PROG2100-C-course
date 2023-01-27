/*
 * author: amir kamalian
 * date:   jan 16 2023
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "../inc/FileStruct.hpp"
#include "../inc/Processor.hpp"

#define VALID_WINDOWS_REGX "^(?!^(PRN|AUX|CLOCK$|NUL|CON|COM\d|LPT\d|..)(..+)?$)[^\x00-\x1f\?:";|/]+$"
#define CHARACTER_REPLACE_REGEX ""


using String = std::string;

int main() {

    /* testing the replacement and writing to file from the processor class */
    std::vector<String> testVector = {"This is a test", "this is another test"};
    FileStruct test(testVector);

    Processor::replace(test, "test", "bubbles");

    std::cout << test.getFileStruct()[0] << std::endl;
    std::cout << test.getFileStruct()[1] << std::endl;

    /* writing to file: output file is automatically written to directory where
     * program was called */
    std::ofstream output("testOut.html");

    Processor::writeContentToFile(test, output);

    output.close();


    return 0;
}


//TODO:: create the file struct
//TODO:: write the processor class
    //TODO:: processor takes in reference to file struct obj and modifies the text
//TODO:: write the validation class
    //TODO:: need validation for file names
    //TODO:: need validation for proper Windows file format (?)

// https://www.bestprog.net/en/2019/08/04/keywords-default-delete-examples-of-using/

