#ifndef UNUSUALPURPOSEVESSEL_H
#define UNUSUALPURPOSEVESSEL_H

#include "../abstractvessel.h"

class UnusualPurposeVessel : public AbstractVessel
{

private:
    bool isMeetingCriteria() override { return AbstractVessel::isMeetingCriteria(); }
    bool isConstructionMeetingCriteria() override;

public:
    UnusualPurposeVessel();
    UnusualPurposeVessel(
        float length, float width, float height,
        float overallCompletenessCoefficient, float specificationSpeed,
        VesselSwimmingAreaType swimmingAreaType
    );

};

#endif // UNUSUALPURPOSEVESSEL_H
