//
//  main.c
//  E-kasa projesi
//
//  Created by Mehmet Tuna Arıkaya on 16.05.2024.
//

#include <stdio.h>

int urunEkle();
int odemeIslemleri(int urunCesidi[]);
int yanitVerme();

int main() {
    printf("Sitemize hos geldiniz\n");

    int cinsiyet;
    printf("Cinsiyetinizi seciniz:\n");
    printf("1-Kadin\n");
    printf("2-Erkek\n");
    scanf("%d", &cinsiyet);

    if (cinsiyet != 1 && cinsiyet != 2) {
        printf("Lutfen gecerli bir cinsiyet secin.\n");
        return 1;
    }

    printf("Adiniz ve Soyadiniz: ");
    char Ad[50], Soyad[50];
    scanf("%s %s", Ad, Soyad);

    urunEkle();

    int urunCesidi[2];
    printf("Alacaginiz kazak ve sweatshirt adetini girin:\n");
    scanf("%d %d", &urunCesidi[0], &urunCesidi[1]);

    printf("%d kazak aldiniz.\n", urunCesidi[0]);
    printf("%d sweatshirt aldiniz.\n", urunCesidi[1]);

    odemeIslemleri(urunCesidi);

    return 0;
}

int urunEkle() {
    printf("Urun cesitlerimiz:\n");
    printf("1-Kazak\n2-Sweatshirt\n");
    printf("Bedenler ve renkler:\n");

    char urun[2][3][10] = {{"Small", "Medium", "Large"}, {"kirmizi", "mavi", "yesil"}};
    for (int c = 0; c < 2; c++) {
        for (int b = 0; b < 3; b++) {
            printf("%s ", urun[c][b]);
        }
        printf("\n");
    }

    printf("Bir kazak fiyati: 90 TL\n");
    printf("Bir sweatshirt fiyati: 120 TL\n");

    return 0;
}

int odemeIslemleri(int urunCesidi[]) {
    printf("Odeme islemlerine geciniz.\n");
    printf("Odeme turunu seciniz:\n");
    printf("BILGILENDIRME: Nakitte karta oranla %%10 daha fazla indirim uygulanacaktir.\n");

    int toplamu = urunCesidi[0] + urunCesidi[1];
    int tutar1 = (urunCesidi[0] * 90) + (urunCesidi[1] * 120);
    int toplam = 0, kupon = 0;

    for (int k = 1; k <= toplamu; k++) {
        kupon = k * 20;
        if (toplam + kupon >= tutar1 / 2) {
            break;
        }
        toplam += kupon;
    }

    int p = (toplam + kupon >= tutar1 / 2) ? (tutar1 / 2) - 80 : toplam;

    printf("Kazandiginiz kupon: %d TL\n", p);

    printf("Sepeti onayliyor musunuz?\n");
    int r = yanitVerme();

    switch (r) {
        case 1:
            printf("Odeme islemlerine geciliyor...\n");
            printf("Odeme turunu seciniz:\n");
            printf("1-Nakit\n2-Kart\n");

            int odemeturu;
            scanf("%d", &odemeturu);

            if (odemeturu == 1) {
                printf("Nakit sectiginiz icin %%10 indirim uygulanacaktir.\n");
                float tutar3 = (toplam + kupon >= tutar1 / 2) ? tutar1 - p - (tutar1 * 0.1) : tutar1 - toplam - (tutar1 * 0.1);
                printf("Toplam odenecek tutar: %.1f TL\n", tutar3);
            } else if (odemeturu == 2) {
                printf("Toplam odenecek tutar: %d TL\n", (toplam + kupon >= tutar1 / 2) ? tutar1 - p : tutar1 - toplam);
            }
            break;

        case 2:
            printf("Baska urunlere goz atmak ister misiniz?\nNot: Sepetiniz sifirlanacaktir.\n");
            int x = yanitVerme();
            if (x == 1) {
                urunEkle();
            } else {
                printf("Iyi gunler dileriz.\n");
            }
            break;

        default:
            printf("Lutfen gecerli bir islem seciniz.\n");
            break;
    }

    return 0;
}

int yanitVerme() {
    printf("1-Evet\n2-Hayir\n");
    int y;
    scanf("%d", &y);
    return y;
}
