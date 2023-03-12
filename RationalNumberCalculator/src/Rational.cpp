/**
 *
 * author: amir kamalian
 * date:   11 mar 2023
 *
 * */


#include "../inc/Rational.h++"


/** Default constructor
 * The default rational number will be 0/1 */
Rational::Rational() = default;

/** Numerator and denominator specified
 * @param _d: must be integer value, specifies denominator
 * @param _n: must be integer value, specified numerator */
Rational::Rational(int _n, int _d) : _nu(_n), _de(_d) {
};

/** For whole numbers
 * @param _wn: integer value that represents a whole number.  The
 * numerator (_nu) is set to the whole number (_wn) and the denominator
 * is set to 1 (_de) */
Rational::Rational(int _wn) : _nu(_wn) {
};

/** String input
 * @param _rn: validated to ensure follows either whole number format or has whole
 * numbers for numerator and denominator */
Rational::Rational(std::string _rn) {
    if(std::regex_match(_rn, std::regex(REGEX_WHOLE))) {

        this->_nu = std::stoi(_rn);

    } else if(std::regex_match(_rn, std::regex(REGEX_RATIONAL))) {
        /* split the rational number into its numerator and denominator then
         * return a rational object */
        this->_nu = std::stoi(_rn.substr(0, _rn.find(DELIMITER)));
        _rn.erase(0, _rn.find(DELIMITER) + DELIMITER_LENGTH);
        this->_de = std::stoi(_rn.substr(0, _rn.find(DELIMITER)));

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





