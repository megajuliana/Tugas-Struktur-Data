#include <iostream>
using namespace std;

//output
//nama karyawan : andri
//tanggal masuk : 04 febuari 2021
//alamat : Jl.M.Toha.Cianjur
//Gaji Perbulan : Rp. 2750000


struct Tanggal { 
	int hari;
	string bulan;
	int tahun;
};

struct Alamat {
	string jalan;
	string kota;
};

struct Karyawan {
	string nama;
	int gaji;
	Tanggal tanggalMasuk;
	Alamat alamat;
};

int main(){
	Karyawan k1;
	k1.nama = "andri" ;
	k1.gaji = 2750000 ;
	k1.tanggalMasuk.hari =  04;
	k1.tanggalMasuk.bulan = "febuari";
	k1.tanggalMasuk.tahun = 2021;

	cout << "Nama : " << k1.nama << endl; 
	cout << "Tanggal Masuk : " << k1.tanggalMasuk.hari << "" 
		 << k1.tanggalMasuk.bulan << " " 
		 << k1.tanggalMasuk.tahun << endl; 
	cout << "Alamat : " << k1.alamat.jalan << " " <<  k1.alamat.kota << endl; 
	cout << "Gaji Perbulan : " << k1.gaji << endl; 

}
