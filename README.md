# Ujian Tengah Semester (UTS) Struktur Data 2024/2025
**Nama**: Wahyu Nur Setiawan  
**NIM**: 2009076017  
**Program Studi:** Teknik Elektro  
**Fakultas:** Teknik Universitas Mulawarman  
**Mata Kuliah:** Struktur Data  
**Tanggal:** Senin, 21 Oktober 2024  
**Batas Waktu:** Rabu, 28 Oktober 2024 Pukul 17.00 WITA  
**Sifat Ujian:** Take Home (Dikumpulkan pada repository GitHub)  
**Dosen Pengampu:** Dr. Eng. Ir. Aji Ery Burhandenny, S.T., M.AIT.

---

## Petunjuk Umum

1. Kerjakan semua soal dengan bahasa pemrograman **C++**.
2. Wajib menggunakan **preprocessor directive iostream** untuk penggunaan `cin` dan `cout` (input/output).
   > Penggunaan `stdio.h` dengan `printf` dan `scanf` tidak akan dinilai.
3. Setiap soal memiliki bobot nilai yang sama.
4. **Upload** kode program dan laporan penjelasan untuk setiap soal ke repositori **“UTS Struktur Data”** di GitHub.
5. Berikan **komentar yang jelas** pada kode program Anda.

---

## Soal

### Soal 1: Array dan Pointer (20 poin)
Implementasikan sebuah program untuk mengelola data mahasiswa menggunakan **array** dan **pointer**. Program harus memiliki fitur sebagai berikut:
- Membuat `struct Mahasiswa` dengan anggota: `NIM` (string), `nama` (string), dan `IPK` (float).
- Menggunakan *array of pointers* untuk menyimpan data 10 mahasiswa.
- Mengimplementasikan fungsi untuk menambah, menghapus, dan menampilkan data mahasiswa.
- Membuat fungsi untuk mengurutkan data mahasiswa berdasarkan IPK (algoritma bebas, contoh: *bubble sort*).

---

### Soal 2: Struct dan File Handling (20 poin)
Buat program untuk mengelola inventaris peralatan laboratorium dengan menggunakan **struct** dan **file handling**. Program harus memiliki fitur:
- Membuat `struct Peralatan` dengan anggota: `kode` (string), `nama` (string), `jumlah` (int), dan `kondisi` (string).
- Mengimplementasikan fungsi untuk menambah, mengubah, dan menghapus data peralatan.
- Menyimpan dan membaca data peralatan dari file teks.
- Menampilkan laporan inventaris peralatan yang diurutkan berdasarkan `kode` peralatan.

---

### Soal 3: Stack (20 poin)
Implementasikan sebuah program kalkulator notasi **postfix** menggunakan **stack**. Program harus memiliki fitur:
- Membuat `class Stack` dengan operasi `push`, `pop`, dan `isEmpty`.
- Mengimplementasikan fungsi untuk mengevaluasi ekspresi postfix.
- Menangani operasi aritmatika dasar (`+`, `-`, `*`, `/`) dan operator pangkat (`^`).
- Menampilkan langkah-langkah evaluasi ekspresi postfix.

---

### Soal 4: Queue (20 poin)
Buat simulasi antrian layanan pelanggan di sebuah bank menggunakan **queue**. Program harus memiliki fitur:
- Membuat `class Queue` dengan operasi `enqueue`, `dequeue`, dan `isEmpty`.
- Mengimplementasikan `struct Pelanggan` dengan anggota: `nomor antrian` dan `waktu layanan` (dalam menit).
- Mensimulasikan proses antrian dengan 3 loket layanan.
- Menghitung dan menampilkan statistik: rata-rata waktu tunggu, pelanggan terlayani, dan sisa antrian.

---

### Soal 5: Implementasi Gabungan (20 poin)
Buat sebuah program manajemen perpustakaan sederhana yang menggabungkan penggunaan **array**, **pointer**, **struct**, **stack**, dan **queue**. Program harus memiliki fitur:
- Menggunakan `struct Buku` dengan anggota: `ISBN`, `judul`, `pengarang`, dan `tahun terbit`.
- Menyimpan data buku menggunakan *array of pointers*.
- Mengimplementasikan **stack** untuk menyimpan riwayat peminjaman buku.
- Menggunakan **queue** untuk mengelola antrian peminjaman buku.
- Membuat fungsi untuk menambah, mencari, dan menampilkan data buku.
- Mengimplementasikan fungsi peminjaman dan pengembalian buku.

---

## Kriteria Penilaian

1. **Ketepatan implementasi struktur data** (40%)
2. **Kebenaran logika program** (30%)
3. **Kerapian dan dokumentasi kode** (15%)
4. **Kreativitas dan fitur tambahan** (15%)

---

**SELAMAT MENGERJAKAN**
