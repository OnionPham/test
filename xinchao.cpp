#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    long long Tong = x * y;
    int domino = 2, dem = 0;
    while(Tong >= domino){//khi nao ma domino == Tong thi dung
        Tong -= domino;
        dem++;
    }
    cout << dem;
}
