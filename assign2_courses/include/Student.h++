/**
 * author: amir kamalian\n
 * date:   O5 feb 2O23
 *
 *
 */


#ifndef STUDENT
#define STUDENT


#include <iostream>


class Student {
private:
    std::string full_name;
    int num_courses = 1;
    std::string* course_list = new std::string[num_courses];

    /** resizes the courseList array by one */
    void _resize_();

public:
    /**
     * UDC:
     * @param _fname - the full name of the student.  Note, no validation is done here for the name.
     * @return A student object that may or may not contain courses at time of instantiation.
     * */
    Student() = default;
    Student(std::string _fname) : full_name{std::move(_fname)} { /**/ };
    Student(Student& s);
    Student(Student&& s) = default;
    ~Student();

    /** getters and setters */
    [[nodiscard]] int getNumCourses() const { return (this->num_courses - 1); };

    [[nodiscard]] const std::string& getFullName() { return this->full_name; };

    [[nodiscard("Courses array")]] const std::string* getCourseList() const { return this->course_list; };

    void setName(std::string fname) { this->full_name = std::move(fname); };

    /** adding courses to the course list */
    void addCourse(std::string& course_name);

    /** empties the course list and sets number of course to 0 */
    void purgeCourses();

    /** operator overloads */
    friend std::ostream& operator<<(std::ostream& stream, const Student& student) {
        stream << "Name: " + student.full_name << "\n";
        stream << "Number of courses: " << (student.num_courses - 1);
        stream << "\n----------------------------\n";

        for(int i=0; i<student.num_courses - 1; i++) {
            stream << "Course " << (i + 1) << ": " << student.course_list[i] << "\n";
        }

        stream << "____________________________\n";

        return stream;
    };

    /* = sign operator overload needed */

};


#endif


