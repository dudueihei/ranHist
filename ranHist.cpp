#include <iostream>
#include <TRandom3.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>

int main() {
  TFile* rootFile = new TFile("output.root", "RECREATE");

  TTree* tree = new TTree("randomData", "Random Number Data");

  double randomNumber;
  tree->Branch("randomNumber", &randomNumber, "randomNumber/D");

  TH1F* histogram = new TH1F("histogram", "Random Number Histogram", 100, 0, 1);

  TRandom3* randomGenerator = new TRandom3();

  for (int i = 0; i < 10000; ++i) {
    randomNumber = randomGenerator->Rndm();
    tree->Fill();
    histogram->Fill(randomNumber);
  }

  rootFile->Write();

  rootFile->Close();

  std::cout << "Data saved to output.root" << std::endl;

  return 0;
}
