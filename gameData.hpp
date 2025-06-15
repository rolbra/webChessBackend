#pragma once

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "figure.hpp"
#include "player.hpp"

typedef utility::string_t utilString;

class GameData
{
public:
    void initPositions();
    GameData();

    web::json::value positions; //this json-string transports the figure informations to the client
    void switchActivePlayer();

private:
    void initPosition(int index, Figure figure);
    void setTransferdata();
    void createFigures();
    
    Figure rook_black_0;
    Figure knight_black_0;
    Figure bishop_black_0;
    Figure queen_black;
    Figure king_black;
    Figure bishop_black_1;
    Figure knight_black_1;
    Figure rook_black_1;

    Figure pawn_black_0;
    Figure pawn_black_1;
    Figure pawn_black_2;
    Figure pawn_black_3;
    Figure pawn_black_4;
    Figure pawn_black_5;
    Figure pawn_black_6;
    Figure pawn_black_7;


    Figure rook_white_0;
    Figure knight_white_0;
    Figure bishop_white_0;
    Figure queen_white;
    Figure king_white;
    Figure bishop_white_1;
    Figure knight_white_1;
    Figure rook_white_1;

    Figure pawn_white_0;
    Figure pawn_white_1;
    Figure pawn_white_2;
    Figure pawn_white_3;
    Figure pawn_white_4;
    Figure pawn_white_5;
    Figure pawn_white_6;
    Figure pawn_white_7;

    Player playerWhite;
    Player playerBlack;
    std::shared_ptr<Player> activePlayer;
};