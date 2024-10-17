class FigureMover
{
public:
    FigureMover(GameData& data);
    void moveFigure(std::string from, std::string to);

public:
    GameData* gameData;

private:
    int findFigureByPosition(const std::string pos);
    void setFigurePosition(const int index, const std::string pos);
};