#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
class NhanVien {
private:
	string MaNV, HoTen, GioiTinh, NgaySinh, DiaChi, NgayHD;
	int MaSoThue;
public:
	static int cnt;
	friend istream& operator >> (istream& in, NhanVien& a);
	friend ostream& operator << (ostream& out, NhanVien a);
};
int NhanVien::cnt = 0;
istream& operator >> (istream& in, NhanVien& a) {
	NhanVien::cnt++;
	a.MaNV = to_string(NhanVien::cnt);
	in.ignore();
	cout << "Nhap Ten: "; getline(in, a.HoTen);
	cout << "Gioi Tinh: "; getline(in, a.GioiTinh);
	cout << "Ngay Sinh: "; getline(in, a.NgaySinh);
	cout << "dia chi: "; getline(in, a.DiaChi);
	cout << "MaSoThue"; in >> a.MaSoThue;
	in.ignore();
	cout << "Ngay Ki Hop Dong: "; getline(in, a.NgayHD);
	return in;
}
ostream& operator << (ostream& out, NhanVien a) {
	out << setfill('0') << setw(5) << a.MaNV << " " << a.HoTen << " " << a.GioiTinh << " " << a.NgaySinh << " " << a.DiaChi << " " << a.MaSoThue << " " << a.NgayHD << endl;
	return out;
}
int main() {
	int n; cin >> n;
	vector <NhanVien> a(n);
	for (auto &x : a) cin >> x;
	for (auto x : a)cout << x;
	return 0;
}