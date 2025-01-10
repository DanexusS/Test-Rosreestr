#include "opendeckvessel.h"

#include <QtLogging>

bool OpenDeckVessel::isMeetingCriteria() {
    // TODO: Необходимо реализовать логику проверки соответствия пунктам 3.1 и 3.6 из Правил.
    qWarning("Необходимо реализовать логику проверки соответствия пунктам 3.1 и 3.6 из Правил.");

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

    if (!this->m_isTransferingCargoInHighTemperature)
        return this->checkSpeed();

    // TODO: Необходимо реализовать прямой расчет прочности по согласованной методике.
    qWarning("Необходимо реализовать прямой расчет прочности по согласованной методике.");

    return true;
}

OpenDeckVessel::OpenDeckVessel() : AbstractVessel() {}

OpenDeckVessel::OpenDeckVessel(
    float length, float width, float height,
    float overallCompletenessCoefficient, float specificationSpeed,
    bool isTransferingCargoInHighTemperature,
    VesselSwimmingAreaType swimmingAreaType
) :
    AbstractVessel(
        length, width, height,
        overallCompletenessCoefficient, specificationSpeed,
        VesselType::OpenDeckVesselType, swimmingAreaType
    ),
    m_isTransferingCargoInHighTemperature(isTransferingCargoInHighTemperature)
{}
