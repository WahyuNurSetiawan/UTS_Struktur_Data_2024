# Jawaban Soal 1: Pengelolaan Data Mahasiswa Menggunakan Array dan Pointer

Pada soal ini, kita diminta untuk mengimplementasikan program yang mengelola data mahasiswa menggunakan **array** dan **pointer**. Program ini memiliki fitur menambah, menghapus, menampilkan, dan mengurutkan data mahasiswa berdasarkan IPK. Berikut adalah penjelasan untuk setiap bagian dari program:

## 1. Struktur Data Mahasiswa
Kita mendefinisikan sebuah `struct` bernama `Mahasiswa` yang memiliki tiga anggota:
- `NIM` (string): Nomor Induk Mahasiswa.
- `nama` (string): Nama lengkap mahasiswa.
- `IPK` (float): Indeks Prestasi Kumulatif mahasiswa.

```cpp
struct Mahasiswa {
    std::string NIM;
    std::string nama;
    float IPK;
};
```

## 2. Fungsi Menambah Data Mahasiswa
Fungsi `tambahMahasiswa` digunakan untuk menambah data mahasiswa baru. Fungsi ini menerima input NIM, nama, dan IPK dari pengguna. Kami menggunakan `std::getline` untuk membaca nama lengkap agar mendukung spasi.

```cpp
void tambahMahasiswa(Mahasiswa* mhs[], int &jumlah) {
    if (jumlah >= 10) {
        std::cout << "Data mahasiswa penuh!\n";
        return;
    }
    mhs[jumlah] = new Mahasiswa;
    std::cout << "Masukkan NIM: ";
    std::cin >> mhs[jumlah]->NIM;
    std::cin.ignore();
    std::cout << "Masukkan Nama: ";
    std::getline(std::cin, mhs[jumlah]->nama);
    std::cout << "Masukkan IPK: ";
    std::cin >> mhs[jumlah]->IPK;
    jumlah++;
}
```

## 3. Fungsi Menampilkan Data Mahasiswa dalam Bentuk Tabel
Fungsi `tampilkanMahasiswa` menampilkan seluruh data mahasiswa yang telah ditambahkan dalam bentuk tabel. Kami menggunakan `std::setw` untuk mengatur lebar kolom agar tampilan data lebih rapi.

```cpp
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
```

## 4. Fungsi Menghapus Data Mahasiswa Berdasarkan NIM
Fungsi `hapusMahasiswa` memungkinkan penghapusan data mahasiswa berdasarkan NIM. Jika NIM ditemukan, data akan dihapus dan elemen-elemen setelahnya akan digeser untuk mengisi celah.

```cpp
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
```

## 5. Fungsi Mengurutkan Data Mahasiswa Berdasarkan IPK
Fungsi `urutkanMahasiswa` mengurutkan data mahasiswa berdasarkan IPK menggunakan algoritma *bubble sort*. Data akan diurutkan secara menurun (descending), dari IPK tertinggi ke terendah.

```cpp
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
```

## 6. Program Utama (Main Function)
Pada fungsi utama, terdapat menu untuk memilih operasi yang diinginkan, seperti menambah, menampilkan, menghapus, mengurutkan data mahasiswa, atau keluar dari program.

```cpp
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
                tampilkanMahasiswa(mahasiswa, jumlah);
                break;
            case 5:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    for (int i = 0; i < jumlah; i++) {
        delete mahasiswa[i];
    }

    return 0;
}
```

## Kesimpulan
Program soal pertama ini:
- Menggunakan `array of pointers` untuk menyimpan data 10 mahasiswa.
- Mengimplementasikan fungsi untuk menambah, menghapus, menampilkan, dan mengurutkan data mahasiswa.
- Menyajikan data dalam bentuk tabel dengan kolom NIM, Nama, dan IPK.
