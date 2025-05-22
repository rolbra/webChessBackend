#include "figure.hpp"

Figure::Figure()
{
    
}

Figure::Figure(std::string name, int posX, int posY, std::string code)
{
    this->name = name;
    x = posX;
    y = posY;
    this->code = code;
}

void Figure::init(std::string name, int posX, int posY, std::string code)
{
    this->name = name;
    x = posX;
    y = posY;
    this->code = code;
}

std::string Figure::getName()
{
    return name;
}

void Figure::setPosX(int x)
{
    this->x = x;
}

int Figure::getPosXAsInt()
{
    return x;
}

void Figure::setPosY(int y)
{
    this->y = y;
}

int Figure::getPosYAsInt()
{
    return y;
}

std::string Figure::getPosXAsChar()
{
    return std::to_string(x);
}

std::string Figure::getPosYAsChar()
{
    return std::to_string(y);
}

std::string Figure::getCode()
{
    return code;
}