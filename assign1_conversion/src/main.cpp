/*
 * author: amir kamalian
 * date:   jan 16 2023
 *
 */

#include <iostream>
#include <vector>
#include "../inc/FileStruct.hpp"
#include "../inc/Processor.hpp"
#include "../inc/Validation.hpp"
#include "../inc/WindowsFileException.hpp"

#define VALID_WINDOWS_REGEX ".?:(\\\\[a-zA-Z 0-9]*)*.[a-zA-Z]*.cpp" /* checks for valid input of source file */
#define REPLACE_LT "[<]" /* text to replace so that it can be displayed in html */
#define REPLACE_GT "[>]"


using String = std::string;
using std::cout, std::endl, std::cin;

int main() {

    /* file handlers used for reading and writing */
    std::ifstream readFile;
    std::ofstream writeFile("output.html");

    /* main program loop */
    String line;
    bool exit = false;
    while(!exit) {

        /* input collection and validation */
        cout << "Please enter the full path of the input source file or 'q' to quit [must have .cpp extension]: ";
        std::getline(cin, line);
        if(line == "q") { /* user quit the program */
            exit = true;
            continue;
        } else {
            try { /* I would not do this normally; exception thrown when file pattern does not match VALID_WINDOWS_REGEX */
                if(!Validation::validateInput(line, VALID_WINDOWS_REGEX)) {
                    throw WindowsFileException();
                }
            } catch(WindowsFileException& wfe) {
                cout << wfe.what() << endl;
            }
        }

        /* check if the source file exists; throws ios_base::failure exception if
         * it fails to read the file */
        readFile.open(line);
        try {
            if(readFile.fail()) {
                throw std::ios_base::failure("[file note found]");
            }
        } catch(std::ios_base::failure& fnf) {
            cout << fnf.what() << endl;
        }

        /* reading the source file */
        std::vector<String> lines;
        String fileLine;
        while(std::getline(readFile, fileLine)) {
            lines.push_back(fileLine);
        }
        FileStruct sourceFile(lines);

        /* replacement processing and writing to file */
        Processor::replace(sourceFile, REPLACE_LT, "&lt");
        Processor::replace(sourceFile, REPLACE_GT, "&gt");

        /* writing contents to output html file */
        Processor::writeContentToFile(sourceFile, writeFile);

        exit = true;
    }

    writeFile.close();
    readFile.close();

    return 0;
}



