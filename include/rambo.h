#ifndef rambo_h
#define rambo_h

/* Random Momenta Beautifully Organised (RAMBO) is a Democratic Phase Space generator
*/

#include <iostream>
#include "TLorentzVector.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TPad.h"
#include "TVector3.h"
#include "TRandom2.h"
#include "TMath.h"
#include <vector>
#include <valarray>

class Rambo
{
    public:
        Rambo(int, TLorentzVector, std::vector<double>, int);
        ~Rambo();
        void Generate();
        TLorentzVector * GetDecay(int);
    protected:
        int num_daughter;
        double acceptance;
        TRandom2 rand;
        TLorentzVector m_parentMomenta;
        std::valarray<TLorentzVector> m_daughterMomenta_random;
        std::vector<TLorentzVector> m_daughterMomenta_massless;
        std::vector<TLorentzVector> m_daughterMomenta_massive; 
        std::vector<double> m_daughterMassContainer;
        double m_weightMassless;
        double m_weightMassive;
        void GenerateQ();
        void GenerateP();
        void GenerateMass();
        void CalculateWeightsMassless();
        void CalculateWeightsMassive();
        void CalculateAcceptance();
        void BoostDaughter();
        int fak_n(int num);

};
#endif

