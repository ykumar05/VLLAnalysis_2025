void AnaScript::CR_DY(){
  //Defining booleans
  bool mu2 = false;
  bool e2  = false;

  //Defining the 2Muon/2Electron events(OS)
  if(is_l2OS_event){
    if(LightLepton.at(0).id*LightLepton.at(1).id == -169)
      mu2 = true;
    if(LightLepton.at(0).id*LightLepton.at(1).id == -121)
      e2 = true;
  }
  
  //Calculating Event Weight(Invoking scale factors)
  float evt_weight = 1.0;
  float TriggerWeight = 1.0;
  float ZpTReWeightFactor = 1.0;
  float JetReWeightFactor = 1.0;
  float leptonSF = 1.0;
  float BTaggingSF = 1.0;

  if(_data == 0 && !_run3){
    if(mu2 || e2){

      //20UL18
      if(_year == 2018){
	leptonSF = LeptonID_SFUL18(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL18(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta());
	TriggerWeight = (1-(1-TriggEff2018Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2018Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));
	evt_weight = evt_weight*leptonSF*TriggerWeight;
      }

      //20UL17
      if(_year == 2017){
	leptonSF = LeptonID_SFUL17(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL17(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta());
	TriggerWeight = (1-(1-TriggEff2017Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2017Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));
	evt_weight = evt_weight*leptonSF*TriggerWeight;
      }

      //20UL16preVFP
      if(_year == 2016){
	leptonSF = LeptonID_SFUL16preVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16preVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta());
	TriggerWeight = (1-(1-TriggEff2016preVFPData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016preVFPData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));
	evt_weight = evt_weight*leptonSF*TriggerWeight;
      }

      //20UL16postVFP
      if(_year == 3016){
	leptonSF = LeptonID_SFUL16postVFP(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFUL16postVFP(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta());
	TriggerWeight = (1-(1-TriggEff2016postVFPData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2016postVFPData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));
	evt_weight = evt_weight*leptonSF*TriggerWeight;
      }
      
      //ZpT ReWeighting
      /*if(mu2)
	ZpTReWeightFactor = ZpTFactor_DY_Muons(_sample, LightLepton.at(0).v, LightLepton.at(1).v);
	if(e2)
	ZpTReWeightFactor = ZpTFactor_DY_Electrons(_sample, LightLepton.at(0).v, LightLepton.at(1).v);*/
      
      //NJet ReWeighting
      /*if(mu2)
	JetReWeightFactor = JetReWeighting_DY_Muons(_sample, Jets);
	if(e2)
	JetReWeightFactor = JetReWeighting_DY_Electrons(_sample, Jets);
      	evt_weight = evt_weight*ZpTReWeightFactor*JetReWeightFactor;*/
    }
  }
 
  if(_data == 0 && _run3){
    if(mu2 || e2){

      //Run3Summer23
      if(_year == 2023){
	leptonSF = LeptonID_SFRun3Summer23(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer23(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta());
	TriggerWeight = (1-(1-TriggEff2023Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2023Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));
	evt_weight = evt_weight*leptonSF*TriggerWeight;
      }

      //Run3Summer22
      if(_year == 2022){
	leptonSF = LeptonID_SFRun3Summer22(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta());
	TriggerWeight = (1-(1-TriggEff2022Data(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022Data(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));
	evt_weight = evt_weight*leptonSF*TriggerWeight;
      }

      //Run3Summer22EE
      if(_year == 3022){
	leptonSF = LeptonID_SFRun3Summer22EE(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta())*LeptonID_SFRun3Summer22EE(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta());
	TriggerWeight = (1-(1-TriggEff2022EEData(LightLepton.at(0).id, LightLepton.at(0).v.Pt(), LightLepton.at(0).v.Eta()))*(1-TriggEff2022EEData(LightLepton.at(1).id, LightLepton.at(1).v.Pt(), LightLepton.at(1).v.Eta())));
	evt_weight = evt_weight*leptonSF*TriggerWeight;
      }
    }
  }
 
  //2 Muons final state
  if(mu2){
    float pair01mass = OSSFMass(0,1);
    if(76<pair01mass && pair01mass<106){
      h.DY_CR[0]->Fill((int)LightLepton.size(),evt_weight);
      h.DY_CR[1]->Fill(LightLepton.at(0).v.Pt(),evt_weight);
      h.DY_CR[2]->Fill(LightLepton.at(0).v.Eta(),evt_weight);
      h.DY_CR[3]->Fill(LightLepton.at(0).v.Phi(),evt_weight);
      h.DY_CR[4]->Fill(LightLepton.at(1).v.Pt(),evt_weight);
      h.DY_CR[5]->Fill(LightLepton.at(1).v.Eta(),evt_weight);
      h.DY_CR[6]->Fill(LightLepton.at(1).v.Phi(),evt_weight);
      //------>Event Level Kinematics
      h.DY_CR[7]->Fill(LT,evt_weight);
      h.DY_CR[8]->Fill(*PuppiMET_pt,evt_weight);
      h.DY_CR[9]->Fill(LT_PuppiMET,evt_weight);
      h.DY_CR[10]->Fill((int)Jets.size(),evt_weight);
      h.DY_CR[11]->Fill((int)bJets.size(),evt_weight);
      h.DY_CR[12]->Fill(HT,evt_weight);
      h.DY_CR[13]->Fill(ST,evt_weight);
      //------>Angular Variables
      h.DY_CR[14]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),evt_weight);
      h.DY_CR[15]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),evt_weight);
      h.DY_CR[16]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),evt_weight);
      h.DY_CR[17]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),evt_weight);
      //Invariant Mass
      h.DY_CR[18]->Fill(pair01mass,evt_weight);
      h.DY_CR[19]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).Pt(),evt_weight);
      h.DY_CR[40]->Fill(evt_weight);
    }
  }

  //2 Electrons final state
  if(e2){
    float pair01mass = OSSFMass(0,1);
    if(76<pair01mass && pair01mass<106){
      h.DY_CR[20]->Fill((int)LightLepton.size(),evt_weight);
      h.DY_CR[21]->Fill(LightLepton.at(0).v.Pt(),evt_weight);
      h.DY_CR[22]->Fill(LightLepton.at(0).v.Eta(),evt_weight);
      h.DY_CR[23]->Fill(LightLepton.at(0).v.Phi(),evt_weight);
      h.DY_CR[24]->Fill(LightLepton.at(1).v.Pt(),evt_weight);
      h.DY_CR[25]->Fill(LightLepton.at(1).v.Eta(),evt_weight);
      h.DY_CR[26]->Fill(LightLepton.at(1).v.Phi(),evt_weight);
      //------>Event Level Kinematics
      h.DY_CR[27]->Fill(LT,evt_weight);
      h.DY_CR[28]->Fill(*PuppiMET_pt,evt_weight);
      h.DY_CR[29]->Fill(LT_PuppiMET,evt_weight);
      h.DY_CR[30]->Fill((int)Jets.size(),evt_weight);
      h.DY_CR[31]->Fill((int)bJets.size(),evt_weight);
      h.DY_CR[32]->Fill(HT,evt_weight);
      h.DY_CR[33]->Fill(ST,evt_weight);
      //------Angular Variables
      h.DY_CR[34]->Fill(delta_phi(LightLepton.at(0).v.Phi(),*PuppiMET_phi),evt_weight);
      h.DY_CR[35]->Fill(delta_phi(LightLepton.at(1).v.Phi(),*PuppiMET_phi),evt_weight);
      h.DY_CR[36]->Fill(delta_phi(LightLepton.at(0).v.Phi(),LightLepton.at(1).v.Phi()),evt_weight);
      h.DY_CR[37]->Fill(LightLepton.at(0).v.DeltaR(LightLepton.at(1).v),evt_weight);
      //Invariant Mass
      h.DY_CR[38]->Fill(pair01mass,evt_weight);
      h.DY_CR[39]->Fill((LightLepton.at(0).v+LightLepton.at(1).v).Pt(),evt_weight);
      h.DY_CR[41]->Fill(evt_weight);
    }
  }
}















































