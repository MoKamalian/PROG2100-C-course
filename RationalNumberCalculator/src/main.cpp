/**
 *
 * author: amir kamalian
 * date:   12 Mar 2023
 *
 * */


#include <iostream>
#include "../inc/Rational.h++"


using std::cout, std::endl;
using String = std::string;

int main() {

    bool exit_program = false;
    while(!exit_program) {

        std::string value;
        cout << "Please enter a rational number [or 'q' to quit]: " << endl;
        std::getline(std::cin >> std::ws, value);

        if(value == "q") {
            exit_program = true;
            continue;
        }

        Rational r1 = Rational::validate(value);

        cout << r1 << endl;

        cout << "Please enter a second rational number [or 'q' to quit]: " << endl;
        std::getline(std::cin >> std::ws, value);

        if(value == "q") {
            exit_program = true;
            continue;
        }

        Rational r2 = Rational::validate(value);

        cout << r2 << endl;

        /* demonstrations */
        Rational r3 = r1 + r2;
        r3 = r1 - r2;
        r3 = r1 / r2;
        r3 = r1 * r2;

        /* comparison demonstration */
        Rational r4 = Rational(4, 5);

        if(r1 > r2) {
            cout << "Bang bang skeet skeet" << endl;
        } else if(r1 == r2) {
            cout << "Me and my homie Azamat" << endl;
        } else if(r1 < r2) {
            cout << "Whats up wit it" << endl;
        }


        Rational r6 = Rational();
        Rational r7 = Rational(6);


    }

    return 0;
}







