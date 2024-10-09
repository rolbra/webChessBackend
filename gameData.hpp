#include <cpprest/http_listener.h>
#include <cpprest/json.h>

class GameData
{
    void initPositions();

public:
    GameData();

    int id;
    web::json::value positions;
};