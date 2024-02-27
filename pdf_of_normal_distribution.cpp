#include <random>
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
  return 0;
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis(mu, sigma);

  std::vector<int> hist(nbins, 0);
  double bin_width = (xmax - xmin) / nbins;

  for (int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    if (r >= xmin && r <= xmax) {
      int bin_index = static_cast<int>((r - xmin) / bin_width);
      hist[bin_index]++;
    }
  }
  std::ofstream outfile("pdf_data.txt");
  for (int i = 0; i < nbins; ++i) {
    double bin_center = xmin + (i + 0.5) * bin_width;
    double bin_height = hist[i] / static_cast<double>(nsamples) / bin_width;
    outfile << bin_center << " " << bin_height << std::endl;
  }
  outfile.close();
}
