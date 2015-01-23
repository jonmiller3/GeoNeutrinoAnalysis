//
//  SolarBackground.h
//  GeoNuSim
//
//  Created by Jonathan Miller on 1/23/15.
//  Copyright (c) 2015 Jonathan Miller. All rights reserved.
//

#ifndef __GeoNuSim__SolarBackground__
#define __GeoNuSim__SolarBackground__

#include <stdio.h>

// this should do a couple of things
// read in the solar background into a PDF
// sample the PDF (getting a direction and an energy)
// I can correct for type using the electron-neutrino
// cross section

#include "TRandom3.h"
#include "TMath.h"
#include "TF2.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"

using namespace std;

class SolarBackground {
    //TF2* solarpdf;
    TH2F* solarpdf;
    
public:
    SolarBackground();
    void ReadInputFile();
    double* GetElectron();
    TH2F* GetPDF(){return solarpdf;}
    
};



#endif /* defined(__GeoNuSim__SolarBackground__) */
