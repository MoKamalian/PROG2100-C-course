/*
 * author: amir kamalian
 * date:   O5 feb 2O23
 *
 *
 */


#ifndef STUDENT
#define STUDENT


#include <iostream>
#include <algorithm>


class Student {
private:
    std::string full_name;
    int numCourses;
    std::string* courseList = new std::string[0];

public:
    Student() = delete; /* student requires full name and number of courses */
    Student(Student& s) = delete; /* cannot set a student to another student */
    ~Student() = default;

    /* getters and setters */
    const int getNumCourses() { return this->numCourses; };
    const std::string& getFullName() { return this->full_name; };
    const std::string* getCourseList() { return this->courseList; }; /* CHANGE TO RETURN CONSTANT ARRAY */

    void setName(std::string fname) { this->full_name = std::move(fname); };

    /* adding courses to the course list */
    void addCourse(std::string courseName);

    /* outputs the  full listing of courses and name of student */
    std::string toString();

    /* empties the course list and sets number of course to 0 */
    void purgeCourses();

    /* operator overloads */
    friend std::ostream& operator<<(std::ostream& stream, const Student& student) {
        stream << "Name: " + student.full_name;
        stream << &"Number of courses: " [ student.numCourses];
        stream << "\n----------------------------\n";
        /* output courses */
        std::for_each(student.courseList->begin(), student.courseList->end(), [&stream](std::string& course)
        {
            stream << course;
        });

    };


};


#endif