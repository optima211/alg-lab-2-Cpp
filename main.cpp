#include <iostream>
#include <stack>

using namespace std;
int n, select, kol_ser = 0, ser, kontr_sum;

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
                kontr_sum += stk.top();
                cout << stk.top() << "   ";
            }
            break;
        case 2://заполнение по убыванию
            cout << "Start decrease" << endl;
            for (int i = 0, b = n + 1; i < b; b--) {
                stk.push(b);
                kontr_sum += stk.top();
                cout << stk.top() << "   ";
            }
            break;
        case 3://заполнение случайными числами
            cout << "Start random" << endl;
            for (int i = 0; i < n; i++) {
                stk.push(rand() % 100);
                kontr_sum += stk.top();
                cout << stk.top() << "   ";
            }
            break;
        default:
            cout << endl << "write correct number!";
            break;
    }
    cout << endl << "Please, select:" << endl << "4- Print stack" << endl << "5- Count control sum" << endl
         << "6- Count series" << endl;
    cin >> select;
    switch (select) {
        case 4://вывод
            cout << "Output data" << endl;
            for (int i = 0; i < n; i++) {
                cout << stk.top() << "   ";
                stk.pop();
            }
            break;
        case 5:
            printf("\nCount control sum:%d\n", kontr_sum);
            break;
        case 6://подсчет количества серий
            ser = 0;//not work!!!!!!!!!!!
            for (int i = 1; i < n; i++) {
                ser = stk.top();
//                if (stk[i - 1] != stk[i])
//                    kol_ser++;
//                stk.pop();
            }
            printf("\nCount series:%d\n", kol_ser);
            break;
        default:
            cout << endl << "write correct number!";
            break;
    }
    cout << endl << "thank you for using our program. come again!";
    return 0;
}