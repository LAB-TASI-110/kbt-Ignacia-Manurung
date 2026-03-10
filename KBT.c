//  Ignacia Putri Manurung - 12S25034

#include <stdio.h>    // Untuk fungsi input/output seperti printf, scanf, fgets
#include <stdlib.h>   // Untuk fungsi umum seperti rand, srand
#include <string.h>   // Untuk fungsi manipulasi string seperti strcmp, strcpy
#include <time.h>     // Untuk inisialisasi srand dengan waktu saat ini

// Mendefinisikan konstanta untuk ukuran buffer string
#define MAX_STR_LEN 50
#define MAX_ROUTE_LEN 20
#define NUM_ROUTES 15

int main() {
    // 1. Deklarasi Variabel dan Konstanta
    char nama[MAX_STR_LEN];
    char id[MAX_STR_LEN];
    char tempat_awal_berangkat[MAX_STR_LEN];
    char tujuan_berangkat[MAX_STR_LEN];
    int pilihan_kbt_int; // 1: Ekonomi, 2: VIP
    char pilihan_kbt_str[MAX_STR_LEN];
    char cara_pembayaran[MAX_STR_LEN];

    int nomor_kursi;
    char jadwal_berangkat[MAX_STR_LEN];
    char lama_perjalanan[MAX_STR_LEN];
    double harga_tiket;

    // Inisialisasi generator angka acak untuk nomor kursi
    srand(time(NULL));

    // Daftar rute yang tersedia
    const char *daftar_rute[NUM_ROUTES] = {
        "Jakarta", "Surabaya", "Bandung", "Medan", "Semarang",
        "Makassar", "Palembang", "Denpasar", "Balikpapan", "Banjarmasin",
        "Samarinda", "Padang", "Pekanbaru", "Manado", "Yogyakarta"
    };

    // Harga dasar tiket
    const double HARGA_DASAR = 150000.0; // Contoh harga dasar
    const double FAKTOR_VIP = 1.8;       // Harga VIP = Harga Dasar * Faktor VIP

    int rute_valid = 0; // Flag untuk validasi rute
    int pilihan_kbt_valid = 0; // Flag untuk validasi pilihan KBT
    int i; // Untuk looping

    // 2. Tampilan Pembuka dan Alur Petugas
    printf("==============================================\n");
    printf("       SISTEM TICKETING KOPERASI BINTANG TAPANULI (KBT)\n");
    printf("==============================================\n\n");
    printf("Selamat datang, Petugas!\n");
    printf("Silakan masukkan detail pemesanan tiket.\n\n");

    // 3. Input Data Penumpang
    printf("Masukkan Nama Penumpang        : ");
    fgets(nama, MAX_STR_LEN, stdin);
    nama[strcspn(nama, "\n")] = 0; // Menghilangkan newline character

    printf("Masukkan ID Penumpang          : ");
    fgets(id, MAX_STR_LEN, stdin);
    id[strcspn(id, "\n")] = 0;

    printf("Masukkan Tempat Awal Berangkat : ");
    fgets(tempat_awal_berangkat, MAX_STR_LEN, stdin);
    tempat_awal_berangkat[strcspn(tempat_awal_berangkat, "\n")] = 0;

    // 4. Pilihan Rute dan Jadwal
    printf("\n--- Pilihan Rute Perjalanan ---\n");
    printf("Kota Tujuan yang tersedia:\n");
    for (i = 0; i < NUM_ROUTES; i++) {
        printf("- %s\n", daftar_rute[i]);
    }

    while (!rute_valid) {
        printf("Masukkan Kota Tujuan Berangkat : ");
        fgets(tujuan_berangkat, MAX_STR_LEN, stdin);
        tujuan_berangkat[strcspn(tujuan_berangkat, "\n")] = 0;

        for (i = 0; i < NUM_ROUTES; i++) {
            if (strcmp(tujuan_berangkat, daftar_rute[i]) == 0) {
                rute_valid = 1;
                break;
            }
        }
        if (!rute_valid) {
            printf("Maaf, kota tujuan '%s' tidak tersedia. Mohon pilih dari daftar.\n", tujuan_berangkat);
        }
    }

    while (!pilihan_kbt_valid) {
        printf("\nPilih Tipe KBT (1: Ekonomi, 2: VIP) : ");
        if (scanf("%d", &pilihan_kbt_int) != 1) {
            printf("Input tidak valid. Mohon masukkan angka 1 atau 2.\n");
            // Membersihkan buffer input jika terjadi kesalahan
            while (getchar() != '\n');
        } else {
            if (pilihan_kbt_int == 1) {
                strcpy(pilihan_kbt_str, "Ekonomi");
                pilihan_kbt_valid = 1;
            } else if (pilihan_kbt_int == 2) {
                strcpy(pilihan_kbt_str, "VIP");
                pilihan_kbt_valid = 1;
            } else {
                printf("Pilihan tidak valid. Mohon masukkan 1 untuk Ekonomi atau 2 untuk VIP.\n");
            }
        }
    }
    // Membersihkan buffer setelah scanf
    while (getchar() != '\n');

    printf("Masukkan Cara Pembayaran       : ");
    fgets(cara_pembayaran, MAX_STR_LEN, stdin);
    cara_pembayaran[strcspn(cara_pembayaran, "\n")] = 0;

    // Simulasi Jadwal dan Durasi Perjalanan (bisa lebih kompleks di dunia nyata)
    // Untuk tujuan ini, kita asumsikan jadwal dan durasi default atau berdasarkan rute sederhana
    strcpy(jadwal_berangkat, "2023-12-31, 10:00 WIB"); // Contoh jadwal default
    if (strcmp(tujuan_berangkat, "Jakarta") == 0 || strcmp(tujuan_berangkat, "Surabaya") == 0) {
        strcpy(lama_perjalanan, "12 Jam");
    } else if (strcmp(tujuan_berangkat, "Medan") == 0 || strcmp(tujuan_berangkat, "Palembang") == 0) {
        strcpy(lama_perjalanan, "15 Jam");
    } else {
        strcpy(lama_perjalanan, "8-10 Jam"); // Default untuk rute lain
    }


    // 5. Perhitungan Harga Tiket
    harga_tiket = HARGA_DASAR;
    if (pilihan_kbt_int == 2) { // VIP
        harga_tiket *= FAKTOR_VIP;
    }

    // 6. Pengecekan Ketersediaan Kursi (Simulasi)
    // Menghasilkan nomor kursi acak antara 1 dan 50 (misalnya)
    nomor_kursi = (rand() % 50) + 1;

    // 7. Pencatatan Transaksi dan Pembuatan Tiket (data sudah terkumpul di variabel)

    // 8. Tampilan Output Tiket
    printf("\n\n==============================================\n");
    printf("              TIKET KOPERASI BINTANG TAPANULI (KBT)\n");
    printf("==============================================\n");
    printf("Nama Penumpang       : %s\n", nama);
    printf("ID Penumpang         : %s\n", id);
    printf("Tempat Awal Berangkat: %s\n", tempat_awal_berangkat);
    printf("Tujuan Berangkat     : %s\n", tujuan_berangkat);
    printf("Pilihan KBT          : %s\n", pilihan_kbt_str);
    printf("Nomor Kursi          : %d\n", nomor_kursi);
    printf("Jadwal Berangkat     : %s\n", jadwal_berangkat);
    printf("Lama Perjalanan      : %s\n", lama_perjalanan);
    printf("Harga Tiket          : Rp %.2f\n", harga_tiket);
    printf("Cara Pembayaran      : %s\n", cara_pembayaran);
    printf("==============================================\n");
    printf("Terima kasih telah menggunakan layanan KBT.\n");
    printf("==============================================\n");

    return 0; // Mengindikasikan program berhasil dieksekusi
}
