#include <iostream>
using namespace std;
int main(){
    long long n,a,b;
    cin >> n >> a >> b;
    long long cost;
    if(b > 2*a){
        cost = n*a;
    }else{
        cost = (n/2) * b + (n % 2) * a;
    }
    cout << cost << endl;
}
