#include "player.hpp"

Player::Player()
{
}

void Player::init(int id, std::string name)
{
    this->id = id;
    this->name = name;
}

int Player::getId()
{
    return id;
}

std::string Player::getName()
{
    return name;
}

void Player::setName(std::string name)
{
    this->name = name;
}