#pragma once
#include "GenericPlayer.h"

// Игрок-человек.
class Player : public GenericPlayer
{
public:
    Player(const string& name = "");
    virtual ~Player();
    // нужна ли карта еще
    virtual bool isHitting() const;
    void win() const;// победил
    void lose() const; // проиграл
    void push() const; //сдать
};

