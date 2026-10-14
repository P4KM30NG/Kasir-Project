#include <stdio.h>
#include <ctype.h>
#include <string.h>

char idBarang[10][7] =
{
  "BRG001", 
  "BRG002", 
  "BRG003", 
  "BRG004", 
  "BRG005", 
  "BRG006", 
  "BRG007", 
  "BRG008", 
  "BRG009", 
  "BRG010",
};

char barang[10][50] = 
{
    "Keyboard Mechanical RGB", 
    "Mouse Wireless", 
    "Mousepad XL", 
    "Headset Gaming", 
    "Webcam Full HD 1080p", 
    "Monitor 24 Inch IPS", 
    "Flashdisk 64GB", 
    "SSD 512GB", 
    "USB Hub 4 Port", 
    "Speaker Bluetooth",
};

int hargaBarang[] =
{
    450000, 150000, 85000, 375000, 320000, 1850000, 95000, 650000, 75000, 280000
};

int stokBarang[] = 
{
    15,25,30,12,10,8,40,18,20,14
};

char kategoriBarang[10][12] =
{
    "Keyboard", 
    "Mouse", 
    "Aksesoris", 
    "Audio", 
    "Kamera", 
    "Monitor", 
    "Penyimpanan", 
    "Penyimpanan", 
    "Aksesoris", 
    "Audio",
};

char keranjang[10][7] =
{
    {0}
};

int jumlahItem_keranjang[10] = 
{
    0
};

int jumlahKeranjang = 0;

void list_barang(int ukuranArray_list) //FUNGSI MENAMPILKAN LIST BARANG
{
    int i = 0;
    printf("ID     |        NAMA BARANG        |   KATEGORI   | HARGA (RP) | STOK\n");
    while (i < ukuranArray_list)
    {
        printf("%s | %-25s | %-12s | %-10d | %d\n", idBarang[i], barang[i], kategoriBarang[i], hargaBarang[i], stokBarang[i]);
        i++;
    };
}

void tambah_keranjang(const char *idBarang_input, int jumlahBarang_input) //FUNGSI MENAMBAH KE KERANJANG
{
    int i = 0;
    while (i < jumlahKeranjang)
    {
        if (strcmp(keranjang[i], idBarang_input) == 0)
        {
            jumlahItem_keranjang[i] += jumlahBarang_input;
            return;
        }
        i++;
    }

    if (jumlahKeranjang >= 10)
    {
        printf("Keranjang sudah penuh!\n");
        return;
    }

    strcpy(keranjang[jumlahKeranjang], idBarang_input);
    jumlahItem_keranjang[jumlahKeranjang] = jumlahBarang_input;
    jumlahKeranjang++;
}

void list_kranjang(int ukuranArray_kranjang, int ukuranArray_list) //FUNGSI NAMPILKAN KERANJANG
{
    int i = 0;
    printf("ID     |        NAMA BARANG        | JUMLAH |   KATEGORI   | HARGA (RP) | SUBTOTAL\n");
    while (i < ukuranArray_kranjang)
    {
        int j = 0;
        int k = 0;
        while(j < ukuranArray_list)
        {
            if (strcmp(keranjang[i], idBarang[j]) == 0)
            {
                printf("%s | %-25s |   %d   | %-12s | %-10d | %d\n", idBarang[j], barang[j], jumlahItem_keranjang[i], kategoriBarang[i], hargaBarang[j], jumlahItem_keranjang[i] * hargaBarang[j]);
                k = 1;
                break;
            }
            j++;
        }
        if (!k) {
            printf("%s | ID Tidak Ditemukan | %d | - | -\n",
                   keranjang[i],
                   jumlahItem_keranjang[i]);
        }

        i++;
    }
}

void hapusIsi_kranjang(int ukuranArray_kranjang, int ukuranArray_list) //FUNGSI HAPUS ISI KERANJANG
{
    char idBarang_Hapus[7];
    int i = 0;
    printf("\n");
    list_kranjang(ukuranArray_kranjang, ukuranArray_list);
    printf("Masukkan ID Barang yang mau dihapus: ");
    scanf("%6s", idBarang_Hapus);

    while (i < jumlahKeranjang)
    {
        if (strcmp(keranjang[i], idBarang_Hapus) == 0)
        {
            int j = i;
            while (j < jumlahKeranjang - 1)
            {
                strcpy(keranjang[j], keranjang[j + 1]);
                jumlahItem_keranjang[j] = jumlahItem_keranjang[j + 1];
                j++;
            }
            jumlahKeranjang--;
            keranjang[jumlahKeranjang][0] = '\0';
            jumlahItem_keranjang[jumlahKeranjang] = 0;

            list_kranjang(jumlahKeranjang, ukuranArray_list);
            return;
        }
        i++;
    }

    printf("ID barang tidak ditemukan di keranjang.\n");
}

void edit_kranjang(int ukuranArray_kranjang, int ukuranArray_list)
{
    (void)ukuranArray_kranjang;
    (void)ukuranArray_list;
}

void checkout(int ukuranArray_kranjang, int ukuranArray_list)
{
    list_kranjang(ukuranArray_kranjang, ukuranArray_list);
}

int main()
{
    int pilihanMenu = -1;

    while (pilihanMenu != 0) {
        printf("=== PROGRAM KASIR SEDERHANA ===\n          Select Menu          \n");
        printf("1. Preview List Barang\n2. Tambah ke Keranjang\n3. Hapus barang di Keranjang\n4. Edit Keranjang\n5. Lihat Keranjang\n6. Checkout\n7. Print Struk\n0. Exit Program\nMenu Ke-");
        scanf("%d", &pilihanMenu);

        switch (pilihanMenu) {
            case 0:
                printf("Terimakasih telah Berbelanja bersama kami!");
                break;

            case 1: {
                char pilihanList;
                int arrayLen_barang = sizeof(idBarang) / sizeof(idBarang[0]);
                list_barang(arrayLen_barang);
                printf("\nKembali ke menu? (Y): "); scanf(" %c", &pilihanList);
                pilihanList = tolower(pilihanList);
                if (pilihanList == 'n') {
                    printf("Terimakasih telah Berbelanja bersama kami!\n");
                    break;
                } else {
                    printf("\n");
                    continue;
                }
            }

            case 2: {
                int y;
                char pilihanTambah;
                char idInput[7];
                while (1) {
                    printf("Masukkan ID Barang:"); scanf(" %6s", idInput);
                    printf("Masukkan Jumlah Barang:"); scanf(" %d", &y);
                    tambah_keranjang(idInput, y);
                    printf("Tambah Lagi?(Y/N):"); scanf(" %c", &pilihanTambah);
                    pilihanTambah = tolower(pilihanTambah);
                    if (pilihanTambah == 'n') {
                        printf("\n");
                        break;
                    }
                    printf("\n");
                }
                break;
            }

            case 3: {
                char pilihanList_kranjang;
                hapusIsi_kranjang(jumlahKeranjang, sizeof(idBarang) / sizeof(idBarang[0]));
                printf("Barang Berhasil dihapus");
                printf("\nKembali ke menu? (Y): "); scanf(" %c", &pilihanList_kranjang);
                pilihanList_kranjang = tolower(pilihanList_kranjang);
                if (pilihanList_kranjang == 'n') {
                    printf("Terimakasih telah Berbelanja bersama kami!\n");
                    break;
                } else {
                    printf("\n");
                    continue;
                }
            }

            case 4: {
                char pilihanList_kranjang;
                edit_kranjang(jumlahKeranjang, sizeof(idBarang) / sizeof(idBarang[0]));
                printf("Barang Berhasil diubah");
                printf("\nKembali ke menu? (Y): "); scanf(" %c", &pilihanList_kranjang);
                pilihanList_kranjang = tolower(pilihanList_kranjang);
                if (pilihanList_kranjang == 'n') {
                    printf("Terimakasih telah Berbelanja bersama kami!\n");
                    break;
                } else {
                    printf("\n");
                    continue;
                }
            }

            case 5: {
                int arrayLen_barang = sizeof(idBarang) / sizeof(idBarang[0]);
                char pilihanList_kranjang;
                list_kranjang(jumlahKeranjang, arrayLen_barang);
                printf("\nKembali ke menu? (Y): "); scanf(" %c", &pilihanList_kranjang);
                pilihanList_kranjang = tolower(pilihanList_kranjang);
                if (pilihanList_kranjang == 'n') {
                    printf("Terimakasih telah Berbelanja bersama kami!\n");
                    break;
                } else {
                    printf("\n");
                    continue;
                }
            }

            case 6:
            case 7:
            default:
                printf("Salah pilih menu!\n");
                continue;
        }
    }

    return 0;
}