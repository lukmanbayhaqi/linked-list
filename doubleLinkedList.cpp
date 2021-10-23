#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <memory>

int pil;

void pilih();

void buat_baru();

void tambah_belakang();

void tambah_depan();

void tambah_tengah();

void hapus_belakang();

void hapus_depan();

void tampil();

struct simpul
{
  char nim[8], nama[20];
  int umur;
  struct simpul *kiri, *tengah, *kanan;
} mhs, *baru, *awal = NULL, *pertengahan = NULL, *akhir = NULL, *hapus, *bantu;

int main()
{
  do
  {
    system("cls");

    std::cout << "MENU DOUBLE LINKEDLIST" << std::endl;
    std::cout << "0. Tambah Tengah" << std::endl;
    std::cout << "1. Tambah Depan" << std::endl;
    std::cout << "2. Tambah Belakang" << std::endl;
    std::cout << "3. Hapus Depan" << std::endl;
    std::cout << "4. Hapus Belakang" << std::endl;
    std::cout << "5. Tampilkan" << std::endl;
    std::cout << "6. Selesai" << std::endl;
    std::cout << "Pilihan Anda : ";
    std::cin >> pil;

    pilih();
  } while (pil != 6);

  return 0;
}

void pilih()
{
  if (pil == 0)
    tambah_tengah();
  else if (pil == 1)
    tambah_depan();
  else if (pil == 2)
    tambah_belakang();
  else if (pil == 3)
    hapus_depan();
  else if (pil == 4)
    hapus_belakang();
  else if (pil == 5)
    tampil();
  else
    std::cout << "selesai";
}

void buat_baru()
{
  baru = (simpul *)malloc(sizeof(struct simpul));

  std::cout << "input nim : ";
  std::cin >> baru->nim;
  std::cout << "input nama : ";
  std::cin >> baru->nama;
  std::cout << "input umur : ";
  std::cin >> baru->umur;

  baru->kiri = NULL;
  baru->tengah = NULL;
  baru->kanan = NULL;
}

void tambah_belakang()
{
  buat_baru();

  if (awal == NULL)
  {
    awal = baru;
    pertengahan = baru;
    akhir = baru;
  }
  else
  {
    akhir->kanan = baru;
    baru->kiri = akhir;
    akhir = baru;
  }

  std::cout << std::endl
            << std::endl;

  tampil();
}

void tambah_depan()
{
  buat_baru();

  if (awal == NULL)
  {
    awal = baru;
    pertengahan = baru;
    akhir = baru;
  }
  else
  {
    baru->kanan = awal;
    awal->kiri = baru;
    awal = baru;

    /*
    baru = {
      kanan: awal
    }
    awal = {
      kiri: baru
    }
    awal = baru
    */
  }

  std::cout << std::endl
            << std::endl;

  tampil();
}

void tambah_tengah()
{
  buat_baru();

  if (awal == NULL)
  {
    awal = baru;
    pertengahan = baru;
    akhir = baru;
  }
  else
  {
    // pertengahan->tengah = baru;
    // baru->tengah = pertengahan;
    // pertengahan = baru;

    /*
      pertengahan->kanan = baru;
      baru->kiri = pertengahan;
      pertengahan = baru;
    */

    awal->kiri = baru;
    pertengahan->tengah = baru;
    akhir->kanan = baru;
    baru->kiri = pertengahan;
    pertengahan = baru;
  }

  std::cout << std::endl
            << std::endl;

  tampil();
}

void hapus_depan()
{
  if (awal == NULL)
    std::cout << "Kosong";
  else if (awal->kanan == NULL)
  {
    hapus = awal;
    awal = NULL;
    akhir = NULL;

    free(hapus);
  }
  else
  {
    hapus = awal;
    awal = hapus->kanan;
    awal->kiri = NULL;

    free(hapus);
  }

  std::cout << std::endl
            << std::endl;

  tampil();
}

void hapus_belakang()
{
  if (awal == NULL)
    std::cout << "Kosong";
  else if (awal->kanan == NULL)
  {
    hapus = awal;
    awal = NULL;
    akhir = NULL;

    free(hapus);
  }
  else
  {
    hapus = akhir;
    akhir = hapus->kiri;
    akhir->kanan = NULL;

    free(hapus);
  }

  std::cout << std::endl
            << std::endl;

  tampil();
}

void tampil()
{
  if (awal == NULL)
    std::cout << "Kosong";
  else
  {
    bantu = awal;

    while (bantu != NULL)
    {
      std::cout << " nim : " << bantu->nim;
      std::cout << " nama : " << bantu->nama;
      std::cout << " umur : " << bantu->umur << std::endl;

      bantu = bantu->kanan;
    }
  }

  getch();
}
