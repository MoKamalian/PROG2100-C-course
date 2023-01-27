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
#include "../inc/Validation.hpp"

#define VALID_WINDOWS_REGX ".?:(\\[a-zA-Z 0-9]*)*.[a-zA-Z]*.cpp" /* checks for valid input source file */
#define CHARACTER_REPLACE_REGEX ""


using String = std::string;
using std::cout, std::endl;

int main() {
    std::vector<String> testVector = {"#include <iostream>", "cout << x << endl;"};
    FileStruct test(testVector);

    /* testing the replacement and writing to file from the processor class


    Processor::replace(test, "[<]", "&lt");
    Processor::replace(test, "[>]", "&gt");

    cout << test.getFileStruct()[0] << endl;
    cout << test.getFileStruct()[1] << endl;

    */

    /* writing to file: output file is automatically written to directory where
     * program was called */
    std::ofstream output("testOut.html");

    Processor::writeContentToFile(test, output);

    output.close();

    String testInput = "C:\\Documents\\FileInput.cpp";
    String windowsRegex = VALID_WINDOWS_REGX;

    cout << (Validation::validateInput(testInput, windowsRegex) ? "true" : "false") << endl;

    return 0;
}


//TODO:: write the validation class
    //TODO:: need validation for file names
    //TODO:: need validation for proper Windows file format (?)

// https://www.bestprog.net/en/2019/08/04/keywords-default-delete-examples-of-using/

