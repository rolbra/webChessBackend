#include "gameData.hpp"

using namespace web;
using namespace web::http;

GameData::GameData()
{
    createFigures();
    
    playerWhite.init( 0, "Pris" );
    playerBlack.init( 1, "Roli" );
    this->activePlayer = std::make_shared<Player>(playerWhite);
    
    setTransferdata();
    initPositions();
}

void GameData::createFigures()
{
    rook_black_0.init("rook_black_0", 0, 7, ROOKBLACK, "black", "rook");
    knight_black_0.init("knight_black_0", 1, 7, KNIGHTBLACK, "black", "knight");
    bishop_black_0.init("bishop_black_0", 2, 7, BISHOPBLACK, "black", "bishop");
    queen_black.init("queen_black", 3, 7, QUEENTBLACK, "black", "queen");
    king_black.init("king_black", 4, 7, KINGBLACK, "black", "king");
    bishop_black_1.init("bishop_black_1", 5, 7, BISHOPBLACK, "black", "bishop");
    knight_black_1.init("knight_black_1", 6, 7, KNIGHTBLACK, "black", "knight");
    rook_black_1.init("rook_black_1", 7, 7, ROOKBLACK, "black", "rook");

    pawn_black_0.init("pawn_black_0", 0, 6, PAWNBLACK, "black", "pawn");
    pawn_black_1.init("pawn_black_1", 1, 6, PAWNBLACK, "black", "pawn");
    pawn_black_2.init("pawn_black_2", 2, 6, PAWNBLACK, "black", "pawn");
    pawn_black_3.init("pawn_black_3", 3, 6, PAWNBLACK, "black", "pawn");
    pawn_black_4.init("pawn_black_4", 4, 6, PAWNBLACK, "black", "pawn");
    pawn_black_5.init("pawn_black_5", 5, 6, PAWNBLACK, "black", "pawn");
    pawn_black_6.init("pawn_black_6", 6, 6, PAWNBLACK, "black", "pawn");
    pawn_black_7.init("pawn_black_7", 7, 6, PAWNBLACK, "black", "pawn");


    rook_white_0.init("rook_white_0", 0, 0, ROOKWHITE, "white", "rook");
    knight_white_0.init("knight_white_0", 1, 0, KNIGHTWHITE, "white", "knight");
    bishop_white_0.init("bishop_white_0", 2, 0, BISHOPWHITE, "white", "bishop");
    queen_white.init("queen_white", 3, 0, QUEENTWHITE, "white", "queen");
    king_white.init("king_white", 4, 0, KINGWHITE, "white", "king");
    bishop_white_1.init("bishop_white_1", 5, 0, BISHOPWHITE, "white", "bishop");
    knight_white_1.init("knight_white_1", 6, 0, KNIGHTWHITE, "white", "knight");
    rook_white_1.init("rook_white_1", 7, 0, ROOKWHITE, "white", "rook");

    pawn_white_0.init("pawn_white_0", 0, 1, PAWNWHITE, "white", "pawn");
    pawn_white_1.init("pawn_white_1", 1, 1, PAWNWHITE, "white", "pawn");
    pawn_white_2.init("pawn_white_2", 2, 1, PAWNWHITE, "white", "pawn");
    pawn_white_3.init("pawn_white_3", 3, 1, PAWNWHITE, "white", "pawn");
    pawn_white_4.init("pawn_white_4", 4, 1, PAWNWHITE, "white", "pawn");
    pawn_white_5.init("pawn_white_5", 5, 1, PAWNWHITE, "white", "pawn");
    pawn_white_6.init("pawn_white_6", 6, 1, PAWNWHITE, "white", "pawn");
    pawn_white_7.init("pawn_white_7", 7, 1, PAWNWHITE, "white", "pawn");
}

void GameData::switchActivePlayer()
{
    if(activePlayer->getId() == playerWhite.getId())
        activePlayer = std::make_shared<Player>(playerBlack);
    else if(activePlayer->getId() == playerBlack.getId())
        activePlayer = std::make_shared<Player>(playerWhite);
    else
    {
        std::cout << "error switching active player";
        return;
    }

    this->positions["activePlayer"]["id"] = json::value::number(this->activePlayer->getId());
    this->positions["activePlayer"]["name"] = json::value::string(activePlayer->getName());

    std::cout << "next move performs " << activePlayer->getName() << std::endl;
}

void GameData::initPosition(int index, Figure figure)
{
    const auto figures = utilString("figures");

    positions[figures][index]["name"] = json::value::string(figure.getName());
    positions[figures][index]["x"] = json::value::string(figure.getPosXAsChar());
    positions[figures][index]["y"] = json::value::string(figure.getPosYAsChar());
    positions[figures][index]["code"] = json::value::string(figure.getCode());
    positions[figures][index]["color"] = json::value::string(figure.getColor());
    positions[figures][index]["type"] = json::value::string(figure.getType());
}

void GameData::setTransferdata()
{
    positions[utilString("gameInfo")][utilString("id")] = json::value::number( 100 );
    
    positions[utilString("playerWhite")][utilString("id")] = json::value::number( playerWhite.getId() );
    positions[utilString("playerWhite")][utilString("name")] = json::value::string( playerWhite.getName() );
    
    positions[utilString("playerBlack")][utilString("id")] = json::value::number( playerBlack.getId() );
    positions[utilString("playerBlack")][utilString("name")] = json::value::string( playerBlack.getName() );

    positions[utilString("activePlayer")][utilString("id")] = json::value::number( activePlayer->getId() );
    positions[utilString("activePlayer")][utilString("name")] = json::value::string( activePlayer->getName() );
}

void GameData::initPositions()
{
    int index=0; //todo: use a loop for init
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