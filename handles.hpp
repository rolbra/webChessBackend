void handle_options( web::http::http_request request );

using HandlerFunction = std::function<void(web::http::http_request)>;

void handleRequests( web::http::http_request request, const std::unordered_map<utility::string_t, HandlerFunction>& routes );
void handlePostGetPositions( web::http::http_request request );
void handlePostResetGame( web::http::http_request request );
void handlePostMoveFigure( web::http::http_request request );

void handleGetGameStatus( web::http::http_request request );