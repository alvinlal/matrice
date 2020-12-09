#include<iostream>

class Matrice {
	int* a, rows, columns;

public:
	Matrice(int m, int n) {
		a = new int[static_cast<long long>(m) * static_cast<long long> (n)];
		rows = m;
		columns = n;
	}
	Matrice(const Matrice& A) {


		rows = A.rows;
		columns = A.columns;
		a = new int[static_cast<long long>(rows) * static_cast<long long> (columns)];
		memcpy(a, A.a, static_cast<long long>(rows) * static_cast<long long> (columns) * sizeof(int));
	}
	Matrice& operator=(const Matrice& A) {
		try {
			if (rows != A.rows || columns != A.columns) {
				throw (0);
			}
		}
		catch (int) {
			std::cout << "can't assign matrices with different order";
		}

		memcpy(a, A.a, static_cast<long long>(rows) * static_cast<long long> (columns) * sizeof(int));
		return *this;
	}
	~Matrice() {
		delete[] a;
	}
	void putElement(int i, int j, int value) {
		a[i * columns + j] = value;
	}
	int getElement(int i, int j) {
		return a[i * columns + j];
	}
	void print() {
		for (int i = 0; i < rows; i++) {
			std::cout << "\n";
			for (int j = 0; j < columns; j++) {
				std::cout << a[i * columns + j] << " ";
			}
		}
	}
	void init(int k) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				a[i * columns + j] = k;
			}
		}
	}

	Matrice& operator-() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				a[i * columns + j] = -a[i * columns + j];
			}
		}
		return *this;
	}
	Matrice& operator+() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				a[i * columns + j] = abs(a[i * columns + j]);
			}
		}
		return *this;
	}
	Matrice operator+(const Matrice& A) const {
		try {
			if (rows != A.rows || columns != A.columns) {
				throw (0);
			}
		}
		catch (int) {
			std::cout << "can't add matrices with different order";
		}
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp.a[i * columns + j] = a[i * columns + j] + A.a[i * columns + j];
			}
		}
		return temp;
	}
	Matrice operator-(const Matrice& A) const {
		try {
			if (rows != A.rows || columns != A.columns) {
				throw (0);
			}
		}
		catch (int) {
			std::cout << "can't subtract matrices with different order";
		}
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp.a[i * columns + j] = a[i * columns + j] - A.a[i * columns + j];
			}
		}
		return temp;
	}
	Matrice operator/(const Matrice& A) const {
		try {
			if (rows != A.rows || columns != A.columns) {
				throw (0);
			}
		}
		catch (int) {
			std::cout << "can't divide matrices with different order";
		}
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp.a[i * columns + j] = a[i * columns + j] / A.a[i * columns + j];
			}
		}
		return temp;
	}
	Matrice operator*(const Matrice& A) const {
		try {
			if (rows != A.rows || columns != A.columns) {
				throw (0);
			}
		}
		catch (int) {
			std::cout << "can't multiply matrices with invalid order";
		}
		Matrice temp(rows, A.columns);
		temp.init(0);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				for (int k = 0; k < columns; k++) {
					temp.a[i * A.columns + j] += a[i * columns + k] * A.a[k * A.columns + j];
				}
			}
		}
		return temp;
	}
	int operator()(int i, int j) {
		try {
			if (i > rows || i<0 || j > columns || j < 0) {
				throw (0);
			}
		}
		catch (int) {
			std::cout << "\nIndexes are out of bounds";
		}
		return a[i * columns + j];
	}
	friend Matrice operator+(int k, const Matrice& A) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = k + A.a[i * A.columns + j];
			}
		}
		return temp;
	}
	friend Matrice operator+(const Matrice& A, int k) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = k + A.a[i * A.columns + j];
			}
		}
		return temp;
	}
	friend Matrice operator-(const Matrice& A, int k) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = A.a[i * A.columns + j] - k;
			}
		}
		return temp;
	}
	friend Matrice operator-(int k, const Matrice& A) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = k - A.a[i * A.columns + j];
			}
		}
		return temp;
	}
	friend Matrice operator*(int k, const Matrice& A) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = k * A.a[i * A.columns + j];
			}
		}
		return temp;
	}
	friend Matrice operator*(const Matrice& A, int k) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = k * A.a[i * A.columns + j];
			}
		}
		return temp;
	}
	friend Matrice operator/(const Matrice& A, int k) {
		try {
			if (k == 0) {
				throw (0);
			}
		}
		catch (int) {
			std::cout << "cannot divide by zero";
		}
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = A.a[i * A.columns + j] / k;
			}
		}
		return temp;
	}
	friend Matrice operator/(int k, const Matrice& A) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = k / A.a[i * A.columns + j];
			}
		}
		return temp;
	}
	friend Matrice operator^(const Matrice& A, int k) {
		Matrice temp(A.rows, A.columns);
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				temp.a[i * A.columns + j] = int(pow(A.a[i * A.columns + j], k));
			}
		}
		return temp;
	}

	friend std::istream& operator>>(std::istream& stream, const Matrice& A);
	friend std::ostream& operator<<(std::ostream& stream, const Matrice& A);
};


std::ostream& operator<<(std::ostream& stream, const Matrice& A) {
	for (int i = 0; i < A.rows; i++) {
		stream << "\n";
		for (int j = 0; j < A.columns; j++) {
			stream << A.a[i * A.columns + j] << " ";
		}
	}
	stream << "\n";
	return stream;
}
std::istream& operator>>(std::istream& stream, const Matrice& A) {
	for (int i = 0; i < A.rows; i++) {
		std::cout << "\nEnter row " << i + 1 << " : ";
		for (int j = 0; j < A.columns; j++) {
			stream >> A.a[i * A.columns + j];
		}
	}
	return stream;
}
