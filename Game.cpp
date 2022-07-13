#include "Game.h"

Game::Game(const vector<string>& names)
{
    // Создаем массив игроков.
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        mPlayers.push_back(Player(*pName));
    }
    // Инициализируем ГСЧ.
    srand(static_cast<unsigned int>(time(NULL)));// Преобразование time_t
    mDeck.populate();
    mDeck.shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    // Сдать всем по 2 карты.
    vector<Player>::iterator pPlayer;

    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            mDeck.deal(*pPlayer);
        }
        mDeck.deal(mHouse);
    }
    // Скрыть первую карту казино.
    mHouse.flipFirstCard();

    // Показать все карты на руках.
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << mHouse << endl;
    // Сдать дополнительные карты игрокам.
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        mDeck.additionalCards(*pPlayer);
    }

    // Перевернуть первую карту казино.
    mHouse.flipFirstCard();
    cout << endl << mHouse;

    // Раздать дополнительную карту казино.
    mDeck.additionalCards(mHouse);
    if (mHouse.isBusted())
    {
        // Проверить на выигрыш.
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                pPlayer->win();
            }
        }
    }
    else
    {
        // Сравнить карты игроков и казино.
        for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                pPlayer->win();
            }
            else if (pPlayer->getTotal() < mHouse.getTotal())
            {
                pPlayer->lose();
            }
            else
            {
                pPlayer->push();
            }
        }
    }
    // Очистить карты в руках.
    for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    mHouse.clear();
}