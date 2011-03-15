#ifndef _MATH_VECTOR_
#define _MATH_VECTOR_

#include <ostream>
#include <cmath>

namespace math
{
template<class T> class vector3;
template<class T> class vector4;

/**
 * Two-dimensional vector class
 */
template<class T>
class vector2
{
    typedef T type;

public:
    T x, y;

    /**
     * Construct vector (n, n)
     */
    explicit vector2(T n = T(0))
    {
        set(n);
    }

    /**
     * Construct vector (x, y)
     */
    vector2(T x, T y)
    {
        set(x, y);
    }

    /**
     * Construct vector from array
     */
    explicit vector2(const T *a)
    {
        set(a);
    }

    /**
     * Construct vector (x, y) from (x, y, z)
     */
    vector2(const vector3<T> &v) :
        x(v.x), y(v.y)
    {
    }

    /**
     * Construct vector (x / w, y / w) from (x, y, z, w)
     */
    vector2(const vector4<T> &v)
    {
        x = v.x / v.w;
        y = v.x / v.w;
    }

    ~vector2()
    {
    }

    /**
     * Array access operator
     * @return reference to i element
     */
    inline T &operator [](unsigned int i)
    {
        return get(i);
    }

    /**
     * Array access operator
     * @return reference to i element of constant vector
     */
    inline const T &operator [](unsigned int i) const
    {
        return get(i);
    }

    /**
     * Access operator
     * @return reference to i element
     */
    inline T &operator ()(unsigned int i)
    {
        return get(i);
    }

    /**
     * Access operator
     * @return reference to i element of constant vector
     */
    inline const T &operator ()(unsigned int i) const
    {
        return get(i);
    }

    /**
     * Type cast
     * @return array pointer
     */
    inline operator T *()
    {
        return &x;
    }

    /**
     * Type cast
     * @return constant array pointer
     */
    inline operator const T *() const
    {
        return &x;
    }

    /**
     * Explicit getter
     * @return reference to i element
     */
    inline T &get(unsigned int i)
    {
        return *(&x + i);
    }

    /**
     * Explicit getter
     * @return reference to i element of constant vector
     */
    inline const T &get(unsigned int i) const
    {
        return *(&x + i);
    }

    /**
     * Set vector (n, n)
     */
    inline vector3<T> &set(T n = T(0))
    {
        x = n;
        y = n;
        return *this;
    }

    /**
     * Set vector (x, y)
     */
    inline vector3<T> &set(T x, T y)
    {
        this->x = x;
        this->y = y;
        return *this;
    }

    /**
     * Set vector from array
     */
    inline vector3<T> &set(const T *a)
    {
        x = a[0];
        y = a[1];
        return *this;
    }

    /**
     * Operator +=
     */
    inline vector2<T> &operator +=(const vector2<T> &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    /**
     * Operator +
     */
    inline vector2<T> operator +(const vector2<T> &rhs) const
    {
        return vector2<T> (x + rhs.x, y + rhs.y);
    }

    /**
     * Operator -=
     */
    inline vector2<T> &operator -=(const vector2<T> &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    /**
     * Operator -
     */
    inline vector2<T> operator -() const
    {
        return vector2<T>(-x, -y);
    }

    /**
     * Operator -
     */
    inline vector2<T> operator -(const vector2<T> &rhs) const
    {
        return vector2<T> (x - rhs.x, y - rhs.y);
    }

    /**
     * Operator *=
     */
    inline vector2<T> &operator *=(T rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    /**
     * Operator *
     */
    inline vector2<T> operator *(const T rhs) const
    {
        return vector2<T> (x * rhs, y * rhs);
    }

    /**
     * Operator *
     */
    friend inline vector2<T> operator *(const T lhs, const vector2<T> &rhs)
    {
        return vector2<T> (lhs * rhs.x, lhs * rhs.y);
    }

    /**
     * Operator /=
     */
    inline vector2<T> &operator /=(T rhs)
    {
        x /= rhs;
        y /= rhs;
        return *this;
    }

    /**
     * Operator /
     */
    inline vector2<T> operator /(T rhs) const
    {
        return vector2<T> (x / rhs, y / rhs);
    }

    /**
     * Operator ==
     */
    inline bool operator ==(const vector2<T> &rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }

    /**
     * Operator !=
     */
    inline bool operator !=(const vector2<T> &rhs) const
    {
        return x != rhs.y || y != rhs.y;
    }

    /**
     * @return scalar product
     */
    friend inline T dot(const vector2<T> &lhs, const vector2<T> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    /**
     * @return vector length
     */
    inline T norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    /**
     * @return normalized vector
     */
    inline vector2<T> normalize() const
    {
        return operator /(norm());
    }

    friend inline std::ostream &operator <<(std::ostream &lhs,
                                            const vector2<T> &rhs)
    {
        return lhs << "(" << rhs.x << ", " << rhs.y << ")";
    }
};

typedef vector2<float> vector2f;
typedef vector2<double> vector2d;
typedef vector2<long double> vector2ld;


/**
 * Three-dimensional vector class
 */
template<class T>
class vector3
{
    typedef T type;

public:
    T x, y, z;

    /**
     * Construct vector (n, n, n)
     */
    explicit vector3(T n = T(0))
    {
        set(n);
    }

    /**
     * Construct vector (x, y, z)
     */
    vector3(T x, T y, T z)
    {
        set(x, y, z);
    }

    /**
     * Construct vector from array
     */
    explicit vector3(const T *a)
    {
        set(a);
    }

    /**
     * Construct vector (x, y, z) from (x, y)
     */
    vector3(const vector2<T> &v, T z = T(0)) :
        x(v.x), y(v.y), z(z)
    {
    }

    /**
     * Construct vector (x / w, y / w, z / w) from (x, y, z, w)
     */
    vector3(const vector4<T> &v)
    {
        T m = 1.0 / v.w;
        x = v.x * m;
        y = v.y * m;
        z = v.z * m;
    }

    ~vector3()
    {
    }

    /**
     * Array access operator
     * @return reference to i element of vector
     */
    inline T &operator [](unsigned int i)
    {
        return get(i);
    }

    /**
     * Array access operator
     * @return reference to i element of constant vector
     */
    inline const T &operator [](unsigned int i) const
    {
        return get(i);
    }

    /**
     * Access operator
     * @return reference to i element of vector
     */
    inline T &operator ()(unsigned int i)
    {
        return get(i);
    }

    /**
     * Access operator
     * @return reference to i element of constant vector
     */
    inline const T &operator ()(unsigned int i) const
    {
        return get(i);
    }

    /**
     * Type cast
     * @return array pointer
     */
    inline operator T *()
    {
        return &x;
    }

    /**
     * Type cast
     * @return constant array pointer
     */
    inline operator const T *() const
    {
        return &x;
    }

    /**
     * Explicit getter
     * @return reference to i element
     */
    inline T &get(unsigned int i)
    {
        return *(&x + i);
    }

    /**
     * Explicit getter
     * @return reference to i element of constant vector
     */
    inline const T &get(unsigned int i) const
    {
        return *(&x + i);
    }

    /**
     * Set vector (n, n, n)
     */
    inline vector3<T> &set(T n = T(0))
    {
        x = n;
        y = n;
        z = n;
        return *this;
    }

    /**
     * Set vector (x, y, z)
     */
    inline vector3<T> &set(T x, T y, T z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        return *this;
    }

    /**
     * Set vector from array
     */
    inline vector3<T> &set(const T *a)
    {
        x = a[0];
        y = a[1];
        z = a[2];
        return *this;
    }

    /**
     * Operator +=
     */
    inline vector3<T> &operator +=(const vector3<T> &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    /**
     * Operator +
     */
    inline vector3<T> operator +(const vector3<T> &rhs) const
    {
        return vector3<T> (x + rhs.x, y + rhs.y, z + rhs.z);
    }

    /**
     * Operator -=
     */
    inline vector3<T> &operator -=(const vector3<T> &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    /**
     * Operator -
     */
    inline vector3<T> operator -() const
    {
        return vector3<T>(-x, -y, -z);
    }

    /**
     * Operator -
     */
    inline vector3<T> operator -(const vector3<T> &rhs) const
    {
        return vector3<T> (x - rhs.x, y - rhs.y, z - rhs.z);
    }

    /**
     * Operator *=
     */
    inline vector3<T> &operator *=(T rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    /**
     * Operator *
     */
    inline vector3<T> operator *(T rhs) const
    {
        return vector3<T> (x * rhs, y * rhs, z * rhs);
    }

    /**
     * Operator *
     */
    friend inline vector3<T> operator *(T lhs, const vector3<T> &rhs)
    {
        return vector3<T> (lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
    }

    /**
     * Operator /=
     */
    inline vector3<T> &operator /=(T rhs)
    {
        T m = 1.0 / rhs;
        x *= m;
        y *= m;
        z *= m;
        return *this;
    }

    /**
     * Operator /
     */
    inline vector3<T> operator /(T rhs) const
    {
        T m = 1.0 / rhs;
        return vector3<T> (x * m, y * m, z * m);
    }

    /**
     * Operator ==
     */
    inline bool operator ==(const vector3<T> &rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    /**
     * Operator !=
     */
    inline bool operator !=(const vector3<T> &rhs) const
    {
        return x != rhs.x || y != rhs.y || z != rhs.z;
    }

    /**
     * @return scalar product
     */
    friend inline T dot(const vector3<T> &lhs, const vector3<T> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    /**
     * @return vector product
     */
    friend inline vector3<T> cross(const vector3<T> &lhs, const vector3<T> &rhs)
    {
        return vector3<T> (lhs.y * rhs.z - lhs.z * rhs.y,
                           lhs.z * rhs.x - lhs.x * rhs.z,
                           lhs.x * rhs.y - lhs.y * rhs.x);
    }

    /**
     * @return vector length
     */
    inline T norm() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    /**
     * @return normalized vector
     */
    inline vector3<T> normalize() const
    {
        return operator /(norm());
    }

    friend inline std::ostream &operator <<(std::ostream &lhs,
                                            const vector3<T> &rhs)
    {
        return lhs << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    }
};

typedef vector3<float> vector3f;
typedef vector3<double> vector3d;
typedef vector3<long double> vector3ld;

/**
 * Homogeneous vector class
 */
template<class T>
class vector4
{
    typedef T type;

public:
    T x, y, z, w;

    /**
     * Construct vector (n, n, n, n)
     */
    explicit vector4(T n = T(0))
    {
        set(n);
    }

    /**
     * Construct vector (x, y, z, w)
     */
    vector4(T x, T y, T z, T w = T(1))
    {
        set(x, y, z, w);
    }

    /**
     * Construct vector from array
     */
    explicit vector4(const T *a)
    {
        set(a);
    }

    /**
     * Construct vector (x, y, z, w) from (x, y)
     */
    vector4(const vector2<T> &v, T z = T(0), T w = T(1)) :
        x(v.x), y(v.y), z(z), w(w)
    {
    }

    /**
     * Construct vector (x, y, z, w) from (x, y, z)
     */
    vector4(const vector3<T> &v, T w = T(1)) :
        x(v.x), y(v.y), z(v.z), w(w)
    {
    }

    ~vector4()
    {
    }

    /**
     * Array access operator
     * @return reference to i element of vector
     */
    inline T &operator [](unsigned int i)
    {
        return get(i);
    }

    /**
     * Array access
     * @return reference to i element of constant vector
     */
    inline const T &operator [](unsigned int i) const
    {
        return get(i);
    }

    /**
     * Access operator
     * @return reference to i element of vector
     */
    inline T &operator ()(unsigned int i)
    {
        return get(i);
    }

    /**
     * Access operator
     * @return reference to i element of constant vector
     */
    inline const T &operator ()(unsigned int i) const
    {
        return get(i);
    }

    /**
     * Type cast
     * @return array pointer
     */
    inline operator T *()
    {
        return &x;
    }

    /**
     * Type cast
     * @return constant array pointer
     */
    inline operator const T *() const
    {
        return &x;
    }

    /**
     * Explicit getter
     * @return reference to i element of vector
     */
    inline T &get(unsigned int i)
    {
        return *(&x + i);
    }

    /**
     * Explicit getter
     * @return reference to i element of constant vector
     */
    inline const T &get(unsigned int i) const
    {
        return *(&x + i);
    }

    /**
     * Set vector (n, n, n, n)
     */
    inline vector4<T> &set(T n = T(0))
    {
        x = n;
        y = n;
        z = n;
        w = T(1);
        return *this;
    }

    /**
     * Set vector (x, y, z, w)
     */
    inline vector4<T> &set(T x, T y, T z, T w = T(1))
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        return *this;
    }

    /**
     * Set vector from array
     */
    inline vector4<T> &set(const T *a)
    {
        x = a[0];
        y = a[1];
        z = a[2];
        w = a[3];
        return *this;
    }

    /**
     * Operator +=
     */
    inline vector4<T> &operator +=(const vector4<T> &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    /**
     * Operator +
     */
    inline vector4<T> operator +(const vector4<T> &rhs) const
    {
        return vector4<T> (x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    }

    /**
     * Operator -=
     */
    inline vector4<T> &operator -=(const vector4<T> &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }

    /**
     * Operator -
     */
    inline vector4<T> operator -() const
    {
        return vector4<T>(-x, -y, -z, -w);
    }

    /**
     * Operator -
     */
    inline vector4<T> operator -(const vector4<T> &rhs) const
    {
        return vector4<T> (x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }

    /**
     * Operator *=
     */
    inline vector4<T> &operator *=(T rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        w *= rhs;
        return *this;
    }

    /**
     * Operator *
     */
    inline vector4<T> operator *(T rhs) const
    {
        return vector4<T> (x * rhs, y * rhs, z * rhs, w * rhs);
    }

    /**
     * Operator *
     */
    friend inline vector4<T> operator *(T lhs, const vector4<T> &rhs)
    {
        return vector4<T> (lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
    }

    /**
     * Operator /=
     */
    inline vector4<T> &operator /=(T rhs)
    {
        T m = 1.0 / rhs;
        x *= m;
        y *= m;
        z *= m;
        w *= m;
        return *this;
    }

    /**
     * Operator /
     */
    inline vector4<T> operator /(T rhs) const
    {
        T m = 1.0 / rhs;
        return vector4<T> (x * m, y * m, z * m, w * m);
    }

    /**
     * Operator ==
     */
    inline bool operator ==(const vector4<T> &rhs) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
    }

    /**
     * Operator !=
     */
    inline bool operator !=(const vector4<T> &rhs) const
    {
        return x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w;
    }

    /**
     * @return scalar product
     */
    friend inline T dot(const vector4<T> &lhs, const vector4<T> &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
    }

    /**
     * @return vector length
     */
    inline T norm() const
    {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @return normalized vector
     */
    inline vector4<T> normalize() const
    {
        return operator /(norm());
    }

    friend inline std::ostream &operator <<(std::ostream &lhs,
                                            const vector4<T> &rhs)
    {
        return lhs << "(" << rhs.x << ", "
                          << rhs.y << ", "
                          << rhs.z << ", "
                          << rhs.w << ")";
    }
};

typedef vector4<float> vector4f;
typedef vector4<double> vector4d;
typedef vector4<long double> vector4ld;
}

#endif
