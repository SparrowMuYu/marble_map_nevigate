//
// Created by sparrow on 11/2/21.
//

#ifndef INC_521_MAP_INIT_H
#define INC_521_MAP_INIT_H

#include <marble/MarbleWidget.h>
#include <marble/MarbleModel.h>
#include <marble/RouteRequest.h>
#include <marble/GeoDataPlacemark.h>
#include <marble/RoutingManager.h>
#include <marble/SearchRunnerManager.h>
#include <marble/ReverseGeocodingRunnerManager.h>

#include "map_track/map_track.h"
#include "amb_sim//amb_sim.h"

class map_init
{
public:
    map_init();
    ~map_init();

    Marble::MarbleWidget* get_map_widget ();
    Marble::MarbleModel* get_model ();
    Marble::SearchRunnerManager* get_s_manager ();
    Marble::ReverseGeocodingRunnerManager* get_rg_manager ();
    Marble::RoutingManager* get_r_manager ();
    Marble::RouteRequest* get_r_request ();
    map_track* get_map_tracker ();

private:
    const QString map_theme_id = "earth/openstreetmap/openstreetmap.dgml";
    map_track *map_tracker;
    amb_sim *amb;

    Marble::MarbleWidget *map_widget;
    Marble::MarbleModel *model;
    Marble::SearchRunnerManager *s_manager;
    Marble::ReverseGeocodingRunnerManager *rg_manager;

    Marble::RoutingManager *r_manager;
    Marble::RouteRequest *r_request;

    Marble::GeoDataDocument *doc;
};

#endif //INC_521_MAP_INIT_H
