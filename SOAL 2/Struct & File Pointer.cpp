#include <iostream>
#include <iomanip>
#include <string>

struct Peralatan {
    std::string kode;
    std::string nama;
    int jumlah;
    std::string kondisi;
};

const int MAX_PERALATAN = 10;  // Maksimal jumlah peralatan yang dapat disimpan
Peralatan inventaris[MAX_PERALATAN];
int jumlahPeralatan = 0;

// Fungsi untuk menambah data peralatan
void tambahPeralatan() {
    if (jumlahPeralatan >= MAX_PERALATAN) {
        std::cout << "Data inventaris penuh!\n";
        return;
    }

    std::cout << "Masukkan kode peralatan: ";
    std::cin >> inventaris[jumlahPeralatan].kode;
    std::cin.ignore();
    std::cout << "Masukkan nama peralatan: ";
    std::getline(std::cin, inventaris[jumlahPeralatan].nama);
    std::cout << "Masukkan jumlah: ";
    std::cin >> inventaris[jumlahPeralatan].jumlah;
    std::cin.ignore();
    std::cout << "Masukkan kondisi peralatan: ";
    std::getline(std::cin, inventaris[jumlahPeralatan].kondisi);
    
    jumlahPeralatan++;
    std::cout << "Data peralatan berhasil ditambahkan.\n";
}

// Fungsi untuk mengubah data peralatan berdasarkan kode
void ubahPeralatan(const std::string &kode) {
    for (int i = 0; i < jumlahPeralatan; i++) {
        if (inventaris[i].kode == kode) {
            std::cout << "Masukkan nama baru: ";
            std::getline(std::cin, inventaris[i].nama);
            std::cout << "Masukkan jumlah baru: ";
            std::cin >> inventaris[i].jumlah;
            std::cin.ignore();
            std::cout << "Masukkan kondisi baru: ";
            std::getline(std::cin, inventaris[i].kondisi);
            std::cout << "Data berhasil diubah.\n";
            return;
        }
    }
    std::cout << "Peralatan dengan kode " << kode << " tidak ditemukan.\n";
}

// Fungsi untuk menghapus data peralatan berdasarkan kode
void hapusPeralatan(const std::string &kode) {
    for (int i = 0; i < jumlahPeralatan; i++) {
        if (inventaris[i].kode == kode) {
            for (int j = i; j < jumlahPeralatan - 1; j++) {
                inventaris[j] = inventaris[j + 1];
            }
            jumlahPeralatan--;
            std::cout << "Data peralatan dengan kode " << kode << " telah dihapus.\n";
            return;
        }
    }
    std::cout << "Peralatan dengan kode " << kode << " tidak ditemukan.\n";
}

// Fungsi untuk menampilkan data peralatan dalam bentuk tabel
void tampilkanPeralatan() {
    std::cout << std::left << std::setw(10) << "Kode"
              << std::setw(25) << "Nama"
              << std::setw(10) << "Jumlah"
              << std::setw(15) << "Kondisi" << '\n';
    std::cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < jumlahPeralatan; i++) {
        std::cout << std::left << std::setw(10) << inventaris[i].kode
                  << std::setw(25) << inventaris[i].nama
                  << std::setw(10) << inventaris[i].jumlah
                  << std::setw(15) << inventaris[i].kondisi << '\n';
    }
}

// Fungsi untuk mengurutkan data peralatan berdasarkan kode menggunakan bubble sort
void urutkanPeralatan() {
    for (int i = 0; i < jumlahPeralatan - 1; i++) {
        for (int j = 0; j < jumlahPeralatan - i - 1; j++) {
            if (inventaris[j].kode > inventaris[j + 1].kode) {
                Peralatan temp = inventaris[j];
                inventaris[j] = inventaris[j + 1];
                inventaris[j + 1] = temp;
            }
        }
    }
    std::cout << "Data peralatan berhasil diurutkan berdasarkan kode.\n";
}

int main() {
    int pilihan;
    std::string kode;

    do {
        std::cout << "\nMenu:\n"
                  << "1. Tambah Peralatan\n"
                  << "2. Ubah Peralatan\n"
                  << "3. Hapus Peralatan\n"
                  << "4. Tampilkan Peralatan\n"
                  << "5. Urutkan Peralatan Berdasarkan Kode\n"
                  << "6. Keluar\n"
                  << "Pilihan: ";
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan) {
            case 1:
                tambahPeralatan();
                break;
            case 2:
                std::cout << "Masukkan kode peralatan yang ingin diubah: ";
                std::getline(std::cin, kode);
                ubahPeralatan(kode);
                break;
            case 3:
                std::cout << "Masukkan kode peralatan yang ingin dihapus: ";
                std::getline(std::cin, kode);
                hapusPeralatan(kode);
                break;
            case 4:
                tampilkanPeralatan();
                break;
            case 5:
                urutkanPeralatan();
                tampilkanPeralatan();  // Menampilkan tabel setelah pengurutan
                break;
            case 6:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}
