/**
 *
 * author: amir kamalian
 * date:   22 Mar 2023
 *
 * */


#ifndef ORGANISM_H
#define ORGANISM_H


#include <iostream>
#include <memory>
#include <tuple>
#include "ISpecies.h++"


class Organism : public ISpecies {

protected:
    bool moved = false;
    std::pair<unsigned int, unsigned int> coordinate; // default initialize to 0, 0

public:
    Organism() = default;
    explicit Organism(int _x, int _y);
    ~Organism() = default;

    virtual std::string toString() = 0;
    virtual void print() = 0;
    virtual void move(int x, int y) = 0;
    virtual ISpecies* spawn() = 0;

    /** getters and setters */
    virtual std::pair<unsigned int, unsigned int> getPosition() const  = 0;

    virtual void setPosition(int x, int y) = 0;

    virtual bool didMove() = 0;
    virtual bool resetMove() = 0;
    virtual bool getMoveStatus() const = 0;

    virtual int getSurviveCount() const = 0;
    virtual void resetStarveCount() = 0;

    virtual int updateStarve() = 0;
    virtual int updateSpawn() = 0;

    virtual int getSpawnCount() const = 0;
    virtual void resetSpawnCount() = 0;

    friend std::ostream& operator<<(std::ostream& ostream, Organism& organism);

};



#endif


