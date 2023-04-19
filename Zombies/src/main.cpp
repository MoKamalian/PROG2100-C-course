/**
 *
 * author: amir kamalian
 * date:   22 Mar 2023
 *
 *
 * */


#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <vector>
#include <tuple>
#include "../inc/City.h++"
#include "../inc/Organism.h++"
#include "../inc/Zombie.h++"
#include "../inc/Human.h++"


#define ZOMBIE_SPAWN_LIMIT 8
#define STARVE_COUNT 3
#define HUMAN_SPAWN_LIMIT 3


using std::cout, std::endl;

using coordinate = std::pair<int, int>;
using coordinate_pairs = std::vector<coordinate>;


/** below are the methods used for actual functionality of the application */
template<typename T>
void updateGrid(T& grid, Organism& organism);

/** finds the valid coordinates an organism can move to  coordinate_pairs (*_func)(T&, coordinate)*/
template<typename T, typename F>
coordinate_pairs findValidCoordinate(T& grid, coordinate pos, F&& _func);

/** returns the valid coordinates for Zombie */
template<typename T>
coordinate_pairs returnValidsForZombie(T& grid, coordinate coord);

/** returns the valid coordinates for Human */
template<typename T>
coordinate_pairs returnValidsForHuman(T& grid, coordinate coord);

/** performs a move operation for a Zombie object */
template<typename T>
void performMoveForZombie(T& grid, Organism& organism, coordinate_pairs& valid_pairs);

/** performs a move operation for a Human object */
template<typename T>
void performMoveForHuman(T& grid, Organism& organism, coordinate_pairs& valid_pairs);

/** generates a random integer value within the provided range */
int generateRandom(int being, int end);

/** this function is used to determine which coordinate contains a human
 * from list of valid coordinates */
template<typename T>
std::optional<coordinate> findHumanIn(T& grid, coordinate_pairs valids);

/** populates the grid with the appropriate number of zombies and humans specified */
template<typename T>
void populateCity(T& grid, int numZombies, int numHumans);


int main() {
    /** main loop of the program */


    City grid = City<20, 20>();
    Zombie z1 = Zombie();
    Zombie z2 = Zombie();
    Human h1 = Human();

    grid.insert(&z1, 5, 5);
    z1.setPosition(5, 5);

    grid.insert(&h1, 6, 6);
    h1.setPosition(6, 6);

    grid.insert(&z2, 3, 4);
    z2.setPosition(3, 4);

    cout << grid << endl;

    coordinate coord = coordinate(5, 5);
    coordinate h_coord = coordinate(6, 6);

    coordinate_pairs valids = returnValidsForZombie(grid, coord);
    coordinate_pairs h_valids = returnValidsForHuman(grid,  h_coord);

    for(coordinate pairs : valids) {
        cout << pairs.first << " " << pairs.second << endl;
    }


    performMoveForZombie(grid, z1, valids);
    performMoveForHuman(grid, h1, h_valids);

    cout << grid << endl;

    return 0;
};


/** implementations */
/** populates the city grid with the appropriate number of zombies and humans
 * @param grid: grid to be populated
 * @param numZombies: the number of zombies to populate
 * @param numHumans: the number of humans to populate */
template<typename T>
void populateCity(T& grid, int numZombies, int numHumans);

/** updates the grid by performing moves for zombie and human accordingly
 * @param grid: grid to perform the moves, 2D vector
 * @param organism: the organism to perform the move upon */
template<typename T>
void updateGrid(T& grid, Organism& organism) {
    if(organism.toString() == "H") {
        coordinate_pairs valid_coordinates = findValidCoordinate(grid, organism.getPosition(), returnValidsForHuman);
        performMoveForHuman(grid, organism, valid_coordinates);



    } else if(organism.toString() == "Z") {
        coordinate_pairs valid_coordinates = findValidCoordinate(grid, organism.getPosition(), returnValidsForZombie);
        performMoveForZombie(grid, organism, valid_coordinates);



    }

};



/** find valid coordinates surrounding the organism */
template<typename T, typename F>
coordinate_pairs findValidCoordinate(T& grid, coordinate pos, F&& _func) {
    return _func(grid, pos);
};



/** performs a move operation for a Zombie object */
template<typename T>
void performMoveForZombie(T& grid, Organism& organism, coordinate_pairs& valid_pairs) {
    if(!organism.getMoveStatus()) {
        if(!valid_pairs.empty()) {
            coordinate old_coord = organism.getPosition();
            int range = valid_pairs.size();
            std::optional<coordinate> c = findHumanIn(grid, valid_pairs);

            if (organism.getSpawnCount() <= ZOMBIE_SPAWN_LIMIT) {

                if (organism.getSurviveCount() >= STARVE_COUNT) {
                    /* zombie starves, clear the position */
                    grid.clearPosition(old_coord.first, old_coord.second);

                } else if (c != std::nullopt) { /* if theres a human present, eat it */
                    int x = c.value().first;
                    int y = c.value().second;

                    grid.moveInto(&organism, x, y);
                    organism.setPosition(x, y);
                    organism.didMove();
                    organism.resetStarveCount();

                    grid.clearPosition(old_coord.first, old_coord.second);

                } else {
                    /* if no human is present to eat, move to a random empty spot */
                    int move_position = generateRandom(0, range - 1);
                    int x = valid_pairs[move_position].first;
                    int y = valid_pairs[move_position].second;

                    grid.moveInto(&organism, x, y);
                    organism.setPosition(x, y);
                    organism.didMove();
                    organism.updateStarve();

                    grid.clearPosition(old_coord.first, old_coord.second);

                }
            } else {
                /* spawn another zombie in a clear position */
                if (!valid_pairs.empty()) {
                    int move_position = generateRandom(0, range);
                    int x = valid_pairs[move_position].first;
                    int y = valid_pairs[move_position].second;

                    ISpecies *new_zombie = organism.spawn();
                    new_zombie->setPosition(x, y);

                    grid.moveInto(new_zombie, x, y);

                    organism.resetSpawnCount();
                    organism.resetStarveCount();
                }
            }
        }
    }
};

/** performs a move operation for a Human object */
template<typename T>
void performMoveForHuman(T& grid, Organism& organism, coordinate_pairs& valid_pairs) {
    if(!organism.getMoveStatus()) {
        if (!valid_pairs.empty()) {
            coordinate old_coord = organism.getPosition();
            if (organism.getSurviveCount() <= HUMAN_SPAWN_LIMIT) {
                /* */
                int rand = generateRandom(0, (int) valid_pairs.size() - 1);
                int x = valid_pairs[rand].first;
                int y = valid_pairs[rand].second;
                organism.updateSpawn();

                grid.moveInto(&organism, x, y);
                organism.setPosition(x, y);
                organism.didMove();

                grid.clearPosition(old_coord.first, old_coord.second);

            } else if (organism.getSurviveCount() >= HUMAN_SPAWN_LIMIT) {
                /* if human survives more than three rounds create new human */
                int rand = generateRandom(0, (int) valid_pairs.size() - 1);
                int x = valid_pairs[rand].first;
                int y = valid_pairs[rand].second;

                ISpecies* new_human = organism.spawn();
                new_human->setPosition(x, y);

                grid.moveInto(new_human, x, y);

            }
        }
    }
};

/** this function is used to determine which coordinate contains a human
 * from list of valid coordinates */
template<typename T>
std::optional<coordinate> findHumanIn(T& grid, coordinate_pairs valids) {

    for(int i=0; i<valids.size(); i++) {

        coordinate c = valids[i];
        if(grid.getOrganism(c.first, c.second) != std::nullopt) {

            if(grid.getOrganism(c.first, c.second).value()->toString() == "H") {

                return std::optional<coordinate>{c};

            }
        }
    }

    return std::nullopt;
};



/** generates a random within a following range
 * @param begin: start of the range, inclusive
 * @param end: end of the range, exclusive
 * @returns a single integer value within range */
int generateRandom(int begin, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(begin, end);

    return dist(gen);
};



/** returns the valid coordinates for Zombie
 * @param grid: the grid the Zombie object belongs to
 * @param coord: the coordinate of the Zombie object in the 2D array
 * @returns the valid coordinates the Zombie object within grid bounds */
template<typename T>
coordinate_pairs returnValidsForZombie(T& grid, coordinate coord) {
    int x = coord.first;
    int y = coord.second;
    coordinate_pairs valids = coordinate_pairs();
    /*
     *
     * A  B  C
     * D  *  F
     * G  H  I
     *
     * */

    /* A */
    if(grid.checkBounds(x - 1, y - 1)) {
        coordinate coor = coordinate(x - 1, y - 1);
        if(grid.checkPosition(x - 1, y - 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x - 1, y - 1);

            std::string _type = type.value()->toString();
            if(_type == "H") {
                valids.push_back(coor);
            }

        }
    }

    /* B */
    if(grid.checkBounds(x, y - 1)) {
        coordinate coor = coordinate(x, y - 1);
        if(grid.checkPosition(x, y - 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x, y - 1);
            std::string _type = type.value()->toString();

            if(_type == "H") {
                valids.push_back(coor);
            }
        }
    }

    /* C */
    if(grid.checkBounds(x + 1, y - 1)) {
        coordinate coor = coordinate(x + 1, y - 1);
        if(grid.checkPosition(x + 1, y - 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x + 1, y - 1);
            std::string _type = type.value()->toString();

            if(_type == "H") {
                valids.push_back(coor);
            }
        }
    }

    /* D */
    if(grid.checkBounds(x - 1, y)) {
        coordinate coor = coordinate(x - 1, y);
        if(grid.checkPosition(x - 1, y)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x - 1, y);
            std::string _type = type.value()->toString();

            if(_type == "H") {
                valids.push_back(coor);
            }
        }
    }

    /* F */
    if(grid.checkBounds(x + 1, y)) {
        coordinate coor = coordinate(x + 1, y);
        if(grid.checkPosition(x + 1, y)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x + 1, y);
            std::string _type = type.value()->toString();

            if(_type == "H") {
                valids.push_back(coor);
            }
        }
    }

    /* G */
    if(grid.checkBounds(x - 1, y + 1)) {
        coordinate coor = coordinate(x - 1, y + 1);
        if(grid.checkPosition(x - 1, y + 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x - 1, y + 1);
            std::string _type = type.value()->toString();

            if(_type == "H") {
                valids.push_back(coor);
            }
        }
    }

    /* H */
    if(grid.checkBounds(x, y + 1)) {
        coordinate coor = coordinate(x, y + 1);
        if(grid.checkPosition(x, y + 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x, y + 1);
            std::string _type = type.value()->toString();

            if(_type == "H") {
                valids.push_back(coor);
            }
        }
    }

    /* I */
    if(grid.checkBounds(x + 1, y + 1)) {
        coordinate coor = coordinate(x + 1, y + 1);
        if(grid.checkPosition(x + 1, y + 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        } else {
            /* there is an organism present */
            std::optional<ISpecies*> type = grid.getOrganism(x + 1, y + 1);
            std::string _type = type.value()->toString();

            if(_type == "H") {
                valids.push_back(coor);
            }
        }
    }


    return valids;
};

/** returns the valid coordinates for Human.
 * @param grid: the grid the Human object belongs to.
 * @param coord: the coordinate the Human object belongs to.
 * @returns the valid coordinates that the human object can
 * move to within grid bounds. */
template<typename T>
coordinate_pairs returnValidsForHuman(T& grid, coordinate coord) {
    int x = coord.first;
    int y = coord.second;
    coordinate_pairs valids = coordinate_pairs();
    /*
     * *  B  *
     * D  *  F
     * *  H  *
     *
     * */

    /* B */
    if(grid.checkBounds(x, y - 1)) {
        coordinate coor = coordinate(x, y - 1);
        if(grid.checkPosition(x, y - 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        }
    }

    /* D */
    if(grid.checkBounds(x - 1, y)) {
        coordinate coor = coordinate(x - 1, y);
        if(grid.checkPosition(x - 1, y)) {
            /* the grid position is empty */
            valids.push_back(coor);

        }
    }

    /* F */
    if(grid.checkBounds(x + 1, y)) {
        coordinate coor = coordinate(x + 1, y);
        if(grid.checkPosition(x + 1, y)) {
            /* the grid position is empty */
            valids.push_back(coor);

        }
    }

    /* H */
    if(grid.checkBounds(x, y + 1)) {
        coordinate coor = coordinate(x, y + 1);
        if(grid.checkPosition(x, y + 1)) {
            /* the grid position is empty */
            valids.push_back(coor);

        }
    }


    return valids;
};




