#ifndef _MATH_QUATERNION_
#define _MATH_QUATERNION_

#include <ostream>
#include <cmath>

#include "vector.h"

namespace math
{
template<class T>
class quaternion
{
    typedef T type;

public:
    vector3<T> v;
    T w;

    quaternion(T w = T(0))
    {
        set(w);
    }

    quaternion(T x, T y, T z, T w = T(0))
    {
        set(x, y, z, w);
    }

    quaternion(const vector3<T> &v, T w = T(0))
    {
        set(v, w);
    }

    quaternion(const T *a)
    {
        set(a);
    }

    ~quaternion()
    {
    }

    inline T &operator [](unsigned int i)
    {
        get(i);
    }

    inline const T &operator [](unsigned int i) const
    {
        get(i);
    }

    inline T &operator ()(unsigned int i)
    {
        get(i);
    }

    inline const T &operator ()(unsigned int i) const
    {
        get(i);
    }

    inline operator T *()
    {
        return &v;
    }

    inline operator const T *() const
    {
        return &v;
    }

    inline T &get(unsigned int i)
    {
        return *(&v + i);
    }

    inline const T &get(unsigned int i) const
    {
        return *(&v + i);
    }

    inline vector3<T> &get_im()
    {
        return v;
    }

    inline const vector3<T> &get_im() const
    {
        return v;
    }

    inline T &get_re()
    {
        return w;
    }

    inline const T &get_re() const
    {
        return w;
    }

    inline quaternion<T> &set(T w = T(0))
    {
        v.set();
        this->w = w;
        return *this;
    }

    inline quaternion<T> &set(T x, T y, T z, T w = T(0))
    {
        v.set(x, y, z);
        this->w = w;
        return *this;
    }

    inline quaternion<T> &set(const vector3<T> &v, T w = T(0))
    {
        this->v = v;
        this->w = w;
        return *this;
    }

    inline quaternion<T> &set(const T *a)
    {
        v.set(a);
        w = a[4];
        return *this;
    }

    inline quaternion<T> &operator +=(T rhs)
    {
        w += rhs;
        return *this;
    }

    inline quaternion<T> &operator +=(const vector3<T> &rhs)
    {
        v += rhs;
        return *this;
    }

    inline quaternion<T> &operator +=(const quaternion<T> &rhs)
    {
        v += rhs.v;
        w += rhs.w;
        return *this;
    }

    inline quaternion<T> operator +(T rhs) const
    {
        return quaternion<T>(v, w + rhs);
    }

    inline quaternion<T> operator +(const vector3<T> &rhs) const
    {
        return quaternion<T>(v + rhs, w);
    }

    inline quaternion<T> operator +(const quaternion<T> &rhs) const
    {
        return quaternion<T>(v + rhs.v, w + rhs.w);
    }

    friend inline quaternion<T> operator +(T lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(rhs.v, lhs + rhs.w);
    }

    friend inline quaternion<T> operator +(const vector3<T> &lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(lhs + rhs.v, rhs.w);
    }

    inline quaternion<T> &operator -=(T rhs)
    {
        w -= rhs;
        return *this;
    }

    inline quaternion<T> &operator -=(const vector3<T> &rhs)
    {
        v -= rhs;
        return *this;
    }

    inline quaternion<T> &operator -=(const quaternion<T> &rhs)
    {
        v -= rhs.v;
        w -= rhs.w;
        return *this;
    }

    inline quaternion<T> operator -(T rhs) const
    {
        return quaternion<T>(v, w - rhs);
    }

    inline quaternion<T> operator -(const vector3<T> &rhs) const
    {
        return quaternion<T>(v - rhs, w);
    }

    inline quaternion<T> operator -(const quaternion<T> &rhs) const
    {
        return quaternion<T>(v - rhs.v, w - rhs.w);
    }

    friend inline quaternion<T> operator -(T lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(-rhs.v, lhs - rhs.w);
    }

    friend inline quaternion<T> operator -(const vector3<T> &lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(lhs - rhs.v, -rhs.w);
    }

    inline quaternion<T> &operator *=(T rhs)
    {
        v *= rhs;
        w *= rhs;
        return *this;
    }

    inline quaternion<T> &operator *=(const vector3<T> &rhs)
    {
        v = cross(v, rhs.v);
        w = -dot(v, rhs.v);
        return *this;
    }

    inline quaternion<T> &operator *=(const quaternion<T> &rhs)
    {
        v = cross(v, rhs.v) + w * rhs.v + rhs.w * v;
        w = w * rhs.w - dot(v, rhs.v);
        return *this;
    }

    inline quaternion<T> operator *(T rhs) const
    {
        return quaternion<T>(v * rhs, w * rhs);
    }

    inline quaternion<T> operator *(const vector3<T> &rhs) const
    {
        return quaternion<T>(cross(v, rhs) + w * rhs, -dot(v, rhs));
    }

    inline quaternion<T> operator *(const quaternion<T> &rhs) const
    {
        return quaternion<T>(cross(v, rhs.v) + w * rhs.v + rhs.w * v,
                             w * rhs.w - dot(v, rhs.v));
    }

    friend inline quaternion<T> operator *(T lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(lhs * rhs.v, lhs * rhs.w);
    }

    friend inline quaternion<T> operator *(const vector3<T> &lhs, const quaternion<T> &rhs)
    {
        return quaternion<T>(cross(lhs, rhs.v) + rhs.w * lhs, -dot(lhs, rhs.v));
    }

    inline bool operator ==(const quaternion<T> &rhs) const
    {
        return v == rhs.v && w == rhs.w;
    }

    inline bool operator !=(const quaternion<T> &rhs) const
    {
        return v != rhs.v || w != rhs.w;
    }

    inline T norm() const
    {
        return dot(v, v) + w * w;
    }

    inline quaternion<T> normalize() const
    {
        T m = 1.0 / norm();
        return quaternion<T>(v * m, w * m);
    }

    inline quaternion<T> conjugate() const
    {
        return quaternion<T>(-v, w);
    }

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
