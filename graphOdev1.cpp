// graphOdev1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Eren Uğuray ERAY || 141002082 || İ.Ö
//Graf Teorisi Ödev 1

#include <iostream>
#include <random>
class dugum {
    public:
        int veri;
        dugum* siradaki;
        dugum* onceki;
        dugum* baglanti[20];
        bool ziyaretEdildiMi = false;
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
/*Erdös ve Renyil algoritması ile rastgele bir graf ve komşuluk matrisi oluşturur*/
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


    /*for (int k = 0; k <= 19 && sayacDgm != NULL; k++)
    {
        if (sayacDgm->ziyaretEdildiMi == false)
        {
            bilesenBulma(sayacDgm, 0);
        }
        else
        {
            sayacDgm = sayacDgm->onceki;
        };
    };*/
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
    baglantiKurma(matris,sifir);
    //kenarYazdir(sifir);
    bilesenYazdir(sifir, 0);

    std::cout << std::endl;
    /*for (int v = 0; v <= 19; v++)
    {
        if (kListe1->baglanti[v] != NULL)
        {
            std::cout << kListe1->baglanti[v]->veri << ", ";
        }
    };
    std::cout << std::endl;
    for (int v = 0; v <= 19; v++)
    {
        if (bilesenListe[v] != -1)
        {
            std::cout << bilesenListe[v] << ", ";
        }
    };*/
    gecici = sifir;
    for (int i = 0; i <= 19; i++)
    {
        /*for (int j = 0; j <= 19; j++)
        {
            
        };*/
        std::cout << gecici->ziyaretEdildiMi << ", "<<gecici->veri<<"| ";
        gecici = gecici->siradaki;
    };

    
    

};

/* liste atama

    //std::cout << dgm->veri << std::endl;
    kalinanListe2[j] = dgm->veri;
    kalinanDgm = dgm;
    sayac = 0;
    if (i <= 19)
    {
        for (int r = 0; r <= 19; r++)
        {
            if (kalinanDgm->veri != kalinanListe[r])
            {
                //std::cout << r << std::endl;
                //bilesenBulma(dgm, kalinanDgm, sabitDgm, kalinanListe, kalinanListe2, i, j);
            };
        };
    };
    //bilesenBulma(dgm, kalinanDgm, sabitDgm, kalinanListe, i);
*/

/*-----------------kenar yazdırma------------------------------

dugum* dgm1 = new dugum();
    dugum* dgm2 = new dugum();
    dgm1 = sifir;
    dgm2 = sifir;
    for (int i = 0; i <= 19 && dgm1 != NULL; i++)
    {
        for (int j = 0; j <= 19; j++)
        {
            std::cout << dgm1->veri << " || " << dgm1->baglanti[j] << ", ";
        };
        std::cout << std::endl;
        dgm1 = dgm1->siradaki;
    };

*/
/* -------------------------bağlantı atama---------------------
    dugum* dgm1 = new dugum();
    dugum* dgm2 = new dugum();*/
    //dgm1 = sifir;
    //dgm2 = sifir;
    //for (int i = 0; i <= 19 && dgm1 != NULL; i++)
    //{
    //    for (int j = 0; j <= 19 && dgm2 != NULL; j++)
    //    {
    //        dgm1->baglanti[j] = dgm2;
    //        //std::cout << dgm1->baglanti[j] << ", ";
    //        dgm2 = dgm2->siradaki;
    //    };
    //    dgm1 = dgm1->siradaki;
    //    dgm2 = sifir;
    //};

/*------------bağlantı denetimi---------
    dgm1 = sifir;
    dgm2 = sifir;
    for (int i = 0; i <= 19 && dgm1 != NULL; i++)
    {
        for (int j = 0; j <= 19 ; j++)
        {
            std::cout << dgm1->veri<< " || " << dgm1->baglanti[j] << ", ";
        };
        std::cout << std::endl;
        dgm1 = dgm1->siradaki;
    };
    std::cout << yedi->baglanti[13]->baglanti[3]->baglanti[19]->veri << std::endl;
    
*/


/*---------------------dugum atama-----------------
* 
    int k, h;
    int i = 5, j = 11;
    for (k = 0; k <= i; k++)
    {
        for (h = 0; h <= j; h++)
        {
        };
    };
    --h;
    --k;
    std::cout << h << ' ' << k << std::endl;

*/

/*-------------------bağlantı oluşturma-------------------
* 
int(&baglantıKurma(int (&dizi)[20][20]))[20][20]
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << dizi[i][j] << ", ";
        };
        std::cout << std::endl;
    };
    return dizi;
};

*/

/* --------------------null doğrulama---------------------------

    dugum* gecici = new dugum();
    gecici = dgm;
    for (int i = 0; i < 20 || gecici != NULL; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            std::cout << "sayi " << i << " , " << gecici->baglanti[k] << ", " << std::endl;
        };
        gecici = gecici->siradaki;
        std::cout << std::endl;
    };

*/

/* --------------------------- atama işlemleri-------------------------------------
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
*/

//dugum* gecici = new dugum();
//gecici = dgm1;
//int bileseninDugumleri[20] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
//int bilesenSayisi = 0;
//for (int i = 0; i <= 19 && dgm1 != NULL; i++)
//{
//    //std::cout << i+1 <<". bilesen      dugumleri = ";
//    for (int j = 0; j <= 19 && dgm2 != NULL; j++)
//    {
//        if (dgm1->baglanti[j] != NULL)
//        {
//            bileseninDugumleri[j] = dgm1->baglanti[j]->veri;
//            //std::cout << bileseninDugumleri[j]<<", ";
//        };
//    };
//    //std::cout << std::endl;
//    if (dgm1->veri) {}
//    dgm1 = dgm1->siradaki;
//    dgm2 = gecici;
//};
//if (sabit <= 19)
//{
//    //bilesenBulma();
//};

/*



    kl2->baglanti[j] = dgm;
    liste[j] = i;
    //std::cout <<kl2->baglanti[j]->veri << ", ";
    ////std::cout << kl1->baglanti[i]->veri;
    //std::cout <<liste[j]<< "j"<< j << ", ";
    sayacDgm = dgm;
    int durum = 1;
    int sayac = i+1;
    int sonSayac = 0;
    while (durum != 0 && sayac <= 19)
    {
        if (sayacDgm->baglanti[sayac] != NULL)
        {
            durum = 0;
            sayacDgm = sayacDgm->baglanti[sayac];
            dgm = sayacDgm;
            kl1->baglanti[j] = dgm;
            i = kl1->baglanti[j]->veri;
            j++;
            kl2->baglanti[j] = dgm;
            bilesenBulma(sayacDgm, dgm, sabitDgm, kl1, kl2, i, j, liste,u);
        }
        ++sayac;
    };
    //std::cout << sayacDgm->veri << ", ";
    //std::cout << sayac<<",s ";
    //std::cout << j <<",s ";
    /*sayac--;
    u--;
    //if (kl1->baglanti[u] == kl2->baglanti[u+1])
    //{
    //    //std::cout << "esit";
    //};

sayacDgm = kl2->baglanti[j - 1];
//std::cout << sayacDgm->veri << ", ";
i = sayacDgm->veri;
//std::cout << sayacDgm->veri << ", "<<i<<"! ";
for (int f = 0; f <= 19 && kl2->baglanti[f] != NULL; ++f)
{
    if (kl2->baglanti[f]->veri != i)
    {
        u++;
        //std::cout << u << ", " /*<< kl2->baglanti[f]->veri<<"|";
    };
};;

std::cout << u << ", ";



*/