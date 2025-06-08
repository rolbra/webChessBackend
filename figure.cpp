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

void Figure::init(std::string name, int posX, int posY, std::string code, std::string color, std::string type)
{
    this->name = name;
    x = posX;
    y = posY;
    this->code = code;
    this->color = color;
    this->type = type;
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

std::string Figure::getColor()
{
    return color;
}

std::string Figure::getType()
{
    return type;
}