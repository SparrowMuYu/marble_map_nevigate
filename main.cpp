#include <QApplication>
#include <QtCore/QDebug>
#include <marble/MarbleWidget.h>
#include <marble/MarbleModel.h>
#include <marble/RouteRequest.h>
#include <marble/RoutingManager.h>
#include <marble/SearchRunnerManager.h>
#include <marble/GeoDataPlacemark.h>
#include <marble/MarbleRunnerManager.h>

using namespace Marble;

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    // Create a Marble QWidget without a parent
    MarbleWidget *mapWidget = new MarbleWidget();

    // Load the OpenStreetMap map
    mapWidget->setMapThemeId( "earth/openstreetmap/openstreetmap.dgml" );
    mapWidget->setProjection( Mercator );

    MarbleModel *model = new MarbleModel;
    SearchRunnerManager* s_manager = new SearchRunnerManager( model );
    MarbleRunnerManager* r_manager = new MarbleRunnerManager( model->pluginManager() );
    r_manager->setModel( model );

    QVector<GeoDataPlacemark*> searchResult = s_manager->searchPlacemarks( "Saint Louis" );
            foreach( GeoDataPlacemark* placemark, searchResult ) {
            qDebug() << "Found " << placemark->name() << "at" << placemark->coordinate().toString() << "we have" << placemark->visualCategory();
        }

    // Access the shared route request (start, destination and parameters)
    RoutingManager* manager = mapWidget->model()->routingManager();
    RouteRequest* request = manager->routeRequest();

    // Use default routing settings for cars
    request->setRoutingProfile( manager->defaultProfile( RoutingProfile::Motorcar ) );

    // Set start and destination
    request->append( GeoDataCoordinates( -90.31, 38.65, 0.0, GeoDataCoordinates::Degree ) );
    request->append( GeoDataCoordinates( -90.305, 38.647, 0.0, GeoDataCoordinates::Degree ) );

    // Calculate the route
    manager->retrieveRoute();

    GeoDataCoordinates position( -90.31,  38.65, 0.0, GeoDataCoordinates::Degree );
    qDebug() << position.toString() << "is" << r_manager->searchReverseGeocoding( position );

    // Center the map on the route start point and show it
    mapWidget->centerOn( request->at( 0 ) );
    mapWidget->setDistance( 0.75 );
    mapWidget->show();

    return app.exec();
}
