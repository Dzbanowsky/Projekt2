#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <string>
#include <chrono>
#include<fstream>
using namespace std;
using namespace chrono;
const int N = 20; // Liczebność zbioru.

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
// Program główny
//---------------

int main() {
  auto start = high_resolution_clock::now();
  int d[N], i;

  // Najpierw wypełniamy tablicę d[] liczbami pseudolosowymi
  // a następnie wyświetlamy jej zawartość

  srand((unsigned) time(NULL));

  for (i = 0; i < N; i++) d[i] = rand() % 100;
  for (i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

  // Sortujemy

  i = 0;
  do {
    if (d[i] > d[i + 1]) // Porządek rosnący
    {
      swap(d[i], d[i + 1]);
      i = 0;
      continue;
    }
    i++;
  } while (i < N - 1);

  // Wyświetlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for (i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

  saveResultsToFile("zapis", d, N);
  cout << endl;

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast < microseconds > (stop - start);

  cout << "Czas w mikrosekundach: " << duration.count() << endl;
  return 0;
}
