

#ifndef SPECIES_H
#define SPECIES_H


#include <iostream>
#include <memory>

/** Species interface
 * @details All conforming types must be able
 * to print */
class ISpecies {
public:
    ISpecies() = default;
    virtual ~ISpecies() = default;
    virtual std::string toString() = 0;
    virtual void print() = 0;
    virtual void move(int x, int y) = 0;
    virtual std::unique_ptr<ISpecies> spawn() = 0;
};



#endif


