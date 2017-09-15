#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <cmath>
#include <stdexcept>

struct TimeSpan final
{
    constexpr explicit
    TimeSpan(double sec) :
        m_value(sec)
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

    // Arithmetic Operators.
    friend constexpr TimeSpan operator+(TimeSpan lhs, TimeSpan rhs)
    {
        return TimeSpan(lhs.m_value + rhs.m_value);
    }

    friend constexpr TimeSpan operator-(TimeSpan lhs, TimeSpan rhs)
    {
        return TimeSpan(lhs.m_value - rhs.m_value);
    }

    friend constexpr TimeSpan operator*(TimeSpan lhs, double rhs)
    {
        return TimeSpan(lhs.m_value * rhs);
    }

    friend constexpr TimeSpan operator*(double lhs, TimeSpan rhs)
    {
        return TimeSpan(lhs * rhs.m_value);
    }

    // Relational operators.
    friend constexpr bool operator<(TimeSpan lhs, TimeSpan rhs)
    {
        return lhs.m_value < rhs.m_value;
    }

    friend constexpr bool operator<=(TimeSpan lhs, TimeSpan rhs)
    {
        return lhs.m_value <= rhs.m_value;
    }

    friend constexpr bool operator>(TimeSpan lhs, TimeSpan rhs)
    {
        return lhs.m_value > rhs.m_value;
    }

    friend constexpr bool operator>=(TimeSpan lhs, TimeSpan rhs)
    {
        return lhs.m_value >= rhs.m_value;
    }

private:

    double m_value;
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
