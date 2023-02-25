#include "roulette.hpp"

Roulette::Roulette(){
    std::random_device rd; // obtain a random number from hardware
    ranSeed.seed(rd()); // generates the random seed with rd
};

int Roulette::Spin(){
    std::uniform_int_distribution<> distr(0, 36); // define the range for the roulette
    int res = distr(ranSeed);
    return res;
}