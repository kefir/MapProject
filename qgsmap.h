#ifndef QGSMAP_H
#define QGSMAP_H

#include <QGraphicsView>
#include "qgsmap/qgslayer.h"
#include "qgsmap/qgsfeatuefactory.h"
#include "qgsmap/qgsmapinfo.h"
#include "qgsmap/qgssettings.h"

class QGSLayer;
class QGSFeatueFactory;
<<<<<<< HEAD
class QGSMapInfo;
class QGSSettings;
=======
class QGSSettings;
class QGSMapInfo;
>>>>>>> acbcfe76a74a984cdf3bca8d3d5c589c0d4a6ffa

class QGSMap : public QGraphicsView
{
    Q_OBJECT

public:
    explicit QGSMap(QWidget *parent = 0);

    //pubclasses
    QGSFeatueFactory *featureFactory;

    //layer operations
    QList<QGSLayer*> getLayers();

    QGSLayer* getLayer(int layerId);
    QGSLayer* getLayer(QString layerName);

    QGSLayer* addLayer(int layerId, QString layerName);

    bool deleteLayer(QString layerName);
    bool deleteLayer(int layerId);

<<<<<<< HEAD
    //map operations

=======
    //mapfunctions
>>>>>>> acbcfe76a74a984cdf3bca8d3d5c589c0d4a6ffa
    QGraphicsScene* loadMap(QString mapName = "");

    //server settings
    bool setServerSettings(QString serverHost, int serverPort);
    QGSSettings* getServerSettings();

signals:

public slots:

private:
    bool mapLoaded;
    QGSMapInfo *mapInfo;
    QGSSettings *serverSettings;

    QList<QGSLayer*> layers;


private slots:

protected:

};

#endif // QGSMAP_H
