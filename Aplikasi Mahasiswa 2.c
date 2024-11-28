#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[100];
    char npm[20];
    char prodi[100];
    float ipk;
} Mahasiswa;

// Data dummy untuk 10 mahasiswa
Mahasiswa data[10] = {
    {"Arif Choirudin", "061", "Teknik Informatika", 3.5},
    {"Farel Budi", "012", "Sistem Informasi", 3.2},
    {"Fernando Young", "093", "Teknik Elektro", 3.8},
    {"Rafli Alviro", "224", "Teknik Industri", 4},
    {"Reno Alfa", "305", "DKV", 3.7},
    {"Azrul", "211", "Akuntansi", 2.9},
    {"Sahzada", "767", "Hukum", 3.6},
    {"Dicky Haikal", "268", "Psikologi", 3.9},
    {"David Ainur", "399", "Kedokteran", 3.4},
    {"Salman Alfarizi", "110", "Biologi", 3.3}
};
int jumlah_data = 10;

int compareByName(const void *a, const void *b) {
    return strcmp(((Mahasiswa *)a)->nama, ((Mahasiswa *)b)->nama);
}

int compareByNPM(const void *a, const void *b) {
    return strcmp(((Mahasiswa *)a)->npm, ((Mahasiswa *)b)->npm);
}

int compareByProdi(const void *a, const void *b) {
    return strcmp(((Mahasiswa *)a)->prodi, ((Mahasiswa *)b)->prodi);
}

int compareByIPK(const void *a, const void *b) {
    float ipkA = ((Mahasiswa *)a)->ipk;
    float ipkB = ((Mahasiswa *)b)->ipk;
    return (ipkA > ipkB) - (ipkA < ipkB);
}

void tampilkanData() {

    int pilihan, urutan;
    printf("\nUrutkan data berdasarkan:\n1. Nama\n2. NPM\n3. Prodi\n4. IPK\nPilihan Anda: ");
    scanf("%d", &pilihan);
    printf("\nPilih urutan:\n1. Ascending (A-Z atau 0-9)\n2. Descending (Z-A atau 9-0)\nPilihan Anda: ");
    scanf("%d", &urutan);

    switch (pilihan) {
        case 1:
            qsort(data, jumlah_data, sizeof(Mahasiswa), compareByName);
            break;
        case 2:
            qsort(data, jumlah_data, sizeof(Mahasiswa), compareByNPM);
            break;
        case 3:
            qsort(data, jumlah_data, sizeof(Mahasiswa), compareByProdi);
            break;
        case 4:
            qsort(data, jumlah_data, sizeof(Mahasiswa), compareByIPK);
            break;
    }

    if (urutan == 2) {
        for (int i = 0; i < jumlah_data / 2; i++) {
            Mahasiswa temp = data[i];
            data[i] = data[jumlah_data - i - 1];
            data[jumlah_data - i - 1] = temp;
        }
    }

    printf("\n---------------------------------------------------------\n");
    printf("%-20s %-10s %-20s %-5s\n", "Nama", "NPM", "Prodi", "IPK");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < jumlah_data; i++) {
        printf("%-20s %-10s %-20s %-5.2f\n", data[i].nama, data[i].npm, data[i].prodi, data[i].ipk);
    }
    printf("---------------------------------------------------------\n");
}

int main() {

    printf("\n---------------------------------------------------------\n");
    printf("%-20s %-10s %-20s %-5s\n", "Nama", "NPM", "Prodi", "IPK");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < jumlah_data; i++) {
        printf("%-20s %-10s %-20s %-5.2f\n", data[i].nama, data[i].npm, data[i].prodi, data[i].ipk);
    }
    printf("---------------------------------------------------------\n");

    int pilihan;

    while (1) {
        printf("\nMenu:\n1. Urutkan Data\n2. Keluar\nPilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanData();
                break;
            case 2:
                printf("Keluar dari program.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}
