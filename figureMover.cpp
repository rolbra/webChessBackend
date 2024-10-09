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
    //input: A7, D5
    
    //find figure on A7
    int i = 8;
    auto check = gameData->positions[i]["y"];
    if(check.as_string() == "6")
    {
        std::cout << "move " << gameData->positions[i]["figure"] << std::endl;
    }
    
    //Change positions to D5
    gameData->positions[i]["y"] = json::value::string("5");
}