#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"


class Doodlebug : public Critter {
public:
    // constructor
    Doodlebug();
    // destructor 
    virtual ~Doodlebug();
    // overriding method
    void move() override;
    // overriding method
    void breed() override;
    // overriding method
    void beOlder();
    // check for starving 
    bool isStarve();
    // friend method
    friend ostream& operator<< (std::ostream &out, const Doodlebug &doodlebug);
private:
    // eat an ant
    bool eating();
private:
    const static int DOODLEBUG_SURVIVED_TIME = 8;
    const static int DOODLEBUG_STARVED_TIME = 3;
    int tte; // time to eat
};

#endif /* DOODLEBUG_HPP */