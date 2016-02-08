/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to calculate the momentum amplitude from the exsiting MC ntuple, 
	and rename the variables of interest while we're at it.

*/




#include <TLorentzVector.h>


void PID_misidentification() {

    // -- define tuple file name, tuple name and cuts to apply-----------------------
    // -- and also the name of the output file
    const std::string filename = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bs2JpsiX_MC_2012_signal_withbdt.root";
    const std::string treename = "withbdt";
    const std::string outFilename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/background_MC_samples/Bs2JpsiX_MC_2012_signal_withbdt_misidentification.root");
   
   
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;

    // -- activate the branches you need---------------------------------------------
  
    tree->SetBranchStatus("*", 1);  
    
    


    // -- this file is just here to make the 'CopyTree' happy
    TFile* dummyFile = new TFile("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/dummy.root","RECREATE");
    TTree* rTree1 = tree->CopyTree("bdtg>=0.85");

    double chi_c_M,  chi_c_P, chi_c_PE, chi_c_PT, chi_c_PX, chi_c_PY, chi_c_PZ, chi_c_ETA;
    double kaon_M,  kaon_P, kaon_PE, kaon_PX, kaon_PT, kaon_PY, kaon_PZ, kaon_ETA, kaon_IPCHI2_OWNPV, kaon_TRACK_GhostProb, kaon_ProbNNp, kaon_ProbNNk;
    double proton_M,  proton_P, proton_PE, proton_PT, proton_PX, proton_PY, proton_PZ, proton_ETA, proton_IPCHI2_OWNPV, proton_TRACK_GhostProb, proton_ProbNNp, proton_ProbNNk;
    double Jpsi_M, Jpsi_P, Jpsi_PE, Jpsi_PT, Jpsi_PX, Jpsi_PY, Jpsi_PZ, Jpsi_ETA;
    double gamma_M, gamma_P, gamma_PE, gamma_PT, gamma_PX, gamma_PY, gamma_PZ, gamma_ETA, gamma_CL;
    double muminus_M, muminus_P, muminus_PE, muminus_PT, muminus_PX, muminus_PY, muminus_PZ, muminus_ETA, muminus_ProbNNmu, muminus_TRACK_GhostProb;
    double muplus_M, muplus_P, muplus_PE, muplus_PT, muplus_PX, muplus_PY, muplus_PZ, muplus_ETA, muplus_ProbNNmu, muplus_TRACK_GhostProb;
    double Lambda_b0_DTF_MASS_constr1, Lambda_b0_DTF_CHI2NDOF, Lambda_b0_IPCHI2_OWNPV;
    double Lambda_b0_FDS, Lambda_b0_pi0veto, Lambda_b0_PT; 
    float bdtg; 
    
    bool Lambda_b0_L0MuonDecision_TOS, Lambda_b0_L0DiMuonDecision_TOS;
    bool Lambda_b0_Hlt1DiMuonHighMassDecision_TOS, Lambda_b0_Hlt1DiMuonLowMassDecision_TOS;
    bool Lambda_b0_Hlt1TrackMuonDecision_TOS, Lambda_b0_Hlt1TrackAllL0Decision_TOS;
    bool Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS, Lambda_b0_Hlt2DiMuonDetachedDecision_TOS;
    bool Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS;
    
    
    rTree1->SetBranchAddress("chi_c_M", &chi_c_M);
    rTree1->SetBranchAddress("chi_c_P", &chi_c_P);
    rTree1->SetBranchAddress("chi_c_PE", &chi_c_PE);
    rTree1->SetBranchAddress("chi_c_PT", &chi_c_PT);
    rTree1->SetBranchAddress("chi_c_PX", &chi_c_PX);
    rTree1->SetBranchAddress("chi_c_PY", &chi_c_PY);
    rTree1->SetBranchAddress("chi_c_PZ", &chi_c_PZ);
    //rTree1->SetBranchAddress("chi_c_ETA", &chi_c_ETA);
    
    rTree1->SetBranchAddress("kaon_M", &kaon_M);
    rTree1->SetBranchAddress("kaon_P", &kaon_P);
    rTree1->SetBranchAddress("kaon_PE", &kaon_PE);
    rTree1->SetBranchAddress("kaon_PX", &kaon_PX);
    rTree1->SetBranchAddress("kaon_PT", &kaon_PT);
    rTree1->SetBranchAddress("kaon_PY", &kaon_PY);
    rTree1->SetBranchAddress("kaon_PZ", &kaon_PZ);
    //rTree1->SetBranchAddress("kaon_ETA", &kaon_ETA);
    rTree1->SetBranchAddress("kaon_IPCHI2_OWNPV", &kaon_IPCHI2_OWNPV);
    rTree1->SetBranchAddress("kaon_TRACK_GhostProb", &kaon_TRACK_GhostProb);
    rTree1->SetBranchAddress("kaon_ProbNNp", &kaon_ProbNNp);
    rTree1->SetBranchAddress("kaon_ProbNNk", &kaon_ProbNNk);
    
    rTree1->SetBranchAddress("proton_M", &proton_M);
    rTree1->SetBranchAddress("proton_P", &proton_P);
    rTree1->SetBranchAddress("proton_PE", &proton_PE);
    rTree1->SetBranchAddress("proton_PT", &proton_PT);
    rTree1->SetBranchAddress("proton_PX", &proton_PX);
    rTree1->SetBranchAddress("proton_PY", &proton_PY);
    rTree1->SetBranchAddress("proton_PZ", &proton_PZ);
    //rTree1->SetBranchAddress("proton_ETA", &proton_ETA);
    rTree1->SetBranchAddress("proton_IPCHI2_OWNPV", &proton_IPCHI2_OWNPV);
    rTree1->SetBranchAddress("proton_TRACK_GhostProb", &proton_TRACK_GhostProb);
    rTree1->SetBranchAddress("proton_ProbNNp", &proton_ProbNNp);
    rTree1->SetBranchAddress("proton_ProbNNk", &proton_ProbNNk);

    rTree1->SetBranchAddress("Jpsi_M", &Jpsi_M);
    rTree1->SetBranchAddress("Jpsi_P", &Jpsi_P);
    rTree1->SetBranchAddress("Jpsi_PE", &Jpsi_PE);
    rTree1->SetBranchAddress("Jpsi_PT", &Jpsi_PT);
    rTree1->SetBranchAddress("Jpsi_PX", &Jpsi_PX);
    rTree1->SetBranchAddress("Jpsi_PY", &Jpsi_PY);
    rTree1->SetBranchAddress("Jpsi_PZ", &Jpsi_PZ);
    //rTree1->SetBranchAddress("Jpsi_ETA", &Jpsi_ETA);     
  
    rTree1->SetBranchAddress("gamma_M", &gamma_M);
    rTree1->SetBranchAddress("gamma_P", &gamma_P);
    rTree1->SetBranchAddress("gamma_PE", &gamma_PE);
    rTree1->SetBranchAddress("gamma_PT", &gamma_PT);
    rTree1->SetBranchAddress("gamma_PX", &gamma_PX);
    rTree1->SetBranchAddress("gamma_PY", &gamma_PY);
    rTree1->SetBranchAddress("gamma_PZ", &gamma_PZ);
    //rTree1->SetBranchAddress("gamma_ETA", &gamma_ETA);  
    rTree1->SetBranchAddress("gamma_CL", &gamma_CL);  

    rTree1->SetBranchAddress("muminus_M", &muminus_M);
    rTree1->SetBranchAddress("muminus_P", &muminus_P);
    rTree1->SetBranchAddress("muminus_PE", &muminus_PE); 
    rTree1->SetBranchAddress("muminus_PT", &muminus_PT);
    rTree1->SetBranchAddress("muminus_PX", &muminus_PX);
    rTree1->SetBranchAddress("muminus_PY", &muminus_PY);
    rTree1->SetBranchAddress("muminus_PZ", &muminus_PZ);  
    //rTree1->SetBranchAddress("muminus_ETA", &muminus_ETA);  
    rTree1->SetBranchAddress("muminus_ProbNNmu", &muminus_ProbNNmu);  
    rTree1->SetBranchAddress("muminus_TRACK_GhostProb", &muminus_TRACK_GhostProb);  

    rTree1->SetBranchAddress("muplus_M", &muplus_M);
    rTree1->SetBranchAddress("muplus_P", &muplus_P);
    rTree1->SetBranchAddress("muplus_PE", &muplus_PE);
    rTree1->SetBranchAddress("muplus_PT", &muplus_PT);
    rTree1->SetBranchAddress("muplus_PX", &muplus_PX);
    rTree1->SetBranchAddress("muplus_PY", &muplus_PY);
    rTree1->SetBranchAddress("muplus_PZ", &muplus_PZ);
    //rTree1->SetBranchAddress("muplus_ETA", &muplus_ETA);  
    rTree1->SetBranchAddress("muplus_ProbNNmu", &muplus_ProbNNmu);  
    rTree1->SetBranchAddress("muplus_TRACK_GhostProb", &muplus_TRACK_GhostProb);  

    rTree1->SetBranchAddress("Lambda_b0_DTF_MASS_constr1", &Lambda_b0_DTF_MASS_constr1);
    rTree1->SetBranchAddress("Lambda_b0_DTF_CHI2NDOF", &Lambda_b0_DTF_CHI2NDOF);
    rTree1->SetBranchAddress("Lambda_b0_IPCHI2_OWNPV", &Lambda_b0_IPCHI2_OWNPV);
    rTree1->SetBranchAddress("Lambda_b0_L0DiMuonDecision_TOS", &Lambda_b0_L0DiMuonDecision_TOS);
    rTree1->SetBranchAddress("Lambda_b0_L0MuonDecision_TOS", &Lambda_b0_L0MuonDecision_TOS);
    rTree1->SetBranchAddress("Lambda_b0_FDS", &Lambda_b0_FDS);  
    rTree1->SetBranchAddress("Lambda_b0_Hlt1DiMuonHighMassDecision_TOS", &Lambda_b0_Hlt1DiMuonHighMassDecision_TOS);  
    rTree1->SetBranchAddress("Lambda_b0_Hlt1DiMuonLowMassDecision_TOS", &Lambda_b0_Hlt1DiMuonLowMassDecision_TOS);  
    rTree1->SetBranchAddress("Lambda_b0_Hlt1TrackMuonDecision_TOS", &Lambda_b0_Hlt1TrackMuonDecision_TOS); 
    rTree1->SetBranchAddress("Lambda_b0_Hlt1TrackAllL0Decision_TOS", &Lambda_b0_Hlt1TrackAllL0Decision_TOS); 
    rTree1->SetBranchAddress("Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS", &Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS);  
    rTree1->SetBranchAddress("Lambda_b0_Hlt2DiMuonDetachedDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedDecision_TOS); 
    rTree1->SetBranchAddress("Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS);
    rTree1->SetBranchAddress("Lambda_b0_pi0veto", &Lambda_b0_pi0veto);
    rTree1->SetBranchAddress("Lambda_b0_PT", &Lambda_b0_PT);

    rTree1->SetBranchAddress("bdtg", &bdtg);
    //-------------------------------------------------------------------------------

    TFile* rFile = new TFile( outFilename.c_str() ,"RECREATE");
    TTree* rTree2 = new TTree();
    rTree2->SetName("withbdt");
    
    rTree2->Branch("chi_c_M", &chi_c_M, "chi_c_M/D");
    rTree2->Branch("chi_c_P", &chi_c_P, "chi_c_P/D");
    rTree2->Branch("chi_c_PE", &chi_c_PE, "chi_c_PE/D");
    rTree2->Branch("chi_c_PT", &chi_c_PT, "chi_c_PT/D");
    rTree2->Branch("chi_c_PX", &chi_c_PX, "chi_c_PX/D");
    rTree2->Branch("chi_c_PY", &chi_c_PY, "chi_c_PY/D");
    rTree2->Branch("chi_c_PZ", &chi_c_PZ, "chi_c_PZ/D");
    //rTree2->Branch("chi_c_ETA", &chi_c_ETA, "chi_c_ETA/D");
    
    rTree2->Branch("kaon_M", &kaon_M, "kaon_M/D");
    rTree2->Branch("kaon_P", &kaon_P, "kaon_P/D");
    rTree2->Branch("kaon_PE", &kaon_PE, "kaon_PE/D");
    rTree2->Branch("kaon_PX", &kaon_PX, "kaon_PX/D");
    rTree2->Branch("kaon_PT", &kaon_PT, "kaon_PT/D");
    rTree2->Branch("kaon_PY", &kaon_PY, "kaon_PY/D");
    rTree2->Branch("kaon_PZ", &kaon_PZ, "kaon_PZ/D");
    //rTree2->Branch("kaon_ETA", &kaon_ETA, "kaon_ETA/D");
    rTree2->Branch("kaon_IPCHI2_OWNPV", &kaon_IPCHI2_OWNPV, "kaon_IPCHI2_OWNPV/D");
    rTree2->Branch("kaon_TRACK_GhostProb", &kaon_TRACK_GhostProb, "kaon_TRACK_GhostProb/D");
    rTree2->Branch("kaon_ProbNNp", &kaon_ProbNNp, "kaon_ProbNNp/D");
    rTree2->Branch("kaon_ProbNNk", &kaon_ProbNNk, "kaon_ProbNNk/D");
    
    rTree2->Branch("proton_M", &proton_M, "proton_M/D");
    rTree2->Branch("proton_P", &proton_P, "proton_P/D");
    rTree2->Branch("proton_PE", &proton_PE, "proton_PE/D");
    rTree2->Branch("proton_PT", &proton_PT, "proton_PT/D");
    rTree2->Branch("proton_PX", &proton_PX, "proton_PX/D");
    rTree2->Branch("proton_PY", &proton_PY, "proton_PY/D");
    rTree2->Branch("proton_PZ", &proton_PZ, "proton_PZ/D");
    //rTree2->Branch("proton_ETA", &proton_ETA, "proton_ETA/D");
    rTree2->Branch("proton_IPCHI2_OWNPV", &proton_IPCHI2_OWNPV, "proton_IPCHI2_OWNPV/D");
    rTree2->Branch("proton_TRACK_GhostProb", &proton_TRACK_GhostProb, "proton_TRACK_GhostProb/D");
    rTree2->Branch("proton_ProbNNp", &proton_ProbNNp, "proton_ProbNNp/D");
    rTree2->Branch("proton_ProbNNk", &proton_ProbNNk, "proton_ProbNNk/D");

    rTree2->Branch("Jpsi_M", &Jpsi_M, "Jpsi_M/D");
    rTree2->Branch("Jpsi_P", &Jpsi_P, "Jpsi_P/D");
    rTree2->Branch("Jpsi_PE", &Jpsi_PE, "Jpsi_PE/D");
    rTree2->Branch("Jpsi_PT", &Jpsi_PT, "Jpsi_PT/D");
    rTree2->Branch("Jpsi_PX", &Jpsi_PX, "Jpsi_PX/D");
    rTree2->Branch("Jpsi_PY", &Jpsi_PY, "Jpsi_PY/D");
    rTree2->Branch("Jpsi_PZ", &Jpsi_PZ, "Jpsi_PZ/D");
    //rTree2->Branch("Jpsi_ETA", &Jpsi_ETA, "Jpsi_ETA/D");     
  
    rTree2->Branch("gamma_M", &gamma_M, "gamma_M/D");
    rTree2->Branch("gamma_P", &gamma_P, "gamma_P/D");
    rTree2->Branch("gamma_PE", &gamma_PE, "gamma_PE/D");
    rTree2->Branch("gamma_PT", &gamma_PT, "gamma_PT/D");
    rTree2->Branch("gamma_PX", &gamma_PX, "gamma_PX/D");
    rTree2->Branch("gamma_PY", &gamma_PY, "gamma_PY/D");
    rTree2->Branch("gamma_PZ", &gamma_PZ, "gamma_PZ/D");
    //rTree2->Branch("gamma_ETA", &gamma_ETA, "gamma_ETA/D");  
    rTree2->Branch("gamma_CL", &gamma_CL, "gamma_CL/D");  

    rTree2->Branch("muminus_M", &muminus_M, "muminus_M/D");
    rTree2->Branch("muminus_P", &muminus_P, "muminus_P/D");
    rTree2->Branch("muminus_PE", &muminus_PE, "muminus_PE/D"); 
    rTree2->Branch("muminus_PT", &muminus_PT, "muminus_PT/D");
    rTree2->Branch("muminus_PX", &muminus_PX, "muminus_PX/D");
    rTree2->Branch("muminus_PY", &muminus_PY, "muminus_PY/D");
    rTree2->Branch("muminus_PZ", &muminus_PZ, "muminus_PZ/D");  
    //rTree2->Branch("muminus_ETA", &muminus_ETA, "muminus_ETA/D");  
    rTree2->Branch("muminus_ProbNNmu", &muminus_ProbNNmu, "muminus_ProbNNmu/D");  
    rTree2->Branch("muminus_TRACK_GhostProb", &muminus_TRACK_GhostProb, "muminus_TRACK_GhostProb/D");  

    rTree2->Branch("muplus_M", &muplus_M, "muplus_M/D");
    rTree2->Branch("muplus_P", &muplus_P, "muplus_P/D");
    rTree2->Branch("muplus_PE", &muplus_PE, "muplus_PE/D");
    rTree2->Branch("muplus_PT", &muplus_PT, "muplus_PT/D");
    rTree2->Branch("muplus_PX", &muplus_PX, "muplus_PX/D");
    rTree2->Branch("muplus_PY", &muplus_PY, "muplus_PY/D");
    rTree2->Branch("muplus_PZ", &muplus_PZ, "muplus_PZ/D");
    //rTree2->Branch("muplus_ETA", &muplus_ETA, "muplus_ETA/D");  
    rTree2->Branch("muplus_ProbNNmu", &muplus_ProbNNmu, "muplus_ProbNNmu/D");  
    rTree2->Branch("muplus_TRACK_GhostProb", &muplus_TRACK_GhostProb, "muplus_TRACK_GhostProb/D");  

    rTree2->Branch("Lambda_b0_DTF_MASS_constr1", &Lambda_b0_DTF_MASS_constr1, "Lambda_b0_DTF_MASS_constr1/D");
    rTree2->Branch("Lambda_b0_DTF_CHI2NDOF", &Lambda_b0_DTF_CHI2NDOF, "Lambda_b0_DTF_CHI2NDOF/D");
    rTree2->Branch("Lambda_b0_IPCHI2_OWNPV", &Lambda_b0_IPCHI2_OWNPV, "Lambda_b0_IPCHI2_OWNPV/D");
    rTree2->Branch("Lambda_b0_L0DiMuonDecision_TOS", &Lambda_b0_L0DiMuonDecision_TOS, "Lambda_b0_L0DiMuonDecision_TOS/B");
    rTree2->Branch("Lambda_b0_L0MuonDecision_TOS", &Lambda_b0_L0MuonDecision_TOS, "Lambda_b0_L0MuonDecision_TOS/B");
    rTree2->Branch("Lambda_b0_FDS", &Lambda_b0_FDS, "Lambda_b0_FDS/D");  
    rTree2->Branch("Lambda_b0_Hlt1DiMuonHighMassDecision_TOS", &Lambda_b0_Hlt1DiMuonHighMassDecision_TOS, "Lambda_b0_Hlt1DiMuonHighMassDecision_TOS/B");  
    rTree2->Branch("Lambda_b0_Hlt1DiMuonLowMassDecision_TOS", &Lambda_b0_Hlt1DiMuonLowMassDecision_TOS, "Lambda_b0_Hlt1DiMuonLowMassDecision_TOS/B");  
    rTree2->Branch("Lambda_b0_Hlt1TrackMuonDecision_TOS", &Lambda_b0_Hlt1TrackMuonDecision_TOS, "Lambda_b0_Hlt1TrackMuonDecision_TOS/B");  
    rTree2->Branch("Lambda_b0_Hlt1TrackAllL0Decision_TOS", &Lambda_b0_Hlt1TrackAllL0Decision_TOS, "Lambda_b0_Hlt1TrackAllL0Decision_TOS/B");
    rTree2->Branch("Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS", &Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS, "Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS/B");  
    rTree2->Branch("Lambda_b0_Hlt2DiMuonDetachedDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedDecision_TOS, "Lambda_b0_Hlt2DiMuonDetachedDecision_TOS/B"); 
    rTree2->Branch("Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS, "Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS/B");
    rTree2->Branch("Lambda_b0_pi0veto", &Lambda_b0_pi0veto, "Lambda_b0_pi0veto/D");
    rTree2->Branch("Lambda_b0_PT", &Lambda_b0_PT, "Lambda_b0_PT/D");

    rTree2->Branch("bdtg", &bdtg, "bdtg/F");
    
    
    
    //This is where the misidentification is calculated for P and K---------------------------
    

    const double mK(0.493677);
    
    double mass_proton_as_proton, mass_proton_as_kaon, mass_kaon_as_kaon;
	
    rTree2->Branch("mass_proton_as_proton", &mass_proton_as_proton, "mass_proton_as_proton/D");
    rTree2->Branch("mass_proton_as_kaon", &mass_proton_as_kaon, "mass_proton_as_kaon/D");
    rTree2->Branch("mass_kaon_as_kaon", &mass_kaon_as_kaon, "mass_kaon_as_kaon/D");
    
    double proton_P = sqrt(proton_PX*proton_PX + proton_PY*proton_PY + proton_PZ*proton_PZ) ;
    
    for(int i = 0; i < rTree1->GetEntries(); ++i){    
    //for event in tree
    
        rTree1->GetEntry(i);
        
        TLorentzVector * proton = new TLorentzVector(proton_PX, proton_PY, proton_PZ, proton_PE);
        TLorentzVector * proton_as_kaon = new TLorentzVector(proton_PX, proton_PY, proton_PZ, sqrt(proton_P*proton_P + mK*mK));
        TLorentzVector * kaon = new TLorentzVector(kaon_PX, kaon_PY, kaon_PZ, kaon_PE);  
              
        mass_proton_as_proton = proton->M();
        mass_proton_as_kaon = proton_as_kaon->M();
        mass_kaon_as_kaon = kaon->M();

        rTree2->Fill();
        
    }
   
    rTree2->Print();
    rTree2->Write();
    rFile->Save();



}









