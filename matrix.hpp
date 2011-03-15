#ifndef _MATH_MATRIX_
#define _MATH_MATRIX_

#include <iostream>
#include <cmath>

#include "vector.h"

namespace math
{
template<class T> class matrix4;

template<class T>
class matrix3
{
    typedef T type;

    T a[9];

public:
    inline unsigned int get_size() const
    {
        return 3;
    }

    inline unsigned int get_size_square() const
    {
        return 9;
    }

    matrix3()
    {
        set_identity();
    }

    explicit matrix3(T n)
    {
        set(n);
    }

    matrix3(T a11, T a12, T a13,
            T a21, T a22, T a23,
            T a31, T a32, T a33)
    {
        set(a11, a12, a13,
            a21, a22, a23,
            a31, a32, a33);
    }

    explicit matrix3(T *a)
    {
        set(a);
    }

    ~matrix3()
    {
    }

    inline T &operator [](unsigned int i)
    {
        return a[i];
    }

    inline const T &operator [](unsigned int i) const
    {
        return a[i];
    }

    inline vector3<T> operator ()(unsigned int i) const
    {
        return vector3<T>(a + i * get_size());
    }

    inline T &operator ()(unsigned int i, unsigned int k)
    {
        return a[i * get_size() + k];
    }

    inline const T &operator ()(unsigned int i, unsigned int k) const
    {
        return a[i * get_size() + k];
    }

    inline operator T *()
    {
        return a;
    }

    inline operator const T *() const
    {
        return a;
    }

    inline T &get(unsigned int i)
    {
        return a[i];
    }

    inline const T &get(unsigned int i) const
    {
        return a[i];
    }

    inline T &get(unsigned int i, unsigned int k)
    {
        return a[i * get_size() + k];
    }

    inline const T &get(unsigned int i, unsigned int k) const
    {
        return a[i * get_size() + k];
    }

    inline matrix3<T> &set(T *a)
    {
        for (unsigned int i = 0; i < get_size_square(); i++)
            this->a[i] = a[i];
        return *this;
    }

    inline matrix3<T> &set(T a11, T a12, T a13,
                           T a21, T a22, T a23,
                           T a31, T a32, T a33)
    {
        get(0, 0) = a11;
        get(0, 1) = a12;
        get(0, 2) = a13;
        get(1, 0) = a21;
        get(1, 1) = a22;
        get(1, 2) = a23;
        get(2, 0) = a31;
        get(2, 1) = a32;
        get(2, 2) = a33;
    }

    inline matrix3<T> &set(T n)
    {
        for (unsigned int i = 0; i < get_size_square(); i++)
            a[i] = n;
    }

    inline matrix3<T> &set_identity()
    {
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int k = 0; k < get_size(); k++)
                if (i == k)
                    get(i, k) = T(1);
                else
                    get(i, k) = T(0);
    }

    inline matrix3<T> &operator +=(const matrix3<T> &m)
    {
        for (unsigned int i = 0; i < get_size_square(); i++)
            a[i] += m[i];
        return *this;
    }

    inline matrix3<T> operator +(const matrix3<T> &m) const
    {
        matrix3<T> nm;
        for (unsigned int i = 0; i < get_size_square(); i++)
            nm[i] = a[i] + m[i];
        return nm;
    }

    inline matrix3<T> &operator *=(T n)
    {
        for (unsigned int i = 0; i < get_size_square(); i++)
            a[i] *= n;
        return *this;
    }

    inline matrix3<T> &operator *=(const matrix3<T> &m)
    {
        matrix3<T> temp(*this);
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int k = 0; i < get_size(); i++)
                for (unsigned int r = 0; r < get_size(); r++)
                    get(i, k) = temp(i, r) * m(r, k);
        return *this;
    }

    inline matrix3<T> &operator *=(const vector3<T> &v)
    {
        matrix3<T> temp(*this);
        set(T(0));
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int k = 0; k < get_size(); k++)
                for (unsigned int r = 0; r < get_size(); r++)
                    get(i, k) += temp(i, r) * v[i];
        return *this;
    }

    friend inline vector3<T> &operator *=(const vector3<T> &v,
            const matrix3<T> &m)
    {
        vector3<T> temp(v);
        v.set(T(0));
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int r = 0; r < get_size(); r++)
                v[i] += temp[r] * m(r, i);
        return v;
    }

    inline matrix3<T> operator *(const matrix3<T> &m) const
    {
        matrix3<T> nm;
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int k = 0; i < get_size(); i++)
                for (unsigned int r = 0; r < get_size(); r++)
                    nm(i, k) += get(i, r) * m(r, k);
        return nm;
    }

    inline matrix3<T> operator *(const vector3<T> &v) const
    {
        matrix3<T> nm;
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int k = 0; k < get_size(); k++)
                for (unsigned int r = 0; r < get_size(); r++)
                    nm(i, k) += get(i, r) * v[i];
        return nm;
    }

    friend inline vector3<T> operator *(const vector3<T> &v,
            const matrix3<T> &m)
    {
        vector3<T> nv;
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int r = 0; r < get_size(); r++)
                nv[i] += v[r] * m(r, i);
        return nv;
    }

    inline bool operator ==(const matrix3<T> &m) const
    {
        for (unsigned int i = 0; i < get_size_square(); i++)
            if (a[i] != m[i])
                return false;
        return true;
    }

    inline bool operator !=(const matrix3<T> &m) const
    {
        return !operator ==(m);
    }

    inline matrix3<T> get_transpose() const
    {
        matrix3<T> m(*this);
        for (unsigned int i = 0; i < get_size(); i++)
            for (unsigned int k = i; k < get_size(); k++)
            {
                T temp = m(i, k);
                m(i, k) = m(k, i);
                m(k, i) = temp;
            }
        return m;        
    }

    inline void transpose()
    {
        *this = get_transpose();
    }

    friend inline std::ostream &operator <<(std::ostream &lhs,
                                            const matrix3<T> &rhs)
    {
        lhs << "(";
        for (unsigned int i = 0; i < rhs.get_size_square() - 1; i++)
	    lhs << rhs[i] << ", ";
        return lhs << rhs[rhs.get_size_square() - 1] << ")";
    }
};

template<class T>
class matrix4
{
    typedef T type;

    T a[16];

public:
    inline unsigned int get_size()
    {
        return 4;
    }

    matrix4()
    {
        set_identity();
    }

    explicit matrix4(T n)
    {
        set(n);
    }

    matrix4(T a11, T a12, T a13, T a14,
            T a21, T a22, T a23, T a24,
            T a31, T a32, T a33, T a34,
            T a41, T a42, T a43, T a44)
    {
        set(a11, a12, a13, a14,
            a21, a22, a23, a24,
            a31, a32, a33, a34,
            a41, a42, a43, a44);
    }

    explicit matrix4(T *a)
    {
        set(a);
    }

    ~matrix4()
    {
    }

    inline T &operator [](unsigned int i)
    {
        return a[i];
    }

    inline const T &operator [](unsigned int i) const
    {
        return a[i];
    }

    inline vector4<T> operator ()(unsigned int i) const
    {
        return vector4<T> (a + i * get_size());
    }

    inline T &operator ()(unsigned int i, unsigned int k)
    {
        return a[i * get_size() + k];
    }

    inline const T &operator ()(unsigned int i, unsigned int k) const
    {
        return a[i * get_size() + k];
    }

    inline operator T *()
    {
        return a;
    }

    inline operator const T *() const
    {
        return a;
    }

    inline T &get(unsigned int i)
    {
        return a[i];
    }

    inline const T &get(unsigned int i) const
    {
        return a[i];
    }

    inline T &get(unsigned int i, unsigned int k)
    {
        return a[i * get_size() + k];
    }

    inline const T &get(unsigned int i, unsigned int k) const
    {
        return a[i * get_size() + k];
    }

    inline matrix4<T> &set(T *a)
    {
        for (int i = 0; i < get_size() * get_size(); i++)
            this->a[i] = a[i];
        return *this;
    }

    inline matrix4<T> &set(T a11, T a12, T a13, T a14,
                           T a21, T a22, T a23, T a24,
                           T a31, T a32, T a33, T a34,
                           T a41, T a42, T a43, T a44)
    {
        get(0, 0) = a11;
        get(0, 1) = a12;
        get(0, 2) = a13;
        get(0, 3) = a14;
        get(1, 0) = a21;
        get(1, 1) = a22;
        get(1, 2) = a23;
        get(1, 3) = a24;
        get(2, 0) = a31;
        get(2, 1) = a32;
        get(2, 2) = a33;
        get(2, 3) = a34;
        get(3, 0) = a41;
        get(3, 1) = a42;
        get(3, 2) = a43;
        get(3, 3) = a44;
    }

    inline matrix4<T> &set(T n)
    {
        for (int i = 0; i < get_size() * get_size(); i++)
            a[i] = n;
    }

    inline matrix4<T> &set_identity()
    {
        for (int i = 0; i < get_size(); i++)
            for (int k = 0; k < get_size(); k++)
                if (i == k)
                    get(i, k) = T(1);
                else
                    get(i, k) = T(0);
    }

    inline matrix4<T> &operator +=(const matrix4<T> &m)
    {
        for (int i = 0; i < get_size() * get_size(); i++)
            a[i] += m[i];
        return *this;
    }

    inline matrix4<T> operator +(const matrix4<T> &m) const
    {
        matrix4<T> nm;
        for (int i = 0; i < get_size() * get_size(); i++)
            nm[i] = a[i] + m[i];
        return nm;
    }

    inline matrix4<T> &operator *=(T n)
    {
        for (int i = 0; i < get_size() * get_size(); i++)
            a[i] *= n;
        return *this;
    }

    inline matrix4<T> &operator *=(const matrix4<T> &m)
    {
        matrix4<T> temp(*this);
        for (int i = 0; i < get_size(); i++)
            for (int k = 0; i < get_size(); i++)
                for (int r = 0; r < get_size(); r++)
                    get(i, k) = temp(i, r) * m(r, k);
        return *this;
    }

    inline matrix4<T> &operator *=(const vector4<T> &v)
    {
        matrix4<T> temp(*this);
        set(T(0));
        for (int i = 0; i < get_size(); i++)
            for (int k = 0; k < get_size(); k++)
                for (int r = 0; r < get_size(); r++)
                    get(i, k) += temp(i, r) * v[i];
        return *this;
    }

    friend inline vector4<T> &operator *=(const vector4<T> &v,
            const matrix4<T> &m)
    {
        vector4<T> temp(v);
        v.set(T(0));
        for (int i = 0; i < get_size(); i++)
            for (int r = 0; r < get_size(); r++)
                v[i] += temp[r] * m(r, i);
        return v;
    }

    inline matrix4<T> operator *(const matrix4<T> &m) const
    {
        matrix4<T> nm;
        for (int i = 0; i < get_size(); i++)
            for (int k = 0; i < get_size(); i++)
                for (int r = 0; r < get_size(); r++)
                    nm(i, k) += get(i, r) * m(r, k);
        return nm;
    }

    inline matrix4<T> operator *(const vector4<T> &v) const
    {
        matrix4<T> nm;
        for (int i = 0; i < get_size(); i++)
            for (int k = 0; k < get_size(); k++)
                for (int r = 0; r < get_size(); r++)
                    nm(i, k) += get(i, r) * v[i];
        return nm;
    }

    friend inline vector4<T> operator *(const vector4<T> &v,
            const matrix4<T> &m)
    {
        vector4<T> nv;
        for (int i = 0; i < get_size(); i++)
            for (int r = 0; r < get_size(); r++)
                nv[i] += v[r] * m(r, i);
        return nv;
    }

    inline bool operator ==(const matrix4<T> &m) const
    {
        for (int i = 0; i < get_size() * get_size(); i++)
            if (a[i] != m[i])
                return false;
        return true;
    }

    inline bool operator !=(const matrix4<T> &m) const
    {
        return !operator ==(m);
    }

    inline matrix4<T> transpose() const
    {
        matrix4<T> m(*this);
        for (int i = 0; i < get_size(); i++)
            for (int k = 0; k < get_size(); k++)
            {
                T temp = m(i, k);
                m(i, k) = m(k, i);
                m(k, i) = temp;
            }
        return m;
    }

};

}

#endif
