#ifndef _RACIONAL_HPP
#define _RACIONAL_HPP
#include <stdexcept>
#include <iostream>
using namespace std;

class Racional{
private:
  int numerador;
  int denominador;
  int gdc(int num, int den);
  void simplify();
public:
  Racional(){};
  Racional(int n, int d);
  ~Racional(){};

  int get_numerador();
  int get_denominador();
  void mod_numerador(int n);
  void mod_denominador(int d);
  friend ostream& operator<<(ostream& os, const Racional& r);
  friend istream& operator>>(istream& is, Racional& r);
  friend Racional operator*(int a, Racional r);
  friend Racional operator*(Racional r, int a);
  friend bool operator==(Racional r, int a);
  friend bool operator!=(Racional r, int a);
  Racional& operator=(Racional& r);
  Racional& operator+=(Racional& r);
  // Racional& operator-=(Racional& r);
  // Racional& operator*=(Racional& r);
  // Racional& operator/=(Racional& r);
  Racional operator+(Racional& r);
  Racional operator-(Racional& r);
  Racional operator*(Racional& r);
  Racional operator/(Racional& r);
  bool operator==(Racional& r);
  bool operator>(Racional& r);
  bool operator<(Racional& r);
  bool operator>=(Racional& r);
  bool operator<=(Racional& r);
  bool operator!=(Racional& r);
};

#endif
