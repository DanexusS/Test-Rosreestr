#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include "vesselformlayout.h"

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    VesselFormLayout* vesselFormLayout;

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

};
#endif // MAINWIDGET_H
