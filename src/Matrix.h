#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>

namespace Box
{
    template<typename T> class Matrix
    {
        typedef std::vector< std::vector<T*> > TContainer2d;

    public:
        Matrix(const int numLines, const int numColumns);

    public:
        void insertAt(const T& element, const int line, const int column);
        T& elementAt(const int line, const int column);

    private:
        TContainer2d mMatrix;
        int mNumLines; int mNumColumns;
    };

    /* Template definition has to be in the same file as its declaration to avoid linker errors */
    template <typename T> Matrix<T>::Matrix(const int numLines, const int numColumns)
    {
        std::cout << "Constructing a Matrix with " << numLines << " lines and " << numColumns << " columns" << std::endl;

        mNumLines = numLines;
        mNumColumns = numColumns;

        mMatrix.resize(numLines);

        T* newElements = new T[numLines * numColumns]();

        for (typename TContainer2d::iterator it = mMatrix.begin(), end = mMatrix.end(); it != end; ++it)
        {
            it->resize(numColumns, NULL);
            for (typename std::vector<T*>::iterator it2 = it->begin(), end = it->end(); it2 != end; ++it2)
            {
                *it2 = newElements++;
            }
        }
    }

    template <typename T> void Matrix<T>::insertAt(const T& element, const int line, const int column)
    {
        if (line < 0 || line > mNumLines)
            throw std::out_of_range("Line index out of range");

        if (column < 0 || column > mNumColumns)
            throw std::out_of_range("Column index out of range");

        *mMatrix[line][column] = element;
    }

    template <typename T> T& Matrix<T>::elementAt(const int line, const int column)
    {
        return *mMatrix[line][column];
    }

};
#endif //MATRIX_H
