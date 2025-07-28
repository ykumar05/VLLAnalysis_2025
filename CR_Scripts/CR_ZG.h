void AnaScript::CR_ZG(){
  MassArray_3L.clear();
 
  //Defining
  bool is3mu     = false;
  bool is3ele    = false;
  bool is1ele2mu = false;
  bool is1mu2ele = false;

  //Boolean for chosen pairs
  bool Hell1           = false;
  bool Hell2           = false;
  bool Hell3           = false;
  bool Hell4           = false;
  bool isL0Matched     = true;
  bool isL1Matched     = true;
  bool isL2Matched     = true;
  bool isSMTriggered   = false;
  bool isSETriggered   = false;
  bool isMuonTriggered = false;
  
  if(is_l3_event){//Light lepton passes trigger threshold and exactly 3L event
    h.ZG_CR[33]->Fill(0);
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
	if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2016 || _year == 3016)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 26)
	    isSMTriggered = true;
      	if(_year == 2017)
	  if(abs(LightLepton.at(i).id) == 13 && LightLepton.at(i).v.Pt() > 29)
	    isSMTriggered = true;
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
	  if(_year == 2018 || _year == 2022 || _year == 2023 || _year == 3023 || _year == 3022 || _year == 2017)
	    if(abs(LightLepton.at(j).id) == 11 && LightLepton.at(j).v.Pt() > 35)
	      isSETriggered = true;
	  if(_year == 2016 || _year == 3016)
	    if(abs(LightLepton.at(j).id) == 11 && LightLepton.at(j).v.Pt() > 30)
	      isSETriggered = true;
	}
      }
      isL0Matched = IsGenLightLeptonMatched(LightLepton.at(0).v) || IsGenPhotonMatched(LightLepton.at(0).v);
      isL1Matched = IsGenLightLeptonMatched(LightLepton.at(1).v) || IsGenPhotonMatched(LightLepton.at(1).v);
      isL2Matched = IsGenLightLeptonMatched(LightLepton.at(2).v) || IsGenPhotonMatched(LightLepton.at(2).v);
    }
  }
  
  if(_data == 1){
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
  }

  //bool ZG = false;
  bool ZG = true;

  //Introducing Event Weights
  float Evt_Weight = 1.0;
  float TriggerWeight = 0.0; 
  if(_data == 0 && !_run3){
    if(is3mu || is3ele || is1ele2mu || is1mu2ele){
      //2018
      if(_year == 2018){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2018Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL18(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.06;
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*1.114;
	if(_sample == 94)
	  Evt_Weight = Evt_Weight*0.975;
      }

      //2017
      if(_year == 2017){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_IsoMu27(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_IsoMu27(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
      	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2017Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFUL17(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
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
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023BPixData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023BPixData_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFRun3Summer23BPix(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23BPix(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.96;
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*0.97;
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 ||_sample == 948 || _sample == 949)
	  Evt_Weight = Evt_Weight*0.8395;
      }

      //Run3Summer23
      if(_year == 2023){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2023Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFRun3Summer23(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*0.974;
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*0.96;
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 ||_sample == 948 || _sample == 949)
	  Evt_Weight = Evt_Weight*0.88;
      }

      //Run3Summer22
      if(_year == 2022){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022Data_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFRun3Summer22(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.004;
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*1.006;
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 ||_sample == 948)
	  Evt_Weight = Evt_Weight*0.845;
      }

      //Run3Summer22EE
      if(_year == 3022){
	if(isSMTriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_IsoMu24(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_IsoMu24(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	if(isSETriggered)
	  TriggerWeight = 1-(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta()))*(1-TriggEff2022EEData_Ele32_WPTight_Gsf(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta()));
	Evt_Weight = LeptonID_SFRun3Summer22EE(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(2).id, LightLepton.at(2).v.Pt(), LightLepton.at(2).v.Eta())*TriggerWeight;
	//Applying the ZZ Normalization Factor
	if(_sample == 20 || _sample == 21 || _sample == 22 || _sample == 23|| _sample == 24 || _sample == 25 || _sample == 26)
	  Evt_Weight = Evt_Weight*1.01;
	if(_sample == 30 ||_sample == 31 ||_sample == 32)
	  Evt_Weight = Evt_Weight*0.94;
	if(_sample == 940 || _sample == 941 || _sample == 942 || _sample == 943 || _sample == 944 || _sample == 945 || _sample == 946 || _sample == 947 || _sample == 948)
	  Evt_Weight = Evt_Weight*0.808;
      }
    }
  }
  
  // Region definitions for each lepton combination
  Hell1 = is3mu && isSMTriggered;
  Hell2 = is3ele && isSETriggered;
  Hell3 = is1ele2mu && (isSMTriggered || isSETriggered);
  Hell4 = is1mu2ele && (isSMTriggered || isSETriggered);
      
  //Defining the Region

  if(Hell1 || Hell2 || Hell3 || Hell4){
    bool M_2L1 = false;
    bool M_2L2 = false;
    bool M_2L3 = false;
    bool M_2L4 = false;
    bool M_2L5 = false;
    h.ZG_CR[33]->Fill(1);
    float invmass = (LightLepton.at(0).v+LightLepton.at(1).v+LightLepton.at(2).v).M();
    if(76.0 < invmass && invmass < 106.0){
      if(LightLepton.at(0).id * LightLepton.at(1).id == -169 || LightLepton.at(0).id * LightLepton.at(1).id == -121)
	M_2L1 = (LightLepton.at(0).v+LightLepton.at(1).v).M() < 76;
      if(LightLepton.at(0).id * LightLepton.at(2).id == -169 || LightLepton.at(0).id * LightLepton.at(2).id == -121)
	M_2L2 = (LightLepton.at(0).v+LightLepton.at(2).v).M() < 76;
      if(LightLepton.at(1).id * LightLepton.at(2).id == -169 || LightLepton.at(1).id * LightLepton.at(2).id == -121)
	M_2L3 = (LightLepton.at(1).v+LightLepton.at(2).v).M() < 76;
      if(M_2L1 + M_2L2 + M_2L3 == 1)
	M_2L4 = M_2L1 || M_2L2 || M_2L3;
      if(M_2L1 + M_2L2 +M_2L3 == 2)
	M_2L5 = (M_2L1 && M_2L2) || (M_2L1 && M_2L3) || (M_2L3 && M_2L2);
      h.ZG_CR[33]->Fill(2);
      if(M_2L4 || M_2L5){
	h.ZG_CR[33]->Fill(3);
	if(isL0Matched && isL1Matched && isL2Matched){
	  if(LightLepton.at(2).v.Pt()>15){
	    h.ZG_CR[33]->Fill(4);
	    veto_ZG = false;
	    if(ZG){
	      h.ZG_CR[0]->Fill((int)LightLepton.size(),Evt_Weight);
	      h.ZG_CR[1]->Fill(LightLepton.at(0).v.Pt(),Evt_Weight);
	      h.ZG_CR[2]->Fill(LightLepton.at(1).v.Pt(),Evt_Weight);
	      h.ZG_CR[3]->Fill(LightLepton.at(2).v.Pt(),Evt_Weight);
	      h.ZG_CR[4]->Fill(LightLepton.at(0).v.Eta(),Evt_Weight);
	      h.ZG_CR[5]->Fill(LightLepton.at(1).v.Eta(),Evt_Weight);
	      h.ZG_CR[6]->Fill(LightLepton.at(2).v.Eta(),Evt_Weight);
	      h.ZG_CR[7]->Fill(LightLepton.at(0).v.Phi(),Evt_Weight);
	      h.ZG_CR[8]->Fill(LightLepton.at(1).v.Phi(),Evt_Weight);
	      h.ZG_CR[9]->Fill(LightLepton.at(2).v.Phi(),Evt_Weight);
	      //------>Event Level Kinematics
	      h.ZG_CR[10]->Fill(LT,Evt_Weight);
	      h.ZG_CR[11]->Fill(*PuppiMET_pt,Evt_Weight);
	      h.ZG_CR[12]->Fill(LT_PuppiMET,Evt_Weight);
	      //------>Angular Variables
	      h.ZG_CR[13]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),Evt_Weight);
	      h.ZG_CR[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.ZG_CR[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),LightLepton.at(2).v.Phi()),Evt_Weight);
	      h.ZG_CR[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      h.ZG_CR[17]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      h.ZG_CR[18]->Fill(delta_phi(LightLepton.at(2).v.Phi(),*PuppiMET_phi),Evt_Weight);
	      //------>Transverse Mass
	      h.ZG_CR[19]->Fill(transv_mass(LightLepton.at(0).v.Pt(),LightLepton.at(0).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      h.ZG_CR[20]->Fill(transv_mass(LightLepton.at(1).v.Pt(),LightLepton.at(1).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      h.ZG_CR[21]->Fill(transv_mass(LightLepton.at(2).v.Pt(),LightLepton.at(2).v.Phi(),*PuppiMET_pt,*PuppiMET_phi),Evt_Weight);
	      //------>DeltaR Plots
	      h.ZG_CR[22]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),Evt_Weight);
	      h.ZG_CR[23]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      h.ZG_CR[24]->Fill(LightLepton.at(1).v.DeltaR(LightLepton.at(2).v),Evt_Weight);
	      //Invariant Mass
	      h.ZG_CR[25]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).M(),Evt_Weight);
	      h.ZG_CR[26]->Fill((LightLepton.at(0).v+LightLepton.at(2).v).M(),Evt_Weight);
	      h.ZG_CR[27]->Fill((LightLepton.at(1).v+LightLepton.at(2).v).M(),Evt_Weight);
	      h.ZG_CR[28]->Fill(HT,Evt_Weight);
	      h.ZG_CR[29]->Fill(ST,Evt_Weight);
	      h.ZG_CR[30]->Fill((int)bJets.size(),Evt_Weight);
	      h.ZG_CR[31]->Fill((int)Jets.size(),Evt_Weight);
	      h.ZG_CR[32]->Fill(invmass,Evt_Weight);
	    }
	  }
	}
      }
    }
  }
}

