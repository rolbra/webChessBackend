#pragma once

#include <string>

class Player
{
    int id;
    std::string name;

public:
    Player();
    void init(int id, std::string name);
    int getId() const;
    std::string getName();
    void setName(std::string name);
};