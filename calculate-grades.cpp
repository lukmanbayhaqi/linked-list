#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

struct mahasiswa
   {
       char nim[20];
       char nama[30];
       float nilai1;
       float nilai2;
       float nilai3;
       float nilai4;
       float hasil;
   }mhs;
   

int main(){
    int i,j=1;
    for(i=0;i<1;i++)
   {
       cout<<"Rekap Nilai Mahasiswa Mengunakan Structure"<<endl;
       cout<<"------------------------------------------"<<endl;
       cout<<" "<<endl;
       cout<<"Masukkan NIM           :"; cin>>mhs.nim;
       cout<<"Masukkan Nama          :"; cin>>mhs.nama;
       cout<<"Masukkan Nilai Absensi :"; cin>>mhs.nilai1;
       cout<<"Masukkan Nilai Tugas   :"; cin>>mhs.nilai2;
       cout<<"Masukkan Nilai UTS     :"; cin>>mhs.nilai3;
       cout<<"Masukkan Nilai UAS     :";cin>>mhs.nilai4;
       mhs.hasil=(mhs.nilai1*0.10)+(mhs.nilai2*0.20)+(mhs.nilai3*0.30)+(mhs.nilai4*0.40);
       cout<<endl;
   }
 
   for(i=0;i<1;i++)
   

   {
       cout<<"Hasil Rekap Nilai Mahasiswa"<<endl;
       cout<<"------------------------------------------"<<endl;
       cout<<"Data Mahasiswa ke-"<<j++<<endl;
       cout<<"NIM Mahasiswa  :"<<mhs.nim<<endl;
       cout<<"Nama Mahasiswa :"<<mhs.nama<<endl;
       cout<<"Nilai Absensi  :"<<mhs.nilai1<<endl;
       cout<<"Nilai Tugas    :"<<mhs.nilai2<<endl;
       cout<<"Nilai UTS      :"<<mhs.nilai3<<endl;
       cout<<"Nilai UAS      :"<<mhs.nilai4<<endl;
       if(mhs.hasil>=80 && mhs.hasil<=100)
       cout<<"Nilai Akhir    :A"<<endl;
       else if(mhs.hasil>=70 && mhs.hasil<=79)
       {
       cout<<"Nilai Akhir    :B+"<<endl;
       }
       else if(mhs.hasil>=60 && mhs.hasil<=69)
       {
       cout<<"Nilai Akhir    :B"<<endl;
       }
       else if(mhs.hasil>=50 && mhs.hasil<=59)
       {
       cout<<"Nilai Akhir    :C+"<<endl;
       }
       else if(mhs.hasil>=40 && mhs.hasil<=49)
       {
       cout<<"Nilai Akhir    :C"<<endl;
       }
       else if(mhs.hasil>=30 && mhs.hasil<=39)
       {
       cout<<"Nilai Akhir    :D"<<endl;
       }
       else
       {
       cout<<"Nilai Akhir    :E"<<endl;
       }
       cout<<"=========================================="<<endl;
       cout<<"Tuliskan Nama Pembuat       : Mega Setiawati"<<endl;
       cout<<"Tuliskan NIM Pembuat        : 41820110010"<<endl;
       cout<<"Tuliskan Nama Program Studi : Sistem Informasi"<<endl;
       cout<<endl;
       return 0;
   }
}