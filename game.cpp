#include "game.hpp"


Game::Game(std::list<Player> playerList, Roulette roulette){
    PlayerList = playerList;
    GRoulette = roulette;
}

std::list<long long int> Game::GetBets(){
    std::list<long long int> betList;
    for(auto player : PlayerList){
        long long int bet = player.MakeBet();
        betList.push_back(bet);
        File << "Player " << player.GetName() << " bets " << bet << " on " << BetTypeToStr[player.GetBetType()] << "\n";
    }
    return betList;
}

bool Game::CheckBet(int rouletteRes, BetType type){
    switch(type)
    {
        case Zero:
        return rouletteRes == 0;
        case High:
        return rouletteRes > 18;
        case Low:
        return rouletteRes <= 18 && rouletteRes != 0;
        case Even:
        return rouletteRes%2 == 0 && rouletteRes != 0;
        case Uneven:
        return rouletteRes%2 != 0;
        default:
        return type == Colours.at(rouletteRes);

    }
}

void Game::PayBet(int rouletteRess, std::list<long long int> bets){
    long long int bet;
    // As the bets are in the same order of the player list the poped element of bets correspons to the player that made the bet
    for(Player& player : PlayerList){
        bet = bets.front();
        bets.pop_front();
        bool didWin = CheckBet(rouletteRess,player.GetBetType());
        player.UpdateRecords(didWin,bet);
        if(didWin) File << "Player " << player.GetName() << " who betted " << BetTypeToStr[player.GetBetType()] << " won this round\n";
        else File << "Player " << player.GetName() << " who betted " << BetTypeToStr[player.GetBetType()] << " lost this round\n";
    }
}

void Game::PrintBalance(){
    File << "Final balances: \n";
    long long int totalBalance = 0;
    for(auto player : PlayerList){
        File << "Player " << player.GetName() << "'s final balance is: " << player.GetBalance() << "\n";
        totalBalance += player.GetBalance();
    }
    File << "Total final balance is: " << totalBalance << "\n";
}

void Game::Play(int rounds){
    File.open("PreviousGame");
    for(int i=0;i<rounds;i++){
        File << "Round " << (i+1) << "\n";
        std::list<long long int> bets = GetBets();
        int result = GRoulette.Spin();
        File << "Roulette resulted in " << result << " " << BetTypeToStr[Colours[result]] <<  "\n";
        PayBet(result, bets);
    }
    PrintBalance();
}