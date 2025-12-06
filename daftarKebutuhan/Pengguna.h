#ifndef PENGGUNA_H
#define PENGGUNA_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct kebutuhan {
    long double harga;
    string barang;
};

class pengguna {
private:
    string nama;
    vector<kebutuhan> daftar_kebutuhan;

public:
    pengguna(string a);

    string getName();
    void tambahbarang();
    void tampilkan();
    void update();
    void hapus();
    void totalharga();
};

#endif