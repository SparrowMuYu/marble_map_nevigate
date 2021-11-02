//
// Created by sparrow on 11/2/21.
//

#include "map_init.h"

map_init::map_init() {
    map_widget = new Marble::MarbleWidget();
    model = new Marble::MarbleModel;
    s_manager = new Marble::SearchRunnerManager(model);
    rg_manager = new Marble::ReverseGeocodingRunnerManager(model);
    map_tracker = new map_track();

    map_widget->setMapThemeId(map_theme_id);
    map_widget->setProjection(Marble::Mercator);
    r_manager = map_widget->model()->routingManager();
    r_request = r_manager->routeRequest();
}

map_init::~map_init() {
    delete map_widget;
    delete model;
    delete s_manager;
    delete rg_manager;
    delete r_manager;
    delete r_request;
    delete map_tracker;
}

Marble::MarbleWidget* map_init::get_map_widget () {
    return map_widget;
}

Marble::MarbleModel* map_init::get_model () {
    return model;
}

Marble::SearchRunnerManager* map_init::get_s_manager () {
    return s_manager;
}

Marble::ReverseGeocodingRunnerManager* map_init::get_rg_manager () {
    return rg_manager;
}

Marble::RoutingManager* map_init::get_r_manager() {
    return r_manager;
}

Marble::RouteRequest* map_init::get_r_request() {
    return r_request;
}

map_track* map_init::get_map_tracker() {
    return map_tracker;
}