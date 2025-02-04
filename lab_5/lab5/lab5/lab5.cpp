#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;

    int startVertex;

    while (true)
    {
        cout << "Введите начальную вершину для Прима (от 1 до 8, 0 для выхода): ";
        cin >> startVertex;

        if (startVertex == 0) {
            cout << "Завершение программы." << endl;
            break;
        }

        startVertex -= 1;

        if (startVertex >= 0 && startVertex < 8) {
            cout << "PrimsAlgorithm" << endl;
            graph.PrimsAlgorithm(startVertex);

            cout << "KruskalsAlgoritm" << endl;
            graph.KruskalsAlgoritm();
        }
        else {
            cout << "Неверный ввод. Вершина должна быть от 1 до 8." << endl;
        }
    }

    return 0;
}
