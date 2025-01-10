#include "unusualpurposevessel.h"

#include <QtLogging>

bool UnusualPurposeVessel::isConstructionMeetingCriteria() {
    if (!AbstractVessel::isConstructionMeetingCriteria())
        return false;

    // TODO: Необходимо реализовать прямой расчет прочности по согласованной методике.
    qWarning("Необходимо реализовать прямой расчет прочности по согласованной методике.");

    return this->checkSpeed();
}

UnusualPurposeVessel::UnusualPurposeVessel() {}

UnusualPurposeVessel::UnusualPurposeVessel(
    float length, float width, float height,
    float overallCompletenessCoefficient, float specificationSpeed,
    VesselSwimmingAreaType swimmingAreaType
) :
    AbstractVessel(
        length, width, height,
        overallCompletenessCoefficient, specificationSpeed,
        VesselType::UnusualPurposeVesselType, swimmingAreaType
    )
{}
