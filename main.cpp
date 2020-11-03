#include <iostream>
#include "matrix.h"
#include "lu.h"
int main()
{
	std::cout<<"specify the size of the matrix:"<<std::endl;
	int size;
	std::cin>>size;
	Matrix matriceA(size);
	std::cin>>matriceA;
	lu matrice(matriceA,size);
	matrice.decompositionLU();
	std::cout<<matrice.m_matrixL<<"\n"<<matrice.m_matrixU<<std::endl;

	return 0;
}
