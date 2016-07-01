/*	
	
	Alice Morris
	MPhys Project 2015/16

	

*/




#include <TLorentzVector.h>


void PID_misidentification() {

    // -- define tuple file name, tuple name and cuts to apply-----------------------
    // -- and also the name of the output file
    const std::string filename = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/Lb2chicpK_2011_2012_signal_withbdt.root";
    const std::string treename = "withbdt";
    const std::string outFilename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/signal_samples/Lb2chicpK_2011_2012_swappedmass.root");
    
    const std::string cuts = "";
    //const std::string cuts = "Lambda_b0_DTF_MASS_constr1 > 5650. && Lambda_b0_DTF_MASS_constr1 < 5700.";
    
    const std::string outputPlot("~/cern/plots/p->[K,pi]_signal_MC.pdf");
   
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




    double chi_c_M,  chi_c_P, chi_c_PE, chi_c_PT, chi_c_PX, chi_c_PY, chi_c_PZ, chi_c_ETA;
    double kaon_M,  kaon_P, kaon_PE, kaon_PX, kaon_PT, kaon_PY, kaon_PZ, kaon_ETA, kaon_IPCHI2_OWNPV, kaon_TRACK_GhostProb, kaon_ProbNNp, kaon_ProbNNk;
    double proton_M,  proton_P, proton_PE, proton_PT, proton_PX, proton_PY, proton_PZ, proton_ETA, proton_IPCHI2_OWNPV, proton_TRACK_GhostProb, proton_ProbNNp, proton_ProbNNk;
    double Jpsi_M, Jpsi_P, Jpsi_PE, Jpsi_PT, Jpsi_PX, Jpsi_PY, Jpsi_PZ, Jpsi_ETA;
    double gamma_M, gamma_P, gamma_PE, gamma_PT, gamma_PX, gamma_PY, gamma_PZ, gamma_ETA, gamma_CL;
    double muminus_M, muminus_P, muminus_PE, muminus_PT, muminus_PX, muminus_PY, muminus_PZ, muminus_ETA, muminus_ProbNNmu, muminus_TRACK_GhostProb;
    double muplus_M, muplus_P, muplus_PE, muplus_PT, muplus_PX, muplus_PY, muplus_PZ, muplus_ETA, muplus_ProbNNmu, muplus_TRACK_GhostProb;
    double Lambda_b0_DTF_MASS_constr1, Lambda_b0_DTF_MASS_constr2, Lambda_b0_DTF_CHI2NDOF, Lambda_b0_IPCHI2_OWNPV;
    double Lambda_b0_FDS, Lambda_b0_pi0veto, Lambda_b0_PT; 
    float bdtg; 
    
    Char_t Lambda_b0_L0MuonDecision_TOS, Lambda_b0_L0DiMuonDecision_TOS;
    Char_t Lambda_b0_Hlt1DiMuonHighMassDecision_TOS, Lambda_b0_Hlt1DiMuonLowMassDecision_TOS;
    Char_t Lambda_b0_Hlt1TrackMuonDecision_TOS, Lambda_b0_Hlt1TrackAllL0Decision_TOS;
    Char_t Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS, Lambda_b0_Hlt2DiMuonDetachedDecision_TOS, Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS;
    Char_t Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS;
    
    
    rTree1->SetBranchAddress("chi_c_M", &chi_c_M);
    rTree1->SetBranchAddress("chi_c_P", &chi_c_P);
    rTree1->SetBranchAddress("chi_c_PE", &chi_c_PE);
    rTree1->SetBranchAddress("chi_c_PT", &chi_c_PT);
    rTree1->SetBranchAddress("chi_c_PX", &chi_c_PX);
    rTree1->SetBranchAddress("chi_c_PY", &chi_c_PY);
    rTree1->SetBranchAddress("chi_c_PZ", &chi_c_PZ);
    
    rTree1->SetBranchAddress("kaon_M", &kaon_M);
    rTree1->SetBranchAddress("kaon_P", &kaon_P);
    rTree1->SetBranchAddress("kaon_PE", &kaon_PE);
    rTree1->SetBranchAddress("kaon_PX", &kaon_PX);
    rTree1->SetBranchAddress("kaon_PT", &kaon_PT);
    rTree1->SetBranchAddress("kaon_PY", &kaon_PY);
    rTree1->SetBranchAddress("kaon_PZ", &kaon_PZ);

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

  
    rTree1->SetBranchAddress("gamma_M", &gamma_M);
    rTree1->SetBranchAddress("gamma_P", &gamma_P);
    rTree1->SetBranchAddress("gamma_PE", &gamma_PE);
    rTree1->SetBranchAddress("gamma_PT", &gamma_PT);
    rTree1->SetBranchAddress("gamma_PX", &gamma_PX);
    rTree1->SetBranchAddress("gamma_PY", &gamma_PY);
    rTree1->SetBranchAddress("gamma_PZ", &gamma_PZ);

    rTree1->SetBranchAddress("gamma_CL", &gamma_CL);  

    rTree1->SetBranchAddress("muminus_M", &muminus_M);
    rTree1->SetBranchAddress("muminus_P", &muminus_P);
    rTree1->SetBranchAddress("muminus_PE", &muminus_PE); 
    rTree1->SetBranchAddress("muminus_PT", &muminus_PT);
    rTree1->SetBranchAddress("muminus_PX", &muminus_PX);
    rTree1->SetBranchAddress("muminus_PY", &muminus_PY);
    rTree1->SetBranchAddress("muminus_PZ", &muminus_PZ);  

    rTree1->SetBranchAddress("muminus_ProbNNmu", &muminus_ProbNNmu);  
    rTree1->SetBranchAddress("muminus_TRACK_GhostProb", &muminus_TRACK_GhostProb);  

    rTree1->SetBranchAddress("muplus_M", &muplus_M);
    rTree1->SetBranchAddress("muplus_P", &muplus_P);
    rTree1->SetBranchAddress("muplus_PE", &muplus_PE);
    rTree1->SetBranchAddress("muplus_PT", &muplus_PT);
    rTree1->SetBranchAddress("muplus_PX", &muplus_PX);
    rTree1->SetBranchAddress("muplus_PY", &muplus_PY);
    rTree1->SetBranchAddress("muplus_PZ", &muplus_PZ);

    rTree1->SetBranchAddress("muplus_ProbNNmu", &muplus_ProbNNmu);  
    rTree1->SetBranchAddress("muplus_TRACK_GhostProb", &muplus_TRACK_GhostProb);  

    rTree1->SetBranchAddress("Lambda_b0_DTF_MASS_constr1", &Lambda_b0_DTF_MASS_constr1);
    rTree1->SetBranchAddress("Lambda_b0_DTF_MASS_constr2", &Lambda_b0_DTF_MASS_constr2);
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
    rTree1->SetBranchAddress("Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS); 
    rTree1->SetBranchAddress("Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS);
    rTree1->SetBranchAddress("Lambda_b0_pi0veto", &Lambda_b0_pi0veto);
    rTree1->SetBranchAddress("Lambda_b0_PT", &Lambda_b0_PT);
    
    rTree1->SetBranchAddress("bdtg", &bdtg);

   
    
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

    rTree2->Branch("kaon_M", &kaon_M, "kaon_M/D");
    rTree2->Branch("kaon_P", &kaon_P, "kaon_P/D");
    rTree2->Branch("kaon_PE", &kaon_PE, "kaon_PE/D");
    rTree2->Branch("kaon_PX", &kaon_PX, "kaon_PX/D");
    rTree2->Branch("kaon_PT", &kaon_PT, "kaon_PT/D");
    rTree2->Branch("kaon_PY", &kaon_PY, "kaon_PY/D");
    rTree2->Branch("kaon_PZ", &kaon_PZ, "kaon_PZ/D");

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
  
    rTree2->Branch("gamma_M", &gamma_M, "gamma_M/D");
    rTree2->Branch("gamma_P", &gamma_P, "gamma_P/D");
    rTree2->Branch("gamma_PE", &gamma_PE, "gamma_PE/D");
    rTree2->Branch("gamma_PT", &gamma_PT, "gamma_PT/D");
    rTree2->Branch("gamma_PX", &gamma_PX, "gamma_PX/D");
    rTree2->Branch("gamma_PY", &gamma_PY, "gamma_PY/D");
    rTree2->Branch("gamma_PZ", &gamma_PZ, "gamma_PZ/D");

    rTree2->Branch("gamma_CL", &gamma_CL, "gamma_CL/D");  

    rTree2->Branch("muminus_M", &muminus_M, "muminus_M/D");
    rTree2->Branch("muminus_P", &muminus_P, "muminus_P/D");
    rTree2->Branch("muminus_PE", &muminus_PE, "muminus_PE/D"); 
    rTree2->Branch("muminus_PT", &muminus_PT, "muminus_PT/D");
    rTree2->Branch("muminus_PX", &muminus_PX, "muminus_PX/D");
    rTree2->Branch("muminus_PY", &muminus_PY, "muminus_PY/D");
    rTree2->Branch("muminus_PZ", &muminus_PZ, "muminus_PZ/D");  

    rTree2->Branch("muminus_ProbNNmu", &muminus_ProbNNmu, "muminus_ProbNNmu/D");  
    rTree2->Branch("muminus_TRACK_GhostProb", &muminus_TRACK_GhostProb, "muminus_TRACK_GhostProb/D");  

    rTree2->Branch("muplus_M", &muplus_M, "muplus_M/D");
    rTree2->Branch("muplus_P", &muplus_P, "muplus_P/D");
    rTree2->Branch("muplus_PE", &muplus_PE, "muplus_PE/D");
    rTree2->Branch("muplus_PT", &muplus_PT, "muplus_PT/D");
    rTree2->Branch("muplus_PX", &muplus_PX, "muplus_PX/D");
    rTree2->Branch("muplus_PY", &muplus_PY, "muplus_PY/D");
    rTree2->Branch("muplus_PZ", &muplus_PZ, "muplus_PZ/D");

    rTree2->Branch("muplus_ProbNNmu", &muplus_ProbNNmu, "muplus_ProbNNmu/D");  
    rTree2->Branch("muplus_TRACK_GhostProb", &muplus_TRACK_GhostProb, "muplus_TRACK_GhostProb/D");  

    rTree2->Branch("Lambda_b0_DTF_MASS_constr1", &Lambda_b0_DTF_MASS_constr1, "Lambda_b0_DTF_MASS_constr1/D");
    rTree2->Branch("Lambda_b0_DTF_MASS_constr2", &Lambda_b0_DTF_MASS_constr2, "Lambda_b0_DTF_MASS_constr2/D");
    rTree2->Branch("Lambda_b0_DTF_CHI2NDOF", &Lambda_b0_DTF_CHI2NDOF, "Lambda_b0_DTF_CHI2NDOF/D");
    rTree2->Branch("Lambda_b0_IPCHI2_OWNPV", &Lambda_b0_IPCHI2_OWNPV, "Lambda_b0_IPCHI2_OWNPV/D");
    rTree2->Branch("Lambda_b0_L0DiMuonDecision_TOS", &Lambda_b0_L0DiMuonDecision_TOS, "Lambda_b0_L0DiMuonDecision_TOS/C");
    rTree2->Branch("Lambda_b0_L0MuonDecision_TOS", &Lambda_b0_L0MuonDecision_TOS, "Lambda_b0_L0MuonDecision_TOS/C");
    rTree2->Branch("Lambda_b0_FDS", &Lambda_b0_FDS, "Lambda_b0_FDS/D");  
    rTree2->Branch("Lambda_b0_Hlt1DiMuonHighMassDecision_TOS", &Lambda_b0_Hlt1DiMuonHighMassDecision_TOS, "Lambda_b0_Hlt1DiMuonHighMassDecision_TOS/C");  
    rTree2->Branch("Lambda_b0_Hlt1DiMuonLowMassDecision_TOS", &Lambda_b0_Hlt1DiMuonLowMassDecision_TOS, "Lambda_b0_Hlt1DiMuonLowMassDecision_TOS/C");  
    rTree2->Branch("Lambda_b0_Hlt1TrackMuonDecision_TOS", &Lambda_b0_Hlt1TrackMuonDecision_TOS, "Lambda_b0_Hlt1TrackMuonDecision_TOS/C");  
    rTree2->Branch("Lambda_b0_Hlt1TrackAllL0Decision_TOS", &Lambda_b0_Hlt1TrackAllL0Decision_TOS, "Lambda_b0_Hlt1TrackAllL0Decision_TOS/C");
    rTree2->Branch("Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS", &Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS, "Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS/C");  
    rTree2->Branch("Lambda_b0_Hlt2DiMuonDetachedDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedDecision_TOS, "Lambda_b0_Hlt2DiMuonDetachedDecision_TOS/C"); 
    rTree2->Branch("Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS, "Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS/C");
    rTree2->Branch("Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS, "Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS/C");
    rTree2->Branch("Lambda_b0_pi0veto", &Lambda_b0_pi0veto, "Lambda_b0_pi0veto/D");
    rTree2->Branch("Lambda_b0_PT", &Lambda_b0_PT, "Lambda_b0_PT/D");
                            
    rTree2->Branch("bdtg", &bdtg, "bdtg/F");
   
    
    
    //This is where the misidentification is calculated for P and pi,K---------------------------
    

    const double mK(493.677);
    const double mpi(139.57);
    const double mp(938.27);
    
    double proton_as_kaon_M, proton_as_pion_M, proton_as_proton_M, Lambda_b0_DTF_MASS_proton_as_kaon, Lambda_b0_DTF_MASS_proton_as_pion, Lambda_b0_DTF_MASS_proton_as_proton; 
    //double proton_PX, proton_PY, proton_PZ, chi_c_PX, chi_c_PY, chi_c_PZ, chi_c_PE, kaon_PX, kaon_PY, kaon_PZ, kaon_PE;
	
    
    rTree2->Branch("proton_as_kaon_M", &proton_as_kaon_M, "proton_as_kaon_M/D");
    rTree2->Branch("proton_as_pion_M", &proton_as_pion_M, "proton_as_pion_M/D");
    rTree2->Branch("proton_as_proton_M", &proton_as_proton_M, "proton_as_proton_M/D");
    rTree2->Branch("Lambda_b0_DTF_MASS_proton_as_kaon", &Lambda_b0_DTF_MASS_proton_as_kaon, "Lambda_b0_DTF_MASS_proton_as_kaon/D");
    rTree2->Branch("Lambda_b0_DTF_MASS_proton_as_pion", &Lambda_b0_DTF_MASS_proton_as_pion, "Lambda_b0_DTF_MASS_proton_as_pion/D");
    rTree2->Branch("Lambda_b0_DTF_MASS_proton_as_proton", &Lambda_b0_DTF_MASS_proton_as_proton, "Lambda_b0_DTF_MASS_proton_as_proton/D");
   
    
    
    
    for(int i = 0; i < rTree1->GetEntries(); ++i){    
    //for event in tree
    
        rTree1->GetEntry(i);
        double proton_P = sqrt(proton_PX*proton_PX + proton_PY*proton_PY + proton_PZ*proton_PZ) ;
        
        
        //need to do something to get the tree branch to add the numbers
        
        
        TLorentzVector proton_as_kaon(proton_PX, proton_PY, proton_PZ, sqrt(proton_P*proton_P + mK*mK));
        TLorentzVector proton_as_pion(proton_PX, proton_PY, proton_PZ, sqrt(proton_P*proton_P + mpi*mpi));
        TLorentzVector proton_as_proton(proton_PX, proton_PY, proton_PZ, sqrt(proton_P*proton_P + proton_M*proton_M));
        TLorentzVector kaon(kaon_PX, kaon_PY, kaon_PZ, kaon_PE);
        TLorentzVector chi_c(chi_c_PX, chi_c_PY, chi_c_PZ, chi_c_PE);
        
        
        proton_as_kaon_M = proton_as_kaon.M();
        proton_as_pion_M = proton_as_pion.M();
        proton_as_proton_M = proton_as_proton.M();
        
        TLorentzVector chic_PasK_K = chi_c+kaon+proton_as_kaon;
        TLorentzVector chic_PasPi_K = chi_c+kaon+proton_as_pion;
        TLorentzVector chic_PasP_K = chi_c+kaon+proton_as_proton;
        
        Lambda_b0_DTF_MASS_proton_as_kaon = chic_PasK_K.M();
        Lambda_b0_DTF_MASS_proton_as_pion = chic_PasPi_K.M();
        Lambda_b0_DTF_MASS_proton_as_proton = chic_PasP_K.M();

        rTree2->Fill();
        
    }
   
    rTree2->Print();
    rTree2->Write();
    rFile->Save();
/*
    gROOT->ProcessLine(".L ~/cern/project/lhcbStyle.C");
    lhcbStyle();
    gStyle->SetOptStat(0);	
    TH1D * p_as_k = new TH1D("p_as_k", "p_as_k", 130, 4500., 5800.);
    TH1D * p_as_pi  = new TH1D("p_as_pi", "p_as_pi", 130, 4500., 5800.);
    
    
    
    rTree2->Draw("Lambda_b0_DTF_MASS_proton_as_kaon>>p_as_k", "", "goff");
    rTree2->Draw("Lambda_b0_DTF_MASS_proton_as_pion>>p_as_pi", "", "goff");
    
    
    TCanvas * c = new TCanvas("c", "c", 1200, 500);
    c->Divide(2,1);
    c->cd(1);
    p_as_k->Draw();
    p_as_k->SetTitle("");
    p_as_k->GetXaxis()->SetTitle("m(#chi_{c} (p #rightarrow K) K^{-}) [MeV/c^{2}]");
    p_as_k->GetYaxis()->SetTitle("Candidates (10 MeV/c^{2})");
    c->cd(2);
    p_as_pi->Draw();
    p_as_pi->SetTitle("");
    p_as_pi->GetXaxis()->SetTitle("m(#chi_{c} (p #rightarrow #pi) K^{-}) [MeV/c^{2}]");
    p_as_pi->GetYaxis()->SetTitle("Candidates (10 MeV/c^{2})");
    c->cd(3);
    p_as_pi->Draw();
    p_as_pi->SetTitle("");
    p_as_pi->GetXaxis()->SetTitle("m(#chi_{c} (p #rightarrow #pi) K^{-}) [MeV/c^{2}]");
    p_as_pi->GetYaxis()->SetTitle("Candidates");
    c->cd(4);
    p_as_pi_b->Draw();
    p_as_pi_b->SetTitle("");
    p_as_pi_b->GetXaxis()->SetTitle("m(#chi_{c} (p #rightarrow #pi) K^{-}) [MeV/c^{2}]");
    p_as_pi_b->GetYaxis()->SetTitle("Candidates");
    
    c->SaveAs(outputPlot.c_str());
    //c->SaveAs("~/cern/plots/proton_as_kaon_and_pion.png");
*/

}









