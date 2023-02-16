/*
 * author: amir kamalian
 * date:   O5 feb 2O23
 *
 */


#include "../include/Student.h++"


/* resizes the course list array increasing the size by one */
void Student::resize() {

    std::string* temp = new std::string[this->courseList->size() + 1];
    std::copy(this->courseList->begin(), this->courseList->end(), temp);

    delete[] this->courseList;
    this->courseList = temp;
};

/* adding courses to the dynamic array */
void Student::addCourse(std::string& courseName) {
    this->resize();
    this->courseList->push_back(courseName);
};



