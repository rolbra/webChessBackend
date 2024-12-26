#include <iostream>
#include <cpprest/http_listener.h>
#include "handles.hpp"
#include <unordered_map>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;


int main(void)
{
    std::cout << "server started\n";

    uri_builder uri(U("http://0.0.0.0:8080/api"));
    auto addr = uri.to_uri().to_string();

    http_listener listener(addr);
    listener.support( methods::OPTIONS, handle_options );

    std::unordered_map<utility::string_t, HandlerFunction> routes = {
        { U("/api/positions"), handlePostGetPositions },
        { U("/api/resetGame"), handlePostResetGame },
        { U("/api/moveFigure"), handlePostMoveFigure },
        { U("/api/gameStatus"), handleGetGameStatus }
    };

    listener.support(methods::POST, [&](http_request request) {
        handleRequests(request, routes);
    });

    try
    {
        listener.open().wait();
        std::cout << "Server running at " << addr << "\n";
        std::cout << "==============================================\n\n";
        std::cin.get();
        listener.close().wait();
    }
    catch( const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}