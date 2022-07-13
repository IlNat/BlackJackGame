#include "Card.h"

Card::Card(rank r, suit s, bool ifu) :mRank{ r }, mSuit{ s }, mIsFaceUp{ ifu }
{}

int Card::getValue() const
{
    int value = 0;
    if (mIsFaceUp) // ���� ����� �����������, ������ ��������.
    {
        value = mRank;
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::flip()
{
    mIsFaceUp = !(mIsFaceUp);
}