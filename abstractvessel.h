#ifndef ABSTRACTVESSEL_H
#define ABSTRACTVESSEL_H

enum VesselType {
    TechnicalFleet,
    OpenDeckVessel,
    UnusualDesignVessel,
    UnusualPurposeVessel,
    RegularVessel
};

enum VesselSwimmingAreaType {
    Unrestricted,
    R1,
    R2,
    R2_RSN,
    R2_RSN_4,
    R2_RSN_5,
    R3_RSN,
    R3
};

class AbstractVessel
{
protected:
    /// Соответственно длина судна L из Правил.
    float m_length;
    /// Соответственно ширина судна B из Правил.
    float m_width;
    /// Соответственно высота борта судна D из Правил.
    float m_height;
    /// Соответственно коэффициент общей полноты судна C_b из Правил.
    float m_overallCompletenessCoefficient;
    /// Соответственно спецификационная скорость судна v_0 из Правил.
    float m_specificationSpeed;

    /// Тип судна.
    VesselType m_type;
    /// Классификация района плавания.
    VesselSwimmingAreaType m_swimmingAreaType;

protected:
    /// Функция проверяющая соответствует ли заданное судно критериям, представленным в п. 1.4.1.1 из Правил.
    virtual bool isMeetingCriteria() = 0;
    /// Функция проверяющая соответствует ли заданное судно критериям, представленным в п. 1.4.1.2 из Правил.
    virtual bool isConstructionMeetingCriteria() = 0;

    float getKCoefficient() {return (m_length <= 100) ? 2.2 : (2.2 - 0.25 * (m_length - 100) / 100); }

public:
    AbstractVessel();
    AbstractVessel(
        float length, float width, float height,
        float overallCompletenessCoefficient, float specificationSpeed,
        VesselType type, VesselSwimmingAreaType swimmingAreaType
    );

public:
    /// Основная функция проверки соответствия требованиям к продольной прочности п. 1.4.1 из Правил.
    bool isMeetingMainLongitudinalStrengthRequirements();

public:
    /// Соответственно длина судна L из Правил.
    float length() const { return m_length; }
    /// Соответственно ширина судна B из Правил.
    float width() const { return m_width; }
    /// Соответственно высота борта судна D из Правил.
    float height() const { return m_height; }
    /// Соответственно коэффициент общей полноты судна C_b из Правил.
    float overallCompletenessCoefficient() { return m_overallCompletenessCoefficient; }
    /// Соответственно спецификационная скорость судна v_0 из Правил.
    float specificationSpeed() { return m_specificationSpeed; }
    /// Тип судна.
    VesselType type() const { return m_type; }
    /// Классификация района плавания.
    VesselSwimmingAreaType swimmingAreaType() const { return m_swimmingAreaType; }

};

#endif // ABSTRACTVESSEL_H
