#pragma once
#include "GenericPlayer.h"

// �����-���������.
class HouseKeeper : public GenericPlayer
{
public:
    HouseKeeper(const std::string& name = "");
    virtual ~HouseKeeper();

    virtual bool isHitting() const;
    // ����������� �����.
    virtual void flipFirstCard() const;

};

