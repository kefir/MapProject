#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsItem>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = ui->gsMap->loadMap("test");

    if(scene != NULL)
    {

        QPixmap pix("lol.png");
        QGSLayer *lyr = ui->gsMap->addLayer(1, "Test");

        ui->gsMap->featureFactory->addPoint(lyr, 10, 10);
        ui->gsMap->featureFactory->addPoint(lyr, 20, 10);
        ui->gsMap->featureFactory->addPoint(lyr, 0, 23);
    }
    else
        qDebug() << "Map not found";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();

    if(item != NULL)
    {

    QGSLayer *lyr = ui->gsMap->getLayer(item->text(0));

    if(lyr->isVisible())
        lyr->setVisible(false);
    else
        lyr->setVisible(true);

    }

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->treeWidget->clear();

    QList<QGSLayer*> layers = ui->gsMap->getLayers();

    for(int i=0;i<layers.count();i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0, layers.at(i)->getName());
        ui->treeWidget->addTopLevelItem(item);
    }


}
