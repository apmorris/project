/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to plot two ntuples on top of each other.

*/



{

    // Import formatting template
    gROOT->ProcessLine(".L ~/cern/project/lhcbStyle.C");
    lhcbStyle();
   

    // Definition of variables
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bd2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bs2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bu2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Lb2JpsiX_MC_2012_signal_withbdt.root";
    //const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bs2JpsiPhi_MC_2012_signal_withbdt.root";
    
    const std::string filename1 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/reduced_Lb2chicpK_2011_2012_signal_weighted.root";
    const std::string treename1 = "ds";
    
    const std::string filename2 = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/reduced_Lb2chicpK_MC_2011_2012_signal.root";
    const std::string treename2 = "DecayTree";

    const std::string xaxis    = "log(proton_IPCHI2_OWNPV)";
    const std::string yaxis     = "Events";
    //const std::string yaxis     = "sWeight";
    
    
    const std::string title     = "";
    const std::string varhisto1 = "log(proton_IPCHI2_OWNPV)>>h1";
    const std::string varhisto2 = "log(proton_IPCHI2_OWNPV)>>h2";

    const std::string outfile =   "/afs/cern.ch/user/a/apmorris/cern/plots/var_comparisons/log_proton_IPCHI2_OWNPV_before_bdt.pdf";  
  
    int bins = 16;
    float rangemin = 1.;
    float rangemax = 9.;
/*
    //inbdt
    obs.add(kaon_TRACK_GhostProb);
    obs.add(proton_TRACK_GhostProb);
    obs.add(muminus_TRACK_GhostProb);
    obs.add(muplus_TRACK_GhostProb);
    
    obs.add(Lambda_b0_DTF_CHI2NDOF);
    obs.add(Lambda_b0_IPCHI2_OWNPV);
    obs.add(Lambda_b0_FDS);
    obs.add(Lambda_b0_PT);
    obs.add(kaon_PT);//rebin
    obs.add(kaon_IPCHI2_OWNPV);
    obs.add(proton_PT);//rebin
    obs.add(proton_IPCHI2_OWNPV);
    obs.add(gamma_CL);
    obs.add(gamma_PT);
    obs.add(muplus_ProbNNmu);
    obs.add(muminus_ProbNNmu);

    //only in preselection
    obs.add(chi_c_M);
*/


    // Opening files and trees
    TFile* f1 = TFile::Open( filename1.c_str() );
    if( !f1 ) std::cout << "file " << filename1 << " does not exist" << std::endl;

    TTree* t1 = (TTree*)f1.Get( treename1.c_str() );
    if( !t1 ) std::cout << "tree " << treename1 << " does not exist" << std::endl;

    TFile* f2 = TFile::Open( filename2.c_str() );
    if( !f2 ) std::cout << "file " << filename2 << " does not exist" << std::endl;

    TTree* t2 = (TTree*)f2.Get( treename2.c_str() );
    if( !t1 ) std::cout << "tree " << treename2 << " does not exist" << std::endl;


    // Need to scale the Monte Carlo data to the same number of entries as the data
    // So define two integers and scale accordingly later
    //int Nhisto1 = t1->GetEntries("");
    int Nhisto2 = t2->GetEntries("");


    // Including the LHCb name, formatting
    lhcbName = new TPaveText(gStyle->GetPadLeftMargin() + 0.65,
            0.87 - gStyle->GetPadTopMargin(),
            gStyle->GetPadLeftMargin() + 0.75,
            0.95 - gStyle->GetPadTopMargin(),
            "BRNDC");
    lhcbName->AddText("LHCb");
    lhcbName->SetFillColor(0);
    lhcbName->SetTextAlign(12);
    lhcbName->SetBorderSize(0);

    gStyle->SetOptStat(0);	


    titleBox = new TPaveText(gStyle->GetPadLeftMargin() + 0.05,
            0.98 - gStyle->GetPadTopMargin(),
            gStyle->GetPadLeftMargin() + 0.4,
            0.83 - gStyle->GetPadTopMargin(),
            "BRNDC");
    titleBox->AddText(title.c_str());
    titleBox->SetFillColor(0);
    titleBox->SetTextAlign(12);
    titleBox->SetBorderSize(0);


    // plotting ------------------------------------------------------------------- 

    // Define the histograms
    TH1D* h1 = new TH1D ("h1", title.c_str(), bins, rangemin, rangemax);
    TH1D* h2 = new TH1D ("h2", title.c_str(), bins, rangemin, rangemax);
    
    
    // Differentiating the MC histo from the data histo
    h1->Sumw2(); 	//with this get markers, without get a line
    h2->SetMarkerColor(kRed);
    h2->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw(varhisto1.c_str(), "sigYield_sw", "goff"); 	
    t2->Draw(varhisto2.c_str(), "", "goff");


    // Scaling MC to data 
    int Nhisto1 = h1->Integral();
    h2->Scale(Nhisto1 / float(Nhisto2)); 
    

    // Setting up canvas
    TCanvas* c1 = new TCanvas();
    c1->Divide(1,1);
    c1->cd(1);


    // Plotting 
    
    h1->Draw(); 
    h2->Draw("same");	
    h1->SetTitle( title.c_str() );
    h1->GetXaxis()->SetTitle( xaxis.c_str() );	
    h1->GetYaxis()->SetTitle( yaxis.c_str() );
    //lhcbName->Draw();	
    //titleBox->Draw();	
    
    //int Nhisto1 = t1->GetEntries("");
    c1->SaveAs( outfile.c_str() );   
    

    std::cout << Nhisto1 << " events in histo1" << std::endl;
    std::cout << Nhisto2 << " events in histo2" << std::endl;

}




