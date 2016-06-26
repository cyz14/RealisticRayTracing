// Orthonormal Basis Class
#ifndef _ONB_H_
#define _ONB_H_ 1

#include "Vector3.h"
#include <iostream>
using namespace std;

class ONB
{
public:
    ONB() {}
    ONB(const Vector3& a, const Vector3& b, const Vector3& c)
    { U = a; V = b; W = c; }

    void initFromU(const Vector3& u);
    void initFromV(const Vector3& v);
    void initFromW(const Vector3& w);

    void set(const Vector3& a, const Vector3& b, const Vector3& c)
    { U = a; V = b; W = c; }

    // Calculate the ONB from two vectors
    // The first one is the Fixed vector
    // The second is normalized and its direction can be adjusted
    void initFromUV(const Vector3& u, const Vector3& v);
    void initFromVU(const Vector3& v, const Vector3& u);

    void initFromUW(const Vector3& u, const Vector3& w);
    void initFromWU(const Vector3& w, const Vector3& u);

    void initFromVW(const Vector3& v, const Vector3& w);
    void initFromWV(const Vector3& w, const Vector3& v);

    friend istream& operator>>(istream& in, ONB & t);
    friend ostream& operator<<(ostream& out, const ONB & t);
    friend bool operator==(const ONB& o1, const ONB& o2);

    //Get a component from the ONB basis
    Vector3 u() const { return U; }
    Vector3 v() const { return V; }
    Vector3 w() const { return W; }

    Vector3 U, V, W;
};

#endif