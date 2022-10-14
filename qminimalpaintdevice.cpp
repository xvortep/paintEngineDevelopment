#include "qminimalpaintdevice.h"

QMinimalPaintDevice::QMinimalPaintDevice()
    : QPaintDevice()
{
    m_engine = new QMinimalPaintEngine();
}

QMinimalPaintDevice::~QMinimalPaintDevice()
{
    delete m_engine;
}

QPaintEngine *QMinimalPaintDevice::paintEngine() const
{
    return m_engine;
}

// int QMinimalPaintDevice::devType() const
// {
//     return QInternal::Image; // hack?
// }
