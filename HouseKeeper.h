#pragma once
#include "GenericPlayer.h"

// Игрок-компьютер.
class HouseKeeper : public GenericPlayer
{
public:
    HouseKeeper(const std::string& name = "");
    virtual ~HouseKeeper();

    virtual bool isHitting() const;
    // Перевернуть карту.
    virtual void flipFirstCard() const;

};

