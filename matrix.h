//
// Created by yassine on 02/11/2020.
//

#ifndef MATRICE_LU__MATRIX_H_
#define MATRICE_LU__MATRIX_H_
#include <vector>

#include <iostream>

class Matrix
{
 public:
	Matrix(double**, int);
	Matrix(const Matrix&);
	Matrix(int);
	~Matrix();

	Matrix& operator=(const Matrix&);

	inline double& operator()(int x, int y) {return p[x][y];}

	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);

	static Matrix createIdentity(int);

 private:
	int m_rows, m_cols;
	double** p;
	void allocSpace();
};

#endif //MATRICE_LU__MATRIX_H_
