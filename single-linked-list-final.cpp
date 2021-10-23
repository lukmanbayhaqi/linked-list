#include <iostream>
#include <conio.h>
#include <iomanip> //setw()
using namespace std;

struct node
{
      int data;
      node* next; // untuk menghubungkan dengan node lain, tipe data dibuat sama seperi aturan penggunaan pointer.
};

node* head;
node* tail;
node* curr;
node* curr2;
node* curr3;
node* curr4;
node* entry;
node* del;
node* simpan_pos1;
node* simpan_pos2;
node* simpan_pos3;

void inisialisasi()
{
      head = NULL;
      tail = NULL;
}

void input(int dt)
{
      entry = (node* )malloc(sizeof(node)); //alokasi memori
      entry->data = dt;
      entry->next = NULL;
      if(head==NULL)
      {
            head = entry;
            tail = head;
      }
      else
      {
            tail->next = entry;
            tail = entry;
      }
}

void input_depan(int dt)
{
      entry = (node* )malloc(sizeof(node)); //alokasi memori
      entry->data = dt;
      entry->next = NULL;
      if(head==NULL)
      {
            head = entry;
            tail = head;
            tail->next = NULL;
      }
      else
      {
            entry->next = head;
            head = entry;
      }
}

void hapus()
{
      int simpan;
      if(head==NULL)
      {
            cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
      }
      else
      {
            simpan  = head ->data;
            cout<<"\ndata yang dihapus adalah "<<simpan<<endl;
            //hapus depan
            del = head;
            head = head->next;
            delete del;
      }
}

void cetak()
{
      curr = head;
      if(head == NULL)
            cout<<"\ntidak ada data dalam linked list"<<endl;
      else
      {
            cout<<"\nData yang ada dalam linked list adalah"<<endl;
            cout<<setw(6);
            while(curr!=NULL)
            {
                  cout<<curr->data<<"->";
                  curr = curr->next;
            }
                  cout<<"NULL";
            cout<<endl;
      }
}

int hitung_node()
{
    int jumlah = 0;
      curr = head;
      while(curr!=NULL)
    {
        jumlah++;
        curr=curr->next;
    }

      return(jumlah);
}

void hapus_tengah()
{
    float posisi_tengah;

    posisi_tengah =(hitung_node()/2); //'jumlah' dibagi 2, kemudian dibulatkan ke bawah

    int simpan, simpan2;
    if(head==NULL)
    {
         cout<<"\nlinked list kosong, penghapusan tidak bisa dilakukan"<<endl;
    }
    else
    {
         if(hitung_node()<=2){
             hapus();
         }
         else if(hitung_node()==3){
             curr2 = head;
             simpan_pos1 = curr2->next;
             //menyambungkan node awal dengan node akhir
             curr2->next = curr2->next->next;

             simpan2 = simpan_pos1->data;
             cout<<"\ndata yang dihapus adalah "<<simpan2<<endl;

             simpan_pos1->next = NULL;
             delete simpan_pos1;
         }
         else if(hitung_node()>3)
         {
             curr3 = head;
             //menempatkan pointer di posisi "sebelum" tengah
             for(float i = 0; i<posisi_tengah-1; i++){
                curr3 = curr3->next;
                simpan_pos2 = curr3;
             }

             curr4 = head;
             //menempatkan pointer di posisi tengah
             for(float i = 0; i<posisi_tengah; i++){
                curr4 = curr4->next;
                simpan_pos3 = curr4;
             }

             simpan = simpan_pos3->data;
             cout<<"\ndata yang dihapus adalah "<<simpan<<endl;

            //menyambungkan node sebelum 'node tengah' dengan node sesudah 'node tengah'
             simpan_pos2->next = simpan_pos3->next;
           
             //hapus node
             simpan_pos3->next = NULL; //memutus hubungan node sebelum dihapus
             del = simpan_pos3;
             delete del;
        }
    }
}

void tambahsetelah(int old, int element)
{
//gunakan bantuan node temp untuk mencari data
    struct node* newItem;
    newItem=new node;
    struct node* temp;
    temp=head;
    if(head==NULL)
    {
        cout<<"could not insert"<<endl;
        return;
    }
//lakukan pengecekan apakah kode yang dicari sama dengan head, apabila sesuai maka operasi insert dilakukan jika tidak lanjutkan
    if(head==tail)
    {
        if(head->data!=old)
        {
            cout<<"could not insert"<<endl;
            return ;
        }
//Arahkan pointer next ke newitem
        newItem->data=element;
        head->next=newItem;
        newItem->next=NULL;
        tail=newItem;
        return;
    }
    if(tail->data==element)
    {
        newItem->next=NULL;
        tail->next=newItem;
        tail=newItem;
        return;
    }
    while(temp->data!=old)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"Could not insert"<<endl;
            cout<<"element not found"<<endl;
            return;
        }
    }
//arahkan pointer prev yang berada setelah node temp untuk menunjuk node newitem
    newItem->next=temp->next;
    newItem->data=element;
    temp->next=newItem;
}

void menu()
{
      char pilih, ulang;
      int data;

      do
      {
      system("cls");
      cout<<"SINGLE LINKED LIST NON CIRCULAR"<<endl;
      cout<<"-------------------------------"<<endl;
      cout<<"Menu : "<<endl;
      cout<<"1. Input data depan"<<endl;
      cout<<"2. Input data belakang"<<endl;
      cout<<"3. Hapus data depan"<<endl;
      cout<<"4. Hapus data tengah"<<endl;
      cout<<"5. Tambah Setelah Node"<<endl;
      cout<<"6. Cetak"<<endl;
      cout<<"7. Exit"<<endl;
      cout<<"Masukkan pilihan Anda : ";
      cin>>pilih;

      switch(pilih)
      {
      case '1' :
            cout<<"\nMasukkan data : ";
            cin>>data;
            input_depan(data);
            break;
      case '2' :
            cout<<"\nMasukkan data : ";
            cin>>data;
            input(data);
            cetak();
            break;
      case '3' :
            hapus();
            cetak();
            break;
      case '4' :
            hapus_tengah();
            cetak();
            break;
      case '5' :
          int old, newitem;
          cout << "Node setelah item=";
          cin >> old;
          cout << "Masukkan node baru=";
          cin >> newitem;
          tambahsetelah(old, newitem);
          break;
          cetak();
      case '6' :
            cetak();
            break;
      case '7' :
            exit(0);
            break;
      
      default :
            cout<<"\nPilih ulang"<<endl;
      }
      cout<<"\nKembali ke menu?(y/n)";
      cin>>ulang;
      }while(ulang=='y' || ulang=='Y');
}

int main()
{
      inisialisasi();
      menu();

      return EXIT_SUCCESS;
}