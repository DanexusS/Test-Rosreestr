#ifndef REGULARVESSEL_H
#define REGULARVESSEL_H

#include "../abstractvessel.h"

class RegularVessel : public AbstractVessel
{

private:
    bool isMeetingCriteria() override { return AbstractVessel::isMeetingCriteria(); }
    bool isConstructionMeetingCriteria() override { return AbstractVessel::isConstructionMeetingCriteria() && checkSpeed(); }

public:
    RegularVessel();
    RegularVessel(
        float length, float width, float height,
        float overallCompletenessCoefficient, float specificationSpeed,
        VesselSwimmingAreaType swimmingAreaType
    );

};

#endif // REGULARVESSEL_H
