#define AnaScript_cxx
#include "AnaScript.h"
#include <set>
#include <utility>
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//Setup Function Scripts
#include "Setup_Scripts/BookHistograms.h"
#include "Setup_Scripts/CustomFunctions.h"
#include "Setup_Scripts/ProduceGenCollection.h"
#include "Setup_Scripts/ProduceRecoCollection.h"

//Control Region Functions
#include "CR_Scripts/CR_WZ.h"
#include "CR_Scripts/CR_ZZ.h"
#include "CR_Scripts/CR_ZG.h"
#include "CR_Scripts/CR_DY.h"
#include "CR_Scripts/CR_MisID.h"
#include "CR_Scripts/CR_MisID_4L.h"
#include "CR_Scripts/CR_Test.h"

//PromptRates
#include "ScaleFactor_Scripts/promptRate_2022.h"
#include "ScaleFactor_Scripts/promptRate_2018.h"
#include "ScaleFactor_Scripts/promptRate_2017.h"
#include "ScaleFactor_Scripts/promptRate_2023.h"
#include "ScaleFactor_Scripts/promptRate_2016.h"

//FakeRates
#include "ScaleFactor_Scripts/fakeRate_2022.h"
#include "ScaleFactor_Scripts/fakeRate_2018.h"
#include "ScaleFactor_Scripts/fakeRate_2017.h"
#include "ScaleFactor_Scripts/fakeRate_2023.h"
#include "ScaleFactor_Scripts/fakeRate_2016.h"

//Leptonic SF
#include "ScaleFactor_Scripts/scalefactor_Run3Summer22.h"
#include "ScaleFactor_Scripts/scalefactor_Run3Summer22EE.h"
#include "ScaleFactor_Scripts/scalefactor_Run3Summer23.h"
#include "ScaleFactor_Scripts/scalefactor_Run3Summer23BPix.h"
#include "ScaleFactor_Scripts/scalefactor_UL18.h"
#include "ScaleFactor_Scripts/scalefactor_UL17.h"
#include "ScaleFactor_Scripts/scalefactor_UL16preVFP.h"
#include "ScaleFactor_Scripts/scalefactor_UL16postVFP.h"
#include "ScaleFactor_Scripts/ApplyScaleFactors.h"

//Trigger
#include "ScaleFactor_Scripts/TriggerEfficiencyScaleFactor.h"
#include "ScaleFactor_Scripts/SingleMuonTriggerEfficiencyScaleFactor.h"
#include "ScaleFactor_Scripts/SingleElectronTriggerEfficiencyScaleFactor.h"

//bTagging
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2023BPix.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2023.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2022EE.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2022.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2018.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2017.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2016preVFP.h"
#include "ScaleFactor_Scripts/JetEffFunction_DeepJet_2016postVFP.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_Run3Summer22.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_Run3Summer22EE.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_Run3Summer23.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_Run3Summer23BPix.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_UL18.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_UL17.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_UL16preVFP.h"
#include "ScaleFactor_Scripts/scalefactor_bTagJets_UL16postVFP.h"

void AnaScript::Begin(TTree * /*tree*/)
{
  TString option = GetOption();
}

void AnaScript::SlaveBegin(TTree * /*tree*/)
{
  time(&start);

  TString option = GetOption();
  nEvtTotal = 0;
  nEvtRan = 0;
  nEvtTrigger= 0;
  nEvtBad = 0;
  //nEvtSkim = 0;
  n_l2OS = 0;
  n_l2SS = 0;
  n_l3 = 0;
  n_l4 = 0;
  n_l12j = 0;
  
  //loadGoodLumis("good_lumis_2023.txt");
  //loadGoodLumis("good_lumis_2022.txt");
  loadGoodLumis("good_lumis_2018.txt");
  //loadGoodLumis("good_lumis_2017.txt");
  //loadGoodLumis("good_lumis_2016.txt");
  
  _HstFile = new TFile(_HstFileName,"recreate");
  //Call the function to book the histograms we declared in Hists.
  BookHistograms();
}

void AnaScript::SlaveTerminate()
{
  _HstFile->Write();
  _HstFile->Close();

  float goodevtfrac = ((float)nEvtRan)/((float)nEvtTotal);
  float trigevtfrac = ((float)nEvtTrigger)/((float)nEvtTotal);

  cout<<"---------------------------------------------"<<endl;
  cout<<"Summary:"<<endl;
  cout<<"Total events = "<<nEvtTotal<<endl;
  cout<<"Total events ran = "<<nEvtRan<<" ("<<goodevtfrac*100<<" %)"<<endl;
  cout<<"Total Triggered events = "<<nEvtTrigger<<" ("<<trigevtfrac*100<<" %)"<<endl;
  if(_flag == "doublet")
    cout<<"Total discarded events for VLL Doublet = "<<nEvtBad<<endl;
  cout<<"---------------------------------------------"<<endl;
  cout<<"-----------------------------------------------"<<endl;
  cout<<"               Event Selection                 "<<endl;
  cout<<"-----------------------------------------------"<<endl;
  cout<<"Events with 4 or more Light Leptons = "<<n_l4<<endl;
  cout<<"Events with 3 Light Leptons         = "<<n_l3<<endl;
  cout<<"Events with 2LSS Light Leptons      = "<<n_l2SS<<endl;
  cout<<"Events with 2LOS Light Leptons      = "<<n_l2OS<<endl;
  cout<<"Events with 1L2J Final state        = "<<n_l12j<<endl;
  
  time(&end);

  double time_taken = double(end-start);
  cout<<"Time taken by the program is= "<<fixed<<time_taken<<setprecision(5);
  cout<<"sec"<<endl;
}

void AnaScript::Terminate()
{}

Bool_t AnaScript::Process(Long64_t entry)
{
  //Initializing fReaders:
  fReader.SetLocalEntry(entry);
  if(_run3)
    fReader_Run3.SetLocalEntry(entry);
  else
    fReader_Run2.SetLocalEntry(entry);
  if(_data == 0){
    fReader_MC.SetLocalEntry(entry);
    if(!_run3)
      fReader_Run2_MC.SetLocalEntry(entry);
    else
      fReader_Run3_MC.SetLocalEntry(entry);
  }  
  
  if(_verbosity==0 && nEvtTotal%1000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;      
  else if(_verbosity>0 && nEvtTotal%100000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;

  nEvtTotal++;
  h.nevt->Fill(0);

  GoodEvt2022 = (_year==2022 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt3022 = (_year==3022 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2023 = (_year==2023 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt3023 = (_year==3023 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2018 = (_year==2018 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2017 = (_year==2017 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt2016 = (_year==2016 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  GoodEvt3016 = (_year==3016 ? *Flag_goodVertices && *Flag_globalSuperTightHalo2016Filter && *Flag_HBHENoiseFilter && *Flag_HBHENoiseIsoFilter && *Flag_EcalDeadCellTriggerPrimitiveFilter && (_data ? *Flag_eeBadScFilter : 1) : 1);
  
  GoodEvt = GoodEvt2016 && GoodEvt3016 && GoodEvt2017 && GoodEvt2018 && GoodEvt2022 && GoodEvt3022 && GoodEvt2023 && GoodEvt3023;

  if(GoodEvt){
    nEvtRan++; //only good events
    h.nevt->Fill(1);
    h.acceptance[0]->Fill(0);
    h.acceptance[1]->Fill(0);
    h.acceptance[2]->Fill(0);
    h.acceptance[3]->Fill(0);

    triggerRes=true; //Always true for MC
    if(_data==1){
      triggerRes=false;
      bool muon_trigger = false;
      bool electron_trigger = false;

      //Run2 Trigger Paths
      //2016
      /*if(_year == 2016 || _year == 3016){
	muon_trigger = (*HLT_IsoMu24==1) || (*HLT_IsoTkMu24==1);
	electron_trigger = (*HLT_Ele27_WPTight_Gsf==1);
	}*/
	
      //2017
      /*if(_year==2017){
	muon_trigger = (*HLT_IsoMu27==1);
	electron_trigger = (*HLT_Ele32_WPTight_Gsf_L1DoubleEG==1);
	}*/

      //2018
      /*if(_year==2018){
	muon_trigger = (*HLT_IsoMu24==1); 
	electron_trigger = (*HLT_Ele32_WPTight_Gsf==1);
	}*/
      
      //Run3 Trigger Paths
      /*if(_year==2022 || _year == 3022 || _year == 2023 || _year == 3023){
	muon_trigger     = (*HLT_IsoMu24==1); 
	electron_trigger = (*HLT_Ele32_WPTight_Gsf==1);
	}*/
      
      /*if(_sample == 1000 || _sample == 1001 || _sample == 1002 || _sample == 1003 || _sample == 1004)
	triggerRes = muon_trigger;
	if(_sample == 1100 || _sample == 1101 || _sample == 1102 || _sample == 1103 || _sample == 1104)
	triggerRes = electron_trigger && !muon_trigger;*/
	
      triggerRes = electron_trigger || muon_trigger;
    }
    
    if(triggerRes){
      nEvtTrigger++; //only triggered events
      h.nevt->Fill(2);

      /*******************************************************
       *               Gen particle block                    *
       *******************************************************/   
      //Clearing the Gen Arrays
      bool bad_event = false;
      if(_data == 0){
	genMuon.clear();
	genElectron.clear();
	genPhoton.clear();
	genLightLepton.clear();
	vllep.clear();
	vlnu.clear();
	
	GenMuon();
	GenElectron();
	GenPhoton();
	createSignalArrays();
	
	//Sorting the Gen Arrays
	SortGenObjects();
	SortVLL();
	
	//Correcting the Doublet model (flagging out the invalid decays)
	if(_flag == "doublet"){ //for VLLD files
	  for(int i=0; i<(int)vlnu.size(); i++){
	    for(int j=0; j<(int)vlnu.at(i).dauid.size(); j++){
	      if(fabs(vlnu.at(i).dauid[j]) == 25)      
		bad_event = true;
	      else if(fabs(vlnu.at(i).dauid[j]) == 23)
		bad_event = true;
	    }
	  }
	  //b) The lepton cannot decay to a W,nu of the corresponding flavor (ele/mu):
	  // I am flagging out the events with W(24) as daughetrs of L
	  for(int i=0; i<(int)vllep.size(); i++){
	    for(int j=0; j<(int)vllep.at(i).dauid.size(); j++){
	      if(fabs(vllep.at(i).dauid[j]) == 24)
		bad_event = true;
	    }
	  }
	}
      }
      //Counting bad events:
      if(!bad_event){
	h.nevt->Fill(3);
      }
      
      /*******************************************************
       *               Reco particle block                   *
       *******************************************************/   
      Muon.clear();
      Electron.clear();
      LightLepton.clear();
      LooseLep.clear();
      loosellep.clear();
      looseMuon.clear();
      looseEle.clear();
      Jets.clear();
      MisIDJets.clear();
      MisIDbJets.clear();
      bJets.clear();
  
      //Calling the function that consists the electron and muons block
      createLightLeptons();
      createJets();
      createMisIDJets();
      
      //Sorting the arrays
      SortRecoObjects();

      //Light Lepton Plots
      h.llep[0]->Fill((int)LightLepton.size());
      h.llep[1]->Fill((int)loosellep.size());

      
      //ELectrons
      h.ele[0]->Fill((int)Electron.size());
      for(int i=0; i<(int)Electron.size(); i++){
	h.ele[1]->Fill(Electron.at(i).v.Pt());
	h.ele[2]->Fill(Electron.at(i).v.Eta());
	h.ele[3]->Fill(Electron.at(i).v.Phi());
      }
      if((int)Electron.size()>1){
	h.ele[4]->Fill(Electron.at(0).v.Pt());
	h.ele[5]->Fill(Electron.at(0).v.Eta());
	h.ele[6]->Fill(Electron.at(0).v.Phi());
	h.ele[7]->Fill(Electron.at(1).v.Pt());
	h.ele[8]->Fill(Electron.at(1).v.Eta());
	h.ele[9]->Fill(Electron.at(1).v.Phi());
	h.ele[10]->Fill(delta_phi(Electron.at(0).v.Phi(),*PuppiMET_phi));
	h.ele[11]->Fill(delta_phi(Electron.at(1).v.Phi(),*PuppiMET_phi));
      }
      
      //Muons
      h.mu[0]->Fill((int)Muon.size());
      for(int i=0; i<(int)Muon.size(); i++){
	h.mu[1]->Fill(Muon.at(i).v.Pt());
	h.mu[2]->Fill(Muon.at(i).v.Eta());
	h.mu[3]->Fill(Muon.at(i).v.Phi());
      }
      if((int)Muon.size()>1){
	h.mu[4]->Fill(Muon.at(0).v.Pt());
	h.mu[5]->Fill(Muon.at(0).v.Eta());
	h.mu[6]->Fill(Muon.at(0).v.Phi());
	h.mu[7]->Fill(Muon.at(1).v.Pt());
	h.mu[8]->Fill(Muon.at(1).v.Eta());
	h.mu[9]->Fill(Muon.at(1).v.Phi());
	h.mu[10]->Fill(delta_phi(Muon.at(0).v.Phi(),*PuppiMET_phi));
	h.mu[11]->Fill(delta_phi(Muon.at(1).v.Phi(),*PuppiMET_phi));
      }

      //Jets
      h.jet[0]->Fill((int)Jets.size());
      h.jet[1]->Fill((int)bJets.size());
      for(int i=0; i<(int)Jets.size(); i++){
	h.jet[2]->Fill(Jets.at(i).v.Pt());
      }
      for(int i=0; i<(int)bJets.size(); i++){
	h.jet[3]->Fill(bJets.at(i).v.Pt());
      }
      
      //PuppiMET
      h.met[0]->Fill(*PuppiMET_pt);
      h.met[1]->Fill(*PuppiMET_phi);

      /***********************************************************************************
       *                                 Analysis block                                  *
       ***********************************************************************************/
      
      /*************************************
       *         Trigger Definition        *
       *************************************/
      is_l3_MisID_event = false;
      is_l4_MisID_event = false;
      is_l2SS_event     = false;
      is_l2OS_event     = false;
      is_l12j_event     = false;
      is_l3_event       = false;
      is_l4_event       = false;
      evt_trigger       = false;
      
      //4L Inclusive
      if((int)LightLepton.size() > 3){
	for(int i=0; i<(int)LightLepton.size(); i++){
	  if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	  if(_year == 2017){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	      evt_trigger = true;
	  }
	  if(_year == 2016 || _year == 3016){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 30)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	}
	if(evt_trigger){
	  if((LightLepton.at(0).v+LightLepton.at(1).v).M() > 12){
	    if((LightLepton.at(0).v+LightLepton.at(2).v).M() > 12){
	      if((LightLepton.at(0).v+LightLepton.at(3).v).M() > 12){
		if((LightLepton.at(1).v+LightLepton.at(2).v).M() > 12){
		  if((LightLepton.at(1).v+LightLepton.at(3).v).M() > 12){
		    if((LightLepton.at(2).v+LightLepton.at(3).v).M() > 12){
		      if(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v) > 0.2){
			if(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v) > 0.2){
			  if(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v) > 0.2){
			    if(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v) > 0.2){
			      if(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v) > 0.2){
				if(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v) > 0.2){
				  is_l4_event = true;
				  n_l4++;
				  h.acceptance[0]->Fill(1);
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }

      //4L Inclusive
      if((int)LooseLep.size() > 3){
	for(int i=0; i<(int)LooseLep.size(); i++){
	  if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	    if(fabs(LooseLep.at(i).id) == 11 && LooseLep.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LooseLep.at(i).id) == 13 && LooseLep.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	  if(_year == 2017){
	    if(fabs(LooseLep.at(i).id) == 11 && LooseLep.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LooseLep.at(i).id) == 13 && LooseLep.at(i).v.Pt() > 29)
	      evt_trigger = true;
	  }
	  if(_year == 2016 || _year == 3016){
	    if(fabs(LooseLep.at(i).id) == 11 && LooseLep.at(i).v.Pt() > 30)
	      evt_trigger = true;
	    if(fabs(LooseLep.at(i).id) == 13 && LooseLep.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	}
	if(evt_trigger){
	  if((LooseLep.at(0).v+LooseLep.at(1).v).M() > 12){
	    if((LooseLep.at(0).v+LooseLep.at(2).v).M() > 12){
	      if((LooseLep.at(0).v+LooseLep.at(3).v).M() > 12){
		if((LooseLep.at(1).v+LooseLep.at(2).v).M() > 12){
		  if((LooseLep.at(1).v+LooseLep.at(3).v).M() > 12){
		    if((LooseLep.at(2).v+LooseLep.at(3).v).M() > 12){
		      if(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v) > 0.2){
			if(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v) > 0.2){
			  if(LooseLep.at(0).v.DeltaR(LooseLep.at(3).v) > 0.2){
			    if(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v) > 0.2){
			      if(LooseLep.at(1).v.DeltaR(LooseLep.at(3).v) > 0.2){
				if(LooseLep.at(2).v.DeltaR(LooseLep.at(3).v) > 0.2){
				  is_l4_MisID_event = true;
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
      
      //Exactly 3L
      if((int)LightLepton.size() == 3){
	for(int i=0; i<(int)LightLepton.size(); i++){
	  if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	  if(_year == 2017){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	      evt_trigger = true;
	  }
	  if(_year == 2016 || _year == 3016){
	    if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 30)
	      evt_trigger = true;
	    if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	}
	if(evt_trigger){
	  if((LightLepton.at(0).v+LightLepton.at(1).v).M() > 12){
	    if((LightLepton.at(0).v+LightLepton.at(2).v).M() > 12){
	      if((LightLepton.at(1).v+LightLepton.at(2).v).M() > 12){
  		if(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v) > 0.2){
		  if(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v) > 0.2){
		    if(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v) > 0.2){
		      is_l3_event = true;
		      n_l3++;
		      h.acceptance[0]->Fill(2);
		    }
		  }
		}
	      }
	    }
	  }
	}
      }

      //Exactly 3L: MisID
      if((int)LooseLep.size() == 3){
	for(int i=0; i<(int)LooseLep.size(); i++){
	  if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	    if(fabs(LooseLep.at(i).id) == 11 && LooseLep.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LooseLep.at(i).id) == 13 && LooseLep.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	  if(_year == 2017){
	    if(fabs(LooseLep.at(i).id) == 11 && LooseLep.at(i).v.Pt() > 35)
	      evt_trigger = true;
	    if(fabs(LooseLep.at(i).id) == 13 && LooseLep.at(i).v.Pt() > 29)
	      evt_trigger = true;
	  }
	  if(_year == 2016 || _year == 3016){
	    if(fabs(LooseLep.at(i).id) == 11 && LooseLep.at(i).v.Pt() > 30)
	      evt_trigger = true;
	    if(fabs(LooseLep.at(i).id) == 13 && LooseLep.at(i).v.Pt() > 26)
	      evt_trigger = true;
	  }
	}
	if(evt_trigger){
	  if((LooseLep.at(0).v+LooseLep.at(1).v).M() > 12){
	    if((LooseLep.at(0).v+LooseLep.at(2).v).M() > 12){
	      if((LooseLep.at(1).v+LooseLep.at(2).v).M() > 12){
  		if(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v) > 0.2){
		  if(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v) > 0.2){
		    if(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v) > 0.2){
		      is_l3_MisID_event = true;
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
      
      //2L SS
      if((int)LightLepton.size()==2){
	if((LightLepton.at(0).id)*(LightLepton.at(1).id) == 169 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == 121 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == 143){
	  for(int i=0; i<(int)LightLepton.size(); i++){
	    if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
		evt_trigger = true;
	    }
	    if(_year == 2017){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
		evt_trigger = true;
	    }
	    if(_year == 2016 || _year == 3016){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 30)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
		evt_trigger = true;
	    }
	  }
	  if(evt_trigger){
	    if((LightLepton.at(0).v+LightLepton.at(1).v).M() > 12){
	      if(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v) > 0.2){
		is_l2SS_event = true;
		n_l2SS++;
		h.acceptance[0]->Fill(3);
	      }
	    }
	  }
	}
      }

      //2L OS
      if((int)LightLepton.size()==2){
	if((LightLepton.at(0).id)*(LightLepton.at(1).id) == -169 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == -121 || (LightLepton.at(0).id)*(LightLepton.at(1).id) == -143){
	  for(int i=0; i<(int)LightLepton.size(); i++){
	    if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
		evt_trigger = true;
	    }
	    if(_year == 2017){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 35)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
		evt_trigger = true;
	    }
	    if(_year == 2016 || _year == 3016){
	      if(fabs(LightLepton.at(i).id) == 11 && LightLepton.at(i).v.Pt() > 30)
		evt_trigger = true;
	      if(fabs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
		evt_trigger = true;
	    }
	  }
	  if(evt_trigger){	  
	    if((LightLepton.at(0).v+LightLepton.at(1).v).M() > 12){
	      if(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v) > 0.2){
		is_l2OS_event = true;
		n_l2OS++;
		h.acceptance[0]->Fill(4);
	      }
	    }	
	  }
	}
      }
      
      //1L2J
      else if((int)LightLepton.size()==1 && (int)Jets.size()>1){
	if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	  if(fabs(LightLepton.at(0).id) == 11 && LightLepton.at(0).v.Pt() > 35)
	    evt_trigger = true;
	  if(fabs(LightLepton.at(0).id) == 13 && LightLepton.at(0).v.Pt() > 26)
	    evt_trigger = true;
	}
	if(_year == 2017){
	  if(fabs(LightLepton.at(0).id) == 11 && LightLepton.at(0).v.Pt() > 35)
	    evt_trigger = true;
	  if(fabs(LightLepton.at(0).id) == 13 && LightLepton.at(0).v.Pt() > 29)
	    evt_trigger = true;
	}
	if(_year == 2016 || _year == 3016){
	  if(fabs(LightLepton.at(0).id) == 11 && LightLepton.at(0).v.Pt() > 30)
	    evt_trigger = true;
	  if(fabs(LightLepton.at(0).id) == 13 && LightLepton.at(0).v.Pt() > 26)
	    evt_trigger = true;
	}
	if(evt_trigger){	  
	  is_l12j_event = true;
	  n_l12j++;
	  h.acceptance[0]->Fill(5);
	}
      }

      //Filling Event level variable
      LT=0.0;
      LT_PuppiMET = 0.0;
      HT = 0.0;
      ST = 0.0;
      if((int)LightLepton.size()>0){
	for(int i=0; i<(int)LightLepton.size(); i++)
	  LT += LightLepton.at(i).v.Pt();
	LT_PuppiMET = LT + *PuppiMET_pt;
      }
      if((int)Jets.size()>0){
	for(int k=0; k<(int)Jets.size(); k++)
	  HT += Jets.at(k).v.Pt();
      }
      ST = LT_PuppiMET + HT;
      
      //Filling Event level variable: MisID
      LT_MisID = 0.0;
      LT_PuppiMET_MisID = 0.0;
      HT_MisID = 0.0;
      ST_MisID = 0.0;
      if((int)LooseLep.size()>0){
	for(int i=0; i<(int)LooseLep.size(); i++){
	  LT_MisID += LooseLep.at(i).v.Pt();
	}
      	LT_PuppiMET_MisID = LT_MisID + *PuppiMET_pt;
      }
      if((int)Jets.size()>0){
	for(int k=0; k<(int)Jets.size(); k++)
	  HT_MisID += Jets.at(k).v.Pt();
      }
      ST_MisID = LT_PuppiMET_MisID + HT_MisID;
      
      //Defining Booleans
      veto_WZ    = true;
      veto_ZZ    = true;
      veto_ZG    = true;
      veto_Test  = true;
      veto_MisID = true;
      
      //Defining the Control Regions
      /*CR_MisID_4L();
	CR_MisID();*/
      CR_Test();
      CR_ZG();
      CR_ZZ();
      CR_WZ();
      CR_DY();
	
      /*****************************************
       *             Scale Factors             *
       *****************************************/
      float EvtWeight = 1.0;
      float TriggerWeight = 1.0;
      
      //Run II 
      if(_data == 0 && !_run3){
	//Four Lepton Events
	if(is_l4_event){
	  if(_year == 2018){
	    TriggerWeight = 1-(1-TriggEff2018Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	    EvtWeight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL18(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2018(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	  if(_year == 2017){
	    TriggerWeight = 1-(1-TriggEff2017Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	    EvtWeight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL17(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2017(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	  if(_year == 2016){
	    TriggerWeight = 1-(1-TriggEff2016preVFPData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2016preVFPData(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	    EvtWeight = LeptonID_SFUL16preVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2016preVFP(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	  if(_year == 3016){
	    TriggerWeight = 1-(1-TriggEff2016postVFPData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2016postVFPData(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	    EvtWeight = LeptonID_SFUL16postVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2016postVFP(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	}

	//Three lepton events
	if(is_l3_event){
	  if(_year == 2018){
	    TriggerWeight = 1-(1-TriggEff2018Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	    EvtWeight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2018(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	  if(_year == 2017){
	    TriggerWeight = 1-(1-TriggEff2017Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	    EvtWeight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2017(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	  
	  if(_year == 2016){
	    TriggerWeight = 1-(1-TriggEff2016preVFPData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	    EvtWeight = LeptonID_SFUL16preVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2016preVFP(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	  if(_year == 3016){
	    TriggerWeight = 1-(1-TriggEff2016postVFPData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	    EvtWeight = LeptonID_SFUL16postVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2016postVFP(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.0;
	    //ZGamma Norm
	    if(_sample == 93)
	      EvtWeight = EvtWeight*1.0;
	  }
	}
      }

      //Run III 
      if(_data == 0 && _run3){
	//Four Lepton Events
	if(is_l4_event){
	  if(_year == 2022){
	    TriggerWeight = 1-(1-TriggEff2022Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2022Data(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	    EvtWeight = LeptonID_SFRun3Summer22(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSFRun3Summer2022(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.004;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.006;
	    //ZGamma Norm
	    if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948)
	      EvtWeight = EvtWeight*0.845;
	  }
	  if(_year == 3022){
	    TriggerWeight = 1-(1-TriggEff2022EEData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2022EEData(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	    EvtWeight = LeptonID_SFRun3Summer22EE(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSFRun3Summer2022EE(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0007;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*0.92;
	    //ZGamma Norm
	    if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948)
	      EvtWeight = EvtWeight*0.798;
	  }
	}

	//Three lepton events
	if(is_l3_event){
	  if(_year == 2022){
	    TriggerWeight = 1-(1-TriggEff2022Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	    EvtWeight = LeptonID_SFRun3Summer22(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2022(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.004;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*1.006;
	    //ZGamma Norm
	    if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948)
	      EvtWeight = EvtWeight*0.845;
	  }
	  if(_year == 3022){
	    TriggerWeight = 1-(1-TriggEff2022EEData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	    EvtWeight = LeptonID_SFRun3Summer22EE(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2022EE(_sample, Jets);
	    //ZZ Norm
	    if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 ||_sample == 25 ||_sample == 26)
	      EvtWeight = EvtWeight*1.0007;
	    //WZ Norm
	    if(_sample == 30 ||_sample == 31 ||_sample == 32)
	      EvtWeight = EvtWeight*0.92;
	    //ZGamma Norm
	    if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948)
	      EvtWeight = EvtWeight*0.798;
	  }
	}
      }
      
      /*****************************************************
       *             Event level variables: 4L             *
       *****************************************************/
      bool Bin1_4L = false;
      bool Bin2_4L = false;
      bool Bin3_4L = false;
      bool Bin4_4L = false;

      bool doublet_4L = false;
      //bool doublet_4L = true;
      bool singlet_4L = false;
      //bool singlet_4L = true;

      bool sig_4L  = false;
      //bool sig_4L = true;
	
      if(sig_4L){
	if(is_l4_event && !bad_event && veto_ZZ){
	  h.count[0]->Fill(1);
	  if((int)bJets.size() == 0){
	    h.count[1]->Fill(1);
	    if(doublet_4L){
	      if(LightLepton.at(0).v.Pt() > 200){
		if(*PuppiMET_pt > 100)
		  Bin1_4L = true;
		if(*PuppiMET_pt < 100)
		  Bin2_4L = true;
	      }
	      if(LightLepton.at(0).v.Pt() < 200){
		if(*PuppiMET_pt > 100)
		  Bin3_4L = true;
		if(*PuppiMET_pt < 100)
		  Bin4_4L = true;
	      }
	    }
	    if(singlet_4L){
	      if(*PuppiMET_pt > 150)
		Bin1_4L = true;
	      if(*PuppiMET_pt < 150)
		Bin2_4L = true;
	    }
	    
	    //------>Kinematics
	    h.hist_l4[0]->Fill((int)LightLepton.size(),EvtWeight);
	    h.hist_l4[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	    h.hist_l4[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	    h.hist_l4[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	    h.hist_l4[4]->Fill(LightLepton.at(3).v.Pt(),EvtWeight);
	    h.hist_l4[5]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	    h.hist_l4[6]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	    h.hist_l4[7]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	    h.hist_l4[8]->Fill(LightLepton.at(3).v.Eta(),EvtWeight);
	    h.hist_l4[9]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	    h.hist_l4[10]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	    h.hist_l4[11]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	    h.hist_l4[12]->Fill(LightLepton.at(3).v.Phi(),EvtWeight);
	    //------>Event Level Kinematics
	    h.hist_l4[13]->Fill(LT,EvtWeight);
	    h.hist_l4[14]->Fill(*PuppiMET_pt,EvtWeight);
	    h.hist_l4[15]->Fill(LT_PuppiMET,EvtWeight);
	    //------>Angular Variables
	    h.hist_l4[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	    h.hist_l4[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	    h.hist_l4[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	    h.hist_l4[19]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*PuppiMET_phi),EvtWeight);
	    h.hist_l4[20]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	    h.hist_l4[21]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	    h.hist_l4[22]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	    h.hist_l4[23]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	    h.hist_l4[24]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	    h.hist_l4[25]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	    //------>Transverse Mass
	    h.hist_l4[26]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	    h.hist_l4[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	    h.hist_l4[28]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	    h.hist_l4[29]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	    //------>DeltaR Plots
	    h.hist_l4[30]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	    h.hist_l4[31]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	    h.hist_l4[32]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	    h.hist_l4[33]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	    h.hist_l4[34]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	    h.hist_l4[35]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	    //Invariant Mass
	    h.hist_l4[36]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	    h.hist_l4[37]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	    h.hist_l4[38]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),EvtWeight);
	    h.hist_l4[39]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	    h.hist_l4[40]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),EvtWeight);
	    h.hist_l4[41]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),EvtWeight);
	    h.hist_l4[43]->Fill(ST,EvtWeight);
	    h.hist_l4[42]->Fill(HT,EvtWeight);
	    h.hist_l4[44]->Fill((int)bJets.size(),EvtWeight);
	    h.hist_l4[45]->Fill((int)Jets.size(),EvtWeight);
	    
	    //Binning Scheme
	    if(Bin1_4L){
	      h.hist_l4_Bin1[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l4_Bin1[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l4_Bin1[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l4_Bin1[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l4_Bin1[4]->Fill(LightLepton.at(3).v.Pt(),EvtWeight);
	      h.hist_l4_Bin1[5]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l4_Bin1[6]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l4_Bin1[7]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l4_Bin1[8]->Fill(LightLepton.at(3).v.Eta(),EvtWeight);
	      h.hist_l4_Bin1[9]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l4_Bin1[10]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l4_Bin1[11]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      h.hist_l4_Bin1[12]->Fill(LightLepton.at(3).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l4_Bin1[13]->Fill(LT,EvtWeight);
	      h.hist_l4_Bin1[14]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l4_Bin1[15]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l4_Bin1[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin1[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin1[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin1[19]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin1[20]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l4_Bin1[21]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin1[22]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin1[23]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin1[24]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin1[25]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l4_Bin1[26]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin1[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin1[28]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin1[29]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l4_Bin1[30]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l4_Bin1[31]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin1[32]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin1[33]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin1[34]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin1[35]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l4_Bin1[36]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l4_Bin1[37]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin1[38]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin1[39]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin1[40]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin1[41]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin1[43]->Fill(ST,EvtWeight);
	      h.hist_l4_Bin1[42]->Fill(HT,EvtWeight);
	      h.hist_l4_Bin1[44]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l4_Bin1[45]->Fill((int)Jets.size(),EvtWeight);
	    }
	    if(Bin2_4L){
	      h.hist_l4_Bin2[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l4_Bin2[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l4_Bin2[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l4_Bin2[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l4_Bin2[4]->Fill(LightLepton.at(3).v.Pt(),EvtWeight);
	      h.hist_l4_Bin2[5]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l4_Bin2[6]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l4_Bin2[7]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l4_Bin2[8]->Fill(LightLepton.at(3).v.Eta(),EvtWeight);
	      h.hist_l4_Bin2[9]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l4_Bin2[10]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l4_Bin2[11]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      h.hist_l4_Bin2[12]->Fill(LightLepton.at(3).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l4_Bin2[13]->Fill(LT,EvtWeight);
	      h.hist_l4_Bin2[14]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l4_Bin2[15]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l4_Bin2[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin2[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin2[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin2[19]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin2[20]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l4_Bin2[21]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin2[22]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin2[23]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin2[24]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin2[25]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l4_Bin2[26]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin2[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin2[28]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin2[29]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l4_Bin2[30]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l4_Bin2[31]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin2[32]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin2[33]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin2[34]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin2[35]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l4_Bin2[36]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l4_Bin2[37]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin2[38]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin2[39]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin2[40]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin2[41]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin2[43]->Fill(ST,EvtWeight);
	      h.hist_l4_Bin2[42]->Fill(HT,EvtWeight);
	      h.hist_l4_Bin2[44]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l4_Bin2[45]->Fill((int)Jets.size(),EvtWeight);
	    }
	    if(Bin3_4L){
	      h.hist_l4_Bin3[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l4_Bin3[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l4_Bin3[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l4_Bin3[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l4_Bin3[4]->Fill(LightLepton.at(3).v.Pt(),EvtWeight);
	      h.hist_l4_Bin3[5]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l4_Bin3[6]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l4_Bin3[7]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l4_Bin3[8]->Fill(LightLepton.at(3).v.Eta(),EvtWeight);
	      h.hist_l4_Bin3[9]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l4_Bin3[10]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l4_Bin3[11]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      h.hist_l4_Bin3[12]->Fill(LightLepton.at(3).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l4_Bin3[13]->Fill(LT,EvtWeight);
	      h.hist_l4_Bin3[14]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l4_Bin3[15]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l4_Bin3[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin3[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin3[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin3[19]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin3[20]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l4_Bin3[21]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin3[22]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin3[23]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin3[24]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin3[25]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l4_Bin3[26]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin3[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin3[28]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin3[29]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l4_Bin3[30]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l4_Bin3[31]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin3[32]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin3[33]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin3[34]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin3[35]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l4_Bin3[36]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l4_Bin3[37]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin3[38]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin3[39]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin3[40]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin3[41]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin3[43]->Fill(ST,EvtWeight);
	      h.hist_l4_Bin3[42]->Fill(HT,EvtWeight);
	      h.hist_l4_Bin3[44]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l4_Bin3[45]->Fill((int)Jets.size(),EvtWeight);
	    }
	    if(Bin4_4L){
	      h.hist_l4_Bin4[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l4_Bin4[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l4_Bin4[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l4_Bin4[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l4_Bin4[4]->Fill(LightLepton.at(3).v.Pt(),EvtWeight);
	      h.hist_l4_Bin4[5]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l4_Bin4[6]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l4_Bin4[7]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l4_Bin4[8]->Fill(LightLepton.at(3).v.Eta(),EvtWeight);
	      h.hist_l4_Bin4[9]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l4_Bin4[10]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l4_Bin4[11]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      h.hist_l4_Bin4[12]->Fill(LightLepton.at(3).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l4_Bin4[13]->Fill(LT,EvtWeight);
	      h.hist_l4_Bin4[14]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l4_Bin4[15]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l4_Bin4[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin4[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin4[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin4[19]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin4[20]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l4_Bin4[21]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin4[22]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin4[23]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l4_Bin4[24]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      h.hist_l4_Bin4[25]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l4_Bin4[26]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin4[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin4[28]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l4_Bin4[29]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l4_Bin4[30]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l4_Bin4[31]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin4[32]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin4[33]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l4_Bin4[34]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      h.hist_l4_Bin4[35]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l4_Bin4[36]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l4_Bin4[37]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin4[38]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin4[39]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l4_Bin4[40]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin4[41]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),EvtWeight);
	      h.hist_l4_Bin4[43]->Fill(ST,EvtWeight);
	      h.hist_l4_Bin4[42]->Fill(HT,EvtWeight);
	      h.hist_l4_Bin4[44]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l4_Bin4[45]->Fill((int)Jets.size(),EvtWeight);
	    }
	  }
	}
      }
      
      /*****************************************************
       *             Event level variables: 3L             *
       *****************************************************/
      bool Bin1_3L = false;
      bool Bin2_3L = false;
      bool Bin3_3L = false;
      bool Bin4_3L = false;
  
      bool doublet_3L = false;
      //bool doublet_3L = true;
      bool singlet_3L = false;
      //bool singlet_3L = true;

      bool sig_3L = false;
      //bool sig_3L = true;

      if(sig_3L){
	if(is_l3_event && !bad_event && veto_WZ && veto_MisID && veto_ZG && veto_Test){
	  h.count[2]->Fill(1);
	  if((int)bJets.size() == 0){
	    h.count[3]->Fill(1);
	    if(doublet_3L){
	      if((LightLepton.at(0).v+LightLepton.at(1).v).M() > 106){
		if(*PuppiMET_pt > 150)
		  Bin1_3L = true;
		if(*PuppiMET_pt < 150)
		  Bin2_3L = true;
	      }
	      if((LightLepton.at(0).v+LightLepton.at(1).v).M() < 106){
		if(*PuppiMET_pt > 150)
		  Bin3_3L = true;
		if(*PuppiMET_pt < 150)
		  Bin4_3L = true;
	      }
	    }
	    if(singlet_3L){
	      if(*PuppiMET_pt > 150)
		Bin1_3L = true;
	      if(*PuppiMET_pt < 150)
		Bin2_3L = true;
	    }
	    
	    //------>Kinematics
	    h.hist_l3[0]->Fill((int)LightLepton.size(),EvtWeight);
	    h.hist_l3[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	    h.hist_l3[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	    h.hist_l3[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	    h.hist_l3[4]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	    h.hist_l3[5]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	    h.hist_l3[6]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	    h.hist_l3[7]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	    h.hist_l3[8]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	    h.hist_l3[9]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	    //------>Event Level Kinematics
	    h.hist_l3[10]->Fill(LT,EvtWeight);
	    h.hist_l3[11]->Fill(*PuppiMET_pt,EvtWeight);
	    h.hist_l3[12]->Fill(LT_PuppiMET,EvtWeight);
	    //------>Angular Variables
	    h.hist_l3[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	    h.hist_l3[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	    h.hist_l3[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	    h.hist_l3[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	    h.hist_l3[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	    h.hist_l3[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	    //------>Transverse Mass
	    h.hist_l3[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	    h.hist_l3[20]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	    h.hist_l3[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	    //------>DeltaR Plots
	    h.hist_l3[22]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	    h.hist_l3[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	    h.hist_l3[24]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	    //Invariant Mass
	    h.hist_l3[25]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	    h.hist_l3[26]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	    h.hist_l3[27]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	    h.hist_l3[29]->Fill(ST,EvtWeight);
	    h.hist_l3[28]->Fill(HT,EvtWeight);
	    h.hist_l3[30]->Fill((int)bJets.size(),EvtWeight);
	    h.hist_l3[31]->Fill((int)Jets.size(),EvtWeight);
	   
	    //Binned Scheme
	    if(Bin1_3L){
	      h.hist_l3_Bin1[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l3_Bin1[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l3_Bin1[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l3_Bin1[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l3_Bin1[4]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l3_Bin1[5]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l3_Bin1[6]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l3_Bin1[7]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l3_Bin1[8]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l3_Bin1[9]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l3_Bin1[10]->Fill(LT,EvtWeight);
	      h.hist_l3_Bin1[11]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l3_Bin1[12]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l3_Bin1[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l3_Bin1[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin1[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin1[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin1[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin1[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l3_Bin1[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin1[20]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin1[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l3_Bin1[22]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l3_Bin1[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l3_Bin1[24]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l3_Bin1[25]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l3_Bin1[26]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin1[27]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin1[29]->Fill(ST,EvtWeight);
	      h.hist_l3_Bin1[28]->Fill(HT,EvtWeight);
	      h.hist_l3_Bin1[30]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l3_Bin1[31]->Fill((int)Jets.size(),EvtWeight);
	    }
	    if(Bin2_3L){
	      h.hist_l3_Bin2[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l3_Bin2[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l3_Bin2[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l3_Bin2[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l3_Bin2[4]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l3_Bin2[5]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l3_Bin2[6]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l3_Bin2[7]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l3_Bin2[8]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l3_Bin2[9]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l3_Bin2[10]->Fill(LT,EvtWeight);
	      h.hist_l3_Bin2[11]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l3_Bin2[12]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l3_Bin2[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l3_Bin2[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin2[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin2[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin2[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin2[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l3_Bin2[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin2[20]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin2[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l3_Bin2[22]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l3_Bin2[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l3_Bin2[24]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l3_Bin2[25]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l3_Bin2[26]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin2[27]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin2[29]->Fill(ST,EvtWeight);
	      h.hist_l3_Bin2[28]->Fill(HT,EvtWeight);
	      h.hist_l3_Bin2[30]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l3_Bin2[31]->Fill((int)Jets.size(),EvtWeight);
	    }
	    if(Bin3_3L){
	      h.hist_l3_Bin3[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l3_Bin3[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l3_Bin3[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l3_Bin3[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l3_Bin3[4]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l3_Bin3[5]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l3_Bin3[6]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l3_Bin3[7]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l3_Bin3[8]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l3_Bin3[9]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l3_Bin3[10]->Fill(LT,EvtWeight);
	      h.hist_l3_Bin3[11]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l3_Bin3[12]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l3_Bin3[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l3_Bin3[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin3[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin3[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin3[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin3[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l3_Bin3[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin3[20]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin3[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l3_Bin3[22]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l3_Bin3[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l3_Bin3[24]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l3_Bin3[25]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l3_Bin3[26]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin3[27]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin3[29]->Fill(ST,EvtWeight);
	      h.hist_l3_Bin3[28]->Fill(HT,EvtWeight);
	      h.hist_l3_Bin3[30]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l3_Bin3[31]->Fill((int)Jets.size(),EvtWeight);
	    }
	    if(Bin4_3L){
	      h.hist_l3_Bin4[0]->Fill((int)LightLepton.size(),EvtWeight);
	      h.hist_l3_Bin4[1]->Fill(LightLepton.at(0).v.Pt(),EvtWeight);
	      h.hist_l3_Bin4[2]->Fill(LightLepton.at(1).v.Pt(),EvtWeight);
	      h.hist_l3_Bin4[3]->Fill(LightLepton.at(2).v.Pt(),EvtWeight);
	      h.hist_l3_Bin4[4]->Fill(LightLepton.at(0).v.Eta(),EvtWeight);
	      h.hist_l3_Bin4[5]->Fill(LightLepton.at(1).v.Eta(),EvtWeight);
	      h.hist_l3_Bin4[6]->Fill(LightLepton.at(2).v.Eta(),EvtWeight);
	      h.hist_l3_Bin4[7]->Fill(LightLepton.at(0).v.Phi(),EvtWeight);
	      h.hist_l3_Bin4[8]->Fill(LightLepton.at(1).v.Phi(),EvtWeight);
	      h.hist_l3_Bin4[9]->Fill(LightLepton.at(2).v.Phi(),EvtWeight);
	      //------>Event Level Kinematics
	      h.hist_l3_Bin4[10]->Fill(LT,EvtWeight);
	      h.hist_l3_Bin4[11]->Fill(*PuppiMET_pt,EvtWeight);
	      h.hist_l3_Bin4[12]->Fill(LT_PuppiMET,EvtWeight);
	      //------>Angular Variables
	      h.hist_l3_Bin4[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),EvtWeight);
	      h.hist_l3_Bin4[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin4[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),EvtWeight);
	      h.hist_l3_Bin4[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin4[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin4[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),EvtWeight);
	      //------>Transverse Mass
	      h.hist_l3_Bin4[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin4[20]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      h.hist_l3_Bin4[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),EvtWeight);
	      //------>DeltaR Plots
	      h.hist_l3_Bin4[22]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),EvtWeight);
	      h.hist_l3_Bin4[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      h.hist_l3_Bin4[24]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),EvtWeight);
	      //Invariant Mass
	      h.hist_l3_Bin4[25]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),EvtWeight);
	      h.hist_l3_Bin4[26]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin4[27]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),EvtWeight);
	      h.hist_l3_Bin4[29]->Fill(ST,EvtWeight);
	      h.hist_l3_Bin4[28]->Fill(HT,EvtWeight);
	      h.hist_l3_Bin4[30]->Fill((int)bJets.size(),EvtWeight);
	      h.hist_l3_Bin4[31]->Fill((int)Jets.size(),EvtWeight);
	    }
	  }
	}
      }
    }//TriggeredEvts
  }//GoodEvt
  return kTRUE;
}
