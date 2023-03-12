/**
 *
 * author: amir kamalian
 * date:   12 Mar 2023
 *
 * */


#include <iostream>
#include "../inc/Rational.h++"

using std::cout, std::endl;

int main() {


    Rational r = Rational();


    std::string str1 = "123";
    std::string str2 = "-456";
    std::string str3 = "1/-3";
    std::string str4 = "1.33";

    Rational::validate(str1);
    Rational::validate(str2);
    Rational::validate(str3);
    Rational::validate(str4);

    Rational r2 = Rational("1.33");

    cout << r2.getDenominator() << endl;
    cout << r2.getNumerator() << endl;



    return 0;
}
