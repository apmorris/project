void selectBackground(){ 

    // -- define tuple file name, tuple name and cuts to apply
    // -- and also the name of the output file
    
    const std::string filename = "/afs/cern.ch/work/a/apmorris/public/Lb2chicpK/signal_samples/Lb2chicpK_2011_2012_signal.root";
    const std::string outFilename("/afs/cern.ch/work/a/apmorris/public/Lb2chicpK/signal_samples/background.root");
        
    const std::string treename("Tuple/DecayTree");
 
    const std::string cuts = "Lambda_b0_DTF_MASS_constr1 > 5700. && Lambda_b0_DTF_MASS_constr1 < 5800.";
    
// Copy the tree --------------------------------------------------------------------
    
    std::cout << "Opening file: " << filename.c_str() << endl;
    
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
    tree->SetBranchStatus("*", 1);   
      
    double n_pre = tree->GetEntries();
    std::cout << "# of events in original tuple = " << n_pre << endl;  
      
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
    

    std::cout << "# of events in the background tuple = " << n_post << endl;


} 

