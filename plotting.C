/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to plot two ntuples on top of each other.

*/



{

    // Import formatting template
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");
    lhcbStyle();
   

    // Definition of variables
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bd2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bs2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bu2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Lb2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bs2JpsiPhi_MC_2012_signal_withbdt.root";
    
    const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/reduced_Lb2JpsipK_2011_2012_signal.root";
    
    const std::string treename1 = "DecayTree";
    //const std::string filename2 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/Lb2chicpK_MC_2011_2012_signal_cut.root";
    //const std::string treename2 = "DecayTree";

    const std::string xaxis =     "#it{m(J/#psi pK^{-} )} [MeV/#it{c}^{2}]";
    const std::string yaxis =     "Candidates / 2MeV/#it{c}^{2} \n";
    const std::string varname =   "Lambda_b0_DTF_MASS_constr1";
    const std::string varhisto1 = "Lambda_b0_DTF_MASS_constr1>>h1";
    //const std::string varhisto2 = "Lambda_b0_DTF_MASS_constr1>>h2";

    const std::string outfile =   "/afs/cern.ch/user/a/apmorris/cern/plots/normalisation_samples/Lb2JpsipK_2011_2012_mass.png";  
  
    int bins = 75;
    float rangemin = 5550.;
    float rangemax = 5700.;



    // Opening files and trees
    TFile* f1 = TFile::Open( filename1.c_str() );
    if( !f1 ) std::cout << "file " << filename1 << " does not exist" << std::endl;

    TTree* t1 = (TTree*)f1.Get( treename1.c_str() );
    if( !t1 ) std::cout << "tree " << treename1 << " does not exist" << std::endl;

    //TFile* f2 = TFile::Open( filename2.c_str() );
    //if( !f2 ) std::cout << "file " << filename2 << " does not exist" << std::endl;

    //TTree* t2 = (TTree*)f2.Get( treename2.c_str() );
    //if( !t1 ) std::cout << "tree " << treename2 << " does not exist" << std::endl;


    // Need to scale the Monte Carlo data to the same number of entries as the data
    // So define two integers and scale accordingly later
    //int Nhisto1 = t1->GetEntries();
    //int Nhisto2 = t2->GetEntries();


    // Including the LHCb name, formatting
    lhcbName = new TPaveText(gStyle->GetPadLeftMargin() + 0.6,
            0.87 - gStyle->GetPadTopMargin(),
            gStyle->GetPadLeftMargin() + 0.7,
            0.95 - gStyle->GetPadTopMargin(),
            "BRNDC");
    lhcbName->AddText("LHCb");
    lhcbName->SetFillColor(0);
    lhcbName->SetTextAlign(12);
    lhcbName->SetBorderSize(0);

    gStyle->SetOptStat(0);	





    // plotting ------------------------------------------------------------------- 

    // Define the histograms
    TH1D* h1 = new TH1D ("h1", varname.c_str(), bins, rangemin, rangemax);
    //TH1D* h2 = new TH1D ("h2", varname.c_str(), bins, rangemin, rangemax);
    
    
    // Differentiating the MC histo from the data histo
    h1->Sumw2(); 	//with this get markers, without get a line
    //h2->SetMarkerColor(kRed);
    //h2->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw(varhisto1.c_str(), "", "goff"); 	
    //t2->Draw(varhisto2.c_str(), "", "goff");


    // Scaling MC to data
    //h2->Scale(Nhisto1 / float(Nhisto2)); 


    // Setting up canvas
    TCanvas* c1 = new TCanvas();
    c1->Divide(1,1);
    c1->cd(1);


    // Plotting 
    //h2->Draw();
    h1->Draw(); 	
    h1->SetTitle( varname.c_str() );
    h1->GetXaxis()->SetTitle( xaxis.c_str() );	
    h1->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		

    int Nhisto1 = t1->GetEntries("");
    c1->SaveAs( outfile.c_str() );   

    std::cout << Nhisto1 << " events in histo1" << std::endl;
    //std::cout << Nhisto2 << " events in histo2" << std::endl;

}




