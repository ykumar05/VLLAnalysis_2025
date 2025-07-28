double AnaScript::FakeRate_Run3Summer23(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 15)
	  fake_rate = 0.199271;
	if(15 < pt && pt < 25)
	  fake_rate = 0.178873;
	if(25 < pt && pt < 40)
	  fake_rate = 0.140553;
	if(pt > 40)
	  fake_rate = 0.0506329;
      }
      // Endcap Region
      else{
	if(pt < 15)
	  fake_rate = 0.261478;
	if(15 < pt && pt < 25)
	  fake_rate = 0.229249;
	if(25 < pt && pt < 40)
	  fake_rate = 0.178771;
	if(pt > 40)
	  fake_rate = 0.0909091;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 15)
	  fake_rate = 0.144939;
	if(15 < pt && pt < 25)
	  fake_rate = 0.118058;
	if(25 < pt && pt < 40)
	  fake_rate = 0.105311;
	if(pt > 40)
	  fake_rate = 0.087108;
      }
      // Endcap Region
      else{
	if(pt < 15)
	  fake_rate = 0.20823;
	if(15 < pt && pt < 25)
	  fake_rate = 0.176077;
	if(25 < pt && pt < 40)
	  fake_rate = 0.142857;
	if(pt > 40)
	  fake_rate = 0.139535;
      }
    }

    // Data: SingleMuon
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 15)
	  fake_rate = 0.197276;
	if(15 < pt && pt < 25)
	  fake_rate = 0.16852;
	if(25 < pt && pt < 40)
	  fake_rate = 0.206952;
	if(pt > 40)
	  fake_rate = 0.0733173;
      }
      // Endcap Region
      else{
	if(pt < 15)
	  fake_rate = 0.282801;
	if(15 < pt && pt < 25)
	  fake_rate = 0.25398;
	if(25 < pt && pt < 40)
	  fake_rate = 0.202933;
	if(pt > 40)
	  fake_rate = 0.0353029;
      }
    }
  }

  // Electrons
  if(fabs(id)==11){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 15)
	  fake_rate = 0.19219;
	if(15 < pt && pt < 25)
	  fake_rate = 0.143412;
	if(25 < pt && pt < 40)
	  fake_rate = 0.127613;
	if(pt > 40)
	  fake_rate = 0.216981;
      }
      // Endcap Region
      else{
	if(pt < 15)
	  fake_rate = 0.228964;
	if(15 < pt && pt < 25)
	  fake_rate = 0.186446;
	if(25 < pt && pt < 40)
	  fake_rate = 0.199301;
	if(pt > 40)
	  fake_rate = 0.215054;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 15)
	  fake_rate = 0.196843;
	if(15 < pt && pt < 25)
	  fake_rate = 0.178091;
	if(25 < pt && pt < 40)
	  fake_rate = 0.131356;
	if(pt > 40)
	  fake_rate = 0.161616;
      }
      // Endcap Region
      else{
	if(pt < 15)
	  fake_rate = 0.238405;
	if(15 < pt && pt < 25)
	  fake_rate = 0.201774;
	if(25 < pt && pt < 40)
	  fake_rate = 0.247312;
	if(pt > 40)
	  fake_rate = 0.290909;
      }
    }

    // Data: EGamma
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 15)
	  fake_rate = 0.206867;
	if(15 < pt && pt < 25)
	  fake_rate = 0.157326;
	if(25 < pt && pt < 40)
	  fake_rate = 0.132539;
	if(pt > 40)
	  fake_rate = 0.165782;
      }
      // Endcap Region
      else{
	if(pt < 15)
	  fake_rate = 0.261117;
	if(15 < pt && pt < 25)
	  fake_rate = 0.203537;
	if(25 < pt && pt < 40)
	  fake_rate = 0.221971;
	if(pt > 40)
	  fake_rate = 0.111577;
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
	  corr_factor = 0.375*2/(0.199271+0.261478);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.318182*2/(0.199271+0.261478);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.247368*2/(0.199271+0.261478);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.26204*2/(0.199271+0.261478);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.22779*2/(0.199271+0.261478);  
	if(4.0 < RT)
	  corr_factor = 0.179748*2/(0.199271+0.261478);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.25*2/(0.178873+0.229249);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.25*2/(0.178873+0.229249);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.286517*2/(0.178873+0.229249);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.200553*2/(0.178873+0.229249);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.180723*2/(0.178873+0.229249);  
	if(4.0 < RT)
	  corr_factor = 0.153101*2/(0.178873+0.229249);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.307692*2/(0.140553+0.178771);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.470588*2/(0.140553+0.178771);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.229167*2/(0.140553+0.178771);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.140097*2/(0.140553+0.178771);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.120567*2/(0.140553+0.178771);  
	if(4.0 < RT)
	  corr_factor = 0.0806452*2/(0.140553+0.178771);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.0769231*2/(0.0506329+0.0909091);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.025641*2/(0.0506329+0.0909091);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0625*2/(0.0506329+0.0909091);  
	if(4.0 < RT)
	  corr_factor = 0.133333*2/(0.0506329+0.0909091);  
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.314178*2/(0.197276+0.282801);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.313968*2/(0.197276+0.282801);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.266428*2/(0.197276+0.282801);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.213168*2/(0.197276+0.282801);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.215793*2/(0.197276+0.282801);  
	if(4.0 < RT)
	  corr_factor = 0.186329*2/(0.197276+0.282801);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.365562*2/(0.16852+0.25398);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.329093*2/(0.16852+0.25398);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.32562*2/(0.16852+0.25398);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.181861*2/(0.16852+0.25398);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.155867*2/(0.16852+0.25398);  
	if(4.0 < RT)
	  corr_factor = 0.147044*2/(0.16852+0.25398);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.305111*2/(0.206952+0.202933);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.549657*2/(0.206952+0.202933);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.379525*2/(0.206952+0.202933);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.206191*2/(0.206952+0.202933);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0457764*2/(0.206952+0.202933);  
	if(4.0 < RT)
	  corr_factor = 0.111235*2/(0.206952+0.202933);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.113843*2/(0.0733173+0.0353029);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0823876*2/(0.0733173+0.0353029);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0466949*2/(0.0733173+0.0353029);  
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
	  corr_factor = 0.314024*2/(0.19219+0.228964);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.277512*2/(0.19219+0.228964);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.32613*2/(0.19219+0.228964);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.24181*2/(0.19219+0.228964);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.185528*2/(0.19219+0.228964);  
	if(4.0 < RT)
	  corr_factor = 0.151553*2/(0.19219+0.228964);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.232044*2/(0.143412+0.186446);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.313869*2/(0.143412+0.186446);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.289575*2/(0.143412+0.186446);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.161953*2/(0.143412+0.186446);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.120823*2/(0.143412+0.186446);  
	if(4.0 < RT)
	  corr_factor = 0.101*2/(0.143412+0.186446);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.5*2/(0.127613+0.199301);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.308824*2/(0.127613+0.199301);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.237762*2/(0.127613+0.199301);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.138177*2/(0.127613+0.199301);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0882353*2/(0.127613+0.199301);  
	if(4.0 < RT)
	  corr_factor = 0.0722892*2/(0.127613+0.199301);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.333333*2/(0.216981+0.215054);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.3*2/(0.216981+0.215054);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.28169*2/(0.216981+0.215054);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.144444*2/(0.216981+0.215054);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.12*2/(0.216981+0.215054);  
	if(4.0 < RT)
	  corr_factor = 0.166667*2/(0.216981+0.215054);  
      }
    }
 
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.360916*2/(0.206867+0.261117);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.327447*2/(0.206867+0.261117);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.314975*2/(0.206867+0.261117);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.240059*2/(0.206867+0.261117);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.201105*2/(0.206867+0.261117);  
	if(4.0 < RT)
	  corr_factor = 0.152346*2/(0.206867+0.261117);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.27011*2/(0.157326+0.203537);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.337834*2/(0.157326+0.203537);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.260683*2/(0.157326+0.203537);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.173478*2/(0.157326+0.203537);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.128227*2/(0.157326+0.203537);  
	if(4.0 < RT)
	  corr_factor = 0.109793*2/(0.157326+0.203537);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.4*2/(0.132539+0.221971);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.366858*2/(0.132539+0.221971);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.285368*2/(0.132539+0.221971);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.101879*2/(0.132539+0.221971);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.089562*2/(0.132539+0.221971);  
	if(4.0 < RT)
	  corr_factor = 0.0979018*2/(0.132539+0.221971);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.114152*2/(0.165782+0.111577);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.140872*2/(0.165782+0.111577);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0083809*2/(0.165782+0.111577);  
	if(4.0 < RT)
	  corr_factor = 0.21928*2/(0.165782+0.111577);  
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
}

double AnaScript::FakeRate_Run3Summer23BPix(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.207071; 
	if(15 < pt && pt < 25)
	  fake_rate = 0.157771; 
	if(25 < pt && pt < 40)
	  fake_rate = 0.151625; 
	if(40 < pt)
	  fake_rate = 0.0869565;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.2466; 
	if(15 < pt && pt < 25)
	  fake_rate = 0.243902;
	if(25 < pt && pt < 40)
	  fake_rate = 0.218391;
	if(40 < pt)
	  fake_rate = 0.0714286;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.145467; 
	if(15 < pt && pt < 25)
	  fake_rate = 0.107204; 
	if(25 < pt && pt < 40)
	  fake_rate = 0.0869231;
	if(40 < pt)
	  fake_rate = 0.0651558; 
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.212598; 
	if(15 < pt && pt < 25)
	  fake_rate = 0.172589; 
	if(25 < pt && pt < 40)
	  fake_rate = 0.129741; 
	if(40 < pt)
	  fake_rate = 0.156863; 
      }
    }

    // Data
    // EEM + MMM
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.183002; 
	if(15 < pt && pt < 25)
	  fake_rate = 0.171971; 
	if(25 < pt && pt < 40)
	  fake_rate = 0.175999; 
	if(40 < pt)
	  fake_rate = 0.269644; 
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.264219; 
	if(15 < pt && pt < 25)
	  fake_rate = 0.217185; 
	if(25 < pt && pt < 40)
	  fake_rate = 0.156871; 
	if(40 < pt)
	  fake_rate = 0.138633; 
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
	  fake_rate = 0.180793;
	if(15 < pt && pt < 25)
	  fake_rate = 0.14465;
	if(25 < pt && pt < 40)
	  fake_rate = 0.150709;
	if(40 < pt)
	  fake_rate = 0.2;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.222863;
	if(15 < pt && pt < 25)
	  fake_rate = 0.181342;
	if(25 < pt && pt < 40)
	  fake_rate = 0.218868;
	if(40 < pt)
	  fake_rate = 0.1;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.210815;
	if(15 < pt && pt < 25)
	  fake_rate = 0.174085;
	if(25 < pt && pt < 40)
	  fake_rate = 0.193277;
	if(40 < pt)
	  fake_rate = 0.241758;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.246617;
	if(15 < pt && pt < 25)
	  fake_rate = 0.202151;
	if(25 < pt && pt < 40)
	  fake_rate = 0.177852;
	if(40 < pt)
	  fake_rate = 0.196429;
      }
    }

    // Data: EGamma
    // MME + EEE
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.220425;
	if(15 < pt && pt < 25)
	  fake_rate = 0.170994;
	if(25 < pt && pt < 40)
	  fake_rate = 0.176787;
	if(40 < pt)
	  fake_rate = 0.313755;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.270684;
	if(15 < pt && pt < 25)
	  fake_rate = 0.206286;
	if(25 < pt && pt < 40)
	  fake_rate = 0.238418;
	if(40 < pt)
	  fake_rate = 0.303398;
      }
    }
  }

  return fake_rate;
}

double AnaScript::FakeRate_RT_Run3Summer23BPix(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.337349*2/(0.207071+0.2466);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.350515*2/(0.207071+0.2466);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.369159*2/(0.207071+0.2466);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.240741*2/(0.207071+0.2466);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.210923*2/(0.207071+0.2466);
	if(4.0 < RT)
	  corr_factor = 0.185259*2/(0.207071+0.2466);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.1875*2/(0.157771+0.243902);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.296875*2/(0.157771+0.243902);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.269231*2/(0.157771+0.243902);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.200935*2/(0.157771+0.243902);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.172646*2/(0.157771+0.243902);
	if(4.0 < RT)
	  corr_factor = 0.144186*2/(0.157771+0.243902);
      }
      if(25 < pt && pt < 40){ 
      	if(RT < 0.0)
	  corr_factor = 0.6*2/(0.151625+0.218391);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.333333*2/(0.151625+0.218391);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.214286*2/(0.151625+0.218391);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.169811*2/(0.151625+0.218391);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.119048*2/(0.151625+0.218391);
	if(4.0 < RT)
	  corr_factor = 0.120879*2/(0.151625+0.218391);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.166667*2/(0.0869565+0.0714286);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.037037*2/(0.0869565+0.0714286);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.181818*2/(0.0869565+0.0714286);
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.32508*2/(0.264219+0.183002);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.310058*2/(0.264219+0.183002);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.270098*2/(0.264219+0.183002);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.222587*2/(0.264219+0.183002);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.202191*2/(0.264219+0.183002);
	if(4.0 < RT)
	  corr_factor = 0.174801*2/(0.264219+0.183002);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.195418*2/(0.171971+0.217185);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.397*2/(0.171971+0.217185);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.260682*2/(0.171971+0.217185);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.164553*2/(0.171971+0.217185);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.158541*2/(0.171971+0.217185);
	if(4.0 < RT)
	  corr_factor = 0.157974*2/(0.171971+0.217185);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.195981*2/(0.175999+0.156871);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.478708*2/(0.175999+0.156871);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.00017449*2/(0.175999+0.156871);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.188214*2/(0.175999+0.156871);
	if(4.0 < RT)
	  corr_factor = 0.0425455*2/(0.175999+0.156871);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.0;
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.234047*2/(0.269644+0.138633);
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
	  corr_factor = 0.310734*2/(0.180793+0.222863);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.345763*2/(0.180793+0.222863);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.345336*2/(0.180793+0.222863);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.213003*2/(0.180793+0.222863);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.163911*2/(0.180793+0.222863);
	if(4.0 < RT)
	  corr_factor = 0.141499*2/(0.180793+0.222863);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.303371*2/(0.14465+0.181342);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.302564*2/(0.14465+0.181342);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.259968*2/(0.14465+0.181342);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.164269*2/(0.14465+0.181342);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.130056*2/(0.14465+0.181342);
	if(4.0 < RT)
	  corr_factor = 0.103187*2/(0.14465+0.181342);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.208333*2/(0.150709+0.218868);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.347826*2/(0.150709+0.218868);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.304659*2/(0.150709+0.218868);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.134091*2/(0.150709+0.218868);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.136585*2/(0.150709+0.218868);
	if(4.0 < RT)
	  corr_factor = 0.0689655*2/(0.150709+0.218868);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.571429*2/(0.2+0.1);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.227273*2/(0.2+0.1);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0545455*2/(0.2+0.1);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.05*2/(0.2+0.1);
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
 
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.399445*2/(0.220425+0.270684);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.300283*2/(0.220425+0.270684);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.326284*2/(0.220425+0.270684);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.25596*2/(0.220425+0.270684);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.199098*2/(0.220425+0.270684);
	if(4.0 < RT)
	  corr_factor = 0.164113*2/(0.220425+0.270684);
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.354358*2/(0.170994+0.206286);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.377938*2/(0.170994+0.206286);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.267336*2/(0.170994+0.206286);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.188673*2/(0.170994+0.206286);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.147092*2/(0.170994+0.206286);
	if(4.0 < RT)
	  corr_factor = 0.0877792*2/(0.170994+0.206286);
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.349613*2/(0.176787+0.238418);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.294403*2/(0.176787+0.238418);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.292642*2/(0.176787+0.238418);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.18114*2/(0.176787+0.238418);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.139562*2/(0.176787+0.238418);
	if(4.0 < RT)
	  corr_factor = 0.0474037*2/(0.176787+0.238418);
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.479337*2/(0.313755+0.303398);
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.258948*2/(0.313755+0.303398);
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.267839*2/(0.313755+0.303398);
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.372018*2/(0.313755+0.303398);
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
  }
  return corr_factor;
}

double AnaScript::FakeRateMixed_Run3Summer23BPix(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
    double FakeRate_DY   = FakeRate_Run3Summer23BPix(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer23BPix(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_Run3Summer23BPix(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_Run3Summer23BPix(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_Run3Summer23BPix(id, v1, v2, "SingleMuon");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
    double FakeRate_DY   = FakeRate_Run3Summer23BPix(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_Run3Summer23BPix(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_Run3Summer23BPix(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_Run3Summer23BPix(id, pt, fabs(eta), "EGamma")*FakeRate_RT_Run3Summer23BPix(id, v1, v2, "EGamma");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  return fake_rate;
}

