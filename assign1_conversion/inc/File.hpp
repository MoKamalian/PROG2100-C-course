
/*
 * author: amir kamalian
 * date:   22 jan 2O23
 *
 *
 */

/*
 * This interface is meant to be implemented by
 * types that will store a source file with the
 * '.cpp' file extension.
 *      - only method included here is for accessing
 *        the vector containing the string of the
 *        source file.
 */

#ifndef FILE
#define FILE

#include <iostream>
#include <vector>

class File {

public:
    virtual std::vector<std::string>& getFileStruct();

};

#endif
