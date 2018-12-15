#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cout << "insert number!" << endl;
    cin >> n;
    stack<int> stk;
    //возрастающее заполнение
    for (int i=0; i < n; i++){
        stk.push(i);
    }
    //вывод
    for (int i=0; i < n; i++) {
        cout << stk.top();
        stk.pop();}
    return 0;
}