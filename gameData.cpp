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
    updateFields();
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

    this->figures.at(0) = new Figure2(Id::ROOKBLACK_0, 0, 7, Color::BLACK, Type::ROOK);
    this->figures.at(1) = new Figure2(Id::KNIGHTBLACK_0, 1, 7, Color::BLACK, Type::KNIGHT);
    this->figures.at(2) = new Figure2(Id::BISHOPBLACK_0, 2, 7, Color::BLACK, Type::BISHOP);
    this->figures.at(3) = new Figure2(Id::QUEENBLACK, 3, 7, Color::BLACK, Type::QUEEN);
    this->figures.at(4) = new Figure2(Id::KING_BLACK, 4, 7, Color::BLACK, Type::KING);
    this->figures.at(5) = new Figure2(Id::BISHOPBLACK_1, 5, 7, Color::BLACK, Type::BISHOP);
    this->figures.at(6) = new Figure2(Id::KNIGHTBLACK_1, 6, 7, Color::BLACK, Type::KNIGHT);
    this->figures.at(7) = new Figure2(Id::ROOKBLACK_1, 7, 7, Color::BLACK, Type::ROOK);

    this->figures.at(8) = new Figure2(Id::PAWNBLACK_0, 0, 6, Color::BLACK, Type::PAWN);
    this->figures.at(9) = new Figure2(Id::PAWNBLACK_1, 1, 6, Color::BLACK, Type::PAWN);
    this->figures.at(10) = new Figure2(Id::PAWNBLACK_2, 2, 6, Color::BLACK, Type::PAWN);
    this->figures.at(11) = new Figure2(Id::PAWNBLACK_3, 3, 6, Color::BLACK, Type::PAWN);
    this->figures.at(12) = new Figure2(Id::PAWNBLACK_4, 4, 6, Color::BLACK, Type::PAWN);
    this->figures.at(13) = new Figure2(Id::PAWNBLACK_5, 5, 6, Color::BLACK, Type::PAWN);
    this->figures.at(14) = new Figure2(Id::PAWNBLACK_6, 6, 6, Color::BLACK, Type::PAWN);
    this->figures.at(15) = new Figure2(Id::PAWNBLACK_7, 7, 6, Color::BLACK, Type::PAWN);

    
    this->figures.at(16) = new Figure2(Id::ROOKWHITE_0, 0, 0, Color::BLACK, Type::ROOK);
    this->figures.at(17) = new Figure2(Id::KNIGHTWHITE_0, 1, 0, Color::BLACK, Type::KNIGHT);
    this->figures.at(18) = new Figure2(Id::BISHOPWHITE_0, 2, 0, Color::BLACK, Type::BISHOP);
    this->figures.at(19) = new Figure2(Id::QUEENWHITE, 3, 0, Color::BLACK, Type::QUEEN);
    this->figures.at(20) = new Figure2(Id::KING_WHITE, 4, 0, Color::BLACK, Type::KING);
    this->figures.at(21) = new Figure2(Id::BISHOPWHITE_1, 5, 0, Color::BLACK, Type::BISHOP);
    this->figures.at(22) = new Figure2(Id::KNIGHTWHITE_1, 6, 0, Color::BLACK, Type::KNIGHT);
    this->figures.at(23) = new Figure2(Id::ROOKWHITE_1, 7, 0, Color::BLACK, Type::ROOK);

    this->figures.at(24) = new Figure2(Id::PAWNWHITE_0, 0, 1, Color::WHITE, Type::PAWN);
    this->figures.at(25) = new Figure2(Id::PAWNWHITE_1, 1, 1, Color::WHITE, Type::PAWN);
    this->figures.at(26) = new Figure2(Id::PAWNWHITE_2, 2, 1, Color::WHITE, Type::PAWN);
    this->figures.at(27) = new Figure2(Id::PAWNWHITE_3, 3, 1, Color::WHITE, Type::PAWN);
    this->figures.at(28) = new Figure2(Id::PAWNWHITE_4, 4, 1, Color::WHITE, Type::PAWN);
    this->figures.at(29) = new Figure2(Id::PAWNWHITE_5, 5, 1, Color::WHITE, Type::PAWN);
    this->figures.at(30) = new Figure2(Id::PAWNWHITE_6, 6, 1, Color::WHITE, Type::PAWN);
    this->figures.at(31) = new Figure2(Id::PAWNWHITE_7, 7, 1, Color::WHITE, Type::PAWN);
}

void GameData::initPosition(int index, Figure figure)
{
    positions[index]["name"] = json::value::string(figure.getName());
    positions[index]["x"] = json::value::number(figure.getPosXAsInt());
    positions[index]["y"] = json::value::number(figure.getPosYAsInt());
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

void GameData::updateFields()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            fields[i][j] = nullptr;
        }
    }

    for(int i=0; i<figures.size(); i++)
    {
        auto x = this->figures.at(i)->getXasInt();
        auto y = this->figures.at(i)->getYasInt();
        this->fields[x][y] = this->figures.at(i);
    }
}