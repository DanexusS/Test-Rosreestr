#include "unusualdesignvessel.h"

#include <QtLogging>

bool UnusualDesignVessel::isConstructionMeetingCriteria() {
    if (!AbstractVessel::isConstructionMeetingCriteria())
        return false;

    // TODO: Необходимо реализовать прямой расчет прочности по согласованной методике.
    qWarning("Необходимо реализовать прямой расчет прочности по согласованной методике.");

    return this->checkSpeed();
}

UnusualDesignVessel::UnusualDesignVessel() : AbstractVessel() {}

UnusualDesignVessel::UnusualDesignVessel(
    float length, float width, float height,
    float overallCompletenessCoefficient, float specificationSpeed,
    VesselSwimmingAreaType swimmingAreaType
) :
    AbstractVessel(
        length, width, height,
        overallCompletenessCoefficient, specificationSpeed,
        VesselType::UnusualDesignVesselType, swimmingAreaType
    )
{}
