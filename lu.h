//
// Created by yassine on 02/11/2020.
//

#ifndef MATRICE_LU__LU_H_
#define MATRICE_LU__LU_H_
#include "matrix.h"
class lu
{
 private:
	int m_size;
	Matrix m_matrixU;
	Matrix m_matrixL;
 public:
	lu(const Matrix&,int);
    void decompositionLU();
    const Matrix& getMatrixU()const;
	const Matrix& getMatrixL()const;
};

#endif //MATRICE_LU__LU_H_
