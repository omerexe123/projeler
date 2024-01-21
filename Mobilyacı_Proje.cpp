#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<stdio.h>

using namespace std;

void giriş();
void listeleme();
void arama();
void silme();
void düzenleme();

struct Mobilya
{
    string kategorı;
    int fıyat;
    char urun_no[5];
    string renk;
    string isim;
};
Mobilya mbl;

int main()
{
    setlocale(LC_ALL,"Turkish");

    int secim;
    int cvp;
    
    do
    {
    cout<<"\n";
    system("cls");
    cout<<"\n";
    cout<<"|->-->-->-->--<--<--<--<-<|"<<endl;
    cout<<"|       HOŞ GELDİNİZ..    |"<<endl;
    cout<<"|                         |"<<endl;
    cout<<"|  1->  Ürün Girişi    <- |"<<endl;
    cout<<"|  2->  Ürün Listeleme <- |"<<endl;
    cout<<"|  3->  Ürün Arama     <- |"<<endl;
    cout<<"|  4->  Ürün Silme     <- |"<<endl;
    cout<<"|  5->  Ürün Düzenleme <- |"<<endl;
    cout<<"|->-->-->-->--<--<--<--<-<|"<<endl;
    cout<<endl;
    cout<<"Yapmak istediğiniz işlemi seçiniz (1/2/3/4/5): ";
    cin>>secim;
    cout<<"\n";

    switch (secim)
    {
        case 1:
             {
              giriş();
              break;
             }
        case 2:
            {
              listeleme();
              break;
            }
        case 3:
            {
              arama();
              break;
            }
        case 4:
            {
              silme();
              break;
            }
        case 5:
            {
              düzenleme();
              break;
            } 
    }    
    cout<<endl;
    cout<<"Ana Menüye Dönmek İçin (1), Kapatmak İçin (0): ";
    cin>>cvp;
    cout<<"\n";

    }
    while(cvp==1);
    return 0;
}

//Ürün Girişi Yapma Fonksiyonu
void giriş()
{
    cout<<"Ürün Girişi Yapıyorsunuz..\n";
    cout<<"\n";

    ofstream yaz("veriler.dat",ios::binary | ios::app);

    int cvp;
    int sayac;
    do{
        cout<<"Ürünün Kategorisini Girniz: ";
        cin>>mbl.kategorı;
        cout<<"Ürünün Ürün Numarası Girniz: ";
        cin>>mbl.urun_no;
        cout<<"Ürünün Rengini Girniz: ";
        cin>>mbl.renk;
        cout<<"Ürünün İsmini Giriniz: ";
        cin>>mbl.isim;
        cout<<"Ürünün Fiyatını Girniz: ";
        cin>>mbl.fıyat;
        cout<<"\n";

        sayac++;

        yaz.write((char*)&mbl,sizeof(mbl));

        cout<<"Tekrar ürün girmek için (1/0): ";
        cin>>cvp;
        cout<<"\n";
    }while(cvp==1);
    cout<<"Eklenen Ürün Sayısı: "<<sayac;
    cout<<"\n";
    yaz.close();
}

//Ürün Listeleme Fonksiyonu
void listeleme()
{
    ifstream oku("veriler.dat",ios::binary | ios::app);
    oku.seekg(0,ios::end);

    int adet=oku.tellg()/sizeof(mbl);
    cout<<"Toplam Ürün Sayısı: "<<adet<<"\n";
    cout<<endl;
    cout<<"   ---> ÜRÜNLER <---  \n";

    if(adet>0)
    {
       for (int i = 0; i <adet ; i++)
       {
        oku.seekg(i*sizeof(mbl));
        oku.read((char*)&mbl,sizeof(mbl));
        cout<<"\n";
        cout<<i+1<<". Ürünün Bilgileri \n";
        cout<<"Kategori: "<<mbl.kategorı<<"\n";
        cout<<"Numara: "<<mbl.urun_no<<"\n";
        cout<<"Renk: "<<mbl.renk<<"\n";
        cout<<"İsim: "<<mbl.isim<<"\n";
        cout<<"Fiyat: "<<mbl.fıyat<<"\n";
        cout<<"------------------------\n";
       }
       oku.close();
    }
    else
    cout<<"Kayıtlı Ürün Bulunamadı..\n"; 
}

//Ürün Arama Fonksiyonu
void arama()
{
    ifstream oku("veriler.dat",ios::binary | ios::app);
    oku.seekg(0,ios::end);
    int adet=oku.tellg()/sizeof(mbl);

    char urunno[5];
    cout<<"Aramak İstediğiniz Ürün Numarasını Giriniz: ";
    cin>>urunno;

    if(adet>0)
    {
       for (int i = 0; i <adet ; i++)
       {
        oku.seekg(i*sizeof(mbl));
        oku.read((char*)&mbl,sizeof(mbl));

        if(strcmp(mbl.urun_no,urunno)==0)
        {
        cout<<"\n";
        cout<<"Bulunan Ürünün Bilgileri.. \n";
        cout<<"Kategori: "<<mbl.kategorı<<"\n";
        cout<<"Numara: "<<mbl.urun_no<<"\n";
        cout<<"Renk: "<<mbl.renk<<"\n";
        cout<<"İsim: "<<mbl.isim<<"\n";
        cout<<"Fiyat: "<<mbl.fıyat<<"\n";
        cout<<"------------------------\n";
        }
    
       }
       cout<<"\nAranan Ürün Bulunnamadı..\n";
       oku.close();
    }
    else
    cout<<"Kayıtlı Ürün Bulunamadı..\n";  
}

//Ürün Silme Fonksiyonu
void silme()
{
    ifstream oku("veriler.dat",ios::binary | ios::app);
    oku.seekg(0,ios::end);
    int adet=oku.tellg()/sizeof(mbl);
    bool var=false;
    int secım;
    char urunno[5];
    cout<<"Silmek İstediğiniz Ürün Numarasını Giriniz: ";
    cin>>urunno;

    if(adet>0)
    {
       for (int i = 0; i <adet ; i++)
       {
        oku.seekg(i*sizeof(mbl));
        oku.read((char*)&mbl,sizeof(mbl));

        if(strcmp(mbl.urun_no,urunno)==0)
        {
        cout<<"\n";
        cout<<"Silinecek Ürünün Bilgileri.. \n";
        cout<<"Kategori: "<<mbl.kategorı<<"\n";
        cout<<"Numara: "<<mbl.urun_no<<"\n";
        cout<<"Renk: "<<mbl.renk<<"\n";
        cout<<"İsim: "<<mbl.isim<<"\n";
        cout<<"Fiyat: "<<mbl.fıyat<<"\n";
        cout<<"------------------------\n";

        cout<<"Ürün Kaydını Silmek İstiyor musunuz ? (1/0)";
        cin>>secım;

        if(secım==0)
        {

            ofstream y_yaz("Yedek.dat",ios::app|ios::binary);

            y_yaz.write((char*)&mbl,sizeof(mbl));
            y_yaz.close();
        }
        else if(secım==1)
        {
          var=true;
        }

        }
        else
        {
            //Silinmeycek Ürünler
            ofstream y_yaz("Yedek.dat",ios::app|ios::binary);

            y_yaz.write((char*)&mbl,sizeof(mbl));
            y_yaz.close();

       }
       
    }
    oku.close();

    if(var)
    {
        remove("veriler.dat");
        rename("Yedek.dat","veriler.dat");
        cout<<"KAYIT SİLİNDİ ✓✓✓\n";
    }
    else
    {
        remove("Yedek.dat");
        cout<<"Kayıt Bulunamadı..\n";
    }
    }
    else
    cout<<"Kayıtlı Ürün Bulunamadı..\n"; 
}

//Ürün Düzenleme Fonksiyonu
void düzenleme()
{
    ifstream oku("veriler.dat",ios::binary | ios::app);
    oku.seekg(0,ios::end);
    int adet=oku.tellg()/sizeof(mbl);
    bool var=false;
    int secım;
    char urunno[5];
    cout<<"Düzeltmek İstediğiniz Ürün Numarasını Giriniz: ";
    cin>>urunno;

    if(adet>0)
    {
       for (int i = 0; i <adet ; i++)
       {
        oku.seekg(i*sizeof(mbl));
        oku.read((char*)&mbl,sizeof(mbl));

        if(strcmp(mbl.urun_no,urunno)==0)
        {
        cout<<"\n";
        cout<<"Düzeltilecek Ürünün Bilgileri.. \n";
        cout<<"Kategori: "<<mbl.kategorı<<"\n";
        cout<<"Numara: "<<mbl.urun_no<<"\n";
        cout<<"Renk: "<<mbl.renk<<"\n";
        cout<<"İsim: "<<mbl.isim<<"\n";
        cout<<"Fiyat: "<<mbl.fıyat<<"\n";
        cout<<"------------------------\n";

        cout<<"Ürün Kaydını Düzenlemek İstiyor musunuz ? (1/0)";
        cin>>secım;

        if(secım==0)
        {

            ofstream y_yaz("Yedek.dat",ios::app|ios::binary);

            y_yaz.write((char*)&mbl,sizeof(mbl));
            y_yaz.close();
        }
        else if(secım==1)
        {
          var=true;

          ofstream y_yaz("Yedek.dat",ios::app|ios::binary);

              cout<<"Ürünün Kategorisini Girniz: ";
              cin>>mbl.kategorı;
              cout<<"Ürünün Ürün Numarası Girniz: ";
              cin>>mbl.urun_no;
              cout<<"Ürünün Rengini Girniz: ";
              cin>>mbl.renk;
              cout<<"Ürünün İsmini Girniz: ";
              cin>>mbl.isim;
              cout<<"Ürünün Fiyatını Girniz: ";
              cin>>mbl.fıyat;
              cout<<"\n";

         y_yaz.write((char*)&mbl,sizeof(mbl));
         y_yaz.close();

        }

        }
        else
        {
            //Düzeltilmeyecek Ürünler
            ofstream y_yaz("Yedek.dat",ios::app|ios::binary);

            y_yaz.write((char*)&mbl,sizeof(mbl));
            y_yaz.close();

       }
       
    }
    oku.close();

    if(var)
    {
        remove("veriler.dat");
        rename("Yedek.dat","veriler.dat");
        cout<<"KAYIT DÜZENLENDİ✓✓✓\n";
    }
    else
    {
        remove("Yedek.dat");
        cout<<"Kayıt Bulunamadı..\n";
    }
    }
    else
    cout<<"Kayıtlı Ürün Bulunamadı..\n"; 
}
