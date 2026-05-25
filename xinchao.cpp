#include <iostream>
using namespace std;
int main(){
    int x,y,z;
    cin >> x >> y >> z;
    x = sqrt((x*z) / y);
    y = sqrt((y*z) / x);
    z = sqrt((x*y) / z);
    cout << 4*(x+y+z) << endl;
}