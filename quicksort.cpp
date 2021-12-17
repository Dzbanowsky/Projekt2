#include <iostream>

#include <iomanip>

#include <cstdlib>

#include <time.h>

#include <chrono>

#include <string>

#include <fstream>
using namespace std;
using namespace chrono;



const int N = 20; // Liczebność zbioru.

int d[N];

void saveResultsToFile(string file_name, int tab[], int rozmiar) {
  fstream plik;
  plik.open(file_name + ".txt", ios:: in | ios::out); //otworzenie pliku
  if (plik.good() == true) {
    cout << "Po sortowaniu:\n\n";
    for (int i = 0; i < rozmiar; i++) {
      plik << tab[i] << endl; // wpisujemy posortowane dane do pliku
      cout << setw(4) << tab[i]; // wypisujemy posortowane dane
    }
    plik.close(); // zamknięcie pliku
  }
}
// Procedura sortowania szybkiego
//-------------------------------

void Sortuj_szybko(int lewy, int prawy) //funkcja do quicksorta
{
  int i, j, piwot; //deklaracja zmiennych

  i = (lewy + prawy) / 2;
  piwot = d[i];
  d[i] = d[prawy];
  for (j = i = lewy; i < prawy; i++)
    if (d[i] < piwot) //warunek do podmiany
  {
    swap(d[i], d[j]); //podmiana elementow
    j++;
  }
  d[prawy] = d[j];
  d[j] = piwot;
  if (lewy < j - 1) Sortuj_szybko(lewy, j - 1);
  if (j + 1 < prawy) Sortuj_szybko(j + 1, prawy);
}

// Program główny
//---------------

int main() {
  int i;
  auto start = high_resolution_clock::now();
  srand((unsigned) time(NULL));

  // Najpierw wypełniamy tablicę d[] liczbami pseudolosowymi
  // a następnie wyświetlamy jej zawartość

  for (i = 0; i < N; i++) d[i] = rand() % 100;
  for (i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

  // Sortujemy

  Sortuj_szybko(0, N - 1);

  // Wyświetlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for (i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

  saveResultsToFile("zapis", d, N);
  cout<<endl;

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast < microseconds > (stop - start);

  cout << "Czas w mikrosekundach: " << duration.count() << endl;

  return 0;
}
