#include <cpprest/http_listener.h>
#include <cpprest/json.h>

class GameData
{

public:
    void initPositions();
    GameData();

    int id;
    web::json::value positions;
};