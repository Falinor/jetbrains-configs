#ifndef MATRIX_HH_
# define MATRIX_HH_

template <typename T>
class Matrix
{
  public:
    /**
    ** Creates a matrix with zero row and zero column.
    */
    Matrix();

    /**
    ** Creates an empty matrix with \p rows rows and \p cols columns.
    */
    Matrix(unsigned int rows, unsigned int cols);

    /**
    ** Returns the number of rows in the matrix.
    */
    unsigned int rows_get() const;

    /**
    ** Returns the number of columns in the matrix.
    */
    unsigned int cols_get() const;

    /**
    ** \brief Returns the value of the matrix at the row \p row and the column
    **        \p column.
    */
    T& operator()(unsigned int row, unsigned int col);

    /**
    ** Computes the addition of two matrices in a new matrix.
    */
    Matrix<T> operator+(const Matrix<T>& rhs) const;

    /**
    ** Computes the subtraction of two matrices in a new matrix.
    */
    Matrix<T> operator-(const Matrix<T>& rhs) const;

    /**
    ** Computes the multiplication of two matrices in a new matrix.
    */
    Matrix<T> operator*(const Matrix<T>& rhs) const;

    /**
    ** \brief Computes the division of two matrices in a new matrix.
    ** \note  The division of two matrices is actually the multiplication of
    **        the first matrix with the second one’s inverse.
    */
    Matrix<T> operator/(const Matrix<T>& rhs) const;

    /**
    ** Computes the addition of two matrices in the first matrix.
    */
    Matrix<T>& operator+=(const Matrix<T>& rhs);

    /**
    ** Computes the subtraction of two matrices in the first matrix.
    */
    Matrix<T>& operator-=(const Matrix<T>& rhs);

    /**
    ** Computes the multiplication of two matrices in the first matrix.
    */
    Matrix<T>& operator*=(const Matrix<T>& rhs);

    /**
    ** \brief Computes the division of two matrices in the first matrix.
    ** \note  The division of two matrices is actually the multiplication of
    **        the first matrix with the second one’s inverse.
    */
    Matrix<T>& operator/=(const Matrix<T>& rhs);

    /**
    ** \brief Writes all matrix’s elements in the stream \p ostr.
    **   Elements on the same line are separated with ' ', lines with a '\n'.
    */
    template <typename U>
    friend std::ostream& operator<<(std::ostream& ostr, const Matrix<U>& mat);

    /**
    ** \brief Reads from the stream \p istr and fills the matrix with the read
    **   data.
    ** \note  This function doesn't check for errors from the stream and stops
    **   when it reaches the end of the matrix.
    */
    friend std::istream& operator>>(std::istream& istr, Matrix<int>& mat);

    /**
    ** \copydoc Matrix::operator>>(std::istream&, Matrix<int>&)
    */
    friend std::istream& operator>>(std::istream& istr,
				    Matrix<unsigned int>& mat);

    /**
    ** Returns the matrix’s trace.
    */
    T tr() const;

    /**
    ** Returns the matrix’s transpose.
    */
    Matrix<double> t() const;

    /**
    ** Returns the matrix’s inverse.
    */
    Matrix<double> inverse() const;

    /**
    ** Returns the matrix’s determinant.
    */
    double det() const;
};

#endif /* !MATRIX_HH_ */
