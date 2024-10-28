#include <iostream>
#include <string>
#include <queue>
#include <stack>

struct Buku {
    std::string ISBN;
    std::string judul;
    std::string pengarang;
    int tahunTerbit;
};

class Perpustakaan {
private:
    Buku* koleksiBuku[100];
    int jumlahBuku = 0;
    std::stack<std::string> riwayatPeminjaman;
    std::queue<std::string> antrianPeminjaman;

public:
    // Menambahkan buku ke koleksi
    void tambahBuku(const std::string& ISBN, const std::string& judul, const std::string& pengarang, int tahunTerbit) {
        if (jumlahBuku >= 100) {
            std::cout << "Koleksi penuh!\n";
            return;
        }
        koleksiBuku[jumlahBuku] = new Buku{ISBN, judul, pengarang, tahunTerbit};
        jumlahBuku++;
        std::cout << "Buku berhasil ditambahkan!\n";
    }

    // Mencari buku berdasarkan ISBN
    Buku* cariBuku(const std::string& ISBN) {
        for (int i = 0; i < jumlahBuku; i++) {
            if (koleksiBuku[i]->ISBN == ISBN) {
                return koleksiBuku[i];
            }
        }
        return nullptr;
    }

    // Menampilkan semua buku dalam koleksi
    void tampilkanKoleksi() {
        std::cout << "Koleksi Buku:\n";
        for (int i = 0; i < jumlahBuku; i++) {
            std::cout << "ISBN: " << koleksiBuku[i]->ISBN 
                      << ", Judul: " << koleksiBuku[i]->judul
                      << ", Pengarang: " << koleksiBuku[i]->pengarang
                      << ", Tahun Terbit: " << koleksiBuku[i]->tahunTerbit << '\n';
        }
    }

    // Meminjam buku
    void pinjamBuku(const std::string& ISBN) {
        Buku* buku = cariBuku(ISBN);
        if (buku) {
            antrianPeminjaman.push(ISBN);
            std::cout << "Buku dengan ISBN " << ISBN << " masuk ke dalam antrian peminjaman.\n";
        } else {
            std::cout << "Buku tidak ditemukan!\n";
        }
    }

    // Mengelola proses peminjaman
    void prosesPeminjaman() {
        if (antrianPeminjaman.empty()) {
            std::cout << "Tidak ada antrian peminjaman.\n";
            return;
        }

        std::string ISBN = antrianPeminjaman.front();
        antrianPeminjaman.pop();
        riwayatPeminjaman.push(ISBN);
        std::cout << "Buku dengan ISBN " << ISBN << " telah dipinjam.\n";
    }

    // Pengembalian buku (menyimpan ke riwayat)
    void kembalikanBuku() {
        if (riwayatPeminjaman.empty()) {
            std::cout << "Tidak ada buku yang sedang dipinjam.\n";
            return;
        }

        std::string ISBN = riwayatPeminjaman.top();
        riwayatPeminjaman.pop();
        std::cout << "Buku dengan ISBN " << ISBN << " telah dikembalikan dan disimpan ke dalam riwayat.\n";
    }

    // Menampilkan riwayat peminjaman
    void tampilkanRiwayat() {
        std::stack<std::string> temp = riwayatPeminjaman;
        std::cout << "Riwayat Peminjaman Buku:\n";
        while (!temp.empty()) {
            std::cout << "ISBN: " << temp.top() << '\n';
            temp.pop();
        }
    }

    // Destructor untuk membersihkan memori
    ~Perpustakaan() {
        for (int i = 0; i < jumlahBuku; i++) {
            delete koleksiBuku[i];
        }
    }
};

int main() {
    Perpustakaan perpustakaan;
    int pilihan;
    std::string ISBN, judul, pengarang;
    int tahunTerbit;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tambah Buku\n";
        std::cout << "2. Tampilkan Koleksi Buku\n";
        std::cout << "3. Cari Buku\n";
        std::cout << "4. Pinjam Buku\n";
        std::cout << "5. Proses Peminjaman Buku\n";
        std::cout << "6. Kembalikan Buku\n";
        std::cout << "7. Tampilkan Riwayat Peminjaman\n";
        std::cout << "8. Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan ISBN: ";
                std::cin >> ISBN;
                std::cin.ignore();
                std::cout << "Masukkan Judul: ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan Pengarang: ";
                std::getline(std::cin, pengarang);
                std::cout << "Masukkan Tahun Terbit: ";
                std::cin >> tahunTerbit;
                perpustakaan.tambahBuku(ISBN, judul, pengarang, tahunTerbit);
                break;
            case 2:
                perpustakaan.tampilkanKoleksi();
                break;
            case 3:
                std::cout << "Masukkan ISBN buku yang dicari: ";
                std::cin >> ISBN;
                if (perpustakaan.cariBuku(ISBN)) {
                    std::cout << "Buku ditemukan!\n";
                } else {
                    std::cout << "Buku tidak ditemukan!\n";
                }
                break;
            case 4:
                std::cout << "Masukkan ISBN buku yang ingin dipinjam: ";
                std::cin >> ISBN;
                perpustakaan.pinjamBuku(ISBN);
                break;
            case 5:
                perpustakaan.prosesPeminjaman();
                break;
            case 6:
                perpustakaan.kembalikanBuku();
                break;
            case 7:
                perpustakaan.tampilkanRiwayat();
                break;
            case 8:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 8);

    return 0;
}
