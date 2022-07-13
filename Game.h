#pragma once
#include <vector>
#include <string>
#include "Deck.h"
#include "HouseKeeper.h"
#include "Player.h"

class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    //Играем в игру!
    void Play();
private:
    Deck mDeck;
    HouseKeeper mHouse;
    vector<Player> mPlayers;

};

