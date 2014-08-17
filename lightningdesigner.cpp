#include "lightningdesigner.h"
#include "ui_lightningdesigner.h"

LightningDesigner::LightningDesigner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LightningDesigner)
{
    ui->setupUi(this);
}

LightningDesigner::~LightningDesigner()
{
    delete ui;
}
