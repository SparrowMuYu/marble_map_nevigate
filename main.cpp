#include <QApplication>
#include <QtCore/QDebug>
#include "marble_map/map_init.h"

#include <iostream>

using namespace Marble;

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    map_track *marble_map = new map_track();
    // example -90.31, 38.65
    float lon = atof(argv[1]);
    float lat = atof(argv[2]);
    marble_map->set_usr_present_search_area(
            lon, lat, 1);
    marble_map->search_set_hos();
    marble_map->set_target_present();
    marble_map->track();
    marble_map->show_map();
    marble_map->start_sim();

    return app.exec();
}

#include "main.moc"