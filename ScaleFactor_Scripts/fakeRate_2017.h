double AnaScript::FakeRate_UL17(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.165891;
	if(15 < pt && pt < 25)
	  fake_rate = 0.129702;
	if(25 < pt && pt < 40)
	  fake_rate = 0.116487;
	if(40 < pt)
	  fake_rate = 0.0454545;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.220077;
	if(15 < pt && pt < 25)
	  fake_rate = 0.179695;
	if(25 < pt && pt < 40)
	  fake_rate = 0.212121;
	if(40 < pt)
	  fake_rate = 0.0909091;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.118552;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0819034;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0652355;
	if(40 < pt)
	  fake_rate = 0.0643508;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.163991;
	if(15 < pt && pt < 25)
	  fake_rate = 0.131343;
	if(25 < pt && pt < 40)
	  fake_rate = 0.1195;
	if(40 < pt)
	  fake_rate = 0.126459;
      }
    }

    //Data: SingleMuon
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.163982;
	if(15 < pt && pt < 25)
	  fake_rate = 0.126088;
	if(25 < pt && pt < 40)
	  fake_rate = 0.223413;
	if(40 < pt)
	  fake_rate = 0.149179;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.234137;
	if(15 < pt && pt < 25)
	  fake_rate = 0.206537;
	if(25 < pt && pt < 40)
	  fake_rate = 0.20231;
	if(40 < pt)
	  fake_rate = 0.118446;
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
	  fake_rate = 0.159986;
	if(15 < pt && pt < 25)
	  fake_rate = 0.104257;
	if(25 < pt && pt < 40)
	  fake_rate = 0.108657;
	if(40 < pt)
	  fake_rate = 0.0729927;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.222053;
	if(15 < pt && pt < 25)
	  fake_rate = 0.187664;
	if(25 < pt && pt < 40)
	  fake_rate = 0.216066;
	if(40 < pt)
	  fake_rate = 0.148515;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.137535;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0704023;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0617378;
	if(40 < pt)
	  fake_rate = 0.0865874;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.233294;
	if(15 < pt && pt < 25)
	  fake_rate = 0.159222;
	if(25 < pt && pt < 40)
	  fake_rate = 0.182762;
	if(40 < pt)
	  fake_rate = 0.240506;
      }
    }

    //Data: EGamma
    //MME+EEE
    if(sample == "EGamma"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.180344;
	if(15 < pt && pt < 25)
	  fake_rate = 0.113215;
	if(25 < pt && pt < 40)
	  fake_rate = 0.128776;
	if(40 < pt)
	  fake_rate = 0.329585;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.289173;
	if(15 < pt && pt < 25)
	  fake_rate = 0.215403;
	if(25 < pt && pt < 40)
	  fake_rate = 0.22872;
	if(40 < pt)
	  fake_rate = 0.427387;
      }
    }
  }  
  
  return fake_rate;
}

double AnaScript::FakeRate_RT_UL17(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.245614*2/(0.165891+0.220077);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.331579*2/(0.165891+0.220077);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.246231*2/(0.165891+0.220077);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.211648*2/(0.165891+0.220077);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.187421*2/(0.165891+0.220077);  
	if(4.0 < RT)
	  corr_factor = 0.140415*2/(0.165891+0.220077);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.238095*2/(0.129702+0.179695);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.230769*2/(0.129702+0.179695);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.192513*2/(0.129702+0.179695);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.166667*2/(0.129702+0.179695);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.125828*2/(0.129702+0.179695);  
	if(4.0 < RT)
	  corr_factor = 0.110276*2/(0.129702+0.179695);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.25*2/(0.116487+0.212121);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.296296*2/(0.116487+0.212121);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.168*2/(0.116487+0.212121);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.182186*2/(0.116487+0.212121);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0625*2/(0.116487+0.212121);  
	if(4.0 < RT)
	  corr_factor = 0.117978*2/(0.116487+0.212121);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.25*2/(0.0454545+0.0909091);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0;
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.034*2/(0.0454545+0.0909091);  
	if(4.0 < RT)
	  corr_factor = 0.0714286*2/(0.0454545+0.0909091);  
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.243374*2/(0.163982+0.234137);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.291237*2/(0.163982+0.234137);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.270482*2/(0.163982+0.234137);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.196018*2/(0.163982+0.234137);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.172585*2/(0.163982+0.234137);  
	if(4.0 < RT)
	  corr_factor = 0.146788*2/(0.163982+0.234137);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.2442*2/(0.126088+0.206537);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.290749*2/(0.126088+0.206537);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.201879*2/(0.126088+0.206537);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.182257*2/(0.126088+0.206537);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.109228*2/(0.126088+0.206537);  
	if(4.0 < RT)
	  corr_factor = 0.116804*2/(0.126088+0.206537);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.377765*2/(0.223413+0.20231);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.478241*2/(0.223413+0.20231);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.338525*2/(0.223413+0.20231);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.229522*2/(0.223413+0.20231);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.188653*2/(0.223413+0.20231);  
	if(4.0 < RT)
	  corr_factor = 0.0570508*2/(0.223413+0.20231);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.10923*2/(0.149179+0.118446);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.158929*2/(0.149179+0.118446);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0990395*2/(0.149179+0.118446);  
	if(4.0 < RT)
	  corr_factor = 0.145759*2/(0.149179+0.118446);  
      }
    }
  }

  //Electrons
  if(fabs(id)==11){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.333333*2/(0.159986+0.222053);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.272727*2/(0.159986+0.222053);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.299413*2/(0.159986+0.222053);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.220323*2/(0.159986+0.222053);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.157631*2/(0.159986+0.222053);  
	if(4.0 < RT)
	  corr_factor = 0.136013*2/(0.159986+0.222053);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.138686*2/(0.104257+0.187664);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.315603*2/(0.104257+0.187664);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.230861*2/(0.104257+0.187664);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.121528*2/(0.104257+0.187664);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0944484*2/(0.104257+0.187664);  
	if(4.0 < RT)
	  corr_factor = 0.10423*2/(0.104257+0.187664);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.228571*2/(0.108657+0.216066);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.325*2/(0.108657+0.216066);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.220859*2/(0.108657+0.216066);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.113757*2/(0.108657+0.216066);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0838509*2/(0.108657+0.216066);  
	if(4.0 < RT)
	  corr_factor = 0.0923077*2/(0.108657+0.216066);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.125*2/(0.0729927+0.148515);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.162162*2/(0.0729927+0.148515);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.092437*2/(0.0729927+0.148515);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0606061*2/(0.0729927+0.148515);  
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
 
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.356269*2/(0.180344+0.289173);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.368656*2/(0.180344+0.289173);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.318305*2/(0.180344+0.289173);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.261542*2/(0.180344+0.289173);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.202515*2/(0.180344+0.289173);  
	if(4.0 < RT)
	  corr_factor = 0.162584*2/(0.180344+0.289173);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.245643*2/(0.113215+0.215403);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.275305*2/(0.113215+0.215403);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.258155*2/(0.113215+0.215403);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.150911*2/(0.113215+0.215403);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.118434*2/(0.113215+0.215403);  
	if(4.0 < RT)
	  corr_factor = 0.102907*2/(0.113215+0.215403);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.320505*2/(0.128776+0.22872);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.334605*2/(0.128776+0.22872);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.284811*2/(0.128776+0.22872);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.107539*2/(0.128776+0.22872);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.097591*2/(0.128776+0.22872);  
	if(4.0 < RT)
	  corr_factor = 0.104006*2/(0.128776+0.22872);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.39;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.25*2/(0.329585+0.427387);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.233065*2/(0.329585+0.427387);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.269833*2/(0.329585+0.427387);  
	if(4.0 < RT)
	  corr_factor = 0.0565281*2/(0.329585+0.427387);  
      }
    }
  }
  return corr_factor;
}

double AnaScript::FakeRateMixed_UL17(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
    double FakeRate_DY   = FakeRate_UL17(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL17(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL17(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL17(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_UL17(id, v1, v2, "SingleMuon");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
    double FakeRate_DY   = FakeRate_UL17(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL17(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL17(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL17(id, pt, fabs(eta), "EGamma")*FakeRate_RT_UL17(id, v1, v2, "EGamma");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  return fake_rate;
}
