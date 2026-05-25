#include <iostream>
using namespace std;
int main(){
    long long n,S;
    cin >> n >> S;
    long long result = S/n;
    if(S % n != 0){
        result++;
    }
    cout << result << endl;
    return 0;
}
