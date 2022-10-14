#ifndef QPAINTDEVICE_MINIMAL_H
#define QPAINTDEVICE_MINIMAL_H

#include "QtGui/qpaintdevice.h"
#include "qminimalpaintengine.h"

class QMinimalPaintEngine;

class Q_GUI_EXPORT QMinimalPaintDevice : public QPaintDevice
{
    Q_GADGET
public:
    QMinimalPaintDevice();
    ~QMinimalPaintDevice();

    QPaintEngine *paintEngine() const override;
    
private:
    // QMinimalPaintEngine m_engine;
    QMinimalPaintEngine *m_engine;
};

#endif