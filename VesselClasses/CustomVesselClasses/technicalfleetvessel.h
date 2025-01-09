#ifndef TECHNICALFLEETVESSEL_H
#define TECHNICALFLEETVESSEL_H

#include "../abstractvessel.h"

class TechnicalFleetVessel : public AbstractVessel
{

private:
    bool isMeetingCriteria() override;
    bool isConstructionMeetingCriteria() override;

public:
    TechnicalFleetVessel();
    TechnicalFleetVessel(
        float length, float width, float height,
        float overallCompletenessCoefficient, float specificationSpeed,
        VesselSwimmingAreaType swimmingAreaType
    );

};

#endif // TECHNICALFLEETVESSEL_H
