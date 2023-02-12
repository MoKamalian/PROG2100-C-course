
#ifndef FILE_STRUCT
#define FILE_STRUCT

/*
 * author: amir kamalian
 * date:   22 jan 2O23
 *
 */

/* data struct that will be used to store the lines
 * of the input file.
 *      - each line is stored as a string element
 *      - the file struct implements from File
 *        interface.
 *      - There is no setter involved for this class
 *        once the file has been read, more lines
 *        cannot be added.
 */

#include <iostream>
#include <vector>
#include "File.hpp"

struct FileStruct : public File {

private:
    std::vector<std::string> lines;

public:
    explicit FileStruct(std::vector<std::string> lines) : lines{std::move(lines)} {};
    FileStruct() = delete; /* you must provide the string lines when instantiating */
    ~FileStruct() = default;

    /* getter */
    std::vector<std::string>& getFileStruct() override {
        return this->lines;
    };

    /* foreach method requires function pointer as input */
    void forEach(void (*function)(std::string line)) {
        for(std::string& line : this->lines) {
            function(line);
        }
    };

};


#endif
