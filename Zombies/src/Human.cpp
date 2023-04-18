/**
 *
 *
 * author: amir kamalian
 * date:   4 April 2023
 *
 * */


#include "../inc/Human.h++"


/** constructor */
Human::Human(int _w, int _h) : survive_count{0}, Organism(_w, _h) {

};

/** print to console */
void Human::print() {
    std::cout << "\033[48;5;211m"; // background
    std::cout << "\033[38;5;15m" << " H " << "\033[0m"; // foreground and reset
};

/** Print a human in grid */
std::string Human::toString() {
    return "H";
};

/** Move functionality for human */
void Human::move(int x, int y) {
    this->coordinate.first = x;
    this->coordinate.second = y;

    this->moved = true;
};

/** Spawn another human within game bounds */
std::unique_ptr<ISpecies> Human::spawn() {
    Human* h = new Human();
    return std::unique_ptr<ISpecies>(h);
};


/** getters and setters */
std::pair<unsigned int, unsigned int> Human::getPosition() const {
    return this->coordinate;
};

void Human::setPosition(int x, int y) {
    this->coordinate.first = x;
    this->coordinate.second = y;
};


/** resetting the move variables */
bool Human::didMove() {
    return this->moved = true;
};

bool Human::resetMove() {
    return this->moved = false;
};

bool Human::getMoveStatus() const {
    return this->moved;
};

/** updates the survival count of the human object */
int Human::updateSurvive() noexcept {
    return this->survive_count++;
};

/** resets the survival count back to 0 */
int Human::resetSurvive() noexcept {
    return this->survive_count = 0;
};






