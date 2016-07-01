/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to fit models to the reduced MC data.

*/

                                                                                    //
void fit_MC_norm(std::string input_file = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/reduced_Lb2JpsipK_MC_2011_2012_norm.root", std::string out_file_mass = "~/cern/plots/fitting/Lb2JpsipK_MC_2011_2012_cut_mass_fit_doublegauss.pdf"){
                                                                                    //
    gROOT->ProcessLine(".L ~/cern/project/lhcbStyle.C");
    lhcbStyle();

    const std::string filename(input_file.c_str());
    const std::string treename = "DecayTree";

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;
    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;


    // -- signal, mass shape
    RooRealVar Lambda_b0_DTF_MASS_constr1("Lambda_b0_DTF_MASS_constr1","m(J/#psi p K^{-})", 5550., 5700., "MeV/c^{2}"); 
    RooRealVar Jpsi_M("Jpsi_M","m(#mu#mu)", 3000., 3200., "MeV/c^{2}"); 
    //RooRealVar chi_c_M("chi_c_M","m(J/#psi#gamma)", 3350., 3750., "MeV/c^{2}"); 
    RooRealVar mean("mean","mean", 5620., 5595., 5650.);
    RooRealVar sigma1("sigma1","sigma1", 10., 1., 100.);
    RooRealVar sigma2("sigma2","sigma2", 100., 1., 1000.);
    RooRealVar alpha1("alpha1","alpha1", 1.0, 0.5, 5.0);
    RooRealVar n1("n1","n1", 1.8, 0.2, 15.0);
    RooRealVar alpha2("alpha2","alpha2", -0.5, -5.5, 0.0);
    RooRealVar n2("n2","n2", 0.7, 0.2, 10.0);
    //RooRealVar bkgcat_chic("bkgcat_chic","bkgcat_chic", 0, 100);

    Lambda_b0_DTF_MASS_constr1.setBins(75);

    RooGaussian gauss1("gauss1","gauss1", Lambda_b0_DTF_MASS_constr1, mean, sigma1);
    RooGaussian gauss2("gauss2","gauss2", Lambda_b0_DTF_MASS_constr1, mean, sigma2);
    RooCBShape cb1("cb1","cb1", Lambda_b0_DTF_MASS_constr1, mean, sigma1, alpha1, n1); 
    RooCBShape cb2("cb2","cb2", Lambda_b0_DTF_MASS_constr1, mean, sigma2, alpha2, n2); 
    /*
    // the chi_c2 component
    RooRealVar mean3("mean3","mean3", 5570., 5520., 5580.);
    RooRealVar sigma3("sigma3","sigma3", 10., 1., 20.);
    RooGaussian gauss3("gauss3","gauss3", Lambda_b0_DTF_MASS_constr1, mean3, sigma3);
    */
    RooRealVar cbRatio("cbRatio","cbRatio", 0.8, 0.1, 1.0);
    RooRealVar frac2("frac2","frac2", 0.3, 0., 1.);
    
  

    /*
    alpha1.setVal( 2.1  );
    alpha2.setVal( -4.9 );
    n1.setVal( 3.2 );
    n2.setVal( 7.9 );
    cbRatio.setVal( 0.6808 );
    alpha1.setConstant( true );
    alpha2.setConstant( true );
    cbRatio.setConstant( true );
    n1.setConstant( true );
    n2.setConstant( true );
    */

    // -- add signal & bg
    //RooAddPdf pdf("pdf", "pdf", RooArgList(gauss1, gauss2), RooArgList( frac2 ));  
    RooAddPdf pdf("pdf", "pdf", RooArgList(cb1, cb2), RooArgList( cbRatio ));  

    
    RooArgSet obs;
    obs.add(Lambda_b0_DTF_MASS_constr1);
    obs.add(Jpsi_M);
    //obs.add(chi_c_M);
    //obs.add(bkgcat_chic);
    RooDataSet ds("ds","ds", obs, RooFit::Import(*tree)); 
 //RooFit::Cut("Lambda_b0_DTF_MASS_constr1 > 5580")
    RooPlot* plot = Lambda_b0_DTF_MASS_constr1.frame();

    plot->SetAxisRange(5550., 5700.);


    pdf.fitTo( ds );

    ds.plotOn( plot);
    pdf.plotOn( plot );
    //gauss3.plotOn( plot );



    RooPlot* plotPullMass = Lambda_b0_DTF_MASS_constr1.frame();

    plotPullMass->addPlotable( plot->pullHist() );
    //plotPullMass->SetMinimum();
    //plotPullMass->SetMaximum();
    plotPullMass->SetAxisRange(5550., 5700.);
    TCanvas* c = new TCanvas();
    c->cd();

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
    //pad2->SetBottomMargin(0.1);
    //pad2->SetTopMargin(0.0);

    pdf.plotOn( plot, RooFit::Components( cb1 ), RooFit::LineColor( kRed ), RooFit::LineStyle(kDashed) );
    pdf.plotOn( plot, RooFit::Components( cb2 ), RooFit::LineColor( kOrange ), RooFit::LineStyle(kDotted) );
    //pdf.plotOn( plot, RooFit::Components( bgPdf ), RooFit::LineColor( kBlue ), RooFit::LineStyle(kDashDotted) );

    pad1->cd();
    //pad1->SetLogy();
    plot->Draw();

    pad2->cd();
    plotPullMass->Draw("AP");

    c->SaveAs(out_file_mass.c_str());


}



