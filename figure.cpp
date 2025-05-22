#include <string>
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





//-----------------___Figure2

Figure2::Figure2(Id id, int posX, int posY, Color color, Type type)
{
    this->id = id;
    this->color = color;
    this->type = type;
    this->x = posX;
    this->y = posY;
}

int Figure2::getXasInt()
{
    return x;
}

int Figure2::getYasInt()
{
    return y;
}