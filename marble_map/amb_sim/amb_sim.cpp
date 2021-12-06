//
// Created by sparrow on 12/5/21.
//

#include "amb_sim.h"
#include "stdlib.h"

amb_sim::amb_sim() {
    updta_timer = new QTimer(this);
    amb_thread = new QThread;
    amb_place_mark = new Marble::GeoDataPlacemark("ambulance");
    init_coord = Marble::GeoDataCoordinates(lon, lat, altitude, coord_unit);
    this->moveToThread(amb_thread);

    connect(amb_thread, SIGNAL(started()), this, SLOT(startWork()));
    connect(amb_thread, SIGNAL(finished()), this, SLOT(finishWork()));

    amb_thread->start();
}

void amb_sim::startWork()
{
    updta_timer->setInterval(10);
    connect(updta_timer, SIGNAL(timeout()), this, SLOT(iterate()));
    updta_timer->start();
}

void amb_sim::iterate()
{
    bool reach_lon = false, reach_lat = false;
    qreal p_lon = patient_coord->longitude(coord_unit);
    qreal p_lat = patient_coord->latitude(coord_unit);

    Marble::GeoDataCoordinates coord(lon, lat, altitude, coord_unit);
    if (lon_rec != lon || lat_rec != lat) {
        lon_rec = lon;
        lat_rec = lat;
        emit coordinatesChanged(coord);
    }


    if (lon < p_lon) {
        if (p_lon - lon > 0.001) {
            lon = lon + 0.0001;
        } else {
            reach_lon = true;
        }
    } else {
        if (p_lon > 0.001) {
            lon = lon - 0.0001;
        } else {
            reach_lon = true;
        }
    }
    if (lat < p_lat) {
        if (p_lat > 0.0001) {
            lat = lat + 0.0001;
        } else {
            reach_lat = true;
        }
    } else {
        if (lat - p_lat > 0.0001) {
            lat = lat - 0.0001;
        } else {
            reach_lat = true;
        }
    }

    if (reach_lon && reach_lat) {
        if (!if_reach_patient) {
            emit reach_patient();
            if_reach_patient = true;
        } else {
            amb_thread->exit();
        }
    }
}

void amb_sim::finishWork()
{
    updta_timer->stop();
    QApplication::quit();
    exit(EXIT_SUCCESS);
}

Marble::GeoDataPlacemark* amb_sim::get_amb_place_mark() {
    return &*amb_place_mark;
}

void amb_sim::set_patient_coord(Marble::GeoDataCoordinates *coord) {
    patient_coord = coord;
}



