#include <iostream>
using namespace std;


void hanoi(int n, int from, int to, int temp) {
    if (n == 1) {
        cout << "Переместить диск 1 с " << from << " на " << to << " стержень" << endl;
    }
    else {
      
        hanoi(n - 1, from, temp, to);
        cout << "Переместить диск " << n << " с " << from << " на " << to << " стержень" << endl;
        hanoi(n - 1, temp, to, from);
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int N; 
    int k; 
    int i;
    cout << "Введите количество дисков (N): ";
    cin >> N;
    a:
    cout << "Введите номер стержня, на котором находятся диски: ";
    cin >> i;
    cout << "Введите номер стержня, на который нужно переместить диски: ";
    cin >> k;
    cout << '\n';
    if (i == k) {
        cout << "Ошибка!!! Введите значения заново... ";
        goto a;
    }
    int temp = 6 - i - k; 

    hanoi(N, i, k, temp);

    return 0;
}