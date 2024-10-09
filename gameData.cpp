#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "gameData.hpp"

using namespace web;
using namespace web::http;

GameData::GameData()
{
    initPositions();
}

void GameData::initPositions()
{
    //black
    positions[0]["figure"] = json::value::string("rook_blk_0");
    positions[0]["x"] = json::value::string("0");
    positions[0]["y"] = json::value::string("7");
    positions[0]["code"] = json::value::string("&#x265C;");
    
    positions[1]["figure"] = json::value::string("knight_blk_0");
    positions[1]["x"] = json::value::string("1");
    positions[1]["y"] = json::value::string("7");
    positions[1]["code"] = json::value::string("&#x265E;");

    positions[2]["figure"] = json::value::string("bishop_blk_0");
    positions[2]["x"] = json::value::string("2");
    positions[2]["y"] = json::value::string("7");
    positions[2]["code"] = json::value::string("&#x265D;");

    positions[3]["figure"] = json::value::string("queen_blk");
    positions[3]["x"] = json::value::string("3");
    positions[3]["y"] = json::value::string("7");
    positions[3]["code"] = json::value::string("&#x265B;");

    positions[4]["figure"] = json::value::string("king_blk");
    positions[4]["x"] = json::value::string("4");
    positions[4]["y"] = json::value::string("7");
    positions[4]["code"] = json::value::string("&#x265A;");

    positions[5]["figure"] = json::value::string("bishop_blk_1");
    positions[5]["x"] = json::value::string("5");
    positions[5]["y"] = json::value::string("7");
    positions[5]["code"] = json::value::string("&#x265D;");

    positions[6]["figure"] = json::value::string("knight_blk_1");
    positions[6]["x"] = json::value::string("6");
    positions[6]["y"] = json::value::string("7");
    positions[6]["code"] = json::value::string("&#x265E;");

    positions[7]["figure"] = json::value::string("rook_blk_1");
    positions[7]["x"] = json::value::string("7");
    positions[7]["y"] = json::value::string("7");
    positions[7]["code"] = json::value::string("&#x265C;");


    positions[8]["figure"] = json::value::string("pawn_blk_0");
    positions[8]["x"] = json::value::string("0");
    positions[8]["y"] = json::value::string("6");
    positions[8]["code"] = json::value::string("&#x265F;");
    
    positions[9]["figure"] = json::value::string("pawn_blk_1");
    positions[9]["x"] = json::value::string("1");
    positions[9]["y"] = json::value::string("6");
    positions[9]["code"] = json::value::string("&#x265F;");

    positions[10]["figure"] = json::value::string("pawn_blk_2");
    positions[10]["x"] = json::value::string("2");
    positions[10]["y"] = json::value::string("6");
    positions[10]["code"] = json::value::string("&#x265F;");

    positions[11]["figure"] = json::value::string("pawn_blk_3");
    positions[11]["x"] = json::value::string("3");
    positions[11]["y"] = json::value::string("6");
    positions[11]["code"] = json::value::string("&#x265F;");

    positions[12]["figure"] = json::value::string("pawn_blk_4");
    positions[12]["x"] = json::value::string("4");
    positions[12]["y"] = json::value::string("6");
    positions[12]["code"] = json::value::string("&#x265F;");

    positions[13]["figure"] = json::value::string("pawn_blk_5");
    positions[13]["x"] = json::value::string("5");
    positions[13]["y"] = json::value::string("6");
    positions[13]["code"] = json::value::string("&#x265F;");

    positions[14]["figure"] = json::value::string("pawn_blk_6");
    positions[14]["x"] = json::value::string("6");
    positions[14]["y"] = json::value::string("6");
    positions[14]["code"] = json::value::string("&#x265F;");

    positions[15]["figure"] = json::value::string("pawn_blk_7");
    positions[15]["x"] = json::value::string("7");
    positions[15]["y"] = json::value::string("6");
    positions[15]["code"] = json::value::string("&#x265F;");

    //white
    positions[16]["figure"] = json::value::string("rook_white_0");
    positions[16]["x"] = json::value::string("0");
    positions[16]["y"] = json::value::string("0");
    positions[16]["code"] = json::value::string("&#x2656;");
    
    positions[17]["figure"] = json::value::string("knight_white_0");
    positions[17]["x"] = json::value::string("1");
    positions[17]["y"] = json::value::string("0");
    positions[17]["code"] = json::value::string("&#x2658;");

    positions[18]["figure"] = json::value::string("bishop_white_0");
    positions[18]["x"] = json::value::string("2");
    positions[18]["y"] = json::value::string("0");
    positions[18]["code"] = json::value::string("&#x2657;");

    positions[19]["figure"] = json::value::string("queen_white");
    positions[19]["x"] = json::value::string("3");
    positions[19]["y"] = json::value::string("0");
    positions[19]["code"] = json::value::string("&#x2655;");

    positions[20]["figure"] = json::value::string("king_white");
    positions[20]["x"] = json::value::string("4");
    positions[20]["y"] = json::value::string("0");
    positions[20]["code"] = json::value::string("&#x2654;");

    positions[21]["figure"] = json::value::string("bishop_white_1");
    positions[21]["x"] = json::value::string("5");
    positions[21]["y"] = json::value::string("0");
    positions[21]["code"] = json::value::string("&#x2657;");

    positions[22]["figure"] = json::value::string("knight_white_1");
    positions[22]["x"] = json::value::string("6");
    positions[22]["y"] = json::value::string("0");
    positions[22]["code"] = json::value::string("&#x2658;");

    positions[23]["figure"] = json::value::string("rook_white_1");
    positions[23]["x"] = json::value::string("7");
    positions[23]["y"] = json::value::string("0");
    positions[23]["code"] = json::value::string("&#x2656;");


    positions[24]["figure"] = json::value::string("pawn_white_0");
    positions[24]["x"] = json::value::string("0");
    positions[24]["y"] = json::value::string("1");
    positions[24]["code"] = json::value::string("&#x2659;");
    
    positions[25]["figure"] = json::value::string("pawn_white_1");
    positions[25]["x"] = json::value::string("1");
    positions[25]["y"] = json::value::string("1");
    positions[25]["code"] = json::value::string("&#x2659;");

    positions[26]["figure"] = json::value::string("pawn_white_2");
    positions[26]["x"] = json::value::string("2");
    positions[26]["y"] = json::value::string("1");
    positions[26]["code"] = json::value::string("&#x2659;");

    positions[27]["figure"] = json::value::string("pawn_white_3");
    positions[27]["x"] = json::value::string("3");
    positions[27]["y"] = json::value::string("1");
    positions[27]["code"] = json::value::string("&#x2659;");

    positions[28]["figure"] = json::value::string("pawn_white_4");
    positions[28]["x"] = json::value::string("4");
    positions[28]["y"] = json::value::string("1");
    positions[28]["code"] = json::value::string("&#x2659;");

    positions[29]["figure"] = json::value::string("pawn_white_5");
    positions[29]["x"] = json::value::string("5");
    positions[29]["y"] = json::value::string("1");
    positions[29]["code"] = json::value::string("&#x2659;");

    positions[30]["figure"] = json::value::string("pawn_white_6");
    positions[30]["x"] = json::value::string("6");
    positions[30]["y"] = json::value::string("1");
    positions[30]["code"] = json::value::string("&#x2659;");

    positions[31]["figure"] = json::value::string("pawn_white_7");
    positions[31]["x"] = json::value::string("7");
    positions[31]["y"] = json::value::string("1");
    positions[31]["code"] = json::value::string("&#x2659;");
}