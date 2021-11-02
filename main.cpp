#include <QApplication>
#include <QtCore/QDebug>
#include "marble_map/map_init.h"

using namespace Marble;

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    map_init *marble_map = new map_init();

    // Create a Marble QWidget without a parent
    MarbleWidget *mapWidget = new MarbleWidget();

    marble_map->get_map_tracker()->set_usr_present_search_area(
            -90.31, 38.65, 1);
    marble_map->get_map_tracker()->set_target_present(
            -90.311, 38.6321);
    marble_map->get_map_tracker()->track(marble_map->get_r_manager(),
                                         marble_map->get_r_request());
    marble_map->get_map_tracker()->show_map(marble_map->get_map_widget(),
                                            marble_map->get_r_request());

    return app.exec();
}
