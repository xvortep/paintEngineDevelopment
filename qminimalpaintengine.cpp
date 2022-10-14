#include "qminimalpaintengine.h"

#include <iostream>

QMinimalPaintEngine::QMinimalPaintEngine()
{

}

QMinimalPaintEngine::~QMinimalPaintEngine()
{

}

bool QMinimalPaintEngine::begin(QPaintDevice *pdev)
{
    Q_UNUSED(pdev);
    PRITI;
    return true; // hack
}

bool QMinimalPaintEngine::end()
{
    PRITI;
    return true; // hack
}

void QMinimalPaintEngine::updateState(const QPaintEngineState &state)
{
    Q_UNUSED(state);
    PRITI;
}

void QMinimalPaintEngine::drawRects(const QRect *rects, int rectCount)
{
    Q_UNUSED(rects);
    Q_UNUSED(rectCount);
    PRITI;
}

void QMinimalPaintEngine::drawRects(const QRectF *rects, int rectCount)
{
    Q_UNUSED(rects);
    Q_UNUSED(rectCount);
    PRITI;
}

void QMinimalPaintEngine::drawLines(const QLine *lines, int lineCount)
{
    Q_UNUSED(lines);
    Q_UNUSED(lineCount);
    PRITI;
}

void QMinimalPaintEngine::drawLines(const QLineF *lines, int lineCount)
{
    Q_UNUSED(lines);
    Q_UNUSED(lineCount);
    PRITI;
}

void QMinimalPaintEngine::drawEllipse(const QRectF &r)
{
    Q_UNUSED(r);
    PRITI;
}

void QMinimalPaintEngine::drawEllipse(const QRect &r)
{
    Q_UNUSED(r);
    PRITI;
}

void QMinimalPaintEngine::drawPath(const QPainterPath &path)
{
    Q_UNUSED(path);
    PRITI;
}

void QMinimalPaintEngine::drawPoints(const QPointF *points, int pointCount)
{
    Q_UNUSED(points);
    Q_UNUSED(pointCount);
    PRITI;
}
void QMinimalPaintEngine::drawPoints(const QPoint *points, int pointCount)
{
    Q_UNUSED(points);
    Q_UNUSED(pointCount);
    PRITI;
}

void QMinimalPaintEngine::drawPolygon(const QPointF *points, int pointCount, PolygonDrawMode mode)
{
    Q_UNUSED(points);
    Q_UNUSED(pointCount);
    Q_UNUSED(mode);
    PRITI;
}

void QMinimalPaintEngine::drawPolygon(const QPoint *points, int pointCount, PolygonDrawMode mode)
{
    Q_UNUSED(points);
    Q_UNUSED(pointCount);
    Q_UNUSED(mode);
    PRITI;
}

void QMinimalPaintEngine::drawPixmap(const QRectF &r, const QPixmap &pm, const QRectF &sr)
{
    Q_UNUSED(r);
    Q_UNUSED(pm);
    Q_UNUSED(sr);
    PRITI;
}

void QMinimalPaintEngine::drawTextItem(const QPointF &p, const QTextItem &textItem)
{
    Q_UNUSED(p);
    Q_UNUSED(textItem);
    PRITI;
}

void QMinimalPaintEngine::drawTiledPixmap(const QRectF &r, const QPixmap &pixmap, const QPointF &s)
{
    Q_UNUSED(r);
    Q_UNUSED(pixmap);
    Q_UNUSED(s);
    PRITI;
}

void QMinimalPaintEngine::drawImage(const QRectF &r, const QImage &pm, const QRectF &sr,
                        Qt::ImageConversionFlags flags) // flags = Qt::AutoColor // hack
{
    Q_UNUSED(r);
    Q_UNUSED(pm);
    Q_UNUSED(sr);
    Q_UNUSED(flags);
    PRITI;
}

QPoint QMinimalPaintEngine::coordinateOffset() const
{
    PRITI;
    return QPoint();
}
