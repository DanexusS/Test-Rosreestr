#include "vesselformlayout.h"

#include <QLineEdit>

#include <QDoubleValidator>

#include <QComboBox>
#include <QCheckBox>

#include "decimallineedit.h"

VesselFormLayout::VesselFormLayout(QWidget* parent) : QFormLayout(parent) {
    DecimalLineEdit* lengthInput = new DecimalLineEdit(parent);
    this->addRow("Введите длину:", lengthInput);

    DecimalLineEdit* widthInput = new DecimalLineEdit(parent);
    this->addRow("Введите ширину:", widthInput);

    DecimalLineEdit* heightInput = new DecimalLineEdit(parent);
    this->addRow("Введите длину:", heightInput);

    DecimalLineEdit* overallCompletenessCoefficient = new DecimalLineEdit(parent);
    this->addRow("Введите коэффициент общей полноты:", overallCompletenessCoefficient);

    DecimalLineEdit* specificationSpeedInput = new DecimalLineEdit(parent);
    this->addRow("Введите спецификационную скорость:", specificationSpeedInput);
}
