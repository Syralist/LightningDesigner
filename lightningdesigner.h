#ifndef LIGHTNINGDESIGNER_H
#define LIGHTNINGDESIGNER_H

#include <QMainWindow>
#include <QList>
#include <QPushButton>

namespace Ui {
class LightningDesigner;
}

class LightningDesigner : public QMainWindow
{
    Q_OBJECT

public:
    explicit LightningDesigner(QWidget *parent = 0);
    ~LightningDesigner();

    struct LED
    {
        QPushButton* button;
        quint8 RED;
        quint8 GREEN;
        quint8 BLUE;
    };
    typedef QList<LED> STATE;
    typedef QList<STATE> PATTERN;

private:
    Ui::LightningDesigner *ui;

    PATTERN m_Pattern;
};

#endif // LIGHTNINGDESIGNER_H
