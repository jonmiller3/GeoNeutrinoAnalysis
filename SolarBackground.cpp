//
//  SolarBackground.cpp
//  GeoNuSim
//
//  Created by Jonathan Miller on 1/23/15.
//  Copyright (c) 2015 Jonathan Miller. All rights reserved.
//

#include "SolarBackground.h"
//modification

void SolarBackground::ReadInputFile(){
    

    string fname = Form("example_solar2.root");
    string treename = Form("T");
    string vname = Form("A");
    
    char* pPath;
    pPath = getenv ("HOME");
    std::string basename=Form("%s/Dropbox/Geo_neutrinos/",pPath);
    fname=basename+fname;
    
    TFile* file = new TFile(fname.c_str());
    
    TTree* tree=(TTree*)gDirectory->Get(treename.c_str());
    
    double* variable = new double[6];
    // I don't recall, do I use & here?
    tree->SetBranchAddress(vname.c_str(),&variable);
    
    int nentries = tree->GetEntries();
    
    for (int i=0; i<nentries; i++) {
        
        tree->GetEntry(i);
        
        double ve = variable[0];
        double vm = variable[1];
        double vt = variable[2];
        
        double vE = variable[3];
        double daybin = variable[4];
        double dir = variable[5];
        
        // now I can fill, right now
        // I ignore all information about
        // type/cross section
        
        // I am thinking now that I
        // handle the kinematic
        // and detector response
        // all later, so here I just
        // get the direction as recorded
        // and the energy as recorded
        // with maybe a modification
        // for neutrino-electron XS
        
        if (vE>10) {
            continue;
        }
        
        // I guess the XS information goes into the weight
        solarpdf->Fill(dir,vE);
        
    }
    
    // I think that is all I need to do
    // I don't need the Spec because I amnot
    // running this many times in parallel
    
    
    return;
    
}

SolarBackground::SolarBackground(){
    
    solarpdf = new TH2F("solarpdf","Solar PDF",100,0,TMath::Pi(),100,0,10);
    
    ReadInputFile();
    return;
    
}

double* SolarBackground::GetElectron(){
    
    double* res;
    
    double x;
    double y;
    
    solarpdf->GetRandom2(x, y);
    
    res={x,y};
    
    // this is not corrected for detector response/kinematics
    
    return res;
    
}