#include <iostream>
#include <iomanip>
#include <string>

// Menyimpan data mahasiswa dalam array
struct Mahasiswa {
    std::string NIM;
    std::string nama;
    float IPK;
};

// Fungsi untuk menambah data mahasiswa
void tambahMahasiswa(Mahasiswa* mhs[], int &jumlah) {
    if (jumlah >= 10) {
        std::cout << "Data mahasiswa penuh!\n";
        return;
    }

    mhs[jumlah] = new Mahasiswa;
    std::cout << "Masukkan NIM: ";
    std::cin >> mhs[jumlah]->NIM;
    std::cin.ignore();  // Membersihkan buffer untuk menghindari masalah input
    std::cout << "Masukkan Nama: "; //Bisa memasukkan spasi karena output menggunggan getline
    std::getline(std::cin, mhs[jumlah]->nama);  // Menggunakan getline untuk nama lengkap
    std::cout << "Masukkan IPK: "; 
    std::cin >> mhs[jumlah]->IPK;
    jumlah++;
}

// Fungsi untuk menampilkan data mahasiswa dalam bentuk tabel
void tampilkanMahasiswa(Mahasiswa* mhs[], int jumlah) {
    std::cout << std::left << std::setw(15) << "NIM"
              << std::setw(25) << "Nama"
              << std::setw(5) << "IPK" << '\n';
    std::cout << "-----------------------------------------------\n";
    for (int i = 0; i < jumlah; i++) {
        std::cout << std::left << std::setw(15) << mhs[i]->NIM
                  << std::setw(25) << mhs[i]->nama
                  << std::setw(5) << mhs[i]->IPK << '\n';
    }
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusMahasiswa(Mahasiswa* mhs[], int &jumlah, const std::string &NIM) {
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i]->NIM == NIM) {
            delete mhs[i];
            for (int j = i; j < jumlah - 1; j++) {
                mhs[j] = mhs[j + 1];
            }
            jumlah--;
            std::cout << "Data mahasiswa dengan NIM " << NIM << " telah dihapus.\n";
            return;
        }
    }
    std::cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan IPK (bubble sort)
void urutkanMahasiswa(Mahasiswa* mhs[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (mhs[j]->IPK < mhs[j + 1]->IPK) {
                Mahasiswa* temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
    std::cout << "Data mahasiswa berhasil diurutkan berdasarkan IPK.\n";
}

int main() {
    Mahasiswa* mahasiswa[10];
    int jumlah = 0;
    int pilihan;
    std::string NIM;

    do {
        std::cout << "\nMenu:\n"
                  << "1. Tambah Mahasiswa\n"
                  << "2. Tampilkan Mahasiswa\n"
                  << "3. Hapus Mahasiswa\n"
                  << "4. Urutkan Mahasiswa Berdasarkan IPK\n"
                  << "5. Keluar\n"
                  << "Pilihan: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(mahasiswa, jumlah);
                break;
            case 2:
                tampilkanMahasiswa(mahasiswa, jumlah);
                break;
            case 3:
                std::cout << "Masukkan NIM untuk dihapus: ";
                std::cin >> NIM;
                hapusMahasiswa(mahasiswa, jumlah, NIM);
                break;
            case 4:
                urutkanMahasiswa(mahasiswa, jumlah);
                tampilkanMahasiswa(mahasiswa, jumlah);  // Menampilkan tabel setelah pengurutan
                break;
            case 5:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    // Bersihkan memori yang dialokasikan
    for (int i = 0; i < jumlah; i++) {
        delete mahasiswa[i];
    }

    return 0;
}
