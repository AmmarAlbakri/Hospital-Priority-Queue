#ifndef Hasta_h
#define Hasta_h
#include<string>
#include<cstring>
using namespace std;
class Hasta{
    
	int hastaNo;
	char hastaAdi[30];
	int hastaYasi;
	char cinsiyet[1];
	bool mahkumlukDurumBilgisi;
	int engellilikOrani;
    char kanamaliHastaDurumBilgisi[15];
	double hastaKayitSaati;
	double muayeneSaati;	       
	int muayeneSuresi;       	
	int oncelikPuani ;	
  public:
	void print();
    void operator=(Hasta const &rhs);
  
    int gethastaNo(){
        return hastaNo;
    }
    char* gethastaAdi(){
        return hastaAdi;
    }
    int getHastaNo(){
        return hastaNo;
    }
    int gethastaYasi(){
        return hastaYasi;
    }
    char* getcinsiyet(){
        return cinsiyet;
    }
    bool getmahkumlukDurumBilgisi(){
        return mahkumlukDurumBilgisi;
    }
    int getengellilikOrani(){
        return engellilikOrani;
    }
    char* getkanamaliHastaDurumBilgisi(){
        return kanamaliHastaDurumBilgisi;
    }
    double gethastaKayitSaati(){
        return hastaKayitSaati;
    }
    double getmuayeneSaati(){
        return muayeneSaati;
    }
    int getmuayeneSuresi(){
        return muayeneSuresi;
    }
    int getoncelikPuani(){
        return oncelikPuani;
    }
    
    void sethastaNo(int x){
        hastaNo=x;
    }
    void sethastaAdi(string x){
        strcpy(hastaAdi,x.c_str());
    }
    void sethastaYasi(int x){
        hastaYasi=x;
    }
    void setcinsiyet(string x){
        strcpy(cinsiyet,x.c_str());
    }
    void setmahkumlukDurumBilgisi(bool x){
        mahkumlukDurumBilgisi=x;
    }
    void setengellilikOrani(int x){
        engellilikOrani=x;
    }
    void setkanamaliHastaDurumBilgisi(string x){
        strcpy(kanamaliHastaDurumBilgisi,x.c_str());
    }
    void sethastaKayitSaati(double x){
        hastaKayitSaati=x;
    }
    void setmuayeneSaati(double x){
        muayeneSaati=x;
    }
    void setmuayeneSuresi(int x){
        muayeneSuresi=x;
    }
    void setoncelikPuani(int x){
        oncelikPuani=x;
    }
    
    
    
    
    
    
    
    
    
    
};
#endif
