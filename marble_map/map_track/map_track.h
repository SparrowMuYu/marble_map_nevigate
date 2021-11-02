//
// Created by sparrow on 11/2/21.
//

#ifndef INC_521_MAP_TRACK_H
#define INC_521_MAP_TRACK_H

#include <marble/MarbleWidget.h>
#include <marble/MarbleModel.h>
#include <marble/RouteRequest.h>
#include <marble/GeoDataPlacemark.h>
#include <marble/RoutingManager.h>
#include <marble/SearchRunnerManager.h>
#include <marble/ReverseGeocodingRunnerManager.h>

class map_track
{
public:
    map_track() {};
    void show_map (Marble::MarbleWidget *widget,
                   Marble::RouteRequest *request);
    void track (Marble::RoutingManager *manager,
                Marble::RouteRequest *request);
    void set_usr_present_search_area (qreal longitude,
                                      qreal latitude,
                                      int if_civil);
    void search_set_target (Marble::SearchRunnerManager *manager);
    void set_target_present (qreal longitude,
                             qreal latitude);
    Marble::GeoDataCoordinates get_usr_present ();

private:
    const qreal search_range = 0.03;
    const int center_index = 0;
    const qreal map_distance = 1;
    const qreal altitude = 0.0;
    const Marble::GeoDataCoordinates::Unit coord_unit =
            Marble::GeoDataCoordinates::Degree;

    QVector<Marble::GeoDataPlacemark*> search_result;
    Marble::GeoDataCoordinates usr_present;
    Marble::GeoDataCoordinates target_present;
    Marble::GeoDataLatLonBox search_area;
};

#endif //INC_521_MAP_TRACK_H
