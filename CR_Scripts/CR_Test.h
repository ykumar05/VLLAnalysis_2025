void AnaScript::CR_Test(){
  //Clearing the Mass Arrays
  MassArray_3L.clear();
  TransverseMassArray_3L.clear();
  
  //Initializing different masses for 3L Final state
  float mass_01 = 0.0;
  float mass_02 = 0.0;
  float mass_12 = 0.0;

  //Defining
  bool is3mu     = false;
  bool is3ele    = false;
  bool is1ele2mu = false;
  bool is1mu2ele = false;

  //Boolean for chosen pairs
  bool chosen1 = false;
  bool chosen2 = false;
  bool chosen3 = false;
  bool isSMTriggered = false;
  bool isSETriggered = false;
  bool isMuonTriggered = false;
  
  if(is_l3_event){//Light lepton passes trigger threshold and exactly 3L event
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 2197)
      is3mu = true;
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 1331)
      is3ele = true;
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 1859)
      is1ele2mu = true;
    if(abs((LightLepton.at(0).id)*(LightLepton.at(1).id)*(LightLepton.at(2).id)) == 1573)
      is1mu2ele = true;
  }
  
  if(_data == 0){
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){
      //SingleMuon Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2018 || _year == 2016 || _year == 3016)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	    isSMTriggered = true;
      	if(_year == 2017)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	    isSMTriggered = true;
      }
      //SingleElectron Triggered!
      for(int i = 0; i < (int)LightLepton.size(); i++){
	if(_year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2018 || _year == 2016 || _year == 3016)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	    isMuonTriggered = true;
	if(_year == 2017)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	    isMuonTriggered = true;
      }
      if(!isMuonTriggered){
	for(int j = 0; j < (int)LightLepton.size(); j++){
	  if(_year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2018 || _year == 2017)
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
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){
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
  
  //bool Test = false;
  bool Test = true;

  //Introducing Event Weights
  float Evt_Weight = 1.0;
  float TriggerWeight = 0.0; 
  if(_data == 0 && !_run3){
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){

      //20UL18
      if(_year == 2018){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
   	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//Final Event Weight
	Evt_Weight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2018(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.06;
	//Applying the WZ Normalization Factor
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*1.114;
	//Applying the ZG Normalization Factor
	if(_sample == 94)
	  Evt_Weight = Evt_Weight*0.975;
      }

      //20UL17
      if(_year == 2017){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_IsoMu27(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 ||_sample == 21 ||_sample == 22 ||_sample == 23 ||_sample == 24 ||_sample == 25 ||_sample == 26)
	  Evt_Weight = Evt_Weight*1.045;
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*1.124;
	if(_sample == 94)
	  Evt_Weight = Evt_Weight*0.967;
      }
  
      //2016preVFP
      if(_year == 2016){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL16preVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.129;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*0.933;
	if(_sample == 94)
	  Evt_Weight = Evt_Weight*0.76;
      }
      
      //2016postVFP
      if(_year == 3016){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL16postVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.954;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*1.086;
	if(_sample == 94)
	  Evt_Weight = Evt_Weight*0.852;
      }
    }
  }
  
  if(_data == 0 && _run3){
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){

      //Run3Summer23BPix
      if(_year == 3023){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
   	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//Final Event Weight
	Evt_Weight = LeptonID_SFRun3Summer23BPix(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2023BPix(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.96;
	//Applying the WZ Normalization Factor
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*0.97;
	//Applying the ZG Normalization Factor
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948 || _sample == 949)
	  Evt_Weight = Evt_Weight*0.8395;
      }

      //Run3Summer23
      if(_year == 2023){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
   	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//Final Event Weight
	Evt_Weight = LeptonID_SFRun3Summer23(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2023(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.974;
	//Applying the WZ Normalization Factor
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*0.96;
	//Applying the ZG Normalization Factor
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948 || _sample == 949)
	  Evt_Weight = Evt_Weight*0.88;
      }

      //Run3Summer22
      if(_year == 2022){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
   	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//Final Event Weight
	Evt_Weight = LeptonID_SFRun3Summer22(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2022(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.004;
	//Applying the WZ Normalization Factor
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*1.006;
	//Applying the ZG Normalization Factor
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948)
	  Evt_Weight = Evt_Weight*0.845;
      }

      //Run3Summer22EE
      if(_year == 3022){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
   	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//Final Event Weight
	Evt_Weight = LeptonID_SFRun3Summer22EE(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2022EE(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.01;
	//Applying the WZ Normalization Factor
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*0.94;
	//Applying the ZG Normalization Factor
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948)
	  Evt_Weight = Evt_Weight*0.808;
      }
    }
  }

  /***************************************************************************************
   *         Define Scale factors for all 4 kinds of Final state possible here           *
   ***************************************************************************************/ 
  
  /********************************************
   *                  3 Muons                 *
   ********************************************/
  if(is3mu && isSMTriggered){
    if(LightLepton.at(0).id*LightLepton.at(1).id == -169){
      mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      chosen1 = true;
    }
    if(LightLepton.at(0).id*LightLepton.at(2).id == -169){
      mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      chosen2 = true;
    }
    if(LightLepton.at(1).id*LightLepton.at(2).id == -169){
      mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      chosen3 = true;
    }

    if(chosen1 && chosen2){
      if(fabs(mass_01-91.2)<fabs(mass_02-91.2)){
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen2 && chosen3){
      if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen1 && chosen3){
      if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
  }

  /********************************************
   *                3 Electrons               *
   ********************************************/
  if(is3ele && isSETriggered){
    if(LightLepton.at(0).id*LightLepton.at(1).id == -121){
      mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
      chosen1 = true;
    }
    if(LightLepton.at(0).id*LightLepton.at(2).id == -121){
      mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
      chosen2 = true;
    }
    if(LightLepton.at(1).id*LightLepton.at(2).id == -121){
      mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
      chosen3 = true;
    }

    if(chosen1 && chosen2){
      if(fabs(mass_01-91.2)<fabs(mass_02-91.2)){
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen2 && chosen3){
      if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen1 && chosen3){
      if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
  }

  /********************************************
   *          1 Electron & 2 Muons            *
   ********************************************/
  if(is1ele2mu){
    if(isSMTriggered || isSETriggered){
      if(LightLepton.at(0).id*LightLepton.at(1).id == -169){
	mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
	chosen1 = true;
      }
      if(LightLepton.at(0).id*LightLepton.at(2).id == -169){
	mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
	chosen2 = true;
      }
      if(LightLepton.at(1).id*LightLepton.at(2).id == -169){
	mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
	chosen3 = true;
      }
      if(chosen1){
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen2){
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen3){
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
  }

  /********************************************
   *          1 Muon & 2 Electrons            *
   ********************************************/
  if(is1mu2ele){
    if(isSMTriggered || isSETriggered){
      if(LightLepton.at(0).id*LightLepton.at(1).id == -121){
	mass_01 = (LightLepton.at(0).v+LightLepton.at(1).v).M();
	chosen1 = true;
      }
      if(LightLepton.at(0).id*LightLepton.at(2).id == -121){
	mass_02 = (LightLepton.at(0).v+LightLepton.at(2).v).M();
	chosen2 = true;
      }
      if(LightLepton.at(1).id*LightLepton.at(2).id == -121){
	mass_12 = (LightLepton.at(1).v+LightLepton.at(2).v).M();
	chosen3 = true;
      }
      if(chosen1){
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen2){
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen3){
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
  }
      
  //Extending the definition of the Test CR
  if((int)MassArray_3L.size()>0 && (int)TransverseMassArray_3L.size()>0){
    if(76<MassArray_3L.at(0) && MassArray_3L.at(0)<106){//OnZ Mass
      if(TransverseMassArray_3L.at(0) < 150){
	if(*PuppiMET_pt < 150){
	  if((int)bJets.size() == 0){
	    veto_Test = false;
	    if(Test){
	      h.Test_CR[0]->Fill(1,Evt_Weight);
	      h.Test_CR[1]->Fill((int)LightLepton.size(),Evt_Weight);
	      h.Test_CR[2]->Fill(LightLepton.at(0).v.Pt(),Evt_Weight);
	      h.Test_CR[3]->Fill(LightLepton.at(1).v.Pt(),Evt_Weight);
	      h.Test_CR[4]->Fill(LightLepton.at(2).v.Pt(),Evt_Weight);
	      h.Test_CR[5]->Fill(LightLepton.at(0).v.Eta(),Evt_Weight);
	      h.Test_CR[6]->Fill(LightLepton.at(1).v.Eta(),Evt_Weight);
	      h.Test_CR[7]->Fill(LightLepton.at(2).v.Eta(),Evt_Weight);
	      h.Test_CR[8]->Fill(LightLepton.at(0).v.Phi(),Evt_Weight);
	      h.Test_CR[9]->Fill(LightLepton.at(1).v.Phi(),Evt_Weight);
	      h.Test_CR[10]->Fill(LightLepton.at(2).v.Phi(),Evt_Weight);
	      //------>Event Level Kinematics
	      h.Test_CR[11]->Fill(LT,Evt_Weight);
	      h.Test_CR[12]->Fill(*PuppiMET_pt,Evt_Weight);
	      h.Test_CR[13]->Fill(LT_PuppiMET,Evt_Weight);
	      //------>Angular Variables
	      h.Test_CR[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),Evt_Weight);
	      h.Test_CR[15]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.Test_CR[16]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.Test_CR[17]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      h.Test_CR[18]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      h.Test_CR[19]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      //------>Transverse Mass
	      h.Test_CR[20]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      h.Test_CR[21]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      h.Test_CR[22]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      //------>DeltaR Plots
	      h.Test_CR[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),Evt_Weight);
	      h.Test_CR[24]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      h.Test_CR[25]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      //Invariant Mass
	      h.Test_CR[26]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),Evt_Weight);
	      h.Test_CR[27]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),Evt_Weight);
	      h.Test_CR[28]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),Evt_Weight);
	      h.Test_CR[29]->Fill(HT,Evt_Weight);
	      h.Test_CR[30]->Fill(ST,Evt_Weight);
	      h.Test_CR[31]->Fill((int)bJets.size(),Evt_Weight);
	      h.Test_CR[32]->Fill((int)Jets.size(),Evt_Weight);
	    }
	  }
	}
      }
    }
  }
}


 
