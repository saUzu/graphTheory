//                                                                                          Eren Uğuray ERAY 141002082 İkinci Öğretim
//                                                          GRAF TEORİSİ İKİNCİ ÖDEVİ
//
//      NOTLAR:
//              - İkinci ödevi, birinci ödevin üzerinde yaptım.
//              1. ÖDEV NOTU:
//                          - tembel olduğum için grafı ve komşuluk matrisini otomatikleştirdim.
//                          - otomatikleştirdiğim kısımlar için gereken random kütüphanesi codeblock'ta çalışmıyor.
//                          - kodun çalışmaklığını denemek için; 
//                                      - "main" fonksiyonundaki "matris" değişkeni içine 0 veya 1 değerlerini girerseniz komşuluğu deneyebilirsiniz.
//                                      - değerleri matrisin ilkköşegenine simetrik giriniz. dizi[0][10]=1 ise dizi[10][0]'da 1 olacak.
//                          - otomatikleştirdiğim fonksiyonların çağırıldığı yerleri yorum satırı yapınız.
//
//              2. ÖDEV NOTU:
//                          - tembel olduğum için dijkstra algoritması için gereken yol ağırlıklarını otomatikleştirdim.
//                          - otomatikleştirdiğim kısımlar için gereken random kütüphanesi codeblock'ta çalışmıyor.
//                          - kodun çalışmaklığını denemek için;
//                                      - "main" fonksiyonundaki "agirlikMatrisi" değişkeni içine 1 ila 10 arasında bir değer girin.
//                                      - değerleri matrisin ilkköşegenine simetrik giriniz. dizi[0][10]=8 ise dizi[10][0]'da 8 olacak.
//                          - otomatikleştirdiğim fonksiyonların çağırıldığı yerleri yorum satırı yapınız.
//      
//  #####################################################################################################################################################
//  #       ÖNEMLİ NOT;                                                                                                                                 #
//  #       - KODUN SADECE RANDOM KÜTÜPHANESİ ve OTOMATİKLEŞTİRİLEN KISIMLARI CODEBLOCK'ta ÇALIŞMIYOR. ORALARI ÖDEVDE İSTENMEYEN YERLER!                #
//  #       - ÖDEVDE İSTENENLERİN HEPSİ CODEBLOCK'ta ÇALIŞIYOR.                                                                                         #
//  #                                           (RANDOM ve OTOMATİKLEŞTİRİLEN KISIMLAR VISUAL STUDIO'da ÇALIŞIYOR.)                                     #
//  #####################################################################################################################################################
//


#include <iostream>
#include <random>

#define SONSUZ 100

class dugum {
public:
    int veri;
    dugum* siradaki;
    dugum* onceki;
    dugum* baglanti[20];
    bool ziyaretEdildiMi = false;
    dugum* enKisaOnceki;
    int uzaklik = SONSUZ;
};
/* Düğümd sınıfındaki 'baglanti' içeriğini nullar */
void baglantiNullama(dugum* dgm)
{
    for (int i = 0; i <= 19 || dgm != NULL; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            dgm->baglanti[k] = NULL;
        };
        dgm = dgm->siradaki;
    };
};
/*listenin bağlantisini nullar*/
void kListeNulla(dugum* dgm)
{
    for (int k = 0; k < 20; k++)
    {
        dgm->baglanti[k] = NULL;
    };
};
/*listeyi artarak sıralama ile gösterir*/
void artanSiralama(dugum* dgm)
{
    while (dgm != NULL)
    {
        std::cout << dgm->veri << "\n";
        dgm = dgm->siradaki;
    };
};
/*listeyi azalarak sıralama ile gösterir*/
void azalanSiralama(dugum* dgm)
{
    while (dgm != NULL)
    {
        std::cout << dgm->veri << "\n";
        dgm = dgm->onceki;
    };
};
/*Erdös ve Renyil algoritması ile rastgele bir graf ve komşuluk matrisi oluşturur */
int(&rastgeleGraf(int(&dizi)[20][20]))[20][20]
{
    std::random_device rast;
    std::mt19937 gen(rast());
    std::uniform_real_distribution<> aralik(0, 1);
    float sabitOlasilikSayisi = aralik(gen);
    //float sabitOlasilikSayisi = 1;

    for (int i = 0; i <= 19; i++)
    {
        for (int j = i; j <= 19; j++)
        {
            float rastgeleOlasilik = aralik(gen);
            if (dizi[i][j] == -1)
            {
                if (rastgeleOlasilik < sabitOlasilikSayisi && dizi[i][j] != 0)
                {
                    dizi[i][j] = 1;
                    dizi[j][i] = 1;
                }
                else
                {
                    dizi[i][j] = 0;
                    dizi[j][i] = 0;
                };
            };
        };
    };
    return dizi;
};
/* rastgele oluşturulan komşuluk matrisinin doğruluğunu denetler*/
int(&dogrulukDenetimi(int(&dizi)[20][20]))[20][20]
{
    std::cout << std::endl;
    int dogruluk = 0;
    std::cout << "Matris esitlik denetimi" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (dizi[i][j] == dizi[j][i])
            {
                ++dogruluk;
            };
        };
    };

    if (dogruluk == 400)
    {
        std::cout << "Matris Dogru!\tdogruluk degeri = " << dogruluk << std::endl;
    }
    else
    {
        std::cout << "Matris Yanlıs!\tdogruluk degeri = " << dogruluk << std::endl;
    };

    return dizi;
};
/*komşuluk matrisini yazdırır*/
int(&matrisYazdir(int(&dizi)[20][20]))[20][20]
{
    std::cout << "              ERDOS ve RENYIL rastgele graf algoritmasi ile olusturuldu!" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        std::cout << "                       ";
        for (int j = 0; j < 20; j++)
        {
            std::cout << dizi[i][j] << ",";
        };
        std::cout << std::endl;
    };
    return dizi;
};
/*Grafın komşuluk matrisine göre kenar bağlantılarını kurar*/
void baglantiKurma(int dizi[20][20], dugum* dgm1)
{
    dugum* gecici = new dugum();
    dugum* dgm2 = new dugum();
    dgm2 = dgm1;
    gecici = dgm1;
    for (int i = 0; i <= 19; i++)
    {
        for (int j = 0; j <= 19; j++)
        {
            if (dizi[i][j] == 1)
            {
                dgm1->baglanti[j] = dgm2;
            };
            dgm2 = dgm2->siradaki;
        };
        dgm1 = dgm1->siradaki;
        dgm2 = gecici;
    };
};
/*kenarları ekrana yazdırır*/
void kenarYazdir(dugum* dgm)
{
    for (int i = 0; i <= 19; i++)
    {
        for (int j = 0; j <= 19; j++)
        {
            std::cout << i << " " << j << " " << dgm->baglanti[j] << "|";
        };
        dgm = dgm->siradaki;
        std::cout << std::endl;
    };
};
/*ÖDEVDE ASIL İSTENEN ####### Özyinelemeli(recursive) fonksiyon olarak çalışır ve grafın alt bileşenleri bulunur*/
void bilesenBulma(dugum* sayacDgm, int i)
{
    sayacDgm->ziyaretEdildiMi = true;
    std::cout << sayacDgm->veri << "|";
    int sayac = 0;
    while (sayac < 20)
    {
        if (sayacDgm->baglanti[sayac] != NULL)
        {
            if (sayacDgm->baglanti[sayac]->ziyaretEdildiMi == false)
            {
                bilesenBulma(sayacDgm->baglanti[sayac], i);
            }
            else
            {
                sayac++;
            };
        }
        else
        {
            sayac++;
        };
    };
};
/*bulnan bileşenleri yazdırır*/
void bilesenYazdir(dugum* sayacDgm, int i)
{
    int sayac = 1;
    for (i = 0; i < 20 && sayacDgm != NULL; i++)
    {
        if (sayacDgm->ziyaretEdildiMi == false)
        {
            std::cout << sayac << ". Bilesen ----->           ";
            bilesenBulma(sayacDgm, i);
            sayac++;
            std::cout << std::endl;
            i--;
        }
        else
        {
            sayacDgm = sayacDgm->siradaki;
        };
    };
};
/*  ziyaret sıfırlama   */
void ziyaretSifirlama(dugum* dgm)
{
    for (int t = 0; t <= 19; t++)
    {
        dgm->ziyaretEdildiMi = false;
        dgm = dgm->siradaki;
    };
};
/*  yol ağırlığını sıfırlar */
void uzaklikSifirlama(dugum* dgm)
{
    for (int t = 0; t <= 19; t++)
    {
        dgm->uzaklik=SONSUZ;
        dgm = dgm->siradaki;
    };
};
/*  en kısa yolu sifirlama*/
void enKisaYolSifirlama(dugum* dgm)
{
    for (int r = 0; r <= 19; r++)
    {
        if (dgm != NULL)
        {
            dgm->enKisaOnceki = NULL;
            dgm = dgm->siradaki;
        };
    };
};
/*  komşuluk matrisini ağırlık matrisine eşitleyip ağırlık ekleniyor    */
void yolAgirlikEkle(int(&dizi1)[20][20], int(&dizi2)[20][20])
{
    for (int o = 0; o <= 19; o++)
    {
        for (int e = 0; e <= 19; e++)
        {
            dizi2[o][e] = dizi1[o][e];
        };
    }; 
    std::random_device rast;
    std::mt19937 gen(rast());
    std::uniform_int_distribution<> aralik(1, 10);
    for (int o = 0; o <= 19; o++)
    {
        for (int e = o; e <= 19; e++)
        {
            if (dizi2[o][e] == 1 && dizi2[e][o] == 1)
            {
                if (o != e)
                {
                    int agirlik = aralik(gen);
                    dizi2[o][e] = agirlik;
                    dizi2[e][o] = dizi2[o][e];
                }
                else
                {
                    dizi2[o][e] = 0;
                };
            }
            else
            {
                dizi2[o][e] = SONSUZ;
                dizi2[e][o] = dizi2[o][e];
            };
        };
    };
};
/*  ziyaret edilmemiş yolları yazdırma  */
void yolYazdir(dugum* dgm)
{
    for (int o = 0; o <= 19 && dgm != NULL; o++)
    {
        if (dgm->uzaklik != 100 && dgm->ziyaretEdildiMi == false)
        {
            std::cout << dgm->veri << "," << dgm->uzaklik << "| ";
        };
        if (dgm->siradaki != NULL)
        {
            dgm = dgm->siradaki;
        };
    };
    std::cout << std::endl;
};
/*  Djikstra algoritması ile yolları bulma 2  */
void yolBulma(dugum* dgm, int x, int agirlikM[20][20], dugum* basDgm)
{
    dgm->ziyaretEdildiMi = true;
    for (int o = 0; o <= 19; o++)
    {
        if (dgm->baglanti[o] != NULL)
        {
            if (dgm->baglanti[o]->uzaklik > dgm->uzaklik + agirlikM[x][o])
            {
                dgm->baglanti[o]->uzaklik = dgm->uzaklik + agirlikM[x][o];
                dgm->baglanti[o]->enKisaOnceki = dgm;
                //std::cout << agirlikM[x][o] << ", ";
                //std::cout << dgm->baglanti[o]->veri << ", ";
                //std::cout << dgm->baglanti[o]->uzaklik << "|| ";
            };
        };
    };
    //yolYazdir(basDgm);
};
/*  Djikstra algoritması ile yolları bulma 1  */
void dijAlgo(dugum* enKisaYol, int x, int agirlikM[20][20], dugum* basDgm)
{
    int sayac = 0; 
    while (sayac != 1)
    {
        if (enKisaYol->ziyaretEdildiMi == false)
        {
            //std::cout << std::endl;
            //std::cout << enKisaYol->veri << ", " << enKisaYol->uzaklik << std::endl;
            yolBulma(enKisaYol, enKisaYol->veri, agirlikM,basDgm);
        }
        else
        {
            dugum* sayacDgm = new dugum();
            dugum* gecici = new dugum();
            sayacDgm = basDgm;
            for (int o = 0; o <= 19; o++)
            {
                if (sayacDgm != NULL)
                {
                    if (sayacDgm->ziyaretEdildiMi == false && sayacDgm->uzaklik != 100 && gecici->uzaklik > sayacDgm->uzaklik)
                    {
                        gecici = sayacDgm;
                        enKisaYol = gecici;
                        //std::cout << sayacDgm->veri << ",a ";
                    };
                    sayacDgm = sayacDgm->siradaki;
                };
            };
            if (enKisaYol->ziyaretEdildiMi == true)
            {
                sayac = 1;
            }
            else
            {
                dijAlgo(enKisaYol, enKisaYol->veri, agirlikM, basDgm);
            };
        };
    };
};
/*  rotayı doğrulamasını denetler*/
void rotaDogrulukDenetimi(dugum* dgm)
{
    for (; dgm!= NULL; dgm = dgm->siradaki)
    {
        if (dgm->enKisaOnceki != NULL)
        {
            std::cout << dgm->veri << ", " << dgm->uzaklik << "," << dgm->enKisaOnceki->veri << std::endl;
        };
        if (dgm->ziyaretEdildiMi == true && dgm->enKisaOnceki != NULL)
        {
            std::cout << dgm->veri << ", " << dgm->uzaklik << "," << dgm->enKisaOnceki->veri << std::endl;
        };
    };
};
/*  bulunan rotayı yazdırır */
void rotaYazdir(dugum* basDgm, dugum* sonDgm, int belirtecSayisi)
{
    dugum* geciciDgm = new dugum();
    dugum* sayacDgm = new dugum();
    geciciDgm = basDgm;
    sayacDgm = geciciDgm;
    std::cout << std::endl;
    int uzaklik = 0;
    for (int o = 0; o <= 19; o++)
    {
        if (geciciDgm->veri != belirtecSayisi)
        {
            if (geciciDgm->uzaklik!=100)
            {
                std::cout << belirtecSayisi << "-" << geciciDgm->veri << " arasi        ";
                uzaklik = geciciDgm->uzaklik;
            };
            while (sayacDgm != NULL)
            {
                if (sayacDgm->uzaklik != 100)
                {
                    if (sayacDgm->enKisaOnceki == NULL)
                    {

                        std::cout << sayacDgm->veri << "                        ";
                    }
                    else
                    {
                        std::cout << sayacDgm->veri << "-";
                    };
                };
                sayacDgm = sayacDgm->enKisaOnceki;
            };
            if (geciciDgm->uzaklik != 100)
            {
                std::cout << uzaklik;
                std::cout << std::endl;
            };
        };
        if (geciciDgm->siradaki!= NULL)
        {
            geciciDgm = geciciDgm->siradaki;
        };
        sayacDgm = geciciDgm;
    };
};
int main()
{
    int matris[20][20] = { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} };
    int bilesenListe[20] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    int agirlikMatrisi[20][20] = { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} };
    dugum* sifir = new dugum();
    dugum* bir = new dugum();
    dugum* iki = new dugum();
    dugum* uc = new dugum();
    dugum* dort = new dugum();
    dugum* bes = new dugum();
    dugum* alti = new dugum();
    dugum* yedi = new dugum();
    dugum* sekiz = new dugum();
    dugum* dokuz = new dugum();
    dugum* on = new dugum();
    dugum* onBir = new dugum();
    dugum* onIki = new dugum();
    dugum* onUc = new dugum();
    dugum* onDort = new dugum();
    dugum* onBes = new dugum();
    dugum* onAlti = new dugum();
    dugum* onYedi = new dugum();
    dugum* onSekiz = new dugum();
    dugum* onDokuz = new dugum();

    dugum* kListe1 = new dugum();
    dugum* gecici = new dugum();
    kListe1->veri = 31;
    kListe1->siradaki = NULL;
    kListe1->onceki = NULL;

    sifir->veri = 0;
    sifir->siradaki = bir;
    sifir->onceki = NULL;

    bir->veri = 1;
    bir->siradaki = iki;
    bir->onceki = sifir;

    iki->veri = 2;
    iki->siradaki = uc;
    iki->onceki = bir;

    uc->veri = 3;
    uc->siradaki = dort;
    uc->onceki = iki;

    dort->veri = 4;
    dort->siradaki = bes;
    dort->onceki = uc;

    bes->veri = 5;
    bes->siradaki = alti;
    bes->onceki = dort;

    alti->veri = 6;
    alti->siradaki = yedi;
    alti->onceki = bes;

    yedi->veri = 7;
    yedi->siradaki = sekiz;
    yedi->onceki = alti;

    sekiz->veri = 8;
    sekiz->siradaki = dokuz;
    sekiz->onceki = yedi;

    dokuz->veri = 9;
    dokuz->siradaki = on;
    dokuz->onceki = sekiz;

    on->veri = 10;
    on->siradaki = onBir;
    on->onceki = dokuz;

    onBir->veri = 11;
    onBir->siradaki = onIki;
    onBir->onceki = on;

    onIki->veri = 12;
    onIki->siradaki = onUc;
    onIki->onceki = onBir;

    onUc->veri = 13;
    onUc->siradaki = onDort;
    onUc->onceki = onIki;

    onDort->veri = 14;
    onDort->siradaki = onBes;
    onDort->onceki = onUc;

    onBes->veri = 15;
    onBes->siradaki = onAlti;
    onBes->onceki = onDort;

    onAlti->veri = 16;
    onAlti->siradaki = onYedi;
    onAlti->onceki = onBes;

    onYedi->veri = 17;
    onYedi->siradaki = onSekiz;
    onYedi->onceki = onAlti;

    onSekiz->veri = 18;
    onSekiz->siradaki = onDokuz;
    onSekiz->onceki = onYedi;

    onDokuz->veri = 19;
    onDokuz->siradaki = NULL;
    onDokuz->onceki = onSekiz;




    baglantiNullama(sifir);
    kListeNulla(kListe1);
    //azalanSiralama(onDokuz);
    //artanSiralama(sifir);
    rastgeleGraf(matris);
    matrisYazdir(matris);
    dogrulukDenetimi(matris);
    baglantiKurma(matris, sifir);
    //kenarYazdir(sifir);
    bilesenYazdir(sifir, 0);
    yolAgirlikEkle(matris, agirlikMatrisi);

    std::cout << std::endl;
    gecici = sifir;
    for (int i = 0; i <= 19; i++)
    {
        std::cout << gecici->ziyaretEdildiMi << ", " << gecici->veri << "| ";
        gecici = gecici->siradaki;
    };
    std::cout << std::endl;
    matrisYazdir(agirlikMatrisi);
    std::cout << std::endl;
    int ilk = -1;
    bool p = true;
    while (p != false)
    {
        ziyaretSifirlama(sifir);
        uzaklikSifirlama(sifir);
        enKisaYolSifirlama(sifir);
        std::cout << std::endl;
        std::cout << "yolu bulunacak dugumu giriniz (0 ila 19 arasinda) (---> cikmak icin herhangi bir sayiyi negatif giriniz)    ";
        std::cin >> ilk;
        if (ilk < 0)
        {
            p = false;
        }
        else if (ilk > 19)
        {
            std::cout << "Lutfen 0 ila 19 arasinda sayi giriniz";
        }
        else
        {
            std::cout << "Kaynak-Hedef      Rota                    Mesafe";
            std::cout << std::endl;
            gecici = sifir;
            while (gecici->veri != ilk)
            {
                gecici = gecici->siradaki;
            };
            gecici->uzaklik = 0;
            dijAlgo(gecici, ilk, agirlikMatrisi,sifir);

            //std::cout << std::endl;
            //rotaDogrulukDenetimi(sifir);
            rotaYazdir(sifir,gecici,ilk);
        };
        /*std::cout << std::endl;
        if (onDokuz->ziyaretEdildiMi == true)
        {
            std::cout << "edildi";
        }
        else
        {
            std::cout << "yok";
        };*/
    };
};