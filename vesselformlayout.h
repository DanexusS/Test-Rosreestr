#ifndef VESSELFORMLAYOUT_H
#define VESSELFORMLAYOUT_H

#include <QWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QFormLayout>

#include <QStringList>

#include "decimallineedit.h"
#include "VesselClasses/abstractvessel.h"

class VesselFormLayout : public QFormLayout
{
    Q_OBJECT

private:
    DecimalLineEdit* m_lengthInput;
    DecimalLineEdit* m_widthInput;
    DecimalLineEdit* m_heightInput;
    DecimalLineEdit* m_overallCompletenessCoefficientInput;
    DecimalLineEdit* m_specificationSpeedInput;

    QComboBox* m_typeSelection;
    QCheckBox* m_isTransferingCargoInHighTemperature;
    QComboBox* m_swimmingAreaTypeSelection;

private slots:
    void showExtraRowWhenNecessary(int new_index) { setRowVisible(6, new_index == 1); }

public:
    VesselFormLayout(QStringList vesselTypes, QStringList vesselSwimmingAreaTypes, QWidget* parent = nullptr);

public:
    AbstractVessel* getVesselData();

signals:
    void dataChanged();

};

#endif // VESSELFORMLAYOUT_H
