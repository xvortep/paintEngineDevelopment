#ifndef QPAINTENGINE_MINIMAL_H
#define QPAINTENGINE_MINIMAL_H

#include <QtCore/qdebug.h>

#include <iostream>

#include "QtGui/qpaintengine.h"


#define PRITI do{std::cout << __PRETTY_FUNCTION__ << std::endl;}while(0)

QT_BEGIN_NAMESPACE

class QPaintEngine;

class Q_GUI_EXPORT QMinimalPaintEngine : public QPaintEngine // TODO check this Q_GUI_EXPORT thing
{
public:

    QMinimalPaintEngine();
    ~QMinimalPaintEngine();

    /* reimplemented methods start here */
    bool begin(QPaintDevice *pdev) override;
    bool end() override;

    void updateState(const QPaintEngineState &state) override;

    void drawRects(const QRect *rects, int rectCount) override;
    void drawRects(const QRectF *rects, int rectCount) override;

    void drawLines(const QLine *lines, int lineCount) override;
    void drawLines(const QLineF *lines, int lineCount) override;

    void drawEllipse(const QRectF &r) override;
    void drawEllipse(const QRect &r) override;

    void drawPath(const QPainterPath &path) override;

    void drawPoints(const QPointF *points, int pointCount) override;
    void drawPoints(const QPoint *points, int pointCount) override;

    void drawPolygon(const QPointF *points, int pointCount, PolygonDrawMode mode) override;
    void drawPolygon(const QPoint *points, int pointCount, PolygonDrawMode mode) override;

    void drawPixmap(const QRectF &r, const QPixmap &pm, const QRectF &sr) override;
    void drawTextItem(const QPointF &p, const QTextItem &textItem) override;
    void drawTiledPixmap(const QRectF &r, const QPixmap &pixmap, const QPointF &s) override;
    void drawImage(const QRectF &r, const QImage &pm, const QRectF &sr,
                           Qt::ImageConversionFlags flags = Qt::AutoColor) override;

    QPoint coordinateOffset() const override;

    inline Type type() const override { PRITI; return QPaintEngine::Picture; }


    /* and end here */

private:


};


QT_END_NAMESPACE

#endif 
