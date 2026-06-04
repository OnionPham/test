#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
class SinhVien{
    private:
        string MaSV, HoTen, class_name, email;
    public:
        friend istream& operator >> (istream &in,SinhVien &a);
        friend ostream& operator << (ostream &out,SinhVien a);
        string getLop(){
            return this->class_name;
        }
};
istream& operator >> (istream &in,SinhVien &a){//ham nhap
    getline(in,a.MaSV);
    getline(in,a.HoTen);
    getline(in,a.class_name);
    getline(in,a.email);
    return in;
}
ostream& operator << (ostream &out,SinhVien a){//ham xuat
    out << a.MaSV << " " << a.HoTen << " " << a.class_name << " " << a.email;
    return out;
}
bool cmp(SinhVien a,SinhVien b){
    return a.getLop() < b.getLop();
}
int main(){
    int n;cin >> n;
    cin.ignore();
    vector<SinhVien> ds(n);
    for(int i = 0; i < n; i++){
        cin >> ds[i];
    }
    sort(ds.begin(), ds.end(), cmp);
    for(SinhVien x : ds){
        cout << x << endl;
    }
    return 0;
}