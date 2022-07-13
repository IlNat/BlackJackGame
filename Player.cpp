#include "Player.h"

Player::Player(const string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
    cout << mName << ", ��� ����� ���? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << mName << ". �� ��������! \n";
}

void Player::lose() const
{
    cout << mName << " ��������. \n";
}

void Player::push() const
{
    cout << mName << " ����� ���. \n";
}
