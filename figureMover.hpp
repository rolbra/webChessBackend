class FigureMover
{
public:
    FigureMover(GameData& data);
    void moveFigure(std::string from, std::string to);
    void resetPositions();

public:
    GameData* gameData;

private:
    std::string translatePosition(const std::string pos);
    int findFigureByPosition(const std::string pos);
    void setFigurePosition(const int index, const std::string pos);
};