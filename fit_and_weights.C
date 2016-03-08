/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to fit models to the data.


*/

//#include "RooStudentT.h"

void fit_and_weights(){

    gROOT->ProcessLine(".L ~/cern/project/lhcbStyle.C");
    //gROOT->ProcessLine(".L ~/cern/project/RooStudentT.h");
    //gROOT->ProcessLine(".L ~/cern/project/RooStudentT.cxx++");
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
    const std::string filename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/reduced_Lb2chicpK_2011_2012_signal.root");           
    const std::string treename = "DecayTree";                                         
    const std::string out_file_mass("~/cern/plots/fitting/Lb2chicpK_2011_2012_mass_fit_before_bdt.pdf");                                   
                                                                                    //

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;
    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;



    // -- signal, mass shape
    RooRealVar Lambda_b0_DTF_MASS_constr1("Lambda_b0_DTF_MASS_constr1","m(#chi_{c1}pK^{-})", 5550., 5700., "MeV/c^{2}");
    //RooRealVar Lambda_b0_DTF_MASS_constr2("Lambda_b0_DTF_MASS_constr2","m(#chi_{c}pK^{-})", 5550., 5700., "MeV/c^{2}"); 
    RooRealVar Jpsi_M("Jpsi_M","m(#mu#mu)", 3000., 3200., "MeV/c^{2}"); 
    RooRealVar chi_c_M("chi_c_M","m(J/#psi#gamma)", 3400., 3700., "MeV/c^{2}"); 
    RooRealVar mean("mean","mean", 5630., 5610., 5650.);
    RooRealVar sigma1("sigma1","sigma1", 10., 1., 100.);
    RooRealVar sigma2("sigma2","sigma2", 30.0, 5.0, 300.0);
    RooRealVar sigmaT("sigmaT", "sigmaT", 1.9, 1., 100.);
    RooRealVar alpha1("alpha1","alpha1", 1.0, 0.5, 5.0);
    RooRealVar n1("n1","n1", 1.8, 0.2, 20.0);
    RooRealVar alpha2("alpha2","alpha2", -0.5, -5.5, 0.0);
    RooRealVar n2("n2","n2", 0.7, 0.2, 10.0);
    RooRealVar nu("nu", "nu", 2., 0.7, 100.);
    //RooRealVar bkgcat_chic("bkgcat_chic","bkgcat_chic", 0, 100);
    RooRealVar bdtg("bdtg", "bdtg", -1.0, 1.0);                                    //
    RooRealVar frac2("frac2","frac2", 0.3, 0., 1.);
    
    Lambda_b0_DTF_MASS_constr1.setBins(75);
    //Lambda_b0_DTF_MASS_constr2.setBins(75);
    
    RooRealVar proton_ProbNNp("proton_ProbNNp","proton_ProbNNp",0.0,1.0);
    RooRealVar proton_ProbNNk("proton_ProbNNk","proton_ProbNNk",0.0,1.0);
    RooRealVar kaon_ProbNNp("kaon_ProbNNp","kaon_ProbNNp",0.0,1.0);
    RooRealVar kaon_ProbNNk("kaon_ProbNNk","kaon_ProbNNk",0.0,1.0);
    
    
    
    
    RooRealVar chi_c_PE("chi_c_PE","chi_c_PE", 0., 350e3);      
    RooRealVar chi_c_PX("chi_c_PX","chi_c_PX", -3e4, 3e4);
    RooRealVar chi_c_PY("chi_c_PY","chi_c_PY", -3e4, 3e4);
    RooRealVar chi_c_PZ("chi_c_PZ","chi_c_PZ", 0., 350e3);
    RooRealVar kaon_PE("kaon_PE","kaon_PE", 0., 140e3);
    RooRealVar kaon_PX("kaon_PX","kaon_PX", -7e3, 9e3);
    RooRealVar kaon_PY("kaon_PY","kaon_PY", -6e3, 6e3);
    RooRealVar kaon_PZ("kaon_PZ","kaon_PZ", 0., 130e3);
    RooRealVar proton_PE("proton_PE","proton_PE", 0., 160e3);
    RooRealVar proton_PX("proton_PX","proton_PX", -12e3, 10e3);
    RooRealVar proton_PY("proton_PY","proton_PY", -8e3, 8e3);
    RooRealVar proton_PZ("proton_PZ","proton_PZ", 0., 160e3);
    
    //in bdt
    RooRealVar kaon_TRACK_GhostProb("kaon_TRACK_GhostProb","kaon_TRACK_GhostProb", 0., 0.3);
    RooRealVar proton_TRACK_GhostProb("proton_TRACK_GhostProb","proton_TRACK_GhostProb", 0., 0.3);
    RooRealVar muminus_TRACK_GhostProb("muminus_TRACK_GhostProb","muminus_TRACK_GhostProb", 0., 0.3);
    RooRealVar muplus_TRACK_GhostProb("muplus_TRACK_GhostProb","muplus_TRACK_GhostProb", 0., 0.3);
    
    //in bdt
    RooRealVar Lambda_b0_DTF_CHI2NDOF("Lambda_b0_DTF_CHI2NDOF","Lambda_b0_DTF_CHI2NDOF",0.,7.);
    RooRealVar Lambda_b0_IPCHI2_OWNPV("Lambda_b0_IPCHI2_OWNPV","Lambda_b0_IPCHI2_OWNPV",0.,25.);
    RooRealVar Lambda_b0_FDS("Lambda_b0_FDS","Lambda_b0_FDS",0.,400.);
    RooRealVar Lambda_b0_PT("Lambda_b0_PT","Lambda_b0_PT",0.,50000.);
    RooRealVar kaon_PT("kaon_PT","kaon_PT",0.,12000.);
    RooRealVar kaon_IPCHI2_OWNPV("kaon_IPCHI2_OWNPV","kaon_IPCHI2_OWNPV",0.,22500.);
    RooRealVar proton_PT("proton_PT","proton_PT",0.,12000.);
    RooRealVar proton_IPCHI2_OWNPV("proton_IPCHI2_OWNPV","proton_IPCHI2_OWNPV",0.,22000.);
    RooRealVar gamma_CL("gamma_CL","gamma_CL",0.,1.);
    RooRealVar gamma_PT("gamma_PT","gamma_PT",0., 9000.);
    RooRealVar muplus_ProbNNmu("muplus_ProbNNmu","muplus_ProbNNmu",0.,1.);
    RooRealVar muminus_ProbNNmu("muminus_ProbNNmu","muminus_ProbNNmu",0.,1.);

    //only in preselection
    RooRealVar chi_c_M("chi_c_M","chi_c_M",3400.,3700.);
    
    
    RooGaussian gauss1("gauss1","gauss1", Lambda_b0_DTF_MASS_constr1, mean, sigma1);
    RooGaussian gauss2("gauss2","gauss2", Lambda_b0_DTF_MASS_constr1, mean, sigma2);
    RooCBShape cb1("cb1","cb1", Lambda_b0_DTF_MASS_constr1, mean, sigma1, alpha1, n1); 
    RooCBShape cb2("cb2","cb2", Lambda_b0_DTF_MASS_constr1, mean, sigma2, alpha2, n2); 
    
    //RooStudentT * student = new RooStudentT("student", "student", Lambda_b0_DTF_MASS_constr1, mean, sigmaT, nu);
     
    RooAddPdf sig("sig", "sig", RooArgList(cb1, cb2), RooArgList( frac2 ));
    RooRealVar cbRatio("cbRatio","cb Ratio", 0.8, 0.1, 1.0);
    RooRealVar sigYield("sigYield","sig Yield", 4e2, 0., 1e4);
    RooRealVar bgYield("bgYield","bg Yield", 1e2, 0., 5e5);

    /*8/2/16
    EXT PARAMETER                                INTERNAL      INTERNAL
  NO.   NAME      VALUE            ERROR       STEP SIZE       VALUE
   1  alpha1       2.50957e+00   5.68360e-02   2.65700e-03  -1.07061e-01
   2  alpha2      -2.28664e+00   5.52765e-02   3.09340e-03  -6.11388e+00
   3  frac2        6.51083e-01   2.02553e-02   3.33095e-03   3.06964e-01
   4  mean         5.61967e+03   1.61655e-02   2.24983e-04  -1.02914e-01
   5  n1           1.18728e+00   8.03720e-02   2.61213e-03  -1.04832e+00
   6  n2           1.97964e+00   1.78120e-01   7.39156e-03  -6.90351e-01
   7  sigma1       3.88071e+00   4.77592e-02   4.00488e-04  -1.22796e+00
   8  sigma2       7.03034e+00   1.36260e-01   1.79652e-04  -1.41525e+00
    */
    //put in values from fit_MC here                                                //
 
    alpha1.setVal( 2.50957e+00 );                                                   //
    alpha2.setVal( -2.28664e+00 );                                                 //
    n1.setVal( 1.18728e+00 );                                                       //
    n2.setVal( 1.97964e+00 );                                                       //
    frac2.setVal( 6.51083e-01 );                                                    //
    sigma1.setVal( 3.88071e+00 );                                                   //
    sigma2.setVal( 7.03034e+00 );                                                   //
                                                                                    
    alpha1.setConstant( true );
    alpha2.setConstant( true );
    frac2.setConstant( true );
    n1.setConstant( true );
    n2.setConstant( true );
    sigma1.setConstant( true );
    sigma2.setConstant( true );
    
/*//double gauss
    frac2.setVal( 9.48776e-01 );
    sigma1.setVal( 4.78033e+00 );
    sigma2.setVal( 1.94376e+01 );
    frac2.setConstant( true );
    sigma1.setConstant( true );
    sigma2.setConstant( true );
    */
    
    //student's t
    //sigmaT.setVal(4.17461e+00);
    //sigmaT.setConstant (true);
    
    // -- bg, mass shape
    RooRealVar a1("a1","a1", 0., -0.5, 0.5);
    RooChebychev comb("comb","comb", Lambda_b0_DTF_MASS_constr1, a1);
    RooRealVar mean3("mean3","mean3", 5560., 5500., 5600.);
    RooRealVar sigma3("sigma3","sigma3", 5., 1., 10.);
    RooRealVar frac3("frac3","frac", 0.2, -0.1, 0.3);
    RooGaussian gauss3("gauss3","gauss3", Lambda_b0_DTF_MASS_constr1, mean3, sigma3);
    RooAddPdf bg("bg","bg", RooArgList(gauss3, comb), RooArgList(frac3));

    // -- add signal & bg
    //RooAddPdf studentpdf("studentpdf", "studentpdf", RooArgList(student));
    RooAddPdf pdf("pdf", "pdf", RooArgList(sig ,bg), RooArgList(sigYield, bgYield));  

    RooArgSet obs;
    obs.add(Lambda_b0_DTF_MASS_constr1);
    obs.add(Jpsi_M);
    //setup RooRealVars for these!
    obs.add(chi_c_PE);      
    obs.add(chi_c_PX);
    obs.add(chi_c_PY);
    obs.add(chi_c_PZ);
    obs.add(kaon_PE);
    obs.add(kaon_PX);
    obs.add(kaon_PY);
    obs.add(kaon_PZ);
    obs.add(proton_PE);
    obs.add(proton_PX);
    obs.add(proton_PY);
    obs.add(proton_PZ);
    
    //inbdt
    obs.add(kaon_TRACK_GhostProb);
    obs.add(proton_TRACK_GhostProb);
    obs.add(muminus_TRACK_GhostProb);
    obs.add(muplus_TRACK_GhostProb);
    
    obs.add(Lambda_b0_DTF_CHI2NDOF);
    obs.add(Lambda_b0_IPCHI2_OWNPV);
    obs.add(Lambda_b0_FDS);
    obs.add(Lambda_b0_PT);
    obs.add(kaon_PT);
    obs.add(kaon_IPCHI2_OWNPV);
    obs.add(proton_PT);
    obs.add(proton_IPCHI2_OWNPV);
    obs.add(gamma_CL);
    obs.add(gamma_PT);
    obs.add(muplus_ProbNNmu);
    obs.add(muminus_ProbNNmu);

    //only in preselection
    obs.add(chi_c_M);
    
       
    obs.add(proton_ProbNNp);
    obs.add(proton_ProbNNk);
    obs.add(kaon_ProbNNp);
    obs.add(kaon_ProbNNk);

    
    RooDataSet ds("ds","ds", obs, RooFit::Import(*tree)); 

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

    pdf.plotOn( plot, RooFit::Components( sig ), RooFit::LineColor( kTeal ), RooFit::LineStyle(kDashed) );
    pdf.plotOn( plot, RooFit::Components( comb ), RooFit::LineColor( kOrange ), RooFit::LineStyle(kDashed) );
    pdf.plotOn( plot, RooFit::Components( gauss3 ), RooFit::LineColor( kViolet ), RooFit::LineStyle(kDashed) );
    //pdf.plotOn( plot, RooFit::Components( *student ), RooFit::LineColor( kTeal ), RooFit::LineStyle(kDashed) );

    pad1->cd();
    plot->Draw();



    pad2->cd();
    plotPullMass->Draw("AP");

    c->SaveAs(out_file_mass.c_str());

// this is the sweighting

    RooStats::SPlot* sData = new RooStats::SPlot("sData","An SPlot",
            ds, &pdf, RooArgList(sigYield, bgYield) );


    RooDataSet * dataw_z = new RooDataSet(ds.GetName(),ds.GetTitle(),&ds,*(ds.get()),0,"sigYield_sw") ;
    
    TTree *tree_data = (TTree*)dataw_z->tree();
    TFile * newfile = TFile::Open("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/reduced_Lb2chicpK_2011_2012_signal_weighted.root","RECREATE");
    tree_data->Write();
    newfile->Close();  
    
     
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
