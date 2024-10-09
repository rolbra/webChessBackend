class FigureMover
{
public:
    FigureMover(GameData& data);
    void moveFigure(std::string from, std::string to);

public:
    GameData* gameData;
};