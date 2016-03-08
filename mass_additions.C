/*	
	
	Alice Morris
	MPhys Project 2015/16

	

*/




#include <TLorentzVector.h>


void mass_additions() {

    // -- define tuple file name, tuple name and cuts to apply-----------------------
    // -- and also the name of the output file
    const std::string filename = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/Lb2chicpK_2011_2012_signal_weighted.root";
    const std::string treename = "ds";
    const std::string outFilename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/Lb2chicpK_2011_2012_signal_new_masses.root");
    
    const std::string cuts = "sigYield_sw";
    //const std::string cuts = "Lambda_b0_DTF_MASS_constr1 > 5650. && Lambda_b0_DTF_MASS_constr1 < 5700.";
    
    const std::string outputPlot("~/cern/plots/m_chicp_and_pK.pdf");
   
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;

    // -- activate the branches you need---------------------------------------------
  
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
    tree->SetBranchStatus("*", 1);
    
    
    
    // -- this file is just here to make the 'CopyTree' happy
    TFile* dummyFile = new TFile("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/dummy.root","RECREATE");
    TTree* rTree1 = tree->CopyTree(cuts.c_str());




    double  chi_c_PE, chi_c_PX, chi_c_PY, chi_c_PZ ;
    double kaon_PE, kaon_PX, kaon_PY, kaon_PZ, kaon_ProbNNp, kaon_ProbNNk;
    double proton_PE, proton_PX, proton_PY, proton_PZ, proton_ProbNNp, proton_ProbNNk;
    double Jpsi_M;
    
    
    double Lambda_b0_DTF_MASS_constr1;
    double sigYield_sw, L_sigYield, bgYield_sw, L_bgYield; 
    
    
    
    rTree1->SetBranchAddress("chi_c_PE", &chi_c_PE);
    rTree1->SetBranchAddress("chi_c_PX", &chi_c_PX);
    rTree1->SetBranchAddress("chi_c_PY", &chi_c_PY);
    rTree1->SetBranchAddress("chi_c_PZ", &chi_c_PZ);
    
    rTree1->SetBranchAddress("kaon_PE", &kaon_PE);
    rTree1->SetBranchAddress("kaon_PX", &kaon_PX);
    rTree1->SetBranchAddress("kaon_PY", &kaon_PY);
    rTree1->SetBranchAddress("kaon_PZ", &kaon_PZ);

    rTree1->SetBranchAddress("kaon_ProbNNp", &kaon_ProbNNp);
    rTree1->SetBranchAddress("kaon_ProbNNk", &kaon_ProbNNk);
    
    rTree1->SetBranchAddress("proton_PE", &proton_PE);
    rTree1->SetBranchAddress("proton_PX", &proton_PX);
    rTree1->SetBranchAddress("proton_PY", &proton_PY);
    rTree1->SetBranchAddress("proton_PZ", &proton_PZ);

    rTree1->SetBranchAddress("proton_ProbNNp", &proton_ProbNNp);
    rTree1->SetBranchAddress("proton_ProbNNk", &proton_ProbNNk);

    rTree1->SetBranchAddress("Jpsi_M", &Jpsi_M);

    rTree1->SetBranchAddress("Lambda_b0_DTF_MASS_constr1", &Lambda_b0_DTF_MASS_constr1);
    
    rTree1->SetBranchAddress("sigYield_sw", &sigYield_sw);  
    rTree1->SetBranchAddress("L_sigYield", &L_sigYield);
    rTree1->SetBranchAddress("bgYield_sw", &bgYield_sw);
    rTree1->SetBranchAddress("L_bgYield", &L_bgYield);
    
   
    
    TFile* rFile = new TFile( outFilename.c_str() ,"RECREATE");
    TTree* rTree2 = new TTree();
    rTree2->SetName("ds");
    
    rTree2->Branch("chi_c_PE", &chi_c_PE, "chi_c_PE/D");
    rTree2->Branch("chi_c_PX", &chi_c_PX, "chi_c_PX/D");
    rTree2->Branch("chi_c_PY", &chi_c_PY, "chi_c_PY/D");
    rTree2->Branch("chi_c_PZ", &chi_c_PZ, "chi_c_PZ/D");

    rTree2->Branch("kaon_PE", &kaon_PE, "kaon_PE/D");
    rTree2->Branch("kaon_PX", &kaon_PX, "kaon_PX/D");
    rTree2->Branch("kaon_PY", &kaon_PY, "kaon_PY/D");
    rTree2->Branch("kaon_PZ", &kaon_PZ, "kaon_PZ/D");

    rTree2->Branch("kaon_ProbNNp", &kaon_ProbNNp, "kaon_ProbNNp/D");
    rTree2->Branch("kaon_ProbNNk", &kaon_ProbNNk, "kaon_ProbNNk/D");
    
    rTree2->Branch("proton_PE", &proton_PE, "proton_PE/D");
    rTree2->Branch("proton_PX", &proton_PX, "proton_PX/D");
    rTree2->Branch("proton_PY", &proton_PY, "proton_PY/D");
    rTree2->Branch("proton_PZ", &proton_PZ, "proton_PZ/D");

    rTree2->Branch("proton_ProbNNp", &proton_ProbNNp, "proton_ProbNNp/D");
    rTree2->Branch("proton_ProbNNk", &proton_ProbNNk, "proton_ProbNNk/D");

    rTree2->Branch("Jpsi_M", &Jpsi_M, "Jpsi_M/D");

    rTree2->Branch("Lambda_b0_DTF_MASS_constr1", &Lambda_b0_DTF_MASS_constr1, "Lambda_b0_DTF_MASS_constr1/D");
    
    rTree2->Branch("sigYield_sw", &sigYield_sw, "sigYield_sw/D");  
    rTree2->Branch("L_sigYield", &L_sigYield, "L_sigYield/D");
    rTree2->Branch("bgYield_sw", &bgYield_sw, "bgYield_sw/D");
    rTree2->Branch("L_bgYield", &L_bgYield, "L_bgYield/D");                    
                                              
   
    
    
    //This is where the masses are added---------------------------------------------
    

    
    
    double m_pK, m_chicp;
    //double proton_PX, proton_PY, proton_PZ, chi_c_PX, chi_c_PY, chi_c_PZ, chi_c_PE, kaon_PX, kaon_PY, kaon_PZ, kaon_PE;
	
	
    
    rTree2->Branch("m_chicp", &m_chicp, "m_chicp/D");
    rTree2->Branch("m_pK", &m_pK, "m_pK/D");
    
    
    
    for(int i = 0; i < rTree1->GetEntries(); ++i){    
    //for event in tree
    
        rTree1->GetEntry(i);
        double proton_P = sqrt(proton_PX*proton_PX + proton_PY*proton_PY + proton_PZ*proton_PZ) ;
        
        

        
        
        TLorentzVector proton(proton_PX, proton_PY, proton_PZ, proton_PE);
        TLorentzVector kaon(kaon_PX, kaon_PY, kaon_PZ, kaon_PE);
        TLorentzVector chic(chi_c_PX, chi_c_PY, chi_c_PZ, chi_c_PE);
        
        TLorentzVector chicp = chic+proton;
        TLorentzVector pK = proton+kaon;
        
        m_chicp = chicp.M();
        m_pK = pK.M();
        
        rTree2->Fill();
        
    }
   
    rTree2->Print();
    rTree2->Write();
    rFile->Save();
/*
    gROOT->ProcessLine(".L ~/cern/project/lhcbStyle.C");
    lhcbStyle();
    
    gStyle->SetOptStat(0);
    	
    TH1D * chicp_mass = new TH1D("chicp_mass", "chicp_mass", 80, 1400., 2200.);
    TH1D * pK_mass  = new TH1D("pK_mass", "pK_mass", 75, 4250., 5500.);
    
    
    
    rTree2->Draw("m_chicp>>chicp_mass", "", "goff");
    rTree2->Draw("m_pK>>pK_mass", "", "goff");
    
    
    TCanvas * c = new TCanvas("c", "c", 1400, 500);
    c->Divide(2,1);
    c->cd(1);
    chicp_mass->Draw();
    chicp_mass->SetTitle("");
    chicp_mass->GetXaxis()->SetTitle("m(#chi_{c} p) [MeV/c^{2}]");
    chicp_mass->GetYaxis()->SetTitle("Candidates (/ 10 MeV/c^{2})");
    c->cd(2);
    pK_mass->Draw();
    pK_mass->SetTitle("");
    pK_mass->GetXaxis()->SetTitle("m(p K^{-}) [MeV/c^{2}]");
    pK_mass->GetYaxis()->SetTitle("Candidates (/ 10 MeV/c^{2})");*/
    /*c->cd(3);
    p_as_pi->Draw();
    p_as_pi->SetTitle("");
    p_as_pi->GetXaxis()->SetTitle("m(#chi_{c} (p #rightarrow #pi) K^{-}) [MeV/c^{2}]");
    p_as_pi->GetYaxis()->SetTitle("Candidates");
    c->cd(4);
    p_as_pi_b->Draw();
    p_as_pi_b->SetTitle("");
    p_as_pi_b->GetXaxis()->SetTitle("m(#chi_{c} (p #rightarrow #pi) K^{-}) [MeV/c^{2}]");
    p_as_pi_b->GetYaxis()->SetTitle("Candidates");*/
    
    //c->SaveAs(outputPlot.c_str());
    //c->SaveAs("~/cern/plots/proton_as_kaon_and_pion.png");


}
