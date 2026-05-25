#include <iostream>
using namespace std;
int main(){
    long long a,b,m;
    cin >> a >> b >> m;
    long long pos = 0;
    for(int i = 1;i<=k;i++){
        if(k % 2 == 1){
            pos += a;
        }
        else{
            pos += b;
        }
    }
    cout << pos << endl;
    return 0;
}
