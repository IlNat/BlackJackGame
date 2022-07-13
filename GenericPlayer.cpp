#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const string& name) :mName{ name }
{}

GenericPlayer::~GenericPlayer()
{}

// Переполнение, больше 21.
bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}

// Сообщить о переполнении.
void GenericPlayer::bust() const
{
    cout << mName << " Перебор. \n";
}