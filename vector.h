#ifndef _MATH_VECTOR_
#define _MATH_VECTOR_

#include <iostream>
#include <cmath>

namespace math
{
    template <class T> class vector3;
    template <class T> class vector4;
    
    template <class T>
    class vector2
    {
        typedef T type;
        
    public:
        T x, y;
        
        explicit vector2(T n = T())
        {
            set(n);
        }
        
        vector2(T x, T y)
        {
            set(x, y);
        }

        explicit vector2(T *a)
        {
            set(a);
        }

        vector2(const vector3<T> &v) : x(v.x), y(v.y)
        {
        }

        vector2(const vector4<T> &v) : x(v.x), y(v.y) 
        {
        }
        
        ~vector2() 
        {
        }
        
        inline T &operator [] (unsigned int i)
        {
            return *(&x + i);
        }

        inline const T &operator [] (unsigned int i) const
        {
            return *(&x + i);
        }

        inline T &operator () (unsigned int i)
        {
            return *(&x + i);
        }

        inline const T &operator () (unsigned int i) const
        {
            return *(&x + i);
        }

        inline operator T * ()
        {
            return &x;
        }

        inline operator const T * () const
        {
            return &x;
        }

        inline vector3<T> &set(T n = T())
        {
            x = n;
            y = n;
            return *this;
        }

        inline vector3<T> &set(T x, T y)
        {
            this->x = x;
            this->y = y;
            return *this;
        }

        inline vector3<T> &set(T *a)
        {
            x = a[0];
            y = a[1];
            return *this;
        }

        inline vector2<T> &operator += (T n)
        {
            x += n;
            y += n;
            return *this;
        }

        inline vector2<T> &operator += (const vector2<T> &v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }
        
        inline vector2<T> operator + (const vector2<T> &v) const 
        {
            return vector2<T>(x + v.x, y + v.y);
        }

        inline vector2<T> operator + (const T n) const
        {
            return vector2<T>(x + n, y + n);
        }

        friend inline vector2<T> operator + (const T n, const vector2<T> &v)
        {
            return vector2<T>(n + v.x, n + v.y);
        }
        
        inline vector2<T> &operator -= (T n)
        {
            x -= n;
            y -= n;
            return *this;
        }

        inline vector2<T> &operator -= (const vector2<T> &v)
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        inline vector2<T> operator - (const vector2<T> &v) const 
        {
            return vector2<T>(x - v.x, y - v.y);
        }

        inline vector2<T> operator - (const T n) const
        {
            return vector2<T>(x - n, y - n);
        }

        friend inline vector2<T> operator - (const T n, const vector2<T> &v)
        {
            return vector2<T>(n - v.x, n - v.y);
        }
        
        inline vector2<T> &operator *= (T n)
        {
            x *= n;
            y *= n;
            return *this;
        }

        inline vector2<T> &operator *= (const vector2<T> &v)
        {
            x *= v.x;
            y *= v.y;
            return *this;
        }
        
        inline vector2<T> operator * (const vector2<T> &v) const 
        {
            return vector2<T>(x * v.x, y * v.y);
        }

        inline vector2<T> operator * (const T n) const
        {
            return vector2<T>(x * n, y * n);
        }

        friend inline vector2<T> operator * (const T n, const vector2<T> &v)
        {
            return vector2<T>(n * v.x, n * v.y);
        }

        inline vector2<T> &operator /= (T n)
        {
            x /= n;
            y /= n;
            return *this;
        }

        inline vector2<T> &operator /= (const vector2<T> &v)
        {
            x /= v.x;
            y /= v.y;
            return *this;
        }
        
        inline vector2<T> operator / (const vector2<T> &v) const 
        {
            return vector2<T>(x / v.x, y / v.y);
        }
        
        inline vector2<T> operator / (const T n) const
        {
            return vector2<T>(x / n, y / n);
        }

        friend inline vector2<T> operator / (const T n, const vector2<T> &v)
        {
            return vector2<T>(n / v.x, n / v.y);
        }
        
        inline bool operator == (const vector2<T> &v) const
        {
            return x == v.x && y == v.y;
        }

        inline bool operator != (const vector2<T> &v) const
        {
            return x != v.y || y != v.y;
        }

        friend inline T dot(const vector2<T> &v1, const vector2<T> &v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }
        
        inline const T length() const
        {
            return std::sqrt(x * x + y * y);
        }

        inline vector2<T> normalize() const
        {
            T len = length();
            return vector2<T>(x / len, y / len);
        }

        friend inline std::ostream &operator << (std::ostream &s, const vector2<T> &v) 
        {
            return s << "(" << v.x << ", " << v.y << ")";
        }
        
    };

    typedef vector2<float> vector2f;
    typedef vector2<double> vector2d;
    typedef vector2<long double> vector2ld;

    template <class T>
    class vector3
    {
        typedef T type;
        
    public:
        T x, y, z;
        
        explicit vector3(T n = T())
        {
            set(n);
        }

        vector3(T x, T y, T z)
        {
            set(x, y, z);
        }

        explicit vector3(T *a)
        {
            set(a);
        }

        vector3(const vector2<T> &v, T z = T()) : x(v.x), y(v.y), z(z) 
        {
        }

        vector3(const vector4<T> &v) : x(v.x), y(v.y), z(v.z) 
        {
        }
        
        ~vector3() 
        {
        }
        
        inline T &operator [] (unsigned int i)
        {
            return *(&x + i);
        }

        inline const T &operator [] (unsigned int i) const
        {
            return *(&x + i);
        }

        inline T &operator () (unsigned int i)
        {
            return *(&x + i);
        }

        inline const T &operator () (unsigned int i) const
        {
            return *(&x + i);
        }

        inline operator T * ()
        {
            return &x;
        }

        inline operator const T * () const
        {
            return &x;
        }

        inline vector3<T> &set(T n = T())
        {
            x = n;
            y = n;
            z = n;
            return *this;
        }

        inline vector3<T> &set(T x, T y, T z) 
        {
            this->x = x;
            this->y = y;
            this->z = z;
            return *this;
        }

        inline vector3<T> &set(T *a)
        {
            x = a[0];
            y = a[1];
            z = a[2];
            return *this;
        }

        inline vector3<T> &operator += (T n)
        {
            x += n;
            y += n;
            z += n;
            return *this;
        }

        inline vector3<T> &operator += (const vector3<T> &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }
        
        inline vector3<T> operator + (const vector3<T> &v) const 
        {
            return vector3<T>(x + v.x, y + v.y, z + v.z);
        }

        inline vector3<T> operator + (const T n) const
        {
            return vector3<T>(x + n, y + n, z + n);
        }

        friend inline vector3<T> operator + (const T n, const vector3<T> &v)
        {
            return vector3<T>(n + v.x, n + v.y, n + v.z);
        }
        
        inline vector3<T> &operator -= (T n)
        {
            x -= n;
            y -= n;
            z -= n;
            return *this;
        }

        inline vector3<T> &operator -= (const vector3<T> &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        inline vector3<T> operator - (const vector3<T> &v) const 
        {
            return vector3<T>(x - v.x, y - v.y, z - v.z);
        }

        inline vector3<T> operator - (const T n) const
        {
            return vector3<T>(x - n, y - n, z - n);
        }

        friend inline vector3<T> operator - (const T n, const vector3<T> &v)
        {
            return vector3<T>(n - v.x, n - v.y, n - v.z);
        }
        
        inline vector3<T> &operator *= (T n)
        {
            x *= n;
            y *= n;
            z *= n;
            return *this;
        }

        inline vector3<T> &operator *= (const vector3<T> &v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            return *this;
        }
        
        inline vector3<T> operator * (const vector3<T> &v) const 
        {
            return vector3<T>(x * v.x, y * v.y, z * v.z);
        }

        inline vector3<T> operator * (const T n) const
        {
            return vector3<T>(x * n, y * n, z * n);
        }

        friend inline vector3<T> operator * (const T n, const vector3<T> &v)
        {
            return vector3<T>(n * v.x, n * v.y, n * v.z);
        }

        inline vector3<T> &operator /= (T n)
        {
            x /= n;
            y /= n;
            z /= n;
            return *this;
        }

        inline vector3<T> &operator /= (const vector3<T> &v)
        {
            x /= v.x;
            y /= v.y;
            z /= v.z;
            return *this;
        }
        
        inline vector3<T> operator / (const vector3<T> &v) const 
        {
            return vector3<T>(x / v.x, y / v.y, z / v.z);
        }
        
        inline vector3<T> operator / (const T n) const
        {
            return vector3<T>(x / n, y / n, z / n);
        }

        friend inline vector3<T> operator / (const T n, const vector3<T> &v)
        {
            return vector3<T>(n / v.x, n / v.y, n / v.z);
        }
        
        inline bool operator == (const vector3<T> &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }

        inline bool operator != (const vector3<T> &v) const
        {
            return x != v.x || y != v.y || z != v.z;
        }

        friend inline T dot(const vector3<T> &v1, const vector3<T> &v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }

        friend inline vector3<T> cross(const vector3<T> &v1, const vector3<T> &v2)
        {
            return vector3<T>(
                v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
        }
        
        inline const T length() const
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        inline vector3<T> normalize() const
        {
            T len = length();
            return vector3<T>(x / len, y / len, z / len);
        }

        friend inline std::ostream &operator << (std::ostream &s, const vector3<T> &v) 
        {
            return s << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        }
        
    };

    typedef vector3<float> vector3f;
    typedef vector3<double> vector3d;
    typedef vector3<long double> vector3ld;

    template <class T>
    class vector4 
    {
        typedef T type;
        
    public:
        T x, y, z, w;
        
        explicit vector4(T n = T())
        {
            set(n);
        }

        vector4(T x, T y, T z, T w)
        {
            set(x, y, z, w);
        }
        
        explicit vector4(T *a)
        {
            set(a);
        }

        vector4(const vector2<T> &v, T z = T(), T w = T()) : x(v.x), y(v.y), z(z), w(w)
        {
        }

        vector4(const vector3<T> &v, T z = T()) : x(v.x), y(v.y), z(z)
        {
        }
        
        ~vector4()
        {
        }
        
        inline T &operator [] (unsigned int i)
        {
            return *(&x + i);
        }

        inline const T &operator [] (unsigned int i) const
        {
            return *(&x + i);
        }

        inline T &operator () (unsigned int i)
        {
            return *(&x + i);
        }

        inline const T &operator () (unsigned int i) const
        {
            return *(&x + i);
        }

        inline operator T * ()
        {
            return &x;
        }

        inline operator const T * () const
        {
            return &x;
        }

        inline vector4<T> &set(T n = T())
        {
            x = n;
            y = n;
            z = n;
            w = n;
            return *this;
        }

        inline vector4<T> &set(T x, T y, T z, T w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
            return *this;
        }

        inline vector4<T> &set(T *a)
        {
            x = a[0];
            y = a[1];
            z = a[2];
            w = a[3];
            return *this;
        }

        inline vector4<T> &operator += (T n)
        {
            x += n;
            y += n;
            z += n;
            w += n;
            return *this;
        }

        inline vector4<T> &operator += (const vector4<T> &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            return *this;
        }
        
        inline vector4<T> operator + (const vector4<T> &v) const 
        {
            return vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
        }

        inline vector4<T> operator + (const T n) const
        {
            return vector4<T>(x + n, y + n, z + n, w + n);
        }

        friend inline vector4<T> operator + (const T n, const vector4<T> &v)
        {
            return vector4<T>(n + v.x, n + v.y, n + v.z, n + v.w);
        }
        
        inline vector4<T> &operator -= (T n)
        {
            x -= n;
            y -= n;
            z -= n;
            w -= n;
            return *this;
        }

        inline vector4<T> &operator -= (const vector4<T> &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            w -= v.w;
            return *this;
        }

        inline vector4<T> operator - (const vector4<T> &v) const 
        {
            return vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
        }

        inline vector4<T> operator - (const T n) const
        {
            return vector4<T>(x - n, y - n, z - n, w - n);
        }

        friend inline vector4<T> operator - (const T n, const vector4<T> &v)
        {
            return vector2<T>(n - v.x, n - v.y, n - v.z, n - v.w);
        }
        
        inline vector4<T> &operator *= (T n)
        {
            x *= n;
            y *= n;
            z *= n;
            w *= n;
            return *this;
        }

        inline vector4<T> &operator *= (const vector4<T> &v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            w *= v.w;
            return *this;
        }
        
        inline vector4<T> operator * (const vector4<T> &v) const 
        {
            return vector4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
        }

        inline vector4<T> operator * (const T n) const
        {
            return vector4<T>(x * n, y * n, z * n, w * n);
        }

        friend inline vector4<T> operator * (const T n, const vector4<T> &v)
        {
            return vector4<T>(n * v.x, n * v.y, n * v.z, n * v.w);
        }

        inline vector4<T> &operator /= (T n)
        {
            x /= n;
            y /= n;
            z /= n;
            w /= n;
            return *this;
        }

        inline vector4<T> &operator /= (const vector4<T> &v)
        {
            x /= v.x;
            y /= v.y;
            z /= v.z;
            w /= v.w;
            return *this;
        }
        
        inline vector4<T> operator / (const vector4<T> &v) const 
        {
            return vector4<T>(x / v.x, y / v.y, z / v.z, w / v.w);
        }
        
        inline vector4<T> operator / (const T n) const
        {
            return vector4<T>(x / n, y / n, z / n, w / n);
        }

        friend inline vector4<T> operator / (const T n, const vector4<T> &v)
        {
            return vector4<T>(n / v.x, n / v.y, n / v.z, n / v.w);
        }
        
        inline bool operator == (const vector4<T> &v) const
        {
            return x == v.x && y == v.y && z == v.z && w == v.w;
        }

        inline bool operator != (const vector4<T> &v) const
        {
            return x != v.x || y != v.y || z != v.z || w != v.w;
        }

        friend inline T dot(const vector4<T> &v1, const vector4<T> &v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
        }
        
        inline const T length() const
        {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        inline vector4<T> normalize() const
        {
            T len = length();
            return vector4<T>(x / len, y / len, z / len, w / len);
        }

        friend inline std::ostream &operator << (std::ostream &s, const vector4<T> &v) 
        {
            return s << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
        }
     
    };

    typedef vector4<float> vector4f;
    typedef vector4<double> vector4d;
    typedef vector4<long double> vector4ld;
}

#endif
