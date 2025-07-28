double AnaScript::PromptRate_Run3Summer22EE(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.81014;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.915826;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.961226;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.972446;
	if(100 < pt)
	  prompt_rate = 0.978883;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.856896;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.94159;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.976082;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.979068;
	if(100 < pt)
	  prompt_rate = 0.981424;
      }
    }
    
    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.781976;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.882013;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.920311;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.944431;
	if(100 < pt)
	  prompt_rate = 0.95275;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.833636;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.918816;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.944827;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.960716;
	if(100 < pt)
	  prompt_rate = 0.966147;
      }
    }

    //Data: SingleMuon
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.719476;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.840534;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.907608;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.958651;
	if(100 < pt)
	  prompt_rate = 0.978517;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.893821;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.954334;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.980993;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.983148;
	if(100 < pt)
	  prompt_rate = 0.988769;
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
	  prompt_rate = 0.868984;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.935448;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.964396;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.975584;
	if(100 < pt)
	  prompt_rate = 0.982934;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.852538;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.91833;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.951521;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.967871;
	if(100 < pt)
	  prompt_rate = 0.974694;
      }
    }
    
    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.864864;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.919022;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.942212;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.960646;
	if(100 < pt)
	  prompt_rate = 0.969937;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.845921;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.905663;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.932672;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.951749;
	if(100 < pt)
	  prompt_rate = 0.96296;
      }
    }

    //Data: EGamma
    if(sample == "EGamma"){
    //Barrel Region
    if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.804858;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.892364;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.929665;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.96158;
	if(100 < pt)
	  prompt_rate = 0.979712;
      }
      //Endcap Region                                                                                                 
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.875873;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.93607;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.965769;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.971854;
	if(100 < pt)
	  prompt_rate = 0.984279;
      }
    }
  }
  return prompt_rate;
}

double AnaScript::PromptRateMixed_Run3Summer22EE(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_Run3Summer22EE(id, pt, fabs(eta), "SingleMuon")/PromptRate_Run3Summer22EE(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer22EE(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer22EE(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_Run3Summer22EE(id, pt, fabs(eta), "EGamma")/PromptRate_Run3Summer22EE(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer22EE(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer22EE(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}

double AnaScript::PromptRate_Run3Summer22(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;

  //Muons
  if(fabs(id)==13){
    //DYJetsToLL
    if(sample == "DYJetsToLL"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.824501;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.924215;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.966255;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.974092;
	if(100 < pt)
	  prompt_rate = 0.980744;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.857222;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.94181;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.976241;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.978405;
	if(100 < pt)
	  prompt_rate = 0.979781;
      }
    }
    
    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.797687;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.891411;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.925432;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.947294;
	if(100 < pt)
	  prompt_rate = 0.953025;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.834871;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.917208;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.945634;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.958166;
	if(100 < pt)
	  prompt_rate = 0.965699;
      }
    }

    //Data: SingleMuon
    if(sample == "SingleMuon"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.843462;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.924893;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.964724;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.974385;
	if(100 < pt)
	  prompt_rate = 0.978346;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.872783;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.945737;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.976399;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.979586;
	if(100 < pt)
	  prompt_rate = 0.989011;
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
	  prompt_rate = 0.875241;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.939727;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.967251;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.976452;
	if(100 < pt)
	  prompt_rate = 0.98435;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.851991;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.917751;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.951419;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.967713;
	if(100 < pt)
	  prompt_rate = 0.974936;
      }
    }
    
    //TTBar
    if(sample == "TTBar"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.870202;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.922086;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.945395;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.962673;
	if(100 < pt)
	  prompt_rate = 0.969924;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.845897;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.903608;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.930947;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.952383;
	if(100 < pt)
	  prompt_rate = 0.963111;
      }
    }

    //Data: EGamma
    if(sample == "EGamma"){
      //Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.865397;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.93472;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.962402;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.975763;
	if(100 < pt)
	  prompt_rate = 0.986659;
      }
      //Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.843849;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.914291;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.948879;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.965284;
	if(100 < pt)
	  prompt_rate = 0.978474;
      }
    }
  }
  return prompt_rate;
}

double AnaScript::PromptRateMixed_Run3Summer22(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_Run3Summer22(id, pt, fabs(eta), "SingleMuon")/PromptRate_Run3Summer22(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer22(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer22(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_Run3Summer22(id, pt, fabs(eta), "EGamma")/PromptRate_Run3Summer22(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer22(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer22(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}

