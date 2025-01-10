#include "mainwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <QFont>

#include "VesselClasses/abstractvessel.h"

void MainWidget::validateVesselData() {
    qInfo();

    AbstractVessel* currentVessel = this->vesselFormLayout->getVesselData();
    bool result = currentVessel->isMeetingMainLongitudinalStrengthRequirements();

    this->checkResult->setCriteriaInfo(result);
}

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    QStringList vesselTypes = {
        "Технический флот",
        "Судно с широким раскрытием палубы",
        "Судно необычной конструкции",
        "Судно необычного назначения",
        "Обычное судно"
    };
    QStringList vesselSwimmingAreaTypes = {
        "Неограниченный",
        "R1",
        "R2",
        "R2_RSN",
        "R2_RSN_4",
        "R2_RSN_5",
        "R3_RSN",
        "R3"
    };

    QLabel* title = new QLabel("Проверка соответствия требованиям продольной прочности суден");
    QFont font = title->font();
    font.setPixelSize(15);
    title->setFont(font);
    title->setAlignment(Qt::AlignCenter);

    this->checkResult = new ResultLabel("Результат проверки на соответствие требованиям.");

    this->vesselFormLayout = new VesselFormLayout(vesselTypes, vesselSwimmingAreaTypes);
    connect(this->vesselFormLayout, &VesselFormLayout::dataChanged, this->checkResult, &this->checkResult->setDefault);

    QPushButton* checkButton = new QPushButton("Проверить судно", parent);
    connect(checkButton, &QPushButton::clicked, this, &MainWidget::validateVesselData);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->setSpacing(25);

    main_layout->addWidget(title);
    main_layout->addLayout(this->vesselFormLayout);
    main_layout->addWidget(checkButton);
    main_layout->addWidget(this->checkResult);
}

MainWidget::~MainWidget() {}
