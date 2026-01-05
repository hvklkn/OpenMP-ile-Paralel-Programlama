#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>

using namespace std;

// Matrisleri doldurmak için rastgele değerler atayan bir fonksiyon
void fillMatrix(vector<vector<double>> &matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 10 + 1; // 1 ile 10 arasında rastgele değerler
        }
    }
}

// Matris çarpımının sıralı versiyonu
void sequentialMatrixMultiplication(const vector<vector<double>> &A, const vector<vector<double>> &B, vector<vector<double>> &C, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matris çarpımının OpenMP ile paralel versiyonu
void parallelMatrixMultiplication(const vector<vector<double>> &A, const vector<vector<double>> &B, vector<vector<double>> &C, int size, int numThreads) {
    #pragma omp parallel for num_threads(numThreads)
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int size = 500; // Matris boyutu
    vector<vector<double>> A(size, vector<double>(size));
    vector<vector<double>> B(size, vector<double>(size));
    vector<vector<double>> C(size, vector<double>(size));

    fillMatrix(A, size);
    fillMatrix(B, size);

    // Sıralı çalıştırma
    auto start = chrono::high_resolution_clock::now();
    sequentialMatrixMultiplication(A, B, C, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> sequentialDuration = end - start;

    cout << "Sequential Execution Time: " << sequentialDuration.count() << " seconds" << endl;

    // Paralel çalıştırma farklı iş parçacığı sayıları ile
    for (int numThreads = 1; numThreads <= 8; numThreads *= 2) {
        auto start = chrono::high_resolution_clock::now();
        parallelMatrixMultiplication(A, B, C, size, numThreads);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> parallelDuration = end - start;

        cout << "Parallel Execution Time with " << numThreads << " threads: "
             << parallelDuration.count() << " seconds" << endl;
    }

    return 0;
}
