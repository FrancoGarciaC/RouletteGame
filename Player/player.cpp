#include "player.hpp"

#define MAX_BET 4000
#define MIN_BET 5

Player::Player(std::string name, long long int balance, std::deque<long long int> initialBetRecord, BetType type){
    Name = name;
    Balance = balance;
    InitialBetRecord = initialBetRecord;
    BetRecord = initialBetRecord;
    BType = type;
}

void Player::SetName(std::string newName){
    Name = newName;
}

std::string Player::GetName(){
    return Name;
}

void Player::SetBalance(long long int newBalance){
    Balance = newBalance;
}

long long int Player::GetBalance(){
    return Balance;
}

void Player::SetBetRecord(std::deque<long long int> newBetRecord){
    BetRecord = newBetRecord;
}

std::deque<long long int> Player::GetBetRecord(){
    return BetRecord;
}

void Player::SetBetType(BetType newType){
    BType = newType;
}

BetType Player::GetBetType(){
    return BType;
}

long long int Player::MakeBet(){
    long long int bet;
    switch (BetRecord.size()) // Checks if a record reset is needed and calculates the bet accordingly
    {
        case 0:
            BetRecord = InitialBetRecord;
            bet = BetRecord.front() + BetRecord.back();
            break;
        case 1:
            bet = BetRecord.front();
            if(MIN_BET > bet || bet > MAX_BET)
            {
                BetRecord = InitialBetRecord;
                bet = BetRecord.front();
            }
            break;
        default:
            bet = BetRecord.front() + BetRecord.back();
            if(MIN_BET > bet || bet > MAX_BET)
            {
                BetRecord = InitialBetRecord;
                bet = BetRecord.front() + BetRecord.back();
            }
            break;
    }
    return bet;
}

void Player::UpdateRecords(bool won,long long int bet){
    if(BetRecord.empty()) BetRecord = InitialBetRecord;
    if(won){ // Adds the money earned at the end
        BetRecord.push_back(bet);
        Balance += bet;
        return;
    } 
    else // Removes the betted amount from the record
    {
        BetRecord.pop_front();
        if(!BetRecord.empty()) // In case there was only one number betted
            BetRecord.pop_back();
        Balance -= bet;
        return;
    }
}