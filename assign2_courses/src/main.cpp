
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

    /* main program loop */
    bool exit = false;
    while(not exit) {

        Student student;

        /* asking for student name */
        String student_name;
        cout << "Please enter the students name [type and enter 'q' to exit the program]: ";
        std::getline(cin >> std::ws, student_name);

        if(student_name.empty()) {
            cout << "[error : name cannot be blank]" << endl;
            continue;
        } else if(student_name == "q") {
            exit = true;
            continue;
        }

        student.setName(student_name);

        cout << "\n_________________________________________\n";

        /* populating course information */
        cout << "Please enter the course names one by one [type and enter 'done' when finished]: " << endl;

        bool course_entry_done = false;
        while(not course_entry_done) {

            String course_name;
            cout << "Course name: ";
            std::getline(cin >> std::ws, course_name);

            if(course_name == "q" || course_name == "done") {
                course_entry_done = true;
                continue;
            } else {
               student.addCourse(course_name);
            }

        } // end course entry while loop

        cout << student.toString() << endl;


        /* asking for the second students name and copying first students courses
         * over to the new student */
        cout << "Please enter the 2nd students name [type and enter 'q' to exit the program]: ";
        std::getline(cin >> std::ws, student_name);

        if(student_name.empty()) {
            cout << "[error : name cannot be blank]" << endl;
            continue;
        } else if(student_name == "q") {
            exit = true;
            continue;
        }

        Student student2 = student;
        student2.setName(student_name);

        cout << student2 << endl;

        /* displaying student 1s name and course list after purging */
        student.purgeCourses();
        cout << student << endl;

        /* check that a deep copy has occurred */
        cout << student2 << endl;

        /* demonstration of custom assignment operator */
        Student student3;
        student3 = student2;

        cout << "========== Student 3 ==========" << endl;
        cout << student3 << endl;


    } // end main while loop


    return 0;

};









