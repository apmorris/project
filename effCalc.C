/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to calculate efficiencies. 

*/
#include "TStopwatch.h"

void effCalc(){ 

    // -- define tuple file name, tuple name and cuts to apply
    // -- and also the name of the output file
    
    const std::string filename = "/afs/cern.ch/work/a/apmorris/public/Lb2chicpK/signal_samples/Lb2chicpK_MC_2011_2012_signal_withbdt.root";
    //const std::string outFilename("/afs/cern.ch/work/a/apmorris/public/Lb2chicpK/signal_samples/");
        
    const std::string treename("withbdt");
    
    const std::string outfile = "~/cern/new_plots/signal_MC_gamma_PT_cut.pdf";
    const std::string xaxis   = "m(#chi_{c1}pK^{-}) (MeV/c^{2})";
    const std::string yaxis   = "Events / 2 MeV/c^{2}";
    const std::string cuts("gamma_PT > 500. ");
    
    //TStopwatch sw;
    //sw.Start();
    std::cout << "Opening file: " << filename.c_str() << endl;
    
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
    tree->SetBranchStatus("*", 1);   
      
    //double n_pre = tree->GetEntries("bdtg>=0.85");
    //std::cout << "# of events in original tree = " << n_pre << endl;  
      
    // -- this file is just here to make the 'CopyTree' happy
    
    std::cout << "Copying tree: " << treename.c_str() << endl;
    
    TFile* newFile = new TFile("/afs/cern.ch/work/a/apmorris/public/Lb2chicpK/signal_samples/dummy.root","RECREATE");
    TTree* rTree1 = tree->CopyTree( cuts.c_str() );
    
    //rTree1->Print();
    rTree1->Write();
    newFile->Save();

    
    double n_post = rTree1->GetEntries();
    
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

/*
    titleBox = new TPaveText(gStyle->GetPadLeftMargin() + 0.3,
            0.98 - gStyle->GetPadTopMargin(),
            0.98 - gStyle->GetPadLeftMargin(),
            0.83 - gStyle->GetPadTopMargin(),
            "BRNDC");
    titleBox->AddText(title.c_str());
    titleBox->SetFillColor(0);
    titleBox->SetTextAlign(12);
    titleBox->SetBorderSize(0);
*/
    
    

    // plotting ------------------------------------------------------------------- 

    // Define the histograms
    TH1D* h1 = new TH1D ("h1", "Effect of cutting #gamma pT on simulated sample post-selection", 100, 5500., 5700.);
    TH1D* h2 = new TH1D ("h2", "Effect of cutting #gamma pT on simulated sample post-selection", 100, 5500., 5700.);
    
    
    // Differentiating the two histos from each other
    //h1->Sumw2(); 	
    //h2->Sumw2();
    
    //h1->SetMarkerStyle(kFullDotLarge);
    h1->SetMarkerSize(0.7);
   
    h2->SetMarkerColor(kRed);
    //h2->SetMarkerStyle(kFullDotLarge);
    h2->SetMarkerSize(0.7);
    h2->SetLineColor(kRed);
    

    // Draw the histograms 
    rTree1->Draw("Lambda_b0_DTF_MASS_constr1>>h1", "", "goff"); 	
    tree->Draw("Lambda_b0_DTF_MASS_constr1>>h2", "", "goff");

    
    // Setting up canvas
    TCanvas* c1 = new TCanvas();
    c1->Divide(1,1);
    c1->cd(1);


    // Plotting 
    
    h2->Draw(); 
    h1->Draw("same");
    //h1->SetTitle( title.c_str() );
    h2->GetXaxis()->SetTitle( xaxis.c_str() );	
    h2->GetYaxis()->SetTitle( yaxis.c_str() );
    h2->GetXaxis()->SetLabelSize(0.04);
    h2->GetYaxis()->SetLabelSize(0.035);
    h2->GetXaxis()->SetTitleSize(0.04);
    h2->GetYaxis()->SetTitleSize(0.04);
    //lhcbName->Draw();	
    //titleBox->Draw();
    
    leg = new TLegend(0.75,0.8,0.9,0.9);
    //leg->SetHeader("The Legend Title");
    
    leg->AddEntry(h2,"before cut","l");
    leg->AddEntry(h1,"after cut","l");
    leg->Draw();	
    
    //int Nhisto1 = t1->GetEntries("");
    //c1->SaveAs( outfile.c_str() );   
    
    
    //sw.Stop();
    double n_pre = h2->Integral();
    double efficiency = n_post/n_pre;
    double error = sqrt(efficiency*(1.-efficiency)/n_pre);
    
    std::cout << "# of events in the tree before cut applied = " << n_pre << endl;
    std::cout << "Efficiency = " << efficiency << endl;
    std::cout << "Error = " << error << endl;


    //std::cout << "Total time elapsed: "; sw.Print();

} 

