# Jawaban Soal 5: Manajemen Perpustakaan Menggunakan Array, Pointer, Struct, Stack, dan Queue

Program ini adalah simulasi manajemen perpustakaan sederhana yang menggunakan beberapa struktur data, yaitu **array of pointers**, **stack**, dan **queue**. Program ini memiliki fitur untuk menambah, mencari, dan menampilkan data buku, serta mengelola peminjaman dan pengembalian buku menggunakan antrian dan riwayat.

## Penjelasan Kode

### 1. Struct `Buku`

`struct Buku` digunakan untuk menyimpan informasi setiap buku dalam koleksi perpustakaan. Setiap buku memiliki:

- `ISBN` (string): Kode unik buku.
- `judul` (string): Judul buku.
- `pengarang` (string): Nama pengarang buku.
- `tahunTerbit` (int): Tahun terbit buku.

```cpp
struct Buku {
    std::string ISBN;
    std::string judul;
    std::string pengarang;
    int tahunTerbit;
};
```

### 2. Class `Perpustakaan`

Kelas `Perpustakaan` berisi array of pointers untuk menyimpan data buku, stack untuk menyimpan riwayat peminjaman, dan queue untuk mengelola antrian peminjaman. Kelas ini memiliki metode-metode untuk menjalankan operasi manajemen perpustakaan.

```cpp
class Perpustakaan {
private:
    Buku* koleksiBuku[100];
    int jumlahBuku = 0;
    std::stack<std::string> riwayatPeminjaman;
    std::queue<std::string> antrianPeminjaman;

public:
    // Menambahkan buku ke koleksi
    void tambahBuku(const std::string& ISBN, const std::string& judul, const std::string& pengarang, int tahunTerbit);

    // Mencari buku berdasarkan ISBN
    Buku* cariBuku(const std::string& ISBN);

    // Menampilkan semua buku dalam koleksi
    void tampilkanKoleksi();

    // Meminjam buku
    void pinjamBuku(const std::string& ISBN);

    // Mengelola proses peminjaman
    void prosesPeminjaman();

    // Mengembalikan buku
    void kembalikanBuku();

    // Menampilkan riwayat peminjaman
    void tampilkanRiwayat();

    // Destructor untuk membersihkan memori
    ~Perpustakaan();
};
```

### 3. Metode `Perpustakaan`

#### `tambahBuku`

Menambahkan buku baru ke koleksi perpustakaan. Jika koleksi sudah penuh (maksimal 100 buku), program akan menampilkan pesan bahwa koleksi penuh.

```cpp
void tambahBuku(const std::string& ISBN, const std::string& judul, const std::string& pengarang, int tahunTerbit) { ... }
```

#### `cariBuku`

Mencari buku berdasarkan ISBN. Fungsi ini mengembalikan pointer ke buku jika ditemukan, atau `nullptr` jika buku tidak ada di koleksi.

```cpp
Buku* cariBuku(const std::string& ISBN) { ... }
```

#### `tampilkanKoleksi`

Menampilkan semua buku dalam koleksi perpustakaan, dengan informasi ISBN, judul, pengarang, dan tahun terbit.

```cpp
void tampilkanKoleksi() { ... }
```

#### `pinjamBuku`

Menambahkan buku ke dalam antrian peminjaman berdasarkan ISBN. Jika buku ditemukan, ISBN akan ditambahkan ke `antrianPeminjaman`.

```cpp
void pinjamBuku(const std::string& ISBN) { ... }
```

#### `prosesPeminjaman`

Memproses peminjaman buku dari antrian peminjaman. Buku yang diproses akan ditambahkan ke `riwayatPeminjaman`.

```cpp
void prosesPeminjaman() { ... }
```

#### `kembalikanBuku`

Menghapus buku dari `riwayatPeminjaman` saat buku dikembalikan.

```cpp
void kembalikanBuku() { ... }
```

#### `tampilkanRiwayat`

Menampilkan daftar buku yang telah dipinjam dari `riwayatPeminjaman`.

```cpp
void tampilkanRiwayat() { ... }
```

### 4. Main Function

Fungsi `main` memberikan menu interaktif untuk pengguna, memungkinkan mereka memilih operasi seperti menambah buku, menampilkan koleksi, mencari buku, meminjam dan mengembalikan buku, serta melihat riwayat peminjaman.

```cpp
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
```

---

## Contoh Penggunaan Program

### Menambah Buku

```
Pilihan: 1
Masukkan ISBN: 12345
Masukkan Judul: Struktur Data
Masukkan Pengarang: John Doe
Masukkan Tahun Terbit: 2021
Buku berhasil ditambahkan!
```

### Menampilkan Koleksi Buku

```
Pilihan: 2
Koleksi Buku:
ISBN: 12345, Judul: Struktur Data, Pengarang: John Doe, Tahun Terbit: 2021
```

### Meminjam Buku

```
Pilihan: 4
Masukkan ISBN buku yang ingin dipinjam: 12345
Buku dengan ISBN 12345 masuk ke dalam antrian peminjaman.
```

### Proses Peminjaman

```
Pilihan: 5
Buku dengan ISBN 12345 telah dipinjam.
```

### Kembalikan Buku

```
Pilihan: 6
Buku dengan ISBN 12345 telah dikembalikan dan disimpan ke dalam riwayat.
```

### Tampilkan Riwayat Peminjaman

```
Pilihan: 7
Riwayat Peminjaman Buku:
ISBN: 12345
```
