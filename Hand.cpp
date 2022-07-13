#include "Hand.h"

Hand::Hand()
{
    mCards.reserve(7);
}

Hand::~Hand()
{
    clear();
}

inline void Hand::add(Card* pCard)
{
    mCards.push_back(pCard);
}

void Hand::clear()
{
    vector<Card*>::iterator iter = mCards.begin();
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        delete* iter;
        *iter = nullptr;
    }
    // ������� ������ ����������.
    mCards.clear();
}

int Hand::getTotal() const
{
    // ���� ���� � ���� ���, �� ���������� �������� "�". 
    if (mCards.empty())
    {
        return 0;
    }

    // ���� ������ ����� ����� �������� "�", �� ��� ����� �������� �����. 
    if (mCards[0]->getValue() == 0)
    {
        return 0;
    }

    // ������� ����� ����� ���� ����. ������ ��� ���� 1 ����.
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        total += (*iter)->getValue();
    }

    // ����������: ������ �� ���� ���.
    bool containsAce = false;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        if ((*iter)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // ���� ���� ������ ��� � ����� �������� ���������, �� ��� ���� 11 �����.
    if (containsAce && total <= 11)
    {
        // ��������� ������ 10 �����. �.�. ���� ��� �������� +1.
        total += 10;
    }
    return total;
}