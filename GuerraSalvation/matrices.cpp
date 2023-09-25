#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    // Constructor que crea una matriz vacía con las dimensiones especificadas
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data.resize(rows, std::vector<double>(cols, 0.0));
    }

    // Constructor que crea una matriz a partir de un vector de vectores
    Matrix(std::vector<std::vector<double>> inputData) {
        rows = inputData.size();
        cols = inputData[0].size();
        data = inputData;
    }

    // Métodos para obtener el número de filas y columnas
    int numRows() const {
        return rows;
    }

    int numCols() const {
        return cols;
    }

    // Método para acceder a un elemento específico de la matriz
    double& operator()(int row, int col) {
        return data[row][col];
    }

    // Método para imprimir la matriz
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Sobrecarga del operador de suma para matrices
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para sumarse.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result(i, j) = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    Matrix A(2, 2); // Crear una matriz de 2x2
    A(0, 0) = 1.0;
    A(0, 1) = 2.0;
    A(1, 0) = 3.0;
    A(1, 1) = 4.0;

    Matrix B = {{5.0, 6.0}, {7.0, 8.0}}; // Crear una matriz a partir de un vector de vectores

    Matrix C = A + B; // Sumar matrices

    std::cout << "Matriz A:" << std::endl;
    A.print();

    std::cout << "Matriz B:" << std::endl;
    B.print();

    std::cout << "Matriz C = A + B:" << std::endl;
    C.print();

    return 0;
}
