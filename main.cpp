#include "simulator.h"
#include "MyGraphicsScene.h"
#include "MyGraphicsView.h"
#include <qtimeline.h>
#include <time.h>
#include <qapplication.h>
#include <qgraphicsview.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qsrand(time(0));

    MyGraphicsScene scene;
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    scene.setBackgroundBrush(Qt::white);
    scene.setSceneRect(0, 0, 740, 540);

    MyGraphicsView view(&scene);
    view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view.setRenderHint(QPainter::Antialiasing);
    view.show();

    Simulator simulator(&scene);
    simulator.start();

    return app.exec();
}
