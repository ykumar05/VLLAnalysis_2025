/********************************************
 *            2D Matrix Method              *
 ********************************************/
void AnaScript::CR_MisID(){
  if(_data == 1){
    //Clearing the Mass Arrays
    MassArray_3L.clear();
    TransverseMassArray_3L.clear();

    //Initializing different masses for 3L Final state
    float mass_01 = 0.0;
    float mass_02 = 0.0;
    float mass_12 = 0.0;
    
    //Boolean for chosen pairs
    bool chosen1               = false;
    bool chosen2               = false;
    bool chosen3               = false;
    bool is3mu                 = false;
    bool is3ele                = false;
    bool is1ele2mu             = false;
    bool is1mu2ele             = false;
    bool isSMTriggered         = false;
    bool isSETriggered         = false;
    bool isMuonTriggered       = false;
    bool isMuonTriggerable     = false;
    bool isElectronTriggerable = false;
    bool isTightElectron1      = false;
    bool isTightElectron2      = false;

    //ZGamma MisID Pred
    bool Hell1           = false;
    bool Hell2           = false;
    bool Hell3           = false;
    bool Hell4           = false;

    //Veto CR
    bool veto_MisID_LooseLep = true;
    bool veto_WZ_LooseLep    = true;
    bool veto_ZG_LooseLep    = true;
    
    if(is_l3_MisID_event){
      if(fabs((LooseLep.at(0).id)*(LooseLep.at(1).id)*(LooseLep.at(2).id)) == 2197)
	is3mu = true;
      if(fabs((LooseLep.at(0).id)*(LooseLep.at(1).id)*(LooseLep.at(2).id)) == 1331)
	is3ele = true;
      if(fabs((LooseLep.at(0).id)*(LooseLep.at(1).id)*(LooseLep.at(2).id)) == 1859)
	is1ele2mu = true;
      if(fabs((LooseLep.at(0).id)*(LooseLep.at(1).id)*(LooseLep.at(2).id)) == 1573)
	is1mu2ele = true;
      
      if(fabs(LooseLep.at(1).id) == 11)
	if(Electron_cutBased[LooseLep.at(1).ind] > 2)
	  isTightElectron1 = true;
      if(fabs(LooseLep.at(2).id) == 11)
	if(Electron_cutBased[LooseLep.at(2).ind] > 2)
	  isTightElectron2 = true;
    }
    
    //Accounting for overlapping regions by hand
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){
      //SingleMuon Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022){
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26){
	    if(_sample == 1000 || _sample == 1001 || _sample == 1002 || _sample == 1003){
	      isSMTriggered = true;
	    }
	  }
	}
	if(_year == 2017){
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29){
	    if(_sample == 1000 || _sample == 1001 || _sample == 1002 || _sample == 1003 || _sample == 1004){
	      isSMTriggered = true;
	    }
	  }
	}
	if(_year == 2016 || _year == 3016){
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26){
	    if(_sample == 1000 || _sample == 1001 || _sample == 1002 || _sample == 1003 || _sample == 1004){
	      isSMTriggered = true;
	    }
	  }
	}
      }

      //SingleElectron Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2016 || _year == 3016)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	    isMuonTriggered = true;
	if(_year == 2017)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	    isMuonTriggered = true;
      }
      if(!isMuonTriggered){
	for(int j = 0; j < (int)LightLepton.size(); j++){
	  if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2017){
	    if(abs(LightLepton.at(j).id) == 11 && LightLepton.at(j).v.Pt() > 35){
	      if(_sample == 1100 || _sample == 1101 || _sample == 1102 || _sample == 1103 || _sample == 1104)
		isSETriggered = true;
	    }
	  }
	  if(_year == 2016 || _year == 3016){
	    if(abs(LightLepton.at(j).id) == 11 && LightLepton.at(j).v.Pt() > 30){
	      if(_sample == 1100 || _sample == 1101 || _sample == 1102 || _sample == 1103 || _sample == 1104){
		isSETriggered = true;
	      }
	    }
	  }
	}
      }
    }
    
    //ZGamma MisID Pred
    Hell1 = is3mu && isSMTriggered;
    Hell2 = is3ele && isSETriggered;
    Hell3 = is1ele2mu && (isSMTriggered || isSETriggered);
    Hell4 = is1mu2ele && (isSMTriggered || isSETriggered);

    //Calculating the MisID Event Weight
    double N_T_fake = 0.0;
    if(is_l3_MisID_event){
      if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022){
	if(fabs(LooseLep.at(0).id) == 13 && LooseLep.at(0).v.Pt() > 26){
	  if(Muon_pfRelIso04_all[LooseLep.at(0).ind] < 0.15){
	    isMuonTriggerable = true;
	  }
	}
      }
      if(_year == 2017){
	if(fabs(LooseLep.at(0).id) == 13 && LooseLep.at(0).v.Pt() > 29){
	  if(Muon_pfRelIso04_all[LooseLep.at(0).ind] < 0.15){
	    isMuonTriggerable = true;
	  }
	}
      }
      if(_year == 2016 || _year == 3016){
	if(fabs(LooseLep.at(0).id) == 13 && LooseLep.at(0).v.Pt() > 26){
	  if(Muon_pfRelIso04_all[LooseLep.at(0).ind] < 0.15){
	    isMuonTriggerable = true;
	  }
	}
      }
      if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2017){
	if(fabs(LooseLep.at(0).id) == 11 && LooseLep.at(0).v.Pt() > 35){
	  if(Electron_cutBased[LooseLep.at(0).ind] > 2){
	    isElectronTriggerable = true;
	  }
	}
      }
      if(_year == 2016 || _year == 3016){
	if(fabs(LooseLep.at(0).id) == 11 && LooseLep.at(0).v.Pt() > 30){
	  if(Electron_cutBased[LooseLep.at(0).ind] > 2){
	    isElectronTriggerable = true;
	  }
	}
      }
    }
    
    if(isMuonTriggerable || isElectronTriggerable){
      double p1 = 0.0;
      double p2 = 0.0;
      double f1 = 0.0;
      double f2 = 0.0;
      //Evaluation of Correction Factors
      TLorentzVector Recoil_L1;
      TLorentzVector Recoil_L2;
      // Sum all leptons except the third one
      for (int i = 0; i < (int)LooseLep.size(); ++i) {
	if (i != 2){
	  Recoil_L2 += LooseLep.at(i).v;
	}
	if (i != 1){
	  Recoil_L1 += LooseLep.at(i).v;
	}
      }
      for (int i = 0; i < (int)MisIDJets.size(); ++i) {
	Recoil_L1 += MisIDJets.at(i).v;
	Recoil_L2 += MisIDJets.at(i).v;
      }
      
      if(fabs(LooseLep.at(1).id) == 13 && fabs(LooseLep.at(2).id) == 13){
	bool N_TT = Muon_pfRelIso04_all[LooseLep.at(1).ind] < 0.15 && Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15;
	bool N_LT = Muon_pfRelIso04_all[LooseLep.at(1).ind] > 0.15 && Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15;
	bool N_TL = Muon_pfRelIso04_all[LooseLep.at(1).ind] < 0.15 && Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15;
	bool N_LL = Muon_pfRelIso04_all[LooseLep.at(1).ind] > 0.15 && Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15;
      
	if(_year == 3022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22EE(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22EE(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2018){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL18(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL18(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL18(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL18(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2017){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL17(13,LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL17(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL17(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL17(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16preVFP(13,LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16preVFP(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16preVFP(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16preVFP(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16postVFP(13,LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16postVFP(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16postVFP(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16postVFP(13, Recoil_L2, LooseLep.at(2).v);
	}
	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p1-f1)*(p2-f2));
	  
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p1*p2*N_LL-p1*(1-p2)*N_LT-(1-p1)*p2*N_TL+(1-p1)*(1-p2)*N_TT);
	double N_FP = mf*((-1)*p1*f2*N_LL+p1*(1-f2)*N_LT+(1-p1)*f2*N_TL-(1-p1)*(1-f2)*N_TT);
	double N_PF = mf*((-1)*f1*p2*N_LL+f1*(1-p2)*N_LT+(1-f1)*p2*N_TL-(1-f1)*(1-p2)*N_TT);
	  
	//Calculating the MisID Event weight
	N_T_fake = f1*f2*N_FF + f1*p2*N_FP + p1*f2*N_PF;
      }
      
      //L1: Muon, L2: Electron
      if(fabs(LooseLep.at(1).id) == 13 && fabs(LooseLep.at(2).id) == 11){
	bool N_TT = Muon_pfRelIso04_all[LooseLep.at(1).ind] < 0.15 && (isTightElectron2);
	bool N_LT = Muon_pfRelIso04_all[LooseLep.at(1).ind] > 0.15 && (isTightElectron2);
	bool N_TL = Muon_pfRelIso04_all[LooseLep.at(1).ind] < 0.15 && (!isTightElectron2);
	bool N_LL = Muon_pfRelIso04_all[LooseLep.at(1).ind] > 0.15 && (!isTightElectron2);
	
	if(_year == 3022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22EE(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22EE(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2018){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL18(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL18(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL18(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL18(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2017){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL17(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL17(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL17(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL17(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16preVFP(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16preVFP(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16preVFP(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16preVFP(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16postVFP(13, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16postVFP(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16postVFP(13, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16postVFP(11, Recoil_L2, LooseLep.at(2).v);
	}
	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p1-f1)*(p2-f2));
	
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p1*p2*N_LL-p1*(1-p2)*N_LT-(1-p1)*p2*N_TL+(1-p1)*(1-p2)*N_TT);
	double N_FP = mf*((-1)*p1*f2*N_LL+p1*(1-f2)*N_LT+(1-p1)*f2*N_TL-(1-p1)*(1-f2)*N_TT);
	double N_PF = mf*((-1)*f1*p2*N_LL+f1*(1-p2)*N_LT+(1-f1)*p2*N_TL-(1-f1)*(1-p2)*N_TT);
	
	//Calculating the MisID Event weight
	N_T_fake = f1*f2*N_FF + f1*p2*N_FP + p1*f2*N_PF;
      }
      
      //L1: Electron, L2: Muon
      if(fabs(LooseLep.at(1).id) == 11 && fabs(LooseLep.at(2).id) == 13){
	bool N_TT = (isTightElectron1)  && Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15;
	bool N_LT = (!isTightElectron1) && Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15;
	bool N_TL = (isTightElectron1)  && Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15;
	bool N_LL = (!isTightElectron1) && Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15;

	if(_year == 3022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22EE(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22EE(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2018){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL18(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL18(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL18(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL18(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2017){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL17(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL17(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL17(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL17(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16preVFP(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16preVFP(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16preVFP(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16preVFP(13, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16postVFP(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16postVFP(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16postVFP(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16postVFP(13, Recoil_L2, LooseLep.at(2).v);
	}
	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p1-f1)*(p2-f2));
	  
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p1*p2*N_LL-p1*(1-p2)*N_LT-(1-p1)*p2*N_TL+(1-p1)*(1-p2)*N_TT);
	double N_FP = mf*((-1)*p1*f2*N_LL+p1*(1-f2)*N_LT+(1-p1)*f2*N_TL-(1-p1)*(1-f2)*N_TT);
	double N_PF = mf*((-1)*f1*p2*N_LL+f1*(1-p2)*N_LT+(1-f1)*p2*N_TL-(1-f1)*(1-p2)*N_TT);
	  
	//Calculating the MisID Event weight
	N_T_fake = f1*f2*N_FF + f1*p2*N_FP + p1*f2*N_PF;
      }
	
	
      //L1, L2: Electrons
      if(fabs(LooseLep.at(1).id) == 11 && fabs(LooseLep.at(2).id) == 11){
	bool N_TT = (isTightElectron1)  && (isTightElectron2);
	bool N_LT = (!isTightElectron1) && (isTightElectron2);
	bool N_TL = (isTightElectron1)  && (!isTightElectron2);
	bool N_LL = (!isTightElectron1) && (!isTightElectron2);

	if(_year == 3022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22EE(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22EE(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2022){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer22(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer22(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer22(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer22(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3023){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2018){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL18(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL18(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL18(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL18(11, Recoil_L2, LooseLep.at(2).v);
	}
	
	if(_year == 2017){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL17(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL17(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL17(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL17(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16preVFP(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16preVFP(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16preVFP(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16preVFP(11, Recoil_L2, LooseLep.at(2).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p1 = PromptRateMixed_UL16postVFP(11, LooseLep.at(1).v.Pt(), LooseLep.at(1).v.Eta());
	  p2 = PromptRateMixed_UL16postVFP(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  //Calculating Fake Rates
	  f1 = FakeRateMixed_UL16postVFP(11, Recoil_L1, LooseLep.at(1).v);
	  f2 = FakeRateMixed_UL16postVFP(11, Recoil_L2, LooseLep.at(2).v);
	}
	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p1-f1)*(p2-f2));
	  
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p1*p2*N_LL-p1*(1-p2)*N_LT-(1-p1)*p2*N_TL+(1-p1)*(1-p2)*N_TT);
	double N_FP = mf*((-1)*p1*f2*N_LL+p1*(1-f2)*N_LT+(1-p1)*f2*N_TL-(1-p1)*(1-f2)*N_TT);
	double N_PF = mf*((-1)*f1*p2*N_LL+f1*(1-p2)*N_LT+(1-f1)*p2*N_TL-(1-f1)*(1-p2)*N_TT);
	  
	//Calculating the MisID Event weight
	N_T_fake = f1*f2*N_FF + f1*p2*N_FP + p1*f2*N_PF;
      }
    }  
 
    
    /********************************************
     *                  3 Muons                 *
     ********************************************/
    if(is3mu && isSMTriggered){
      if(LooseLep.at(0).id*LooseLep.at(1).id == -169){
	mass_01 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	chosen1 = true;
      }
      if(LooseLep.at(0).id*LooseLep.at(2).id == -169){
	mass_02 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	chosen2 = true;
      }
      if(LooseLep.at(1).id*LooseLep.at(2).id == -169){
	mass_12 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	chosen3 = true;
      }
      
      if(chosen1 && chosen2){
	if(fabs(mass_01-91.2)<fabs(mass_02-91.2)){
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	else{
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
      if(chosen2 && chosen3){
	if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	else{
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
      if(chosen1 && chosen3){
	if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	else{
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
    }

    /********************************************
     *                3 Electrons               *
     ********************************************/
    if(is3ele && isSETriggered){
      if(LooseLep.at(0).id*LooseLep.at(1).id == -121){
	mass_01 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	chosen1 = true;
      }
      if(LooseLep.at(0).id*LooseLep.at(2).id == -121){
	mass_02 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	chosen2 = true;
      }
      if(LooseLep.at(1).id*LooseLep.at(2).id == -121){
	mass_12 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	chosen3 = true;
      }

      if(chosen1 && chosen2){
	if(fabs(mass_01-91.2)<fabs(mass_02-91.2)){
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	else{
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
      if(chosen2 && chosen3){
	if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	else{
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
      if(chosen1 && chosen3){
	if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	else{
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
    }

    /********************************************
     *          1 Electron & 2 Muons            *
     ********************************************/
    if(is1ele2mu){
      if(isSETriggered || isSMTriggered){
	if(LooseLep.at(0).id*LooseLep.at(1).id == -169){
	  mass_01 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	  chosen1 = true;
	}
	if(LooseLep.at(0).id*LooseLep.at(2).id == -169){
	  mass_02 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	  chosen2 = true;
	}
	if(LooseLep.at(1).id*LooseLep.at(2).id == -169){
	  mass_12 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	  chosen3 = true;
	}
	if(chosen1){
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	if(chosen2){
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	if(chosen3){
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
    }

    /********************************************
     *          1 Muon & 2 Electrons            *
     ********************************************/
    if(is1mu2ele){
      if(isSMTriggered || isSETriggered){
	if(LooseLep.at(0).id*LooseLep.at(1).id == -121){
	  mass_01 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	  chosen1 = true;
	}
	if(LooseLep.at(0).id*LooseLep.at(2).id == -121){
	  mass_02 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	  chosen2 = true;
	}
	if(LooseLep.at(1).id*LooseLep.at(2).id == -121){
	  mass_12 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	  chosen3 = true;
	}
	if(chosen1){
	  MassArray_3L.push_back(mass_01);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	if(chosen2){
	  MassArray_3L.push_back(mass_02);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
	if(chosen3){
	  MassArray_3L.push_back(mass_12);
	  TransverseMassArray_3L.push_back(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
	}
      }
    }

    //MisID CR: MisID Prediction
    if((int)MassArray_3L.size()>0 && (int)TransverseMassArray_3L.size()>0){
      if(76<MassArray_3L.at(0) && MassArray_3L.at(0)<106){//OnZ Mass
	if(TransverseMassArray_3L.at(0)<50){//Transverse Mass
	  if(*PuppiMET_pt<100){
	    if((int)bJets.size() == 0){
	      veto_MisID_LooseLep = false;
	      h.MisID_CR[0]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	      h.MisID_CR[1]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	      h.MisID_CR[2]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	      h.MisID_CR[3]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	      h.MisID_CR[4]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	      h.MisID_CR[5]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	      h.MisID_CR[6]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	      h.MisID_CR[7]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	      h.MisID_CR[8]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	      //------>Event Level Kinematics
	      h.MisID_CR[9]->Fill((int)bJets.size(),N_T_fake);
	      h.MisID_CR[10]->Fill((int)Jets.size(),N_T_fake);
	      h.MisID_CR[11]->Fill(LT_MisID,N_T_fake);
	      h.MisID_CR[12]->Fill(*PuppiMET_pt,N_T_fake);
	      h.MisID_CR[13]->Fill(LT_PuppiMET_MisID,N_T_fake);
	      h.MisID_CR[14]->Fill(HT_MisID,N_T_fake);
	      h.MisID_CR[15]->Fill(ST_MisID,N_T_fake);
	      //------>Transverse Mass
	      h.MisID_CR[16]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.MisID_CR[17]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.MisID_CR[18]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.MisID_CR[19]->Fill(MassArray_3L.at(0),N_T_fake);
	      h.MisID_CR[20]->Fill(TransverseMassArray_3L.at(0),N_T_fake);
	      //dPhi and dR's
	      h.MisID_CR[21]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	      h.MisID_CR[22]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	      h.MisID_CR[23]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	      h.MisID_CR[24]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.MisID_CR[25]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.MisID_CR[26]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.MisID_CR[27]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	      h.MisID_CR[28]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	      h.MisID_CR[29]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	      //Number Plots
	      h.MisID_CR[30]->Fill((int)LooseLep.size(),N_T_fake);
	    }
	  }
	}
      }
    }

    //WZ CR: MisID Prediction
    if((int)MassArray_3L.size()>0 && (int)TransverseMassArray_3L.size()>0){
      if(76<MassArray_3L.at(0) && MassArray_3L.at(0)<106){//OnZ Mass
	if(50<TransverseMassArray_3L.at(0) && TransverseMassArray_3L.at(0)<150){//Transverse Mass
	  if(*PuppiMET_pt>50 && *PuppiMET_pt<150){
	    if(LooseLep.at(2).v.Pt()>20){//Softest Lepton Pt
	      if((int)bJets.size()==0){
		veto_WZ_LooseLep = false;
		h.WZ_CR[38]->Fill(1,N_T_fake);
		h.WZ_CR[39]->Fill((int)LooseLep.size(),N_T_fake);
		h.WZ_CR[40]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
		h.WZ_CR[41]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
		h.WZ_CR[42]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
		h.WZ_CR[43]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
		h.WZ_CR[44]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
		h.WZ_CR[45]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
		h.WZ_CR[46]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
		h.WZ_CR[47]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
		h.WZ_CR[48]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
		//------>Event Level Kinematics
		h.WZ_CR[49]->Fill(LT_MisID,N_T_fake);
		h.WZ_CR[50]->Fill(*PuppiMET_pt,N_T_fake);
		h.WZ_CR[51]->Fill(LT_PuppiMET_MisID,N_T_fake);
		//------>Angular Variables
		h.WZ_CR[52]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
		h.WZ_CR[53]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
		h.WZ_CR[54]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
		h.WZ_CR[55]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
		h.WZ_CR[56]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
		h.WZ_CR[57]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
		//------>Transverse Mass
		h.WZ_CR[58]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
		h.WZ_CR[59]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
		h.WZ_CR[60]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
		//------>DeltaR Plots
		h.WZ_CR[61]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
		h.WZ_CR[62]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
		h.WZ_CR[63]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
		//Invariant Mass
		h.WZ_CR[64]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
		h.WZ_CR[65]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
		h.WZ_CR[66]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
		h.WZ_CR[67]->Fill(HT_MisID,N_T_fake);
		h.WZ_CR[68]->Fill(ST_MisID,N_T_fake);
		h.WZ_CR[70]->Fill((int)bJets.size(),N_T_fake);
		h.WZ_CR[71]->Fill((int)Jets.size(),N_T_fake);
	      }
	    }
	  }
	}
      }
    }

    //ZGamma CR: MisID Prediction
    if(Hell1 || Hell2 || Hell3 || Hell4){
      bool M_2L1 = false;
      bool M_2L2 = false;
      bool M_2L3 = false;
      bool M_2L4 = false;
      bool M_2L5 = false;
      float invmass = (LooseLep.at(0).v+LooseLep.at(1).v+LooseLep.at(2).v).M();
      if(76.0 < invmass && invmass < 106.0){
	if(LooseLep.at(0).id * LooseLep.at(1).id == -169 || LooseLep.at(0).id * LooseLep.at(1).id == -121)
	  M_2L1 = (LooseLep.at(0).v+LooseLep.at(1).v).M() < 76;
	if(LooseLep.at(0).id * LooseLep.at(2).id == -169 || LooseLep.at(0).id * LooseLep.at(2).id == -121)
	  M_2L2 = (LooseLep.at(0).v+LooseLep.at(2).v).M() < 76;
	if(LooseLep.at(1).id * LooseLep.at(2).id == -169 || LooseLep.at(1).id * LooseLep.at(2).id == -121)
	  M_2L3 = (LooseLep.at(1).v+LooseLep.at(2).v).M() < 76;
	if(M_2L1 + M_2L2 + M_2L3 == 1)
	  M_2L4 = M_2L1 || M_2L2 || M_2L3;
	if(M_2L1 + M_2L2 +M_2L3 == 2)
	  M_2L5 = (M_2L1 && M_2L2) || (M_2L1 && M_2L3) || (M_2L3 && M_2L2);
	if(M_2L4 || M_2L5){
	  if(LooseLep.at(2).v.Pt() > 15){
	    veto_ZG_LooseLep = false;
	    h.ZG_CR[0]->Fill((int)LooseLep.size(),N_T_fake);
	    h.ZG_CR[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	    h.ZG_CR[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	    h.ZG_CR[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	    h.ZG_CR[4]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	    h.ZG_CR[5]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	    h.ZG_CR[6]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	    h.ZG_CR[7]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	    h.ZG_CR[8]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	    h.ZG_CR[9]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	    //------>Event Level Kinematics
	    h.ZG_CR[10]->Fill(LT_MisID,N_T_fake);
	    h.ZG_CR[11]->Fill(*PuppiMET_pt,N_T_fake);
	    h.ZG_CR[12]->Fill(LT_PuppiMET_MisID,N_T_fake);
	    //------>Angular Variables
	    h.ZG_CR[13]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	    h.ZG_CR[14]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	    h.ZG_CR[15]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	    h.ZG_CR[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	    h.ZG_CR[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	    h.ZG_CR[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	    //------>Transverse Mass
	    h.ZG_CR[19]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	    h.ZG_CR[20]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	    h.ZG_CR[21]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	    //------>DeltaR Plots
	    h.ZG_CR[22]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	    h.ZG_CR[23]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	    h.ZG_CR[24]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	    //Invariant Mass
	    h.ZG_CR[25]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	    h.ZG_CR[26]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	    h.ZG_CR[27]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	    h.ZG_CR[28]->Fill(HT_MisID,N_T_fake);
	    h.ZG_CR[29]->Fill(ST_MisID,N_T_fake);
	    h.ZG_CR[30]->Fill((int)bJets.size(),N_T_fake);
	    h.ZG_CR[31]->Fill((int)Jets.size(),N_T_fake);
	    h.ZG_CR[32]->Fill(invmass,N_T_fake);
	  }
	}
      }
    }

    //Test CR: MisID Prediction
    if((int)MassArray_3L.size()>0 && (int)TransverseMassArray_3L.size()>0){
      if(76<MassArray_3L.at(0) && MassArray_3L.at(0)<106){//OnZ Mass
	if(TransverseMassArray_3L.at(0) < 150){//Transverse Mass
	  if(*PuppiMET_pt < 150){
	    if((int)bJets.size() == 0){
	      h.Test_CR[0]->Fill(1,N_T_fake);
	      h.Test_CR[1]->Fill((int)LooseLep.size(),N_T_fake);
	      h.Test_CR[2]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	      h.Test_CR[3]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	      h.Test_CR[4]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	      h.Test_CR[5]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	      h.Test_CR[6]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	      h.Test_CR[7]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	      h.Test_CR[8]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	      h.Test_CR[9]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	      h.Test_CR[10]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	      //------>Event Level Kinematics
	      h.Test_CR[11]->Fill(LT_MisID,N_T_fake);
	      h.Test_CR[12]->Fill(*PuppiMET_pt,N_T_fake);
	      h.Test_CR[13]->Fill(LT_PuppiMET_MisID,N_T_fake);
	      //------>Angular Variables
	      h.Test_CR[14]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	      h.Test_CR[15]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	      h.Test_CR[16]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	      h.Test_CR[17]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.Test_CR[18]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.Test_CR[19]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	      //------>Transverse Mass
	      h.Test_CR[20]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.Test_CR[21]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.Test_CR[22]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      //------>DeltaR Plots
	      h.Test_CR[23]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	      h.Test_CR[24]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	      h.Test_CR[25]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	      //Invariant Mass
	      h.Test_CR[26]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	      h.Test_CR[27]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	      h.Test_CR[28]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	      h.Test_CR[29]->Fill(HT_MisID,N_T_fake);
	      h.Test_CR[30]->Fill(ST_MisID,N_T_fake);
	      h.Test_CR[31]->Fill((int)bJets.size(),N_T_fake);
	      h.Test_CR[32]->Fill((int)Jets.size(),N_T_fake);
	    }
	  }
	}
      }
    }
 
    //Signal Studies: 3L
    bool Bin1_3L = false;
    bool Bin2_3L = false;
    bool Bin3_3L = false;
    bool Bin4_3L = false;
    
    bool doublet_3L = false;
    //bool doublet_3L = true;
    bool singlet_3L = false;
    //bool singlet_3L = true;

    if(is_l3_MisID_event && veto_MisID_LooseLep && veto_WZ_LooseLep  && veto_ZG_LooseLep){
      if((int)bJets.size() == 0){
	if(doublet_3L){
	  if((LooseLep.at(0).v+LooseLep.at(1).v).M() > 106){
	    if(*PuppiMET_pt > 150)
	      Bin1_3L = true;
	    if(*PuppiMET_pt < 150)
	      Bin2_3L = true;
	  }
	  if((LooseLep.at(0).v+LooseLep.at(1).v).M() < 106){
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
	
	//Inclusive
	h.hist_l3[0]->Fill((int)LooseLep.size(),N_T_fake);
	h.hist_l3[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	h.hist_l3[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	h.hist_l3[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	h.hist_l3[4]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	h.hist_l3[5]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	h.hist_l3[6]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	h.hist_l3[7]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	h.hist_l3[8]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	h.hist_l3[9]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	//------>Event Level Kinematics
	h.hist_l3[10]->Fill(LT_MisID,N_T_fake);
	h.hist_l3[11]->Fill(*PuppiMET_pt,N_T_fake);
	h.hist_l3[12]->Fill(LT_PuppiMET_MisID,N_T_fake);
	//------>Angular Variables
	h.hist_l3[13]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	h.hist_l3[14]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	h.hist_l3[15]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	h.hist_l3[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	h.hist_l3[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	h.hist_l3[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	//------>Transverse Mass
	h.hist_l3[19]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	h.hist_l3[20]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	h.hist_l3[21]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	//------>DeltaR Plots
	h.hist_l3[22]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	h.hist_l3[23]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	h.hist_l3[24]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	//Invariant Mass
	h.hist_l3[25]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	h.hist_l3[26]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	h.hist_l3[27]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	h.hist_l3[29]->Fill(ST_MisID,N_T_fake);
	h.hist_l3[28]->Fill(HT_MisID,N_T_fake);
	h.hist_l3[30]->Fill((int)bJets.size(),N_T_fake);
	h.hist_l3[31]->Fill((int)Jets.size(),N_T_fake);
	//Binned Scheme: Bin1
	if(Bin1_3L){
	  h.hist_l3_Bin1[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l3_Bin1[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l3_Bin1[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l3_Bin1[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l3_Bin1[4]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l3_Bin1[5]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l3_Bin1[6]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l3_Bin1[7]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l3_Bin1[8]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l3_Bin1[9]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l3_Bin1[10]->Fill(LT_MisID,N_T_fake);
	  h.hist_l3_Bin1[11]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l3_Bin1[12]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l3_Bin1[13]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l3_Bin1[14]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin1[15]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin1[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin1[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin1[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l3_Bin1[19]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin1[20]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin1[21]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l3_Bin1[22]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l3_Bin1[23]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l3_Bin1[24]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l3_Bin1[25]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l3_Bin1[26]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin1[27]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin1[29]->Fill(ST_MisID,N_T_fake);
	  h.hist_l3_Bin1[28]->Fill(HT_MisID,N_T_fake);
	  h.hist_l3_Bin1[30]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l3_Bin1[31]->Fill((int)Jets.size(),N_T_fake);
	}
	if(Bin2_3L){
	  h.hist_l3_Bin2[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l3_Bin2[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l3_Bin2[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l3_Bin2[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l3_Bin2[4]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l3_Bin2[5]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l3_Bin2[6]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l3_Bin2[7]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l3_Bin2[8]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l3_Bin2[9]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l3_Bin2[10]->Fill(LT_MisID,N_T_fake);
	  h.hist_l3_Bin2[11]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l3_Bin2[12]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l3_Bin2[13]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l3_Bin2[14]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin2[15]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin2[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin2[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin2[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l3_Bin2[19]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin2[20]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin2[21]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l3_Bin2[22]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l3_Bin2[23]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l3_Bin2[24]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l3_Bin2[25]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l3_Bin2[26]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin2[27]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin2[29]->Fill(ST_MisID,N_T_fake);
	  h.hist_l3_Bin2[28]->Fill(HT_MisID,N_T_fake);
	  h.hist_l3_Bin2[30]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l3_Bin2[31]->Fill((int)Jets.size(),N_T_fake);
	}
	if(Bin3_3L){
	  h.hist_l3_Bin3[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l3_Bin3[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l3_Bin3[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l3_Bin3[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l3_Bin3[4]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l3_Bin3[5]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l3_Bin3[6]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l3_Bin3[7]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l3_Bin3[8]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l3_Bin3[9]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l3_Bin3[10]->Fill(LT_MisID,N_T_fake);
	  h.hist_l3_Bin3[11]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l3_Bin3[12]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l3_Bin3[13]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l3_Bin3[14]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin3[15]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin3[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin3[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin3[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l3_Bin3[19]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin3[20]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin3[21]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l3_Bin3[22]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l3_Bin3[23]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l3_Bin3[24]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l3_Bin3[25]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l3_Bin3[26]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin3[27]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin3[29]->Fill(ST_MisID,N_T_fake);
	  h.hist_l3_Bin3[28]->Fill(HT_MisID,N_T_fake);
	  h.hist_l3_Bin3[30]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l3_Bin3[31]->Fill((int)Jets.size(),N_T_fake);
	}
	if(Bin4_3L){
	  h.hist_l3_Bin4[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l3_Bin4[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l3_Bin4[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l3_Bin4[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l3_Bin4[4]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l3_Bin4[5]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l3_Bin4[6]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l3_Bin4[7]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l3_Bin4[8]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l3_Bin4[9]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l3_Bin4[10]->Fill(LT_MisID,N_T_fake);
	  h.hist_l3_Bin4[11]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l3_Bin4[12]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l3_Bin4[13]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l3_Bin4[14]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin4[15]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l3_Bin4[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin4[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin4[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l3_Bin4[19]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin4[20]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l3_Bin4[21]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l3_Bin4[22]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l3_Bin4[23]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l3_Bin4[24]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l3_Bin4[25]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l3_Bin4[26]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin4[27]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l3_Bin4[29]->Fill(ST_MisID,N_T_fake);
	  h.hist_l3_Bin4[28]->Fill(HT_MisID,N_T_fake);
	  h.hist_l3_Bin4[30]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l3_Bin4[31]->Fill((int)Jets.size(),N_T_fake);
	}
      }
    }
  }
}
