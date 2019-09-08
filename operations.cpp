#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "operations.h"
using namespace std;

void nullMatrix(vector<vector<int>> &m, int r, int c){
  vector<int> nullRow(c, 0);
  for(int i = 0; i < r; i++){
    m.push_back(nullRow);
  }
}

void printMatrix(vector<vector<int>> &m){
  int r = m.size();
  int c = m[0].size();
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cout << setw(4) << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void fillMatrix(vector<vector<int>> &m){
  int r = m.size();
  int c = m[0].size();
  int n;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cout << "Enter the number for row " << i+1 << ", column " << j+1 << ": ";
      cin >> n;
      m[i][j] = n;
    }
  }
}

vector<vector<int>> createMatrix(){
  vector<vector<int>> matrix;
  int rows;
  int columns;
  cout << "Enter the number of rows: ";
  cin >> rows;
  cout << "Enter the number of columns: ";
  cin >> columns;
  nullMatrix(matrix, rows, columns);
  fillMatrix(matrix);
  return matrix;
}

vector<vector<int>> sumMatrix(vector<vector<int>> a, vector<vector<int>> b){
  int rA = a.size();
  int cA = a[0].size();
  int rB = b.size();
  int cB = b[0].size();
  vector<vector<int>> c;
  nullMatrix(c, rA, cA);
  if(rA == rB && cA == cB){
    for(int i = 0; i < rA; i++){
      for(int j = 0; j < cA; j++){
        c[i][j] = a[i][j] + b[i][j];
      }
    }
    return c;
  }else{
    cout << "It isn't possible to do the sum. (Returning null matrix)" << endl;
    return c;
  }
}

vector<vector<int>> subMatrix(vector<vector<int>> a, vector<vector<int>> b){
  int rA = a.size();
  int cA = a[0].size();
  int rB = b.size();
  int cB = b[0].size();
  vector<vector<int>> c;
  nullMatrix(c, rA, cA);
  if(rA == rB && cA == cB){
    for(int i = 0; i < rA; i++){
      for(int j = 0; j < cA; j++){
        c[i][j] = a[i][j] - b[i][j];
      }
    }
    return c;
  }else{
    cout << "It isn't possible to do the subtraction. (Returning null matrix)" << endl;
    return c;
  }
}

vector<vector<int>> scaleMatrix(vector<vector<int>> m, int e){
  int r = m.size();
  int c = m[0].size();
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      m[i][j] = m[i][j]*e;
    }
  }
  return m;
}

vector<vector<int>> multMatrix(vector<vector<int>> a, vector<vector<int>> b){
  int rA = a.size();
  int cA = a[0].size();
  int rB = b.size();
  int cB = b[0].size();
  vector<vector<int>> c;
  nullMatrix(c, rA, cB);
  if(cA == rB){
    for(int i = 0; i < rA; i++){
      for(int j = 0; j < cB; j++){
        c[i][j] = 0;
        for(int k = 0; k < cA; k++){
          c[i][j] += a[i][k]*b[k][j] ;
        }
      }
    }
    return c;
  }else{
    cout << "It isn't possible to multiply.(Returning null matrix)" << endl;
    return c;
  }
}

vector<vector<int>> transposedMatrix(vector<vector<int>> m){
  int r = m.size();
  int c = m[0].size();
  vector<vector<int>> mt;
  nullMatrix(mt, c, r);
  for(int i = 0; i < mt.size(); i++){
    for(int j = 0; j < mt[0].size(); j++){
      mt[i][j] = m[j][i];
    }
  }
  return mt;
}

vector<vector<int>> minorMatrix(vector<vector<int>> m, int r, int c){
  int a = m[0].size();
  int b = m.size();
  if(a != b){
    cout << "Only for square matrix" << endl;
    return m;
  }else{
    for(int i = 0; i < a; i++){
      m[i].erase(m[i].begin()+(c-1));
    }
    m.erase(m.begin()+(r-1));
  }
  return m;
}

int matrixDeterminant(vector<vector<int>> m){
  int a = m[0].size();
  int b = m.size();
  int d = 0;
  if(a == 2 && b == 2){
    return m[0][0]*m[1][1] - m[1][0]*m[0][1];
  }else{
    for(int i = 0; i < a; i++){
      d += m[0][i] * cofactorMatrix(m,1,i+1);
    }
    return d;
  }
}

int cofactorMatrix(vector<vector<int>> m, int r, int c){
  int cof;
  cof = pow(-1,(r+1+c+1))*matrixDeterminant(minorMatrix(m,r,c));
  return cof;
}