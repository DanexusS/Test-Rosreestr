#include "abstractvessel.h"

#include <stdexcept>

#include <QtLogging>

bool AbstractVessel::isMeetingCriteria() {
    switch (this->m_swimmingAreaType) {

    case Unrestricted:
        return true;
    case R1:
        return this->m_length >= 65;
    case R2:
    case R2_RSN:
    case R2_RSN_4:
    case R2_RSN_5:
    case R3_RSN:
    case R3:
        return this->m_length >= 60;

    }

    return false;
}

bool AbstractVessel::isConstructionMeetingCriteria() {
    bool first_ration_criteria = this->m_length / this->m_width <= 5;
    bool second_ration_criteria = false;

    if (!first_ration_criteria) return false;

    switch (this->m_swimmingAreaType) {

    case Unrestricted:
    case R1:
        second_ration_criteria = this->m_width / this->m_height >= 2.5;
        break;
    case R2:
    case R2_RSN:
    case R2_RSN_4:
    case R2_RSN_5:
    case R3_RSN:
    case R3:
        second_ration_criteria = this->m_width / this->m_height >= 4;
        break;

    }

    if (!second_ration_criteria) return false;
    if (this->m_overallCompletenessCoefficient >= 0.6) return false;

    return true;
}

AbstractVessel::AbstractVessel() {}

AbstractVessel::AbstractVessel(
    float length, float width, float height,
    float overallCompletenessCoefficient, float specificationSpeed,
    VesselType type, VesselSwimmingAreaType swimmingAreaType
) :
    m_type(type),
    m_swimmingAreaType(swimmingAreaType)
{
    if (length < 0 || width < 0 || height < 0)
        throw std::invalid_argument("Измерения корабля не должны быть отрицательными.");
    if (specificationSpeed < 0)
        throw std::invalid_argument("Cпецификационная скорость не должна быть отрицательной.");

    this->m_length = length;
    this->m_width = width;
    this->m_height = height;
    this->m_overallCompletenessCoefficient = overallCompletenessCoefficient;
    this->m_specificationSpeed = specificationSpeed;
}

bool AbstractVessel::isMeetingMainLongitudinalStrengthRequirements() {
    if (!this->isMeetingCriteria()) {
        qInfo("На судно не распространяется требования главы 1.4 из Правил.");
        return false;
    }

    if (!this->isConstructionMeetingCriteria()) {
        qInfo("Конструкция не соответствует описанным в Правилам критериям.");
        return false;
    }

    return true;
}
