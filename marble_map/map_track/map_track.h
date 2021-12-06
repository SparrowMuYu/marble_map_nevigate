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

#include "../amb_sim/amb_sim.h"

class map_track : public QWidget
{
Q_OBJECT
public:
    map_track(QWidget *parent = 0);
    void start_sim();

public:
    void show_map ();
    void track ();
    void renew_route_hos ();
    void search_set_hos ();
    void set_usr_present_search_area (qreal longitude,
                                      qreal latitude,
                                      int if_search_hos);
    qreal find_distance (Marble::GeoDataCoordinates coord);
    qreal find_distance ();
    Marble::GeoDataCoordinates get_usr_present ();

public slots:
    void setCarCoordinates(const Marble::GeoDataCoordinates &coord);
    void renew_route_target ();
    void set_target_present ();
    void update_hos ();

private:
    const qreal search_range = 0.05;
    const int center_index = 0;
    const qreal map_distance = 2;
    const qreal altitude = 0.0;
    const Marble::GeoDataCoordinates::Unit coord_unit =
            Marble::GeoDataCoordinates::Degree;

    const QString map_theme_id = "earth/openstreetmap/openstreetmap.dgml";

    QVector<Marble::GeoDataPlacemark*> search_result;
    Marble::GeoDataCoordinates usr_present;
    Marble::GeoDataCoordinates hos_present;
    Marble::GeoDataCoordinates target_present;
    Marble::GeoDataLatLonBox search_area;

    qreal usr_lon, usr_lat;

    amb_sim *amb;

    Marble::MarbleWidget *map_widget;
    Marble::MarbleModel *model;
    Marble::SearchRunnerManager *s_manager;
    Marble::ReverseGeocodingRunnerManager *rg_manager;

    Marble::RoutingManager *r_manager;
    Marble::RouteRequest *r_request;

    Marble::GeoDataDocument *doc;
};

#endif //INC_521_MAP_TRACK_H
