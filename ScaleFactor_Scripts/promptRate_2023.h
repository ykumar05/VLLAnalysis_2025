double AnaScript::PromptRate_Run3Summer23(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;

  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 30)
	  prompt_rate = 0.824834;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.924949;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.966101;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.974312;
	if(pt > 100)
	  prompt_rate = 0.98103;
      }
      // Endcap Region
      else{
	if(pt < 30)
	  prompt_rate = 0.851711;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.937684;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.97293;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.979333;
	if(pt > 100)
	  prompt_rate = 0.978655;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 30)
	  prompt_rate = 0.799191;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.892854;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.927134;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.94815;
	if(pt > 100)
	  prompt_rate = 0.955336;
      }
      // Endcap Region
      else{
	if(pt < 30)
	  prompt_rate = 0.825924;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.912947;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.941962;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.959307;
	if(pt > 100)
	  prompt_rate = 0.964518;
      }
    }

    // Data: SingleMuon
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 30)
	  prompt_rate = 0.874924;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.943301;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.975266;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.979215;
	if(pt > 100)
	  prompt_rate = 0.98135;
      }
      // Endcap Region
      else{
	if(pt < 30)
	  prompt_rate = 0.899279;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.957657;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.98229;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.982088;
	if(pt > 100)
	  prompt_rate = 0.987968;
      }
    }
  }

  // Electrons
  if(fabs(id)==11){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 30)
	  prompt_rate = 0.871762;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.937145;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.964881;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.976546;
	if(pt > 100)
	  prompt_rate = 0.984396;
      }
      // Endcap Region
      else{
	if(pt < 30)
	  prompt_rate = 0.843592;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.909579;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.944866;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.96303;
	if(pt > 100)
	  prompt_rate = 0.968555;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 30)
	  prompt_rate = 0.867185;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.921618;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.945252;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.964289;
	if(pt > 100)
	  prompt_rate = 0.974392;
      }
      // Endcap Region
      else{
	if(pt < 30)
	  prompt_rate = 0.837923;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.897944;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.926278;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.948299;
	if(pt > 100)
	  prompt_rate = 0.965588;
      }
    }

    // Data: EGamma
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(pt < 30)
	  prompt_rate = 0.883886;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.948346;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.971548;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.981047;
	if(pt > 100)
	  prompt_rate = 0.987932;
      }
      // Endcap Region
      else{
	if(pt < 30)
	  prompt_rate = 0.871023;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.934533;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.962568;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.975394;
	if(pt > 100)
	  prompt_rate = 0.987879;
      }
    }
  }
  
  return prompt_rate;
}

double AnaScript::PromptRateMixed_Run3Summer23(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_Run3Summer23(id, pt, fabs(eta), "SingleMuon")/PromptRate_Run3Summer23(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer23(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer23(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_Run3Summer23(id, pt, fabs(eta), "EGamma")/PromptRate_Run3Summer23(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer23(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer23(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}

double AnaScript::PromptRate_Run3Summer23BPix(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;

  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.823608;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.92396;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.96551;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.974952;
	if(100 < pt)
	  prompt_rate = 0.980347;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.851126;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.937295;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.97287;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.978343;
	if(100 < pt)
	  prompt_rate = 0.986753;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.798971;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.891384;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.926933;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.948511;
	if(100 < pt)
	  prompt_rate = 0.955973;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.827672;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.912234;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.942026;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.958045;
	if(100 < pt)
	  prompt_rate = 0.966067;
      }
    }

    // Data: SingleMuon
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.881246;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.947813;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.977932;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.980081;
	if(100 < pt)
	  prompt_rate = 0.985093;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.898647;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.956893;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.981964;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.982203;
	if(100 < pt)
	  prompt_rate = 0.98063;
      }
    }
  }

  // Electrons
  if(fabs(id)==11){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.871365;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.937006;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.964603;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.97744;
	if(100 < pt)
	  prompt_rate = 0.987235;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.842986;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.908751;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.943893;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.966001;
	if(100 < pt)
	  prompt_rate = 0.980729;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.866659;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.921326;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.944659;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.963162;
	if(100 < pt)
	  prompt_rate = 0.972121;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.836458;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.89601;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.926224;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.949386;
	if(100 < pt)
	  prompt_rate = 0.961834;
      }
    }

    // Data: EGamma
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.890342;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.952902;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.97508;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.980714;
	if(100 < pt)
	  prompt_rate = 0.988854;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.869122;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.933724;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.962429;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.977099;
	if(100 < pt)
	  prompt_rate = 0.987421;
      }
    }
  }
 
  return prompt_rate;
}

double AnaScript::PromptRateMixed_Run3Summer23BPix(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "SingleMuon")/PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "EGamma")/PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_Run3Summer23BPix(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}
