#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "handles.hpp"

using namespace web;
using namespace web::http;

void handle_options( http_request request )
{
    std::cout << "incoming OPTIONS request\n";
    std::cout << "-------------------------\n";
    std::cout << request.to_string() << "\n";
    
    http_response response(status_codes::OK);
    response.headers().add(U("Access-Control-Allow-Methods"), U("POST, OPTIONS"));
    response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type, Access-Control-Allow-Origin"));
    response.headers().add(U("Access-Control-Allow-Origin"), U("*"));

    request.reply( response );
}

void handle_post( http_request request )
{
    std::cout << "incoming POST request\n";
    std::cout << "-------------------------\n";
    std::cout << request.to_string() << "\n";
    
    request.extract_json()
    .then( [=]( json::value jsonData )
    {
        json::value responseData;
        responseData["message"] = json::value::string("Data received successfully");

        http_response response(status_codes::OK);
        response.headers().add(U("Access-Control-Allow-Methods"), U("POST, OPTIONS"));
        response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type, Access-Control-Allow-Origin"));
        response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
        response.set_body(responseData);

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
    
    json::value responseData;
    responseData["message"] = json::value::string("What's up?");

    request.reply( status_codes::OK, responseData );
}