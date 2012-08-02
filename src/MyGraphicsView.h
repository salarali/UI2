#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
 
#include <QGraphicsView>
#include <QGraphicsRectItem>
 
class MyGraphicsView : public QGraphicsView
{
private:
	const int fieldWidth;
	const int fieldHeight;
public:
    MyGraphicsView(QWidget* parent = NULL);
    MyGraphicsView(QGraphicsScene* scene, QWidget* parent = NULL);
protected:
			void drawBackground(QPainter* painter, const QRectF& rect);
    virtual void resizeEvent(QResizeEvent* event);
};
 
#endif // MYGRAPHICSVIEW_H