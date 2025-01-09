#include "technicalfleetvessel.h"

#include <cmath>

#include <QtLogging>

bool TechnicalFleetVessel::isMeetingCriteria() {
    if (!AbstractVessel::isMeetingCriteria())
        return false;

    // TODO: Необходимо реализовать логику проверки соответствия пунктам 3.1 и 3.6 из Правил.
    qWarning("Необходимо реализовать логику проверки соответствия пунктам 3.1 и 3.6 из Правил.");

    return true;
}

bool TechnicalFleetVessel::isConstructionMeetingCriteria() {
    if (!AbstractVessel::isConstructionMeetingCriteria()) return false;

    float v = this->getKCoefficient() * std::sqrt(this->m_length);
    return this->m_specificationSpeed > v;
}

TechnicalFleetVessel::TechnicalFleetVessel() : AbstractVessel() {}

TechnicalFleetVessel::TechnicalFleetVessel(
    float length, float width, float height,
    float overallCompletenessCoefficient, float specificationSpeed,
    VesselSwimmingAreaType swimmingAreaType
) :
    AbstractVessel(
        length, width, height,
        overallCompletenessCoefficient, specificationSpeed,
        VesselType::TechnicalFleet, swimmingAreaType
    )
{}
