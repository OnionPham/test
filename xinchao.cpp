#include <iostream>
using namespace std;
int main(){
    int k,n,w;
    cin >> k >> n >> w;
    int MoneyNeed = 0;
    for(int i = 1;i<=w;i++){
        MoneyNeed += i*k;
    }
    if(MoneyNeed < n){
        cout << 0;
        return 0;
    }
    else{
        cout << MoneyNeed - n;
    }
    return 0;
}
