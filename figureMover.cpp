#include <string>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "figure.hpp"
#include "gameData.hpp"
#include "figureMover.hpp"

using namespace web;

FigureMover::FigureMover(GameData& data)
{
    this->gameData = &data;
}

bool FigureMover::evaluateMove(std::string from, std::string to)
{
    from = translatePosition(from);
    to = translatePosition(to);

    int movingFigureIndex = findFigureIndexByPosition(from);
    int destinationFigureIndex = findFigureIndexByPosition(to);

    if(movingFigureIndex == -1)
        return false;

    auto figure = gameData->positions[movingFigureIndex];
    std::string figureName = figure["figure"].as_string();
    int srcX = figure["x"].as_integer();
    int srcY = figure["y"].as_integer();

    int destX = gameData->positions[destinationFigureIndex]["x"].as_integer();
    int destY = gameData->positions[destinationFigureIndex]["y"].as_integer();

    //Is destination on field?
    //Is 

    return true;
};

void FigureMover::moveFigure(std::string from, std::string to)
{
    from = translatePosition(from);
    to = translatePosition(to);

    int movingFigureIndex = findFigureIndexByPosition(from);
    int beatenFigureIndex = findFigureIndexByPosition(to);

    if(movingFigureIndex == -1)
        return;
    else
        std::cout << "figure " << gameData->positions[movingFigureIndex]["figure"] << std::endl;
    
    if(beatenFigureIndex != -1)
    {
        std::cout << "beats " << gameData->positions[beatenFigureIndex]["figure"] << std::endl;
        setFigurePosition(beatenFigureIndex, "I8");     //todo: remove beaten figure from board
    }
    setFigurePosition(movingFigureIndex, to);
}

std::string FigureMover::translatePosition(const std::string pos)
{
    //translates A1 to 00, B2 to 11 etc.
    std::string posX = pos.substr(0,1);
    posX = toupper(posX[0]) - 17;

    std::string posY = pos.substr(1,1);
    posY = toupper(posY[0]) - 1;

    std::string newPos = posX + posY;
    
    return newPos;
}

int FigureMover::findFigureIndexByPosition(const std::string pos)
{
    int i = 0;

    std::string posX = pos.substr(0,1);
    std::string posY = pos.substr(1,1);

    for(; i < 32; i++)
    {
        if(this->gameData->positions[i]["x"].as_string() == posX && this->gameData->positions[i]["y"].as_string() == posY)
            return i;
    }

    return -1;
}

void FigureMover::setFigurePosition(const int index, const std::string pos)
{
    std::string posX = pos.substr(0,1);
    std::string posY = pos.substr(1,1);

    this->gameData->positions[index]["x"] = json::value::string(posX);
    this->gameData->positions[index]["y"] = json::value::string(posY);
}

void FigureMover::resetPositions()
{
    std::cout << "reset positions" << std::endl;
    this->gameData->initPositions();
}