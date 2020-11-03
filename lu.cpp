//
// Created by yassine on 02/11/2020.
//
#include "lu.h"
lu::lu(const Matrix& matrixA, int size) : m_matrixU{ matrixA }, m_matrixL(size), m_size{ size }
{
}

void lu::decompositionLU()
{
	for (int i{ 0 }; i < m_size; ++i)
	{
		for (int j{ i + 1 }; j < m_size; ++j)
		{
			m_matrixL(j,i)=m_matrixU(j,i)/m_matrixU(i,i);
			m_matrixU(j,i)=0;
			for (int k{ i + 1 }; k < m_size; ++k)
			{
            m_matrixU(j,k)-=m_matrixL(j,i)*m_matrixU(i,k);
			}
		}
	}
}
const Matrix& lu::getMatrixU() const
{
	return m_matrixU;
}
const Matrix& lu::getMatrixL() const
{
	return m_matrixL;
}
