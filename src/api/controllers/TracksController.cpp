

#include "TracksController.h"
#include "../config/Constants.h"
#include "../dao/MongoDao.h"

TracksController::TracksController() {
    addRoute(HTTP_GET, "/tracks/",
             new RequestHandler<TracksController, JSONResponse>(this, &TracksController::get));
}

TracksController::~TracksController() {

}

void TracksController::get(Request &request, JSONResponse &response) {
    MongoDao dao;
    Track *track = dao.getTrack(1122265510);
    response["songId"] = 1234;
    response["url"] = "http://127.0.0.1:8080/music/moonlight.mp3"; // TODO: Get the real one
    delete track;
}