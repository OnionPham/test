#include <iostream>
using namespace std;
int main(){
    int x,y,z;
    cin >> x >> y >> z;
    long long a = sqrt((x*z) / y);
    long long b = sqrt((y*z) / x);
    long long c = sqrt((x*y) / z);
    cout << 4*(a+b+c) << endl;
}
