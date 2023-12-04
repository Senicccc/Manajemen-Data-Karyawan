#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Deklarasi fungsi
void menu();
void menu2 ();
void bersih();
void kepala();
void daftar();
void keluar ();
void simpanS();
void baca_data();
void baca_pass();  // Deklarasi fungsi baca_pass
void halamanSetelahDaftar(); // Deklarasi fungsi halamanSetelahDaftar

int dex = 0;
int jumStruct = 10;

struct data_kar {
    // Definisi struktur untuk data_kar
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
    // Definisi struktur untuk data_temp
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

    string username, password;
    int pilih;
    int login;
    int i = 1;
    char a;
    cout << "||                      MENU UTAMA                          ||\n";
    cout << "==============================================================\n";
    cout << "[1] Login \n";
    cout << "[2] Daftar \n";
    cout << "[3] Keluar \n";

    cout << "Pilih Menu: ";
    cin >> pilih;

    switch (pilih) {
        case 1:

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
            } else {
                i = i + 1;
                cout << "\nUsername atau Password Salah!" << endl;
                cout << endl;
                cout << "Apakah anda ingin mencoba lagi? (y)  ";
                cin >> a;
                bersih();
                kepala();
                return menu ();
            }
            bersih();
            return menu2();
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

// Implementasi fungsi daftar
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
            dex = i;  // Atur nilai dex agar sesuai dengan indeks data terakhir yang dimasukkan
            break;
        }
    }

    simpanS();

    cout << "============ Akun anda telah berhasil dibuat! ============\n\n";
    cout << "Tekan Enter untuk kembali ke Menu Utama...";
    cin.ignore(); // Membersihkan buffer sebelum menunggu input Enter
    cin.get();    // Menunggu input Enter
    bersih();     // Bersihkan konsol setelah Enter ditekan
}

void keluar () {
    cout << "\n\nTekan tombol apapun untuk keluar dari program...\n";
}

void menu2()
{
    ifstream infile;
    infile.open("file.dat", ios::in | ios::out | ios::app);
    baca_data();
    infile.close();
    kepala();
    cout << "||                       Pilih Menu                        ||\n";
    cout << "=============================================================\n";
    cout << "[1] Lihat Semua Data\n";
    cout << "[2] Cari Data\n";
    cout << "[3] Tambah Data\n";
    cout << "[4] Urutkan Nama Ascending\n";
    cout << "[5] Logout\n";
    cout << "[6] Exit\n";

    int pilih = 0;
    cout << "\nPilih Menu: ";
    cin >> pilih;
}

// Implementasi fungsi baca_pass
void baca_pass() {
    // Tambahkan implementasi sesuai kebutuhan
}

// Implementasi fungsi bersihkanKonsol
void bersihkanKonsol() {
    // Tambahkan implementasi sesuai kebutuhan
}

// Implementasi fungsi simpanS
void simpanS() {
    // Tambahkan implementasi sesuai kebutuhan
}

void baca_data () {
}
