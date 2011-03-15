#ifndef _MATH_QUATERNION_
#define _MATH_QUATERNION_

#include <ostream>
#include <cmath>

#include "vector.h"

namespace math
{
/**
 * Quaternion class
 */
template<class T>
class quaternion
{
    typedef T type;

public:
    /**
     * Imaginary part
     */
    vector3<T> v;

    /**
     * Real part
     */
    T w;

    /**
     * Construct quaternion (0, 0, 0, w)
     */
    quaternion(T w = T(0))
    {
        set(w);
    }

    /**
     * Construct quaternion (x, y, z, w)
     */
    quaternion(T x, T y, T z, T w = T(0))
    {
        set(x, y, z, w);
    }

    /**
     * Construct quaternion (v, w)
     */
    quaternion(const vector3<T> &v, T w = T(0))
    {
        set(v, w);
    }

    /**
     * Construct quaternion from array
     */
    quaternion(const T *a)
    {
        set(a);
    }

    ~quaternion()
    {
    }

    /**
     * Array access operator
     * @return reference to i element
     */
    inline T &operator [](unsigned int i)
    {
        get(i);
    }

    /**
     * Array access operator
     * @return reference to i element of constant quaternion
     */
    inline const T &operator [](unsigned int i) const
    {
        get(i);
    }

    /**
     * Access operator
     * @return reference to i element
     */
    inline T &operator ()(unsigned int i)
    {
        get(i);
    }

    /**
     * Access operator
     * @return reference to i element of constant quaternion
     */
    inline const T &operator ()(unsigned int i) const
    {
        get(i);
    }

    /**
     * Type cast
     * @return array pointer
     */
    inline operator T *()
    {
        return &v;
    }

    /**
     * Type case
     * @return constant array pointer
     */
    inline operator const T *() const
    {
        return &v;
    }

    /**
     * Explicit getter
     * @return reference to i element
     */
    inline T &get(unsigned int i)
    {
        return *(&v + i);
    }

    /**
     * Explicit getter
     * @return reference to i element of constant quaternion
     */
    inline const T &get(unsigned int i) const
    {
        return *(&v + i);
    }

    /**
     * Explicit getter
     * @return imaginary part
     */
    inline vector3<T> &get_im()
    {
        return v;
    }

    /**
     * Explicit getter
     * @return imaginary part of constant quaternion
     */
    inline const vector3<T> &get_im() const
    {
        return v;
    }

    /**
     * Explicit getter
     * @return real part
     */
    inline T &get_re()
    {
        return w;
    }

    /**
     * Explicit getter
     * @return real part of constant quaternion
     */
    inline const T &get_re() const
    {
        return w;
    }

    /**
     * Set quaternion (0, 0, 0, w)
     */
    inline quaternion<T> &set(T w = T(0))
    {
        v.set();
        this->w = w;
        return *this;
    }

    /**
     * Set quaternion (x, y, z, w)
     */
    inline quaternion<T> &set(T x, T y, T z, T w = T(0))
    {
        v.set(x, y, z);
        this->w = w;
        return *this;
    }

    /**
     * Set quaternion (v, w)
     */
    inline quaternion<T> &set(const vector3<T> &v, T w = T(0))
    {
        this->v = v;
        this->w = w;
        return *this;
    }

    /**
     * Set quaternion from array
     */
    inline quaternion<T> &set(const T *a)
    {
        v.set(a);
        w = a[4];
        return *this;
    }

    /**
     * Operator +=
     */
    inline quaternion<T> &operator +=(T rhs)
    {
        w += rhs;
        return *this;
    }

    /**
     * Operator +=
     */
    inline quaternion<T> &operator +=(const vector3<T> &rhs)
    {
        v += rhs;
        return *this;
    }

    /**
     * Operator +=
     */
    inline quaternion<T> &operator +=(const quaternion<T> &rhs)
    {
        v += rhs.v;
        w += rhs.w;
        return *this;
    }

    /**
     * Operator +
     */
    inline quaternion<T> operator +(T rhs) const
    {
        return quaternion<T>(v, w + rhs);
    }

    /**
     * Operator +
     */
    inline quaternion<T> operator +(const vector3<T> &rhs) const
    {
        return quaternion<T>(v + rhs, w);
    }

    /**
     * Operator +
     */
    inline quaternion<T> operator +(const quaternion<T> &rhs) const
    {
        return quaternion<T>(v + rhs.v, w + rhs.w);
    }

    /**
     * Operator +
     */
    friend inline quaternion<T> operator +(T lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(rhs.v, lhs + rhs.w);
    }

    /**
     * Operator +
     */
    friend inline quaternion<T> operator +(const vector3<T> &lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(lhs + rhs.v, rhs.w);
    }

    /**
     * Operator -=
     */
    inline quaternion<T> &operator -=(T rhs)
    {
        w -= rhs;
        return *this;
    }

    /**
     * Operator -=
     */
    inline quaternion<T> &operator -=(const vector3<T> &rhs)
    {
        v -= rhs;
        return *this;
    }

    /**
     * Operator -=
     */
    inline quaternion<T> &operator -=(const quaternion<T> &rhs)
    {
        v -= rhs.v;
        w -= rhs.w;
        return *this;
    }

    /**
     * Operator -
     */
    inline quaternion<T> operator -(T rhs) const
    {
        return quaternion<T>(v, w - rhs);
    }

    /**
     * Operator -
     */
    inline quaternion<T> operator -(const vector3<T> &rhs) const
    {
        return quaternion<T>(v - rhs, w);
    }

    /**
     * Operator -
     */
    inline quaternion<T> operator -(const quaternion<T> &rhs) const
    {
        return quaternion<T>(v - rhs.v, w - rhs.w);
    }

    /**
     * Operator -
     */
    friend inline quaternion<T> operator -(T lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(-rhs.v, lhs - rhs.w);
    }

    /**
     * Operator -
     */
    friend inline quaternion<T> operator -(const vector3<T> &lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(lhs - rhs.v, -rhs.w);
    }

    /**
     * Operator *=
     */
    inline quaternion<T> &operator *=(T rhs)
    {
        v *= rhs;
        w *= rhs;
        return *this;
    }

    /**
     * Operator *=
     */
    inline quaternion<T> &operator *=(const vector3<T> &rhs)
    {
        v = cross(v, rhs.v);
        w = -dot(v, rhs.v);
        return *this;
    }

    /**
     * Operator *=
     */
    inline quaternion<T> &operator *=(const quaternion<T> &rhs)
    {
        v = cross(v, rhs.v) + w * rhs.v + rhs.w * v;
        w = w * rhs.w - dot(v, rhs.v);
        return *this;
    }

    /**
     * Operator *
     */
    inline quaternion<T> operator *(T rhs) const
    {
        return quaternion<T>(v * rhs, w * rhs);
    }

    /**
     * Operator *
     */
    inline quaternion<T> operator *(const vector3<T> &rhs) const
    {
        return quaternion<T>(cross(v, rhs) + w * rhs, -dot(v, rhs));
    }

    /**
     * Operator *
     */
    inline quaternion<T> operator *(const quaternion<T> &rhs) const
    {
        return quaternion<T>(cross(v, rhs.v) + w * rhs.v + rhs.w * v,
                             w * rhs.w - dot(v, rhs.v));
    }

    /**
     * Operator *
     */
    friend inline quaternion<T> operator *(T lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(lhs * rhs.v, lhs * rhs.w);
    }

    /**
     * Operator *
     */
    friend inline quaternion<T> operator *(const vector3<T> &lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(cross(lhs, rhs.v) + rhs.w * lhs, -dot(lhs, rhs.v));
    }

    /**
     * Operator ==
     */
    inline bool operator ==(const quaternion<T> &rhs) const
    {
        return v == rhs.v && w == rhs.w;
    }

    /**
     * Operator !=
     */
    inline bool operator !=(const quaternion<T> &rhs) const
    {
        return v != rhs.v || w != rhs.w;
    }

    /**
     * @return quaternion norm
     */
    inline T norm() const
    {
        return dot(v, v) + w * w;
    }

    /**
     * @return normalized quaternion
     */
    inline quaternion<T> normalize() const
    {
        T m = 1.0 / norm();
        return quaternion<T>(v * m, w * m);
    }

    /**
     * @return conjugated quaternion
     */
    inline quaternion<T> conjugate() const
    {
        return quaternion<T>(-v, w);
    }

    /**
     * @return inversed quaternion
     */
    inline quaternion<T> inverse() const
    {
        return conjugate().normalize();
    }
};

typedef quaternion<float> quaternionf;
typedef quaternion<double> quaterniond;
typedef quaternion<long double> quaternionld;
}

#endif
