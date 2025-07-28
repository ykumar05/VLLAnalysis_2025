double AnaScript::PromptRate_UL17(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.805914;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.916702;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.96305;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.972668;
	if(100 < pt)
	  prompt_rate = 0.97893;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.840156;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.935922;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.973632;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.979703;
	if(100 < pt)
	  prompt_rate = 0.983886;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.778612;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.880469;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.918968;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.942196;
	if(100 < pt)
	  prompt_rate = 0.950457;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.818112;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.910801;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.940659;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.956941;
	if(100 < pt)
	  prompt_rate = 0.963083;
      }
    }

    //Data: SingleMuon
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.836453;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.925101;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.965341;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.975266;
	if(100 < pt)
	  prompt_rate = 0.980311;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.881897;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.951898;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.980318;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.98441;
	if(100 < pt)
	  prompt_rate = 0.979988;
      }
    }
  }

  //Electrons
  if(fabs(id)==11){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.806027;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.882114;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.921825;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.943753;
	if(100 < pt)
	  prompt_rate = 0.96269;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.861726;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.919778;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.950439;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.967016;
	if(100 < pt)
	  prompt_rate = 0.975014;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.800774;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.858289;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.888749;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.915986;
	if(100 < pt)
	  prompt_rate = 0.935216;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.857214;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.906203;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.930626;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.951589;
	if(100 < pt)
	  prompt_rate = 0.963318;
      }
    }

    //Data: EGamma
    if(sample == "EGamma"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.811145;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.887442;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.924212;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.945978;
	if(100 < pt)
	  prompt_rate = 0.966449;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.882129;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.936284;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.962139;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.973746;
	if(100 < pt)
	  prompt_rate = 0.977567;
      }
    }
  }
 
  return prompt_rate;
}

double AnaScript::PromptRateMixed_UL17(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_UL17(id, pt, fabs(eta), "SingleMuon")/PromptRate_UL17(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL17(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL17(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_UL17(id, pt, fabs(eta), "EGamma")/PromptRate_UL17(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL17(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL17(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}
