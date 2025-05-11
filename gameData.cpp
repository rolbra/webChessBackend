#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "figure.hpp"
#include "gameData.hpp"

using namespace web;
using namespace web::http;

GameData::GameData()
{
    createFigures();
    initPositions();
}

void GameData::createFigures()
{
    rook_black_0.init("rook_black_0", 0, 7, ROOKBLACK);
    knight_black_0.init("knight_black_0", 1, 7, KNIGHTBLACK);
    bishop_black_0.init("bishop_black_0", 2, 7, BISHOPBLACK);
    queen_black.init("queen_black", 3, 7, QUEENTBLACK);
    king_black.init("king_black", 4, 7, KINGBLACK);
    bishop_black_1.init("bishop_black_1", 5, 7, BISHOPBLACK);
    knight_black_1.init("knight_black_1", 6, 7, KNIGHTBLACK);
    rook_black_1.init("rook_black_1", 7, 7, ROOKBLACK);

    pawn_black_0.init("pawn_black_0", 0, 6, PAWNBLACK);
    pawn_black_1.init("pawn_black_1", 1, 6, PAWNBLACK);
    pawn_black_2.init("pawn_black_2", 2, 6, PAWNBLACK);
    pawn_black_3.init("pawn_black_3", 3, 6, PAWNBLACK);
    pawn_black_4.init("pawn_black_4", 4, 6, PAWNBLACK);
    pawn_black_5.init("pawn_black_5", 5, 6, PAWNBLACK);
    pawn_black_6.init("pawn_black_6", 6, 6, PAWNBLACK);
    pawn_black_7.init("pawn_black_7", 7, 6, PAWNBLACK);


    rook_white_0.init("rook_white_0", 0, 0, ROOKWHITE);
    knight_white_0.init("knight_white_0", 1, 0, KNIGHTWHITE);
    bishop_white_0.init("bishop_white_0", 2, 0, BISHOPWHITE);
    queen_white.init("queen_white", 3, 0, QUEENTWHITE);
    king_white.init("king_white", 4, 0, KINGWHITE);
    bishop_white_1.init("bishop_white_1", 5, 0, BISHOPWHITE);
    knight_white_1.init("knight_white_1", 6, 0, KNIGHTWHITE);
    rook_white_1.init("rook_white_1", 7, 0, ROOKWHITE);

    pawn_white_0.init("pawn_white_0", 0, 1, PAWNWHITE);
    pawn_white_1.init("pawn_white_1", 1, 1, PAWNWHITE);
    pawn_white_2.init("pawn_white_2", 2, 1, PAWNWHITE);
    pawn_white_3.init("pawn_white_3", 3, 1, PAWNWHITE);
    pawn_white_4.init("pawn_white_4", 4, 1, PAWNWHITE);
    pawn_white_5.init("pawn_white_5", 5, 1, PAWNWHITE);
    pawn_white_6.init("pawn_white_6", 6, 1, PAWNWHITE);
    pawn_white_7.init("pawn_white_7", 7, 1, PAWNWHITE);
}

void GameData::initPosition(int index, Figure figure)
{
    positions[index]["name"] = json::value::string(figure.getName());
    positions[index]["x"] = json::value::string(figure.getPosXAsChar());
    positions[index]["y"] = json::value::string(figure.getPosYAsChar());
    positions[index]["code"] = json::value::string(figure.getCode());
}

void GameData::initPositions()
{
    int index=0;
    initPosition(index++, rook_black_0);
    initPosition(index++, knight_black_0);
    initPosition(index++, bishop_black_0);
    initPosition(index++, queen_black);
    initPosition(index++, king_black);
    initPosition(index++, bishop_black_1);
    initPosition(index++, knight_black_1);
    initPosition(index++, rook_black_1);
    
    initPosition(index++, pawn_black_0);
    initPosition(index++, pawn_black_1);
    initPosition(index++, pawn_black_2);
    initPosition(index++, pawn_black_3);
    initPosition(index++, pawn_black_4);
    initPosition(index++, pawn_black_5);
    initPosition(index++, pawn_black_6);
    initPosition(index++, pawn_black_7);


    initPosition(index++, rook_white_0);
    initPosition(index++, knight_white_0);
    initPosition(index++, bishop_white_0);
    initPosition(index++, queen_white);
    initPosition(index++, king_white);
    initPosition(index++, bishop_white_1);
    initPosition(index++, knight_white_1);
    initPosition(index++, rook_white_1);
    
    initPosition(index++, pawn_white_0);
    initPosition(index++, pawn_white_1);
    initPosition(index++, pawn_white_2);
    initPosition(index++, pawn_white_3);
    initPosition(index++, pawn_white_4);
    initPosition(index++, pawn_white_5);
    initPosition(index++, pawn_white_6);
    initPosition(index++, pawn_white_7);
}