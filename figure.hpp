#define ROOKBLACK "&#x265C;"
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