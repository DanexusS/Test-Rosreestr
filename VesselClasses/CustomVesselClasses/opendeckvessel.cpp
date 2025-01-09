#include "opendeckvessel.h"

#include <cmath>

#include <QtLogging>

bool OpenDeckVessel::isMeetingCriteria() {
    if (this->m_swimmingAreaType == VesselSwimmingAreaType::Unrestricted && this->m_length >= 90)
    {
        // TODO: Необходимо реализовать проверку соответствия требованиям части XVIII "Дополнительные требования к контейнеровозам и судам, перевозящим грузы преимущественно в контейнерах."
        qWarning(
            "Необходимо реализовать проверку соответствия требованиям части XVIII "
            "\"Дополнительные требования к контейнеровозам и судам, перевозящим грузы преимущественно в контейнерах.\""
        );

        return true;
    }

    return AbstractVessel::isMeetingCriteria();
}

bool OpenDeckVessel::isConstructionMeetingCriteria() {
    if (!AbstractVessel::isConstructionMeetingCriteria())
        return false;

    if (!this->m_isTransferingCargoInHighTemperature) {
        float v = this->getKCoefficient() * std::sqrt(this->m_length);
        return this->m_specificationSpeed > v;
    }

    // TODO: Необходимо реализовать прямой расчет прочности по согласованной методике.
    qWarning("Необходимо реализовать прямой расчет прочности по согласованной методике.");

    return true;
}

OpenDeckVessel::OpenDeckVessel() {}

OpenDeckVessel::OpenDeckVessel(
    float length, float width, float height,
    float overallCompletenessCoefficient, float specificationSpeed,
    bool isTransferingCargoInHighTemperature,
    VesselSwimmingAreaType swimmingAreaType
) :
    AbstractVessel(
        length, width, height,
        overallCompletenessCoefficient, specificationSpeed,
        VesselType::OpenDeckVessel, swimmingAreaType
    ),
    m_isTransferingCargoInHighTemperature(isTransferingCargoInHighTemperature)
{}
