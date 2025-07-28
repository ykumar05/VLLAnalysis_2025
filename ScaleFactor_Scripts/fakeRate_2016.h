double AnaScript::FakeRate_UL16preVFP(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.151057;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0977897;
	if(25 < pt && pt < 40)
	  fake_rate = 0.105263;
	if(40 < pt)
	  fake_rate = 0.0425532;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.229342;
	if(15 < pt && pt < 25)
	  fake_rate = 0.183702;
	if(25 < pt && pt < 40)
	  fake_rate = 0.125;
	if(40 < pt)
	  fake_rate = 0.125;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.108098;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0698451;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0620819;
	if(40 < pt)
	  fake_rate = 0.0633528;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.173548;
	if(15 < pt && pt < 25)
	  fake_rate = 0.135367;
	if(25 < pt && pt < 40)
	  fake_rate = 0.122465;
	if(40 < pt)
	  fake_rate = 0.1125;
      }
    }

    // Data: SingleMuon (EEM + MMM)
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.154063;
	if(15 < pt && pt < 25)
	  fake_rate = 0.104203;
	if(25 < pt && pt < 40)
	  fake_rate = 0.11948;
	if(40 < pt)
	  fake_rate = 0.152372;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.206571;
	if(15 < pt && pt < 25)
	  fake_rate = 0.153808;
	if(25 < pt && pt < 40)
	  fake_rate = 0.203809;
	if(40 < pt)
	  fake_rate = 0.298498;
      }
    }
  }

  // Electrons
  if(fabs(id)==11){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.171638;
	if(15 < pt && pt < 25)
	  fake_rate = 0.119837;
	if(25 < pt && pt < 40)
	  fake_rate = 0.114638;
	if(40 < pt)
	  fake_rate = 0.104651;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.264998;
	if(15 < pt && pt < 25)
	  fake_rate = 0.223514;
	if(25 < pt && pt < 40)
	  fake_rate = 0.223039;
	if(40 < pt)
	  fake_rate = 0.36;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.119112;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0756098;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0570087;
	if(40 < pt)
	  fake_rate = 0.0662824;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.252498;
	if(15 < pt && pt < 25)
	  fake_rate = 0.190618;
	if(25 < pt && pt < 40)
	  fake_rate = 0.180747;
	if(40 < pt)
	  fake_rate = 0.264151;
      }
    }

    // Data: EGamma (MME + EEE)
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.184773;
	if(15 < pt && pt < 25)
	  fake_rate = 0.102615;
	if(25 < pt && pt < 40)
	  fake_rate = 0.100895;
	if(40 < pt)
	  fake_rate = 0.106531;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.297201;
	if(15 < pt && pt < 25)
	  fake_rate = 0.201651;
	if(25 < pt && pt < 40)
	  fake_rate = 0.208601;
	if(40 < pt)
	  fake_rate = 0.101747;
      }
    }
  }
  
  return fake_rate;
}

double AnaScript::FakeRate_RT_UL16preVFP(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.182927*2/(0.151057+0.229342);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.287671*2/(0.151057+0.229342);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.246154*2/(0.151057+0.229342);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.220339*2/(0.151057+0.229342);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.175943*2/(0.151057+0.229342);
	if(4.0 < RT)
	  corr_factor = 0.135003*2/(0.151057+0.229342);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.163265*2/(0.0977897+0.183702);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.131579*2/(0.0977897+0.183702); 
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.20132*2/(0.0977897+0.183702); 
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.134809*2/(0.0977897+0.183702); 
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0982987*2/(0.0977897+0.183702); 
	if(4.0 < RT)
	  corr_factor = 0.0932568*2/(0.0977897+0.183702); 
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.166667*2/(0.105263+0.125);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.130435*2/(0.105263+0.125);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.166667*2/(0.105263+0.125);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.10929*2/(0.105263+0.125);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.101852*2/(0.105263+0.125);
	if(4.0 < RT)
	  corr_factor = 0.0686275*2/(0.105263+0.125);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.117647*2/(0.0425532+0.125);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0740741*2/(0.0425532+0.125);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0625*2/(0.0425532+0.125);
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.211124*2/(0.154063+0.206571);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.216373*2/(0.154063+0.206571);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.221956*2/(0.154063+0.206571);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.196526*2/(0.154063+0.206571);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.146331*2/(0.154063+0.206571);
	if(4.0 < RT)
	  corr_factor = 0.140575*2/(0.154063+0.206571);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.230898*2/(0.104203+0.153808);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.24675*2/(0.104203+0.153808); 
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.152896*2/(0.104203+0.153808); 
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.14064*2/(0.104203+0.153808); 
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0923358*2/(0.104203+0.153808); 
	if(4.0 < RT)
	  corr_factor = 0.0789427*2/(0.104203+0.153808); 
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.3*2/(0.11948+0.203809);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.25*2/(0.11948+0.203809);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.181045*2/(0.11948+0.203809);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.149046*2/(0.11948+0.203809);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0966451*2/(0.11948+0.203809);
	if(4.0 < RT)
	  corr_factor = 0.116806*2/(0.11948+0.203809);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.3*2/(0.152372+0.298498);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.279369*2/(0.152372+0.298498);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0977235*2/(0.152372+0.298498);
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
	  corr_factor = 0.324561*2/(0.171638+0.264998);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.34555*2/(0.171638+0.264998);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.352304*2/(0.171638+0.264998);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.239583*2/(0.171638+0.264998);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.184343*2/(0.171638+0.264998);
	if(4.0 < RT)
	  corr_factor = 0.153262*2/(0.171638+0.264998);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.228571*2/(0.119837+0.223514);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.327161*2/(0.119837+0.223514);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.290698*2/(0.119837+0.223514);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.141732*2/(0.119837+0.223514);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.113665*2/(0.119837+0.223514);
	if(4.0 < RT)
	  corr_factor = 0.0897616*2/(0.119837+0.223514);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.2*2/(0.114638+0.223039);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.380952*2/(0.114638+0.223039);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.239286*2/(0.114638+0.223039);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.127072*2/(0.114638+0.223039);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0584795*2/(0.114638+0.223039);
	if(4.0 < RT)
	  corr_factor = 0.0454545*2/(0.114638+0.223039);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.3*2/(0.104651+0.36);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.295455*2/(0.104651+0.36);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.147059*2/(0.104651+0.36);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0;
	if(4.0 < RT)
	  corr_factor = 0.25*2/(0.104651+0.36);
      }
    }
 
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.323153*2/(0.184773+0.297201);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.393232*2/(0.184773+0.297201);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.334631*2/(0.184773+0.297201);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.260414*2/(0.184773+0.297201);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.198941*2/(0.184773+0.297201);
	if(4.0 < RT)
	  corr_factor = 0.158833*2/(0.184773+0.297201);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.400732*2/(0.102615+0.201651);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.253791*2/(0.102615+0.201651);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.223261*2/(0.102615+0.201651);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.134878*2/(0.102615+0.201651);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.091568*2/(0.102615+0.201651);
	if(4.0 < RT)
	  corr_factor = 0.0955307*2/(0.102615+0.201651);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.113405*2/(0.208601+0.100895);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.212159*2/(0.208601+0.100895);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.127238*2/(0.208601+0.100895);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.124093*2/(0.208601+0.100895);
	if(4.0 < RT)
	  corr_factor = 0.0821691*2/(0.208601+0.100895);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.2*2/(0.106531+0.101747);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.371613*2/(0.106531+0.101747);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.134093*2/(0.106531+0.101747);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0183316*2/(0.106531+0.101747);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.144962*2/(0.106531+0.101747);
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
  }
  return corr_factor;
}

double AnaScript::FakeRateMixed_UL16preVFP(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
    double FakeRate_DY   = FakeRate_UL16preVFP(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL16preVFP(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL16preVFP(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL16preVFP(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_UL16preVFP(id, v1, v2, "SingleMuon");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
    double FakeRate_DY   = FakeRate_UL16preVFP(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL16preVFP(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL16preVFP(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL16preVFP(id, pt, fabs(eta), "EGamma")*FakeRate_RT_UL16preVFP(id, v1, v2, "EGamma");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  return fake_rate;
}

double AnaScript::FakeRate_UL16postVFP(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;
  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.149112;
	if(15 < pt && pt < 25)
	  fake_rate = 0.116667;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0608974;
	if(40 < pt)
	  fake_rate = 0.125;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.216272;
	if(15 < pt && pt < 25)
	  fake_rate = 0.211244;
	if(25 < pt && pt < 40)
	  fake_rate = 0.131579;
	if(40 < pt)
	  fake_rate = 0.0588235;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.110294;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0679573;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0584062;
	if(40 < pt)
	  fake_rate = 0.0590829;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.151213;
	if(15 < pt && pt < 25)
	  fake_rate = 0.13248;
	if(25 < pt && pt < 40)
	  fake_rate = 0.13076;
	if(40 < pt)
	  fake_rate = 0.145773;
      }
    }

    // Data (SingleMuon: EEM+MMM)
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.149318;
	if(15 < pt && pt < 25)
	  fake_rate = 0.112898;
	if(25 < pt && pt < 40)
	  fake_rate = 0.107582;
	if(40 < pt)
	  fake_rate = 0.0242189;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.233949;
	if(15 < pt && pt < 25)
	  fake_rate = 0.195935;
	if(25 < pt && pt < 40)
	  fake_rate = 0.196493;
	if(40 < pt)
	  fake_rate = 0.114213;
      }
    }
  }
  
  // Electrons
  if(fabs(id)==11){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.172572;
	if(15 < pt && pt < 25)
	  fake_rate = 0.11536;
	if(25 < pt && pt < 40)
	  fake_rate = 0.115226;
	if(40 < pt)
	  fake_rate = 0.192308;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.250299;
	if(15 < pt && pt < 25)
	  fake_rate = 0.219011;
	if(25 < pt && pt < 40)
	  fake_rate = 0.22293;
	if(40 < pt)
	  fake_rate = 0.241379;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.127681;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0658762;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0540541;
	if(40 < pt)
	  fake_rate = 0.0551559;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.234734;
	if(15 < pt && pt < 25)
	  fake_rate = 0.184145;
	if(25 < pt && pt < 40)
	  fake_rate = 0.164763;
	if(40 < pt)
	  fake_rate = 0.258333;
      }
    }

    // Data: EGamma (MME + EEE)
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.186289;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0889558;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0785713;
	if(40 < pt)
	  fake_rate = 0.108839;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.313333;
	if(15 < pt && pt < 25)
	  fake_rate = 0.207566;
	if(25 < pt && pt < 40)
	  fake_rate = 0.259627;
	if(40 < pt)
	  fake_rate = 0.358312;
      }
    }
  }
  
  return fake_rate;
}

double AnaScript::FakeRate_RT_UL16postVFP(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.216667*2/(0.149112+0.216272);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.277778*2/(0.149112+0.216272);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.200803*2/(0.149112+0.216272);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.21134*2/(0.149112+0.216272);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.169528*2/(0.149112+0.216272);  
	if(4.0 < RT)
	  corr_factor = 0.128226*2/(0.149112+0.216272);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.285714*2/(0.116667+0.211244);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.222222*2/(0.116667+0.211244);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.22831*2/(0.116667+0.211244);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.144186*2/(0.116667+0.211244);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.131653*2/(0.116667+0.211244);  
	if(4.0 < RT)
	  corr_factor = 0.102857*2/(0.116667+0.211244);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.125*2/(0.0608974+0.131579);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0833333*2/(0.0608974+0.131579);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.0769231*2/(0.0608974+0.131579);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0689655*2/(0.0608974+0.131579);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0625*2/(0.0608974+0.131579);  
	if(4.0 < RT)
	  corr_factor = 0.113924*2/(0.0608974+0.131579);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.142857*2/(0.125+0.0588235);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0952381*2/(0.125+0.0588235);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0714286*2/(0.125+0.0588235);  
	if(4.0 < RT)
	  corr_factor = 0.142857*2/(0.125+0.0588235);  
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.223726*2/(0.149318+0.233949);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.254507*2/(0.149318+0.233949);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.27042*2/(0.149318+0.233949);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.192425*2/(0.149318+0.233949);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.183673*2/(0.149318+0.233949);
	if(4.0 < RT)
	  corr_factor = 0.13438*2/(0.149318+0.233949);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.321698*2/(0.112898+0.195935);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.304727*2/(0.112898+0.195935);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.19068*2/(0.112898+0.195935);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.125762*2/(0.112898+0.195935);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.125027*2/(0.112898+0.195935);
	if(4.0 < RT)
	  corr_factor = 0.10719*2/(0.112898+0.195935);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.279031*2/(0.107582+0.196493);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.135533*2/(0.107582+0.196493);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.273019*2/(0.107582+0.196493);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0726039*2/(0.107582+0.196493);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.106175*2/(0.107582+0.196493);
	if(4.0 < RT)
	  corr_factor = 0.1291*2/(0.107582+0.196493);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.342335*2/(0.0242189+0.114213);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0331532*2/(0.0242189+0.114213);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0;
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
	  corr_factor = 0.319588*2/(0.172572+0.250299);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.322981*2/(0.172572+0.250299);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.373737*2/(0.172572+0.250299);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.23775*2/(0.172572+0.250299);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.161695*2/(0.172572+0.250299);
	if(4.0 < RT)
	  corr_factor = 0.139866*2/(0.172572+0.250299);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.21875*2/(0.11536+0.219011);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.302817*2/(0.11536+0.219011);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.281314*2/(0.11536+0.219011);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.12788*2/(0.11536+0.219011);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.112462*2/(0.11536+0.219011);
	if(4.0 < RT)
	  corr_factor = 0.0998249*2/(0.11536+0.219011);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.2*2/(0.115226+0.22293);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.3*2/(0.115226+0.22293);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.231111*2/(0.115226+0.22293);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.10303*2/(0.115226+0.22293);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0873016*2/(0.115226+0.22293);
	if(4.0 < RT)
	  corr_factor = 0.0454545*2/(0.115226+0.22293);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.130057*2/(0.192308+0.241379);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.25*2/(0.192308+0.241379);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.075*2/(0.192308+0.241379);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.25*2/(0.192308+0.241379);
	if(4.0 < RT)
	  corr_factor = 0.25*2/(0.192308+0.241379);
      }
    }
 
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.421201*2/(0.186289+0.313333);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.362925*2/(0.186289+0.313333);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.355049*2/(0.186289+0.313333);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.253468*2/(0.186289+0.313333);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.223804*2/(0.186289+0.313333);
	if(4.0 < RT)
	  corr_factor = 0.167214*2/(0.186289+0.313333);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.252644*2/(0.0889558+0.207566);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.263859*2/(0.0889558+0.207566);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.213888*2/(0.0889558+0.207566);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.139303*2/(0.0889558+0.207566);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0998139*2/(0.0889558+0.207566);
	if(4.0 < RT)
	  corr_factor = 0.0996427*2/(0.0889558+0.207566);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.3*2/(0.0785713+0.259627);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.249325*2/(0.0785713+0.259627);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.244185*2/(0.0785713+0.259627);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.122139*2/(0.0785713+0.259627);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0560319*2/(0.0785713+0.259627);
	if(4.0 < RT)
	  corr_factor = 0.0956468*2/(0.0785713+0.259627);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.120294*2/(0.108839+0.358312);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.216617*2/(0.108839+0.358312);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.36887*2/(0.108839+0.358312);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0;
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
  }
  return corr_factor;
}

double AnaScript::FakeRateMixed_UL16postVFP(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
    double FakeRate_DY   = FakeRate_UL16postVFP(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL16postVFP(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL16postVFP(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL16postVFP(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_UL16postVFP(id, v1, v2, "SingleMuon");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
    double FakeRate_DY   = FakeRate_UL16postVFP(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL16postVFP(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL16postVFP(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL16postVFP(id, pt, fabs(eta), "EGamma")*FakeRate_RT_UL16postVFP(id, v1, v2, "EGamma");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  return fake_rate;
}

