//
// Created by evarist on 08.09.23.
//

#include "complex_n.h"
#include <cmath>
#include <iostream>



Complex_n Complex_n::operator/(double d) const {
    return {re / d, im / d};
}


Complex_n Complex_n::operator*(double d) const {
    return {re * d, im * d};
}


Complex_n Complex_n::operator+(double d) const {
    return {re + d, im};
}


Complex_n Complex_n::operator-(double d) const {
    return {re - d, im};
}


Complex_n &Complex_n::operator/=(const Complex_n &c) {
    double a = c.cabs();
    double re_tmp = re;
    double im_tmp = im;
    re = (re_tmp * c.re + im_tmp * c.im) / a / a;
    im = (im_tmp * c.re - c.im * re_tmp) / a / a;
    return *this;
}

Complex_n &Complex_n::operator+=(const Complex_n &c) {
    re += c.re;
    im += c.im;
    return *this;
}

Complex_n &Complex_n::operator-=(const Complex_n &c) {
    re -= c.re;
    im -= c.im;
    return *this;
}


Complex_n &Complex_n::operator*=(const Complex_n &c) {
    double re_tmp = re;
    double im_tmp = im;
    re = re_tmp * c.re - im_tmp * c.im;
    im = im_tmp * c.re + c.im * re_tmp;
    return *this;
}


Complex_n Complex_n::conjugate() const {
    return {re, -im};
}


double Complex_n::cabs() const {
    return sqrt(re * re + im * im);
}


std::ostream &operator<<(std::ostream &stream, const Complex_n &c) {
    if (c.im > 0)
        return (stream << c.re << " + " << c.im << 'i');
    else if (c.im < 0)
        return (stream << c.re << " - " << -c.im << 'i');
    return (stream << c.re);
}


std::istream &operator>>(std::istream &stream, Complex_n &c) {
    return (stream >> c.re >> c.im);
}


Complex_n operator/(Complex_n &a, Complex_n &d) {
    double b = d.cabs();
    return {(a.get_re() * d.get_re() + a.get_im() * d.get_im()) / b / b,
            (a.get_im() * d.get_re() - d.get_im() * a.get_re()) / b / b};
}


Complex_n operator*(Complex_n &a, Complex_n &d) {
    return {a.get_re() * d.get_re() - a.get_im() * d.get_im(), a.get_re() * d.get_im() + d.get_re() * a.get_im()};
}


Complex_n operator+(Complex_n &a, Complex_n &d) {
    return {a.get_re() + d.get_re(), a.get_im() + d.get_im()};
}


Complex_n operator-(Complex_n &a, Complex_n &d) {
    return {a.get_re() - d.get_re(), a.get_im() - d.get_im()};
}


bool Complex_n::operator==(Complex_n &a) const {
    return (re == a.re && im == a.im);
}


bool Complex_n::operator!=(Complex_n &a) const {
    return (re != a.re || im != a.im);
}


Complex_n operator/(double d, Complex_n &c) {
    double a = c.cabs();
    return c.conjugate() * d / a / a;
}


Complex_n operator*(double d, Complex_n &c) {
    return {c.re * d, c.im * d};
}

Complex_n operator+(double d, Complex_n &c) {
    return {c.re + d, c.im};
}

Complex_n operator-(double d, Complex_n &c) {
    return {d - c.re, -c.im};
}