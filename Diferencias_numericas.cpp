#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

float sum1(int N);
float sum2(int N);

int main(int argc, char **argv){
  std::ofstream fout;
  fout.precision(16); 
  fout.setf(std::ios::scientific);
  fout.open("datos1.txt");
  for (int N = 1; N <= 1000000; ++N){
    float S1 = sum1(N);
    float S2 = sum2(N);
    float Delta = 1-(S1/S2);
    fout << N << "\t"<< S1 << "\t"<< S2 << "\t"<< std::fabs(Delta) << "\n";
  }
  fout.close();

  return 0;
}

float sum1(int N){
  float sum1 = 0.0;
  for (int k = 1; k <= N; ++k){
    sum1 += 1.0/k;
  }
    return sum1;
}

float sum2(int N){
  float sum2 = 0.0;
  for (int k = N; k >= 1; --k){
    sum2 += 1.0/k;
  }
    return sum2;
}