/********************************************
 *            2D Matrix Method              *
 ********************************************/
void AnaScript::CR_MisID_4L(){
  if(_data == 1){
    //Clearing the Mass Arrays
    MassArray_4L.clear();
    MassArray_pT.clear();

    //Clearing the arrays of pairings
    pairing1.clear();//[0123]
    pairing2.clear();//[0213]
    pairing3.clear();//[0312]
  
    //Initializing different masses for 4 muons state
    float mass_01_12=0.0;//01:GoodMu.at(0),GoodMu.at(1); 12:Pairing1 and Pairing2
    float mass_23_12=0.0;
    float mass_02_12=0.0;
    float mass_13_12=0.0;
    float mass_01_13=0.0;
    float mass_23_13=0.0;
    float mass_03_13=0.0;
    float mass_12_13=0.0;
    float mass_02_23=0.0;
    float mass_13_23=0.0;
    float mass_03_23=0.0;
    float mass_12_23=0.0;

    //Initializing different pT's for 4 muons state
    float pT_01_12=0.0;//01:GoodMu.at(0),GoodMu.at(1); 12:Pairing1 and Pairing2
    float pT_23_12=0.0;
    float pT_02_12=0.0;
    float pT_13_12=0.0;
    float pT_01_13=0.0;
    float pT_23_13=0.0;
    float pT_03_13=0.0;
    float pT_12_13=0.0;
    float pT_02_23=0.0;
    float pT_13_23=0.0;
    float pT_03_23=0.0;
    float pT_12_23=0.0;
  
    //Defining booleans
    bool mu4       = false;
    bool e4        = false;
    bool e2mu2     = false;
    bool chosen1   = false;
    bool chosen2   = false;
    bool chosen3   = false;
    bool chosen4   = false;
    bool chosen5   = false;
    bool chosen6   = false;
    bool pairing12 = false;
    bool pairing13 = false;
    bool pairing23 = false;
    
    //Boolean for chosen pairs
    bool isSMTriggered         = false;
    bool isSETriggered         = false;
    bool isMuonTriggered       = false;
    bool isMuonTriggerable     = false;
    bool isElectronTriggerable = false;
    bool isTightElectron2      = false;
    bool isTightElectron3      = false;

    //Veto CRs
    bool veto_ZZ_LooseLep = true;

    if(is_l4_MisID_event){
      if(abs(LooseLep.at(0).id*LooseLep.at(1).id*LooseLep.at(2).id*LooseLep.at(3).id) == 28561)
	mu4   = true;
      if(abs(LooseLep.at(0).id*LooseLep.at(1).id*LooseLep.at(2).id*LooseLep.at(3).id) == 20449)
	e2mu2 = true;
      if(abs(LooseLep.at(0).id*LooseLep.at(1).id*LooseLep.at(2).id*LooseLep.at(3).id) == 14641)
	e4    = true;
      
      if(fabs(LooseLep.at(2).id) == 11)
	if(Electron_cutBased[LooseLep.at(2).ind] > 2)
	  isTightElectron2 = true;
      if(fabs(LooseLep.at(3).id) == 11)
	if(Electron_cutBased[LooseLep.at(3).ind] > 2)
	  isTightElectron3 = true;
    }
    
    if(mu4 || e4 ||e2mu2){
      //SingleMuon Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
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
	if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023 || _year == 2016 || _year == 3016)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	    isMuonTriggered = true;
	if(_year == 2017)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	    isMuonTriggered = true;
      }
      if(!isMuonTriggered){
	for(int j = 0; j < (int)LightLepton.size(); j++){
	  if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023 || _year == 2017){
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

    //Calculating the MisID Event Weight
    double N_T_fake = 0.0;
    if(is_l4_MisID_event){
      if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023){
	if(fabs(LooseLep.at(0).id) == 13 && LooseLep.at(0).v.Pt() > 26){
	  if(Muon_pfRelIso04_all[LooseLep.at(0).ind] < 0.15){
	    if(Muon_pfRelIso04_all[LooseLep.at(1).ind] < 0.15){
	      isMuonTriggerable = true;
	    }
	  }
	}
      }
      if(_year == 2017){
	if(fabs(LooseLep.at(0).id) == 13 && LooseLep.at(0).v.Pt() > 29){
	  if(Muon_pfRelIso04_all[LooseLep.at(0).ind] < 0.15){
	    if(Muon_pfRelIso04_all[LooseLep.at(1).ind] < 0.15){
	      isMuonTriggerable = true;
	    }
	  }
	}
      }
      if(_year == 2016 || _year == 3016){
	if(fabs(LooseLep.at(0).id) == 13 && LooseLep.at(0).v.Pt() > 26){
	  if(Muon_pfRelIso04_all[LooseLep.at(0).ind] < 0.15){
	    if(Muon_pfRelIso04_all[LooseLep.at(1).ind] < 0.15){
	      isMuonTriggerable = true;
	    }
	  }
	}
      }
      if(_year == 2018 || _year == 2022 || _year == 3022 || _year == 2023 || _year == 3023 || _year == 2017){
	if(fabs(LooseLep.at(0).id) == 11 && LooseLep.at(0).v.Pt() > 35){
	  if(Electron_cutBased[LooseLep.at(0).ind] > 2){
	    if(Electron_cutBased[LooseLep.at(1).ind] > 2){
	      isElectronTriggerable = true;
	    }
	  }
	}
      }
      if(_year == 2016 || _year == 3016){
	if(fabs(LooseLep.at(0).id) == 11 && LooseLep.at(0).v.Pt() > 30){
	  if(Electron_cutBased[LooseLep.at(0).ind] > 2){
	    if(Electron_cutBased[LooseLep.at(1).ind] > 2){
	      isElectronTriggerable = true;
	    }
	  }
	}
      }
    }
    
    if(isMuonTriggerable || isElectronTriggerable){
      double p2 = 0.0;
      double p3 = 0.0;
      double f2 = 0.0;
      double f3 = 0.0;
      //Evaluation of Correction Factors
      TLorentzVector Recoil_L2;
      TLorentzVector Recoil_L3;
      // Sum all leptons except the third one
      for (int i = 0; i < (int)LooseLep.size(); ++i) {
	if (i != 2){
	  Recoil_L2 += LooseLep.at(i).v;
	}
	if (i != 3){
	  Recoil_L3 += LooseLep.at(i).v;
	}
      }
      for (int i = 0; i < (int)MisIDJets.size(); ++i) {
	Recoil_L2 += MisIDJets.at(i).v;
	Recoil_L3 += MisIDJets.at(i).v;
      }

      //L2: Muon, L3: Muon
      if(fabs(LooseLep.at(2).id) == 13 && fabs(LooseLep.at(3).id) == 13){
	bool N_TT = Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15 && Muon_pfRelIso04_all[LooseLep.at(3).ind] < 0.15;
	bool N_LT = Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15 && Muon_pfRelIso04_all[LooseLep.at(3).ind] < 0.15;
	bool N_TL = Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15 && Muon_pfRelIso04_all[LooseLep.at(3).ind] > 0.15;
	bool N_LL = Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15 && Muon_pfRelIso04_all[LooseLep.at(3).ind] > 0.15;
      
	if(_year == 3023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 3022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22EE(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22EE(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2018){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL18(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL18(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL18(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL18(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2017){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL17(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL17(13,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL17(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL17(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16preVFP(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16preVFP(13,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16preVFP(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16preVFP(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16postVFP(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16postVFP(13,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16postVFP(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16postVFP(13, Recoil_L3, LooseLep.at(3).v);
	}
	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p2-f2)*(p3-f3));
	  
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p2*p3*N_LL-p2*(1-p3)*N_LT-(1-p2)*p3*N_TL+(1-p2)*(1-p3)*N_TT);
	double N_FP = mf*((-1)*p2*f3*N_LL+p2*(1-f3)*N_LT+(1-p2)*f3*N_TL-(1-p2)*(1-f3)*N_TT);
	double N_PF = mf*((-1)*f2*p3*N_LL+f2*(1-p3)*N_LT+(1-f2)*p3*N_TL-(1-f2)*(1-p3)*N_TT);
	  
	//Calculating the MisID Event weight
	N_T_fake = f2*f3*N_FF + f2*p3*N_FP + p2*f3*N_PF;
      }
      
      //L2: Muon, L3: Electron
      if(fabs(LooseLep.at(2).id) == 13 && fabs(LooseLep.at(3).id) == 11){
	bool N_TT = Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15 && (isTightElectron3);
	bool N_LT = Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15 && (isTightElectron3);
	bool N_TL = Muon_pfRelIso04_all[LooseLep.at(2).ind] < 0.15 && (!isTightElectron3);
	bool N_LL = Muon_pfRelIso04_all[LooseLep.at(2).ind] > 0.15 && (!isTightElectron3);
	
	if(_year == 3023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 3022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22EE(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22EE(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2018){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL18(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL18(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL18(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL18(11, Recoil_L3, LooseLep.at(3).v);
	}
	
	if(_year == 2017){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL17(13, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL17(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL17(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL17(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16preVFP(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16preVFP(11,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16preVFP(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16preVFP(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16postVFP(13,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16postVFP(11,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16postVFP(13, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16postVFP(11, Recoil_L3, LooseLep.at(3).v);
	}
	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p2-f2)*(p3-f3));
	
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p2*p3*N_LL-p2*(1-p3)*N_LT-(1-p2)*p3*N_TL+(1-p2)*(1-p3)*N_TT);
	double N_FP = mf*((-1)*p2*f3*N_LL+p2*(1-f3)*N_LT+(1-p2)*f3*N_TL-(1-p2)*(1-f3)*N_TT);
	double N_PF = mf*((-1)*f2*p3*N_LL+f2*(1-p3)*N_LT+(1-f2)*p3*N_TL-(1-f2)*(1-p3)*N_TT);
	
	//Calculating the MisID Event weight
	N_T_fake = f2*f3*N_FF + f2*p3*N_FP + p2*f3*N_PF;
      }
      
      //L2: Electron, L3: Muon
      if(fabs(LooseLep.at(2).id) == 11 && fabs(LooseLep.at(3).id) == 13){
	bool N_TT = (isTightElectron2)  && Muon_pfRelIso04_all[LooseLep.at(3).ind] < 0.15;
	bool N_LT = (!isTightElectron2) && Muon_pfRelIso04_all[LooseLep.at(3).ind] < 0.15;
	bool N_TL = (isTightElectron2)  && Muon_pfRelIso04_all[LooseLep.at(3).ind] > 0.15;
	bool N_LL = (!isTightElectron2) && Muon_pfRelIso04_all[LooseLep.at(3).ind] > 0.15;

	if(_year == 3023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23BPix(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23BPix(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 3022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22EE(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22EE(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22EE(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2018){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL18(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL18(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL18(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL18(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2017){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL17(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL17(13, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL17(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL17(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16preVFP(11,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16preVFP(13,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16preVFP(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16preVFP(13, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16postVFP(11,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16postVFP(13,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16postVFP(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16postVFP(13, Recoil_L3, LooseLep.at(3).v);
	}

	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p2-f2)*(p3-f3));
	  
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p2*p3*N_LL-p2*(1-p3)*N_LT-(1-p2)*p3*N_TL+(1-p2)*(1-p3)*N_TT);
	double N_FP = mf*((-1)*p2*f3*N_LL+p2*(1-f3)*N_LT+(1-p2)*f3*N_TL-(1-p2)*(1-f3)*N_TT);
	double N_PF = mf*((-1)*f2*p3*N_LL+f2*(1-p3)*N_LT+(1-f2)*p3*N_TL-(1-f2)*(1-p3)*N_TT);
	  
	//Calculating the MisID Event weight
	N_T_fake = f2*f3*N_FF + f2*p3*N_FP + p2*f3*N_PF;
      }
	
	
      //L2, L3: Electrons
      if(fabs(LooseLep.at(2).id) == 11 && fabs(LooseLep.at(3).id) == 11){
	bool N_TT = (isTightElectron2)  && (isTightElectron3);
	bool N_LT = (!isTightElectron2) && (isTightElectron3);
	bool N_TL = (isTightElectron2)  && (!isTightElectron3);
	bool N_LL = (!isTightElectron2) && (!isTightElectron3);

	if(_year == 3023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23BPix(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23BPix(11, Recoil_L3, LooseLep.at(3).v);
	}
	
	if(_year == 2023){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer23(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer23(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer23(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer23(11, Recoil_L3, LooseLep.at(3).v);
	}
	
	if(_year == 3022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22EE(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22EE(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22EE(11, Recoil_L3, LooseLep.at(3).v);
	}
	
	if(_year == 2022){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_Run3Summer22(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_Run3Summer22(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_Run3Summer22(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_Run3Summer22(11, Recoil_L3, LooseLep.at(3).v);
	}
	
	if(_year == 2018){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL18(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL18(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL18(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL18(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2017){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL17(11, LooseLep.at(2).v.Pt(), LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL17(11, LooseLep.at(3).v.Pt(), LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL18(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL18(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 2016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16preVFP(11,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16preVFP(11,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16preVFP(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16preVFP(11, Recoil_L3, LooseLep.at(3).v);
	}

	if(_year == 3016){
	  //Calculating Prompt Rates
	  p2 = PromptRateMixed_UL16postVFP(11,LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Eta());
	  p3 = PromptRateMixed_UL16postVFP(11,LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Eta());
	  //Calculating Fake Rates
	  f2 = FakeRateMixed_UL16postVFP(11, Recoil_L2, LooseLep.at(2).v);
	  f3 = FakeRateMixed_UL16postVFP(11, Recoil_L3, LooseLep.at(3).v);
	}
	
	//Calculating the multiplicative factor to calculate N_F
	double mf = 1/((p2-f2)*(p3-f3));
	  
	//Calculating the N_FF, N_FP, N_PF
	double N_FF = mf*(p2*p3*N_LL-p2*(1-p3)*N_LT-(1-p2)*p3*N_TL+(1-p2)*(1-p3)*N_TT);
	double N_FP = mf*((-1)*p2*f3*N_LL+p2*(1-f3)*N_LT+(1-p2)*f3*N_TL-(1-p2)*(1-f3)*N_TT);
	double N_PF = mf*((-1)*f2*p3*N_LL+f2*(1-p3)*N_LT+(1-f2)*p3*N_TL-(1-f2)*(1-p3)*N_TT);
	  
	//Calculating the MisID Event weight
	N_T_fake = f2*f3*N_FF + f2*p3*N_FP + p2*f3*N_PF;
      }
    }

    //Four Muon Final state
    if(mu4 && isSMTriggered){
      if(LooseLep.at(0).id*LooseLep.at(1).id == -169){
	if(LooseLep.at(2).id*LooseLep.at(3).id == -169){
	  pairing1.push_back(LooseLep.at(0));
	  pairing1.push_back(LooseLep.at(1));
	  pairing1.push_back(LooseLep.at(2));
	  pairing1.push_back(LooseLep.at(3));
	}
      }
      if(LooseLep.at(0).id*LooseLep.at(2).id == -169){
	if(LooseLep.at(1).id*LooseLep.at(3).id == -169){
	  pairing2.push_back(LooseLep.at(0));
	  pairing2.push_back(LooseLep.at(2));
	  pairing2.push_back(LooseLep.at(1));
	  pairing2.push_back(LooseLep.at(3));
	}
      }
      if(LooseLep.at(0).id*LooseLep.at(3).id == -169){
	if(LooseLep.at(1).id*LooseLep.at(2).id == -169){
	  pairing3.push_back(LooseLep.at(0));
	  pairing3.push_back(LooseLep.at(3));
	  pairing3.push_back(LooseLep.at(1));
	  pairing3.push_back(LooseLep.at(2));
	}
      }
      
      if(pairing1.size()>3 && pairing2.size()>3)
	pairing12= true;
      if(pairing1.size()>3 && pairing3.size()>3)
	pairing13 = true;
      if(pairing2.size()>3 && pairing3.size()>3)
	pairing23 = true;
      
      if(pairing12){
	mass_01_12 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	mass_23_12 = (LooseLep.at(2).v+LooseLep.at(3).v).M();
	mass_02_12 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	mass_13_12 = (LooseLep.at(1).v+LooseLep.at(3).v).M();
	pT_01_12   = (LooseLep.at(0).v+LooseLep.at(1).v).Pt();
	pT_23_12   = (LooseLep.at(2).v+LooseLep.at(3).v).Pt();
	pT_02_12   = (LooseLep.at(0).v+LooseLep.at(2).v).Pt();
	pT_13_12   = (LooseLep.at(1).v+LooseLep.at(3).v).Pt();
	float massdiff_pairing1 = fabs(mass_01_12-91.2)+fabs(mass_23_12-91.2);
	float massdiff_pairing2 = fabs(mass_02_12-91.2)+fabs(mass_13_12-91.2);
	if(massdiff_pairing1<massdiff_pairing2)
	  chosen1 = true;
	else
	  chosen2 = true;
      }
      
      if(pairing13){
	mass_01_13 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	mass_23_13 = (LooseLep.at(2).v+LooseLep.at(3).v).M();
	mass_03_13 = (LooseLep.at(0).v+LooseLep.at(3).v).M();
	mass_12_13 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	pT_01_13   = (LooseLep.at(0).v+LooseLep.at(1).v).Pt();
	pT_23_13   = (LooseLep.at(2).v+LooseLep.at(3).v).Pt();
	pT_03_13   = (LooseLep.at(0).v+LooseLep.at(3).v).Pt();
	pT_12_13   = (LooseLep.at(1).v+LooseLep.at(2).v).Pt();
	float massdiff_pairing1 = fabs(mass_01_13-91.2)+fabs(mass_23_13-91.2);
	float massdiff_pairing3 = fabs(mass_03_13-91.2)+fabs(mass_12_13-91.2);
	if(massdiff_pairing1<massdiff_pairing3)
	  chosen3 = true;
	else
	  chosen4 = true;
      }
    
      if(pairing23){
	mass_02_23 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	mass_13_23 = (LooseLep.at(1).v+LooseLep.at(3).v).M();
	mass_03_23 = (LooseLep.at(0).v+LooseLep.at(3).v).M();
	mass_12_23 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	pT_02_23   = (LooseLep.at(0).v+LooseLep.at(2).v).Pt();
	pT_13_23   = (LooseLep.at(1).v+LooseLep.at(3).v).Pt();
	pT_03_23   = (LooseLep.at(0).v+LooseLep.at(3).v).Pt();
	pT_12_23   = (LooseLep.at(1).v+LooseLep.at(2).v).Pt();
	float massdiff_pairing2 = fabs(mass_02_23-91.2)+fabs(mass_13_23-91.2);
	float massdiff_pairing3 = fabs(mass_03_23-91.2)+fabs(mass_12_23-91.2);
	if(massdiff_pairing2<massdiff_pairing3)
	  chosen5 = true;
	else
	  chosen6 = true;
      }
    }

    //Four Electron Final state
    if(e4 && isSETriggered){
      if(LooseLep.at(0).id*LooseLep.at(1).id == -121){
	if(LooseLep.at(2).id*LooseLep.at(3).id == -121){
	  pairing1.push_back(LooseLep.at(0));
	  pairing1.push_back(LooseLep.at(1));
	  pairing1.push_back(LooseLep.at(2));
	  pairing1.push_back(LooseLep.at(3));
	}
      }
      if(LooseLep.at(0).id*LooseLep.at(2).id == -121){
	if(LooseLep.at(1).id*LooseLep.at(3).id == -121){
	  pairing2.push_back(LooseLep.at(0));
	  pairing2.push_back(LooseLep.at(2));
	  pairing2.push_back(LooseLep.at(1));
	  pairing2.push_back(LooseLep.at(3));
	}
      }
      if(LooseLep.at(0).id*LooseLep.at(3).id == -121){
	if(LooseLep.at(1).id*LooseLep.at(2).id == -121){
	  pairing3.push_back(LooseLep.at(0));
	  pairing3.push_back(LooseLep.at(3));
	  pairing3.push_back(LooseLep.at(1));
	  pairing3.push_back(LooseLep.at(2));
	}
      }

      if(pairing1.size()>3 && pairing2.size()>3)
	pairing12= true;
      if(pairing1.size()>3 && pairing3.size()>3)
	pairing13 = true;
      if(pairing2.size()>3 && pairing3.size()>3)
	pairing23 = true;

      if(pairing12){
	mass_01_12 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	mass_23_12 = (LooseLep.at(2).v+LooseLep.at(3).v).M();
	mass_02_12 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	mass_13_12 = (LooseLep.at(1).v+LooseLep.at(3).v).M();
	pT_01_12   = (LooseLep.at(0).v+LooseLep.at(1).v).Pt();
	pT_23_12   = (LooseLep.at(2).v+LooseLep.at(3).v).Pt();
	pT_02_12   = (LooseLep.at(0).v+LooseLep.at(2).v).Pt();
	pT_13_12   = (LooseLep.at(1).v+LooseLep.at(3).v).Pt();
	float massdiff_pairing1 = fabs(mass_01_12-91.2)+fabs(mass_23_12-91.2);
	float massdiff_pairing2 = fabs(mass_02_12-91.2)+fabs(mass_13_12-91.2);
	if(massdiff_pairing1<massdiff_pairing2)
	  chosen1 = true;
	else
	  chosen2 = true;
      }
  
      if(pairing13){
	mass_01_13 = (LooseLep.at(0).v+LooseLep.at(1).v).M();
	mass_23_13 = (LooseLep.at(2).v+LooseLep.at(3).v).M();
	mass_03_13 = (LooseLep.at(0).v+LooseLep.at(3).v).M();
	mass_12_13 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	pT_01_12   = (LooseLep.at(0).v+LooseLep.at(1).v).Pt();
	pT_23_12   = (LooseLep.at(2).v+LooseLep.at(3).v).Pt();
	pT_02_12   = (LooseLep.at(0).v+LooseLep.at(2).v).Pt();
	pT_13_12   = (LooseLep.at(1).v+LooseLep.at(3).v).Pt();
	float massdiff_pairing1 = fabs(mass_01_13-91.2)+fabs(mass_23_13-91.2);
	float massdiff_pairing3 = fabs(mass_03_13-91.2)+fabs(mass_12_13-91.2);
	if(massdiff_pairing1<massdiff_pairing3)
	  chosen3 = true;
	else
	  chosen4 = true;
      }
    
      if(pairing23){
	mass_02_23 = (LooseLep.at(0).v+LooseLep.at(2).v).M();
	mass_13_23 = (LooseLep.at(1).v+LooseLep.at(3).v).M();
	mass_03_23 = (LooseLep.at(0).v+LooseLep.at(3).v).M();
	mass_12_23 = (LooseLep.at(1).v+LooseLep.at(2).v).M();
	pT_02_23   = (LooseLep.at(0).v+LooseLep.at(2).v).Pt();
	pT_13_23   = (LooseLep.at(1).v+LooseLep.at(3).v).Pt();
	pT_03_23   = (LooseLep.at(0).v+LooseLep.at(3).v).Pt();
	pT_12_23   = (LooseLep.at(1).v+LooseLep.at(2).v).Pt();
	float massdiff_pairing2 = fabs(mass_02_23-91.2)+fabs(mass_13_23-91.2);
	float massdiff_pairing3 = fabs(mass_03_23-91.2)+fabs(mass_12_23-91.2);
	if(massdiff_pairing2<massdiff_pairing3)
	  chosen5 = true;
	else
	  chosen6 = true;
      }
    }
  
    if(pairing12){
      if(chosen1){
	MassArray_4L.push_back(mass_01_12);
	MassArray_4L.push_back(mass_23_12);
	MassArray_pT.push_back(pT_01_12);
	MassArray_pT.push_back(pT_23_12);
      }
      if(chosen2){
	MassArray_4L.push_back(mass_02_12);
	MassArray_4L.push_back(mass_13_12);
	MassArray_pT.push_back(pT_02_12);
	MassArray_pT.push_back(pT_13_12);
      }
    }
    if(pairing13){
      if(chosen3){
	MassArray_4L.push_back(mass_01_13);
	MassArray_4L.push_back(mass_23_13);
	MassArray_pT.push_back(pT_01_13);
	MassArray_pT.push_back(pT_23_13);
      }
      if(chosen4){
	MassArray_4L.push_back(mass_03_13);
	MassArray_4L.push_back(mass_12_13);
	MassArray_pT.push_back(pT_03_13);
	MassArray_pT.push_back(pT_12_13);
      }
    }
    if(pairing23){
      if(chosen5){
	MassArray_4L.push_back(mass_02_23);
	MassArray_4L.push_back(mass_13_23);
	MassArray_pT.push_back(pT_02_23);
	MassArray_pT.push_back(pT_13_23);
      }
      if(chosen6){
	MassArray_4L.push_back(mass_03_23);
	MassArray_4L.push_back(mass_12_23);
	MassArray_pT.push_back(pT_03_23);
	MassArray_pT.push_back(pT_12_23);
      }
    }
  
    //2 Electron and 2 Muon Final state
    if(e2mu2){
      if(isSMTriggered || isSETriggered){
	if(LooseLep.at(0).id*LooseLep.at(1).id == -169){
	  if(LooseLep.at(2).id*LooseLep.at(3).id == -121){
	    MassArray_4L.push_back((LooseLep.at(0).v+LooseLep.at(1).v).M());
	    MassArray_4L.push_back((LooseLep.at(2).v+LooseLep.at(3).v).M());
	    MassArray_pT.push_back((LooseLep.at(0).v+LooseLep.at(1).v).Pt());
	    MassArray_pT.push_back((LooseLep.at(2).v+LooseLep.at(3).v).Pt());
	  }
	}
	if(LooseLep.at(0).id*LooseLep.at(2).id == -169){
	  if(LooseLep.at(1).id*LooseLep.at(3).id == -121){
	    MassArray_4L.push_back((LooseLep.at(0).v+LooseLep.at(2).v).M());
	    MassArray_4L.push_back((LooseLep.at(1).v+LooseLep.at(3).v).M());
	    MassArray_pT.push_back((LooseLep.at(0).v+LooseLep.at(2).v).Pt());
	    MassArray_pT.push_back((LooseLep.at(1).v+LooseLep.at(3).v).Pt());
	  }
	}
	if(LooseLep.at(0).id*LooseLep.at(3).id == -169){
	  if(LooseLep.at(1).id*LooseLep.at(2).id == -121){
	    MassArray_4L.push_back((LooseLep.at(0).v+LooseLep.at(3).v).M());
	    MassArray_4L.push_back((LooseLep.at(1).v+LooseLep.at(2).v).M());
	    MassArray_pT.push_back((LooseLep.at(0).v+LooseLep.at(3).v).Pt());
	    MassArray_pT.push_back((LooseLep.at(1).v+LooseLep.at(2).v).Pt());
	  }
	}
	if(LooseLep.at(1).id*LooseLep.at(2).id == -169){
	  if(LooseLep.at(0).id*LooseLep.at(3).id == -121){
	    MassArray_4L.push_back((LooseLep.at(1).v+LooseLep.at(2).v).M());
	    MassArray_4L.push_back((LooseLep.at(0).v+LooseLep.at(3).v).M());
	    MassArray_pT.push_back((LooseLep.at(1).v+LooseLep.at(2).v).Pt());
	    MassArray_pT.push_back((LooseLep.at(0).v+LooseLep.at(3).v).Pt());
	  }
	}
	if(LooseLep.at(1).id*LooseLep.at(3).id == -169){
	  if(LooseLep.at(0).id*LooseLep.at(2).id == -121){
	    MassArray_4L.push_back((LooseLep.at(1).v+LooseLep.at(3).v).M());
	    MassArray_4L.push_back((LooseLep.at(0).v+LooseLep.at(2).v).M());
	    MassArray_pT.push_back((LooseLep.at(1).v+LooseLep.at(3).v).Pt());
	    MassArray_pT.push_back((LooseLep.at(0).v+LooseLep.at(2).v).Pt());
	  }
	}
	if(LooseLep.at(2).id*LooseLep.at(3).id == -169){
	  if(LooseLep.at(0).id*LooseLep.at(1).id == -121){
	    MassArray_4L.push_back((LooseLep.at(2).v+LooseLep.at(3).v).M());
	    MassArray_4L.push_back((LooseLep.at(0).v+LooseLep.at(1).v).M());
	    MassArray_pT.push_back((LooseLep.at(2).v+LooseLep.at(3).v).Pt());
	    MassArray_pT.push_back((LooseLep.at(0).v+LooseLep.at(1).v).Pt());
	  }
	}
      }
    }

    //MisID Prediction: ZZ CR
    if((int)MassArray_4L.size()>0 && (int)MassArray_pT.size()>0){
      if(76<MassArray_4L.at(0) && MassArray_4L.at(0)<106){//Pair 1 is a Z
	if(76<MassArray_4L.at(1) && MassArray_4L.at(1)<106){//Pair 2 is a Z
	  if(*PuppiMET_pt < 60){
	    if((int)bJets.size()==0){
	      veto_ZZ_LooseLep = false;
	      h.ZZ_CR[29]->Fill(1,N_T_fake);
	      h.ZZ_CR[25]->Fill((int)MassArray_4L.size(),N_T_fake);
	      h.ZZ_CR[30]->Fill((int)LooseLep.size(),N_T_fake);
	      h.ZZ_CR[31]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	      h.ZZ_CR[32]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	      h.ZZ_CR[33]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	      h.ZZ_CR[34]->Fill(LooseLep.at(3).v.Pt(),N_T_fake);
	      h.ZZ_CR[35]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	      h.ZZ_CR[36]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	      h.ZZ_CR[37]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	      h.ZZ_CR[38]->Fill(LooseLep.at(3).v.Eta(),N_T_fake);
	      h.ZZ_CR[39]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	      h.ZZ_CR[40]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	      h.ZZ_CR[41]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	      h.ZZ_CR[42]->Fill(LooseLep.at(3).v.Phi(),N_T_fake);
	      //------>Event Level Kinematics
	      h.ZZ_CR[43]->Fill(LT_MisID,N_T_fake);
	      h.ZZ_CR[44]->Fill(*PuppiMET_pt,N_T_fake);
	      h.ZZ_CR[45]->Fill(LT_PuppiMET_MisID,N_T_fake);
	      //------>Angular Variables
	      h.ZZ_CR[46]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.ZZ_CR[47]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.ZZ_CR[48]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.ZZ_CR[49]->Fill(delta_phi(LooseLep.at(3).v.Phi(),*PuppiMET_phi),N_T_fake);
	      h.ZZ_CR[50]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	      h.ZZ_CR[51]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	      h.ZZ_CR[52]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	      h.ZZ_CR[53]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	      h.ZZ_CR[54]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	      h.ZZ_CR[55]->Fill(delta_phi(LooseLep.at(2).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	      //------>Transverse Mass
	      h.ZZ_CR[56]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.ZZ_CR[57]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.ZZ_CR[58]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      h.ZZ_CR[59]->Fill(transv_mass(LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	      //------>DeltaR Plots
	      h.ZZ_CR[60]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	      h.ZZ_CR[61]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	      h.ZZ_CR[62]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	      h.ZZ_CR[63]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	      h.ZZ_CR[64]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	      h.ZZ_CR[65]->Fill(LooseLep.at(2).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	      //Invariant Mass
	      h.ZZ_CR[66]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	      h.ZZ_CR[67]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	      h.ZZ_CR[68]->Fill((LooseLep.at(0).v+LooseLep.at(3).v).M(),N_T_fake);
	      h.ZZ_CR[69]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	      h.ZZ_CR[70]->Fill((LooseLep.at(1).v+LooseLep.at(3).v).M(),N_T_fake);
	      h.ZZ_CR[71]->Fill((LooseLep.at(2).v+LooseLep.at(3).v).M(),N_T_fake);
	      h.ZZ_CR[72]->Fill(HT_MisID,N_T_fake);
	      h.ZZ_CR[73]->Fill(ST_MisID,N_T_fake);
	      h.ZZ_CR[75]->Fill((int)bJets.size(),N_T_fake);
	      h.ZZ_CR[76]->Fill((int)Jets.size(),N_T_fake);
	      h.ZZ_CR[77]->Fill(MassArray_4L.at(0),N_T_fake);
	      h.ZZ_CR[78]->Fill(MassArray_4L.at(1),N_T_fake);
	      h.ZZ_CR[79]->Fill(MassArray_pT.at(0),N_T_fake);
	      h.ZZ_CR[80]->Fill(MassArray_pT.at(1),N_T_fake);
	    }
	  }
	}
      }
    }

    //Signal Region: 4L
    bool Bin1_4L = false;
    bool Bin2_4L = false;
    bool Bin3_4L = false;
    bool Bin4_4L = false;
    
    bool doublet_4L = false;
    //bool doublet_4L = true;
    bool singlet_4L = false;
    //bool singlet_4L = true;
    
    if(is_l4_MisID_event && veto_ZZ_LooseLep){
      if((int)bJets.size() == 0){
	if(doublet_4L){
	  if(LooseLep.at(0).v.Pt() > 200){
	    if(*PuppiMET_pt > 100)
	      Bin1_4L = true;
	    if(*PuppiMET_pt < 100)
	      Bin2_4L = true;
	  }
	  if(LooseLep.at(0).v.Pt() < 200){
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
	
	h.hist_l4[0]->Fill((int)LooseLep.size(),N_T_fake);
	h.hist_l4[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	h.hist_l4[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	h.hist_l4[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	h.hist_l4[4]->Fill(LooseLep.at(3).v.Pt(),N_T_fake);
	h.hist_l4[5]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	h.hist_l4[6]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	h.hist_l4[7]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	h.hist_l4[8]->Fill(LooseLep.at(3).v.Eta(),N_T_fake);
	h.hist_l4[9]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	h.hist_l4[10]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	h.hist_l4[11]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	h.hist_l4[12]->Fill(LooseLep.at(3).v.Phi(),N_T_fake);
	//------>Event Level Kinematics
	h.hist_l4[13]->Fill(LT_MisID,N_T_fake);
	h.hist_l4[14]->Fill(*PuppiMET_pt,N_T_fake);
	h.hist_l4[15]->Fill(LT_PuppiMET_MisID,N_T_fake);
	//------>Angular Variables
	h.hist_l4[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	h.hist_l4[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	h.hist_l4[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	h.hist_l4[19]->Fill(delta_phi(LooseLep.at(3).v.Phi(),*PuppiMET_phi),N_T_fake);
	h.hist_l4[20]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	h.hist_l4[21]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	h.hist_l4[22]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	h.hist_l4[23]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	h.hist_l4[24]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	h.hist_l4[25]->Fill(delta_phi(LooseLep.at(2).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	//------>Transverse Mass
	h.hist_l4[26]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	h.hist_l4[27]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	h.hist_l4[28]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	h.hist_l4[29]->Fill(transv_mass(LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	//------>DeltaR Plots
	h.hist_l4[30]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	h.hist_l4[31]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	h.hist_l4[32]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	h.hist_l4[33]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	h.hist_l4[34]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	h.hist_l4[35]->Fill(LooseLep.at(2).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	//Invariant Mass
	h.hist_l4[36]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	h.hist_l4[37]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	h.hist_l4[38]->Fill((LooseLep.at(0).v+LooseLep.at(3).v).M(),N_T_fake);
	h.hist_l4[39]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	h.hist_l4[40]->Fill((LooseLep.at(1).v+LooseLep.at(3).v).M(),N_T_fake);
	h.hist_l4[41]->Fill((LooseLep.at(2).v+LooseLep.at(3).v).M(),N_T_fake);
	h.hist_l4[43]->Fill(ST_MisID,N_T_fake);
	h.hist_l4[42]->Fill(HT_MisID,N_T_fake);
	h.hist_l4[44]->Fill((int)bJets.size(),N_T_fake);
	h.hist_l4[45]->Fill((int)Jets.size(),N_T_fake);
	if(Bin1_4L){
	  h.hist_l4_Bin1[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l4_Bin1[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l4_Bin1[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l4_Bin1[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l4_Bin1[4]->Fill(LooseLep.at(3).v.Pt(),N_T_fake);
	  h.hist_l4_Bin1[5]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l4_Bin1[6]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l4_Bin1[7]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l4_Bin1[8]->Fill(LooseLep.at(3).v.Eta(),N_T_fake);
	  h.hist_l4_Bin1[9]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l4_Bin1[10]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l4_Bin1[11]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  h.hist_l4_Bin1[12]->Fill(LooseLep.at(3).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l4_Bin1[13]->Fill(LT_MisID,N_T_fake);
	  h.hist_l4_Bin1[14]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l4_Bin1[15]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l4_Bin1[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin1[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin1[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin1[19]->Fill(delta_phi(LooseLep.at(3).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin1[20]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l4_Bin1[21]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin1[22]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin1[23]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin1[24]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin1[25]->Fill(delta_phi(LooseLep.at(2).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l4_Bin1[26]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin1[27]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin1[28]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin1[29]->Fill(transv_mass(LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l4_Bin1[30]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l4_Bin1[31]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin1[32]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin1[33]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin1[34]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin1[35]->Fill(LooseLep.at(2).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l4_Bin1[36]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l4_Bin1[37]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin1[38]->Fill((LooseLep.at(0).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin1[39]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin1[40]->Fill((LooseLep.at(1).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin1[41]->Fill((LooseLep.at(2).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin1[43]->Fill(ST_MisID,N_T_fake);
	  h.hist_l4_Bin1[42]->Fill(HT_MisID,N_T_fake);
	  h.hist_l4_Bin1[44]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l4_Bin1[45]->Fill((int)Jets.size(),N_T_fake);
	}
	if(Bin2_4L){
	  h.hist_l4_Bin2[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l4_Bin2[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l4_Bin2[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l4_Bin2[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l4_Bin2[4]->Fill(LooseLep.at(3).v.Pt(),N_T_fake);
	  h.hist_l4_Bin2[5]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l4_Bin2[6]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l4_Bin2[7]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l4_Bin2[8]->Fill(LooseLep.at(3).v.Eta(),N_T_fake);
	  h.hist_l4_Bin2[9]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l4_Bin2[10]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l4_Bin2[11]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  h.hist_l4_Bin2[12]->Fill(LooseLep.at(3).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l4_Bin2[13]->Fill(LT_MisID,N_T_fake);
	  h.hist_l4_Bin2[14]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l4_Bin2[15]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l4_Bin2[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin2[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin2[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin2[19]->Fill(delta_phi(LooseLep.at(3).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin2[20]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l4_Bin2[21]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin2[22]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin2[23]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin2[24]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin2[25]->Fill(delta_phi(LooseLep.at(2).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l4_Bin2[26]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin2[27]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin2[28]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin2[29]->Fill(transv_mass(LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l4_Bin2[30]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l4_Bin2[31]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin2[32]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin2[33]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin2[34]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin2[35]->Fill(LooseLep.at(2).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l4_Bin2[36]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l4_Bin2[37]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin2[38]->Fill((LooseLep.at(0).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin2[39]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin2[40]->Fill((LooseLep.at(1).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin2[41]->Fill((LooseLep.at(2).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin2[43]->Fill(ST_MisID,N_T_fake);
	  h.hist_l4_Bin2[42]->Fill(HT_MisID,N_T_fake);
	  h.hist_l4_Bin2[44]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l4_Bin2[45]->Fill((int)Jets.size(),N_T_fake);
	}
	if(Bin3_4L){
	  h.hist_l4_Bin3[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l4_Bin3[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l4_Bin3[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l4_Bin3[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l4_Bin3[4]->Fill(LooseLep.at(3).v.Pt(),N_T_fake);
	  h.hist_l4_Bin3[5]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l4_Bin3[6]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l4_Bin3[7]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l4_Bin3[8]->Fill(LooseLep.at(3).v.Eta(),N_T_fake);
	  h.hist_l4_Bin3[9]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l4_Bin3[10]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l4_Bin3[11]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  h.hist_l4_Bin3[12]->Fill(LooseLep.at(3).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l4_Bin3[13]->Fill(LT_MisID,N_T_fake);
	  h.hist_l4_Bin3[14]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l4_Bin3[15]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l4_Bin3[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin3[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin3[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin3[19]->Fill(delta_phi(LooseLep.at(3).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin3[20]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l4_Bin3[21]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin3[22]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin3[23]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin3[24]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin3[25]->Fill(delta_phi(LooseLep.at(2).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l4_Bin3[26]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin3[27]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin3[28]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin3[29]->Fill(transv_mass(LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l4_Bin3[30]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l4_Bin3[31]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin3[32]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin3[33]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin3[34]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin3[35]->Fill(LooseLep.at(2).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l4_Bin3[36]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l4_Bin3[37]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin3[38]->Fill((LooseLep.at(0).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin3[39]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin3[40]->Fill((LooseLep.at(1).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin3[41]->Fill((LooseLep.at(2).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin3[43]->Fill(ST_MisID,N_T_fake);
	  h.hist_l4_Bin3[42]->Fill(HT_MisID,N_T_fake);
	  h.hist_l4_Bin3[44]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l4_Bin3[45]->Fill((int)Jets.size(),N_T_fake);
	}
	if(Bin4_4L){
	  h.hist_l4_Bin4[0]->Fill((int)LooseLep.size(),N_T_fake);
	  h.hist_l4_Bin4[1]->Fill(LooseLep.at(0).v.Pt(),N_T_fake);
	  h.hist_l4_Bin4[2]->Fill(LooseLep.at(1).v.Pt(),N_T_fake);
	  h.hist_l4_Bin4[3]->Fill(LooseLep.at(2).v.Pt(),N_T_fake);
	  h.hist_l4_Bin4[4]->Fill(LooseLep.at(3).v.Pt(),N_T_fake);
	  h.hist_l4_Bin4[5]->Fill(LooseLep.at(0).v.Eta(),N_T_fake);
	  h.hist_l4_Bin4[6]->Fill(LooseLep.at(1).v.Eta(),N_T_fake);
	  h.hist_l4_Bin4[7]->Fill(LooseLep.at(2).v.Eta(),N_T_fake);
	  h.hist_l4_Bin4[8]->Fill(LooseLep.at(3).v.Eta(),N_T_fake);
	  h.hist_l4_Bin4[9]->Fill(LooseLep.at(0).v.Phi(),N_T_fake);
	  h.hist_l4_Bin4[10]->Fill(LooseLep.at(1).v.Phi(),N_T_fake);
	  h.hist_l4_Bin4[11]->Fill(LooseLep.at(2).v.Phi(),N_T_fake);
	  h.hist_l4_Bin4[12]->Fill(LooseLep.at(3).v.Phi(),N_T_fake);
	  //------>Event Level Kinematics
	  h.hist_l4_Bin4[13]->Fill(LT_MisID,N_T_fake);
	  h.hist_l4_Bin4[14]->Fill(*PuppiMET_pt,N_T_fake);
	  h.hist_l4_Bin4[15]->Fill(LT_PuppiMET_MisID,N_T_fake);
	  //------>Angular Variables
	  h.hist_l4_Bin4[16]->Fill(delta_phi(LooseLep.at(0).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin4[17]->Fill(delta_phi(LooseLep.at(1).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin4[18]->Fill(delta_phi(LooseLep.at(2).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin4[19]->Fill(delta_phi(LooseLep.at(3).v.Phi(),*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin4[20]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(1).v.Phi()),N_T_fake);
	  h.hist_l4_Bin4[21]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin4[22]->Fill(delta_phi(LooseLep.at(0).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin4[23]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(2).v.Phi()),N_T_fake);
	  h.hist_l4_Bin4[24]->Fill(delta_phi(LooseLep.at(1).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  h.hist_l4_Bin4[25]->Fill(delta_phi(LooseLep.at(2).v.Phi(),LooseLep.at(3).v.Phi()),N_T_fake);
	  //------>Transverse Mass
	  h.hist_l4_Bin4[26]->Fill(transv_mass(LooseLep.at(0).v.Pt(),LooseLep.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin4[27]->Fill(transv_mass(LooseLep.at(1).v.Pt(),LooseLep.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin4[28]->Fill(transv_mass(LooseLep.at(2).v.Pt(),LooseLep.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  h.hist_l4_Bin4[29]->Fill(transv_mass(LooseLep.at(3).v.Pt(),LooseLep.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),N_T_fake);
	  //------>DeltaR Plots
	  h.hist_l4_Bin4[30]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(1).v),N_T_fake);
	  h.hist_l4_Bin4[31]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin4[32]->Fill(LooseLep.at(0).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin4[33]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(2).v),N_T_fake);
	  h.hist_l4_Bin4[34]->Fill(LooseLep.at(1).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  h.hist_l4_Bin4[35]->Fill(LooseLep.at(2).v.DeltaR(LooseLep.at(3).v),N_T_fake);
	  //Invariant Mass
	  h.hist_l4_Bin4[36]->Fill((LooseLep.at(0).v+LooseLep.at(1).v).M(),N_T_fake);
	  h.hist_l4_Bin4[37]->Fill((LooseLep.at(0).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin4[38]->Fill((LooseLep.at(0).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin4[39]->Fill((LooseLep.at(1).v+LooseLep.at(2).v).M(),N_T_fake);
	  h.hist_l4_Bin4[40]->Fill((LooseLep.at(1).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin4[41]->Fill((LooseLep.at(2).v+LooseLep.at(3).v).M(),N_T_fake);
	  h.hist_l4_Bin4[43]->Fill(ST_MisID,N_T_fake);
	  h.hist_l4_Bin4[42]->Fill(HT_MisID,N_T_fake);
	  h.hist_l4_Bin4[44]->Fill((int)bJets.size(),N_T_fake);
	  h.hist_l4_Bin4[45]->Fill((int)Jets.size(),N_T_fake);
	}
      }
    }
  }
}
