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



void BDT_cuts_norm(){
    
    
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");
    //lhcbStyle();
    
    const std::string filename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/Lb2JpsipK_2011_2012_signal_withbdt.root");
    const std::string treename = "withbdt";
    
    const std::string filenameMC("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/Lb2JpsipK_MC_2011_2012_norm_withbdt.root");
    
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
    RooRealVar bdtg3("bdtg3", "bdtg3", -1.0, 1.0);
    RooRealVar frac2("frac2","frac2", 0.3, 0., 1.);
    
    RooGaussian gauss1("gauss1","gauss1", Lambda_b0_DTF_MASS_constr1, mean, sigma1);
    RooGaussian gauss2("gauss2","gauss2", Lambda_b0_DTF_MASS_constr1, mean, sigma2);
    RooCBShape cb1("cb1","cb1", Lambda_b0_DTF_MASS_constr1, mean, sigma1, alpha1, n1); 
    RooCBShape cb2("cb2","cb2", Lambda_b0_DTF_MASS_constr1, mean, sigma2, alpha2, n2); 
    RooAddPdf sig("sig", "sig", RooArgList(cb1, cb2), RooArgList( frac2 ));
    RooRealVar cbRatio("cbRatio","cb Ratio", 0.8, 0.1, 1.0);
    RooRealVar sigYield("sigYield","sig Yield", 4e2, 1e1, 1e4);
    RooRealVar bgYield("bgYield","bg Yield", 1e4, 1e1, 1e5);
    
    
    
    //put in values from fit_MC here <<--- DON'T FORGET TO CHANGE THESE IF THE FIT CHANGES!!!
    /*
    EXT PARAMETER                                INTERNAL      INTERNAL
  NO.   NAME      VALUE            ERROR       STEP SIZE       VALUE
   1  alpha1       1.74154e+00   3.36750e-02   1.24897e-04  -4.64754e-01
   2  alpha2      -2.02379e+00   6.38694e-02   1.18078e-04   2.87434e+00
   3  cbRatio      3.81630e-01   2.53217e-02   1.04396e-03  -3.83487e-01
   4  mean         5.61983e+03   1.06900e-02   5.57074e-05  -9.73350e-02
   5  n1           3.61886e+00   1.29299e-01   2.50836e-04  -5.68053e-01
   6  n2           3.28978e+00   1.59452e-01   3.00100e-04  -3.78398e-01
   7  sigma1       7.37006e+00   1.49989e-01   2.60360e-05  -1.05787e+00
   8  sigma2       4.90330e+00   4.88847e-02   5.78092e-06  -1.44570e+00
    */
    alpha1.setVal( 1.74154e+00 );
    alpha2.setVal( -2.02379e+00 );
    n1.setVal( 3.61886e+00 );
    n2.setVal( 3.28978e+00 );
    frac2.setVal( 3.81630e-01 );
    sigma1.setVal( 7.37006e+00 );
    sigma2.setVal( 4.90330e+00 );
    
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
    //RooAddPdf bg("bg","bg", RooArgList(comb), RooArgList(frac3));
    
    // -- add signal & bg
    RooAddPdf pdf("pdf", "pdf", RooArgList(sig, comb), RooArgList( sigYield, bgYield));  
    
    
    double efficiencies1[40];
    double efficiencies1_error[40];
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
        c << "bdtg3" << " >= " << cut_val;
        const std::string cut = c.str();
        
        //std::cout << cut;
    /*
        RooArgSet obs;
        obs.add(Lambda_b0_DTF_MASS_constr1);
        //obs.add(chi_c_Mp);
        //obs.add(mass_pK);
        obs.add(Jpsi_M);
        obs.add(chi_c_M);
        obs.add(bdtg); 
    
        RooDataSet ds("ds","ds", obs, RooFit::Import(*tree), RooFit::Cut(cut.c_str())); 
    
        RooPlot* plot = Lambda_b0_DTF_MASS_constr1.frame();
    
        RooFitResult * result = pdf.fitTo( ds, RooFit::Extended() );
        
        double sig_val = sigYield.getVal();
        double bg_val = bgYield.getVal();
        double sig_error = sigYield.getError();
        double bg_error = bgYield.getError();
        
        double efficiency1 = (sig_val)/(sqrt(sig_val + bg_val));
        efficiencies1[i] = efficiency1;
        
        double efficiency1_error_sq = (pow(sig_error,2)/(sig_val+bg_val) + (pow(sig_val,2)*(pow(sig_error,2)+pow(bg_error,2))/(4*pow((sig_val+bg_val),3))));
        
        double efficiency1_error = sqrt(efficiency1_error_sq);
        efficiencies1_error[i] = efficiency1_error;
        */
        
        double MC_post = treeMC->GetEntries(cut.c_str());
        
        double eff_val = MC_post/MC_pre; 
        
        //something here to get the sideband background count
         
        /*
        Lambda_b0_DTF_MASS_constr1.setRange("R", 5650., 5700.);
        RooFitResult * sideband = bg.fitTo( ds, RooFit::Range("R") );
        sideband->Print();
        */
        Lambda_b0_DTF_MASS_constr1.setRange("R", 5650., 5700.);
        RooAbsReal* integral = pdf.createIntegral(Lambda_b0_DTF_MASS_constr1, RooFit::Range("R"));
        //std::cout << integral->getVal() << std::endl;
        //std::cout << integral->getError() << std::endl;
        //Double_t sideband_bg_val = integral->getVal();
        //double sideband_bg_error = integral->getError();
        
        std::stringstream r;
        r << "bdtg3" << " >= " << cut_val << " && Lambda_b0_DTF_MASS_constr1 >= 5650 && Lambda_b0_DTF_MASS_constr1 <= 5700";
        const std::string cut2 = r.str();
        
        double integ = tree->GetEntries(cut2.c_str());
        //double integ = integral->getVal();

        double efficiency2 = eff_val/(5./2. + sqrt(integ));
        efficiencies2[i] = efficiency2;
        
        effvals[i]=eff_val;
        
        
        std::cout << "\n" << integ << std::endl;
        std::cout << "\n" << eff_val << std::endl;
        std::cout << "\n" << efficiency2 << std::endl;
        
        
        //double efficiency2_error = efficiency2*sqrt(pow(eff_error/eff_val,2)+(1/(4*sideband_bg_val))*pow(sideband_bg_error/(5/2+sideband_bg_val),2));
        
        //std::cout << "\n\n" << "BDT cut value = " << cut_val << "\n" ;
        //std::cout << "S = " << sig_val << " +/- " << sig_error << "\n" ;
        //std::cout << "B = " << bg_val << " +/- " << bg_error << "\n" ;
        //std::cout << "S/sqrt(S+B) = " << efficiency << " +/- " << efficiency_error << "\n\n" ;
        
        //ds.plotOn( plot );
        //pdf.plotOn( plot );
    
        //RooPlot* plotPullMass = mass.frame();
    
        //plotPullMass->addPlotable( plot->pullHist() );
        //plotPullMass->SetMinimum();
        //plotPullMass->SetMaximum();
        
        //std::cout << cut_val;
    }
    
    
    //TCanvas *c1 = new TCanvas(); 
    
    //double zeros[20];
    //for (i=0, i<20, i++) zeros[i]=0.0;
    
    //TGraphErrors* graph = new TGraphErrors(40, bdt_cuts, efficiencies1, 0, efficiencies1_error);
    
    //graph->SetTitle("S/sqrt(S+B) vs BDTG cut");
    //graph->SetMarkerColor(4);
    //graph->SetMarkerStyle(20);
    //graph->SetMarkerSize(1.0);
    //graph->GetXaxis()->SetTitle("BDTG cut (>)");
    //graph->GetXaxis()->SetRangeUser(-1.0,1.0);
    //graph->GetYaxis()->SetTitle("S/sqrt(S+B)");
    //graph->Fit("pol5"); 
    //graph->Draw("AP");
    //c1->SaveAs("~/cern/plots/bdt_cuts/Lb2chicpK_2011_2012_BDTG_cuts_S_sqrtS+B.png");
    //return c1;
    
    //gStyle->SetOptFit(1011);
    TCanvas *c2 = new TCanvas();
    
    TGraph* graph2 = new TGraph(40, bdt_cuts, efficiencies2);
    
    graph2->SetTitle("eff/[5/2+sqrt(B)] vs BDTG3 cut");
    graph2->SetMarkerColor(4);
    graph2->SetMarkerStyle(20);
    graph2->SetMarkerSize(1.0);
    graph2->GetXaxis()->SetTitle("BDTG3 cut (>)");
    graph2->GetXaxis()->SetRangeUser(-1.0,1.0);
    graph2->GetYaxis()->SetTitle("eff/[5/2+sqrt(B)]");
    //graph2->Fit("pol7"); 
    graph2->Draw("AP");
    c2->SaveAs("~/cern/plots/bdt_cuts_norm/Lb2JpsipK_2011_2012_BDTG3_cuts_Punzi.png");
    //return c2;
    
    
    
    
    /*
    TCanvas* c = new TCanvas();
    
    TPad* pad1 = new TPad("pad1","pad1", 0, 0.3, 1, 1.0);
    pad1->SetBottomMargin(0.1);
    pad1->SetTopMargin(0.1);
    pad1->Draw();
    c->cd();
    TPad* pad2 = new TPad("pad2","pad2", 0, 0, 1, 0.3);
    pad2->SetBottomMargin(0.1);
    pad2->SetTopMargin(0.0);
    pad2->Draw();
    
    
    //pdf.plotOn( plot, RooFit::Components( DfbPdf ), RooFit::LineColor( kRed ), RooFit::LineStyle(kDashed) );
    //pdf.plotOn( plot, RooFit::Components( promptPdf ), RooFit::LineColor( kBlue ), RooFit::LineStyle(kDotted) );
    //pdf.plotOn( plot, RooFit::Components( bgPdf ), RooFit::LineColor( kOrange ), RooFit::LineStyle(kDashDotted) );
    
    pad1->cd();
    plot->Draw();
    
    pad2->cd();
    plotPullMass->Draw("AP");
    
    c->SaveAs(out_file_mass);
    
    RooStats::SPlot* sData = new RooStats::SPlot("sData","An SPlot",
            ds, &pdf, RooArgList(sigYield, bgYield) );
    
    
    RooDataSet * dataw_z = new RooDataSet(ds.GetName(),ds.GetTitle(),&ds,*(ds.get()),0,"sigYield_sw") ;
    */
    /*   
    TCanvas* d = new TCanvas();
    RooPlot* w_mass_chicp = mass_chicp.frame();
    dataw_z->plotOn(w_mass_chicp, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_chicp->Draw();
    d->SaveAs("m_chicp_sweighted.png");
    
    TCanvas* e = new TCanvas();
    RooPlot* w_mass_pK = mass_pK.frame();
    dataw_z->plotOn(w_mass_pK, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_pK->Draw();
    e->SaveAs("m_pK_sweighted.png");
    */
    /*
    TCanvas* f = new TCanvas();
    RooPlot* w_mass_Jpsi = mass_Jpsi.frame();
    dataw_z->plotOn(w_mass_Jpsi, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_Jpsi->Draw();
    f->SaveAs("m_Jpsi_sweighted.png");
    
    TCanvas* g = new TCanvas();
    RooPlot* w_mass_Chic = mass_Chic.frame();
    dataw_z->plotOn(w_mass_Chic, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_Chic->Draw();
    g->SaveAs("m_Chic_sweighted.png");
    */
    
    
}












