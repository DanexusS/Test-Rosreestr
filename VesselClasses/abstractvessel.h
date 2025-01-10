#ifndef ABSTRACTVESSEL_H
#define ABSTRACTVESSEL_H

#include <cmath>

/// Тип судна, целочисленные значения каждого типа соответствуют его индексу в списке типов на русском
enum VesselType : int {
    TechnicalFleetType = 0,
    OpenDeckVesselType = 1,
    UnusualDesignVesselType = 2,
    UnusualPurposeVesselType = 3,
    RegularVesselType = 4
};

/// Категории районов плавания судна, целочисленные значения каждой категории соответствуют его индексу в списке типов на русском
enum VesselSwimmingAreaType : int {
    Unrestricted = 0,
    R1 = 1,
    R2 = 2,
    R2_RSN = 3,
    R2_RSN_4 = 4,
    R2_RSN_5 = 5,
    R3_RSN = 6,
    R3 = 7
};

class AbstractVessel
{

private:
    float getKCoefficient() {return (m_length <= 100) ? 2.2 : (2.2 - 0.25 * (m_length - 100) / 100); }

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

    bool checkSpeed() { return m_specificationSpeed > getKCoefficient() * std::sqrt(this->m_length); }

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
