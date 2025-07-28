double AnaScript::PromptRate_UL18(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.813384;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.918521;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.964014;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.972993;
	if(100 < pt)
	  prompt_rate = 0.978018;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.844639;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.934903;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.972477;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.978569;
	if(100 < pt)
	  prompt_rate = 0.978632;
      }
    }
  
    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.78124;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.881665;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.920835;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.944235;
	if(100 < pt)
	  prompt_rate = 0.950998;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.816179;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.909361;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.940552;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.956764;
	if(100 < pt)
	  prompt_rate = 0.961128;
      }
    }

    //Data: SingleMuon
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.835953;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.920663;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.962653;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.97521;
	if(100 < pt)
	  prompt_rate = 0.979661;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.876414;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.947071;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.97718;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.981163;
	if(100 < pt)
	  prompt_rate = 0.984858;
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
	  prompt_rate = 0.812141;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.883157;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.921646;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.944779;
	if(100 < pt)
	  prompt_rate = 0.96308;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.876408;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.929068;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.957497;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.971471;
	if(100 < pt)
	  prompt_rate = 0.979348;
      }
    }

    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.803634;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.858641;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.890471;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.917887;
	if(100 < pt)
	  prompt_rate = 0.93424;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.868868;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.915276;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.937322;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.956185;
	if(100 < pt)
	  prompt_rate = 0.964373;
      }
    }

    //Data: EGamma
    if(sample == "EGamma"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.8095;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.882187;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.918572;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.943619;
	if(100 < pt)
	  prompt_rate = 0.963905;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.884081;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.936772;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.962778;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.9733;
	if(100 < pt)
	  prompt_rate = 0.984204;
      }
    }
  }
  
  return prompt_rate;
}

double AnaScript::PromptRateMixed_UL18(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_UL18(id, pt, fabs(eta), "SingleMuon")/PromptRate_UL18(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL18(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL18(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_UL18(id, pt, fabs(eta), "EGamma")/PromptRate_UL18(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL18(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL18(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}
