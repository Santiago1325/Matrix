#ifndef _operations_h
#define _operations_h
using namespace std;

void nullMatrix(vector<vector<int>> &m, int r, int c);
void printMatrix(vector<vector<int>> &m);
void fillMatrix(vector<vector<int>> &m);
vector<vector<int>> createMatrix();
vector<vector<int>> sumMatrix(vector<vector<int>> a, vector<vector<int>> b);
vector<vector<int>> subMatrix(vector<vector<int>> a, vector<vector<int>> b);
vector<vector<int>> scaleMatrix(vector<vector<int>> m, int e);
vector<vector<int>> multMatrix(vector<vector<int>> a, vector<vector<int>> b);
vector<vector<int>> transposedMatrix(vector<vector<int>> m);

#endif
