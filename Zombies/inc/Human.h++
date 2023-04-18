/**
 *
 * author: amir kamalian
 * date:   22 Mar 2023
 *
 * */

#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <memory>
#include <tuple>
#include "IEdible.h++"
#include "Organism.h++"


class Human : public Organism, public IEdible {
private:
    int survive_count;
public:
    Human() = default;
    Human(Human&) = delete;
    Human(Human&&) noexcept = default;
    Human& operator=(const Human&) = default;
    Human& operator=(Human&&) noexcept = default;
    explicit Human(int _w, int _h);
    ~Human() override = default;

    std::string toString() override;
    void print() override;
    void move(int x, int y) override;
    std::unique_ptr<ISpecies> spawn() override;

    /** getters and setters */
    [[nodiscard]]
    std::pair<unsigned int, unsigned int> getPosition() const override;

    void setPosition(int x, int y) override;

    bool getMoveStatus() const override;

    bool didMove() override;
    bool resetMove() override;

    /** methods to keep track of the survival count of the human object */
    int updateSurvive() noexcept;
    int resetSurvive() noexcept;

};



#endif




