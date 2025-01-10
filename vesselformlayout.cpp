#include "vesselformlayout.h"

#include <QDoubleValidator>

#include <QtLogging>

#include "VesselClasses/CustomVesselClasses/regularvessel.h"
#include "VesselClasses/CustomVesselClasses/opendeckvessel.h"
#include "VesselClasses/CustomVesselClasses/unusualdesignvessel.h"
#include "VesselClasses/CustomVesselClasses/technicalfleetvessel.h"
#include "VesselClasses/CustomVesselClasses/unusualpurposevessel.h"

VesselFormLayout::VesselFormLayout(
    QStringList vesselTypes,
    QStringList vesselSwimmingAreaTypes,
    QWidget* parent
) : QFormLayout(parent)
{
    this->setSpacing(5);

    this->m_lengthInput = new DecimalLineEdit(parent);
    this->addRow("Введите длину (L):", this->m_lengthInput);
    connect(this->m_lengthInput, &QLineEdit::textChanged, this, [this](){ emit this->dataChanged(); });

    this->m_widthInput = new DecimalLineEdit(parent);
    this->addRow("Введите ширину (B):", this->m_widthInput);
    connect(this->m_widthInput, &QLineEdit::textChanged, this, [this](){ emit this->dataChanged(); });

    this->m_heightInput = new DecimalLineEdit(parent);
    this->addRow("Введите высоту (D):", this->m_heightInput);
    connect(this->m_heightInput, &QLineEdit::textChanged, this, [this](){ emit this->dataChanged(); });

    this->m_overallCompletenessCoefficientInput = new DecimalLineEdit(parent);
    this->addRow("Введите коэффициент общей полноты (C_b):", this->m_overallCompletenessCoefficientInput);
    connect(this->m_overallCompletenessCoefficientInput, &QLineEdit::textChanged, this, [this](){ emit this->dataChanged(); });

    this->m_specificationSpeedInput = new DecimalLineEdit(parent);
    this->addRow("Введите спецификационную скорость (v_0):", this->m_specificationSpeedInput);
    connect(this->m_specificationSpeedInput, &QLineEdit::textChanged, this, [this](){ emit this->dataChanged(); });

    this->m_typeSelection = new QComboBox(parent);
    this->m_typeSelection->addItems(vesselTypes);
    this->addRow("Выберите тип судна:", this->m_typeSelection);
    connect(this->m_typeSelection, &QComboBox::currentIndexChanged, this, &VesselFormLayout::showExtraRowWhenNecessary);
    connect(this->m_typeSelection, &QComboBox::currentIndexChanged, this, [this](){ emit this->dataChanged(); });

    this->m_isTransferingCargoInHighTemperature = new QCheckBox("Перевозит ли грузы при высокой температуре:", parent);
    this->addRow(this->m_isTransferingCargoInHighTemperature);
    connect(this->m_isTransferingCargoInHighTemperature, &QCheckBox::clicked, this, [this](){ emit this->dataChanged(); });
    this->setRowVisible(6, false);

    this->m_swimmingAreaTypeSelection = new QComboBox(parent);
    this->m_swimmingAreaTypeSelection->addItems(vesselSwimmingAreaTypes);
    this->addRow("Выберите район плавания:", this->m_swimmingAreaTypeSelection);
    connect(this->m_swimmingAreaTypeSelection, &QComboBox::currentIndexChanged, this, [this](){ emit this->dataChanged(); });
}

AbstractVessel* VesselFormLayout::getVesselData() {
    float length = this->m_lengthInput->text().toFloat();
    float width = this->m_widthInput->text().toFloat();
    float height = this->m_heightInput->text().toFloat();
    float overallCompletenessCoefficient = this->m_overallCompletenessCoefficientInput->text().toFloat();
    float specificationSpeed = this->m_specificationSpeedInput->text().toFloat();

    VesselType vesselType = static_cast<VesselType>(
        this->m_typeSelection->currentIndex()
    );

    VesselSwimmingAreaType vesselSwimmingAreaType = static_cast<VesselSwimmingAreaType>(
        this->m_swimmingAreaTypeSelection->currentIndex()
    );

    AbstractVessel* returnVesselData = nullptr;

    switch (vesselType) {

    case TechnicalFleetType:
        returnVesselData = new TechnicalFleetVessel(
            length, width, height,
            overallCompletenessCoefficient, specificationSpeed, vesselSwimmingAreaType
        );
        break;
    case OpenDeckVesselType:
        returnVesselData = new OpenDeckVessel(
            length, width, height,
            overallCompletenessCoefficient, specificationSpeed,
            this->m_isTransferingCargoInHighTemperature->isChecked(), vesselSwimmingAreaType
            );
        break;
    case UnusualDesignVesselType:
        returnVesselData = new UnusualDesignVessel(
            length, width, height,
            overallCompletenessCoefficient, specificationSpeed, vesselSwimmingAreaType
        );
        break;
    case UnusualPurposeVesselType:
        returnVesselData = new UnusualPurposeVessel(
            length, width, height,
            overallCompletenessCoefficient, specificationSpeed, vesselSwimmingAreaType
        );
        break;
    case RegularVesselType:
        returnVesselData = new RegularVessel(
            length, width, height,
            overallCompletenessCoefficient, specificationSpeed, vesselSwimmingAreaType
        );
        break;

    }

    if (returnVesselData == nullptr) {
        qFatal() << "Выбранный пользователем тип судна не обрабатывается программой.";
        return nullptr;
    }

    return returnVesselData;
}
