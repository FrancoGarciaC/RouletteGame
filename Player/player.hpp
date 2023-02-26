#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <deque>
#include <string>
#include "../bet.hpp"

class Player{
public:
    // Player parameters are:
    Player(std::string name, // a name for the player
     long long int balance, // an initial balance 
     std::deque<long long int>initialBetRecord, // a double ended queue for all the bets as they take the first and last element
     BetType type); // as every player bets on only one type of bet

    // Player destructor
    ~Player() = default;

    // Setter for name
    void SetName(std::string newName);

    // Getter for name
    std::string GetName();

    // Setter for balance
    void SetBalance(long long int newBalance);

    // Getter for balance
    long long int GetBalance();

    // Setter for betRecord
    void SetBetRecord(std::deque<long long int> newBetRecord);

    // Getter for betRecord
    std::deque<long long int> GetBetRecord();

    // Setter for BetType
    void SetBetType(BetType newBetType);

    // Getter for BetType
    BetType GetBetType();

    // Makes a bet from the current status of the players BetRecord
    long long int MakeBet();

    // Updates the betRecord and balance according to the result of the previous bet
    void UpdateRecords(bool won, long long int bet);


private:
    // Player's name
    std::string Name;

    // Player's balance
    long long int Balance;

    // Player's initial betRecord it's the base for the betRecord when it needs to be reset
    std::deque<long long int> InitialBetRecord;

    // Player's betRecord
    std::deque<long long int> BetRecord;

    // Player's BetType
    BetType BType;
};



#endif