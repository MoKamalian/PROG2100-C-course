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


using String = std::string;

int main() {


    /* testing the replacement method from the processor class */
    std::vector<String> testVector = {"This is a test", "this is another test"};
    FileStruct test(testVector);

    Processor::replace(test, "test", "bubbles");

    std::cout << test.getFileStruct()[0] << std::endl;
    std::cout << test.getFileStruct()[1] << std::endl;

    return 0;
}


//TODO:: create the file struct
//TODO:: write the processor class
    //TODO:: processor takes in reference to file struct obj and modifies the text
//TODO:: write the validation class
    //TODO:: need validation for file names
    //TODO:: need validation for proper Windows file format (?)

