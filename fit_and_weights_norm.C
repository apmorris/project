/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to fit models to the data.


*/

//#include "RooStudentT.h"

void fit_and_weights_norm(){

    gROOT->ProcessLine(".L ~/cern/project/lhcbStyle.C");
    lhcbStyle();
    /*gStyle->SetLabelSize(0.05,"x");
    gStyle->SetLabelSize(0.05,"y");
    gStyle->SetTitleSize(0.05,"x");
    gStyle->SetPaperSize(20,26);
    gStyle->SetPadTopMargin(0.0);
    gStyle->SetPadRightMargin(0.05); // increase for colz plots
    gStyle->SetPadBottomMargin(0.0);
    gStyle->SetPadLeftMargin(0.14);
    gStyle->SetTitleH(0.01);*/
                                                                                    //
    const std::string filename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/Lb2JpsipK_2011_2012_signal_withbdt.root");           
    const std::string treename = "withbdt";                                         
    const std::string out_file_mass("~/cern/plots/fitting/Lb2JpsipK_2011_2012_mass_fit_after_bdtg3_cut_-055.pdf");                                   
                                                                                    //

    const std::string cuts("bdtg3>=-0.55");    
    
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;
    
    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;

    TTree* rTree1 = tree->CopyTree( cuts.c_str() );

    // -- signal, mass shape
    RooRealVar Lambda_b0_DTF_MASS_constr1("Lambda_b0_DTF_MASS_constr1","m(J/#psi p K^{-})", 5550., 5700., "MeV/c^{2}"); 
    RooRealVar Jpsi_M("Jpsi_M","m(#mu#mu)", 3000., 3200., "MeV/c^{2}"); 
    //RooRealVar chi_c_M("chi_c_M","m(J/#psi#gamma)", 3400., 3700., "MeV/c^{2}"); 
    RooRealVar mean("mean","mean", 5620., 5600., 5650.);
    RooRealVar sigma1("sigma1","sigma1", 10., 1., 100.);
    RooRealVar sigma2("sigma2","sigma2", 5.0, 1.0, 300.0);
    RooRealVar sigmaT("sigmaT", "sigmaT", 1.9, 1., 100.);
    RooRealVar alpha1("alpha1","alpha1", 1.0, 0.5, 5.0);
    RooRealVar n1("n1","n1", 1.5, 0.2, 15.0);
    RooRealVar alpha2("alpha2","alpha2", -0.5, -5.5, 0.0);
    RooRealVar n2("n2","n2", 1.5, 0.2, 10.0);
    RooRealVar nu("nu", "nu", 2., 0.7, 100.);
    //RooRealVar bkgcat_chic("bkgcat_chic","bkgcat_chic", 0, 100);
    RooRealVar bdtg3("bdtg3", "bdtg3", -1.0, 1.0);                                    //
    RooRealVar frac2("frac2","frac2", 0.3, 0., 1.);
    
    Lambda_b0_DTF_MASS_constr1.setBins(75);
    
    
    
    
    RooGaussian gauss1("gauss1","gauss1", Lambda_b0_DTF_MASS_constr1, mean, sigma1);
    RooGaussian gauss2("gauss2","gauss2", Lambda_b0_DTF_MASS_constr1, mean, sigma2);
    RooCBShape cb1("cb1","cb1", Lambda_b0_DTF_MASS_constr1, mean, sigma1, alpha1, n1); 
    RooCBShape cb2("cb2","cb2", Lambda_b0_DTF_MASS_constr1, mean, sigma2, alpha2, n2);
    
    //RooStudentT * student = new RooStudentT("student", "student", Lambda_b0_DTF_MASS_constr1, mean, sigmaT, nu);
     
    RooAddPdf sig("sig", "sig", RooArgList(cb1, cb2), RooArgList( frac2 ));
    RooRealVar cbRatio("cbRatio","cb Ratio", 0.3, 0.1, 1.0);
    RooRealVar sigYield("sigYield","sig Yield", 4e2, 1e1, 1e5);
    RooRealVar bgYield("bgYield","bg Yield", 1e2, 1e0, 5e5);

    //put in values from fit_MC here <<--- DON'T FORGET TO CHANGE THESE IF THE FIT CHANGES!!!
    /*
    EXT PARAMETER                                INTERNAL      INTERNAL
  NO.   NAME      VALUE            ERROR       STEP SIZE       VALUE
   1  alpha1       2.18020e+00   2.85078e-02   1.38432e-04  -2.56034e-01
   2  alpha2      -2.79102e+00   6.74385e-02   1.51818e-04  -1.49177e-02
   3  cbRatio      3.07172e-01   1.49204e-02   1.72642e-04  -5.69984e-01
   4  mean         5.61985e+03   9.58397e-03   5.56682e-05  -9.66293e-02
   5  n1           1.49358e+00   8.14447e-02   2.09300e-04  -9.70542e-01
   6  n2           1.45276e+00   1.09864e-01   2.59028e-04  -8.39538e-01
   7  sigma1       8.46303e+00   1.32851e-01   2.86985e-05  -1.01453e+00
   8  sigma2       4.93976e+00   3.42842e-02   5.03572e-06  -1.44512e+00
   
   
   
   
   4  mean         5.62097e+03   4.02152e-02   6.00497e-04   3.08772e-01
   5  sigYield     3.52933e+04   2.55400e+02   1.54032e-03  -1.69958e-02
   6  sigma1       1.22322e+01   1.10970e+00   2.87462e-03   1.63838e-01
   7  sigma2       5.54047e+00   1.41829e-01   1.08300e-03  -1.28653e-01
    */
    
   mean.setVal(5.62097e+03);
   sigma1.setVal(1.22322e+01);
   sigma2.setVal(5.54047e+00);
   
   mean.setConstant(true);
   sigma1.setConstant(true);
   sigma2.setConstant(true);
    
    
    
    //alpha1.setVal( 2.18020e+00 );
    //alpha2.setVal( -2.79102e+00 );
    //n1.setVal( 1.49358e+00 );
    //n2.setVal( 1.45276e+00 );
    //frac2.setVal( 3.81630e-01 );
    //sigma1.setVal( 7.37006e+00 );
    //sigma2.setVal( 4.90330e+00 );
    
    //double gauss
    //alpha1.setVal( 2.18020e+00 );
    //alpha2.setVal( -2.79102e+00 );
    //n1.setVal( 1.49358e+00 );
    //n2.setVal( 1.45276e+00 );
    
    
    //alpha1.setConstant( true );
    //alpha2.setConstant( true );
    //frac2.setConstant( true );
    //n1.setConstant( true );
    //n2.setConstant( true );
    //sigma1.setConstant( true );
    //sigma2.setConstant( true );

    // -- bg, mass shape
    RooRealVar a1("a1","a1", -0.1, -0.5, 0.5);
    RooExponential exp("exp", "exp", Lambda_b0_DTF_MASS_constr1, a1);
    RooChebychev comb("comb","comb", Lambda_b0_DTF_MASS_constr1, a1);
    RooRealVar mean3("mean3","mean3", 5560., 5500., 5600.);
    RooRealVar sigma3("sigma3","sigma3", 5., 1., 100.);
    RooRealVar frac3("frac3","frac", 0.2, 0.0, 0.3);
    RooGaussian gauss3("gauss3","gauss3", Lambda_b0_DTF_MASS_constr1, mean3, sigma3);
    //RooAddPdf bg("bg","bg", RooArgList(gauss3, comb), RooArgList(frac3));

    // -- add signal & bg
    RooAddPdf pdf("pdf", "pdf", RooArgList(sig, comb), RooArgList( sigYield, bgYield));  

    RooArgSet obs;
    obs.add(Lambda_b0_DTF_MASS_constr1);
    obs.add(Jpsi_M);
    //obs.add(chi_c_M);
    //obs.add(proton_ProbNNp);
    //obs.add(proton_ProbNNk);
    //obs.add(kaon_ProbNNp);
    //obs.add(kaon_ProbNNk);

    
    RooDataSet ds("ds","ds", obs, RooFit::Import(*rTree1)); 

    RooPlot* plot = Lambda_b0_DTF_MASS_constr1.frame();

    RooFitResult * result = pdf.fitTo( ds, RooFit::Extended() );
    ds.plotOn( plot );
    pdf.plotOn( plot );
    
    RooPlot* plotPullMass = Lambda_b0_DTF_MASS_constr1.frame();

    plotPullMass->addPlotable( plot->pullHist() );
    //plotPullMass->SetMinimum();
    //plotPullMass->SetMaximum();

    TCanvas* c = new TCanvas();

    TPad* pad1 = new TPad("pad1","pad1", 0, 0.3, 1, 0.95);
    //pad1->SetBottomMargin(0.1);
    //pad1->SetTopMargin(0.1);
    pad1->Draw();
    
    //TPad* pad2 = new TPad("pad2","pad2", 0, 0.05, 1, 0.4);
    TPad* pad2 = new TPad("pad2","pad2", 0, 0.05, 1, 0.3);
    pad2->Draw();
    plotPullMass->GetXaxis()->SetLabelSize(0.1);
    plotPullMass->GetYaxis()->SetLabelSize(0.1);
    plotPullMass->GetXaxis()->SetTitleSize(0.1);
    plotPullMass->GetYaxis()->SetTitleSize(0.1);

    //pdf.plotOn( plot, RooFit::Components( sig ), RooFit::LineColor( kTeal ), RooFit::LineStyle(kDashed) );
    pdf.plotOn( plot, RooFit::Components( comb ), RooFit::LineColor( kOrange ), RooFit::LineStyle(kDashed) );
    //pdf.plotOn( plot, RooFit::Components( gauss3 ), RooFit::LineColor( kViolet ), RooFit::LineStyle(kDashed) );

    pad1->cd();
    plot->Draw();



    pad2->cd();
    plotPullMass->Draw("AP");

    c->SaveAs(out_file_mass.c_str());


    std::cout << rTree1->GetEntries() << " events with the following cut applied: " << cuts.c_str() << std::endl;

/*
    RooStats::SPlot* sData = new RooStats::SPlot("sData","An SPlot",
            ds, &pdf, RooArgList(sigYield, bgYield) );


    RooDataSet * dataw_z = new RooDataSet(ds.GetName(),ds.GetTitle(),&ds,*(ds.get()),0,"sigYield_sw") ;
    
    TTree *tree_data = (TTree*)dataw_z->tree();
    TFile * newfile = TFile::Open("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/weighted_data.root","RECREATE");
    tree_data->Write();
    newfile->Close();  
    */
     
 /* 
    TCanvas* d = new TCanvas();
    RooPlot* w_chi_c_Mp = chi_c_Mp.frame();
    dataw_z->plotOn(w_chi_c_Mp, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_chi_c_Mp->Draw();
    d->SaveAs("m_chicp_sweighted.png");
 
    TCanvas* e = new TCanvas();
    RooPlot* w_mass_pK = mass_pK.frame();
    dataw_z->plotOn(w_mass_pK, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_pK->Draw();
    e->SaveAs("m_pK_sweighted.png");
*/
/*
    TCanvas* f = new TCanvas();
    RooPlot* w_Jpsi_M = Jpsi_M.frame();
    dataw_z->plotOn(w_Jpsi_M, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_Jpsi_M->Draw();
    f->SaveAs("~/cern/plots/m_Jpsi_sweighted.png");

    TCanvas* g = new TCanvas();
    RooPlot* w_chi_c_M = chi_c_M.frame();
    dataw_z->plotOn(w_chi_c_M, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_chi_c_M->Draw();
    g->SaveAs("~/cern/plots/m_Chic_sweighted.png");
    */
}
