//                                                                                          Eren Uğuray ERAY 141002082 İkinci Öğretim
//                                                          GRAF TEORİSİ İKİNCİ ÖDEVİ
//
//      NOTLAR:
//              - Dördüncü ödevi, Üçüncü ödevin üzerinde yaptım.
//              - Üçüncü ödevi, İkinci ödevin üzerinde yaptım.
//              - İkinci ödevi, birinci ödevin üzerinde yaptım.
//              1. ÖDEV NOTU:
//                          - tembel olduğum için grafı ve komşuluk matrisini otomatikleştirdim.
//                          - otomatikleştirdiğim kısımlar için gereken random kütüphanesi codeblock'ta çalışmıyor.
//                          - kodun çalışmaklığını denemek için; 
//                                      - < main > fonksiyonundaki < matris > değişkeni içine 0 veya 1 değerlerini girerseniz komşuluğu deneyebilirsiniz.
//                                      - değerleri matrisin ilkköşegenine simetrik giriniz. < dizi[0][10]=1 > ise < dizi[10][0] >'da 1 olacak.
//                          - otomatikleştirdiğim fonksiyonların çağırıldığı yerleri yorum satırı yapınız.
//
//              2. ÖDEV NOTU:
//                          - tembel olduğum için dijkstra algoritması için gereken yol ağırlıklarını otomatikleştirdim.
//                          - otomatikleştirdiğim kısımlar için gereken random kütüphanesi codeblock'ta çalışmıyor.
//                          - kodun çalışmaklığını denemek için;
//                                      - < main() > fonksiyonundaki < agirlikMatrisi > değişkeni içine 1 ila 10 arasında bir değer girin.
//                                      - değerleri matrisin ilkköşegenine simetrik giriniz. < dizi[0][10]=8 ise dizi[10][0] >'da 8 olacak.
//                          - otomatikleştirdiğim fonksiyonların çağırıldığı yerleri yorum satırı yapınız.
//              3. ÖDEV NOTU:
//                          - ama kod bu haliyle hiç değiştirilmeden  < Visual Studio >'da çalışmaktadır.
//                          - kod parçası < Code Block > ortamında bazen determinantı, bölme işlemlerini yanlış hesapladığı için yanlış buluyor.
//                              muhtemelen bu compiler farklılığı yüzünden.
//                              ancak < Visual Studio > ile yapıldığında determinant her zaman çok düşük bir hata payı ile doğru sonucu buluyor.
//                              eğer ki < Code Block >'ta doğru sonucu bulamazsanız lütfen yanlış yaptığımı düşünmeyin.
//                          - DİKKAT!!! < Code Block >'ta random oluşturduğu grafı doğru hesaplıyor. 
//                                      (tek sorun devamlı aynı grafı oluşturuyor. en azından bende ki öyle)
//                          - diğer ödevlerin devamı olduğu için, önceki ödevlerde otomatikleştirdiğim şeyler burada da işlevlerini sürdürmektedir.
//                          - kodun çalışmaklığını denemek için;
//                                      - < main() > fonksionunun başındaki < mttMatrisi>'ni ve en alttaki < yayilimAgacSayisiBulma(dereceMatrisi) > 
//                                          fonksiyonunu yorum satırından çıkarın. Yine aşağıda bulunan < yayilimAgacSayisiBulma(mttMatrisi) > 
//                                          fonksiyonunu yorum satırı yapın.
//                                      - ÖNEMLİ!!!     < FLT_EPSILON > < Visual Studioda > kendiliğinden tanımlı eğer < Visual Studio >'da 
//                                                      denenecekse en başta ki < #define FLT_EPSILON > satırını yorum satırı yapın.
//                          - determinant hesaplamasının doğruluğunu denetlemek için;
//                                      - ilk olarak ödevi çalıştırın. (ÖNEMLİ!!)
//                                      - ödevi çalıştırdığınızda gelen CMD ekranından özel olarak yazdırdığım Gauss Elimination 
//                                          matrisini < CTRL+C > ile kopyalayın.
//                                      - https://matrix.reshish.com/determinant.php sitesine gidin. (ben doğruluğunu buradan denetledim.)
//                                      - sol taraftaki panelden < Determinant >'ı seçin.
//                                      - matrisin boyutunu girin (19)
//                                      - < Set Matrix >'e tıklayın.
//                                      - gelen pencerenin üst orta kısmında < Insert Matrix >'e tıklayın.
//                                      - boş editore kopyaladığınız matrisi yapıştırın.
//                                      - sağ aşağıda < Continue >'ye tıklayın.
//                                      - tekrar sağ aşağıda bulunan < Calculate >'e tıklayın.
//                                      - cevap karşınızda.
//                          -  UYARI!!! eğer < Visual Studio > ile denerseniz grafı otomatik oluşturduğu için bazen birden fazla bileşeni olan graf 
//                              oluşturuyor. bir bileşenli olana kadar yeniden başlatın.(zaten çoğunlukla tek bileşenli çıkıyor.)
//              4. ÖDEV NOTU:
//                          - Otomatikleştirdiğim graf ağaç elde eder ancak ihtimali çok düşük o yüzden aşağıdaki yönergeleri izleyin.
//                          - Aşağıdakilerin tersini otomatikleştirdiğim yerleri görmek için tam tersini yapın.
//                          - UYARI!!!!!    Aşağıdakileri yapmanıza gerek yok zira yapılmış halini gönderiyorum.(aşağısı sadece bilgi içindir.)
//                          - kodun çalışmaklığını denemek için (< Code Block >'ta da, < Visual Studio > içinde geçerli.);
//                                      - 925. satırdaki < baglantiKurma(matris, sifir); > yorum satırı yapın. (UYARI!!! Yapmazsan ÇALIŞMAZ)
//                                      - 981. satırdaki < baglantiKurma(agacMatrisi, sifir); > ve
//                                        982. satırdaki < bilesenYazdir(sifir, 0); > ve 
//                                        984. satırdaki < agacOlmakligiDenetleme(sifir, agacMatrisi); > yorum satırından çıkarın.
//                                      - 985. satırdaki < agacOlmakligiDenetleme(sifir, matris); > yorum satırı yapın.
//                                      - İki adet < agacMatrisi > vardır. biri karmaşık biri basittir.
//                          - < agacMatrisi > üzerinde denemek üzere değişiklik yapmak için;
//                                      - UYARI!!!!!!! ÖNEMLİ!!!!!!! Yoksa çalışMAZ.
//                                      - < agacMatrisi[i][j] >'inci değeri ne ise < agacMatrisi[j][i] >'inci değeride aynı olmak zorundadır.

//      GÜNCELLENENLER
//          - Artık matrislerin üzerinde başlıkları yazıyor (komşuluk, matrix tree, rastgele oluşan vs. )
//          - Gereksiz çıktılar silindi.
//          - Artık kısa yolunun bulunması için girilecek olan düğüm numarası için 0 ila 19 arasındaki sayılar hariç başka karakter girilirse
//            hata verecek ve baştan girmesi istenecek.
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
//#define FLT_EPSILON 1.192092896e-07F
;
class dugum {
public:
    int veri;
    dugum* siradaki;
    dugum* onceki;
    dugum* baglanti[20];
    bool ziyaretEdildiMi = false;
    dugum* enKisaOnceki;
    int uzaklik = SONSUZ;
    dugum* cocuklari[20];
    dugum* ebeveyni;
};
/* Düğüm sınıfındaki 'baglanti' içeriğini nullar */
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
int(&matrisYazdir(int(&dizi)[20][20], int belirtec = 100))[20][20]
{
    switch (belirtec)
    {
    case 1:
        std::cout << "              ERDOS ve RENYIL rastgele graf algoritmasi ile olusturuldu!" << std::endl;
        break;
    case 2:
        std::cout << "                                  Komsuluk Matrisi" << std::endl;
        break;
    case 3:
        std::cout << "                                  Grafin Matrix Tree Theorem Matrisi" << std::endl;
        break;
    default:
        std::cout << "Henuz tanimlanmamis veya bilinmeyen MATRIS!!!!!" << std::endl;
        break;
    };
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
/*  kenarları ekrana yazdırır   */
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
/*  Özyinelemeli(recursive) fonksiyon olarak çalışır ve grafın alt bileşenleri bulunur  */
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
/*  bulnan bileşenleri yazdırır */
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
        dgm->uzaklik = SONSUZ;
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
            yolBulma(enKisaYol, enKisaYol->veri, agirlikM, basDgm);
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
    for (; dgm != NULL; dgm = dgm->siradaki)
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
            if (geciciDgm->uzaklik != 100)
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
        if (geciciDgm->siradaki != NULL)
        {
            geciciDgm = geciciDgm->siradaki;
        };
        sayacDgm = geciciDgm;
    };
};
/*  düğümlerin derecelerini hesaplar   */
void dereceBulma(int(&dizi1)[20][20], int(&dizi2)[20][20])
{
    for (int t = 0; t <= 19; t++)
    {
        int derece = 0;
        for (int h = 0; h <= 19; h++)
        {
            if (dizi2[t][h] != 0 && t != h)
            {
                dizi1[t][h] = -1;
                derece = derece + 1;
            }
            else
            {
                dizi1[t][h] = 0;
            };
        };
        dizi1[t][t] = derece;
    };
};
/*  gaussElimination ile üst üçgen matrisine dönüşen matrisin determinantını hesaplar   */
double determinantHesaplama(double gaussMatrisi[19][19], double determinant)
{
    for (int a = 0; a <= 18; a++)
    {
        determinant *= gaussMatrisi[a][a];
    };
    return determinant;
};
/*  gauss elimination yolu ile matrisi üst matris şekline sokar    */
double(&gaussElimination(double(&matris)[19][19]))[19][19]
{
    for (int h = 0; h <= 18; h++)
    {
        for (int r = h + 1; r <= 18; r++)
        {
            double carpan = (matris[r][h] / matris[h][h]);
            if (abs(matris[r][h]) > FLT_EPSILON)
            {
                for (int k = 0; k <= 18; k++)
                {
                    matris[r][k] = matris[r][k] + (matris[h][k] * carpan) * -1;
                };
            }
            else
            {
                matris[r][h] = 0;
            };
        };
    };
    return matris;
};
/*  yayılım ağac sayısını matrix tree theorem ile bulur */
void yayilimAgacSayisiBulma(int dizi[20][20])
{
    double determinant = 1;
    double gaussMatrisi[19][19];

    for (int u = 0; u <= 18; u++)
    {
        for (int f = 0; f <= 18; f++)
        {
            gaussMatrisi[u][f] = dizi[u][f];
        };
    };
    gaussElimination(gaussMatrisi);
    gaussElimination(gaussMatrisi); // 0'dan çok çok az küçük yada çok çok az büyük (+-) olan sayıları 0'a eşitlemek için ikinci kere eleminasyon yapılıyor. görsel olarak etkili.
    std::cout << std::endl;
    std::cout << "Not: Asagidaki matrisin boyle yazilmasinin nedeni 3.Odev notlarinda yazan adreste determinant dogrulugunun kolayca kopyala-yapistir ile denetlenebilmesi icindir." << std::endl << std::endl;
    std::cout << "          Gauss Eleminasyon ile bulunan matris" << std::endl;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            std::cout << gaussMatrisi[i][j] << " ";
        };
        std::cout << std::endl;
    };
    std::cout << std::endl;
    determinant = determinantHesaplama(gaussMatrisi, determinant);
    long long int lliDeterminant = determinant;
    std::cout << " Matrix Tree Theorem ile bulunan yayilim agaci sayisi:   " << std::endl;
    if (lliDeterminant == 0 && determinant == 0)
    {
        std::cout << "      -Parcali bir graf oldugundan yayilim agaci sayisi 0'dir." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << " Double veri tipi ile        :           " << floor(determinant) << std::endl;
        std::cout << " Long Long Int veri tipi ile :           " << lliDeterminant << " ##### Not: burasi (-)'li cikarsa long long int'in kapasitesini asmasi nedeniyledir." << std::endl;
        std::cout << std::endl;
    };
};
/*  graf döngülü yada ayrık mı diye bakıyor */
void ayrikVeKenarDenetleme(dugum* sayacDgm,int i,float& kenarSayisi)
{
    sayacDgm->ziyaretEdildiMi = true;
    int sayac = 0;
    while (sayac < 20)
    {
        if (sayacDgm->baglanti[sayac] != NULL)
        {
            if (sayacDgm->baglanti[sayac]->ziyaretEdildiMi == false)
            {
                ayrikVeKenarDenetleme(sayacDgm->baglanti[sayac], i,kenarSayisi);
            }
            else
            {
                kenarSayisi++;
                sayac++;
            };
        }
        else
        {
            sayac++;
        };
    };
};
/*  grafın ağac olmaklığını denetleme */
void agacOlmakligiDenetleme(dugum* dgm,int komsulukMatrisi[20][20])
{
    float kenarSayisi = 0;
    int sayac = 0;
    int hata[5] = { 0,0,0,0,0 };
    for (int i = 0; i < 20 && dgm != NULL; i++)
    {
        if (dgm->ziyaretEdildiMi == false)
        {
            ++sayac;
            if (sayac != 2)
            {
                ayrikVeKenarDenetleme(dgm, i, kenarSayisi);
                i--;
            }
            else
            {
                hata[0] = 5;
                break;
            };
        }
        else
        {
            dgm = dgm->siradaki;
        };
    };
    std::cout << std::endl;
    kenarSayisi /= 2;
    if (kenarSayisi > 19 || kenarSayisi < 19)
    {
        hata[1] = 4;
    };
    for (int u = 0; u < 5; u++)
    {
        switch (hata[u])
        {
        case 5:
            std::cout << "Verilen graf bir agac degildir. Cunku parcali graftir." << std::endl;
            u = 6;
            break;
        case 4:
            std::cout << "Verilen graf bir agac degildir. Cunku dongu barindiriyor." << std::endl;
            u = 6;
            break;
        default:
            if (u == 4)
            {
                std::cout << "Verilen graf bir agactir." << std::endl;
            };
            break;
        };
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
    int dereceMatrisi[20][20] = { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
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
    /*
    //daha karmaşık bir ağaç
    int agacMatrisi[20][20] = {
        {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
    };*/
    int agacMatrisi[20][20] = {
        {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
    };
    
    /*int mttMatrisi[20][20]=
    { {10, -1, 0, 0, 0, -1, 0, -1, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, -1, 0},
{ -1, 11, 0, -1, -1, 0, -1, -1, 0, -1, 0, 0, -1, 0, -1, 0, -1, 0, -1, -1},
{ 0, 0, 11, -1, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, 0, -1, 0, -1, -1, 0},
{ 0, -1, -1, 10, 0, -1, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, 0, -1},
{ 0, -1, 0, 0, 8, 0, -1, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1},
{ -1, 0, -1, -1, 0, 9, -1, -1, 0, 0, 0, -1, 0, -1, 0, -1, -1, 0, 0, 0},
{ 0, -1, -1, 0, -1, -1, 12, -1, 0, -1, 0, -1, -1, 0, -1, -1, 0, -1, 0, -1 },
{ -1, -1, -1, 0, 0, -1, -1, 13, -1, 0, -1, -1, -1, -1, 0, -1, -1, 0, 0, -1},
{ -1, 0, -1, -1, 0, 0, 0, -1, 9, 0, 0, -1, -1, -1, -1, 0, 0, 0, -1, 0},
{ -1, -1, 0, 0, 0, 0, -1, 0, 0, 10, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0},
{ 0, 0, 0, -1, 0, 0, 0, -1, 0, -1, 7, -1, -1, -1, 0, 0, 0, -1, 0, 0},
{ -1, 0, -1, 0, 0, -1, -1, -1, -1, 0, -1, 13, -1, 0, -1, -1, 0, -1, -1, -1},
{ -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 15, -1, 0, -1, 0, 0, -1, -1},
{ -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, 0, -1, 10, 0, 0, -1, 0, 0, -1},
{ 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, 0, -1, 0, 0, 10, 0, 0, -1, -1, -1},
{ -1, 0, -1, 0, 0, -1, -1, -1, 0, -1, 0, -1, -1, 0, 0, 10, -1, 0, 0, -1},
{ 0, -1, 0, -1, -1, -1, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 9, 0, -1, 0},
{ 0, 0, -1, -1, -1, 0, -1, 0, 0, -1, -1, -1, 0, 0, -1, 0, 0, 10, -1, -1},
{ -1, -1, -1, 0, -1, 0, 0, 0, -1, 0, 0, -1, -1, 0, -1, 0, -1, -1, 11, -1},
{ 0, -1, 0, -1, -1, 0, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 12}};*/
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
    matrisYazdir(matris, 1);
    dogrulukDenetimi(matris);
    baglantiKurma(matris, sifir);
    //kenarYazdir(sifir);
    bilesenYazdir(sifir, 0);
    yolAgirlikEkle(matris, agirlikMatrisi);

    std::cout << std::endl;
    gecici = sifir;
    std::cout << std::endl;
    matrisYazdir(agirlikMatrisi, 2);
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
            std::cout << "Cikis Yaptiniz....!";
            std::cout << std::endl;
        }
        else if (ilk > 19)
        {
            std::cout << "Lutfen 0 ila 19 arasinda sayi giriniz";
        }
        else if (std::cin.fail())
        {
            std::cout << "Lutfen 0 ila 19 arasinda sayi giriniz!";
            std::cin.clear();
            std::cin.ignore(256, '\n');
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
            dijAlgo(gecici, ilk, agirlikMatrisi, sifir);
            rotaYazdir(sifir, gecici, ilk);
        };
    };
    dereceBulma(dereceMatrisi, matris);
    std::cout << std::endl;
    matrisYazdir(dereceMatrisi, 3);
    yayilimAgacSayisiBulma(dereceMatrisi);
    //yayilimAgacSayisiBulma(mttMatrisi);

    //baglantiKurma(agacMatrisi, sifir);
    //bilesenYazdir(sifir, 0);
    //ziyaretSifirlama(sifir);
    //agacOlmakligiDenetleme(sifir, agacMatrisi);
    ////agacOlmakligiDenetleme(sifir, matris);
    //ziyaretSifirlama(sifir);
    //uzaklikSifirlama(sifir);
    //enKisaYolSifirlama(sifir);

    return 0;
};