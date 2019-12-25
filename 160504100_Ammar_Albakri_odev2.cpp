#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<sstream>
#include"Hasta.h"
using namespace std;
int hastaS = 0;
int size = 100;
int current = 0;
int sira = 1;

Hasta *
hastaBilgileriOku ()
{
  Hasta *data = new Hasta[size];
  ifstream file ("Hasta.txt");
  string line, temp;
  while (getline (file, line))
    {
      stringstream ss (line);
      getline (ss, temp, ',');
      getline (ss, temp, ',');
      data[hastaS].sethastaAdi (temp);
      getline (ss, temp, ',');
      data[hastaS].sethastaYasi (atoi (temp.c_str ()));
      getline (ss, temp, ',');
      data[hastaS].setcinsiyet (temp);
      getline (ss, temp, ',');
      if (strchr (temp.c_str (), 'f'))
	data[hastaS].setmahkumlukDurumBilgisi (false);
      else
	data[hastaS].setmahkumlukDurumBilgisi (true);
      getline (ss, temp, ',');
      data[hastaS].setengellilikOrani (atoi (temp.c_str ()));
      getline (ss, temp, ',');
      data[hastaS].setkanamaliHastaDurumBilgisi (temp);
      getline (ss, temp, ',');
      data[hastaS].sethastaKayitSaati (atof (temp.c_str ()));
      getline (ss, temp, ',');
      getline (ss, temp, ',');

      hastaS++;
    }
  return data;
}

void
printAll (Hasta * data)
{

  for (int i = 0; i < hastaS; i++)
    {
      data[i].print ();
    }

}

void
Hasta::print ()
{
  cout << hastaNo << "\t" << hastaAdi << "\t" << hastaYasi << "\t" << cinsiyet
    << "\t" << mahkumlukDurumBilgisi << "\t" << engellilikOrani;
  cout << "\t" << kanamaliHastaDurumBilgisi << "\t" << hastaKayitSaati <<
    setw(15)<< oncelikPuani << setw(15) << muayeneSuresi << "\n";
}

void
Hasta::operator= (Hasta const &rhs)
{
  hastaNo = rhs.hastaNo;
  strcpy (hastaAdi, rhs.hastaAdi);
  hastaYasi = rhs.hastaYasi;
  strcpy (cinsiyet, rhs.cinsiyet);
  mahkumlukDurumBilgisi = rhs.mahkumlukDurumBilgisi;
  engellilikOrani = rhs.engellilikOrani;
  strcpy (kanamaliHastaDurumBilgisi, rhs.kanamaliHastaDurumBilgisi);
  hastaKayitSaati = rhs.hastaKayitSaati;
  muayeneSaati = rhs.muayeneSaati;
  muayeneSuresi = rhs.muayeneSuresi;
  oncelikPuani = rhs.oncelikPuani;
}

bool
same (double a, double b)
{
  double epsilon = 0.0001;
  return abs (a - b) < epsilon;
}

void
incrTime (double &time)
{
  //cout<<"time plus one"<<endl;
  int tam = time;
  double noktali = time - tam;
  noktali += 0.01;
  if (same (noktali, 0.6))
    {
      tam++;
      noktali = 0.0;
    }
  time = (double) tam + noktali;
}

void
hastaKayitEkle (Hasta * data)
{
  double time = 8.00;
  int i = 1;
  while (time < 24.00)
    {
      for (int j = 0; j < hastaS; j++)
	{
	  if (same (time, data[j].gethastaKayitSaati ()))
	    data[j].sethastaNo (i++);
	}
      incrTime (time);
    }
}

void
oncelikPuaniHesapla (Hasta * data)
{
  int i;
  for (i = 0; i < hastaS; i++)
    {
      int yasPuani =
	(data[i].gethastaYasi () < 5) ? 20 : (data[i].gethastaYasi () <
					      45) ? 0 : (data[i].
							 gethastaYasi () <
							 65) ? 15 : 25;
      int mahkum = (data[i].getmahkumlukDurumBilgisi ())? 50 : 0;
      int engel = data[i].getengellilikOrani () / 4;
      int kanama =
	(strchr (data[i].getkanamaliHastaDurumBilgisi (), 'Y')) ? 0
	: (strchr (data[i].getkanamaliHastaDurumBilgisi (), 'g')) ? 50 : 20;
      data[i].setoncelikPuani (yasPuani + mahkum + engel + kanama);
    }
}

void
muayeneSuresiHesapla (Hasta * data)
{
  int i;
  for (i = 0; i < hastaS; i++)
    {
      int yasPuani = (data[i].gethastaYasi () <= 65) ? 15 : 0;
      int engel = data[i].getengellilikOrani () / 5;
      int kanama =
	(strchr (data[i].getkanamaliHastaDurumBilgisi (), 'Y')) ? 0
	: (strchr (data[i].getkanamaliHastaDurumBilgisi (), 'g')) ? 20 : 10;
      data[i].setmuayeneSuresi (yasPuani + engel + kanama + 10);
    }
}

Hasta *Heap = new Hasta[hastaS];

bool
isEmpty ()
{
  if (current - 1 < 0)
    return true;
  else
    return false;
}

void
insert (Hasta data)
{
  int i = ++current;
  //cout << "insert No :" << data.hastaNo << endl;
  while (i != 1 && data.getoncelikPuani () > Heap[i / 2].getoncelikPuani ())
    {
      Heap[i] = Heap[i / 2];
      i = i / 2;
    }
  Heap[i] = data;
}

void
remove1 ()
{
  int parent = 1, child = 2;
  Hasta temp;
  if (isEmpty ())
    cout << "The heap is empty\n";
  else
    {
//      cout<<"Deleting No :"<<Heap[1].hastaNo<<endl;
      temp = Heap[current];

      current--;
      if (current + 1 != 1)
	{
	  while (child < current)
	    {
	      if (Heap[child].getoncelikPuani () <
		  Heap[child + 1].getoncelikPuani ())
		child++;
	      if (temp.getoncelikPuani () > Heap[child].getoncelikPuani ())
		break;
	      Heap[parent] = Heap[child];
	      parent = child;
	      child *= 2;
	    }
	  Heap[parent] = temp;
	}
      else
	{
	  //delete (Heap+1);

	  //Heap[1].makeZero();
	}

    }
}

Hasta *
getMax ()
{
  if (isEmpty ())
    cout << "Heap is empty" << endl;
  else
    {
//      cout<<"Max is :"<<Heap[1].hastaNo<<endl;
      return (Heap + 1);
    }

}


int
main ()
{
  Hasta *data = hastaBilgileriOku ();
  hastaKayitEkle (data);
  oncelikPuaniHesapla (data);
  muayeneSuresiHesapla (data);
  printAll (data);
  int i;
  double time = 8;
  while (time < 9.00)
    {
      //cout << "Time :" << time << endl;
      for (i = 0; i < hastaS; i++)
	{
	  if (same (time, data[i].gethastaKayitSaati ()))
	    {
	      insert (data[i]);
	    }
	}
      incrTime (time);
    }
  bool muayeneBosMu = true;
  double beklemeSuresi = 0;
  while (time < 24.00)
    {

      //cout << "Time :" << time << endl;
      for (i = 0; i < hastaS; i++)
	{
	  if (same (time, data[i].gethastaKayitSaati ()))
	    {
	      insert (data[i]);
	    }
	}
      if (same (beklemeSuresi, time))
	{
	 // cout << "Muayene bitti // Time : " << time << endl;
	  muayeneBosMu = true;
	}
      if (muayeneBosMu)
	{
	  Hasta *temp = getMax ();
	  temp->setmuayeneSaati (time);
	  double sure = (double) temp->getmuayeneSuresi () / 100;

	  beklemeSuresi = time + sure;
	  int tam = beklemeSuresi;
	  double noktali = beklemeSuresi - tam;
	  if (same (noktali, 0.60) || noktali > 0.60)
	    {
	      tam++;
	      noktali -= 0.60;
	    }
	  beklemeSuresi = (double) tam + noktali;
	  cout << sira << ". sirada " << temp->gethastaNo () << " Numarali "
	    << temp->gethastaAdi () << " adli hasta muayene olmustur.\n";
	  cout << "oncelikPuani:" << temp->getoncelikPuani () <<
	    " muayeneSuresi:" << temp->getmuayeneSuresi () <<
	    " muayene giris saati:" << temp->getmuayeneSaati () << endl;
	  sira++;
	  remove1 ();
	  muayeneBosMu = false;

	}

      incrTime (time);
    }

}
