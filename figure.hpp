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

    void init(std::string name, int posX, int posY, std::string code);

    std::string getName();

    void setPosX(int x);
    void setPosY(int y);
    int getPosXAsInt();
    int getPosYAsInt();
    std::string getPosXAsChar();
    std::string getPosYAsChar();

    std::string getCode();

private:
    std::string name;
    int x;
    int y;
    std::string code;
};



enum class Color
{
    WHITE,
    BLACK
};

enum class Type
{
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN
};

enum Id
{
    ROOKBLACK_0,
    KNIGHTBLACK_0,
    BISHOPBLACK_0,
    QUEENBLACK,
    KING_BLACK, //todo: delete define KINGBLACK
    BISHOPBLACK_1,
    KNIGHTBLACK_1,
    ROOKBLACK_1,

    PAWNBLACK_0,
    PAWNBLACK_1,
    PAWNBLACK_2,
    PAWNBLACK_3,
    PAWNBLACK_4,
    PAWNBLACK_5,
    PAWNBLACK_6,
    PAWNBLACK_7,

    ROOKWHITE_0,
    KNIGHTWHITE_0,
    BISHOPWHITE_0,
    QUEENWHITE,
    KING_WHITE, //todo: delete define KINGWHITE
    BISHOPWHITE_1,
    KNIGHTWHITE_1,
    ROOKWHITE_1,

    PAWNWHITE_0,
    PAWNWHITE_1,
    PAWNWHITE_2,
    PAWNWHITE_3,
    PAWNWHITE_4,
    PAWNWHITE_5,
    PAWNWHITE_6,
    PAWNWHITE_7
};

class Figure2
{

public:
    Figure2();
    Figure2(Id id, int posX, int posY, Color color, Type type);

    int getXasInt();
    int getYasInt();

private:
    Id id;
    int x;
    int y;
    Color color;
    Type type;
};