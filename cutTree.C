/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to apply manual cuts to the new data. 

*/


void cutTree(){ 

    // -- define tuple file name, tuple name and cuts to apply
    // -- and also the name of the output file
    
    const std::string filename = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/Lb2JpsipK_2011_2012_signal_withbdt.root";
    const std::string outFilename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/normalisation_samples/Lb2JpsipK_2011_2012_signal_withbdt_cut_05.root");
        
    const std::string treename("withbdt");
 
// Signal mode cuts -----------------------------------------------------------------

    //const std::string cuts = "Lambda_b0_DTF_MASS_constr1>5550 && Lambda_b0_DTF_MASS_constr1<5700 && Lambda_b0_DTF_CHI2NDOF<7 && Lambda_b0_DTF_CHI2NDOF>0 && Lambda_b0_IPCHI2_OWNPV<25 && Lambda_b0_FDS>10 && kaon_IPCHI2_OWNPV>4 && proton_IPCHI2_OWNPV>4 && gamma_CL>0.03 && chi_c_M>3400 && chi_c_M<3700 && muplus_TRACK_GhostProb<0.3 && muminus_TRACK_GhostProb<0.3 && kaon_TRACK_GhostProb<0.3 && proton_TRACK_GhostProb<0.3 && min(muplus_ProbNNmu,muminus_ProbNNmu)>0.1 && (Lambda_b0_L0MuonDecision_TOS==1||Lambda_b0_L0DiMuonDecision_TOS==1) &&(Lambda_b0_Hlt1DiMuonHighMassDecision_TOS==1||Lambda_b0_Hlt1DiMuonLowMassDecision_TOS==1||Lambda_b0_Hlt1TrackMuonDecision_TOS==1||Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS==1||Lambda_b0_Hlt1TrackAllL0Decision_TOS==1) &&(Lambda_b0_Hlt2DiMuonDetachedDecision_TOS==1||Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS==1||Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS==1) && Lambda_b0_pi0veto==1";

    //for MC
    //const std::string cuts = "Lambda_b0_DTF_MASS_constr1>5550 && Lambda_b0_DTF_MASS_constr1<5700 && Lambda_b0_DTF_CHI2NDOF<7 && Lambda_b0_DTF_CHI2NDOF>0 && Lambda_b0_IPCHI2_OWNPV<25 && Lambda_b0_FDS>10 && kaon_IPCHI2_OWNPV>4 && proton_IPCHI2_OWNPV>4 && gamma_CL>0.03 && chi_c_M>3400 && chi_c_M<3700 && muplus_TRACK_GhostProb<0.3 && muminus_TRACK_GhostProb<0.3 && kaon_TRACK_GhostProb<0.3 && proton_TRACK_GhostProb<0.3 && min(muplus_ProbNNmu,muminus_ProbNNmu)>0.1 && (Lambda_b0_L0MuonDecision_TOS==1||Lambda_b0_L0DiMuonDecision_TOS==1) &&(Lambda_b0_Hlt1DiMuonHighMassDecision_TOS==1||Lambda_b0_Hlt1DiMuonLowMassDecision_TOS==1||Lambda_b0_Hlt1TrackMuonDecision_TOS==1||Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS==1||Lambda_b0_Hlt1TrackAllL0Decision_TOS==1) &&(Lambda_b0_Hlt2DiMuonDetachedDecision_TOS==1||Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS==1||Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS==1) && Lambda_b0_pi0veto==1 && kaon_ProbNNk > 0.3 && proton_ProbNNp > 0.3 && chi_c_BKGCAT==0 && (Lambda_b0_BKGCAT==0||Lambda_b0_BKGCAT==10||Lambda_b0_BKGCAT==50)";  
    
    
    
// Normalisation mode cuts ----------------------------------------------------------
    
    //const std::string cuts = "Lambda_b0_DTF_MASS_constr1>5550 && Lambda_b0_DTF_MASS_constr1<5700 && Lambda_b0_DTF_CHI2NDOF<6 && Lambda_b0_IPCHI2_OWNPV<15 && (Lambda_b0_L0MuonDecision_TOS==1||Lambda_b0_L0DiMuonDecision_TOS==1) &&(Lambda_b0_Hlt1DiMuonHighMassDecision_TOS==1||Lambda_b0_Hlt1DiMuonLowMassDecision_TOS==1||Lambda_b0_Hlt1TrackMuonDecision_TOS==1||Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS==0||Lambda_b0_Hlt1TrackAllL0Decision_TOS==1) &&(Lambda_b0_Hlt2DiMuonDetachedDecision_TOS==1 || Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS==1 || Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS==1)  &&  kaon_TRACK_GhostProb<0.1 && kaon_ProbNNk > 0.3 &&  proton_TRACK_GhostProb<0.1 && proton_ProbNNp > 0.3 && Jpsi_M >3000 && Jpsi_M < 3200 && min(muplus_ProbNNmu,muminus_ProbNNmu)>0.2 && muplus_TRACK_GhostProb<0.1 && muminus_TRACK_GhostProb<0.1";
    
    //for MC
    //const std::string cuts = "Lambda_b0_DTF_MASS_constr1>5550 && Lambda_b0_DTF_MASS_constr1<5700 && Lambda_b0_DTF_CHI2NDOF<6 && Lambda_b0_IPCHI2_OWNPV<15 && (Lambda_b0_L0MuonDecision_TOS==1||Lambda_b0_L0DiMuonDecision_TOS==1) &&(Lambda_b0_Hlt1DiMuonHighMassDecision_TOS==1||Lambda_b0_Hlt1DiMuonLowMassDecision_TOS==1||Lambda_b0_Hlt1TrackMuonDecision_TOS==1||Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS==0||Lambda_b0_Hlt1TrackAllL0Decision_TOS==1) &&(Lambda_b0_Hlt2DiMuonDetachedDecision_TOS==1|| Lambda_b0_Hlt2DiMuonDetachedJPsiDecision_TOS==1||Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS==1)  && kaon_TRACK_GhostProb<0.1 && kaon_ProbNNk > 0.3 && proton_TRACK_GhostProb<0.1 && proton_ProbNNp > 0.3 && Jpsi_M >3000 && Jpsi_M < 3200 && min(muplus_ProbNNmu,muminus_ProbNNmu)>0.2 && muplus_TRACK_GhostProb<0.1 && muminus_TRACK_GhostProb<0.1 && Jpsi_BKGCAT==0 && (Lambda_b0_BKGCAT==0||Lambda_b0_BKGCAT==10||Lambda_b0_BKGCAT==50)";
    
    
    
// BDT cuts ------------------------------------------------------------------------- 
    
    //const std::string cuts = "bdtg>=0.8";
    const std::string cuts = "bdtg3>=0.5";
    
// Copy the tree --------------------------------------------------------------------
    
    std::cout << "Opening file: " << filename.c_str() << endl;
    
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
    tree->SetBranchStatus("*", 1);   
      
    double n_pre = tree->GetEntries();
    std::cout << "# of events in original tree = " << n_pre << endl;  
      
    // -- this file is just here to make the 'CopyTree' happy
    
    std::cout << "Copying tree: " << treename.c_str() << endl;
    
    TFile* newFile = new TFile(outFilename.c_str(),"RECREATE");
    TTree* rTree1 = tree->CopyTree( cuts.c_str() );
    
    /*int percentCounter = 1;

    for(int i = 0; i < tree->GetEntries(); ++i){
  
      const int percent = (int)(tree->GetEntries()/100.0);
    
      if( i == percent*percentCounter ){
        //std::cout << percentCounter << " %" << std::endl;
        percentCounter++;
      }
      
      //tree->GetEntry(i);
      //rTree1->Fill();
      //std::cout << mass << std::endl;   
    }*/
    //rTree1->Print();
    rTree1->Write();
    newFile->Save();

    
    double n_post = rTree1->GetEntries();
    

    std::cout << "# of events in the tree with cuts applied = " << n_post << endl;


} 






