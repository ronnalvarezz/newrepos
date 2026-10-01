#include <iostream>
#include <new>

int** makeMtx(size_t m, size_t n);
void rmMtx(int** mtx, size_t allocated_rows);
int** transpose(int** mtx, size_t m, size_t n);
void printMtx(int ** mtx, size_t m, size_t n);

int main() {
    size_t m = 0; // столбцы
    size_t n = 0; // строки
    std::cin >> m >> n;
    if (!std::cin || m == 0 || n == 0) return 1;

    int ** mtx = nullptr;
    
    mtx = makeMtx(m, n);

    for (size_t i = 0; i < m * n; i++) {
        mtx[i % m][i / m] = 0; //заполнение нулями
    }

    printMtx(mtx, m, n);

    transpose(mtx, m, n);
 
    int** transposed = transpose(mtx, m, n);

    rmMtx(mtx, m);

    printMtx(transposed, n, m);

    rmMtx(transposed, n);
}

void rmMtx(int** mtx, size_t allocated_rows) {
    if (!mtx) return;
    for (size_t i = 0; i < allocated_rows; ++i) {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int** makeMtx(size_t m, size_t n) {
    int** mtx = new int*[m]; 
    try {
        for (size_t i = 0; i < m; ++i) {
            mtx[i] = nullptr; 
            mtx[i] = new int[n];
        }
    }
    catch (const std::bad_alloc& e) {
        rmMtx(mtx, m);
        throw; 
    }
    return mtx;
}

int** transpose(int** mtx, size_t m, size_t n) {
    int** result = makeMtx(n, m);

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            result[j][i] = mtx[i][j];
        }
    }
    return result;
}

void printMtx(int ** mtx, size_t m, size_t n) {
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << mtx[i][j] << " ";
        }
        std::cout << "\n";
    }
}
