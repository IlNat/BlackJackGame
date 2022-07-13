#include "HouseKeeper.h"

HouseKeeper::HouseKeeper(const std::string& name) : GenericPlayer(name) {}

HouseKeeper::~HouseKeeper() {};

bool HouseKeeper::isHitting() const
{
    return (getTotal() <= 16);
}

// ����������� �����.
void HouseKeeper::flipFirstCard() const
{
    if (!(mCards.empty()))
    {
        mCards[0]->flip();
    }
    else
    {
        cout << "��� ���� ��� ����������!\n";
    }
}