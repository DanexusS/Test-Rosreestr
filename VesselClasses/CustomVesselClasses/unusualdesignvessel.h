#ifndef UNUSUALDESIGNVESSEL_H
#define UNUSUALDESIGNVESSEL_H

#include "../abstractvessel.h"

class UnusualDesignVessel : public AbstractVessel
{

private:
    bool isMeetingCriteria() override { return AbstractVessel::isMeetingCriteria(); }
    bool isConstructionMeetingCriteria() override;

public:
    UnusualDesignVessel();
    UnusualDesignVessel(
        float length, float width, float height,
        float overallCompletenessCoefficient, float specificationSpeed,
        VesselSwimmingAreaType swimmingAreaType
    );

};

#endif // UNUSUALDESIGNVESSEL_H
