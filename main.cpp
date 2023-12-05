#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> // input output manipulator

using namespace std;

// Deklarasi fungsi
void menu();
void masuk();
void daftar();
void keluar();
void bersih();
void kepala();
void simpan();
void simpan2();
void baca_data();
void baca_pass();
void menu2();

int dex = 0;
int jumStruct = 10;

struct data_kar {
    string jabatan;
    string nama;
    int umur;
    string goldar;
    string alamat;
    string status;
    string jk;
    string user;
    string pass;
};

struct data_temp {
    string jabatan;
    string nama;
    int umur;
    string goldar;
    string alamat;
    string status;
    string gender;
};

data_kar karyawan[10];
data_temp temp[1];

int main() {
    do {
        bersih();
        kepala();
        menu();
    } while (true);

    return 0;
}

void bersih() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Unix-like systems
    #endif
}


void kepala() {
    cout << " \t\t\APLIKASI MANAJEMEN DATA KARYAWAN\n\t\t    PT. RIND BERSAMA SUKSES \n";
    cout << "==============================================================\n";
}

void menu() {
    ifstream dataku;
    dataku.open("dataku.txt", ios::in | ios::out | ios::app);
    baca_pass();
    dataku.close();

    int pilih;
    cout << "||                      MENU UTAMA                          ||\n";
    cout << "==============================================================\n";
    cout << "[1] Login \n";
    cout << "[2] Daftar \n";
    cout << "[3] Keluar \n";

    cout << "Pilih Menu: ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            masuk();
            break;
        case 2:
            daftar();
            break;
        case 3:
            bersih();
            keluar();
            exit(0);
            break;
    }
}

void masuk() {
    string username, password;
    int login;
    int i = 1;
    char a;

    bersih();
    kepala();
    cout << "||                          LOGIN                           ||\n";
    cout << "==============================================================\n";
    cout << " Username : ";
    cin >> username;
    cout << " Password : ";
    cin >> password;

    login = 0;
    for (int s = 0; s < jumStruct; s++) {
        if (username == karyawan[s].user && password == karyawan[s].pass) {
            login = 1;
        }
    }

    if (login == 1) {
        cout << "Anda Berhasil Login" << endl;
        bersih();
        menu2();

    } else {
        i = i + 1;
        cout << "\nUsername atau Password Salah!" << endl;
        cout << endl;

        // Pilihan untuk login lagi atau kembali ke menu awal
        cout << "Opsi: \n";
        cout << "1. Coba login lagi\n";
        cout << "2. Kembali ke Menu Utama\n";
        cout << "Masukkan opsi pilihan anda: ";
        cin >> a;

        if (a == '1') {
            bersih();
            kepala();
            masuk(); // Login lagi
        } else {
            cout << "Pilihan tidak valid. Kembali ke Menu Utama." << endl;
            bersih();
            kepala();
            menu(); // Kembali ke menu utama
        }
    }
}

void daftar() {
    bersih();
    kepala();

    for (int i = 0; i < jumStruct; i++) {
        if (karyawan[i].user == "") {
            cout << "||                   PENDAFTARAN AKUN                       ||\n";
            cout << "==============================================================\n";
            cout << " Silakan buat username dan password anda\n";
            cout << " Username: ";
            cin >> karyawan[i].user;
            cout << " Password: ";
            cin >> karyawan[i].pass;
            dex = i;
            break;
        }
    }

    simpan();

    cout << "============ Akun anda telah berhasil dibuat! ============\n\n";
    cout << "Tekan Enter untuk kembali ke Menu Utama...";
    cin.ignore();
    cin.get();
    bersih();
    kepala();
    return menu();
}

void keluar() {
    cout << "\n\nTekan tombol apapun untuk keluar dari program...\n";
}

   void cari();
   void tambah();
   void tampil();

void menu2() {

   bool urut = false;

   char balik;

    ifstream infile;
    infile.open("file.dat", ios::in | ios::out | ios::app);
    baca_data();
    infile.close();
    kepala();


    cout << "||                       PILIH MENU                        ||\n";
    cout << "=============================================================\n";
    cout << "[1] Cari Data Karyawan\n";
    cout << "[2] Tambah Data Karyawan\n";
    cout << "[3] Lihat Semua Data Karyawan\n";
    cout << "[4] Urutkan Nama Ascending\n";
    cout << "[5] Logout\n";
    cout << "[6] Exit\n";



   int pilih = 0;
    cout << "\nPilih Menu: ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        bersih();
        cari();
        bersih();
        break;
    case 2:
        bersih();
        tambah();
        bersih();
        return menu2();
        break;
    case 3:
        bersih();
        tampil();
        bersih();
        cout << "Kembali ke menu? (y/n)";
        cin >> balik;
        if (balik == 'y')
        {
            kepala();
            bersih();
            return menu2();
        }
        break;
    case 4:
        urut = true;
        return menu2();
        break;
    case 5:
        return menu();
        break;
    case 6:
        bersih();
        exit(0);
    }
}

void terHapus();
void terEdit();
void tidakValid();

void cari() {
    kepala();
    bool ketemu = false;
    int ind = 0;
    char hapus, edit;
    string key;
    cout << "||                      PENCARIAN DATA                      ||\n";
    cout << "==============================================================\n";
    cout << "Cari data: ";
    cin >> key;
    for (int i = 0; i < dex; i++)
    {
        if (key == karyawan[i].nama)
        {
            bersih();
            kepala();
            cout << "||                      PENCARIAN DATA                      ||\n";
            cout << "==============================================================\n";
            cout << "Data "
                 << "\"" << karyawan[i].nama << "\""
                 << " ditemukan\n\n";
            cout << setw(5) << left << "No"
                 << setw(13) << left << "Nama"
                 << setw(8) << left << "Gender"
                 << setw(5) << left << "Umur"
                 << setw(13) << left << "Alamat"
                 << setw(10) << left << "Jabatan"
                 << setw(10) << left << "Status" << endl;
            cout << "=============================================================\n";

            if (karyawan[i].nama != "")
            {
                cout << setw(5) << left << i + 1 << setw(13) << left;
                cout << karyawan[i].nama << setw(8) << left;
                cout << karyawan[i].jk << setw(5) << left;
                cout << karyawan[i].umur << setw(13) << left;
                cout << karyawan[i].alamat << setw(10) << left;
                cout << karyawan[i].jabatan << setw(10) << left;
                cout << karyawan[i].status << endl;
            }
            ind = i;
            ketemu = true;
        }
    }
    if (ketemu == true)
    {
        int pilih;
        cout << "\n=============================================================\n";
        cout << "[1] Hapus Data\n";
        cout << "[2] Edit Data\n";
        cout << "[3] Kembali ke Menu Pilihan\n";
        cout << "Pilihan: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
//Menghapus Data
            bersih();
            kepala();
            cout << "Hapus data? (y/n)";
            cin >> hapus;
            if (hapus == 'y')
            {
                for (int i = 1; i < dex; i++)
                {
                    karyawan[i] = karyawan[i + 1];
                }
                dex--;
                simpan();
                return terHapus();
            }
            else if (hapus == 'n')
            {
                break;
                return menu2();
            }
        case 2:
//Mengedit data
            cout << "\nEdit data:\n";
            cout << "Nama: ";
            cin >> karyawan[ind].nama;
            cout << "Umur: ";
            cin >> karyawan[ind].umur;
            cout << "Gender: ";
            cin >> karyawan[ind].jk;
            cout << "Alamat: ";
            cin >> karyawan[ind].alamat;
            cout << "Status: ";
            cin >> karyawan[ind].status;
            cout << "Jabatan: ";
            cin >> karyawan[ind].jabatan;
            simpan();
            bersih();
            return terEdit();
//Kembali ke menu
        case 3:
            bersih();
            return menu2();
        }
    }
    if (ketemu != true) //jika yang dicari tidak ada
    {
        return tidakValid();
    }
}

char balik;

void tidakValid()
{
    bersih();
    kepala();
    cout << "Data tidak ditemukan! [Error 404]\n";
    cout << "Kembali ke menu pilihan? (y/n)";
    cin >> balik;
    if (balik == 'y')
    {
        bersih();
        return menu2();
    }
}

void terEdit()
{
    bersih();
    kepala();
    cout << "Data Berhasil Diedit!\n";
    cout << "Kembali ke menu? (y/n)";
    cin >> balik;
    if (balik == 'y')
    {
        bersih();
        return menu2();
    }
}

void terHapus()
{
    bersih();
    kepala();
    cout << "Data Berhasil Dihapus!\n";
    cout << "Kembali ke menu pilihan? (y/n)";
    cin >> balik;
    if (balik == 'y')
    {
        bersih();
        return menu2();
    }
}


void tambah() {
    bersih();
    kepala();
    for (int i = 0; i < jumStruct; i++)
    {
        if (karyawan[i].nama == "")
        {
            cout << "\nTambah data: \n";
            cout << "Nama: ";
            cin >> karyawan[i].nama;
            cout << "Umur: ";
            cin >> karyawan[i].umur;
            cout << "Jenis Kelamin: ";
            cin >> karyawan[i].jk;
            cout << "Alamat: ";
            cin >> karyawan[i].alamat;
            cout << "Status: ";
            cin >> karyawan[i].status;
            cout << "Jabatan: ";
            cin >> karyawan[i].jabatan;
            break;
        }
    }
    dex++;
    simpan2();
    cout << "========== Data berhasil ditambahkan! ==========\n\n";
    system ("pause"); // untuk pause agar pengguna bisa melohat output diatas terlebih dahulu
    bersih();

}

void tampil() {
    // Implementation of the 'tampil' function
}

void baca_pass() {
    // Tambahkan implementasi sesuai kebutuhan
}

// buat simpan data username dan password
void simpan()
{
    ofstream outfile;
    outfile.open("file2.dat");
    for (int i = 0; i < jumStruct; i++)
    {
        if (karyawan[i].user != "")
        {
            outfile << karyawan[i].user << "|";
            outfile << karyawan[i].pass << "|" << endl;
        }
    }
    outfile.close();
}

// simpan2 ini buat simpan data karyawan
void simpan2() {
    ofstream outfile;
    outfile.open("file.dat");
    for (int i = 0; i < jumStruct; i++)
    {
        if (karyawan[i].nama != "")
        {
            outfile << karyawan[i].nama << "|";
            outfile << karyawan[i].umur << "|";
            outfile << karyawan[i].jk << "|";
            outfile << karyawan[i].alamat << "|";
            outfile << karyawan[i].jabatan << "|";
            outfile << karyawan[i].status << "|" << endl;
        }
    }
    outfile.close();
}

void baca_data() {
    // Tambahkan implementasi sesuai kebutuhan
}
