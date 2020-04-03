#include "racional.hpp"
using namespace std;

Racional::Racional(int n, int d){
  if(d == 0){
    throw runtime_error("Racional: denominador no puede ser 0");
  }
  numerador = n;
  denominador = d;
  simplify();
}

int Racional::gdc(int num, int den){
  long gcd, tmp, rest;
  gcd = abs(num);
  tmp = den;
  while(tmp>0){
    rest = gcd % tmp;
    gcd = tmp;
    tmp = rest;
  }
  return gcd;  
}

void Racional::simplify(){
  int g = gdc(numerador, denominador);
  mod_numerador(numerador/g);
  mod_denominador(denominador/g);
}

int Racional::get_numerador(){
  return numerador;
}

int Racional::get_denominador(){
  return denominador;
}

void Racional::mod_numerador(int n){
  numerador = n;
}

void Racional::mod_denominador(int d){
  denominador = d;
}

ostream& operator<<(ostream& os,const Racional& r){
  if(r.denominador != 1){
    os << r.numerador << "/" << r.denominador;
  }else{
    os << r.numerador;
  }
  return os;
}

istream& operator>>(istream& is, Racional& r){
  int n, d;
  is >> n;
  r.mod_numerador(n);
  is.ignore();
  is >> d;
  if(d == 0){
    throw runtime_error("Racional: denominador no puede ser 0");
  }
  r.mod_denominador(d);
  r.simplify();
  return is;
}

bool operator==(Racional r, int a){
  if(r.denominador == 1){
    if(r.numerador == a){
      return true;
    }
  }else{
    return false;
  }
}

bool operator!=(Racional r, int a){
  if(r.denominador != 1){
    return true;
  }else{
    if(r.numerador == a){
      return false;
    }
  }
}

Racional& Racional::operator+=(Racional& r){
  this -> numerador = numerador*r.denominador + r.numerador * denominador;
  this -> denominador = denominador * r.denominador;
  this -> simplify();
  return *this;
}

Racional operator*(int a, Racional r){
  Racional s;
  s.numerador = a * r.numerador;
  s.denominador = r.denominador;
  s.simplify();
  return s;
}

Racional operator*(Racional r, int a){
  Racional s;
  s.numerador = a * r.numerador;
  s.denominador = r.denominador;
  s.simplify();
  return s;
}

Racional& Racional::operator=(Racional& r){
  numerador = r.numerador;
  denominador = r.denominador;
  simplify();
  return r;
}

Racional Racional::operator+(Racional& r){
  Racional s;
  if(denominador == r.denominador){
    s.denominador = r.denominador;
    s.numerador = numerador + r.numerador;
  }
  else{
    s.denominador = denominador * r.denominador;
    s.numerador = numerador * r.denominador + r.numerador * denominador;
  }
  s.simplify();
  return s;
}

Racional Racional::operator-(Racional& r){
  Racional s;
  if(denominador == r.denominador){
    s.denominador = r.denominador;
    s.numerador = numerador - r.numerador;
  }
  else{
    s.denominador = denominador * r.denominador;
    s.numerador = numerador * r.denominador - r.numerador * denominador;
  }
  s.simplify();
  return s;
}

Racional Racional::operator*(Racional& r){
  Racional s;
  s.numerador = numerador * r.numerador;
  s.denominador = denominador * r.denominador;
  s.simplify();
  return s;
}

Racional Racional::operator/(Racional& r){
  Racional s;
  s.numerador = numerador * r.denominador;
  s.denominador = denominador * r.numerador;
  s.simplify();
  return s;
}

bool Racional::operator==(Racional& r){
  if((numerador == r.numerador) && (denominador == r.denominador)){
    return true;
  }
  else{
    return false;
  }
}

bool Racional::operator>(Racional& r){
  float x = numerador / denominador;
  float y = r.numerador / r.denominador;
  if(x > y){
    return true;
  }
  else{
    return false;
  }
}

bool Racional::operator<(Racional& r){
  float x = numerador / denominador;
  float y = r.numerador / r.denominador;
  if(x < y){
    return true;
  }
  else{
    return false;
  }
}

bool Racional::operator>=(Racional& r){
  float x = numerador / denominador;
  float y = r.numerador / r.denominador;
  if(x > y){
    return true;
  }
  else if(x == y){
    return true;
  }
  else{
    return false;
  }
}

bool Racional::operator<=(Racional& r){
  float x = numerador / denominador;
  float y = r.numerador / r.denominador;
  if(x < y){
    return true;
  }
  else if(x == y){
    return true;
  }
  else{
    return false;
  }
}

bool Racional::operator!=(Racional& r){
  float x = numerador / denominador;
  float y = r.numerador / r.denominador;
  if(x == y){
    return false;
  }
  else{
    return true;
  }
}
