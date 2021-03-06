#ifndef PANEL_H
#define PANEL_H

#include <QObject>
#include "../../Qtraspberrylib/display7seg.h"
#include "../../Qtraspberrylib/mcp23017.h"
#include "../../Qtraspberrylib/rotaryencoder.h"
#include "../../Qtraspberrylib/pbutton.h"
#include"../../Qtraspberrylib/qttelnet.h"


class Panel : public QObject
{
    Q_OBJECT
public:
    explicit Panel(QObject *parent = 0);

    void setDispBrightness(quint8 br);
    void setup_hardware();
    void export_pins();

    //These functions are called by subclasses

    virtual void encoder1(quint8 direction);
    virtual void encoder2(quint8 direction);
    virtual void encoder3(quint8 direction);
    virtual void encoder4(quint8 direction);
    virtual void encoder5(quint8 direction);
    virtual void encoder6(quint8 direction);

    virtual void button1(quint8 direction);
    virtual void button2(quint8 direction);
    virtual void button3(quint8 direction);
    virtual void button4(quint8 direction);
    virtual void button5(quint8 direction);
    virtual void button6(quint8 direction);
    virtual void button7(quint8 direction);
    virtual void button8(quint8 direction);

    virtual void button9(quint8 direction);
    virtual void button10(quint8 direction);

    virtual void button11(quint8 direction);
    virtual void button12(quint8 direction);
    virtual void button13(quint8 direction);
    virtual void button14(quint8 direction);

    virtual void button15(quint8 direction);

signals:
    void telMes(QString msg);
    
public slots:
    void telnetMessage(const QString &msg);
    void telnetConnectionError(QAbstractSocket::SocketError);

    //Interrupt handlers
    void ext1_intA(quint8 value);
    void ext1_intB(quint8 value);

    void ext2_intA(quint8 value);
    void ext2_intB(quint8 value);
    void ext3_intB(quint8 value);

    //These functions are executed when interrupts are produced
    void enc1_changed(quint8 direction);
    void enc2_changed(quint8 direction);
    void enc3_changed(quint8 direction);
    void enc4_changed(quint8 direction);
    void enc5_changed(quint8 direction);
    void enc6_changed(quint8 direction);

    void but1_changed(quint8 direction);
    void but2_changed(quint8 direction);
    void but3_changed(quint8 direction);
    void but4_changed(quint8 direction);
    void but5_changed(quint8 direction);
    void but6_changed(quint8 direction);
    void but7_changed(quint8 direction);
    void but8_changed(quint8 direction);

    void but9_changed(quint8 direction);
    void but10_changed(quint8 direction);

    void but11_changed(quint8 direction);
    void but12_changed(quint8 direction);
    void but13_changed(quint8 direction);
    void but14_changed(quint8 direction);

    void but15_changed(quint8 direction);

protected:
    Display7seg disp1;
    Display7seg disp2;
    Display7seg disp3;
    Display7seg disp4;
    quint8 brightness;

    Mcp23017 ext1;
    Mcp23017 ext2;
    Mcp23017 ext3;

    //quint8 porta1_value;
    //quint8 portb1_value;

    RotaryEncoder enc1;
    RotaryEncoder enc2;
    RotaryEncoder enc3;
    RotaryEncoder enc4;
    RotaryEncoder enc5;
    RotaryEncoder enc6;

    Pbutton but1;
    Pbutton but2;
    Pbutton but3;
    Pbutton but4;
    Pbutton but5;
    Pbutton but6;
    Pbutton but7;
    Pbutton but8;
    Pbutton but9;
    Pbutton but10;
    Pbutton but11;
    Pbutton but12;
    Pbutton but13;
    Pbutton but14;
    Pbutton but15;


public:
    QtTelnet* comm;
};

#endif // PANEL_H
