double AnaScript::FakeRate_UL18(int id, float pt, float eta, string sample){
  float fake_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.172847;
	if(15 < pt && pt < 25)
	  fake_rate = 0.126582;
	if(25 < pt && pt < 40)
	  fake_rate = 0.110057;
	if(40 < pt)
	  fake_rate = 0.112676;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.201447;
	if(15 < pt && pt < 25)
	  fake_rate = 0.158491;
	if(25 < pt && pt < 40)
	  fake_rate = 0.17284;
	if(40 < pt)
	  fake_rate = 0.0322581;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.122044;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0772769;
	if(25 < pt && pt < 40)
	  fake_rate = 0.065202;
	if(40 < pt)
	  fake_rate = 0.0673126;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.167599;
	if(15 < pt && pt < 25)
	  fake_rate = 0.123769;
	if(25 < pt && pt < 40)
	  fake_rate = 0.131774;
	if(40 < pt)
	  fake_rate = 0.122278;
      }
    }
  
    //Data
    //EEM+MMM
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.180723;
	if(15 < pt && pt < 25)
	  fake_rate = 0.122118;
	if(25 < pt && pt < 40)
	  fake_rate = 0.13027;
	if(40 < pt)
	  fake_rate = 0.142533;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.233882;
	if(15 < pt && pt < 25)
	  fake_rate = 0.201249;
	if(25 < pt && pt < 40)
	  fake_rate = 0.246629;
	if(40 < pt)
	  fake_rate = 0.0;
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
	  fake_rate = 0.1455;
	if(15 < pt && pt < 25)
	  fake_rate = 0.111882;
	if(25 < pt && pt < 40)
	  fake_rate = 0.106864;
	if(40 < pt)
	  fake_rate = 0.0642857;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.20382;
	if(15 < pt && pt < 25)
	  fake_rate = 0.172452;
	if(25 < pt && pt < 40)
	  fake_rate = 0.179085;
	if(40 < pt)
	  fake_rate = 0.181818;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.122316;
	if(15 < pt && pt < 25)
	  fake_rate = 0.0759746;
	if(25 < pt && pt < 40)
	  fake_rate = 0.077198;
	if(40 < pt)
	  fake_rate = 0.0864023;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.20343;
	if(15 < pt && pt < 25)
	  fake_rate = 0.169301;
	if(25 < pt && pt < 40)
	  fake_rate = 0.194444;
	if(40 < pt)
	  fake_rate = 0.236364;
      }
    }

    //Data: EGamma
    //MME+EEE
    if(sample == "EGamma"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(15 > pt)
	  fake_rate = 0.174881;
	if(15 < pt && pt < 25)
	  fake_rate = 0.097214;
	if(25 < pt && pt < 40)
	  fake_rate = 0.0844783;
	if(40 < pt)
	  fake_rate = 0.0972829;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(15 > pt)
	  fake_rate = 0.272429;
	if(15 < pt && pt < 25)
	  fake_rate = 0.193432;
	if(25 < pt && pt < 40)
	  fake_rate = 0.207668;
	if(40 < pt)
	  fake_rate = 0.113459;
      }
    }
  }
  return fake_rate;
}

double AnaScript::FakeRate_RT_UL18(int id, TLorentzVector v1, TLorentzVector v2 , string sample){
  double corr_factor = 1.0;
  double RT = TransverseProjection(v1,v2); 
  double pt = v2.Pt();
  
  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.231405*2/(0.172847+0.201447);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.215385*2/(0.172847+0.201447);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.284823*2/(0.172847+0.201447);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.20858*2/(0.172847+0.201447);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.165882*2/(0.172847+0.201447);  
	if(4.0 < RT)
	  corr_factor = 0.14273*2/(0.172847+0.201447);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.196721*2/(0.126582+0.158491);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.194444*2/(0.126582+0.158491);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.212714*2/(0.126582+0.158491);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.142303*2/(0.126582+0.158491);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.114094*2/(0.126582+0.158491);  
	if(4.0 < RT)
	  corr_factor = 0.103175*2/(0.126582+0.158491);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.153846*2/(0.110057+0.17284);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.192308*2/(0.110057+0.17284);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.180451*2/(0.110057+0.17284);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.133858*2/(0.110057+0.17284);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0882353*2/(0.110057+0.17284);  
	if(4.0 < RT)
	  corr_factor = 0.103175*2/(0.110057+0.17284);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.214286*2/(0.112676+0.0322581);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0434783*2/(0.112676+0.0322581);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0769231*2/(0.112676+0.0322581);  
	if(4.0 < RT)
	  corr_factor = 0.1*2/(0.112676+0.0322581);  
      }
    }

    //SingleMuon
    if(sample == "SingleMuon"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.342054*2/(0.180723+0.233882);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.270184*2/(0.180723+0.233882);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.258774*2/(0.180723+0.233882);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.200339*2/(0.180723+0.233882);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.202412*2/(0.180723+0.233882);  
	if(4.0 < RT)
	  corr_factor = 0.147013*2/(0.180723+0.233882);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.330396*2/(0.122118+0.201249);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.303288*2/(0.122118+0.201249);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.206212*2/(0.122118+0.201249);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.150561*2/(0.122118+0.201249);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.123789*2/(0.122118+0.201249);  
	if(4.0 < RT)
	  corr_factor = 0.09213*2/(0.122118+0.201249);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.186743*2/(0.13027+0.246629);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.351548*2/(0.13027+0.246629);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.28*2/(0.13027+0.246629);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.125321*2/(0.13027+0.246629);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.125658*2/(0.13027+0.246629);  
	if(4.0 < RT)
	  corr_factor = 0.0295348*2/(0.13027+0.246629);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.0;
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.0;
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.154322*2/(0.142533);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0;
	if(4.0 < RT)
	  corr_factor = 0.0653065*2/(0.142533);  
      }
    }
  }

  //Electrons
  if(fabs(id)==11){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.320755*2/(0.1455+0.20382);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.243137*2/(0.1455+0.20382);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.274633*2/(0.1455+0.20382);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.207188*2/(0.1455+0.20382);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.155109*2/(0.1455+0.20382);  
	if(4.0 < RT)
	  corr_factor = 0.117084*2/(0.1455+0.20382);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.261538*2/(0.111882+0.172452);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.21673*2/(0.111882+0.172452);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.215148*2/(0.111882+0.172452);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.138728*2/(0.111882+0.172452);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.101266*2/(0.111882+0.172452);  
	if(4.0 < RT)
	  corr_factor = 0.0839446*2/(0.111882+0.172452);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.305556*2/(0.106864+0.179085);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.247191*2/(0.106864+0.179085);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.222904*2/(0.106864+0.179085);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0957854*2/(0.106864+0.179085);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.0736544*2/(0.106864+0.179085);  
	if(4.0 < RT)
	  corr_factor = 0.0487805*2/(0.106864+0.179085);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.25*2/(0.0642857+0.181818);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.151899*2/(0.0642857+0.181818);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0430108*2/(0.0642857+0.181818);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.08*2/(0.0642857+0.181818);  
	if(4.0 < RT)
	  corr_factor = 0.0;
      }
    }
 
    //EGamma
    if(sample == "EGamma"){
      if(15 > pt){
	if(RT < 0.0)
	  corr_factor = 0.390819*2/(0.174881+0.272429);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.361604*2/(0.174881+0.272429);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.305716*2/(0.174881+0.272429);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.249965*2/(0.174881+0.272429);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.194255*2/(0.174881+0.272429);  
	if(4.0 < RT)
	  corr_factor = 0.155867*2/(0.174881+0.272429);  
      }
      if(15 < pt && pt < 25){
	if(RT < 0.0)
	  corr_factor = 0.294727*2/(0.097214+0.193432);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.237709*2/(0.097214+0.193432);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.219448*2/(0.097214+0.193432);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.137244*2/(0.097214+0.193432);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.1105*2/(0.097214+0.193432);  
	if(4.0 < RT)
	  corr_factor = 0.0877362*2/(0.097214+0.193432);  
      }
      if(25 < pt && pt < 40){
	if(RT < 0.0)
	  corr_factor = 0.147685*2/(0.0844783+0.207668);  
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.266468*2/(0.0844783+0.207668);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.223755*2/(0.0844783+0.207668);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.122759*2/(0.0844783+0.207668);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.074918*2/(0.0844783+0.207668);  
	if(4.0 < RT)
	  corr_factor = 0.090051*2/(0.0844783+0.207668);  
      }
      if(40 < pt){
	if(RT < 0.0)
	  corr_factor = 0.0;
	if(0.0 < RT && RT < 1.0)
	  corr_factor = 0.255972*2/(0.0972829+0.113459);  
	if(1.0 < RT && RT < 2.0)
	  corr_factor = 0.164909*2/(0.0972829+0.113459);  
	if(2.0 < RT && RT < 3.0)
	  corr_factor = 0.0699583*2/(0.0972829+0.113459);  
	if(3.0 < RT && RT < 4.0)
	  corr_factor = 0.008307*2/(0.0972829+0.113459);  
	if(4.0 < RT)
	  corr_factor = 0.0672413*2/(0.0972829+0.113459);  
      }
    }
  }
  return corr_factor;
}

double AnaScript::FakeRateMixed_UL18(int id, TLorentzVector v1, TLorentzVector v2){
  double k_fake    = 0.0;
  double fake_rate = 0.0;
  double pt  = v2.Pt();
  double eta = v2.Eta();
  
  if(fabs(id) == 13){
    double FakeRate_DY   = FakeRate_UL18(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL18(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL18(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL18(id, pt, fabs(eta), "SingleMuon")*FakeRate_RT_UL18(id, v1, v2, "SingleMuon");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  
  if(fabs(id) == 11){
    double FakeRate_DY   = FakeRate_UL18(id, pt, fabs(eta), "DYJetsToLL")*FakeRate_RT_UL18(id, v1, v2, "DYJetsToLL");
    double FakeRate_TT   = FakeRate_UL18(id, pt, fabs(eta), "TTBar");
    double FakeRate_Data = FakeRate_UL18(id, pt, fabs(eta), "EGamma")*FakeRate_RT_UL18(id, v1, v2, "EGamma");
    if(FakeRate_DY != 0){
      k_fake = FakeRate_Data/FakeRate_DY;
      fake_rate = (k_fake)*((0.9*FakeRate_DY)+(0.1*FakeRate_TT));
    }
    else
      fake_rate = FakeRate_Data;
  }
  return fake_rate;
}
