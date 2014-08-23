#ifndef LIGHTNINGDESIGNER_H
#define LIGHTNINGDESIGNER_H

#include <QMainWindow>
#include <QList>
#include <QPushButton>
#include <QColorDialog>
#include <QColor>

namespace Ui {
class LightningDesigner;
}

class LightningDesigner : public QMainWindow
{
    Q_OBJECT

public:
    explicit LightningDesigner(QWidget *parent = 0);
    ~LightningDesigner();

    typedef struct
    {
        QPushButton* button;
        quint8 RED;
        quint8 GREEN;
        quint8 BLUE;
    } LED_t;
    typedef QList<LED_t *> FRAME_t;
    typedef QList<FRAME_t *> PATTERN_t;

public slots:
    void changeColor();

private:
    QString makeStylesheet(quint8 RED, quint8 GREEN, quint8 BLUE);
    LED_t *addLED(QLayout *layout,quint8 RED=0, quint8 GREEN=0, quint8 BLUE=0);

    Ui::LightningDesigner *ui;
    PATTERN_t *m_Pattern;
};

#endif // LIGHTNINGDESIGNER_H
