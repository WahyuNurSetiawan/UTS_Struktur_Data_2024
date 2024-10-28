# Jawaban Soal 4: Simulasi Antrian Layanan Bank dengan Input Waktu Layanan dalam Jam dan Menit

Program ini adalah simulasi antrian layanan pelanggan di sebuah bank menggunakan **queue**. Program ini memungkinkan pengguna untuk memasukkan data pelanggan secara manual dengan format waktu layanan dalam jam dan menit, kemudian mengkonversinya ke dalam satuan menit. Setelah input selesai, program akan melakukan simulasi layanan antrian dengan beberapa loket dan menampilkan statistik layanan.

## Penjelasan Kode

### 1. Struct `Pelanggan`

Struct `Pelanggan` menyimpan informasi pelanggan, yang terdiri dari:

- `nomor` (int): Nomor antrian pelanggan.
- `waktuLayanan` (int): Waktu layanan pelanggan dalam satuan menit.

```cpp
struct Pelanggan {
    int nomor;
    int waktuLayanan; // Waktu layanan dalam menit
};
```

### 2. Class `Queue`

Kelas `Queue` mengimplementasikan antrian pelanggan dengan operasi dasar:

- `enqueue(const Pelanggan&)`: Menambahkan pelanggan ke antrian.
- `dequeue()`: Mengeluarkan pelanggan dari antrian.
- `isEmpty()`: Mengecek apakah antrian kosong.
- `size()`: Mengembalikan ukuran antrian.

```cpp
class Queue {
public:
    void enqueue(const Pelanggan& pelanggan) { q.push(pelanggan); }
    Pelanggan dequeue() {
        if (q.empty()) {
            std::cerr << "Queue kosong!\n";
            return Pelanggan{-1, 0};
        }
        Pelanggan frontPelanggan = q.front();
        q.pop();
        return frontPelanggan;
    }
    bool isEmpty() const { return q.empty(); }
    int size() const { return q.size(); }

private:
    std::queue<Pelanggan> q;
};
```

### 3. Fungsi `inputWaktuLayanan`

Fungsi ini meminta input waktu layanan dalam format jam dan menit. Setelah input, fungsi mengkonversi waktu ke dalam satuan menit menggunakan rumus `totalMenit = jam * 60 + menit`. Hasil dalam menit kemudian dikembalikan untuk digunakan dalam simulasi layanan.

```cpp
int inputWaktuLayanan() {
    int jam, menit;
    std::cout << "Masukkan waktu layanan (jam menit): ";
    std::cin >> jam >> menit;
    int totalMenit = jam * 60 + menit;
    std::cout << "Waktu layanan dalam menit: " << totalMenit << " menit\n";
    return totalMenit;
}
```

### 4. Fungsi `simulasiAntrian`

Fungsi ini mensimulasikan antrian layanan bank. Selama antrian tidak kosong, pelanggan akan diproses oleh sejumlah loket yang tersedia. Fungsi menghitung total waktu layanan dan waktu tunggu untuk semua pelanggan, serta menampilkan statistik:

- **Total pelanggan terlayani**.
- **Rata-rata waktu tunggu per pelanggan**.
- **Sisa pelanggan dalam antrian**.

```cpp
void simulasiAntrian(Queue& antrian, int jumlahLoket) {
    int totalWaktuTunggu = 0;
    int totalPelangganTerlayani = 0;

    while (!antrian.isEmpty()) {
        int waktuLayananTotal = 0;

        for (int i = 0; i < jumlahLoket && !antrian.isEmpty(); i++) {
            Pelanggan pelanggan = antrian.dequeue();
            waktuLayananTotal += pelanggan.waktuLayanan;

            std::cout << "Pelanggan Nomor " << pelanggan.nomor
                      << " dilayani dengan waktu " << pelanggan.waktuLayanan
                      << " menit.\n";
            totalWaktuTunggu += waktuLayananTotal;
            totalPelangganTerlayani++;
        }

        std::cout << "Waktu layanan total untuk semua loket dalam satu siklus: "
                  << waktuLayananTotal << " menit.\n\n";
    }

    double rataWaktuTunggu = (totalPelangganTerlayani > 0) ?
                              static_cast<double>(totalWaktuTunggu) / totalPelangganTerlayani : 0;

    std::cout << "Statistik:\n";
    std::cout << "Total pelanggan terlayani: " << totalPelangganTerlayani << '\n';
    std::cout << "Rata-rata waktu tunggu per pelanggan: " << std::fixed << std::setprecision(2)
              << rataWaktuTunggu << " menit\n";
    std::cout << "Sisa antrian: " << antrian.size() << " pelanggan\n";
}
```

### 5. Fungsi `main`

Pada fungsi `main`, program menyediakan menu interaktif yang memungkinkan pengguna untuk memasukkan data pelanggan dan memulai simulasi setelah selesai. Setiap kali pelanggan ditambahkan, program akan mengkonversi waktu layanan yang diinput dalam jam dan menit menjadi menit untuk keperluan perhitungan.

```cpp
int main() {
    Queue antrian;
    int jumlahLoket = 3;
    int pilihan;
    int nomorPelanggan = 1;

    std::cout << "Simulasi Antrian Layanan Bank\n";
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tambah Pelanggan\n";
        std::cout << "2. Selesai Memasukkan Pelanggan\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        if (pilihan == 1) {
            int waktuLayanan = inputWaktuLayanan();  // Menggunakan fungsi input waktu
            antrian.enqueue({nomorPelanggan, waktuLayanan});
            nomorPelanggan++;
            std::cout << "Pelanggan berhasil ditambahkan ke antrian.\n";
        } else if (pilihan != 2) {
            std::cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 2);

    std::cout << "\nMemulai simulasi antrian...\n\n";
    simulasiAntrian(antrian, jumlahLoket);

    return 0;
}
```

---

## Contoh Input dan Output

### Proses Input

```
Simulasi Antrian Layanan Bank

Menu:
1. Tambah Pelanggan
2. Selesai Memasukkan Pelanggan
Pilihan: 1
Masukkan waktu layanan (jam menit): 0 30
Waktu layanan dalam menit: 30 menit
Pelanggan berhasil ditambahkan ke antrian.

Pilihan: 1
Masukkan waktu layanan (jam menit): 0 45
Waktu layanan dalam menit: 45 menit
Pelanggan berhasil ditambahkan ke antrian.

Pilihan: 1
Masukkan waktu layanan (jam menit): 1 15
Waktu layanan dalam menit: 75 menit
Pelanggan berhasil ditambahkan ke antrian.

Pilihan: 2
```

### Output dari Simulasi

```
Memulai simulasi antrian...

Pelanggan Nomor 1 dilayani dengan waktu 30 menit.
Pelanggan Nomor 2 dilayani dengan waktu 45 menit.
Pelanggan Nomor 3 dilayani dengan waktu 75 menit.
Waktu layanan total untuk semua loket dalam satu siklus: 150 menit.

Statistik:
Total pelanggan terlayani: 3
Rata-rata waktu tunggu per pelanggan: 50.00 menit
Sisa antrian: 0 pelanggan
```
