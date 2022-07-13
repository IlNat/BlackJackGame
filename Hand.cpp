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
    // Очищаем вектор указателей.
    mCards.clear();
}

int Hand::getTotal() const
{
    // Если карт в руке нет, то возвращает значение "О". 
    if (mCards.empty())
    {
        return 0;
    }

    // Если первая карта имеет значение "О", то она лежит рубашкой вверх. 
    if (mCards[0]->getValue() == 0)
    {
        return 0;
    }

    // Находит сумму очков всех карт. Каждый туз дает 1 очко.
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        total += (*iter)->getValue();
    }

    // Определяет: держит ли рука туз.
    bool containsAce = false;
    for (iter = mCards.begin(); iter != mCards.end(); ++iter)
    {
        if ((*iter)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // Если рука держит туз и сумма довольно маленькая, то туз дает 11 очков.
    if (containsAce && total <= 11)
    {
        // Добавляем только 10 очков. т.к. тузы уже добавили +1.
        total += 10;
    }
    return total;
}