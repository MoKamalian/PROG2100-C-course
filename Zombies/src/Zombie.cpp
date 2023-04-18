/**
 *
 *
 * author: amir kamalian
 * date:   7 april 2023
 *
 *
 * */


#include "../inc/Zombie.h++"


Zombie::Zombie(int _h, int _w) : starve_count{0}, spawn_count{0}, Organism(_w, _h) {
    this->isEdible = false;
};


/** print to console */
void Zombie::print() {
    std::cout << "\033[48;5;124m";
    std::cout << "\033[38;5;15m" << " Z " << "\033[0m";
};

/** Print a human in grid */
std::string Zombie::toString() {
    return "Z";
};

/** Move functionality for zombie
 * @param x: the x coordinate
 * @param y: the y coordinate
 * @note: the given coordinate must be unoccupied */
void Zombie::move(int x, int y) {
    this->coordinate.first = x;
    this->coordinate.second = y;

    this->moved = true;
};


/** methods associated with zombie life cycle
    * i.e. starvation, breeding spawning */

/** updates the starvation count by one
 * @returns the starvation count to be used to determine
 * if the zombie should starve (i.e. removed from grid) */
int Zombie::updateStarve() {
    return this->starve_count++;
};

/** updates the spawn count by one
 * @returns the spawn count that can be used to
 * determine if a new zombie should be spawned */
int Zombie::updateSpawn() {
    return this->spawn_count++;
};

/** Spawn another zombie object on heap
 * @note Spawned zombie is not initialized
 * with grid coordinates.  This must be set
 * after spawning of the zombie. */
std::unique_ptr<ISpecies> Zombie::spawn() {
    Zombie* _z = new Zombie();
    return std::unique_ptr<ISpecies>(_z);
};


/** getters and setters */
std::pair<unsigned int, unsigned int> Zombie::getPosition() const {
    return this->coordinate;
};

void Zombie::setPosition(int x, int y) {
    this->coordinate.first = x;
    this->coordinate.second = y;
};

bool Zombie::getMoveStatus() const {
    return this->moved;
};


/** resetting move variable */
bool Zombie::didMove() {
    return this->moved = true;
};

bool Zombie::resetMove() {
    return this->moved = false;
}







