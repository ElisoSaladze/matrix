#include <iostream>
#include <fstream>
using namespace std;


template <class T>
class Matrix{
	private:
		unsigned int cols;
		unsigned int rows;
		T **data;
	public:
		Matrix () {
			rows = 1;
            cols = 1;
            data = new T*[rows];
			for (int i = 0; i < rows; i++){
                data[i] = new T[cols];
                data[i][0] = 0;
            }
		}
		Matrix(unsigned int rows, unsigned int cols) {
			this->cols=cols;
			this->rows=rows;
			data = new T*[rows];
			for (int i = 0; i < rows; i++){
				data[i] = new T[cols];
				for (int j = 0; j < cols; j++) {
					data[i][j] = 0;
				}
			}
		}
		Matrix(unsigned int rows, unsigned int cols, T value) {
			this->cols=cols;
			this->rows=rows;
			data =new T*[rows];
			for (int i = 0; i < rows; i++) {
				data[i] = new T[cols];
				for (int j = 0; j < cols; j++) {
					data[i][j] = value;
				}
			}
		}
		Matrix (const Matrix &M) {
			rows = M.rows;
			cols = M.cols;
			data =new T*[rows];
			for (int i = 0; i < rows; i++) {
				data[i] = new T[cols];
				for (int j = 0; j < cols; j++) {
					data[i][j] = M.data[i][j];
				}
			}
			data = M.data;
		}
		void setRows (unsigned int rows) {
			this->rows=rows;
		}
		unsigned int getRows () {
			return rows;
		}
		void setCols (unsigned int cols) {
			this->cols=cols;
		}
		unsigned int getCols () {
			return cols;
		}
		T getValue (unsigned int row, unsigned int col) {
			return data[row][col];
		}
		void setValue (unsigned int row, unsigned int col, T value) {
			if (row < rows && col < cols) {
				data[row][col] = value;
			} else {
				cerr <<"Error: row and col out of bounds"<<endl;
			}
		}	
};
template <class T>
Matrix<T> operator+(Matrix<T> &A, Matrix<T> &B) {
	Matrix<T> tmp(A.getRows(), A.getCols());
	for (unsigned int i = 0; i < A.getRows(); i++) {
		for (unsigned int j = 0; j < A.getCols(); j++) {
			tmp.setValue(i, j, A.getValue(i, j) + B.getValue(i, j));
		}
	}
	return tmp;
}

template <class T>
Matrix<T> operator-(Matrix<T> &A, Matrix<T> &B) {
	Matrix<T> tmp(A.getRows(), A.getCols());
	for (unsigned int i = 0; i < A.getRows(); i++) {
		for (unsigned int j = 0; j < A.getCols(); j++) {
			tmp.setValue(i, j, A.getValue(i, j) - B.getValue(i, j));
		}
	}
	return tmp;
}

template <class T>
ostream& operator<<(ostream& output, Matrix<T> &M) {
	for (unsigned int i = 0; i < M.getRows(); i++) {
		for (unsigned int j = 0; j < M.getCols(); j++) {
			output<<M.getValue(i, j)<<" ";
		}
		output<<endl;
	}
	return output;
}


template <class T>
istream& operator>>(istream &input, Matrix<T> &M) {
	T value = 0;
	for (unsigned int i = 0; i < M.getRows(); i++) {
		for (unsigned int j = 0; j < M.getCols(); j++) {
			cout<<"["<<i<<"]"<<"["<<j<<"]= "; input>>value;
			M.setValue(i, j, value);
		}
	}
	return input;
}

template <class T>
Matrix<T> transposition(Matrix<T> &M) {
	Matrix<T> tmp(M.getRows(), M.getCols());
	for (unsigned int i = 0; i < M.getRows(); i++) {
		for (unsigned int j = 0; j < M.getCols(); j++) {
			tmp.setValue(j, i, M.getValue(i, j));
		}
	}
	return tmp;
}

int main (int argc, char** argv) {
	Matrix<double> A(2, 2);
	cin>>A;
	Matrix<double> B(2, 2);
	cin>>B;
	cout<<endl;
	Matrix <double> C = A + B;
	cout<<C;
	return 0;
}
