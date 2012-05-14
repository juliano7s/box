
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>

namespace Box
{

template<typename T>
class Matrix
{
public:
	Matrix();
	Matrix(int numRows, int numColumns);
	Matrix(const Matrix<T> &matrix);
	~Matrix();

public:
	T& operator() (int row, int column);
	T  operator() (int row, int column) const;

public:
	void insertAt(const T& element, int row, int column);
	T& elementAt(int row, int column);

private:
	typedef std::vector< std::vector<T*> > TContainer2d;

	TContainer2d mMatrix;
	int mNumRows; int mNumColumns;
};

/* Constructors */

template <typename T>
Matrix<T>::Matrix()
{
	//empty
}

/* Template definition has to be in the same file as its declaration to avoid linker errors */
template <typename T>
Matrix<T>::Matrix(int numRows, int numColumns)
{
	if (numRows <= 0 || numColumns <= 0)
	{
		throw std::invalid_argument("Matrix can't have a 0 or negative size row or column");
	}

	mNumRows = numRows;
	mNumColumns = numColumns;

	mMatrix.resize(numRows);

	T* newElements = new T[numRows * numColumns]();

	for (typename TContainer2d::iterator it = mMatrix.begin(), end = mMatrix.end(); it != end; ++it)
	{
		it->resize(numColumns, NULL);
		for (typename std::vector<T*>::iterator it2 = it->begin(), end = it->end(); it2 != end; ++it2)
		{
			*it2 = newElements++;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &matrix)
{
	//TODO
}

template <typename T>
Matrix<T>::~Matrix()
{
	//TODO delete all elements
}

/* Operator overloading */

template <typename T>
T& Matrix<T>::operator() (int row, int column)
{
	return *mMatrix[row][column];
}

template <typename T>
T  Matrix<T>::operator() (int row, int column) const
{
	return *mMatrix[row][column];
}

/* Methods */

template <typename T>
void Matrix<T>::insertAt(const T& element, int row, int column)
{
	if (row < 0 || row > mNumRows)
		throw std::out_of_range("Row index out of range");

	if (column < 0 || column > mNumColumns)
		throw std::out_of_range("Column index out of range");

	*mMatrix[row][column] = element;
}

template <typename T>
T& Matrix<T>::elementAt(int row, int column)
{
	return (*this)(row, column);
}


} //end of namespace

#endif //MATRIX_H
