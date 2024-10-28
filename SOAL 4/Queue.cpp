#include <iostream>
#include <queue>
#include <string>
#include <iomanip>

struct Pelanggan {
    int nomor;
    int waktuLayanan; // Waktu layanan dalam menit
};

class Queue {
public:
    void enqueue(const Pelanggan& pelanggan) {
        q.push(pelanggan);
    }

    Pelanggan dequeue() {
        if (q.empty()) {
            std::cerr << "Queue kosong!\n";
            return Pelanggan{-1, 0};
        }
        Pelanggan frontPelanggan = q.front();
        q.pop();
        return frontPelanggan;
    }

    bool isEmpty() const {
        return q.empty();
    }

    int size() const {
        return q.size();
    }

private:
    std::queue<Pelanggan> q;
};

// Fungsi untuk mensimulasikan antrian dan menghitung statistik
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

// Fungsi untuk meminta waktu layanan dalam format jam dan menit, lalu mengkonversi ke menit
int inputWaktuLayanan() {
    int jam, menit;
    std::cout << "Masukkan waktu layanan (jam menit): ";
    std::cin >> jam >> menit;
    int totalMenit = jam * 60 + menit;
    std::cout << "Waktu layanan dalam menit: " << totalMenit << " menit\n";
    return totalMenit;
}

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
