#ifndef MEASUREMENTUNIT_H
#define MEASUREMENTUNIT_H

template <typename T>
struct MeasurementUnit
{
protected:

    constexpr explicit
    MeasurementUnit(double value) :
        m_value(value)
    {}

    double m_value;

public:

    // Arithmetic Operators.
    friend constexpr T operator+(T lhs, T rhs)
    {
        return T(lhs.m_value + rhs.m_value);
    }

    friend constexpr T operator-(T lhs, T rhs)
    {
        return T(lhs.m_value - rhs.m_value);
    }

    friend constexpr T operator*(T lhs, double rhs)
    {
        return T(lhs.m_value * rhs);
    }

    friend constexpr T operator*(double lhs, T rhs)
    {
        return T(lhs * rhs.m_value);
    }

    // Relational operators.
    friend constexpr bool operator<(T lhs, T rhs)
    {
        return lhs.m_value < rhs.m_value;
    }

    friend constexpr bool operator<=(T lhs, T rhs)
    {
        return lhs.m_value <= rhs.m_value;
    }

    friend constexpr bool operator>(T lhs, T rhs)
    {
        return lhs.m_value > rhs.m_value;
    }

    friend constexpr bool operator>=(T lhs, T rhs)
    {
        return lhs.m_value >= rhs.m_value;
    }
};

#endif
