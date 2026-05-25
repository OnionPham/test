#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m; 
    if(m > n){
        cout << -1;
        return 0;
    }
    int minMoves = (n + 1) / 2;
    int maxMoves = n;
    for(int k = minMoves;k <= maxMoves;k++){
        if( k % m == 0){
            cout << k << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
