/**
 *
 * author: amir kamalian
 * date:   11 mar 2023
 *
 * */


#include "../inc/Rational.h++"


/** Default constructor
 * The default rational number will be 0/1 */
Rational::Rational() {
    std::cout << "STRING CONSTRUCTOR CALLED" << std::endl;
};

/** Numerator and denominator specified
 * @param _d: must be integer value, specifies denominator
 * @param _n: must be integer value, specified numerator */
Rational::Rational(int _n, int _d) {
    std::cout << "TWO INTEGERS CONSTRUCTOR CALLED" << std::endl;
    if(_n < 0 and _d > 0) {
        this->_nu = _n;
        this->_de = (_d * -1);
    } else if(_n > 0 and _d < 0) {
        this->_nu = (_n * -1);
        this->_de = _d;
    } else {
        this->_nu = _n;
        this->_de = _d;
    }
};

/** For whole numbers
 * @param _wn: integer value that represents a whole number.  The
 * numerator (_nu) is set to the whole number (_wn) and the denominator
 * is set to 1 (_de) */
Rational::Rational(int _wn) : _nu(_wn) {
    std::cout << "WHOLE NUMBER CONSTRUCTOR CALLED" << std::endl;
};

/** String input
 * @param _rn: validated to ensure follows either whole number format or has whole
 * numbers for numerator and denominator */
Rational::Rational(std::string _rn) {
    std::cout << "STRING CONSTRUCTOR CALLED" << std::endl;
    if(std::regex_match(_rn, std::regex(REGEX_WHOLE))) {

        this->_nu = std::stoi(_rn);

    } else if(std::regex_match(_rn, std::regex(REGEX_RATIONAL))) {
        /* split the rational number into its numerator and denominator then
         * return a rational object */
        this->_nu = std::stoi(_rn.substr(0, _rn.find(DELIMITER)));
        _rn.erase(0, _rn.find(DELIMITER) + DELIMITER_LENGTH);
        this->_de = std::stoi(_rn.substr(0, _rn.find(DELIMITER)));

        /* ensure the negative sign is preserved for both numbers */
        if(this->_nu < 0) {
            this->_de = this->_de * -1;
        } else if(this->_de < 0) {
            this->_nu = this->_nu * -1;
        }

    }
    /* default values used for invalid input */
};



/** Validation method for rational and whole numbers
 * @param: _rn: the string input to be validated against REGEX_PATTERN */
Rational Rational::validate(std::string& _rn) noexcept {
    return Rational(_rn);
    /*
   if(std::regex_match(_rn, std::regex(REGEX_WHOLE))) {

       return Rational(std::stoi(_rn));

   } else if(std::regex_match(_rn, std::regex(REGEX_RATIONAL))) {
       /* split the rational number into its numerator and denominator then
        * return a rational object
        int n = std::stoi(_rn.substr(0, _rn.find(DELIMITER)));
        _rn.erase(0, _rn.find(DELIMITER) + DELIMITER_LENGTH);
        int d = std::stoi(_rn.substr(0, _rn.find(DELIMITER)));

        return Rational(n, d);

    } else {
        if _rn is invalid expression the default constructor is used with 0/1
         * as the rational number
        return Rational();

    }* */

};

/** Finds the greatest common denominator and simplifies the fraction.
 * The simplify function does not change member variables.
 * To change the member variables use reduceRational().
 * @refitem link: https://www.tutorialspoint.com/reduce-the-fraction-to-its-lowest-form-in-cplusplus */
void Rational::reduceRational() {
    int gcd = this->_GCD_(this->_nu, this->_de);
    if(gcd < 0) gcd *= -1;
    this->_nu /= gcd;
    this->_de /= gcd;
};

void Rational::_simplify_(int& i, int& j) {
    int gcd = this->_GCD_(i, j);
    if(gcd < 0) gcd *= -1;
    i /= gcd;
    j /= gcd;
};
/** Find the greatest common denominator */
int Rational::_GCD_(int i, int j) {
    if(j == 0)
        return i;
    return _GCD_(j, i % j);
};



/** getters and setters */
int Rational::getNumerator() const {
    return this->_nu;
};

int Rational::getDenominator() const {
    return this->_de;
};

void Rational::setNumerator(int nu) {
    this->_nu;
};

void Rational::setDenominator(int de) {
    this->_de;
};



/** Comparison operator overloads */
bool Rational::operator<(const Rational& r) const {
    std::cout << "LESS THAN OPERATOR CALLED" << std::endl;
    if(this->_de and r._de > 0) {
        return ((this->_nu * r._de) < (this->_de * r._nu));
    } else if(this->_de) {
        return true;
    }
};

bool Rational::operator>(const Rational& r) const {
    std::cout << "GREATER THAN OPERATOR CALLED" << std::endl;
    if(this->_de and r._de > 0) {
        return ((this->_nu * r._de) > (this->_de * r._nu));
    } else if(this->_de < 0){
        return false;
    }
};

bool Rational::operator==(const Rational& r) const {
    std::cout << "EQUALS OPERATOR CALLED" << std::endl;
    return ((this->_nu * r._de) == (this->_de * r._nu));
};



/** Mathematical operation overloads */
/** @refitem link: https://stackoverflow.com/questions/11199317/what-would-be-the-code-to-add-and-subtract-fractions-in-c */
Rational Rational::operator+(Rational& r) {
    std::cout << "ADDITION OPERATOR CALLED" << std::endl;
    int numerator = (this->_nu * r._de) + (r._nu * this->_de);
    int denominator = (this->_de * r._de);

    this->_simplify_(numerator, denominator);
    return Rational(numerator, denominator);

};

/** @refitem link: https://stackoverflow.com/questions/11199317/what-would-be-the-code-to-add-and-subtract-fractions-in-c */
Rational Rational::operator-(Rational& r) {
    std::cout << "SUBTRACTION OPERATOR CALLED" << std::endl;
    int numerator = (this->_nu * r._de) - (r._nu * this->_de);
    int denominator = (this->_de * r._de);

    std::cout << numerator << "/" << denominator << std::endl;

    this->_simplify_(numerator, denominator);
    return Rational(numerator, denominator);
};

Rational Rational::operator*(Rational& r) {
    std::cout << "MULTIPLICATION OPERATOR CALLED" << std::endl;
    int numerator = this->_nu * r._nu;
    int denominator = this->_de * r._de;

    this->_simplify_(numerator, denominator);
    return Rational(numerator, denominator);
};

/** If there is a division by 0; a default object is returned
 * with 0/1 as the rational number. */
Rational Rational::operator/(Rational& r) {
    std::cout << "DIVISION OPERATOR CALLED" << std::endl;
    if(r._nu == 0) {
        return Rational();
    }

    int numerator = this->_nu * r._de;
    int denominator = this->_de * r._nu;

    this->_simplify_(numerator, denominator);
    return Rational(numerator, denominator);
};



/** Output operator for printing out the Rational object */
std::ostream& operator<<(std::ostream& stream, Rational& r) {
    stream << r._nu << "/" << r._de;
    return stream;
};






