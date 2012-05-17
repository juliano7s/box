
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iterator>
#include <iostream>
#include <stdexcept>

namespace Box
{

template <typename T>
class MatrixIterator;

template<typename T>
class Matrix
{
public:
	typedef MatrixIterator<T> iterator;

public:
	Matrix();
	Matrix(int numRows, int numColumns);
	Matrix(const Matrix<T> &matrix);
	~Matrix();

public:
	T& operator() (int row, int column);
	T  operator() (int row, int column) const;
	iterator begin() { return iterator(*this, &this->first()); }
	/* Do jeito que tá implementando o end() como NULL, parece-me estranho que
       ((matrix.end()++)-- != matrix.end()) e ((matrix.end()++)-- != (matrix.end()--)++) */
	iterator end() { return iterator(*this, NULL); }

public:
	void insertAt(const T& element, int row, int column);
	T& elementAt(int row, int column);
	T& first() { return (*this)(0,0); }
	T& last() { return (*this)(mNumRows - 1, mNumColumns - 1); }

private:
	typedef std::vector< std::vector<T*> > TContainer2d;
	typedef std::vector<T*> TContainer1d;

	TContainer2d mMatrix;
	int mNumRows; int mNumColumns;
};

/* Template definition has to be in the same file as its declaration to avoid linker errors */
/******************* Constructors  ********************/

template <typename T>
Matrix<T>::Matrix()
{
	//empty
}

template <typename T>
Matrix<T>::Matrix(int numRows, int numColumns)
{
    std::cout << "Constructing Matrix: " << this;

	if (numRows <= 0 || numColumns <= 0)
	{
		throw std::invalid_argument("Matrix can't have a 0 or negative size row or column");
	}

	mNumRows = numRows;
	mNumColumns = numColumns;

	mMatrix.resize(numRows);

	T* newElements = new T[numRows * numColumns]();

	/* Resize vectors to fit passed matrix dimensions */
	for (typename TContainer2d::iterator it = mMatrix.begin(), end = mMatrix.end(); it != end; ++it)
	{
		it->resize(numColumns, NULL);
		for (typename TContainer1d::iterator it2 = it->begin(), end = it->end(); it2 != end; ++it2)
		{
			/* Sets the allocated memory to vector positions */
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
    std::cout << "Destructing Matrix: " << this;
    
    /*
	for (Matrix<T>::iterator it = this->begin(), end = this->end(); it != end; ++it)
	{
		T *element = &(*it);
        std::cout << "Deleting matrix element: " << element->position().x <<
            element->position().y << std::endl;
		//delete(element);
	}
    */

    for (typename TContainer2d::iterator it = mMatrix.begin(), end = mMatrix.end(); it != end; ++it)
	{
		for (typename TContainer1d::iterator it2 = it->begin(), end = it->end(); it2 != end; ++it2)
		{
			delete &(*it2);
		}
	}

    int value = 0;
    std::cin >> value;
}

/******************* Operator overloading ********************/

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

/******************* Methods ********************/

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


/******************* Iterator for Matrix class ********************/

template <typename T>
class MatrixIterator
	: public std::iterator<std::bidirectional_iterator_tag, T>
{
	friend class Matrix<T>;

public:
	T& operator*() { return *mpElement; }
	MatrixIterator<T> operator++(int i);
	MatrixIterator<T>& operator++(void);
	MatrixIterator<T> operator--(int i);
	MatrixIterator<T>& operator--(void);
	MatrixIterator<T>& operator= (const MatrixIterator<T>& other);
	bool operator!=(const MatrixIterator<T> &other) const;
	bool operator==(const MatrixIterator<T> &other) const;

private:
	Matrix<T> &mMatrix;
	T *mpElement;

private:
	MatrixIterator(Matrix<T> &matrix, T *element) : mMatrix(matrix), mpElement(element) { };
};

template <typename T>
MatrixIterator<T> MatrixIterator<T>::operator++(int i)
{
	MatrixIterator<T> copy = *this;
	++(*this);
	return copy;
}

template <typename T>
MatrixIterator<T>& MatrixIterator<T>::operator++()
{
	if (mpElement != NULL)
	{
        if (mpElement == &(mMatrix.last()))
        {
            mpElement = NULL;
        } else
        {
            mpElement++;
        }
	}
	return *this;
}

template <typename T>
MatrixIterator<T> MatrixIterator<T>::operator--(int i)
{
	MatrixIterator<T> copy = *this;
	--(*this);
	return copy;
}

template <typename T>
MatrixIterator<T>& MatrixIterator<T>::operator--()
{
	if (mpElement != NULL)
	{
		mpElement--;
	} else
    {
        mpElement = &(mMatrix.last());
    }
	return *this;
}

template <typename T>
MatrixIterator<T>& MatrixIterator<T>::operator=(const MatrixIterator<T> &other)
{
	*mpElement = *other.mpElement;
	return *this;
}

template <typename T>
bool MatrixIterator<T>::operator!=(const MatrixIterator<T> &other) const
{
	if (&this->mMatrix != &other.mMatrix)
	{
		return true;
	} else
	{
		if (this->mpElement !=  other.mpElement)
		{
			return true;
		}
	}

	return false;
}

template <typename T>
bool MatrixIterator<T>::operator== (const MatrixIterator<T> &other) const
{
	return !(*this != other);
}


} //end of namespace

#endif //MATRIX_H
