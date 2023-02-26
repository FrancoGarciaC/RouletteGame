#include "Player/player.hpp"
#include "Roulette/roulette.hpp"
#include "bet.hpp"
#include "game.hpp"


int main(){
    // Set the initial bet record
    std::deque<long long int> initialBetRecord {1, 2, 3, 4};

    // Set all the desired players
    Player A("A",0,initialBetRecord,Red);
    Player B("B",0,initialBetRecord,Black);
    Player C("C",0,initialBetRecord,High);
    Player D("D",0,initialBetRecord,Low);
    Player E("E",0,initialBetRecord,Even);
    Player F("F",0,initialBetRecord,Uneven);

    // Sets the roulette
    Roulette roulette;

    // Sets the game
    Game game({A,B,C,D,E,F}, roulette);

    // Set the amount of rounds
    int rounds = 10000; 

    // Plays the given number of rounds of roulette
    game.Play(rounds);

    return 0;
}