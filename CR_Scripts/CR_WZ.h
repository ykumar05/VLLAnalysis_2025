void AnaScript::CR_WZ(){
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
    h.WZ_CR[76]->Fill(0);
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
  
  //bool MisID = false;
  bool MisID = true;
  
  //bool WZ = false;
  bool WZ = true;

  /***************************************************************************************
   *         Define Scale factors for all 4 kinds of Final state possible here           *
   ***************************************************************************************/ 
  //Introducing Event Weights
  float Evt_Weight = 1.0;
  float TriggerWeight = 0.0; 
  if(_data == 0 && !_run3){
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){
      if(_year == 2018){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
      	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2018(_sample, Jets);
	h.WZ_CR[77]->Fill(Evt_Weight);

	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.06;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*1.114;
      }

      if(_year == 2017){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_IsoMu27(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
      	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2017(_sample, Jets);
	h.WZ_CR[78]->Fill(Evt_Weight);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 ||_sample == 21 ||_sample == 22 ||_sample == 23 ||_sample == 24 ||_sample == 25 ||_sample == 26)
	  Evt_Weight = Evt_Weight*1.045;
	//Applying the WZ Normalization Factor
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*1.124;
      }

      //2016preVFP
      if(_year == 2016){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
      	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016preVFPData_Ele27_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL16preVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2016preVFP(_sample, Jets);
	h.WZ_CR[79]->Fill(Evt_Weight);

	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.129;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*0.933;
      }
      
      //2016postVFP
      if(_year == 3016){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
      	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2016postVFPData_Ele27_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL16postVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSF2016postVFP(_sample, Jets);
	h.WZ_CR[80]->Fill(Evt_Weight);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.954;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*1.086;
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
	Evt_Weight = LeptonID_SFRun3Summer23BPix(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2023BPix(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.96;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*0.97;
      }
      
      //Run3Summer23
      if(_year == 2023){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFRun3Summer23(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2023(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.974;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*0.96;
      }

      //Run3Summer22
      if(_year == 2022){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFRun3Summer22(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2022(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.004;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*1.006;
      }

      //Run3Summer22EE
      if(_year == 3022){
	//SingleMuonTriggerWeight
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	//SingleElectronTriggerWeight
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFRun3Summer22EE(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight*bTagSFRun3Summer2022EE(_sample, Jets);
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23 || _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.01;
	//Applying the WZ Normalization Factor
	if(_sample == 30 || _sample == 31 || _sample == 32)
	  Evt_Weight = Evt_Weight*0.94;
      }
    }
  }
  h.WZ_CR[69]->Fill(Evt_Weight);

  /********************************************
   *                  3 Muons                 *
   ********************************************/
  if(is3mu && isSMTriggered){
    h.WZ_CR[72]->Fill(1,Evt_Weight);
    //Forming pairs of OSSF Muons: Each event will have two pair of OSSF muons and only one correspond to Z and the the leftover muon certainly originates from a W.
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
	h.WZ_CR[0]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[1]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	h.WZ_CR[2]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[3]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen2 && chosen3){
      if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	h.WZ_CR[4]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[5]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	h.WZ_CR[6]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[7]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen1 && chosen3){
      if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	h.WZ_CR[8]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[9]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	h.WZ_CR[10]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[11]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
  }

  /********************************************
   *                3 Electrons               *
   ********************************************/
  if(is3ele && isSETriggered){
    h.WZ_CR[72]->Fill(2,Evt_Weight);
    //Forming pairs of OSSF Muons: Each event will have two pair of OSSF electons and only one correspond to Z and the the leftover electron certainly originates from a W.
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
	h.WZ_CR[12]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[13]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	h.WZ_CR[14]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[15]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen2 && chosen3){
      if(fabs(mass_02-91.2)<fabs(mass_12-91.2)){
	h.WZ_CR[16]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[17]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	h.WZ_CR[18]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
    if(chosen1 && chosen3){
      if(fabs(mass_01-91.2)<fabs(mass_12-91.2)){
	h.WZ_CR[20]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      else{
	h.WZ_CR[22]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[23]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
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
      h.WZ_CR[72]->Fill(3,Evt_Weight);
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
	h.WZ_CR[24]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[25]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen2){
	h.WZ_CR[26]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[27]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen3){
	h.WZ_CR[28]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[29]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
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
      h.WZ_CR[72]->Fill(3,Evt_Weight);
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
	h.WZ_CR[30]->Fill(mass_01,Evt_Weight);
	h.WZ_CR[31]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_01);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen2){
	h.WZ_CR[32]->Fill(mass_02,Evt_Weight);
	h.WZ_CR[33]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_02);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
      if(chosen3){
	h.WZ_CR[34]->Fill(mass_12,Evt_Weight);
	h.WZ_CR[35]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	MassArray_3L.push_back(mass_12);
	TransverseMassArray_3L.push_back(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi));
      }
    }
  }
      
  //Extending the definition of the CR
  if((int)MassArray_3L.size()>0 && (int)TransverseMassArray_3L.size()>0){
    h.WZ_CR[36]->Fill((int)MassArray_3L.size(),Evt_Weight);
    h.WZ_CR[37]->Fill((int)TransverseMassArray_3L.size(),Evt_Weight);
    h.WZ_CR[72]->Fill(MassArray_3L[0],Evt_Weight);
    h.WZ_CR[73]->Fill(TransverseMassArray_3L[0],Evt_Weight);
    h.WZ_CR[74]->Fill(*PuppiMET_pt,Evt_Weight);
    h.WZ_CR[75]->Fill(LightLepton.at(2).v.Pt(),Evt_Weight);
    if(76<MassArray_3L.at(0) && MassArray_3L.at(0)<106){//OnZ Mass
      if(50<TransverseMassArray_3L.at(0) && TransverseMassArray_3L.at(0)<150){//Transverse Mass
	if(*PuppiMET_pt>50 && *PuppiMET_pt<150){
	  if(LightLepton.at(2).v.Pt()>20){//Softest Lepton Pt
	    if((int)bJets.size() == 0){
	      veto_WZ = false;
	      if(WZ){
		h.WZ_CR[38]->Fill(Evt_Weight);
		h.WZ_CR[39]->Fill((int)LightLepton.size(),Evt_Weight);
		h.WZ_CR[40]->Fill(LightLepton.at(0).v.Pt(),Evt_Weight);
		h.WZ_CR[41]->Fill(LightLepton.at(1).v.Pt(),Evt_Weight);
		h.WZ_CR[42]->Fill(LightLepton.at(2).v.Pt(),Evt_Weight);
		h.WZ_CR[43]->Fill(LightLepton.at(0).v.Eta(),Evt_Weight);
		h.WZ_CR[44]->Fill(LightLepton.at(1).v.Eta(),Evt_Weight);
		h.WZ_CR[45]->Fill(LightLepton.at(2).v.Eta(),Evt_Weight);
		h.WZ_CR[46]->Fill(LightLepton.at(0).v.Phi(),Evt_Weight);
		h.WZ_CR[47]->Fill(LightLepton.at(1).v.Phi(),Evt_Weight);
		h.WZ_CR[48]->Fill(LightLepton.at(2).v.Phi(),Evt_Weight);
		//------>Event Level Kinematics
		h.WZ_CR[49]->Fill(LT,Evt_Weight);
		h.WZ_CR[50]->Fill(*PuppiMET_pt,Evt_Weight);
		h.WZ_CR[51]->Fill(LT_PuppiMET,Evt_Weight);
		//------>Angular Variables
		h.WZ_CR[52]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),Evt_Weight);
		h.WZ_CR[53]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
		h.WZ_CR[54]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
		h.WZ_CR[55]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),Evt_Weight);
		h.WZ_CR[56]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),Evt_Weight);
		h.WZ_CR[57]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),Evt_Weight);
		//------>Transverse Mass
		h.WZ_CR[58]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
		h.WZ_CR[59]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
		h.WZ_CR[60]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
		//------>DeltaR Plots
		h.WZ_CR[61]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),Evt_Weight);
		h.WZ_CR[62]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
		h.WZ_CR[63]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
		//Invariant Mass
		h.WZ_CR[64]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),Evt_Weight);
		h.WZ_CR[65]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),Evt_Weight);
		h.WZ_CR[66]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),Evt_Weight);
		h.WZ_CR[67]->Fill(HT,Evt_Weight);
		h.WZ_CR[68]->Fill(ST,Evt_Weight);
		h.WZ_CR[70]->Fill((int)bJets.size(),Evt_Weight);
		h.WZ_CR[71]->Fill((int)Jets.size(),Evt_Weight);
	      }
	    }
	  }
	}
      }
    }
  }

  //Contribution of other backgrounds towards MisID 
  /*******************************************
   *                 MisID CR                *
   *******************************************/
  if((int)MassArray_3L.size()>0 && (int)TransverseMassArray_3L.size()>0){
    if(76<MassArray_3L.at(0) && MassArray_3L.at(0)<106){//OnZ Mass
      if(TransverseMassArray_3L.at(0)<50){//Transverse Mass
	if(*PuppiMET_pt<100){
	  if((int)bJets.size()==0){
	    veto_MisID = false;
	    if(MisID){
	      h.MisID_CR[0]->Fill(LightLepton.at(0).v.Pt(),Evt_Weight);
	      h.MisID_CR[1]->Fill(LightLepton.at(1).v.Pt(),Evt_Weight);
	      h.MisID_CR[2]->Fill(LightLepton.at(2).v.Pt(),Evt_Weight);
	      h.MisID_CR[3]->Fill(LightLepton.at(0).v.Eta(),Evt_Weight);
	      h.MisID_CR[4]->Fill(LightLepton.at(1).v.Eta(),Evt_Weight);
	      h.MisID_CR[5]->Fill(LightLepton.at(2).v.Eta(),Evt_Weight);
	      h.MisID_CR[6]->Fill(LightLepton.at(0).v.Phi(),Evt_Weight);
	      h.MisID_CR[7]->Fill(LightLepton.at(1).v.Phi(),Evt_Weight);
	      h.MisID_CR[8]->Fill(LightLepton.at(2).v.Phi(),Evt_Weight);
	      //------>Event Level Kinematics
	      h.MisID_CR[9]->Fill((int)bJets.size(),Evt_Weight);
	      h.MisID_CR[10]->Fill((int)Jets.size(),Evt_Weight);
	      h.MisID_CR[11]->Fill(LT,Evt_Weight);
	      h.MisID_CR[12]->Fill(*PuppiMET_pt,Evt_Weight);
	      h.MisID_CR[13]->Fill(LT_PuppiMET,Evt_Weight);
	      h.MisID_CR[14]->Fill(HT,Evt_Weight);
	      h.MisID_CR[15]->Fill(ST,Evt_Weight);
	      //------>Transverse Mass
	      h.MisID_CR[16]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      h.MisID_CR[17]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      h.MisID_CR[18]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      h.MisID_CR[19]->Fill(MassArray_3L.at(0),Evt_Weight);
	      h.MisID_CR[20]->Fill(TransverseMassArray_3L.at(0),Evt_Weight);
	      //dPhi and dR's
	      h.MisID_CR[21]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),Evt_Weight);
	      h.MisID_CR[22]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.MisID_CR[23]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.MisID_CR[24]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      h.MisID_CR[25]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      h.MisID_CR[26]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      h.MisID_CR[27]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),Evt_Weight);
	      h.MisID_CR[28]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      h.MisID_CR[29]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      //Number Plots
	      h.MisID_CR[30]->Fill((int)LightLepton.size(),Evt_Weight);
	    }
	  }
	}
      }
    }
  }
}


 
