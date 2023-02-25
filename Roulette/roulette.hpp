#ifndef __ROULETTE_HPP__
#define __ROULETTE_HPP__

#include <random>

class Roulette{
    public:
    // Roulette constructor
    Roulette();
    // Roulette destructor
    ~Roulette() = default;

    //Spins the roulette and returns a number between 0 and 36
    int Spin();

    private:
    // Seed used for the random numbers
    std::mt19937 ranSeed;
};

#endif