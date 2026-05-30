#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
using namespace std;
struct SinhVien{
    string MaSV,TenSV,TenLop,NS;
    double DiemGPA;
};
istream& operator>>(istream& in, SinhVien& sv){
    cout << "Ma SV: ";
    getline(in,sv.MaSV);
    cout << "Ten SV: ";
    getline(in,sv.TenSV);
    cout << "Ten Lop: ";
    getline(in,sv.TenLop);
    cout << "Nam Sinh: ";
    getline(in,sv.NS);
    cout << "GPA: ";
    in >> sv.DiemGPA;
    in.ignore();
    //cin -> in (ooperator)
    return in;
}
ostream& operator <<(ostream &out, const SinhVien& sv){
    out << sv.MaSV << " | " << sv.TenSV << " | " << sv.TenLop << " | " << sv.NS << " | " << sv.DiemGPA;
    //cout -> out (operator)
    return out;
}
//cau 1
void ThemSV(vector <SinhVien>&ds){
    SinhVien x;
    cin >> x;
    ds.push_back(x);
}
//cau 2
void HienDS(const vector <SinhVien> &ds){
    if(ds.empty()){
        cout << "danh sach khong ton tai";
        return;
    }
    
    for(const auto &x : ds){
        cout << x << endl;
    }
}
//cau 3
void Search(const vector <SinhVien> &ds){
    string key;
    cout << "nhap tu khoa can tim: ";
    getline(cin,key);
    bool found = false;
    for(const auto&x : ds){
        if(x.MaSV.find(key) != string::npos ||
        x.TenSV.find(key) != string::npos || 
        x.TenLop.find(key) != string::npos){
            cout << x << endl;
            found = true;
        }
    }
    if(!found){
        cout << "khong tim thay";
    }
}
//cau 4
void GPA_Max(const vector<SinhVien>&ds){
    if(ds.empty())return;
    double mx = ds[0].DiemGPA;
    for(const auto &x : ds){
        mx = max(mx,x.DiemGPA);
        }
        cout << "Sinh Vien co GPA cao nhat: " << endl;
        for(const auto &x : ds){
            if(x.DiemGPA == mx){
                cout << x << endl;
            }
        }
    }
//cau 5
bool cmp(const SinhVien &a, const SinhVien &b){
    return a.DiemGPA > b.DiemGPA;//sap xep giam dan
}
void LietKe_GPA25(vector<SinhVien>&ds){
    vector<SinhVien>result;
    for(const auto &x : ds){
        if(x.DiemGPA >= 2.5){
            result.push_back(x);
        }
    }
    if(result.empty()){
        cout << "khong co sinh vien nao co GPA >= 2.5";
        return;
    }
    sort(result.begin(),result.end(),cmp);
    cout << "Danh sach sinh vien co GPA >= 2.5: " << endl;
    for(const auto &x : result){
        cout << x << endl;
    }
}
//cau 6
string chuanhoa(string name){
    stringstream ss(name);
    vector <string> words;
    string token,res = "";
    while(ss >> token){
        words.push_back(token);
    }
    if (words.empty()) return "";
    res += words[words.size() - 1];
    for(int i = 0; i < words.size() - 1; i++){
        res += " " + words[i];
    }
    return res;//tra ve ten da chuan hoa de sap xep theo ten (ho va ten)
}
bool cmpTen(const SinhVien & a, const SinhVien & b){
    return chuanhoa(a.TenSV) < chuanhoa(b.TenSV);//sap xep tang dan theo ten
}
void SapXep_Ten(vector<SinhVien>&ds){
    sort(ds.begin(),ds.end(),cmpTen);//sap xep tang dan theo ten
}
//cau 7
bool cmp_Lop(const SinhVien & a, const SinhVien & b){
    if(a.TenLop == b.TenLop){
        return chuanhoa(a.TenSV) < chuanhoa(b.TenSV);//sap xep tang dan theo ten neu cung lop
    }
    return a.TenLop < b.TenLop;
}
void sapXepLopTen(vector<SinhVien>&ds){
    sort(ds.begin(),ds.end(),cmp_Lop);
}
//cau 8
bool cmp_LopGPA(const SinhVien & a, const SinhVien & b){
    if(a.TenLop == b.TenLop){
        return a.DiemGPA > b.DiemGPA;//sap xep giam dan theo GPA neu cung lop
    }
    return a.TenLop < b.TenLop;
}
void sapXepLopGPA(vector<SinhVien>&ds){
    sort(ds.begin(),ds.end(),cmp_LopGPA);
}
int main(){
    vector<SinhVien>ds;
    int choice;
    do{
         cout << "\n========== MENU ==========\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "4. Liet ke GPA cao nhat\n";
        cout << "5. Liet ke GPA >= 2.5\n";
        cout << "6. Sap xep theo ten\n";
        cout << "7. Sap xep theo lop, ten\n";
        cout << "8. Sap xep theo lop, GPA\n";
        cout << "0. Thoat\n";

        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore();

        switch(choice){

        case 1:
            ThemSV(ds);
            break;

        case 2:
            HienDS(ds);
            break;

        case 3:
            Search(ds);
            break;

        case 4:
            GPA_Max(ds);
            break;

        case 5:
            LietKe_GPA25(ds);
            break;

        case 6:
            SapXep_Ten(ds);
            cout << "Da sap xep!\n";
            break;

        case 7:
            sapXepLopTen(ds);
            cout << "Da sap xep!\n";
            break;

        case 8:
            sapXepLopGPA(ds);
            cout << "Da sap xep!\n";
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }
        
    }while(choice != 0);
    return 0;
}

