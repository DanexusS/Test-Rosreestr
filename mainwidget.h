#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include "resultlabel.h"
#include "vesselformlayout.h"

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    ResultLabel* checkResult;
    VesselFormLayout* vesselFormLayout;

private slots:
    void validateVesselData();

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

};
#endif // MAINWIDGET_H
