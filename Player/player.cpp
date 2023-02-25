#include "player.hpp"

#define MAX_BET = 4000
#define MIN_BET = 5

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
    if(BetRecord.size() == 0)
        BetRecord = InitialBetRecord;

    if(BetRecord.size() == 1)
        return BetRecord.front();

    return (BetRecord.front() + BetRecord.back());
}

void UpdateRecord(long long int prevBet){
    // Cambiar porque dependiendo del resultado se tiene que borrar o agregar
}