/*
 * author: amir kamalian
 * date:   jan 16 2023
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include "../inc/FileStruct.hpp"
#include "../inc/Processor.hpp"
#include "../inc/Validation.hpp"
#include "../inc/WindowsFileException.hpp"

#define VALID_WINDOWS_REGEX ".?:(\\\\[a-zA-Z 0-9]*)*.[a-zA-Z]*.cpp" /* checks for valid input source file */
#define REPLACE_LT "[<]"
#define REPLACE_GT "[>]"


using String = std::string;
using std::cout, std::endl, std::cin;

int main() {

    /* main program loop */
    std::ifstream readFile;
    std::ofstream writeFile("output.html");

    String line;
    bool exit = false;
    while(!exit) {

        /* input collection and validation */
        cout << "Please enter the full path of the input source file or 'q' to quit [must have .cpp extension]: ";
        std::getline(cin, line);
        if(line == "q") {
            exit = true;
            continue;
        } else {
            try { /* I would not do this normally */
                if(!Validation::validateInput(line, VALID_WINDOWS_REGEX)) {
                    throw WindowsFileException();
                }
            } catch(WindowsFileException& wfe) {
                cout << wfe.what() << endl;
            }
        }

        /* check if the source file exists */
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

        Processor::writeContentToFile(sourceFile, writeFile);

        exit = true;
    }

    writeFile.close();
    readFile.close();


    return 0;
}



