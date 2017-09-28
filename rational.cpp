// COPYRIGHT (C) 2017 Xiaofeng Qu (xq6) All rights reserved.
//
// rational.hpp: Definition of rational class and its interace.

#include "rational.hpp"

#include <iostream>


// -------------------------------------------------------------------------- //
// Helper functions

// Compute the GCD (greatest common divider) of two integer values using Euclid's algorithm.
int
gcd(int a, int b)
{
  a = abs(a);   //make them to be positive numbers
  b = abs(b);
  if(a==0 || b==0){ //if one number is 0, always return 1
    return 1;
  }
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}


// Compute the LCM (Least Common Multiple) of two integer values.
int
lcm(int a, int b)
{
  a = abs(a); //make them positive
  b = abs(b);
  if(a == 0 || b == 0){
    throw "Integers can not be zero in calculating Least Common Multiple";
  }
  return (abs(a) / gcd(a, b)) * abs(b);
}


// -------------------------------------------------------------------------- //
// Rational implementation
// 1. A default constructor sets numerator equal to 0 and denominator equal to 1
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
// 2. A constructor takes an integer and sets numerator equal to p
// and denominator equal to 1
Rational::Rational(int p)
{
    numerator = p;
    denominator = 1;
}
// 3. A constructor takes two integers, p as numerator and q as denominator
// verifies that q is not equal to 0, and normalizes the rational number
Rational::Rational(int p, int q)
{
    int gcDiv = gcd(p, q); // Greatest common divider of p & q

    if (q == 0)
    {
        std::cout << "The denominator cannot be 0. Initial the rational number to 0." << std::endl;
        numerator = 0;
        denominator = 1;
    }
    if (q < 0)
    {
        numerator = -p / gcDiv;
        denominator = -q / gcDiv;
    }
    else
    {
        numerator = p / gcd(p, q);
        denominator = q / gcd(p, q);
    }
}

// TODO: Implement support for
// 1. Compare
//    - r1 == t2
// 1) Compare two rational numbers
bool operator==(const Rational r1, const Rational r2)
{
    if (r1.num() == 0 && r2.num() == 0)
        return true;
    if (r1.num() == r2.num() && r1.den() == r2.den())
        return true;
    else
        return false;
}
// 2) Compare an integer with a rational number
bool operator==(int p, const Rational r2)
{
    Rational r1(p);
    if (r1.num() == 0 && r2.num() == 0)
        return true;
    return r1.num() == r2.num() && r1.den() == r2.den();
}
// 3) Compare a rational number with an integer
bool operator==(const Rational r1, int q)
{
    Rational r2(q);
    if (r1.num() == 0 && r2.num() == 0)
        return true;
    return r1.num() == r2.num() && r1.den() == r2.den();
}
//    - r1 != r2
// 1) Compare two rational numbers
bool operator!=(const Rational r1, const Rational r2)
{
    return !(r1 == r2);
}
// 2) Compare an integer with a rational number
bool operator!=(int p, const Rational r2)
{
    Rational r1(p);
    return !(r1 == r2);
}
// 3) Compare a rational number with an integer
bool operator!=(const Rational r1, int q)
{
    Rational r2(q);
    return !(r1 == r2);
}
// 2. Ordering
//    - r1 < r2
// 1) Compare two rational numbers
bool operator<(const Rational r1, const Rational r2)
{
    int lcMult = lcm(r1.den(), r2.den()); // Least common multiple of
                                          // the denominators of the two Rational number
    if (r1.num() * lcMult / r1.den() < r2.num() * lcMult / r2.den())
        return true;
    else
        return false;
}
// 2) Compare an integer with a rational number
bool operator<(int p, const Rational r2)
{
    if (p * r2.den() < r2.num())
        return true;
    else
        return false;
}
// 3) Compare a rational number with an integer
bool operator<(const Rational r1, int q)
{
    if (r1.num() < q * r1.den())
        return true;
    else
        return false;
}
//    - r1 > r2
// 1) Compare two rational numbers
bool operator>(const Rational r1, const Rational r2)
{
    int lcMult = lcm(r1.den(), r2.den()); // Least common multiple of
                                          // the denominators of the two Rational number
    if (r1.num() * lcMult / r1.den() > r2.num() * lcMult / r2.den())
        return true;
    else
        return false;
}
// 2) Compare an integer with a rational number
bool operator>(int p, const Rational r2)
{
    if (p * r2.den() > r2.num())
        return true;
    else
        return false;
}
// 3) Compare a rational number with an integer
bool operator>(const Rational r1, int q)
{
    if (r1.num() > q * r1.den())
        return true;
    else
        return false;
}
//    - r1 <= r2
// 1) Compare two rational numbers
bool operator<=(const Rational r1, const Rational r2)
{
    if (r1 < r2 || r1 == r2)
        return true;
    else
        return false;
}
// 2) Compare an integer with a rational number
bool operator<=(int p, const Rational r2)
{
    if (p < r2 || p == r2)
        return true;
    else
        return false;
}
// 3) Compare a rational number with an integer
bool operator<=(const Rational r1, int q)
{
    if (r1 < q || r1 == q)
        return true;
    else
        return false;
}
//    - r1 >= r2
// 1) Compare two rational numbers
bool operator>=(const Rational r1, const Rational r2)
{
    if (r1 > r2 || r1 == r2)
        return true;
    else
        return false;
}
// 2) Compare an integer with a rational number
bool operator>=(int p, const Rational r2)
{
    if (p > r2 || p == r2)
        return true;
    else
        return false;
}
// 3) Compare a rational number with an integer
bool operator>=(const Rational r1, int q)
{
    if (r1 > q || r1 == q)
        return true;
    else
        return false;
}
// 3. The standard arithmetic operators
//    - r1 + r2
// Add two rational numbers
Rational operator+(const Rational r1, const Rational r2)
{
    int lcMult = lcm(r1.den(), r2.den()); // Least common multiple of
                                          // the denominators of the two Rational number
    Rational temp((r1.num() * lcMult / r1.den() + r2.num() * lcMult / r2.den()), lcMult); // create a temperate Rational number
    return temp;
}
// An integer adds a rational number
Rational operator+(int p, const Rational r2)
{
    Rational temp((p * r2.den() + r2.num()), r2.den()); // create a temperate Rational number
    return temp;
}
// A rational number adds an integer
Rational operator+(const Rational r1, int q)
{
    Rational temp((r1.num() + q * r1.den()), r1.den()); // create a temperate Rational number
    return temp;
}
//    - r1 - r2
// A rational number minus a rational number
Rational operator-(const Rational r1, const Rational r2)
{
    int lcMult = lcm(r1.den(), r2.den()); // Least common multiple of
                                          // the denominators of the two Rational number
    Rational temp((r1.num() * lcMult / r1.den() - r2.num() * lcMult / r2.den()), lcMult); // create a temperate Rational number
    return temp;
}
// An integer minus a rational number
Rational operator-(int p, const Rational r2)
{
    Rational temp((p * r2.den() - r2.num()), r2.den()); // create a temperate Rational number
    return temp;
}
// A rational number minus an integer
Rational operator-(const Rational r1, int q)
{
    Rational temp((r1.num() - q * r1.den()), r1.den()); // create a temperate Rational number
    return temp;
}
//    - r1 * r2
// A rational number times a rational number
Rational operator*(const Rational r1, const Rational r2)
{
    Rational temp(r1.num() * r2.num(), r1.den() * r2.den());
    return temp;
}
// An integer times a rational number
Rational operator*(int p, const Rational r2)
{
    Rational temp(p * r2.num(), r2.den());
    return temp;
}
// A rational number times an integer
Rational operator*(const Rational r1, int q)
{
    Rational temp(r1.num() * q, r1.den());
    return temp;
}
//    - r1 / r2
// A rational number divided by a rational number
Rational operator/(const Rational r1, const Rational r2)
{
    Rational temp((r1.num() * r2.den()), (r1.den() * r2.num()));
    return temp;
}
// An integer divided by a rational number
Rational operator/(int p, const Rational r2)
{
    Rational temp((p * r2.den()), r2.num());
    return temp;
}
// A rational number divided by an integer
Rational operator/(const Rational r1, int q)
{
    Rational temp(r1.num(), (r1.den() * q));
    return temp;
}
//DO NOT CHANGE operators << and >> overloading functions
std::ostream&
operator<<(std::ostream& os, Rational r)
{
  if (r.den() == 1){
    return os << r.num();
  }
  else {
    return os << r.num() << '/' << r.den();
  }

}

std::istream&
operator>>(std::istream& is, Rational& r)
{
  // Read the first integer, return on error.
  int p;
  is >> p;
  if (!is)
    return is;

  // Check for the divider. Assuming no spaces.
  if (is.peek() != '/') {
    r = Rational(p);
    return is;
  }
  is.get();

  int q;
  is >> q;
  if (!is)
    return is;
  if (q == 0) {
    is.setstate(std::ios::failbit);
    return is;
  }
  r = Rational(p, q);
  return is;
#if 0
  int p, q;
  char c;
  is >> p >> c >> q;
  if (!is)
    return is;
  // Require that the divider to be a '/'.
  if (c != '/') {
    is.setstate(std::ios::failbit);
    return is;
  }

  // Make sure that we didn't read p/0.

  r = Rational(p, q);
  return is;
#endif
}
