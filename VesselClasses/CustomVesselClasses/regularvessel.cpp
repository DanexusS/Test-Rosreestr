#include "regularvessel.h"

RegularVessel::RegularVessel() {}

RegularVessel::RegularVessel(
    float length, float width, float height,
    float overallCompletenessCoefficient, float specificationSpeed,
    VesselSwimmingAreaType swimmingAreaType
) :
    AbstractVessel(
        length, width, height,
        overallCompletenessCoefficient, specificationSpeed,
        VesselType::RegularVesselType, swimmingAreaType
    )
{}
