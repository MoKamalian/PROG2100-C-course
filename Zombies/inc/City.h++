/**
 *
 * author: amir kamalian
 * date:   3 Apr 2023
 *
 */


#ifndef CITY_H
#define CITY_H


#include <iostream>
#include <memory>
#include <optional>
#include "ISpecies.h++"
#include "Organism.h++"


template<int H = 20, int W = 20>
class City {
protected:
    int h = H;
    int w = W;
    ISpecies* grid[H][W];

public:


    City() = default;
    City(City&) = default;
    City(City&&) noexcept = default;
    City& operator=(const City&) = default;
    City& operator=(City&&) noexcept = delete;
    ~City() = default;

    /** Insert a conforming ISpecies type into grid */
    bool insert(ISpecies* sp, int x, int y) noexcept;

    /** moves ISpecies type in position whether occupied or not */
    bool moveInto(ISpecies* sp, int x, int y) noexcept;

    /** clears a position freeing it of any objects */
    void clearPosition(int x, int y);

    /** Checks if the position on the grid is occupied with
     * type that conforms to ISpecies */
    bool checkPosition(int x, int y) noexcept;

     /** checks if grid coordinate is within grid bounds */
    bool checkBounds(int x, int y) const noexcept;

    /** getters and setter methods */
    [[nodiscard]]
    std::optional<ISpecies*> getOrganism(int x, int y) const;

    int getHeight() const;
    int getWidth() const;

    /** stream output for printing out the city grid */
    template<int _h, int _w>
    friend std::ostream& operator<<(std::ostream& output, const City<_h, _w>& city);

};


/** Template class implementation of City */

/** Insert a type that conforms to ISpecies within grid bounds
 * @param sp: conforming ISpecies type to be inserted
 * @param x: the x coordinate
 * @param y: the y coordinate
 * @returns true if insertion was successful, false otherwise */
template<int H, int W>
bool City<H, W>::insert(ISpecies* sp, int x, int y) noexcept {
    if(this->checkPosition(x, y)) {
        this->grid[y][x] = sp;
        return true;
    } else {
        return false;
    }
};

/** moves ISpecies type in position whether occupied or not
 * @param sp: conforming ISpecies type to be inserted
 * @param x: the x coordinate
 * @param y: the y coordinate
 * @returns true if the ISpecies type was able to move into position */
 template<int H, int W>
bool City<H, W>::moveInto(ISpecies* sp, int x, int y) noexcept {
    if(this->checkBounds(x, y)) {
        this->grid[y][x] = sp;
        return true;
    } else {
        return false;
    }
};

/** clears a position freeing it of any objects */
template<int H, int W>
void City<H, W>::clearPosition(int x, int y) {
    if(this->checkBounds(x, y)) {
        this->grid[y][x] = nullptr;
    }
};

/** Check if the position on the grid is occupied with conforming type
 * to ISpecies
 * @param x: the x coordinate
 * @param y: the y coordinate
 * @returns true if the position is free, false if position is occupied or
 * out of bounds */
template<int H, int W>
bool City<H, W>::checkPosition(int x, int y) noexcept {
    if(this->checkBounds(x, y)) {
        return this->grid[y][x] == nullptr;
    } else {
        return false;
    }
};

/** Checks whether the coordinate given is within bounds of grid
 * @param x: given x coordinate
 * @param y: given y coordinate
 * @returns true if the grid coordinates given are within bounds,
 * false otherwise */
template<int H, int W>
bool City<H, W>::checkBounds(int x, int y) const noexcept {
    return !((x < 0) || (x > this->w) || (y < 0) || (y > this->h));
};

/** getter and setter methods */
/** Grab the organism at defined grid location.  All coordinates must be
 * within bounds.
 * @param x: the x coordinate
 * @param y: the y coordinate
 * @return An organism that conforms to ISpecies.  */
template<int H, int W>
std::optional<ISpecies*> City<H, W>::getOrganism(int x, int y) const {
    if(!this->checkBounds(x, y)) {
        return std::nullopt; /// not within bounds
    } else {
        return this->grid[y][x] == nullptr ? std::nullopt : std::optional<ISpecies*>{this->grid[y][x]};
    }
};

template<int H, int W>
int City<H, W>::getHeight() const {
    return this->h;
};

template<int H, int W>
int City<H, W>::getWidth() const {
    return this->w;
};


/** output stream operator overload, prints out the grid */
template<int H, int W>
std::ostream& operator<<(std::ostream& output, const City<H, W>& city) {
    for(int i=0; i<city.h; i++) {
        output << "| ";
        for(int j=0; j<city.w; j++) {
            if(city.grid[i][j] == nullptr) {
                output << " - ";
            } else {
                city.grid[i][j]->print();
            }
        }

        output << " |\n";
    }
    return output;
};



#endif



