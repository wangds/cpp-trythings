#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <cmath>
#include <stdexcept>
#include "MeasurementUnit.h"

struct TimeSpan final : public MeasurementUnit<TimeSpan>
{
    constexpr explicit
    TimeSpan(double sec) :
        MeasurementUnit(sec)
    {
        if (std::isnan(m_value)) {
            throw std::domain_error("TimeSpan: invariant (not NaN)");
        }
    }

    constexpr double
    Sec() const
    {
        return m_value;
    }
};

constexpr TimeSpan operator"" _s(long double sec)
{
    return TimeSpan(static_cast<double>(sec));
}

constexpr TimeSpan operator"" _ms(long double msec)
{
    return TimeSpan(static_cast<double>(msec / 1000.0));
}

#endif
