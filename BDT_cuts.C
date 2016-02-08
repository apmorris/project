/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to fit models to the data.

Script needs to go through different bdt cuts and record the S and B values to an 
array, errors too. Do this in a loop. Then needs to plot the value of S/sqrt(S+B) 
with errors versus bdt cut value. This outside the loop.



*/


#include <sstream>
//#include "NormalizedIntegral.h"



void BDT_cuts(){
    
    
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");
    //lhcbStyle();
    
    const std::string filename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/Lb2chicpK_2011_2012_signal_withbdt.root");                //
    const std::string treename = "withbdt";
    
    const std::string filenameMC("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/Lb2chicpK_MC_2011_2012_signal_withbdt.root");             //
    
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;
    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
    
    TFile* fileMC = TFile::Open( filenameMC.c_str() );
    if( !fileMC ) std::cout << "file " << filenameMC << " does not exist" << std::endl;
    TTree* treeMC = (TTree*)fileMC->Get( treename.c_str() );
    if( !treeMC ) std::cout << "tree " << treename << " does not exist" << std::endl;
    
    
    // -- signal, mass shape
    RooRealVar Lambda_b0_DTF_MASS_constr1("Lambda_b0_DTF_MASS_constr1","m(#chi_{c}pK^{-})", 5550., 5700., "MeV/c^{2}"); 
    RooRealVar Jpsi_M("Jpsi_M","m(#mu#mu)", 3000., 3200., "MeV/c^{2}"); 
    RooRealVar chi_c_M("chi_c_M","m(J/#psi#gamma)", 3400., 3700., "MeV/c^{2}"); 
    RooRealVar mean("mean","mean", 5630., 5610., 5650.);
    RooRealVar sigma1("sigma1","sigma1", 10., 1., 100.);
    RooRealVar sigma2("sigma2","sigma2", 30.0, 5.0, 300.0);
    RooRealVar alpha1("alpha1","alpha1", 1.0, 0.5, 5.0);
    RooRealVar n1("n1","n1", 1.8, 0.2, 15.0);
    RooRealVar alpha2("alpha2","alpha2", -0.5, -5.5, 0.0);
    RooRealVar n2("n2","n2", 0.7, 0.2, 10.0);
    //RooRealVar bkgcat_chic("bkgcat_chic","bkgcat_chic", 0, 100);
    RooRealVar bdtg("bdtg", "bdtg", -1.0, 1.0);                                     //
    RooRealVar frac2("frac2","frac2", 0.3, 0., 1.);
    
    RooGaussian gauss1("gauss1","gauss1", Lambda_b0_DTF_MASS_constr1, mean, sigma1);
    RooGaussian gauss2("gauss2","gauss2", Lambda_b0_DTF_MASS_constr1, mean, sigma2);
    RooCBShape cb1("cb1","cb1", Lambda_b0_DTF_MASS_constr1, mean, sigma1, alpha1, n1); 
    RooCBShape cb2("cb2","cb2", Lambda_b0_DTF_MASS_constr1, mean, sigma2, alpha2, n2); 
    RooAddPdf sig("sig", "sig", RooArgList(cb1, cb2), RooArgList( frac2 ));
    RooRealVar cbRatio("cbRatio","cb Ratio", 0.8, 0.1, 1.0);
    RooRealVar sigYield("sigYield","sig Yield", 4e2, 1e1, 1e4);
    RooRealVar bgYield("bgYield","bg Yield", 1e4, 1e1, 1e5);
    
    /*
    EXT PARAMETER                                INTERNAL      INTERNAL
  NO.   NAME      VALUE            ERROR       STEP SIZE       VALUE
   1  alpha1       1.95196e+00   5.61003e-02   2.56658e-03  -3.62575e-01
   2  alpha2      -1.97943e+00   4.74197e-02   2.83267e-03   2.84008e-01
   3  frac2        6.14816e-01   2.67461e-02   3.79093e-03   2.31700e-01
   4  mean         5.61971e+03   1.71676e-02   2.25218e-04  -1.01505e-01
   5  n1           2.34308e+00   9.38480e-02   2.67929e-03  -7.90059e-01
   6  n2           3.27041e+00   2.01566e-01   8.31475e-03  -3.82656e-01
   7  sigma1       3.84171e+00   5.81416e-02   4.35788e-04  -1.23031e+00
   8  sigma2       6.48664e+00   1.51833e-01   1.74564e-04  -1.42244e+00
    */
    
    //put in values from fit_MC here                                                //
                                                                                    //
    alpha1.setVal( 1.95196e+00 );                                                   //
    alpha2.setVal( -1.97943e+00  );                                                 //
    n1.setVal( 2.34308e+00 );                                                       //
    n2.setVal( 3.27041e+00 );                                                       //
    frac2.setVal( 6.14816e-01 );                                                    //
    sigma1.setVal( 3.84171e+00 );                                                   //
    sigma2.setVal( 6.48664e+00 );                                                   //
    
    alpha1.setConstant( true );
    alpha2.setConstant( true );
    frac2.setConstant( true );
    n1.setConstant( true );
    n2.setConstant( true );
    sigma1.setConstant( true );
    sigma2.setConstant( true );
    
    // -- bg, mass shape
    RooRealVar a1("a1","a1", -0.1, -0.5, 0.5);
    RooChebychev comb("comb","comb", Lambda_b0_DTF_MASS_constr1, a1);
    RooRealVar mean3("mean3","mean3", 5560., 5500., 5600.);
    RooRealVar sigma3("sigma3","sigma3", 5., 1., 10.);
    RooRealVar frac3("frac3","frac", 0.2, 0.0, 0.3);
    RooGaussian gauss3("gauss3","gauss3", Lambda_b0_DTF_MASS_constr1, mean3, sigma3);
    RooAddPdf bg("bg","bg", RooArgList(gauss3, comb), RooArgList(frac3));
    
    // -- add signal & bg
    RooAddPdf pdf("pdf", "pdf", RooArgList(sig, bg), RooArgList( sigYield, bgYield));  
    
    
    
    double bdt_cuts[40];
    double efficiencies2[40];
    double efficiencies2_error[40];
    double sideband_bg_val[40];
    
    double MC_pre = treeMC->GetEntries();
    
    double effvals[40];
    
    
    //loop starting here
    for(int i=0; i < 40; i=i+1) {
        double cut_val = -1.0 + i*0.05;
        //double cut_val = -1.0; // testing
        bdt_cuts[i] = cut_val;
        
        std::stringstream c;
        c << "bdtg" << " >= " << cut_val;
        const std::string cut = c.str();
        
        //std::cout << cut;
    
        Lambda_b0_DTF_MASS_constr1.setRange("R", 5650., 5700.);
        RooAbsReal* integral = pdf.createIntegral(Lambda_b0_DTF_MASS_constr1, RooFit::Range("R"));
        //std::cout << integral->getVal() << std::endl;
        //std::cout << integral->getError() << std::endl;
        
        
        std::stringstream r;
        r << "bdtg" << " >= " << cut_val << " && Lambda_b0_DTF_MASS_constr1 >= 5650 && Lambda_b0_DTF_MASS_constr1 <= 5700";
        const std::string cut2 = r.str();
        
        double integ = tree->GetEntries(cut2.c_str());
        //double integ = integral->getVal();

        double MC_post = treeMC->GetEntries(cut.c_str());

        double eff_val = MC_post/MC_pre;

        double efficiency2 = eff_val/(5./2. + sqrt(integ));
        efficiencies2[i] = efficiency2;
        
        effvals[i]=eff_val;
        
        
        std::cout << "\n" << integ << std::endl;
        std::cout << "\n" << eff_val << std::endl;
        std::cout << "\n" << efficiency2 << std::endl;
        
        
        //double efficiency2_error = efficiency2*sqrt(pow(eff_error/eff_val,2)+(1/(4*sideband_bg_val))*pow(sideband_bg_error/(5/2+sideband_bg_val),2));
        
        
    }
    
    

    
    //gStyle->SetOptFit(1011);
    TCanvas *c2 = new TCanvas();
    
    TGraph* graph2 = new TGraph(40, bdt_cuts, efficiencies2);
    
    graph2->SetTitle("eff/[5/2+sqrt(B)] vs BDTG cut");
    graph2->SetMarkerColor(4);
    graph2->SetMarkerStyle(20);
    graph2->SetMarkerSize(1.0);
    graph2->GetXaxis()->SetTitle("BDTG cut (>)");
    graph2->GetXaxis()->SetRangeUser(-1.0,1.0);
    graph2->GetYaxis()->SetTitle("eff/[5/2+sqrt(B)]");
    //graph2->Fit("pol7"); 
    graph2->Draw("AP");
    c2->SaveAs("~/cern/plots/bdt_cuts/Lb2chicpK_2011_2012_BDTG_cuts_Punzi.png");
    //return c2;
    
    
  
    
    
}












