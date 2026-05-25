#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    int dem = 0;
    int bills[] = {100,20,10,5,1};
    for(int i = 0;i<5;i++){
        dem += n /bills[i];
        n = n % bills[i];
    }
    cout << dem;
    return 0;
}
