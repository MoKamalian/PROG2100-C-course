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

    /** The two functions used to simplify the fraction to its lowest common denominator */
    void _simplify_(int& i, int& j);
    static int _GCD_(int i, int j);

public:
    explicit Rational(); //initialize 0/1
    explicit Rational(int _wn); //for whole numbers (example: 5/1)
    explicit Rational(int _n, int _d); // denominator and numerator
    explicit Rational(std::string _rn); // must parse string
    Rational(Rational& r) = default;
    ~Rational() = default;


    /** reduces _nu and _de to their lowest form */
    void reduceRational();


    /** validator method for rational and whole numbers */
    static Rational validate(std::string& _rn) noexcept;


    /** getters and setters */
    int getDenominator() const;

    int getNumerator() const;

    void setNumerator(int nu);

    void setDenominator(int de);


    /** operator overloads */
    Rational operator+(Rational& r);

    Rational operator-(Rational& r);

    Rational operator*(Rational& r);

    Rational operator/(Rational& r);


    /** comparison operator overloads */
    bool operator<(const Rational& r) const;

    bool operator>(const Rational& r) const;

    bool operator==(const Rational& r) const;


    /** output operator overload */
    friend std::ostream& operator<<(std::ostream& stream, Rational& r);


};



#endif




