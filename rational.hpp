// COPYRIGHT (C) 2017 Xiaofeng Qu (xq6) All rights reserved.
//
// rational.hpp: Definition of rational class and its interface.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>


// Mathematical helper functions.
//
// NOTE: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{
  private:
    int numerator;
    int denominator;

  public:
  // TODO: Define the following:
  // 1. A default constructor
    Rational();
  // 2. A constructor that takes an integer value
    Rational(int );
  // 3. A constructor that takes a pair of values
    Rational(int ,int );

  public:
      // Returns the numerator.
      int num() const { /* TODO: Implement me. */ return numerator; }

      // Returns the denominator
      int den() const { /* TODO: Implement me. */ return denominator; }

};


// TODO: Implement support for
// 1. Comparing two rational numbers for equality:
//    - r1 == t2
bool operator==(const Rational r1, const Rational r2); // Accept two Rationals
bool operator==(int p, const Rational r2); // Accept one int and one Rational
bool operator==(const Rational r1, int q); // Accept one rational and one int
//    - r1 != r2
bool operator!=(const Rational r1, const Rational r2); // Accept two Rationals
bool operator!=(int p, const Rational r2); // Accept one int and one Rational
bool operator!=(const Rational r1, int q); // Accept one rational and one int
// 2. Ordering rational numbers
//    - r1 < r2
bool operator<(const Rational r1, const Rational r2); // Accept two Rationals
bool operator<(int p, const Rational r2); // Accept one int and one Rational
bool operator<(const Rational r1, int q); // Accept one rational and one int
//    - r1 > r2
bool operator>(const Rational r1, const Rational r2); // Accept two Rationals
bool operator>(int p, const Rational r2); // Accept one int and one Rational
bool operator>(const Rational r1, int q); // Accept one rational and one int
//    - r1 <= r2
bool operator<=(const Rational r1, const Rational r2); // Accept two Rationals
bool operator<=(int p, const Rational r2); // Accept one int and one Rational
bool operator<=(const Rational r1, int q); // Accept one rational and one int
//    - r1 >= r2
bool operator>=(const Rational r1, const Rational r2); // Accept two Rationals
bool operator>=(int p, const Rational r2); // Accept one int and one Rational
bool operator>=(const Rational r1, int q); // Accept one rational and one int
// 3. The standard arithmetic operators
//    - r1 + r2
Rational operator+(const Rational r1, const Rational r2); // Accept two Rationals
Rational operator+(int p, const Rational r2); // Accept one int and one Rational
Rational operator+(const Rational r1, int q); // Accept one rational and one int
//    - r1 - r2
Rational operator-(const Rational r1, const Rational r2); // Accept two Rationals
Rational operator-(int p, const Rational r2); // Accept one int and one Rational
Rational operator-(const Rational r1, int q); // Accept one rational and one int
//    - r1 * r2
Rational operator*(const Rational r1, const Rational r2); // Accept two Rationals
Rational operator*(int p, const Rational r2); // Accept one int and one Rational
Rational operator*(const Rational r1, int q); // Accept one rational and one int
//    - r1 / r2
Rational operator/(const Rational r1, const Rational r2); // Accept two Rationals
Rational operator/(int p, const Rational r2); // Accept one int and one Rational
Rational operator/(const Rational r1, int q); // Accept one rational and one int
// These are provided for you.
//
// NOTE: They are defined in rational.cpp.
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
