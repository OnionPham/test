#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;
class GiaoVien {
private:
	string HoTen, Nganh, MaGV;
public:
	static int cnt;
	friend istream& operator >> (istream& in, GiaoVien& a);
	string ChuanHoa_Nganh();
    string getName() {
        return HoTen;
    }
    string getMaGV() {
        return MaGV;
    }
    string getLaseName(){
        string res = "";
        stringstream ss(HoTen);
        string token;
        while (ss >> token) {
            res = token;
        }
        return res;
    }
	friend ostream& operator << (ostream& out, GiaoVien a);
};
string GiaoVien::ChuanHoa_Nganh() {
	string res = "";
	stringstream ss(Nganh);
	string token;
	while (ss >> token) {
		res += toupper(token[0]);
	}
	return res;
}
int GiaoVien::cnt = 0;
istream& operator >> (istream& in, GiaoVien& a) {
	GiaoVien::cnt++;
	a.MaGV = "GV" + (GiaoVien::cnt < 10 ? "0" : "") + to_string(GiaoVien::cnt);
    cout << "nhap ho ten: ";
	getline(in, a.HoTen);
    cout << "nhap nganh: ";
	getline(in, a.Nganh);
    return in;
}
ostream& operator << (ostream& out, GiaoVien a) {
    out << a.MaGV << " " << a.HoTen << " " << a.ChuanHoa_Nganh() << endl;
    return out;
}
bool cmp(GiaoVien a, GiaoVien b) {
    if (a.getLaseName() != b.getLaseName()) {
        return a.getLaseName() < b.getLaseName();
    }
    return a.getMaGV() < b.getMaGV();
}
int main() {
	int n; cout << "nhap so luong test case: "; cin >> n; cin.ignore();
	vector<GiaoVien>a(n);
	for (auto& x : a)cin >> x;
	sort(a.begin(), a.end(), cmp);
	for (auto x : a)cout << x;
	return 0;
}