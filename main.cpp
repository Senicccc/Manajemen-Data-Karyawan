#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Deklarasi fungsi
void menu();
void masuk();
void daftar();
void keluar();
void bersih();
void kepala();
void simpanS();
void baca_data();
void baca_pass();
void menu2();
void halamanSetelahDaftar();

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
    system("cls");
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

    simpanS();

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


    cout << "||                       Pilih Menu                        ||\n";
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
        cari();
        break;
    case 2:
        tambah();
        return menu2();
        break;
    case 3:
        tampil();
        cout << "Kembali ke menu? (y/n)";
        cin >> balik;
        if (balik == 'y')
        {
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

void cari() {
    // Implementation of the 'cari' function
}

void tambah() {
    // Implementation of the 'tambah' function
}

void tampil() {
    // Implementation of the 'tampil' function
}

void baca_pass() {
    // Tambahkan implementasi sesuai kebutuhan
}

void bersihkanKonsol() {
    // Tambahkan implementasi sesuai kebutuhan
}

void simpanS() {
    // Tambahkan implementasi sesuai kebutuhan
}

void baca_data() {
    // Tambahkan implementasi sesuai kebutuhan
}
