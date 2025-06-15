#include "player.hpp"

Player::Player()
{
}

void Player::init(int id, std::string name)
{
    this->id = id;
    this->name = name;
}

int Player::getId() const
{
    return id;
}

std::string Player::getName() const
{
    return name;
}

void Player::setName(std::string name)
{
    this->name = name;
}