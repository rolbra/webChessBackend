#include "handles.hpp"

using namespace web;
using namespace web::http;

GameData gameData;
FigureMover figureMover(gameData);

void logRequest( http_request request )
{
    static int requestCounter = 1;
    std::cout << "incoming request no " << requestCounter++ << "\n";
    std::cout << "-------------------------\n";
    std::cout << request.to_string() << "\n";
}

void setResponseHeaders( http_response &response )
{
    response.headers().add(U("Access-Control-Allow-Methods"), U("POST, OPTIONS"));
    response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type, Access-Control-Allow-Origin"));
    response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
}

void handle_options( http_request request )
{
    http_response response(status_codes::OK);
    setResponseHeaders( response );

    request.reply( response );
}

void updatePositions()
{
    
}

void handleRequests( http_request request, const std::unordered_map<utility::string_t, HandlerFunction>& routes )
{
    auto path = request.request_uri().path();

    auto it = routes.find(path);
    if (it != routes.end()) {
        logRequest( request );
        it->second(request); // Call the associated handler
    } else {
        request.reply(status_codes::NotFound, U("Not Found"));
    }
}

void handlePostGetPositions(web::http::http_request request)
{
    request.extract_json()
        .then( [=]( json::value jsonData )
        {
            http_response response(status_codes::OK);
            setResponseHeaders(response);
            response.set_body(gameData.positions);

            std::cout << gameData.positions << std::endl;
            std::flush( std::cout );

            request.reply(response);
        })
        .then( [=]( pplx::task<void> previousTask )
        {
            try
            {
                previousTask.get(); // This will throw if there was an error in the previous task
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error extracting JSON: " << e.what() << "\n";
                
                json::value responseData;
                responseData["message"] = json::value::string("Invalid JSON format");
                request.reply(status_codes::OK, responseData);
            }
        })
        .wait();
}

void handlePostResetGame( http_request request )
{
    request.extract_json()
        .then( [=]( json::value jsonData )
        {
            http_response response(status_codes::OK);
            setResponseHeaders(response);

            figureMover.resetPositions();

            response.set_body(gameData.positions);

            request.reply(response);
        })
        .then( [=]( pplx::task<void> previousTask )
        {
            try
            {
                previousTask.get(); // This will throw if there was an error in the previous task
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error extracting JSON: " << e.what() << "\n";
                
                json::value responseData;
                responseData["message"] = json::value::string("Invalid JSON format");
                request.reply(status_codes::OK, responseData);
            }
        })
        .wait();
}

void handlePostMoveFigure( http_request request )
{
    request.extract_json()
        .then( [=]( json::value jsonData )
        {
            http_response response(status_codes::OK);
            setResponseHeaders(response);

            std::string from = jsonData["from"].as_string();
            std::string to = jsonData["to"].as_string();
            
            //figureMover.evaluateMove(from, to);
            figureMover.moveFigure( from, to );
            gameData.switchActivePlayer();
            
            response.set_body(gameData.positions);

            request.reply(response);
        })
        .then( [=]( pplx::task<void> previousTask )
        {
            try
            {
                previousTask.get(); // This will throw if there was an error in the previous task
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error extracting JSON: " << e.what() << "\n";
                
                json::value responseData;
                responseData["message"] = json::value::string("Invalid JSON format");
                request.reply(status_codes::OK, responseData);
            }
        })
        .wait();
}

void handleGetGameStatus( http_request request )
{
    http_response response(status_codes::OK);
    setResponseHeaders(response);
    
    json::value responseData;
    responseData["Matchup"] = json::value::string("Benni vs. Roli");
    responseData["Game created"] = json::value::string("Oct/01/2024");
    response.set_body(responseData);

    request.reply(response);
}
