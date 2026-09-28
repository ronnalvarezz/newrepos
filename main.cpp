#include <iostream>

int ** makeMtx(int ** mtx, size_t m, size_t n); // выделяет память
int ** transpose(int ** mtx, size_t m, size_t n);
int rmMtx(int ** mtx, size_t m);

int main() {
    size_t m = 0; // столбцы
    size_t n = 0; // строки
    std::cin >> m >> n;
    if (!std::cin) return 1; // проверка потока

    int ** mtx = nullptr;

    mtx = makeMtx(mtx, m, n);
    
    for (size_t i = 0; i < m * n; i++) {
        mtx[i / m][i % m] = 0; //заполнение нулями
    }

    if (std::cin.fail()) {


    } // проверка потока второй раз вдруг не вся матрица считалась

    transpose(mtx);
    for (size_t i = 0; i < m * n; i++) {
        std::cout << mtx[i / m][i % m] = 0; //вывод
    }

    rmMtx(mtx, m);
}
