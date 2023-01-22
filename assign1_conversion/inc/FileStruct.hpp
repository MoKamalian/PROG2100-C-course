
#ifndef FILE_STRUCT
#define FILE_STRUCT

/*
 * author: amir kamalian
 * date:   22 jan 2O23
 *
 */

/* data struct that will be used to store the lines
 * of the input file.
 *      - each line is stored as a row inside a
 *        2D vector
 *      - the file struct implements from File
 *        interface.
 */

#include <iostream>
#include <vector>
#include "File.hpp"

struct FileStruct : public File {

private:
    std::vector<std::string> lines;

public:
    std::vector<std::string>& getFileStruct() override {
        return this->lines;
    };

};


#endif
