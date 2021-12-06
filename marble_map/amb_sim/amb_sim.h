//
// Created by sparrow on 12/5/21.
//

#ifndef INC_521_AMB_SIM_H
#define INC_521_AMB_SIM_H

#include <QApplication>
#include <QtCore/QThread>
#include <QtCore/QTimer>
#include <QtCore/QHash>
#include <QtCore/qmath.h>
#include <QtCore/QDebug>
#include <QVBoxLayout>

#include <marble/MarbleWidget.h>
#include <marble/MarbleGlobal.h>
#include <marble/GeoDataDocument.h>
#include <marble/GeoDataPlacemark.h>
#include <marble/GeoDataLineString.h>
#include <marble/GeoDataTreeModel.h>
#include <marble/MarbleModel.h>

class amb_sim : public QObject {
Q_OBJECT
public:
    amb_sim();

signals:
    void coordinatesChanged(Marble::GeoDataCoordinates coord);
    void reach_patient();

public slots:
    void startWork();
    void finishWork();

public:
    void set_patient_coord (Marble::GeoDataCoordinates *coord);
    Marble::GeoDataPlacemark* get_amb_place_mark();

private slots:
    void iterate();

private:
    Marble::GeoDataPlacemark *amb_place_mark;
    QThread *amb_thread;
    QTimer *updta_timer;
    Marble::GeoDataCoordinates init_coord;
    Marble::GeoDataCoordinates *patient_coord;

    qreal lon = -90.35, lon_rec = lon;
    qreal lat = 38.64, lat_rec = lat;
    const qreal altitude = 0.0;
    const Marble::GeoDataCoordinates::Unit coord_unit =
            Marble::GeoDataCoordinates::Degree;
    bool if_reach_patient = false;
};


#endif //INC_521_AMB_SIM_H
