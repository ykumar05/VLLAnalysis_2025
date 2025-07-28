void AnaScript::CR_ZZ(){
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
  bool isSMTriggered = false;
  bool isSETriggered = false;
  bool isMuonTriggered = false;
  
  if(is_l4_event){
    if(abs(LightLepton.at(0).id*LightLepton.at(1).id*LightLepton.at(2).id*LightLepton.at(3).id) == 28561)
      mu4   = true;
    if(abs(LightLepton.at(0).id*LightLepton.at(1).id*LightLepton.at(2).id*LightLepton.at(3).id) == 20449)
      e2mu2 = true;
    if(abs(LightLepton.at(0).id*LightLepton.at(1).id*LightLepton.at(2).id*LightLepton.at(3).id) == 14641)
      e4    = true;
  }

  if(_data == 0){
    if(mu4 || e4 ||e2mu2){
      //SingleMuon Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2018 || _year == 2022 || _year ==2023 || _year == 3023 || _year == 3022 || _year == 2016 || _year == 3016)//2016: preVFP, 3016: postVFP
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	    isSMTriggered = true;
	if(_year == 2017)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	    isSMTriggered = true;
      }
      //SingleElectron Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2018 || _year == 2022 || _year ==2023 || _year == 3023 || _year == 3022 || _year == 2016 || _year == 3016)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	    isMuonTriggered = true;
	if(_year == 2017)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	    isMuonTriggered = true;
      }
      if(!isMuonTriggered){
	for(int j = 0; j < (int)LightLepton.size(); j++){
	  if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2017)
	    if(abs(LightLepton.at(j).id) == 11 && LightLepton.at(j).v.Pt() > 35)
	      isSETriggered = true;
	  if(_year == 2016 || _year == 3016)
	    if(abs(LightLepton.at(j).id) == 11 && LightLepton.at(j).v.Pt() > 30)
	      isSETriggered = true;
	}
      }
    }
  }

  if(_data == 1){
    if(mu4 || e4 ||e2mu2){
      //SingleMuon Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022){
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26){
	    if(_sample == 1000 || _sample == 1001 || _sample == 1002 || _sample == 1003 || _sample == 1004){
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
  }

  //bool ZZ = false;
  bool ZZ = true;
    
  //Introducing Event Weights
  float evt_weight = 1.0;
  float TriggerWeight = 0.0;

  //Run II 
  if(_data == 0 && !_run3){
    if(mu4 || e4 ||e2mu2){
      if(_year == 2018){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//Event Weight
	evt_weight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL18(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2018(_sample, Jets);
      	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*1.06;
      }
      
      if(_year == 2017){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_IsoMu27(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	evt_weight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL17(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2017(_sample, Jets);
      	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*1.045;
      }

      //2016preVFP
      if(_year == 2016){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//Event Weight
	evt_weight = LeptonID_SFUL16preVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2016preVFP(_sample, Jets);
      	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*1.129;
      }
      
      //2016postVFP
      if(_year == 3016){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//Event Weight
	evt_weight = LeptonID_SFUL16postVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSF2016postVFP(_sample, Jets);
      	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*0.954;
      }
    }   
  }

  //Run III
  if(_data == 0 && _run3){
    if(mu4 || e4 ||e2mu2){
      //Run3Summer23BPix
      if(_year == 3023){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//Event Weight
	evt_weight = LeptonID_SFRun3Summer23BPix(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSFRun3Summer2023BPix(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*0.96;
      }
      //Run3Summer23
      if(_year == 2023){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//Event Weight
	evt_weight = LeptonID_SFRun3Summer23(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSFRun3Summer2023(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*0.974;
      }
      //Run3Summer22
      if(_year == 2022){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//Event Weight
	evt_weight = LeptonID_SFRun3Summer22(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSFRun3Summer2022(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*1.004;
      }
      //Run3Summer22EE
      if(_year == 3022){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta()));
	//Event Weight
	evt_weight = LeptonID_SFRun3Summer22EE(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(3).id, LightLepton.at(3).v.Pt(), LightLepton.at(3).v.Eta())*TriggerWeight*bTagSFRun3Summer2022EE(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  evt_weight = evt_weight*1.01;
      }
    }
  }
  h.ZZ_CR[74]->Fill(evt_weight);
  
  //Four Muon Final state
  if(mu4 && isSMTriggered){
    h.ZZ_CR[26]->Fill(1,evt_weight);
    if(LightLepton.at(0).id*LightLepton.at(1).id == -169){
      if(LightLepton.at(2).id*LightLepton.at(3).id == -169){
	pairing1.push_back(LightLepton.at(0));
	pairing1.push_back(LightLepton.at(1));
	pairing1.push_back(LightLepton.at(2));
	pairing1.push_back(LightLepton.at(3));
      }
    }
    if(LightLepton.at(0).id*LightLepton.at(2).id == -169){
      if(LightLepton.at(1).id*LightLepton.at(3).id == -169){
	pairing2.push_back(LightLepton.at(0));
	pairing2.push_back(LightLepton.at(2));
	pairing2.push_back(LightLepton.at(1));
	pairing2.push_back(LightLepton.at(3));
      }
    }
    if(LightLepton.at(0).id*LightLepton.at(3).id == -169){
      if(LightLepton.at(1).id*LightLepton.at(2).id == -169){
	pairing3.push_back(LightLepton.at(0));
	pairing3.push_back(LightLepton.at(3));
	pairing3.push_back(LightLepton.at(1));
	pairing3.push_back(LightLepton.at(2));
      }
    }
    
    if(pairing1.size()>3 && pairing2.size()>3)
      pairing12= true;
    if(pairing1.size()>3 && pairing3.size()>3)
      pairing13 = true;
    if(pairing2.size()>3 && pairing3.size()>3)
      pairing23 = true;

    if(pairing12){
      mass_01_12 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      mass_23_12 = (LightLepton.at(2).v+LightLepton.at(3).v).M();
      mass_02_12 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      mass_13_12 = (LightLepton.at(1).v+LightLepton.at(3).v).M();
      pT_01_12   = (LightLepton.at(0).v+LightLepton.at(1).v).Pt();
      pT_23_12   = (LightLepton.at(2).v+LightLepton.at(3).v).Pt();
      pT_02_12   = (LightLepton.at(0).v+LightLepton.at(2).v).Pt();
      pT_13_12   = (LightLepton.at(1).v+LightLepton.at(3).v).Pt();
      float massdiff_pairing1 = fabs(mass_01_12-91.2)+fabs(mass_23_12-91.2);
      float massdiff_pairing2 = fabs(mass_02_12-91.2)+fabs(mass_13_12-91.2);
      if(massdiff_pairing1<massdiff_pairing2){
	chosen1 = true;
	h.ZZ_CR[0]->Fill(mass_01_12,evt_weight);
	h.ZZ_CR[1]->Fill(mass_23_12,evt_weight);
      }
      else{
	chosen2 = true;
	h.ZZ_CR[2]->Fill(mass_02_12,evt_weight);
	h.ZZ_CR[3]->Fill(mass_13_12,evt_weight);
      }
    }
      
    if(pairing13){
      mass_01_13 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      mass_23_13 = (LightLepton.at(2).v+LightLepton.at(3).v).M();
      mass_03_13 = (LightLepton.at(0).v+LightLepton.at(3).v).M();
      mass_12_13 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      pT_01_13   = (LightLepton.at(0).v+LightLepton.at(1).v).Pt();
      pT_23_13   = (LightLepton.at(2).v+LightLepton.at(3).v).Pt();
      pT_03_13   = (LightLepton.at(0).v+LightLepton.at(3).v).Pt();
      pT_12_13   = (LightLepton.at(1).v+LightLepton.at(2).v).Pt();
      float massdiff_pairing1 = fabs(mass_01_13-91.2)+fabs(mass_23_13-91.2);
      float massdiff_pairing3 = fabs(mass_03_13-91.2)+fabs(mass_12_13-91.2);
      if(massdiff_pairing1<massdiff_pairing3){
	chosen3 = true;
	h.ZZ_CR[4]->Fill(mass_01_13,evt_weight);
	h.ZZ_CR[5]->Fill(mass_23_13,evt_weight);
      }
      else{
	chosen4 = true;
	h.ZZ_CR[6]->Fill(mass_03_13,evt_weight);
	h.ZZ_CR[7]->Fill(mass_12_13,evt_weight);
      }
    }
    
    if(pairing23){
      mass_02_23 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      mass_13_23 = (LightLepton.at(1).v+LightLepton.at(3).v).M();
      mass_03_23 = (LightLepton.at(0).v+LightLepton.at(3).v).M();
      mass_12_23 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      pT_02_23   = (LightLepton.at(0).v+LightLepton.at(2).v).Pt();
      pT_13_23   = (LightLepton.at(1).v+LightLepton.at(3).v).Pt();
      pT_03_23   = (LightLepton.at(0).v+LightLepton.at(3).v).Pt();
      pT_12_23   = (LightLepton.at(1).v+LightLepton.at(2).v).Pt();
      float massdiff_pairing2 = fabs(mass_02_23-91.2)+fabs(mass_13_23-91.2);
      float massdiff_pairing3 = fabs(mass_03_23-91.2)+fabs(mass_12_23-91.2);
      if(massdiff_pairing2<massdiff_pairing3){
	chosen5 = true;
	h.ZZ_CR[8]->Fill(mass_02_23,evt_weight);
	h.ZZ_CR[9]->Fill(mass_13_23,evt_weight);
      }
      else{
	chosen6 = true;
	h.ZZ_CR[10]->Fill(mass_03_23,evt_weight);
	h.ZZ_CR[11]->Fill(mass_12_23,evt_weight);
      }
    }
  }

  //Four Electron Final state
  if(e4 && isSETriggered){
    h.ZZ_CR[27]->Fill(1,evt_weight);
    if(LightLepton.at(0).id*LightLepton.at(1).id == -121){
      if(LightLepton.at(2).id*LightLepton.at(3).id == -121){
	pairing1.push_back(LightLepton.at(0));
	pairing1.push_back(LightLepton.at(1));
	pairing1.push_back(LightLepton.at(2));
	pairing1.push_back(LightLepton.at(3));
      }
    }
    if(LightLepton.at(0).id*LightLepton.at(2).id == -121){
      if(LightLepton.at(1).id*LightLepton.at(3).id == -121){
	pairing2.push_back(LightLepton.at(0));
	pairing2.push_back(LightLepton.at(2));
	pairing2.push_back(LightLepton.at(1));
	pairing2.push_back(LightLepton.at(3));
      }
    }
    if(LightLepton.at(0).id*LightLepton.at(3).id == -121){
      if(LightLepton.at(1).id*LightLepton.at(2).id == -121){
	pairing3.push_back(LightLepton.at(0));
	pairing3.push_back(LightLepton.at(3));
	pairing3.push_back(LightLepton.at(1));
	pairing3.push_back(LightLepton.at(2));
      }
    }

    if(pairing1.size()>3 && pairing2.size()>3)
      pairing12= true;
    if(pairing1.size()>3 && pairing3.size()>3)
      pairing13 = true;
    if(pairing2.size()>3 && pairing3.size()>3)
      pairing23 = true;

    if(pairing12){
      mass_01_12 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      mass_23_12 = (LightLepton.at(2).v+LightLepton.at(3).v).M();
      mass_02_12 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      mass_13_12 = (LightLepton.at(1).v+LightLepton.at(3).v).M();
      pT_01_12   = (LightLepton.at(0).v+LightLepton.at(1).v).Pt();
      pT_23_12   = (LightLepton.at(2).v+LightLepton.at(3).v).Pt();
      pT_02_12   = (LightLepton.at(0).v+LightLepton.at(2).v).Pt();
      pT_13_12   = (LightLepton.at(1).v+LightLepton.at(3).v).Pt();
      float massdiff_pairing1 = fabs(mass_01_12-91.2)+fabs(mass_23_12-91.2);
      float massdiff_pairing2 = fabs(mass_02_12-91.2)+fabs(mass_13_12-91.2);
      if(massdiff_pairing1<massdiff_pairing2){
	chosen1 = true;
	h.ZZ_CR[12]->Fill(mass_01_12,evt_weight);
	h.ZZ_CR[13]->Fill(mass_23_12,evt_weight);
      }
      else{
	chosen2 = true;
	h.ZZ_CR[14]->Fill(mass_02_12,evt_weight);
	h.ZZ_CR[15]->Fill(mass_13_12,evt_weight);
      }
    }
  
    if(pairing13){
      mass_01_13 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      mass_23_13 = (LightLepton.at(2).v+LightLepton.at(3).v).M();
      mass_03_13 = (LightLepton.at(0).v+LightLepton.at(3).v).M();
      mass_12_13 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      pT_01_12   = (LightLepton.at(0).v+LightLepton.at(1).v).Pt();
      pT_23_12   = (LightLepton.at(2).v+LightLepton.at(3).v).Pt();
      pT_02_12   = (LightLepton.at(0).v+LightLepton.at(2).v).Pt();
      pT_13_12   = (LightLepton.at(1).v+LightLepton.at(3).v).Pt();
      float massdiff_pairing1 = fabs(mass_01_13-91.2)+fabs(mass_23_13-91.2);
      float massdiff_pairing3 = fabs(mass_03_13-91.2)+fabs(mass_12_13-91.2);
      if(massdiff_pairing1<massdiff_pairing3){
	chosen3 = true;
	h.ZZ_CR[16]->Fill(mass_01_13,evt_weight);
	h.ZZ_CR[17]->Fill(mass_23_13,evt_weight);
      }
      else{
	chosen4 = true;
	h.ZZ_CR[18]->Fill(mass_03_13,evt_weight);
	h.ZZ_CR[19]->Fill(mass_12_13,evt_weight);
      }
    }
    
    if(pairing23){
      mass_02_23 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      mass_13_23 = (LightLepton.at(1).v+LightLepton.at(3).v).M();
      mass_03_23 = (LightLepton.at(0).v+LightLepton.at(3).v).M();
      mass_12_23 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      pT_02_23   = (LightLepton.at(0).v+LightLepton.at(2).v).Pt();
      pT_13_23   = (LightLepton.at(1).v+LightLepton.at(3).v).Pt();
      pT_03_23   = (LightLepton.at(0).v+LightLepton.at(3).v).Pt();
      pT_12_23   = (LightLepton.at(1).v+LightLepton.at(2).v).Pt();
      float massdiff_pairing2 = fabs(mass_02_23-91.2)+fabs(mass_13_23-91.2);
      float massdiff_pairing3 = fabs(mass_03_23-91.2)+fabs(mass_12_23-91.2);
      if(massdiff_pairing2<massdiff_pairing3){
	chosen5 = true;
	h.ZZ_CR[20]->Fill(mass_02_23,evt_weight);
	h.ZZ_CR[21]->Fill(mass_13_23,evt_weight);
      }
      else{
	chosen6 = true;
	h.ZZ_CR[22]->Fill(mass_03_23,evt_weight);
	h.ZZ_CR[23]->Fill(mass_12_23,evt_weight);
      }
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
      h.ZZ_CR[28]->Fill(1,evt_weight);
      if(LightLepton.at(0).id*LightLepton.at(1).id == -169){
	if(LightLepton.at(2).id*LightLepton.at(3).id == -121){
	  MassArray_4L.push_back((LightLepton.at(0).v+LightLepton.at(1).v).M());
	  MassArray_4L.push_back((LightLepton.at(2).v+LightLepton.at(3).v).M());
	  MassArray_pT.push_back((LightLepton.at(0).v+LightLepton.at(1).v).Pt());
	  MassArray_pT.push_back((LightLepton.at(2).v+LightLepton.at(3).v).Pt());
	}
      }
      if(LightLepton.at(0).id*LightLepton.at(2).id == -169){
	if(LightLepton.at(1).id*LightLepton.at(3).id == -121){
	  MassArray_4L.push_back((LightLepton.at(0).v+LightLepton.at(2).v).M());
	  MassArray_4L.push_back((LightLepton.at(1).v+LightLepton.at(3).v).M());
	  MassArray_pT.push_back((LightLepton.at(0).v+LightLepton.at(2).v).Pt());
	  MassArray_pT.push_back((LightLepton.at(1).v+LightLepton.at(3).v).Pt());
	}
      }
      if(LightLepton.at(0).id*LightLepton.at(3).id == -169){
	if(LightLepton.at(1).id*LightLepton.at(2).id == -121){
	  MassArray_4L.push_back((LightLepton.at(0).v+LightLepton.at(3).v).M());
	  MassArray_4L.push_back((LightLepton.at(1).v+LightLepton.at(2).v).M());
	  MassArray_pT.push_back((LightLepton.at(0).v+LightLepton.at(3).v).Pt());
	  MassArray_pT.push_back((LightLepton.at(1).v+LightLepton.at(2).v).Pt());
	}
      }
      if(LightLepton.at(1).id*LightLepton.at(2).id == -169){
	if(LightLepton.at(0).id*LightLepton.at(3).id == -121){
	  MassArray_4L.push_back((LightLepton.at(1).v+LightLepton.at(2).v).M());
	  MassArray_4L.push_back((LightLepton.at(0).v+LightLepton.at(3).v).M());
	  MassArray_pT.push_back((LightLepton.at(1).v+LightLepton.at(2).v).Pt());
	  MassArray_pT.push_back((LightLepton.at(0).v+LightLepton.at(3).v).Pt());
	}
      }
      if(LightLepton.at(1).id*LightLepton.at(3).id == -169){
	if(LightLepton.at(0).id*LightLepton.at(2).id == -121){
	  MassArray_4L.push_back((LightLepton.at(1).v+LightLepton.at(3).v).M());
	  MassArray_4L.push_back((LightLepton.at(0).v+LightLepton.at(2).v).M());
	  MassArray_pT.push_back((LightLepton.at(1).v+LightLepton.at(3).v).Pt());
	  MassArray_pT.push_back((LightLepton.at(0).v+LightLepton.at(2).v).Pt());
	}
      }
      if(LightLepton.at(2).id*LightLepton.at(3).id == -169){
	if(LightLepton.at(0).id*LightLepton.at(1).id == -121){
	  MassArray_4L.push_back((LightLepton.at(2).v+LightLepton.at(3).v).M());
	  MassArray_4L.push_back((LightLepton.at(0).v+LightLepton.at(1).v).M());
	  MassArray_pT.push_back((LightLepton.at(2).v+LightLepton.at(3).v).Pt());
	  MassArray_pT.push_back((LightLepton.at(0).v+LightLepton.at(1).v).Pt());
	}
      }
    }
  }
 
  //ZZ CR
  if((int)MassArray_4L.size()>0 && (int)MassArray_pT.size()>0){
    h.ZZ_CR[24]->Fill((int)MassArray_4L.size(),evt_weight);
    if(76<MassArray_4L.at(0) && MassArray_4L.at(0)<106){//Pair 1 is a Z
      if(76<MassArray_4L.at(1) && MassArray_4L.at(1)<106){//Pair 2 is a Z
	if(*PuppiMET_pt < 60){
	  if((int)bJets.size()==0){
	    veto_ZZ = false;
	    if(ZZ){
	      h.ZZ_CR[29]->Fill(1,evt_weight);
	      h.ZZ_CR[25]->Fill((int)MassArray_4L.size(),evt_weight);
	      h.ZZ_CR[30]->Fill((int)LightLepton.size(),evt_weight);
	      h.ZZ_CR[31]->Fill(LightLepton.at(0).v.Pt(),evt_weight);
	      h.ZZ_CR[32]->Fill(LightLepton.at(1).v.Pt(),evt_weight);
	      h.ZZ_CR[33]->Fill(LightLepton.at(2).v.Pt(),evt_weight);
	      h.ZZ_CR[34]->Fill(LightLepton.at(3).v.Pt(),evt_weight);
	      h.ZZ_CR[35]->Fill(LightLepton.at(0).v.Eta(),evt_weight);
	      h.ZZ_CR[36]->Fill(LightLepton.at(1).v.Eta(),evt_weight);
	      h.ZZ_CR[37]->Fill(LightLepton.at(2).v.Eta(),evt_weight);
	      h.ZZ_CR[38]->Fill(LightLepton.at(3).v.Eta(),evt_weight);
	      h.ZZ_CR[39]->Fill(LightLepton.at(0).v.Phi(),evt_weight);
	      h.ZZ_CR[40]->Fill(LightLepton.at(1).v.Phi(),evt_weight);
	      h.ZZ_CR[41]->Fill(LightLepton.at(2).v.Phi(),evt_weight);
	      h.ZZ_CR[42]->Fill(LightLepton.at(3).v.Phi(),evt_weight);
	      //------>Event Level Kinematics
	      h.ZZ_CR[43]->Fill(LT,evt_weight);
	      h.ZZ_CR[44]->Fill(*PuppiMET_pt,evt_weight);
	      h.ZZ_CR[45]->Fill(LT_PuppiMET,evt_weight);
	      //------>Angular Variables
	      h.ZZ_CR[46]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),evt_weight);
	      h.ZZ_CR[47]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),evt_weight);
	      h.ZZ_CR[48]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),evt_weight);
	      h.ZZ_CR[49]->Fill(delta_phi(LightLepton.at(3).v.Phi(),*PuppiMET_phi),evt_weight);
	      h.ZZ_CR[50]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),evt_weight);
	      h.ZZ_CR[51]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),evt_weight);
	      h.ZZ_CR[52]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(3).v.Phi()),evt_weight);
	      h.ZZ_CR[53]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),evt_weight);
	      h.ZZ_CR[54]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(3).v.Phi()),evt_weight);
	      h.ZZ_CR[55]->Fill(delta_phi(LightLepton.at(2).v.Phi(),LightLepton.at(3).v.Phi()),evt_weight);
	      //------>Transverse Mass
	      h.ZZ_CR[56]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),evt_weight);
	      h.ZZ_CR[57]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),evt_weight);
	      h.ZZ_CR[58]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),evt_weight);
	      h.ZZ_CR[59]->Fill(transv_mass(LightLepton.at(3).v.Pt(),LightLepton.at(3).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),evt_weight);
	      //------>DeltaR Plots
	      h.ZZ_CR[60]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),evt_weight);
	      h.ZZ_CR[61]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),evt_weight);
	      h.ZZ_CR[62]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(3).v),evt_weight);
	      h.ZZ_CR[63]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),evt_weight);
	      h.ZZ_CR[64]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(3).v),evt_weight);
	      h.ZZ_CR[65]->Fill(LightLepton.at(2).v.DeltaR(LightLepton.at(3).v),evt_weight);
	      //Invariant Mass
	      h.ZZ_CR[66]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),evt_weight);
	      h.ZZ_CR[67]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),evt_weight);
	      h.ZZ_CR[68]->Fill((LightLepton.at(0).v+LightLepton.at(3).v).M(),evt_weight);
	      h.ZZ_CR[69]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),evt_weight);
	      h.ZZ_CR[70]->Fill((LightLepton.at(1).v+LightLepton.at(3).v).M(),evt_weight);
	      h.ZZ_CR[71]->Fill((LightLepton.at(2).v+LightLepton.at(3).v).M(),evt_weight);
	      h.ZZ_CR[72]->Fill(HT,evt_weight);
	      h.ZZ_CR[73]->Fill(ST,evt_weight);
	      h.ZZ_CR[75]->Fill((int)bJets.size(),evt_weight);
	      h.ZZ_CR[76]->Fill((int)Jets.size(),evt_weight);
	      h.ZZ_CR[77]->Fill(MassArray_4L.at(0),evt_weight);
	      h.ZZ_CR[78]->Fill(MassArray_4L.at(1),evt_weight);
	      h.ZZ_CR[79]->Fill(MassArray_pT.at(0),evt_weight);
	      h.ZZ_CR[80]->Fill(MassArray_pT.at(1),evt_weight);
	    }
	  }
	}
      }
    }
  }
}
