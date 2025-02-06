class FigureMover
{
public:
    FigureMover(GameData& data);
    bool evaluateMove(std::string from, std::string to);
    void moveFigure(std::string from, std::string to);
    void resetPositions();

public:
    GameData* gameData;

private:
    std::string translatePosition(const std::string pos);
    int findFigureIndexByPosition(const std::string pos);
    void setFigurePosition(const int index, const std::string pos);

    bool evaluateRook(std::string from, std::string to);
    bool evaluateKnight(std::string from, std::string to);
    bool evaluateBishop(std::string from, std::string to);
    bool evaluateQueen(std::string from, std::string to);
    bool evaluateKing(std::string from, std::string to);
    bool evaluatePawn(std::string from, std::string to);
};