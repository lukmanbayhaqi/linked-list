#include <stdio.h>
#include <iostream>
#include <conio.h>
struct Tinggal
{
  char Jalan[40];
  char Kota[15];
  char Pos[5];
};
struct Tgl_Lahir
{
  int Tanggal;
  int Bulan;
  int Tahun;
};
struct Mahasiswa
{
  char Nim[9];
  char Nama[25];
  Tinggal Alamat;
  Tgl_Lahir Lahir;
};

int main()
{
  Mahasiswa Mhs;
  std::cout << "NIM : ";
  std::cin.getline(Mhs.Nim, 9);
  std::cout << "Nama : ";
  std::cin.getline(Mhs.Nama, 25);
  std::cout << "Alamat :\n";
  std::cout << "\tJalan : ";
  std::cin.getline(Mhs.Alamat.Jalan, 40);
  std::cout << "\tKota : ";
  std::cin.getline(Mhs.Alamat.Kota, 15);
  std::cout << "\tKode Pos : ";
  std::cin.getline(Mhs.Alamat.Pos, 5);
  std::cout << "Tanggal Lahir :\n";
  std::cout << "\tTanggal : ";
  std::cin >> Mhs.Lahir.Tanggal;
  std::cout << "\tBulan : ";
  std::cin >> Mhs.Lahir.Bulan;
  std::cout << "\tTahun : ";
  std::cin >> Mhs.Lahir.Tahun;
  std::cout << "\n\nMencetak Kembali Nilai Anggota\n\n";
  std::cout << "NIM : " << Mhs.Nim;
  std::cout << "\nNama : " << Mhs.Nama;
  std::cout << "\nAlamat :\n";
  std::cout << "\n\tJalan : " << Mhs.Alamat.Jalan;
  std::cout << "\n\tKota : " << Mhs.Alamat.Kota;
  std::cout << "\n\tKode Pos: " << Mhs.Alamat.Pos;
  std::cout << "\nTanggal Lahir : " << Mhs.Lahir.Tanggal << "-";
  std::cout << Mhs.Lahir.Bulan << "-" << Mhs.Lahir.Tahun;
  getch();
}
