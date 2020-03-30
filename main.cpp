#include "matrix.hpp"

int main(){
	Matrix a(4,4,true);
	cout << a << endl;
	cout << a.is_identity() << endl;
	

	return 0;
}