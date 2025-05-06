#include <iostream>
#include <string.h>
using namespace std;

// membuat struct node 
class Node {
public: 
    int noMhs;
    Node *next;
};

class Linkedlist {
    Node *START;
public:
    Linkedlist() {
        START = NULL;
    }

    void addNode() {
        int nim;
        cout << "\nMasukan Nomor mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs) {
            if ((START != NULL) && (nim == START->noMhs)) {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs)) {
            if (nim == current->noMhs) {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }
    bool listEmpty()
    {
        return (START ==NULL);
    }
    bool Search (int nim, Node ** previous, Node **current)
    {
        *previous =START;
        *current= START;

        while ((*current != NULL )&& (nim !=(*current )->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return(*current != NULL);
        
    }
    bool delNode(int nim)
    {
        Node *current, *previous ;
        if (!Search (nim, &previous, &current))
             return false;

        if (current == START )
             START = START->next;
        else
            previous->next =current->next;

        delete current;
        return true;
        
    }
    void traverse ()
    {
        if (listEmpty())
        {
            cout<<"\nlist kosong\n";
        }
        else
        {
            cout<<"\nData di dalam list Adalah :\n";
            Node *currentNode = START;
            while (currentNode !=NULL)
            {
                cout<<currentNode->noMhs<<endl;
                currentNode = currentNode->next;
            }
            cout<<endl;

            
        }
        




    }
};
int main()
{
    Linkedlist mhs;
    int nim ;
    char ch;
    while (1)
    {
        cout<<endl
            <<"mENU";
        cout<<endl
            <<"1 .Menambah data kedalam list "<< endl;
        cout<<"2. Menghapus data dari  dalam list "<<endl;
        cout<<"3. mennapilkan data dari  dalam list "<<endl;
        cout<<"4. Mencari data dari  dalam list "<<endl;
        cout<<"5. keluar "<<endl;
        cout<<endl
            <<"Masukan pilihan (1-5) :";


        cin>> ch;
        switch (ch)
        {
            mhs.addNode();
        }
        break;
        case '2':
        {
            if (mhs.listEmpty())
            {
                cout<<endl
                    <<"list kosong "<<endl;
                break;
            }
            cout<<endl
                <<"\nMasukan no mahasiswa yang akan dihapus : ";
            cin>>nim;
            if (mhs.delNode(nim)==false)
                cout<<endl
                    <<"Dta tidak ditemukan "<<endl;
            else
                cout<<endl
                    <<"Data dengan nomor mahasiswa "<<nim <<"berhasil dihabuas "<<endl;
 
        }
        break;
        case '3':
        {
            mhs.traverse();
        }
        break;
        case '4':
        {
            if (mhs.listEmpty() == true)
            {
               cout<<"\nlist kosong\n";
               break;
            }
            Node *previous, * current;
            cout<<endl
                <<"Masukan no mahasiswa yang dicari : ";
            cin>>nim;
            if (mhs.Search(nim,&previous, & current)== false )
                cout<<endl;
            else
            {
                cout<<endl
                    <<"Data ditemukan "<<endl;
                cout<<"\nNo mahasiswa :"<<current->noMhs<<endl;
                cout<<"\n"; 
            }
            break;
             
        }
        case '5':
        {
            exit(0);
        }
        break;
        default:
        {
            cout<<"pihihan salah !. "<<endl;
        }
        break;

    }
    
}
