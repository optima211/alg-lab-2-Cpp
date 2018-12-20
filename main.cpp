#include <iostream>
#include <stack>

using namespace std;
int n, select, kol_ser = 0, ser1 = 0, ser2 = 0, sum;
int *A = new int[100];

void Merge(int *A, int first, int last) {
    int middle, start, final, j;
    int *mas = new int[100];
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        } else {
            mas[j] = A[final];
            final++;
        }
//возвращение результата в список
    for (j = first; j <= last; j++) A[j] = mas[j];
    delete[]mas;
};

//рекурсивная процедура сортировки
void MergeSort(int *A, int first, int last) {
    {
        if (first < last) {
            MergeSort(A, first, (first + last) / 2); //сортировка левой части
            MergeSort(A, (first + last) / 2 + 1, last); //сортировка правой части
            Merge(A, first, last); //слияние двух частей
        }
    }
};

int main() {
    cout << "Hello" << endl << "insert number!" << endl;
    cin >> n;
    stack<int> stk;
    cout << "Please, select:" << endl << "1- Insert data in stack (increase)" << endl
         << "2- Insert data in stack (decrease)" << endl << "3- Insert data in stack (random)" << endl;
    cin >> select;
    switch (select) {
        case 1://заполнение по возрастанию
            cout << "Start increase" << endl;
            for (int i = 0; i < n; i++) {
                stk.push(i);
                sum += stk.top();
                cout << stk.top() << "   ";
            }
            break;
        case 2://заполнение по убыванию
            cout << "Start decrease" << endl;
            for (int i = 0, b = n + 1; i < b; b--) {
                stk.push(b);
                sum += stk.top();
                cout << stk.top() << "   ";
            }
            break;
        case 3://заполнение случайными числами
            cout << "Start random" << endl;
            for (int i = 0; i < n; i++) {
                stk.push(rand() % 100);
                sum += stk.top();
                cout << stk.top() << "   ";
            }
            break;
        default:
            cout << endl << "write correct number!\n";
            system("PAUSE");
            return 0;
    }
    cout << endl << "\nPlease, select:" << endl << "4- Print stack" << endl << "5- Count control sum" << endl
         << "6- Count series" << endl;
    cin >> select;
    switch (select) {
        case 4://вывод
            cout << "\nOutput data\n" << endl;
            for (int i = 0; i < n; i++) {
                cout << stk.top() << "   ";
                stk.pop();
            }
            break;
        case 5:
            printf("\nCount control sum:%d\n", sum);
            break;
        case 6://подсчет количества серий
            kol_ser = 0;
            for (int i = 1; i < n; i++) {
                ser1 = stk.top();
                stk.pop();
                ser2 = stk.top();
                if (ser2 != (ser1 + 1))
                    kol_ser++;
            }
            printf("\nCount series:%d\n", kol_ser);
            break;
        default:
            cout << endl << "\nwrite correct number!\n";
            system("PAUSE");
            return 0;
    }
    cout << endl << "\nwrite <7> for start sort procedure:\n";
    cin >> select;
    switch (select) {
        case 7:
            for (int i = 1; i <= n; i++) {
                A[i] = stk.top();
                stk.pop();
            }
            for (int i = 1; i <= n; i++) cout << A[i] << " ";
            MergeSort(A, 1, n); //вызов сортирующей процедуры
            cout << "\n\noutput sorted massive: \n"; //вывод упорядоченного массива
            for (int i = 1; i <= n; i++) {
                cout << A[i] << " ";
            }
            cout
                    << "\n\nif you want sort increase- press <1>:\nif you want sort decrease- press <2>:"; //вывод упорядоченного массива
            cin >> select;
            if (select == 1) {
                for (int i = 1; i <= n; i++) {
                    cout << A[i] << " ";
                }
            }
            if (select == 2) {
                for (int i = n; i > 0; i--) {
                    cout << A[i] << " ";
                }
            }
            break;
        default:
            cout << endl << "\nwrite correct number!\n";
            system("PAUSE");
            return 0;
    }
    cout << endl << "\nthank you for using our program. come again!\n";
    system("PAUSE");
    return 0;
}