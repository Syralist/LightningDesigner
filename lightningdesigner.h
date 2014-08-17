#ifndef LIGHTNINGDESIGNER_H
#define LIGHTNINGDESIGNER_H

#include <QMainWindow>

namespace Ui {
class LightningDesigner;
}

class LightningDesigner : public QMainWindow
{
    Q_OBJECT

public:
    explicit LightningDesigner(QWidget *parent = 0);
    ~LightningDesigner();

private:
    Ui::LightningDesigner *ui;
};

#endif // LIGHTNINGDESIGNER_H
