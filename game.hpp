#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Player/player.hpp"
#include "Roulette/roulette.hpp"
#include "bet.hpp"
#include <list>
#include <array>
#include <fstream>

class Game{
    public:
    // Game constructor that takes a list for all the players and the roulette to use in the game
    Game(std::list<Player> playerList, Roulette roulette);

    // Game destructor
    ~Game() = default;

    // Plays a round
    void Play(int rounds);

    private:
    // Gets the bets from each player
    std::list<long long int> GetBets();
    
    // Informs the players of the result of the bet
    void PayBet(int rouletteRes, std::list<long long int> bets);

    // Checks if the player that made a bet won the round or not
    bool CheckBet(int rouletteRes, BetType type);

    // Prints the balance of each player and the total balance as a group
    void PrintBalance();

    // Players list
    std::list<Player> PlayerList;

    // Game's roulette
    Roulette GRoulette;

    // File where the game is recorded
    std::ofstream File;

    // Array that represents the position of the colors of each number of the layout
    std::array<BetType,37> Colours = { 
        Zero, Red, Black, Red, Black, Red, Black, Red, Black, Red, Black, Black, Red,
        Black, Red, Black, Red, Black, Red, Red, Black, Red, Black, Red, Black,
        Red, Black, Red, Black, Black, Red, Black, Red, Black, Red, Black, Red
    };
};


#endif