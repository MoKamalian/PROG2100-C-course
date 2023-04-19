/**
 *
 * author: amir kamalian
 * date:   22 Mar 2023
 *
 * */


#ifndef ZOMBIE_H
#define ZOMBIE_H


#include <iostream>
#include <memory>
#include <tuple>
#include "ISpecies.h++"
#include "IEdible.h++"
#include "City.h++"
#include "Organism.h++"


class Zombie : public Organism, public IEdible {
private:
    int starve_count;
    int spawn_count;
public:
    Zombie() = default;
    Zombie(Zombie&) = delete;
    Zombie(Zombie&&) noexcept = default;
    Zombie& operator=(const Zombie&) = default;
    Zombie& operator=(Zombie&&) noexcept = default;
    explicit Zombie(int _h, int _w);
    ~Zombie() = default;

    std::string toString() override;
    void print() override;
    void move(int x, int y) override;

    /** methods associated with zombie life cycle
    * i.e. starvation, breeding spawning */
    int updateStarve() override;

    int getSurviveCount() const;

    void resetStarveCount() override;

    int updateSpawn() override;

    void resetSpawnCount() override;

    int getSpawnCount() const override;

    [[nodiscard("Zombie Object")]]
    ISpecies* spawn() override;

    /** getters and setters */
    [[nodiscard("Contains position on grid")]]
    std::pair<unsigned int, unsigned int> getPosition() const override;

    void setPosition(int x, int y) override;

    bool getMoveStatus() const override;

    /** for resetting the moved variable */
    bool didMove() override;
    bool resetMove() override;



};



#endif


