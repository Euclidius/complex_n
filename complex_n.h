//
// Created by evarist on 08.09.23.
//
#ifndef COMPLEX_N_H
#define COMPLEX_N_H

#include <cmath>
#include <iostream>

class Complex_n {
public:

    Complex_n(double re_ = 0, double im_ = 0) : re(re_), im(im_) {};
    double get_re() const { return re; }
    double get_im() const { return im; }

    Complex_n &operator+=(const Complex_n &c);
    Complex_n &operator-=(const Complex_n &c);
    Complex_n &operator*=(const Complex_n &c);
    Complex_n &operator/=(const Complex_n &c);

    Complex_n operator/(double d) const;
    Complex_n operator*(double d) const;
    Complex_n operator+(double d) const;
    Complex_n operator-(double d) const;

    friend Complex_n operator/(double d, Complex_n &c);
    friend Complex_n operator*(double d, Complex_n &c);
    friend Complex_n operator-(double d, Complex_n &c);
    friend Complex_n operator+(double d, Complex_n &c);

    friend Complex_n operator/(Complex_n &a, Complex_n &d);
    friend Complex_n operator*(Complex_n &a, Complex_n &d);
    friend Complex_n operator-(Complex_n &a, Complex_n &d);
    friend Complex_n operator+(Complex_n &a, Complex_n &d);

    bool operator==(Complex_n &a) const;
    bool operator!=(Complex_n &a) const;

    friend bool operator==(double d, Complex_n &a) { return (d == a.re && a.im == 0); }
    friend bool operator!=(double d, Complex_n &a) { return !(a == d); }

    friend bool operator==(Complex_n &a, double d) { return (d == a.re && a.im == 0); }
    friend bool operator!=(Complex_n &a, double d) { return !(a == d); }

    const Complex_n &operator+() const { return *this; }
    Complex_n operator-() const { return {-re, -im}; }

    Complex_n conjugate() const;
    double cabs() const;

    friend std::ostream &operator<<(std::ostream &stream, const Complex_n &c);
    friend std::istream &operator>>(std::istream &stream, Complex_n &c);

private:
    double re, im;
};


#endif
