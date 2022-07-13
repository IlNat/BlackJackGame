#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const string& name) :mName{ name }
{}

GenericPlayer::~GenericPlayer()
{}

// ������������, ������ 21.
bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}

// �������� � ������������.
void GenericPlayer::bust() const
{
    cout << mName << " �������. \n";
}