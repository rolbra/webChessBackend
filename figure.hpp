#pragma once

#include <string>

#define ROOKBLACK "&#x265C;"        //todo: information how the figure is displayed on the client should better be stored on the client. Possible that the different clients exists with different implementations. One client could use the ascii code, another could use an image file
#define KNIGHTBLACK "&#x265E;"
#define BISHOPBLACK "&#x265D;"
#define QUEENTBLACK "&#x265B;"
#define KINGBLACK "&#x265A;"
#define PAWNBLACK "&#x265F;"

#define ROOKWHITE "&#x2656;"
#define KNIGHTWHITE "&#x2658;"
#define BISHOPWHITE "&#x2657;"
#define QUEENTWHITE "&#x2655;"
#define KINGWHITE "&#x2654;"
#define PAWNWHITE "&#x2659;"


class Figure
{

public:
    Figure();
    Figure(std::string name, int posX, int posY, std::string code);

    void init(std::string name, int posX, int posY, std::string code, std::string color, std::string type);

    std::string getName();

    void setPosX(int x);
    void setPosY(int y);
    int getPosXAsInt();
    int getPosYAsInt();
    std::string getPosXAsChar();
    std::string getPosYAsChar();

    std::string getCode();
    std::string getColor();
    std::string getType();

private:
    std::string name;
    int x;
    int y;
    std::string code;
    std::string color;
    std::string type;
};