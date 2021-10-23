#include <iostream>
#include <conio.h>

struct TNode
{
  int data;
  TNode *next;
};

TNode *head, *tail;

int isEmpty()
{
  if (head == NULL)
    return 1;
  else
    return 0;
}

void insertDepan()
{
  system("cls");

  int jumlah;

  TNode *baru;

  std::cout << "Berapa jumlah data yang ingin diinputkan dari depan?";
  std::cin >> jumlah;

  for (int i = 1; i <= jumlah; i++)
  {
    baru = new TNode;

    std::cout << "Data ke-" << i << " = ";
    std::cin >> baru->data;

    baru->next = NULL;

    if (isEmpty() == 1)
    {
      head = tail = baru;
      tail->next = NULL;
    }
    else
    {
      baru->next = head;
      head = baru;
    }
  }
}

void insertBelakang()
{
  system("cls");
  int jumlah;
  TNode *baru;
  std::cout << "Berapa jumlah data yang ingin diinputkan dari belakang?";
  std::cin >> jumlah;
  for (int i = 1; i <= jumlah; i++)
  {
    baru = new TNode;
    std::cout << "Data ke-" << i << " = ";
    std::cin >> baru->data;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
      head = baru;
      tail = baru;
      tail->next = NULL;
    }
    else
    {
      tail->next = baru;
      tail = baru;
    }
  }
}

void tampil()
{
  system("cls");
  TNode *bantu;
  bantu = head;
  if (isEmpty() == 0)
  {
    while (bantu != NULL)
    {
      std::cout << bantu->data << " ";
      bantu = bantu->next;
    }
    std::cout << std::endl;
  }
  else
    std::cout << "Data masih kosong\n";
  getch();
}

void hapusDepan()
{
  TNode *hapus;
  int d;
  int jumlah;
  system("cls");
  if (isEmpty() == 0)
  {
    std::cout << "Berapa jumlah data yang ingin anda hapus dari depan?";
    std::cin >> jumlah;
    for (int i = 1; i <= jumlah; i++)
    {
      if (head != tail)
      {
        hapus = head;
        d = hapus->data;
        head = head->next;
        delete hapus;
      }
      else
      {
        d = tail->data;
        head = tail = NULL;
      }
      std::cout << d << " terhapus\n";
      if (isEmpty() == 1)
      {
        std::cout << "Data sudah kosong " << std::endl;
        break;
      }
    }
  }
  else
    std::cout << "Masih kosong\n";
  getch();
}

void hapusBelakang()
{
  TNode *hapus, *bantu;
  int d;
  int jumlah;
  system("cls");
  if (isEmpty() == 0)
  {
    std::cout << "Berapa jumlah data yang ingin anda hapus dari belakang? ";
    std::cin >> jumlah;
    for (int i = 1; i <= jumlah; i++)
    {
      bantu = head;
      if (head != tail)
      {
        while (bantu->next != tail)
        {
          bantu = bantu->next;
        }
        hapus = tail;
        tail = bantu;
        d = hapus->data;
        delete hapus;
        tail->next = NULL;
      }
      else
      {
        d = tail->data;
        head = tail = NULL;
      }
      std::cout << d << " terhapus\n";
      if (isEmpty() == 1)
      {
        std::cout << "Data sudah kosong" << std::endl;
        break;
      }
    }
  }
  else
    std::cout << "Masih kosong\n";
  getch();
}

void clear()
{
  TNode *bantu, *hapus;
  bantu = head;
  char jawab = 'y';
  system("cls");
  std::cout << "Hapus semua data? [y/t]";
  std::cin >> jawab;
  if (jawab == 'y' || jawab == 'Y')
  {
    while (bantu != NULL)
    {
      hapus = bantu;
      bantu = bantu->next;
      delete hapus;
    }
    head = NULL;
    tail = NULL;
    std::cout << "Semua data sudah terhapus" << std::endl;
  }
  getch();
}

int main()
{
  head = NULL;
  tail = NULL;
  int pilih;
  char jawab = 'y';
menu:
  system("cls");
  std::cout << "Menu : " << std::endl;
  std::cout << "1. Tampilkan data " << std::endl;
  std::cout << "2. Masukkan data dari depan" << std::endl;
  std::cout << "3. Masukkan data dari belakang " << std::endl;
  std::cout << "4. Hapus data paling depan " << std::endl;
  std::cout << "5. Hapus data paling belakang " << std::endl;
  std::cout << "6. Hapus semua data" << std::endl;
  std::cout << "7. Exit" << std::endl
            << std::endl;
  std::cout << "Silahkan pilih menu : [1-7] ";
  std::cin >> pilih;

  switch (pilih)
  {
  case 1:
    tampil();
    goto menu;
  case 2:
    insertDepan();
    goto menu;
  case 3:
    insertBelakang();
    goto menu;
  case 4:
    hapusDepan();
    goto menu;
  case 5:
    hapusBelakang();
    goto menu;
  case 6:
    clear();
    goto menu;
  case 7:
    std::cout << "Ingin keluar aplikasi? [y/t]";
    std::cin >> jawab;
    if (jawab == 'y' || jawab == 'Y')
      break;
    else
      goto menu;
  default:
    std::cout << "Pilihan Salah ! Silahkan ulangi kembali!";
    getch();
    goto menu;
  }
}
