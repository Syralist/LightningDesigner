#include "lightningdesigner.h"
#include "ui_lightningdesigner.h"

LightningDesigner::LightningDesigner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LightningDesigner)
{
    ui->setupUi(this);

    m_Pattern = new PATTERN_t;
    FRAME_t *frame = new FRAME_t;
    for(int i=0;i<6;i++)
    {
        frame->append(addLED(ui->frameLayout,127,0,0));
        connect(frame->last()->button,SIGNAL(clicked()),this,SLOT(changeColor()));
    }
    m_Pattern->append(frame);
}

LightningDesigner::~LightningDesigner()
{
    delete ui;
}

void LightningDesigner::changeColor()
{
    if(!QObject::sender())
    {
        return;
    }
    else
    {
        QColor newColor = QColorDialog::getColor();
        ((QPushButton*)QObject::sender())->setStyleSheet(makeStylesheet(newColor.red(),newColor.green(),newColor.blue()));
    }
}

QString LightningDesigner::makeStylesheet(quint8 RED, quint8 GREEN, quint8 BLUE)
{
    QString styleSheet = "background-color: rgb(RED, GREEN, BLUE);";
    styleSheet.replace("RED",QString::number(RED));
    styleSheet.replace("GREEN",QString::number(GREEN));
    styleSheet.replace("BLUE",QString::number(BLUE));
    return styleSheet;
}

LightningDesigner::LED_t *LightningDesigner::addLED(QLayout *layout, quint8 RED, quint8 GREEN, quint8 BLUE)
{
    LED_t *led = new LED_t;
    led->RED = RED;
    led->GREEN = GREEN;
    led->BLUE = BLUE;
    led->button = new QPushButton();
    led->button->setStyleSheet(makeStylesheet(led->RED,led->GREEN,led->BLUE));
    led->button->setMinimumSize(16,16);
    led->button->setMaximumSize(16,16);
    layout->addWidget(led->button);
    return led;
}
