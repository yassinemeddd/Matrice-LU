//
// Created by yassine on 02/11/2020.
//

#include "matrix.h"
#include <stdexcept>


using std::ostream;  using std::istream;  using std::endl;

Matrix::Matrix(double** a, int size) : m_rows{size}, m_cols{size}
{
	allocSpace();
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			p[i][j] = a[i][j];
		}
	}
}


Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; ++i)
	{
		delete[] p[i];
	}
	delete[] p;
}

Matrix::Matrix(const Matrix& m) : m_rows{m.m_rows}, m_cols{m.m_cols}
{
	allocSpace();
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			p[i][j] = m.p[i][j];
		}
	}
}

Matrix::Matrix(int size) :m_cols{size},m_rows{size}
{
	allocSpace();
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			p[i][j] = 0;
		}
	}
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (this == &m)
	{
		return *this;
	}

	if (m_rows != m.m_rows || m_cols != m.m_cols)
	{
		for (int i = 0; i < m_rows; ++i)
		{
			delete[] p[i];
		}
		delete[] p;

		m_rows = m.m_rows;
		m_cols = m.m_cols;
		allocSpace();
	}

	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			p[i][j] = m.p[i][j];
		}
	}
	return *this;
}

Matrix Matrix::createIdentity(int size)
{
	Matrix temp(size);
	for (int i = 0; i < temp.m_rows; ++i)
	{
		for (int j = 0; j < temp.m_cols; ++j)
		{
			if (i == j)
			{
				temp.p[i][j] = 1;
			}
			else
			{
				temp.p[i][j] = 0;
			}
		}
	}
	return temp;
}


void Matrix::allocSpace()
{
	p = new double* [m_rows];
	for (int i = 0; i < m_rows; ++i)
	{
		p[i] = new double[m_cols];
	}
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.m_rows; ++i)
	{
		os << m.p[i][0];
		for (int j = 1; j < m.m_cols; ++j)
		{
			os << " " << m.p[i][j];
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, Matrix& m)
{
	for (int i = 0; i < m.m_rows; ++i)
	{
		for (int j = 0; j < m.m_cols; ++j)
		{
			is >> m.p[i][j];
		}
	}
	return is;
}
