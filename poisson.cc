#include<fstream>
#include<iostream>
#include<vector>
#include<cmath>

//using namespace std;

std::ifstream fin("datensumme.txt");
std::ofstream fout("hist.txt");
std::ofstream histpoi("histpoi.txt");
std::vector<int> nums(11);

double factorial(double i) {
  if (i <= 1)
    return 1.0;
  else
    return i*factorial(i-1);
}

double poisson(double mu, int k) {
  double d = std::pow(mu, k);
  d *= std::exp(-mu);
  d /= std::tgamma(k+1);//factorial(k);
  return d;
}

int main() {

  double mu = 3.11538;

  int num = 234;
  for (int i = 0; i < num; i++){
    int temp = 0;
    fin >> temp;
    nums[temp]++;
  }

  for (int i = 0; i < nums.size(); i++) {
    double poi = num * poisson(mu, i);
    //std::cout << "i:\t" << i << ":\t" << nums[i] << "\t" << poi << std::endl;
    fout << i << "\t" << nums[i] << std::endl;  
    histpoi << i << "\t" << nums[i] << "\t" << poi << std::endl;  
  }

  fout.close();
  fin.close();
  histpoi.close();
}