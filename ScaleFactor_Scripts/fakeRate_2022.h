/*double AnaScript::FakeRate_Run3Summer23(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  //Muons
  if(fabs(id)==13){
  //DYJetsToLL
  if(sample == "DYJetsToLL"){
  //Barrel Region
  if(fabs(eta)<=1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  //Endcap Region
  if(fabs(eta)>1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  }

  //TTBar
  if(sample == "TTBar"){
  //Barrel Region
  if(fabs(eta)<=1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  //Endcap Region
  if(fabs(eta)>1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  }
    
  //Data
  //EEM+MMM
  if(sample == "SingleMuon"){
  //Barrel Region
  if(fabs(eta)<=1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  //Endcap Region
  if(fabs(eta)>1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  }
  }
  
  //Electrons
  if(fabs(id)==11){
  //DYJetsToLL
  if(sample == "DYJetsToLL"){
  //Barrel Region
  if(fabs(eta)<=1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  //Endcap Region
  if(fabs(eta)>1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  }
    
  //TTBar
  if(sample == "TTBar"){
  //Barrel Region
  if(fabs(eta)<=1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  //Endcap Region
  if(fabs(eta)>1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  }
    
  //Data: EGamma
  //MME+EEE
  if(sample == "EGamma"){
  //Barrel Region
  if(fabs(eta)<=1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  //Endcap Region
  if(fabs(eta)>1.479){
  if(15 > pt)
  fake_rate = ;
  if(15 < pt && pt < 25)
  fake_rate = ;
  if(25 < pt && pt < 40)
  fake_rate = ;
  if(40 < pt)
  fake_rate = ;
  }
  }
  }
  return fake_rate;
  }

  double AnaScript::FakeRate_RT_Run3Summer23(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
  //DYJetsToLL
  if(sample == "DYJetsToLL"){
  if(15 > pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(15 < pt && pt < 25){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(25 < pt && pt < 40){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(40 < pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  }

  //SingleMuon
  if(sample == "SingleMuon"){
  if(15 > pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(15 < pt && pt < 25){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(25 < pt && pt < 40){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(40 < pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  }
  }

  //Electrons
  if(fabs(id)==11){
  //DYJetsToLL
  if(sample == "DYJetsToLL"){
  if(15 > pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(15 < pt && pt < 25){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(25 < pt && pt < 40){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(40 < pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  }
 
  //EGamma
  if(sample == "EGamma"){
  if(15 > pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(15 < pt && pt < 25){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(25 < pt && pt < 40){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  if(40 < pt){
  if(RT < 0.0)
  corr_factor = *2/(+);  
  if(0.0 < RT && RT < 1.0)
  corr_factor = *2/(+);  
  if(1.0 < RT && RT < 2.0)
  corr_factor = *2/(+);  
  if(2.0 < RT && RT < 3.0)
  corr_factor = *2/(+);  
  if(3.0 < RT && RT < 4.0)
  corr_factor = *2/(+);  
  if(4.0 < RT)
  corr_factor = *2/(+);  
  }
  }
  }
  return corr_factor;
  }

  double AnaScript::FakeRateMixed_Run3Summer23(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
  double FakeRate_DY   = FakeRate_Run3Summer23(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer23(id, v1, v2, "DYJetsToLL");
  double FakeRate_TT   = FakeRate_Run3Summer23(id, pt, fabs(eta), "TTBar");
  double FakeRate_Data = FakeRate_Run3Summer23(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_Run3Summer23(id, v1, v2, "SingleMuon");
  if(FakeRate_DY != 0){
  k_fake = FakeRate_Data/FakeRate_DY;
  fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
  }
  else
  fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
  double FakeRate_DY   = FakeRate_Run3Summer23(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer23(id, v1, v2, "DYJetsToLL");
  double FakeRate_TT   = FakeRate_Run3Summer23(id, pt, fabs(eta), "TTBar");
  double FakeRate_Data = FakeRate_Run3Summer23(id, pt, fabs(eta), "EGamma")*FakeRate_RT_Run3Summer23(id, v1, v2, "EGamma");
  if(FakeRate_DY != 0){
  k_fake = FakeRate_Data/FakeRate_DY;
  fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
  }
  else
  fake_rate = FakeRate_Data;
  }
  return fake_rate;
  }*/

double AnaScript::FakeRate_Run3Summer22EE(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.184371;
	if(15 < pt && pt < 25)
	  fake_rate = 0.159297;
	if(25 < pt && pt < 40)
	  fake_rate = 0.123179;
	if(40 < pt)
	  fake_rate = 0.100917;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.257476;
	if(15 < pt && pt < 25)
	  fake_rate = 0.225256;
	if(25 < pt && pt < 40)
	  fake_rate = 0.164671;
	if(40 < pt)
	  fake_rate = 0.09375;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.138516;
	if(15 < pt && pt < 25)
	  fake_rate = 0.101156;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0802766;
	if(40 < pt)
	  fake_rate = 0.0771739;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.205455;
	if(15 < pt && pt < 25)
	  fake_rate = 0.172633;
	if(25 < pt && pt < 40)
	  fake_rate = 0.157132;
	if(40 < pt)
	  fake_rate = 0.146341;
      }
    }

    //Data: SingleMuon
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.13976;
	if(15 < pt && pt < 25)
	  fake_rate = 0.113757;
	if(25 < pt && pt < 40)
	  fake_rate = 0.12784;
	if(40 < pt)
	  fake_rate = 0.245706;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.254294;
	if(15 < pt && pt < 25)
	  fake_rate = 0.237997;
	if(25 < pt && pt < 40)
	  fake_rate = 0.278312;
	if(40 < pt)
	  fake_rate = 0.399974;
      }
    }
  }
  
  //Electrons
  if(fabs(id)==11){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.167109;
	if(15 < pt && pt < 25)
	  fake_rate = 0.139214;
	if(25 < pt && pt < 40)
	  fake_rate = 0.13499;
	if(40 < pt)
	  fake_rate = 0.135021;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.209292;
	if(15 < pt && pt < 25)
	  fake_rate = 0.178219;
	if(25 < pt && pt < 40)
	  fake_rate = 0.205972;
	if(40 < pt)
	  fake_rate = 0.18593;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.18439;
	if(15 < pt && pt < 25)
	  fake_rate = 0.153065;
	if(25 < pt && pt < 40)
	  fake_rate = 0.130355;
	if(40 < pt)
	  fake_rate = 0.145349;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.215759;
	if(15 < pt && pt < 25)
	  fake_rate = 0.194959;
	if(25 < pt && pt < 40)
	  fake_rate = 0.190476;
	if(40 < pt)
	  fake_rate = 0.235849;
      }
    }

    //Data: EGamma
    if(sample == "EGamma"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.179412;
	if(15 < pt && pt < 25)
	  fake_rate = 0.122581;
	if(25 < pt && pt < 40)
	  fake_rate = 0.139431;
	if(40 < pt)
	  fake_rate = 0.135657;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.26982;
	if(15 < pt && pt < 25)
	  fake_rate = 0.201439;
	if(25 < pt && pt < 40)
	  fake_rate = 0.182538;
	if(40 < pt)
	  fake_rate = 0.186011;
      }
    }
  }
  return fake_rate;
}

double AnaScript::FakeRate_RT_Run3Summer22EE(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.302789*2/(0.184371+0.257476);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.324324*2/(0.184371+0.257476);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.294944*2/(0.184371+0.257476);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.252573*2/(0.184371+0.257476);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.204336*2/(0.184371+0.257476);  
	if(4.0 < RT)
	  corr_factor = 0.165923*2/(0.184371+0.257476);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.25*2/(0.159297+0.225256);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.328638*2/(0.159297+0.225256);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.266467*2/(0.159297+0.225256);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.18567*2/(0.159297+0.225256);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.160281*2/(0.159297+0.225256);  
	if(4.0 < RT)
	  corr_factor = 0.130756*2/(0.159297+0.225256);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.285714*2/(0.123179+0.164671);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.222222*2/(0.123179+0.164671);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.263158*2/(0.123179+0.164671);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.122807*2/(0.123179+0.164671);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0869565*2/(0.123179+0.164671);  
	if(4.0 < RT)
	  corr_factor = 0.0759494*2/(0.123179+0.164671);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.666667*2/(0.100917+0.09375);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.222222*2/(0.100917+0.09375);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.05*2/(0.100917+0.09375);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0285714*2/(0.100917+0.09375);  
	if(4.0 < RT)
	  corr_factor = 0.0434783*2/(0.100917+0.09375);  
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.248503*2/(0.13976+0.254294);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.252297*2/(0.13976+0.254294);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.234089*2/(0.13976+0.254294);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.192982*2/(0.13976+0.254294);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.173103*2/(0.13976+0.254294);  
	if(4.0 < RT)
	  corr_factor = 0.145401*2/(0.13976+0.254294);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.214405*2/(0.113757+0.237997);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.206717*2/(0.113757+0.237997);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.201583*2/(0.113757+0.237997);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.184626*2/(0.113757+0.237997);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.122645*2/(0.113757+0.237997);  
	if(4.0 < RT)
	  corr_factor = 0.136895*2/(0.113757+0.237997);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.32101*2/(0.12784+0.278312);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0486251*2/(0.12784+0.278312);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.374232*2/(0.12784+0.278312);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.195254*2/(0.12784+0.278312);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0975205*2/(0.12784+0.278312);  
	if(4.0 < RT)
	  corr_factor = 0.100115*2/(0.12784+0.278312);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.0;
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.174413*2/(0.245706+0.399974);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.425579*2/(0.245706+0.399974);  
	if(4.0 < RT)
	  corr_factor = 0.135788*2/(0.245706+0.399974);  
      }
    }
  }

  //Electrons
  if(fabs(id)==11){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.29987*2/(0.167109+0.209292);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.324846*2/(0.167109+0.209292);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.269954*2/(0.167109+0.209292);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.212899*2/(0.167109+0.209292);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.155951*2/(0.167109+0.209292);  
	if(4.0 < RT)
	  corr_factor = 0.129832*2/(0.167109+0.209292);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.268617*2/(0.139214+0.178219);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.270893*2/(0.139214+0.178219);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.251222*2/(0.139214+0.178219);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.154181*2/(0.139214+0.178219);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.113409*2/(0.139214+0.178219);  
	if(4.0 < RT)
	  corr_factor = 0.0946042*2/(0.139214+0.178219);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.268293*2/(0.13499+0.205972);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.344262*2/(0.13499+0.205972);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.258763*2/(0.13499+0.205972);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.124558*2/(0.13499+0.205972);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0909091*2/(0.13499+0.205972);  
	if(4.0 < RT)
	  corr_factor = 0.0714286*2/(0.13499+0.205972);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.333333*2/(0.135021+0.18593);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.272727*2/(0.135021+0.18593);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.236025*2/(0.135021+0.18593);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0935961*2/(0.135021+0.18593);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0487805*2/(0.135021+0.18593);  
	if(4.0 < RT)
	  corr_factor = 0.272727*2/(0.135021+0.18593);  
      }
    }
 
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.350163*2/(0.179412+0.26982);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.302662*2/(0.179412+0.26982);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.281593*2/(0.179412+0.26982);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.251746*2/(0.179412+0.26982);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.189898*2/(0.179412+0.26982);  
	if(4.0 < RT)
	  corr_factor = 0.150201*2/(0.179412+0.26982);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.203732*2/(0.122581+0.201439);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.291117*2/(0.122581+0.201439);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.263995*2/(0.122581+0.201439);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.158338*2/(0.122581+0.201439);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.121334*2/(0.122581+0.201439);  
	if(4.0 < RT)
	  corr_factor = 0.0994721*2/(0.122581+0.201439);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.454335*2/(0.139431+0.182538);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.371158*2/(0.139431+0.182538);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.239527*2/(0.139431+0.182538);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.14386*2/(0.139431+0.182538);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0882465*2/(0.139431+0.182538);  
	if(4.0 < RT)
	  corr_factor = 0.0489744*2/(0.139431+0.182538);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.33*2/(0.135657+0.186011);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.27*2/(0.135657+0.186011);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.224297*2/(0.135657+0.186011);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.159636*2/(0.135657+0.186011);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0750374*2/(0.135657+0.186011);  
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
  }
  return corr_factor;
}

double AnaScript::FakeRateMixed_Run3Summer22EE(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
    double FakeRate_DY   = FakeRate_Run3Summer22EE(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer22EE(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_Run3Summer22EE(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_Run3Summer22EE(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_Run3Summer22EE(id, v1, v2, "SingleMuon");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
    double FakeRate_DY   = FakeRate_Run3Summer22EE(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer22EE(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_Run3Summer22EE(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_Run3Summer22EE(id, pt, fabs(eta), "EGamma")*FakeRate_RT_Run3Summer22EE(id, v1, v2, "EGamma");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  return fake_rate;
}

double AnaScript::FakeRate_Run3Summer22(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.174799;
	if(15 < pt && pt < 25)
	  fake_rate = 0.147034;
	if(25 < pt && pt < 40)
	  fake_rate = 0.129278;
	if(40 < pt)
	  fake_rate = 0.0588235;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.256566;
	if(15 < pt && pt < 25)
	  fake_rate = 0.19702;
	if(25 < pt && pt < 40)
	  fake_rate = 0.227273;
	if(40 < pt)
	  fake_rate = 0.0;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.143816;
	if(15 < pt && pt < 25)
	  fake_rate = 0.110654;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0972803;
	if(40 < pt)
	  fake_rate = 0.0878378;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.203653;
	if(15 < pt && pt < 25)
	  fake_rate = 0.178609;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0956284;
	if(40 < pt)
	  fake_rate = 0.103448;
      }
    }
    
    //Data
    //EEM+MMM
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.153742;
	if(15 < pt && pt < 25)
	  fake_rate = 0.110642;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0;
	if(40 < pt)
	  fake_rate = 0.423526;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.227512;
	if(15 < pt && pt < 25)
	  fake_rate = 0.270536;
	if(25 < pt && pt < 40)
	  fake_rate = 0.197738;
	if(40 < pt)
	  fake_rate = 0.0102041;
      }
    }
  }
  
  //Electrons
  if(fabs(id)==11){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.165752;
	if(15 < pt && pt < 25)
	  fake_rate = 0.13348;
	if(25 < pt && pt < 40)
	  fake_rate = 0.169343;
	if(40 < pt)
	  fake_rate = 0.181818;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.214762;
	if(15 < pt && pt < 25)
	  fake_rate = 0.172755;
	if(25 < pt && pt < 40)
	  fake_rate = 0.205829;
	if(40 < pt)
	  fake_rate = 0.135135;
      }
    }
    
    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.207418;
	if(15 < pt && pt < 25)
	  fake_rate = 0.154835;
	if(25 < pt && pt < 40)
	  fake_rate = 0.116935;
	if(40 < pt)
	  fake_rate = 0.145631;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.229592;
	if(15 < pt && pt < 25)
	  fake_rate = 0.168385;
	if(25 < pt && pt < 40)
	  fake_rate = 0.262548;
	if(40 < pt)
	  fake_rate = 0.322034;
      }
    }
    
    //Data: EGamma
    //MME+EEE
    if(sample == "EGamma"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.175857;
	if(15 < pt && pt < 25)
	  fake_rate = 0.131192;
	if(25 < pt && pt < 40)
	  fake_rate = 0.151873;
	if(40 < pt)
	  fake_rate = 0.0949099;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.241702;
	if(15 < pt && pt < 25)
	  fake_rate = 0.176822;
	if(25 < pt && pt < 40)
	  fake_rate = 0.197052;
	if(40 < pt)
	  fake_rate = 0.153809;
      }
    }
  }
  return fake_rate;
}

double AnaScript::FakeRate_RT_Run3Summer22(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.256757*2/(0.174799+0.256566);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.302083*2/(0.174799+0.256566);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.316239*2/(0.174799+0.256566);    
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.227488*2/(0.174799+0.256566);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.15565*2/(0.174799+0.256566);  
	if(4.0 < RT)
	  corr_factor = 0.179061*2/(0.174799+0.256566);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.363636*2/(0.147034+0.19702);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.319444*2/(0.147034+0.19702);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.231959*2/(0.147034+0.19702);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.176056*2/(0.147034+0.19702);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.135922*2/(0.147034+0.19702);  
	if(4.0 < RT)
	  corr_factor = 0.108014*2/(0.147034+0.19702);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.4*2/(0.129278+0.227273);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.157895*2/(0.129278+0.227273);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.318182*2/(0.129278+0.227273);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.121495*2/(0.129278+0.227273);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.173469*2/(0.129278+0.227273);  
	if(4.0 < RT)
	  corr_factor = 0.0277778*2/(0.129278+0.227273);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.5*2/(0.0588235+0.0);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.0;
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0588235*2/(0.0588235+0.0);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0;
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.16957*2/(0.153742+0.227512);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.207316*2/(0.153742+0.227512);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.218572*2/(0.153742+0.227512);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.180983*2/(0.153742+0.227512);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.176105*2/(0.153742+0.227512);  
	if(4.0 < RT)
	  corr_factor = 0.166681*2/(0.153742+0.227512);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.161993*2/(0.110642+0.270536);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.331326*2/(0.110642+0.270536);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.179189*2/(0.110642+0.270536);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.132288*2/(0.110642+0.270536);  
	if(4.0 < RT)
	  corr_factor = 0.116627*2/(0.110642+0.270536);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.4*2/(0.197738);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.15*2/(0.197738);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.0491822*2/(0.197738);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0406632*2/(0.197738);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.073913*2/(0.197738);  
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 1.06008*2/(0.423526+0.0102041);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.418414*2/(0.423526+0.0102041);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0932416*2/(0.423526+0.0102041);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.596822*2/(0.423526+0.0102041);  
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
  }

  //Electrons
  if(fabs(id)==11){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.263158*2/(0.165752+0.214762);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.30226*2/(0.165752+0.214762);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.298309*2/(0.165752+0.214762);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.216569*2/(0.165752+0.214762);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.154618*2/(0.165752+0.214762);  
	if(4.0 < RT)
	  corr_factor = 0.13181*2/(0.165752+0.214762);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.231405*2/(0.13348+0.172755);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.307377*2/(0.13348+0.172755);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.260152*2/(0.13348+0.172755);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.153846*2/(0.13348+0.172755);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.102249*2/(0.13348+0.172755);  
	if(4.0 < RT)
	  corr_factor = 0.0867518*2/(0.13348+0.172755);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.25*2/(0.169343+0.205829);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.345455*2/(0.169343+0.205829);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.275449*2/(0.169343+0.205829);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.157025*2/(0.169343+0.205829);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.106838*2/(0.169343+0.205829);  
	if(4.0 < RT)
	  corr_factor = 0.0813954*2/(0.169343+0.205829);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.625*2/(0.181818+0.135135);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.196429*2/(0.181818+0.135135);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0724638*2/(0.181818+0.135135);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.176471*2/(0.181818+0.135135);  
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
    
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.333944*2/(0.175857+0.241702);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.336294*2/(0.175857+0.241702);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.269833*2/(0.175857+0.241702);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.208007*2/(0.175857+0.241702);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.177026*2/(0.175857+0.241702);  
	if(4.0 < RT)
	  corr_factor = 0.143041*2/(0.175857+0.241702);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.252107*2/(0.131192+0.176822);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.254497*2/(0.131192+0.176822);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.26233*2/(0.131192+0.176822);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.139241*2/(0.131192+0.176822);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.129015*2/(0.131192+0.176822);  
	if(4.0 < RT)
	  corr_factor = 0.0857486*2/(0.131192+0.176822);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.326838*2/(0.151873+0.197052);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.273855*2/(0.151873+0.197052);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.135124*2/(0.151873+0.197052);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0999149*2/(0.151873+0.197052);  
	if(4.0 < RT)
	  corr_factor = 0.12144*2/(0.151873+0.197052);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.625*2/(0.0949099+0.153809);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.29325*2/(0.0949099+0.153809);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.104276*2/(0.0949099+0.153809);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0;
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
  }
  return corr_factor;
}

double AnaScript::FakeRateMixed_Run3Summer22(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
    double FakeRate_DY   = FakeRate_Run3Summer22(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer22(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_Run3Summer22(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_Run3Summer22(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_Run3Summer22(id, v1, v2, "SingleMuon");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
    double FakeRate_DY   = FakeRate_Run3Summer22(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer22(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_Run3Summer22(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_Run3Summer22(id, pt, fabs(eta), "EGamma")*FakeRate_RT_Run3Summer22(id, v1, v2, "EGamma");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  return fake_rate;
}

