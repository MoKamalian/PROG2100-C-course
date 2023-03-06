/**
 * author: amir kamalian\n
 * date:   O5 feb 2O23
 *
 */


#include "../include/Student.h++"

Student::Student(std::string _fname) : full_name{std::move(_fname)} {
    std::cout << "Constructor called" << std::endl;
};

/** Copy Constructor:
 * @param s: The Student object to copy information from
 * @return the new student object will have a copy of the
 * list of courses and the number of courses NOT the name */
Student::Student(Student& s) {
    this->num_courses = (s.getNumCourses() + 1);

    const std::string* _courses = s.getCourseList();
    for(int i=0; i<s.getNumCourses(); i++) {
        this->course_list[i] = _courses[i];
    }

    std::cout << "Copy constructor called" << std::endl;
};

/** destructor */
Student::~Student() {
    if(this->course_list != nullptr) {
        delete[] this->course_list;
    } else {
        return;
    }
    std::cout << "Destructor called" << std::endl;
};

/** operator overload:
 * @param st: the Student object that will be copied
 * @return unlike the copy constructor; ALL information is copied to
 * the assigned object including the name */
Student& Student::operator=(const Student& st) {
    if(&st != this) {

        full_name = st.full_name;
        num_courses = st.num_courses;

        std::string* temp = new std::string[num_courses];

        std::copy(st.course_list, st.course_list + st.num_courses, temp);
        std::swap(course_list, temp);

        delete[] temp;
    }

    std::cout << "" << std::endl;
    return *this;
}

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
void Student::addCourse(std::string course_name) {
    this->course_list[this->num_courses - 1] = course_name;
    this->_resize_();
};

/** Purges the entire course list, reducing the courses size to 1
 * also resets the number of courses member variable to the default 1 */
void Student::purgeCourses() {
    this->num_courses = 1;
    delete[] this->course_list;
};

/** For purposes of string manipulation and desiring a string version of
 * the student object
 * @return string description of the student object (i.e. name, number of courses, and courses list) */
std::string Student::toString() const {

    std::string s = "\n===========\n" + this->full_name + "\n";
    s += "Number of courses: " + std::to_string(this->num_courses - 1) + "\n";
    for(int i=0; i<this->num_courses - 1; i++) {
        s += "Course " + std::to_string(i + 1) + ": " + this->course_list[i] + "\n";
    }
    s += "===========\n";

    return s;
};

