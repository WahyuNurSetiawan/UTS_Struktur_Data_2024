# Jawaban Soal 2: Program Sederhana Pengelolaan Inventaris Peralatan Laboratorium

Program ini adalah versi sederhana yang digunakan untuk mengelola data inventaris peralatan laboratorium. Program ini memiliki fitur untuk menambah, mengubah, menghapus, menampilkan, dan mengurutkan data peralatan.

## Penjelasan Kode

### 1. Struktur Data `Peralatan`

`struct Peralatan` digunakan untuk menyimpan informasi setiap peralatan, yang terdiri dari:

- `kode` (string): Kode unik untuk setiap peralatan.
- `nama` (string): Nama peralatan.
- `jumlah` (int): Jumlah peralatan yang tersedia.
- `kondisi` (string): Kondisi peralatan, seperti "Baik" atau "Rusak".

```cpp
struct Peralatan {
    std::string kode;
    std::string nama;
    int jumlah;
    std::string kondisi;
};
```

### 2. Array Statis untuk Menyimpan Data

Array `inventaris` dengan kapasitas maksimal 10 elemen digunakan untuk menyimpan daftar peralatan.

```cpp
const int MAX_PERALATAN = 10;
Peralatan inventaris[MAX_PERALATAN];
int jumlahPeralatan = 0;
```

### 3. Fungsi `tambahPeralatan`

Fungsi ini memungkinkan pengguna untuk menambahkan data peralatan baru ke dalam array `inventaris`. Jika array penuh, program akan memberikan pesan bahwa data tidak bisa ditambahkan.

```cpp
void tambahPeralatan() { ... }
```

### 4. Fungsi `ubahPeralatan`

Fungsi ini memungkinkan pengguna untuk mengubah informasi peralatan berdasarkan kode yang diberikan.

```cpp
void ubahPeralatan(const std::string &kode) { ... }
```

### 5. Fungsi `hapusPeralatan`

Fungsi ini menghapus data peralatan berdasarkan kode. Jika kode ditemukan, data akan dihapus dengan menggeser elemen-elemen setelahnya ke depan.

```cpp
void hapusPeralatan(const std::string &kode) { ... }
```

### 6. Fungsi `tampilkanPeralatan`

Fungsi ini menampilkan data peralatan dalam bentuk tabel dengan kolom yang rapi.

```cpp
void tampilkanPeralatan() { ... }
```

### 7. Fungsi `urutkanPeralatan`

Mengurutkan data peralatan berdasarkan kode menggunakan algoritma _bubble sort_ untuk membuatnya lebih mudah dipahami oleh pemula.

```cpp
void urutkanPeralatan() { ... }
```

### 8. Program Utama (`main`)

Pada fungsi `main`, terdapat menu interaktif yang memungkinkan pengguna memilih operasi yang ingin dijalankan: menambah, mengubah, menghapus, menampilkan, mengurutkan data peralatan, atau keluar dari program.

```cpp
int main() { ... }
```

---

## Contoh Input dan Output

Berikut adalah contoh interaksi dengan program, yang meliputi operasi menambah, mengubah, menampilkan, mengurutkan, dan menghapus data peralatan.

### 1. Menambahkan Peralatan

```
Menu:
1. Tambah Peralatan
2. Ubah Peralatan
3. Hapus Peralatan
4. Tampilkan Peralatan
5. Urutkan Peralatan Berdasarkan Kode
6. Keluar
Pilihan: 1

Masukkan kode peralatan: A001
Masukkan nama peralatan: Mikroskop
Masukkan jumlah: 5
Masukkan kondisi peralatan: Baik
Data peralatan berhasil ditambahkan.

Pilihan: 1

Masukkan kode peralatan: B002
Masukkan nama peralatan: Tabung Reaksi
Masukkan jumlah: 10
Masukkan kondisi peralatan: Baik
Data peralatan berhasil ditambahkan.

Pilihan: 1

Masukkan kode peralatan: A003
Masukkan nama peralatan: Gelas Ukur
Masukkan jumlah: 7
Masukkan kondisi peralatan: Rusak
Data peralatan berhasil ditambahkan.
```

### 2. Menampilkan Data Peralatan

```
Pilihan: 4

Kode      Nama                     Jumlah   Kondisi
-----------------------------------------------------------
A001      Mikroskop                5        Baik
B002      Tabung Reaksi            10       Baik
A003      Gelas Ukur               7        Rusak
```

### 3. Mengubah Data Peralatan Berdasarkan Kode

```
Pilihan: 2
Masukkan kode peralatan yang ingin diubah: A003

Masukkan nama baru: Gelas Ukur Besar
Masukkan jumlah baru: 8
Masukkan kondisi baru: Baik
Data berhasil diubah.
```

### 4. Mengurutkan Data Berdasarkan Kode

```
Pilihan: 5
Data peralatan berhasil diurutkan berdasarkan kode.

Kode      Nama                     Jumlah   Kondisi
-----------------------------------------------------------
A001      Mikroskop                5        Baik
A003      Gelas Ukur Besar         8        Baik
B002      Tabung Reaksi            10       Baik
```

### 5. Menghapus Peralatan Berdasarkan Kode

```
Pilihan: 3
Masukkan kode peralatan yang ingin dihapus: A001
Data peralatan dengan kode A001 telah dihapus.
```

### 6. Menampilkan Data Setelah Penghapusan

```
Pilihan: 4

Kode      Nama                     Jumlah   Kondisi
-----------------------------------------------------------
A003      Gelas Ukur Besar         8        Baik
B002      Tabung Reaksi            10       Baik
```
