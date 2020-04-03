#include "matrix.hpp"

Matrix::Matrix(int r, int c, bool fill){
	rows = r;
	columns = c;
	double temp;
	extended = false;
	for(int i = 0; i < rows; i++){
		vector<double> aux(columns, 0);
		a.push_back(aux);
	}
	if(fill){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				cout << "Row: " << i+1 << " Column: " << j+1 << endl;
				cin >> temp;
				a[i][j] = temp; 
			}
		}		
	}
}

Matrix::Matrix(const Matrix &m){
	rows = m.rows;
	columns = m.columns;
	extended = false;
	if(m.extended){
		extended = true;
		b = m.b;
	}
	a = m.a;
}

void Matrix::extend(bool homogeneus){
	double aux;
	extended = true;
	if(homogeneus){
		for(int i = 0; i < rows; i++){
			b.push_back(0);
		}
	}else{
		for(int i = 0; i < rows; i++){
			cout << "B" << i+1 << endl;
			cin >> aux;
			b.push_back(aux); 
		}
	}
}

double Matrix::get_element(int row, int column){
	if((0 < row && row <= rows)&&(0 < column && column <= columns)){
		return a[row-1][column-1];
	}else{
		throw runtime_error("get_element: Index out of bounds");
	}
}

vector<double> Matrix::get_row(int row){
	if(0 < row && row <= rows){
		return a[row-1];
	}else{
		throw runtime_error("get_row: Index out of bounds");
	}
}

vector<double> Matrix::get_column(int column){
	if(0 < column && column <= columns){
		vector<double> col;
		for(int i = 0; i < rows; i++){
			col.push_back(a[i][column-1]);
		}
		return col;
	}else{
		throw runtime_error("get_column: Index out of bounds");
	}
}

vector<double> Matrix::get_sol(){
	if(extended){
		return b;
	}else{
		throw runtime_error("get_sol: Matrix is not extended");
	}
}

vector<int> Matrix::get_dimensions(){
	vector<int> dim;
	dim.push_back(rows);
	dim.push_back(columns);
	return dim;
}

bool Matrix::is_squared(){
	return rows == columns;
}

bool Matrix::is_diagonal(){
	if(!is_squared()){
		return false;
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(i != j){
				if(a[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}

bool Matrix::is_superior_triangular(){
	if(!is_squared()){
		return false;
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(j < i){
				if(a[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}

bool Matrix::is_inferior_triangular(){
	if(!is_squared()){
		return false;
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(j > i){
				if(a[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}

bool Matrix::is_triangular(){
	return is_superior_triangular() || is_inferior_triangular();
}

bool Matrix::is_null(){
	for(int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			if(a[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

bool Matrix::is_identity(){
	if(!is_squared()){
		return false;
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(i == j){
				if(a[i][j] != 1){
					return false;
				}
			}else{
				if(a[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}

bool Matrix::is_symmetrical(){
	return *this == transpose();
}

bool Matrix::is_invertible(){
	if(is_squared()){
		return determinant() != 0;
	}else{
		return false;
	}
}

Matrix Matrix::transpose(){
	Matrix b(columns, rows, false);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			b.a[j][i] = a[i][j];
		}
	}
	return b;
}

Matrix Matrix::minor_matrix(int row, int column){
	Matrix b = *this;
	b.a.erase(b.a.begin()+row-1);
	b.rows -= 1;
	for(int i = 0; i < b.rows; i++){
		b.a[i].erase(b.a[i].begin()+column-1);
	} 
	b.columns -= 1;
	return b;
}

double Matrix::determinant(){
	double det = 0;
	if(rows != columns){
		throw runtime_error("determinant: Only for squared matrices");
	}
	if(rows == 2 && columns == 2){
		return a[0][0]*a[1][1] - a[0][1]*a[1][0];
	}else{
		for(int i = 0; i < rows; i++){
			det += a[0][i]*cofactor(1,i+1);
		}
		return det;
	}
}

double Matrix::cofactor(int row, int column){
	double cof = pow(-1,row+column)*minor_matrix(row,column).determinant();
	return cof;
}

Matrix Matrix::adj(){
	if(rows != columns){
		throw runtime_error("adj: Only for squared matrices");
	}
	Matrix ad(rows, columns, false);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			ad.a[i][j] = cofactor(i+1,j+1);
		}
	}
	return ad;
}

Matrix Matrix::inverse(){
	if(!is_invertible()){
		throw runtime_error("find_inverse: Matrix is not invertible");
	}
	Matrix ad = adj();
	Matrix ad_t = ad.transpose();
	Matrix inv = ad_t*(1.0/determinant());
	return inv;
}

double Matrix::trace(){
	if(!is_squared()){
		throw runtime_error("trace: Matrix is not squared");
	}
	double t = 0;
	for(int i = 0; i < rows; i++){
		t += a[i][i];
	}
	return t;
}

Matrix Matrix::solve_system(){
	if(extended){
		if(is_squared()){
			Matrix c(columns, 1, false);
			for(int i = 0; i < columns; i++){
				c.a[i][0] = b[i];
			}
			Matrix sol = inverse()*c;
			return sol;
		}
	}else{
		throw runtime_error("solve_system: Matrix is not extended");
	}	
}

//Operators
ostream& operator<<(ostream& out, const Matrix& m){
	for(int i = 0; i < m.rows; i++){
		for(int j = 0; j < m.columns; j++){
			out << m.a[i][j] << " ";
		}
		if(m.extended){
			out << " | " << m.b[i];
		}
		out << endl;
	}
	return out;
}

Matrix Matrix::operator+(const Matrix &m){
	if(rows != m.rows || columns != m.columns){
		throw runtime_error("+: The dimensions of the matrices are different");
	}else{
		Matrix c(rows, columns, false);
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				c.a[i][j] = a[i][j] + m.a[i][j];
			}
		}
		return c;
	}
}

Matrix Matrix::operator-(const Matrix &m){
	if(rows != m.rows || columns != m.columns){
		throw runtime_error("-: The dimensions of the matrices are different");
	}else{
		Matrix c(rows, columns, false);
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				c.a[i][j] = a[i][j] - m.a[i][j];
			}
		}
		return c;
	}
}

Matrix Matrix::operator*(const Matrix &m){
	if(columns != m.rows){
		throw runtime_error("*: Unable to multiply the matrices, columns and rows don't match");
	}else{
		Matrix c(rows, m.columns, false);
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < m.columns; j++){
				for(int k = 0; k < columns; k++){
					c.a[i][j] += a[i][k]*m.a[k][j];
				}
			}
		}
		return c;
	}
}

bool Matrix::operator==(const Matrix &m){
	if(rows != m.rows || columns != m.columns){
		return false;
	}else{
		if(a != m.a){
			return false;
		}else{
			return true;
		}
	}
}

Matrix& Matrix::operator=(const Matrix &m){
	this->a = m.a;
	rows = m.rows;
	columns = m.columns;
	if(m.extended){
		extended = true;
		this->b = m.b;
	}
	return *this;
}

Matrix operator*(Matrix m, double a){
	for(int i = 0; i < m.rows; i++){
		for(int j = 0; j < m.columns; j++){
			m.a[i][j] *= a;
		}
	}
	return m;
}

Matrix operator*(double a, Matrix m){
	for(int i = 0; i < m.rows; i++){
		for(int j = 0; j < m.columns; j++){
			m.a[i][j] *= a;
		}
	}
	return m;
}