#include <math.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

double microtime(){
  struct timeval time;
  if (gettimeofday(&time, NULL)){
    //  Handle error
    return 0;
  }
  return (double) time.tv_sec + (double) time.tv_usec * .000001;
}

int main(int argc, char *argv[]) {
  double waktuMula, waktuTamat, waktuProses;
  unsigned int range, i, pembagi;
  unsigned short int jumlahPrima, jumlahFaktor;

  waktuMula = microtime();

  if (argc >= 2) range = std::stol(argv[1]); else range = 100000;
  jumlahPrima = 0;

  for (i = 0; i <= range; i++) {
    jumlahFaktor = 0;
    pembagi = 1;
    while (pembagi <= i) {
      if ((i % pembagi) == 0) {
        jumlahFaktor++; // $i habis dibagi $pembagi.
      };
      pembagi++;
    };
    if (jumlahFaktor == 2) {
      // echo "$i\t";
      jumlahPrima++;
    };
  };

  waktuTamat = microtime();
  waktuProses = (waktuTamat - waktuMula);

  cout << "Ada " << jumlahPrima << " bilangan prima antara 0 sampai ";
  cout << range << ". Waktu proses = " << waktuProses << " detik.\n\n";
}