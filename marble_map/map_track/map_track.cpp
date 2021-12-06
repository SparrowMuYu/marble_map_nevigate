//
// Created by sparrow on 11/2/21.
//

#include "map_track.h"

map_track::map_track(QWidget *parent) {
    map_widget = new Marble::MarbleWidget();
    model = new Marble::MarbleModel;
    s_manager = new Marble::SearchRunnerManager(model);
    rg_manager = new Marble::ReverseGeocodingRunnerManager(model);

    map_widget->setMapThemeId(map_theme_id);
    map_widget->setProjection(Marble::Mercator);
    r_manager = map_widget->model()->routingManager();
    r_request = r_manager->routeRequest();

    doc = new Marble::GeoDataDocument;
    amb = new amb_sim();

    doc->append(amb->get_amb_place_mark());

    map_widget->model()->treeModel()->addDocument(doc);
}

void map_track::show_map () {
    map_widget->centerOn(r_request->at(center_index));
    map_widget->setDistance(map_distance);
    map_widget->showFullScreen();
}

void map_track::track () {
    r_request->setRoutingProfile
    (
            r_manager->defaultProfile
            (
                    Marble::RoutingProfile::Motorcar
            )
    );
    r_request->append(usr_present);
    r_request->append(target_present);
    r_manager->retrieveRoute();
}

void map_track::renew_route_target () {
    int index = r_request->size()-1;
    r_request->remove(index);
    r_request->insert(index, target_present);
    r_manager->retrieveRoute();
}

void map_track::renew_route_hos () {
    int index = r_request->size()-2;
    r_request->remove(index);
    r_request->insert(index, hos_present);
    r_manager->retrieveRoute();
}

void map_track::set_usr_present_search_area (qreal longitude,
                                             qreal latitude,
                                             int if_search_hos) {
    usr_lon = longitude;
    usr_lat = latitude;
    usr_present = Marble::GeoDataCoordinates(longitude,
                                             latitude,
                                             altitude,
                                             coord_unit);
    amb->set_patient_coord(&usr_present);
    if (if_search_hos) {
        search_area = Marble::GeoDataLatLonBox
                (usr_present.latitude(coord_unit) + search_range,
                 usr_present.latitude(coord_unit) - search_range,
                 usr_present.longitude(coord_unit) + search_range,
                 usr_present.longitude(coord_unit) - search_range,
                 coord_unit);
    }
}

qreal  map_track::find_distance(Marble::GeoDataCoordinates coord) {
    qreal lon, lat, distance;

    lon = coord.longitude(coord_unit);
    lat = coord.latitude(coord_unit);

    distance = lon * lon + lat * lat - usr_lon * usr_lon - usr_lat * usr_lat;
    if (distance >= 0) {
        return distance;
    } else {
        return -distance;
    }
}

qreal map_track::find_distance() {
    qreal lon, lat, distance;

    lon = target_present.longitude(coord_unit);
    lat = target_present.latitude(coord_unit);

    distance = lon * lon + lat * lat - usr_lon * usr_lon - usr_lat * usr_lat;
    if (distance >= 0) {
        return distance;
    } else {
        return -distance;
    }
}

void map_track::search_set_hos() {
    QVector<Marble::GeoDataPlacemark *> searchResult =
            s_manager->searchPlacemarks("hospital", search_area, 30000);
    bool if_find = false;
    qreal distance = -1, current_distance;
    foreach(Marble::GeoDataPlacemark *placemark, searchResult) {
        current_distance = find_distance(placemark->coordinate());
        if (distance == -1) {
            distance = current_distance;
            if_find = true;
            hos_present = placemark->coordinate();
        } else if (distance > current_distance) {
            distance = current_distance;
            if_find = true;
            hos_present = placemark->coordinate();
        }
    }
}
void map_track::update_hos () {
    amb->set_patient_coord(&hos_present);
    renew_route_hos();
}

void map_track::set_target_present () {
    target_present = amb->get_amb_place_mark()->coordinate();
}

Marble::GeoDataCoordinates map_track::get_usr_present () {
    return usr_present;
}

void map_track::start_sim() {
    QObject::connect(amb,
                     SIGNAL(coordinatesChanged(Marble::GeoDataCoordinates)),
                     this,
                     SLOT(setCarCoordinates(Marble::GeoDataCoordinates)),
                     Qt::BlockingQueuedConnection);
    QObject::connect(amb,
                     SIGNAL(coordinatesChanged(Marble::GeoDataCoordinates)),
                     this,
                     SLOT(renew_route_target()), Qt::BlockingQueuedConnection);
    QObject::connect(amb,
                     SIGNAL(coordinatesChanged(Marble::GeoDataCoordinates)),
                     this,
                     SLOT(set_target_present()), Qt::BlockingQueuedConnection);
    QObject::connect(amb,
                     SIGNAL(reach_patient()),
                     this,
                     SLOT(update_hos()), Qt::BlockingQueuedConnection);
}

void map_track::setCarCoordinates(const Marble::GeoDataCoordinates &coord) {
    amb->get_amb_place_mark()->setCoordinate(coord);
    map_widget->model()->treeModel()->updateFeature(amb->get_amb_place_mark());
}

