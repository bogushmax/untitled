#ifndef _MATH_QUATERNION_
#define _MATH_QUATERNION_

#include "math.h"

namespace math
{

template<class T>
class quaternion
{
    typedef T type;

public:
    vector3<T> v;
    T w;

    quaternion() : w(T(0))
    {
        v.set(T(0));
    }

    quaternion(T x, T y, T z, T w) :
        w(w)
    {
        v.set(x, y, z);
    }

    quaternion(vector3<T> v, T w) :
        v(v), w(w)
    {
    }

    quaternion(vector3<T> v) :
        v(v), w(T(0))
    {
    }

    quaternion(T w) :
        w(w)
    {
        v.set(T(0));
    }

    ~quaternion()
    {
    }

    inline quaternion<T> &operator +=(const quaternion<T> &q) const
    {
        this->v += q.v;
        this->w += q.w;
        return *this;
    }

    inline quaternion<T> operator +(const quaternion<T> &q) const
    {
        return quaternion<T>(v + q.v, w + q.w);
    }

    friend inline quaternion<T> operator+(const vector3<T> &v, const quaternion<T> &q)
    {
        return quaternion<T>(v + q.v, q.w);
    }

    friend inline quaternion<T> operator+(T n, const quaternion<T> &q)
    {
        return quaternion<T>(q.v, q.w + n);
    }

    inline quaternion<T> &operator -=(const quaternion<T> &q) const
    {
        this->v -= q.v;
        this->w -= q.w;
        return *this;
    }

    inline quaternion<T> operator -(const quaternion<T> &q) const
    {
        return quaternion<T>(v - q.v, w - q.w);
    }

    friend inline quaternion<T> operator-(const vector3<T> &v, const quaternion<T> &q)
    {
        return quaternion<T>(v - q.v, q.w);
    }

    friend inline quaternion<T> operator-(T n, quaternion<T> &q)
    {
        return quaternion<T>(q.v, q.w - n);
    }

    inline quaternion<T> &operator *=(const quaternion<T> &q) const
    {
        v = dot(v, q.v) + w * q.v + q.w * v;
        w = w * q.w - (T) v * q.v;
        return *this;
    }

    inline quaternion<T> operator *(const quaternion<T> &q) const
    {
        return quaternion<T>(dot(v, q.v) + w * q.v + q.w * v, w * q.w - (T) v * q.v);
    }

    friend inline quaternion<T> operator *(T n, const quaternion<T> &q)
    {
        return quaternion<T>(n * q.v, n * q.w);
    }

    friend inline quaternion<T> operator *(const vector3<T> &v , const quaternion<T> &q)
    {
        return quaternion<T>(dot(v, q.v) + q.w * v, - (T) v * q.v);
    }

    inline T length() const
    {
        return std::sqrt<T>(v.x * v.x + v.y * v.y + v.z * v.z + w * w);
    }

    inline T norm() const
    {
        return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
    }

    inline quaternion<T> normalize() const
    {
        T len = length();
        return quaternion<T>(w / len, v.x / len, v.y / len, v.z / len);
    }

    inline quaternion<T> conjugate() const
    {
        return quaternion<T>(-v, w);
    }

    inline quaternion<T> inverse() const
    {
        return conjugate();
    }

};

typedef quaternion<float> quaternionf;
typedef quaternion<double> quaterniond;
typedef quaternion<long double> quaternionld;

}

#endif
