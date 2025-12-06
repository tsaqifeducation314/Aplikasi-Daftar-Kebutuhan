#include <iostream>
#include <string>
#include <vector>
#include "Pengguna.h"

using namespace std;

void cekKembar(vector<pengguna> &db, string &name);
void menu1(int &awal);
void daftar(vector<pengguna> &db);
void login(vector<pengguna> &db);
void menu2(vector<pengguna> &db, int &menu, int p);

int main() {
    int awal = 0;
    vector<pengguna> database;

    while (awal != 3) {
        menu1(awal);
        if (awal == 1) {
            daftar(database);
        } else if (awal == 2) {
            if (database.size() == 0) {
                cout << "Belum ada pengguna terdaftar. Silakan daftar terlebih dahulu." << endl;
                continue;
            }
            login(database);
        } else if (awal == 3) {
            cout << "Sampai jumpa!" << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}

void menu1(int &awal) {
    cout << "\n=== APLIKASI DAFTAR KEBUTUHAN ===" << endl;
    cout << "1. Daftar Pengguna Baru" << endl;
    cout << "2. Login Pengguna" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> awal;
    cin.ignore();
}

void daftar(vector<pengguna> &db) {
    string a;
    cout << "Masukkan nama pengguna baru: ";
    getline(cin, a);
    cekKembar(db, a);
    pengguna user(a);
    db.push_back(user);
    cout << "Pengguna " << a << " berhasil didaftarkan." << endl;
}

void cekKembar(vector<pengguna> &db, string &name) {
    bool namaKembar = true;
    while (namaKembar) {
        namaKembar = false;
        for (int i = 0; i < db.size(); i++) {
            if (db[i].getName() == name) {
                cout << "Nama pengguna sudah terdaftar." << endl;
                cout << "Masukkan nama pengguna baru: ";
                getline(cin, name);
                namaKembar = true;
                break;
            }
        }
    }
}

void login(vector<pengguna> &db) {
    cout << "\n--- Pilih Akun Pengguna ---" << endl;
    for (int i = 0; i < db.size(); i++) {
        cout << i + 1 << ". " << db[i].getName() << endl;
    }
    
    int pilihan;
    cout << "Masukkan nomor pengguna untuk login: ";
    cin >> pilihan;
    cin.ignore();
    
    if (pilihan > 0 && pilihan <= db.size()) {
        int menu = 0;
        pilihan--;
        cout << "\nSelamat datang, " << db[pilihan].getName() << "!" << endl;
        menu2(db, menu, pilihan);
    } else {
        cout << "Nomor pengguna tidak valid." << endl;
    }
}

void menu2(vector<pengguna> &db, int &menu, int p) {
    while (menu != 6) {
        cout << "\n--- User: " << db[p].getName() << " ---" << endl;
        cout << "1. Tambah Kebutuhan" << endl;
        cout << "2. Update Kebutuhan" << endl;
        cout << "3. Hapus Kebutuhan" << endl;
        cout << "4. Tampilkan Kebutuhan" << endl;
        cout << "5. Hitung Total Estimasi" << endl;
        cout << "6. Logout / Kembali" << endl;
        cout << "Masukkan pilihan menu: ";
        cin >> menu;
        cin.ignore();
        
        switch (menu) {
            case 1: db[p].tambahbarang(); break;
            case 2: db[p].update(); break;
            case 3: db[p].hapus(); break;
            case 4: db[p].tampilkan(); break;
            case 5: db[p].totalharga(); break;
            case 6: cout << "Logout berhasil." << endl; break;
            default: cout << "Pilihan tidak valid." << endl; break;
        }
    }
}