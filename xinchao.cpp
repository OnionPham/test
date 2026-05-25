#include <iostream>
using namespace std;
int main(){
    int a,b,s;
    cin >> a >> b >> s;
    int dist = a + b;
    if (dist > s || (s - dist) % 2 != 0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
