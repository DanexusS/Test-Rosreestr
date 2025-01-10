#include "decimallineedit.h"

#include <QDoubleValidator>

DecimalLineEdit::DecimalLineEdit(QWidget *parent) : QLineEdit(parent) {
    this->setText("1");

    QDoubleValidator* validator = new QDoubleValidator(this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    validator->setRange(0, 100000.0);

    this->setValidator(validator);
}
