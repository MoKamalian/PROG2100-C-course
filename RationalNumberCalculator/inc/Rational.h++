/**
 *
 * author: amir kamalian\n
 * date:   12 Mar 2023
 *
 * */

#ifndef RATIONAL_CLASS
#define RATIONAL_CLASS


#include <iostream>
#include <regex>


#define REGEX_RATIONAL "(^-?\\d+/?-?[1-9]*$)"
#define REGEX_WHOLE "(^-?\\d+$)"
#define DELIMITER '/'
#define DELIMITER_LENGTH 1


class Rational {

private:
    int _nu = 0;
    int _de = 1;

public:
    explicit Rational(); //initialize 0/1
    explicit Rational(int _wn); //for whole numbers (example: 5/1)
    explicit Rational(int _n, int _d); // denominator and numerator
    explicit Rational(std::string _rn); // must parse string
    Rational(Rational& r) = default;
    ~Rational() = default;


    /** validator method for rational and whole numbers */
    static Rational validate(std::string& _rn) noexcept;


    /** getters and setters */
    int getDenominator() const;

    int getNumerator() const;

    void setNumerator(int nu);

    void setDenominator(int de);


    /** operator overloads */
    Rational& operator+(Rational& r);

    Rational& operator-(Rational& r);

    Rational& operator*(Rational& r);

    Rational& operator/(Rational& r);


    /** comparison operator overloads */
    bool operator<(Rational& r);

    bool operator>(Rational& r);

    bool operator==(Rational& r);


    /** output operator overloads */
    friend std::ostream& operator<<(std::ostream& stream, Rational& r);


};



#endif







