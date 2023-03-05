
/*
 *
 * author: amir kamalian
 * date:   O5 feb 2O23
 *
 */


#include <iostream>
#include "../include/Student.h++"


using String = std::string;
using std::cout, std::endl, std::cin;

int main() {


    Student st("I. C. Wiener");

    String course = "PROG2100";
    String course2 = "PROG2200";
    String course3 = "INFT2100";
    String course4 = "MOBI3002";
    String course5 = "INET2100";

    st.addCourse(course);
    st.addCourse(course2);
    st.addCourse(course3);
    st.addCourse(course4);
    st.addCourse(course5);

    /* main program loop */
    bool exit = false;
    while(not exit) {

        Student student;

        /* asking for student name */
        String student_name;
        cout << "Please enter the students name: ";
        std::getline(cin >> std::ws, student_name);

        if(student_name.empty()) {
            cout << "[error : name cannot be blank]" << endl;
            continue;
        }

        student.setName(student_name);

        /* populating course information */
        bool course_entry_done = false;
        while(not course_entry_done) {

            String course_name;
            cout << "Please enter the course names one by one: " << endl;
            cout << "Course name: ";
            std::getline(cin >> std::ws, course_name);

            if(course_name == "q") {
                course_entry_done = true;
                continue;
            } else {
                student.addCourse(course_name);
            }

        }



    }


    return 0;

};









