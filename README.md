# Scripts used in Lb2chicpK analysis with LHCb

## Run in the following order:

##### 1. cutTree.C
Applies preselection to all data sets - the comments indicate which string of cuts to use for which data set.

##### 2. newReduceTree.C / newReduceTree_norm.C
Reduces the number of branches to make the ntuples more manageable. (I need to check that I keep all the necessary branches here, and also add loop to make new branches which are combinations of particles eg. chi_c + proton, and mis-id'd particles - this will make it easier to look at these later on rather than having lots of individual scripts.)

##### 3. fit_MC.C / fit_MC_norm.C 
Applies a fit to the simulated data sample after the preselection has been applied to it. The fit parameters from this go into the fit_and_weights script.

##### 4. selectBackground.C
Applies cuts to select the high mass sideband of the signal dataset for use in the BDT training.

##### 5. ZTMVAClassification.C / ZTMVAClassification_norm.C
Trains the BDT algorithms using the high mass sideband of the signal dataset and the simulated signal dataset with the preselection applied. Should be run in the directory where the datasets are stored to make sure the weights files are added there.

At this point, open TMVA.root using TMVAGui to save plots showing the performance of the BDT, then choose the best algorithm from the ROC curve.

##### 6. ZTMVAClassificationApplication.C (or _MC.C or _norm.C)
Applies the trained BDT algorithms to the signal/MC/normalisation dataset. Should be run in the directory where each dataset is stored to make sure the weights files are read in correctly.

##### 7. BDT_cuts.C / BDT_cuts_norm.C
Makes the figure of merit for the chosen BDT algorithm so we can find the best point to cut at. There are scripts for both S/sqrt(S+B) and the Punzi FOM in here.

##### 8. fit_and_weights.C / fit_and_weights_norm.C
Performs a fit to the chicpK/JpsipK mass distribution using the chosen ntuple and the values from the fit_MC results. Vetoes can be applied in here once the new branches are added into the newReduceTree script.



## Other scripts:

##### effCalc.C
Includes some code to calculate efficiencies.

##### PID_misidentification.C
Made new branches containing chicpK invariant masses assuming misidentified protons.

##### mass_additions.C
Made new branches with mass combinations such as chic+proton and proton+kaon.

##### fit_chi_c2.C
Haven't used this yet. Will be for fitting the _constr2 chicpK mass.

##### no_photon.C
Plots mass(Jpsi+proton+kaon).

##### plotting.C
General plotting script.

## Other files:

##### notes.txt, method_log.txt, refitting_results.txt
Contain various results and notes from running scripts.
