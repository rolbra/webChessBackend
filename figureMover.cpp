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

    auto jsonData = gameData->positions[movingFigureIndex];
    std::string figureName = jsonData["name"].as_string();
    int srcX = jsonData["x"].as_integer();
    int srcY = jsonData["y"].as_integer();
    Figure figure( jsonData["name"].as_string(), jsonData["x"].as_integer(), jsonData["y"].as_integer(), jsonData["code"].as_string());

    //test: use fields and Figure2 objects for evaluation
    Figure2* figureFrom = gameData->fields[from[0] - '0'][from[1] - '0'];
    if(figureFrom == nullptr )
        return false;

    

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
        std::cout << "figure " << gameData->positions[movingFigureIndex]["name"] << std::endl;
    
    if(beatenFigureIndex != -1)
    {
        std::cout << "beats " << gameData->positions[beatenFigureIndex]["name"] << std::endl;
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

    int posIntX = std::stoi(posX);
    int posIntY = std::stoi(posY);

    for(; i < 32; i++)
    {
        auto tmpX = this->gameData->positions[i]["x"].as_integer();
        auto tmpY = this->gameData->positions[i]["y"].as_integer();
        if(this->gameData->positions[i]["x"].as_integer() == posIntX && this->gameData->positions[i]["y"].as_integer() == posIntY)
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