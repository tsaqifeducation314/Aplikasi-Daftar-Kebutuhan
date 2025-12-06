#include "Pengguna.h"
#include <limits>

pengguna::pengguna(string a) {
    nama = a;
}

string pengguna::getName() {
    return nama;
}

void pengguna::tambahbarang() {
    kebutuhan item;
    cout << "Masukkan nama barang: ";
    getline(cin, item.barang);
    
    cout << "Masukkan harga barang: ";
    cin >> item.harga;
    cin.ignore();
    
    daftar_kebutuhan.push_back(item);
    cout << item.barang << " berhasil ditambahkan." << endl;
}

void pengguna::tampilkan() {
    if (daftar_kebutuhan.empty()) {
        cout << "Daftar kebutuhan masih kosong." << endl;
        return;
    }
    cout << "Daftar kebutuhan untuk " << nama << ":\n";
    for (int i = 0; i < daftar_kebutuhan.size(); i++) {
        cout << i + 1 << ". " << daftar_kebutuhan[i].barang 
             << ": Rp " << daftar_kebutuhan[i].harga << endl;
    }
}

void pengguna::update() {
    if (daftar_kebutuhan.empty()) {
        cout << "Daftar kebutuhan masih kosong." << endl;
        return;
    }
    tampilkan();
    int index;
    cout << "Masukkan nomor barang yang ingin diupdate: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > daftar_kebutuhan.size()) {
        cout << "Nomor barang tidak valid." << endl;
        return;
    }

    cout << "Masukkan nama barang baru (kosongkan jika tidak ingin mengubah): " << endl;
    string nama_baru;
    getline(cin, nama_baru);
    if (!nama_baru.empty()) {
        daftar_kebutuhan[index-1].barang = nama_baru;
    }

    cout << "Masukkan harga barang baru (masukkan 0 jika tidak ingin mengubah): " << endl;
    double harga_baru;
    cin >> harga_baru;
    cin.ignore();
    if (harga_baru != 0) {
        daftar_kebutuhan[index-1].harga = harga_baru;
    }
    cout << "Barang berhasil diupdate." << endl;
}

void pengguna::hapus() {
    if (daftar_kebutuhan.empty()) {
        cout << "Daftar kebutuhan masih kosong." << endl;
        return;
    }
    tampilkan();
    int index;
    cout << "Masukkan nomor barang yang ingin dihapus: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > daftar_kebutuhan.size()) {
        cout << "Nomor barang tidak valid." << endl;
        return;
    }
    
    daftar_kebutuhan.erase(daftar_kebutuhan.begin() + index - 1);
    cout << "Barang berhasil dihapus." << endl;
}

void pengguna::totalharga() {
    double total = 0.0;
    for (int i = 0; i < daftar_kebutuhan.size(); i++) {
        total += daftar_kebutuhan[i].harga;
    }
    cout << "Estimasi total harga: Rp " << total << endl;
}