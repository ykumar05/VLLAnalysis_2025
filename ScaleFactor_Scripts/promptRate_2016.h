double AnaScript::PromptRate_UL16preVFP(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;

  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.811891;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.91901;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.96521;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.972533;
	if(100 < pt)
	  prompt_rate = 0.97768;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.8349;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.932324;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.972941;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.979416;
	if(100 < pt)
	  prompt_rate = 0.979961;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.778506;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.878913;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.915897;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.938888;
	if(100 < pt)
	  prompt_rate = 0.941939;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.806908;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.904174;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.935393;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.95324;
	if(100 < pt)
	  prompt_rate = 0.957435;
      }
    }

    // Data: SingleMuon
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.846213;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.928334;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.96885;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.97613;
	if(100 < pt)
	  prompt_rate = 0.980873;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.873872;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.947825;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.979469;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.982035;
	if(100 < pt)
	  prompt_rate = 0.985465;
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
	  prompt_rate = 0.807919;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.880047;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.920729;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.942413;
	if(100 < pt)
	  prompt_rate = 0.957792;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.869053;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.920393;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.950472;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.969019;
	if(100 < pt)
	  prompt_rate = 0.975263;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.795142;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.850997;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.880987;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.910316;
	if(100 < pt)
	  prompt_rate = 0.925032;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.85992;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.903612;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.928006;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.948715;
	if(100 < pt)
	  prompt_rate = 0.957291;
      }
    }

    // Data: EGamma
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.822303;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.891365;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.926559;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.946747;
	if(100 < pt)
	  prompt_rate = 0.965004;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.887284;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.93813;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.962968;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.974773;
	if(100 < pt)
	  prompt_rate = 0.984326;
      }
    }
  }
  
  return prompt_rate;
}

double AnaScript::PromptRateMixed_UL16preVFP(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_UL16preVFP(id, pt, fabs(eta), "SingleMuon")/PromptRate_UL16preVFP(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL16preVFP(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL16preVFP(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_UL16preVFP(id, pt, fabs(eta), "EGamma")/PromptRate_UL16preVFP(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL16preVFP(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL16preVFP(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}

double AnaScript::PromptRate_UL16postVFP(int id, float pt, float eta, string sample){
  float prompt_rate = 1.0;
  
  // Muons
  if(fabs(id)==13){
    // DYJetsToLL
    if(sample == "DYJetsToLL"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.815033;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.921362;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.966528;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.971656;
	if(100 < pt)
	  prompt_rate = 0.977198;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.845953;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.937794;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.975587;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.978699;
	if(100 < pt)
	  prompt_rate = 0.977348;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.782721;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.881128;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.917932;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.940178;
	if(100 < pt)
	  prompt_rate = 0.947758;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.818891;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.908784;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.938619;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.955457;
	if(100 < pt)
	  prompt_rate = 0.958907;
      }
    }

    // Data: SingleMuon
    if(sample == "SingleMuon"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.849423;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.930397;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.969813;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.977453;
	if(100 < pt)
	  prompt_rate = 0.982452;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.884499;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.952955;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.981916;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.983972;
	if(100 < pt)
	  prompt_rate = 0.984686;
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
	  prompt_rate = 0.807827;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.879556;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.921228;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.941159;
	if(100 < pt)
	  prompt_rate = 0.965240;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.873462;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.924083;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.953899;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.971269;
	if(100 < pt)
	  prompt_rate = 0.977582;
      }
    }

    // TTBar
    if(sample == "TTBar"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.795687;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.849863;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.883672;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.911203;
	if(100 < pt)
	  prompt_rate = 0.929654;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.863741;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.907902;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.930914;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.949690;
	if(100 < pt)
	  prompt_rate = 0.961266;
      }
    }

    // Data: EGamma
    if(sample == "EGamma"){
      // Barrel Region
      if(fabs(eta)<=1.479){
	if(30 > pt)
	  prompt_rate = 0.823122;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.893767;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.928412;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.947545;
	if(100 < pt)
	  prompt_rate = 0.966070;
      }
      // Endcap Region
      if(fabs(eta)>1.479){
	if(30 > pt)
	  prompt_rate = 0.891665;
	if(30 < pt && pt < 40)
	  prompt_rate = 0.941210;
	if(40 < pt && pt < 60)
	  prompt_rate = 0.965492;
	if(60 < pt && pt < 100)
	  prompt_rate = 0.973602;
	if(100 < pt)
	  prompt_rate = 0.986520;
      }
    }
  }
  
  return prompt_rate;
}

double AnaScript::PromptRateMixed_UL16postVFP(int id, float pt, float eta){
  float k_prompt    = 1.0;
  float prompt_rate = 1.0;

  if(fabs(id) == 13){
    k_prompt = PromptRate_UL16postVFP(id, pt, fabs(eta), "SingleMuon")/PromptRate_UL16postVFP(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL16postVFP(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL16postVFP(id, pt, fabs(eta), "TTBar")));
  }
  if(fabs(id) == 11){
    k_prompt = PromptRate_UL16postVFP(id, pt, fabs(eta), "EGamma")/PromptRate_UL16postVFP(id, pt, fabs(eta), "DYJetsToLL");
    prompt_rate = (k_prompt)*((0.9*PromptRate_UL16postVFP(id, pt, fabs(eta), "DYJetsToLL"))+(0.1*PromptRate_UL16postVFP(id, pt, fabs(eta), "TTBar")));
  }
  return prompt_rate;
}
