/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to apply manual cuts to the new data. 

*/
#include "TStopwatch.h"

void newReduceTree_norm(){ 

    // -- define tuple file name, tuple name and cuts to apply
    // -- and also the name of the output file
    
    TStopwatch sw;
    sw.Start();
    
    const std::string filename = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/Lb2JpsipK_MC_2011_2012_norm_cut.root";//change
    
    const std::string treename("DecayTree");

    const std::string cuts = "";

    const std::string outFilename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/reduced_Lb2JpsipK_MC)2011_2012_norm.root");//change
  

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
    tree->SetBranchStatus("*", 0);
    
    tree->SetBranchStatus("kaon_M",1);
    tree->SetBranchStatus("kaon_P",1);
    tree->SetBranchStatus("kaon_PE",1);
    tree->SetBranchStatus("kaon_PT",1);
    tree->SetBranchStatus("kaon_PX",1);
    tree->SetBranchStatus("kaon_PY",1);
    tree->SetBranchStatus("kaon_PZ",1);

    tree->SetBranchStatus("kaon_IPCHI2_OWNPV",1);
    tree->SetBranchStatus("kaon_TRACK_GhostProb",1);
    tree->SetBranchStatus("kaon_ProbNNp",1);
    tree->SetBranchStatus("kaon_ProbNNk",1);
    
    tree->SetBranchStatus("proton_M",1);
    tree->SetBranchStatus("proton_P",1);
    tree->SetBranchStatus("proton_PE",1);
    tree->SetBranchStatus("proton_PT",1);
    tree->SetBranchStatus("proton_PX",1);
    tree->SetBranchStatus("proton_PY",1);
    tree->SetBranchStatus("proton_PZ",1);

    tree->SetBranchStatus("proton_IPCHI2_OWNPV",1);
    tree->SetBranchStatus("proton_TRACK_GhostProb",1);
    tree->SetBranchStatus("proton_ProbNNp",1);
    tree->SetBranchStatus("proton_ProbNNk",1);
    
    tree->SetBranchStatus("Jpsi_M",1);
    tree->SetBranchStatus("Jpsi_P",1);
    tree->SetBranchStatus("Jpsi_PE",1);
    tree->SetBranchStatus("Jpsi_PT",1);
    tree->SetBranchStatus("Jpsi_PX",1);
    tree->SetBranchStatus("Jpsi_PY",1);
    tree->SetBranchStatus("Jpsi_PZ",1);
    
    tree->SetBranchStatus("muminus_M",1);
    tree->SetBranchStatus("muminus_P",1);
    tree->SetBranchStatus("muminus_PE",1);
    tree->SetBranchStatus("muminus_PT",1);
    tree->SetBranchStatus("muminus_PX",1);
    tree->SetBranchStatus("muminus_PY",1);
    tree->SetBranchStatus("muminus_PZ",1);
    tree->SetBranchStatus("muminus_ProbNNmu",1);
    tree->SetBranchStatus("muminus_TRACK_GhostProb",1); 
    
    tree->SetBranchStatus("muplus_M",1);
    tree->SetBranchStatus("muplus_P",1);
    tree->SetBranchStatus("muplus_PE",1);
    tree->SetBranchStatus("muplus_PT",1);
    tree->SetBranchStatus("muplus_PX",1);
    tree->SetBranchStatus("muplus_PY",1);
    tree->SetBranchStatus("muplus_PZ",1);

    tree->SetBranchStatus("muplus_ProbNNmu",1);
    tree->SetBranchStatus("muplus_TRACK_GhostProb",1);
    
    tree->SetBranchStatus("Lambda_b0_DTF_MASS_constr1",1);
    tree->SetBranchStatus("Lambda_b0_DTF_CHI2NDOF",1);
    tree->SetBranchStatus("Lambda_b0_IPCHI2_OWNPV",1);
    tree->SetBranchStatus("Lambda_b0_FDS",1);
    tree->SetBranchStatus("Lambda_b0_L0MuonDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_L0DiMuonDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1DiMuonHighMassDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1DiMuonLowMassDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1TrackMuonDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1TrackAllL0Decision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt2DiMuonDetachedDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_PT",1);
    
     
    //for MC only                                                                   //
    tree->SetBranchStatus("Jpsi_BKGCAT",1);                                         //
    tree->SetBranchStatus("Lambda_b0_BKGCAT",1);                                    //
  
   
    
    // -- this file is just here to make the 'CopyTree' happy
    TFile* dummyFile = new TFile("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/dummy.root","RECREATE");
    TTree* rTree1 = tree->CopyTree(cuts.c_str());



    double kaon_M,  kaon_P, kaon_PE, kaon_PX, kaon_PT, kaon_PY, kaon_PZ, kaon_ETA, kaon_IPCHI2_OWNPV, kaon_TRACK_GhostProb, kaon_ProbNNp, kaon_ProbNNk;
    double proton_M,  proton_P, proton_PE, proton_PT, proton_PX, proton_PY, proton_PZ, proton_ETA, proton_IPCHI2_OWNPV, proton_TRACK_GhostProb, proton_ProbNNp, proton_ProbNNk;
    double Jpsi_M, Jpsi_P, Jpsi_PE, Jpsi_PT, Jpsi_PX, Jpsi_PY, Jpsi_PZ, Jpsi_ETA;
    double muminus_M, muminus_P, muminus_PE, muminus_PT, muminus_PX, muminus_PY, muminus_PZ, muminus_ETA, muminus_ProbNNmu, muminus_TRACK_GhostProb;
    double muplus_M, muplus_P, muplus_PE, muplus_PT, muplus_PX, muplus_PY, muplus_PZ, muplus_ETA, muplus_ProbNNmu, muplus_TRACK_GhostProb;
    double Lambda_b0_DTF_MASS_constr1, Lambda_b0_DTF_CHI2NDOF, Lambda_b0_IPCHI2_OWNPV;
    double Lambda_b0_FDS, Lambda_b0_PT; 
    
    bool Lambda_b0_L0MuonDecision_TOS, Lambda_b0_L0DiMuonDecision_TOS;
    bool Lambda_b0_Hlt1DiMuonHighMassDecision_TOS, Lambda_b0_Hlt1DiMuonLowMassDecision_TOS;
    bool Lambda_b0_Hlt1TrackMuonDecision_TOS, Lambda_b0_Hlt1TrackAllL0Decision_TOS;
    bool Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS, Lambda_b0_Hlt2DiMuonDetachedDecision_TOS, Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS;
    bool Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS;
    
  
    
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
    rTree1->SetBranchAddress("Lambda_b0_PT", &Lambda_b0_PT);

    
    //for MC only                                                                   //
    int Jpsi_BKGCAT, Lambda_b0_BKGCAT;                                              //
    rTree1->SetBranchAddress("Jpsi_BKGCAT", &Jpsi_BKGCAT);                          //
    rTree1->SetBranchAddress("Lambda_b0_BKGCAT", &Lambda_b0_BKGCAT);                //
    
    
    TFile* rFile = new TFile( outFilename.c_str() ,"RECREATE");
    TTree* rTree2 = new TTree();
    rTree2->SetName("DecayTree");

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
    rTree2->Branch("Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS, "Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS/B");
    rTree2->Branch("Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS", &Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS, "Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS/B");
    rTree2->Branch("Lambda_b0_PT", &Lambda_b0_PT, "Lambda_b0_PT/D");
                            
                                                 
    //for MC only                                                                   //
    rTree2->Branch("Jpsi_BKGCAT", &Jpsi_BKGCAT, "Jpsi_BKGCAT/I");                   //
    rTree2->Branch("Lambda_b0_BKGCAT", &Lambda_b0_BKGCAT, "Lambda_b0_BKGCAT/I");    //
    
    
//-----------------------------------------------------------------------------------    

    int percentCounter = 1;

    for(int i = 0; i < rTree1->GetEntries(); ++i){
  
      /*const int percent = (int)(rTree1->GetEntries()/100.0);
    
      if( i == percent*percentCounter ){
        //std::cout << percentCounter << " %" << std::endl;
        percentCounter++;
      }
      */
      rTree1->GetEntry(i);
      rTree2->Fill();
      //std::cout << mass << std::endl;   
    }
    rTree2->Print();
    rTree2->Write();
    rFile->Save();
    
    sw.Stop();
    sw.Print();
}















