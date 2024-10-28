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

int main() {
    Queue antrian;
    int jumlahLoket = 3;

    // Contoh input pelanggan
    antrian.enqueue({1, 5});  // Pelanggan nomor 1 dengan waktu layanan 5 menit
    antrian.enqueue({2, 10}); // Pelanggan nomor 2 dengan waktu layanan 10 menit
    antrian.enqueue({3, 7});  // Pelanggan nomor 3 dengan waktu layanan 7 menit
    antrian.enqueue({4, 3});  // Pelanggan nomor 4 dengan waktu layanan 3 menit
    antrian.enqueue({5, 8});  // Pelanggan nomor 5 dengan waktu layanan 8 menit

    std::cout << "Simulasi Antrian Layanan Bank\n\n";
    simulasiAntrian(antrian, jumlahLoket);

    return 0;
}
