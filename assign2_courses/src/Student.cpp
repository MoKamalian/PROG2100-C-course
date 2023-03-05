/**
 * author: amir kamalian\n
 * date:   O5 feb 2O23
 *
 */


#include "../include/Student.h++"


/** resizes the course list array increasing the size by one */
void Student::_resize_() {
    this->num_courses += 1;

    std::string* temp = new std::string[this->num_courses];
    for(int i=0; i<this->num_courses; i++) {
        temp[i] = this->course_list[i];
    }

    delete[] this->course_list;
    this->course_list = temp;
};

/** adding courses to the dynamic array */
void Student::addCourse(std::string& course_name) {
    this->course_list[this->num_courses - 1] = course_name;
    this->_resize_();
};

/** Purges the entire course list, reducing the courses size to 1 */
void Student::purgeCourses() {

};


