#include <string>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "gameData.hpp"
#include "figureMover.hpp"

using namespace web;

FigureMover::FigureMover(GameData& data)
{
    this->gameData = &data;
};

void FigureMover::moveFigure(std::string from, std::string to)
{
    int figureIndex = findFigureByPosition(from);

    if(figureIndex == -1)
        return;
    else
        std::cout << "figure " << gameData->positions[figureIndex]["figure"] << std::endl;
    
    setFigurePosition(figureIndex, to);

}

int FigureMover::findFigureByPosition(const std::string pos)
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