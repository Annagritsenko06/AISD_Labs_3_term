#include <iostream>
#include <vector>
#include <iomanip>

const int INF = 10000000000; 

void floydWarshall(std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& next) {
    int n = dist.size();

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF) {
                std::cout << std::setw(4) << "INF";
            }
            else {
                std::cout << std::setw(4) << matrix[i][j];
            }
        }
        std::cout << std::endl;
    }
} 

int main() {
    setlocale(LC_CTYPE, "RUS");
    
    std::vector<std::vector<int>> dist = {
        {  0,  28,  21,  59,  12,  27 },
        {  7,   0,  24, INF,  21,   9 },
        {  9,  32,   0,  13,  11, INF },
        {  8, INF,   5,   0,  16, INF },
        { 14,  13,  15,  10,   0,  22 },
        { 15,  18, INF, INF,   6,   0 }
    };

 
    std::vector<std::vector<int>> next = {
        { 0, 2, 3, 4, 5, 6 },
        { 1, 0, 3, 4, 5, 6 },
        { 1, 2, 0, 4, 5, 6 },
        { 1, 2, 3, 0, 5, 6 },
        { 1, 2, 3, 4, 0, 6 },
        { 1, 2, 3, 4, 5, 0 }
    };

    
    floydWarshall(dist, next);

    std::cout << "Матрица кратчайших путей (D):" << std::endl;
    printMatrix(dist);

    std::cout << "\nМатрица последовательностей вершин (S):" << std::endl;
    printMatrix(next);

    return 0;
}
