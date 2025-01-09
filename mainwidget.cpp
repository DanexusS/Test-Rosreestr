#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    this->vesselFormLayout = new VesselFormLayout(this);
    this->setLayout(this->vesselFormLayout);
}

MainWidget::~MainWidget() {}
