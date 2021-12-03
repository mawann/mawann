<?php 
// Program mencari bilangan prima.

$waktuMula = microtime(true);

$range = 100000;
$jumlahPrima = 0;
for ($i = 0; $i <= $range; $i++) {
  $jumlahFaktor = 0;
  $pembagi = 1;
  while ($pembagi <= $i) {
    if (($i % $pembagi) == 0) {
      $jumlahFaktor++; // $i habis dibagi $pembagi.
    };
    $pembagi++;
  };
  if ($jumlahFaktor == 2) {
    // echo "$i\t";
    $jumlahPrima++;
  };
};
$waktuTamat = microtime(true);
$waktuProses = ($waktuTamat - $waktuMula);
echo "Ada $jumlahPrima bilangan prima antara 0 sampai $range. Waktu proses = ";
echo number_format((float) $waktuProses, 10);
echo " detik.\n\n";