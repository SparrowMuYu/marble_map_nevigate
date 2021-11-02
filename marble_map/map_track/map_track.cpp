//
// Created by sparrow on 11/2/21.
//

#include "map_track.h"

void map_track::show_map (Marble::MarbleWidget *widget,
                          Marble::RouteRequest *request) {
    widget->centerOn(request->at(center_index));
    widget->setDistance(map_distance);
    widget->show();
}

void map_track::track (Marble::RoutingManager *manager,
                       Marble::RouteRequest *request) {
    request->setRoutingProfile
    (
            manager->defaultProfile
            (
                    Marble::RoutingProfile::Motorcar
            )
    );
    request->append(usr_present);
    request->append(target_present);
    manager->retrieveRoute();
}

void map_track::set_usr_present_search_area (qreal longitude,
                                             qreal latitude,
                                             int if_civil) {
    usr_present = Marble::GeoDataCoordinates(longitude,
                                             latitude,
                                             altitude,
                                             coord_unit);
    if (if_civil) {
        search_area = Marble::GeoDataLatLonBox
                (usr_present.latitude(coord_unit) + search_range,
                 usr_present.latitude(coord_unit) - search_range,
                 usr_present.longitude(coord_unit) + search_range,
                 usr_present.longitude(coord_unit) - search_range,
                 coord_unit);
    }
}

void map_track::search_set_target(Marble::SearchRunnerManager *manager) {
    QVector<Marble::GeoDataPlacemark*> searchResult =
            manager->searchPlacemarks("hospital", search_area, 30000);
    /*
    foreach( Marble::GeoDataPlacemark* placemark, searchResult ) {
        placemark->coordinate().latitude()
    }
    */
}

void map_track::set_target_present (qreal longitude, qreal latitude) {
    target_present = Marble::GeoDataCoordinates(longitude,
                                                latitude,
                                                altitude,
                                                coord_unit);
}

Marble::GeoDataCoordinates map_track::get_usr_present () {
    return usr_present;
}