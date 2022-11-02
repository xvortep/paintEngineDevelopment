#include "qminimalpaintengine.h"

/* #include <iostream> */

QMinimalPaintEngine::QMinimalPaintEngine(){}


QMinimalPaintEngine::~QMinimalPaintEngine(){}

/*
 *	Init when paint device(pdev) needs something drawn. Return success.
 */
bool QMinimalPaintEngine::begin(QPaintDevice *pdev)
{
    Q_UNUSED(pdev);
    /* PRITI; */
    return true; // Hack.
}

/*
 *	Finish painting. Return success.
 */
bool QMinimalPaintEngine::end()
{
    /* PRITI; */
    return true; // Hack.
}

/*
 *	Unnecessary????????????????????????????
 */
void QMinimalPaintEngine::updateState(const QPaintEngineState &state)
{
    Q_UNUSED(state);
    /* PRITI; */
}

void QMinimalPaintEngine::drawRects(const QRect *rects, int rectCount)
{
    /* PRITI; */

    struct RectF {
        qreal x;
        qreal y;
        qreal w;
        qreal h;
    };
    Q_ASSERT(sizeof(RectF) == sizeof(QRectF));
    RectF fr[256];
    while (rectCount) {
        int i = 0;
        while (i < rectCount && i < 256) {
            fr[i].x = rects[i].x();
            fr[i].y = rects[i].y();
            fr[i].w = rects[i].width();
            fr[i].h = rects[i].height();
            ++i;
        }
        drawRects((QRectF *)(void *)fr, i);
        rects += i;
        rectCount -= i;
    }
}

void QMinimalPaintEngine::drawRects(const QRectF *rects, int rectCount)
{
    /* PRITI; */

	if (hasFeature(PainterPaths) &&
		!state->penNeedsResolving() &&
		!state->brushNeedsResolving()) {
		for (int i=0; i<rectCount; ++i) {
			QPainterPath path;
			path.addRect(rects[i]);
			if (path.isEmpty())
				continue;
			drawPath(path);
		}
		} else {
		for (int i=0; i<rectCount; ++i) {
			QRectF rf = rects[i];
			QPointF pts[4] = { QPointF(rf.x(), rf.y()),
							   QPointF(rf.x() + rf.width(), rf.y()),
							   QPointF(rf.x() + rf.width(), rf.y() + rf.height()),
							   QPointF(rf.x(), rf.y() + rf.height()) };
			drawPolygon(pts, 4, ConvexMode);
		}
	}
}

void QMinimalPaintEngine::drawLines(const QLine *lines, int lineCount)
{
    /* PRITI; */

    struct PointF {
        qreal x;
        qreal y;
    };
    struct LineF {
        PointF p1;
        PointF p2;
    };
    Q_ASSERT(sizeof(PointF) == sizeof(QPointF));
    Q_ASSERT(sizeof(LineF) == sizeof(QLineF));
    LineF fl[256];
    while (lineCount) {
        int i = 0;
        while (i < lineCount && i < 256) {
            fl[i].p1.x = lines[i].x1();
            fl[i].p1.y = lines[i].y1();
            fl[i].p2.x = lines[i].x2();
            fl[i].p2.y = lines[i].y2();
            ++i;
        }
        drawLines((QLineF *)(void *)fl, i);
        lines += i;
        lineCount -= i;
    }
}

void QMinimalPaintEngine::drawLines(const QLineF *lines, int lineCount)
{
    /* PRITI; */

    }    for (int i=0; i<lineCount; ++i) {
        QPointF pts[2] = { lines[i].p1(), lines[i].p2() };

        if (pts[0] == pts[1]) {
            if (state->pen().capStyle() != Qt::FlatCap)
                drawPoints(pts, 1);
            continue;
        }

        drawPolygon(pts, 2, PolylineMode);
    }
}

void QMinimalPaintEngine::drawEllipse(const QRect &r)
{
	/* PRITI; */

	drawEllipse(QRectF(rect));
}

void QMinimalPaintEngine::drawEllipse(const QRectF &r)
{
   /* PRITI; */

    QPainterPath path;
    path.addEllipse(rect);
    if (hasFeature(PainterPaths)) {
        drawPath(path);
    } else {
        QPolygonF polygon = path.toFillPolygon(QTransform());
        drawPolygon(polygon.data(), polygon.size(), ConvexMode);
    }
}

/*
 *	Unnecessary
 */
void QMinimalPaintEngine::drawPath(const QPainterPath &path)
{
    Q_UNUSED(path);
    /* PRITI; */
}

void QMinimalPaintEngine::drawPoints(const QPoint *points, int pointCount)
{
	/* PRITI; */

    Q_ASSERT(sizeof(QT_PointF) == sizeof(QPointF));
    QT_PointF fp[256];
    while (pointCount) {
        int i = 0;
        while (i < pointCount && i < 256) {
            fp[i].x = points[i].x();
            fp[i].y = points[i].y();
            ++i;
        }
        drawPoints((QPointF *)(void *)fp, i);
        points += i;
        pointCount -= i;
    }
}

void QMinimalPaintEngine::drawPoints(const QPointF *points, int pointCount)
{
    /* PRITI; */

    QPainter *p = painter();
    if (!p)
        return;

    qreal penWidth = p->pen().widthF();
    if (penWidth == 0)
        penWidth = 1;

    bool ellipses = p->pen().capStyle() == Qt::RoundCap;

    p->save();

    QTransform transform;
    if (qt_pen_is_cosmetic(p->pen(), p->renderHints())) {
        transform = p->transform();
        p->setTransform(QTransform());
    }

    p->setBrush(p->pen().brush());
    p->setPen(Qt::NoPen);

    for (int i=0; i<pointCount; ++i) {
        QPointF pos = transform.map(points[i]);
        QRectF rect(pos.x() - penWidth / 2, pos.y() - penWidth / 2, penWidth, penWidth);

        if (ellipses)
            p->drawEllipse(rect);
        else
            p->drawRect(rect);
    }

    p->restore();
}

void QMinimalPaintEngine::drawPolygon(const QPoint *points, int pointCount, PolygonDrawMode mode)
{
	/* PRITI; */

    Q_ASSERT_X(qt_polygon_recursion != this, "QPaintEngine::drawPolygon",
               "At least one drawPolygon function must be implemented");
    qt_polygon_recursion = this;
    Q_ASSERT(sizeof(QT_PointF) == sizeof(QPointF));
    QVarLengthArray<QT_PointF> p(pointCount);
    for (int i=0; i<pointCount; ++i) {
        p[i].x = points[i].x();
        p[i].y = points[i].y();
    }
    drawPolygon((QPointF *)p.data(), pointCount, mode);
    qt_polygon_recursion = nullptr;
}

void QMinimalPaintEngine::drawPolygon(const QPointF *points, int pointCount, PolygonDrawMode mode)
{
    /* PRITI; */

    Q_ASSERT_X(qt_polygon_recursion != this, "QPaintEngine::drawPolygon",
               "At least one drawPolygon function must be implemented");
    qt_polygon_recursion = this;
    Q_ASSERT(sizeof(QT_Point) == sizeof(QPoint));
    QVarLengthArray<QT_Point> p(pointCount);
    for (int i = 0; i < pointCount; ++i) {
        p[i].x = qRound(points[i].x());
        p[i].y = qRound(points[i].y());
    }
    drawPolygon((QPoint *)p.data(), pointCount, mode);
    qt_polygon_recursion = nullptr;
}

/*
 *	Fully virtual, must be reimplemented.
 */
void QMinimalPaintEngine::drawPixmap(const QRectF &r, const QPixmap &pm, const QRectF &sr)
{
    Q_UNUSED(r);
    Q_UNUSED(pm);
    Q_UNUSED(sr);
    /* PRITI; */
}

void QMinimalPaintEngine::drawTextItem(const QPointF &p, const QTextItem &textItem)
{
    /* PRITI; */

    const QTextItemInt &ti = static_cast<const QTextItemInt &>(textItem);
    if (ti.glyphs.numGlyphs == 0)
        return;

    if (ti.fontEngine->glyphFormat == QFontEngine::Format_ARGB) {
        QVarLengthArray<QFixedPoint> positions;
        QVarLengthArray<glyph_t> glyphs;
        QTransform matrix = QTransform::fromTranslate(p.x(), p.y() - ti.fontEngine->ascent().toReal());
        ti.fontEngine->getGlyphPositions(ti.glyphs, matrix, ti.flags, glyphs, positions);
        painter()->save();
        painter()->setRenderHint(QPainter::SmoothPixmapTransform,
                                 bool((painter()->renderHints() & QPainter::TextAntialiasing)
                                      && !(painter()->font().styleStrategy() & QFont::NoAntialias)));
        for (int i = 0; i < ti.glyphs.numGlyphs; ++i) {
            QImage glyph = ti.fontEngine->bitmapForGlyph(glyphs[i], QFixed(), QTransform());
            painter()->drawImage(positions[i].x.toReal(), positions[i].y.toReal(), glyph);
        }
        painter()->restore();
        return;
    }

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    ti.fontEngine->addOutlineToPath(0, 0, ti.glyphs, &path, ti.flags);
    if (!path.isEmpty()) {
        painter()->save();
        painter()->setRenderHint(QPainter::Antialiasing,
                                 bool((painter()->renderHints() & QPainter::TextAntialiasing)
                                      && !(painter()->font().styleStrategy() & QFont::NoAntialias)));
        painter()->translate(p.x(), p.y());
        painter()->fillPath(path, painter()->pen().brush());
        painter()->restore();
    }
}

void QMinimalPaintEngine::drawTiledPixmap(const QRectF &r, const QPixmap &pixmap, const QPointF &s)
{
	/* PRITI; */

    int sw = pixmap.width();
    int sh = pixmap.height();

    if (sw*sh < 8192 && sw*sh < 16*rect.width()*rect.height()) {
        int tw = sw, th = sh;
        while (tw*th < 32678 && tw < rect.width()/2)
            tw *= 2;
        while (tw*th < 32678 && th < rect.height()/2)
            th *= 2;
        QPixmap tile;
        if (pixmap.depth() == 1) {
            tile = QBitmap(tw, th);
        } else {
            tile = QPixmap(tw, th);
            if (pixmap.hasAlphaChannel())
                tile.fill(Qt::transparent);
        }
        qt_fill_tile(&tile, pixmap);
        qt_draw_tile(this, rect.x(), rect.y(), rect.width(), rect.height(), tile, p.x(), p.y());
    } else {
        qt_draw_tile(this, rect.x(), rect.y(), rect.width(), rect.height(), pixmap, p.x(), p.y());
    }
}

void QMinimalPaintEngine::drawImage(const QRectF &r, const QImage &pm, const QRectF &sr,
                        Qt::ImageConversionFlags flags) // flags = Qt::AutoColor // hack
{
    /* PRITI; */

    QRectF baseSize(0, 0, image.width(), image.height());
    QImage im = image;
    if (baseSize != sr)
        im = im.copy(qFloor(sr.x()), qFloor(sr.y()),
                     qCeil(sr.width()), qCeil(sr.height()));
    QPixmap pm = QPixmap::fromImage(im, flags);
    drawPixmap(r, pm, QRectF(QPointF(0, 0), pm.size()));
}

QPoint QMinimalPaintEngine::coordinateOffset() const
{
    /* PRITI; */

    return QPoint();
}
