#include <iostream>
#include <vector>
//#include <iomanip>
#include "operations.h"
using namespace std;

int main(){
  int op;
  int n;
  int d;

  vector<vector<int>> A;
  vector<vector<int>> B;
  vector<vector<int>> C;

  cout << "1) Sum two matrix.\n2) Substract two matrix\n3) Multiply a matrix for a number\n4) Multiply two matrix\n5) Find the transposed matrix\n6) Find the determinant of a matrix\n";
  cout << "Enter the number of the desired operation: ";
  cin >> op;

  if(op == 1){
    cout << "Enter matrix A" << endl;
    A = createMatrix();
    printMatrix(A);
    cout << "Enter matrix B" << endl;
    B = createMatrix();
    printMatrix(B);
    cout << "Matrix C = A + B" << endl;
    C = sumMatrix(A,B);
    printMatrix(C);
  }else if(op == 2){
    cout << "Enter matrix A" << endl;
    A = createMatrix();
    printMatrix(A);
    cout << "Enter matrix B" << endl;
    B = createMatrix();
    printMatrix(B);
    cout << "Matrix C = A - B" << endl;
    C = subMatrix(A,B);
    printMatrix(C);
  }else if(op == 3){
    cout << "Enter matrix A" << endl;
    A = createMatrix();
    printMatrix(A);
    cout << "Enter number n: ";
    cin >> n;
    cout << "Matrix C = A*n" << endl;
    C = scaleMatrix(A,n);
    printMatrix(C);
  }else if(op == 4){
    cout << "Enter matrix A" << endl;
    A = createMatrix();
    printMatrix(A);
    cout << "Enter matrix B" << endl;
    B = createMatrix();
    printMatrix(B);
    cout << "Matrix C = A*B" << endl;
    C = multMatrix(A,B);
    printMatrix(C);
  }else if(op == 5){
    cout << "Enter matrix A" << endl;
    A = createMatrix();
    printMatrix(A);
    cout << "Matrix C = A^T" << endl;
    C = transposedMatrix(A);
    printMatrix(C);
  }else if(op == 6){
    cout << "Enter matrix A" << endl;
    A = createMatrix();
    printMatrix(A);
    d = matrixDeterminant(A);
    cout <<"The determinant of the matrix A is: " << d << endl;
  }else{
    cout << "Please enter a valid operation number.\n";
  }

  return 0;
}
