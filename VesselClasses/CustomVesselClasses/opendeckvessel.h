#ifndef OPENDECKVESSEL_H
#define OPENDECKVESSEL_H

#include "../abstractvessel.h"

class OpenDeckVessel : public AbstractVessel
{

private:
    bool m_isTransferingCargoInHighTemperature;

private:
    bool isMeetingCriteria() override;
    bool isConstructionMeetingCriteria() override;

public:
    OpenDeckVessel();
    OpenDeckVessel(
        float length, float width, float height,
        float overallCompletenessCoefficient, float specificationSpeed,
        bool isTransferingCargoInHighTemperature,
        VesselSwimmingAreaType swimmingAreaType
    );

};

#endif // OPENDECKVESSEL_H
