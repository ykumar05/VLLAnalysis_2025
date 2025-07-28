//.........................................................//
//                                                         //
//        Trigger Efficiency scale factor                  //
//                                                         //
//.........................................................//

/******************************************************************************
 *                                  2023BPix                                  *
 ******************************************************************************/
float AnaScript::TriggEff2023BPixData(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){//HLT_IsoMu24
      eff = 0.5*0.949014*(1.0+TMath::Erf((pt-24.9446)/(2.0*0.0456965)));	 
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.955304*(1.0+TMath::Erf((pt-25.1877)/(2.0*0.0328055)));
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){//HLT_Ele32_WPTight_Gsf
      eff = 0.5*0.97538*(1.0+TMath::Erf((pt-33.2668)/(2.0*1.39703)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.970987*(1.0+TMath::Erf((pt-32.7315)/(2.0*1.64687)));
    }
  }
  return eff;
}

/*********************************************************************************
 *                                  2023                                       *
 *********************************************************************************/
float AnaScript::TriggEff2023Data(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){//HLT_IsoMu24
      eff = 0.5*0.952283*(1.0+TMath::Erf((pt-25.3956)/(2.0*0.167536)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.955237*(1.0+TMath::Erf((pt-24.1104)/(2.0*0.0992034)));
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){//HLT_Ele32_WPTight_Gsf
      eff = 0.5*0.974765*(1.0+TMath::Erf((pt-33.0725)/(2.0*1.43905)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.975377*(1.0+TMath::Erf((pt-32.6495)/(2.0*1.69333)));
    }
  }
  return eff;
}

/*********************************************************************************
 *                                  2022EE                                       *
 *********************************************************************************/
float AnaScript::TriggEff2022EEData(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){//HLT_IsoMu24
      eff = 0.5*0.950136*(1.0+TMath::Erf((pt-24.2686)/(2.0*0.00194796)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.940207*(1.0+TMath::Erf((pt-23.8785)/(2.0*0.378177)));
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){//HLT_Ele32_WPTight_Gsf
      eff = 0.5*0.979149*(1.0+TMath::Erf((pt-33.3691)/(2.0*1.28607)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.975062*(1.0+TMath::Erf((pt-32.9815)/(2.0*1.47289)));
    }
  }
  return eff;
}

/*********************************************************************************
 *                                    2022                                       *
 *********************************************************************************/
float AnaScript::TriggEff2022Data(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){//HLT_IsoMu24
      eff = 0.5*0.955504*(1.0+TMath::Erf((pt-24.7165)/(2.0*0.371029)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.931413*(1.0+TMath::Erf((pt-23.4266)/(2.0*0.200128)));
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){//HLT_Ele32_WPTight_Gsf
      eff = 0.5*0.976349*(1.0+TMath::Erf((pt-31.1233)/(2.0*1.68838)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.971387*(1.0+TMath::Erf((pt-29.2013)/(2.0*2.10407)));
    }
  }
  return eff;
}

/*********************************************************************************
 *                                    2018                                       *
 *********************************************************************************/
float AnaScript::TriggEff2018MC(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu24
    if(fabs(eta)<=1.479){
      eff = 0.5*0.971878*(1.0+TMath::Erf((pt-23.9589)/(2.0*0.356627)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.958908*(1.0+TMath::Erf((pt-23.9493)/(2.0*0.408312)));
    }
  }
  if(fabs(id)==11){//HLT_Ele32_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.971841*(1.0+TMath::Erf((pt-33.0664)/(2.0*0.830281)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.981582*(1.0+TMath::Erf((pt-33.9066)/(2.0*1.55882)));
    }
  }
  return eff;
}

float AnaScript::TriggEff2018Data(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){//HLT_IsoMu24
      eff = 0.5*0.950463*(1.0+TMath::Erf((pt-23.9593)/(2.0*0.375996)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.953162*(1.0+TMath::Erf((pt-23.9459)/(2.0*0.457351)));
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){//HLT_Ele32_WPTight_Gsf
      eff = 0.5*0.962897*(1.0+TMath::Erf((pt-33.1188)/(2.0*0.844886)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.975043*(1.0+TMath::Erf((pt-32.9805)/(2.0*1.18094)));
    }
  }
  return eff;
}

/*********************************************************************************
 *                                    2017                                       *
 *********************************************************************************/
float AnaScript::TriggEff2017MC(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu27
    if(fabs(eta)<=1.479){
      eff = 0.5*0.960212*(1.0+TMath::Erf((pt-26.9652)/(2.0*0.597564)));
    }
    else if(fabs(eta)>1.479 && fabs(eta)<=2.4){
      eff = 0.5*0.94303*(1.0+TMath::Erf((pt-26.9123)/(2.0*0.747516)));
    }
  }
  if(fabs(id)==11){//HLT_Ele32_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.96683*(1.0+TMath::Erf((pt-31.6521)/(2.0*1.16952)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.977357*(1.0+TMath::Erf((pt-32.7302)/(2.0*1.98741)));
    }
  }
  return eff;
}

float AnaScript::TriggEff2017Data(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu27
    if(fabs(eta)<=1.479){
      if(pt<=100)
	eff = 0.5*0.929318*(1.0+TMath::Erf((pt-26.9424)/(2.0*0.612448)));
      else
	eff = 0.958305;
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.94163*(1.0+TMath::Erf((pt-26.9092)/(2.0*0.844543)));
    }
  }
  if(fabs(id)==11){//HLT_Ele32_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.955945*(1.0+TMath::Erf((pt-33.0345)/(2.0*0.885676)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.962208*(1.0+TMath::Erf((pt-33.9927)/(2.0*1.55814)));
    }
  }
  return eff;
}

/*****************************************************************************
 *                              2016preVFP                                   *
 *****************************************************************************/
float AnaScript::TriggEff2016preVFPMC(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu24
    if(fabs(eta)<=1.479){
      eff = 0.5*0.971934*(1.0+TMath::Erf((pt-23.4424)/(2.0*0.178376)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.966306*(1.0+TMath::Erf((pt-23.9592)/(2.0*0.487943)));
    }
  }
  if(fabs(id)==11){//HLT_Ele27_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.984513*(1.0+TMath::Erf((pt-27.5914)/(2.0*1.0585)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.989446*(1.0+TMath::Erf((pt-26.0586)/(2.0*1.85888)));
    }
  }
  return eff;
}

float AnaScript::TriggEff2016preVFPData(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){
      eff = 0.5*0.952501*(1.0+TMath::Erf((pt-23.9491)/(2.0*0.405232)));
    }
    else if(fabs(eta)>1.479){
      if(pt<=100)
	eff = 0.5*0.951936*(1.0+TMath::Erf((pt-23.9399)/(2.0*0.533316)));
      else
	eff = 0.774;
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){
      eff = 0.5*0.980431*(1.0+TMath::Erf((pt-26.6311)/(2.0*0.977291)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.984774*(1.0+TMath::Erf((pt-27.5187)/(2.0*1.33533)));
    }
  }
  return eff;
}

/*********************************************************************************
 *                             2016postVFP                                       *
 *********************************************************************************/
float AnaScript::TriggEff2016postVFPMC(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){//HLT_IsoMu24
    if(fabs(eta)<=1.479){
      eff = 0.5*0.974532*(1.0+TMath::Erf((pt-23.3954)/(2.0*0.151737)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.970343*(1.0+TMath::Erf((pt-23.977)/(2.0*0.445236)));
    }
  }
  if(fabs(id)==11){//HLT_Ele27_WPTight_Gsf
    if(fabs(eta)<=1.479){
      eff = 0.5*0.983934*(1.0+TMath::Erf((pt-27.5947)/(2.0*1.06344)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.988555*(1.0+TMath::Erf((pt-26.0556)/(2.0*1.85987)));
    }
  }
  return eff;
}

float AnaScript::TriggEff2016postVFPData(int id, float pt, float eta){
  if( pt<10 || eta>2.4 ) return 0.0;
  float eff = 0.0;
  if(fabs(id)==13){
    if(fabs(eta)<=1.479){
      eff = 0.5*0.963135*(1.0+TMath::Erf((pt-23.9546)/(2.0*0.363316)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.96043*(1.0+TMath::Erf((pt-23.9677)/(2.0*0.463984)));
    }
  }
  if(fabs(id)==11){
    if(fabs(eta)<=1.479){
      eff = 0.5*0.975241*(1.0+TMath::Erf((pt-26.6834)/(2.0*1.08336)));
    }
    else if(fabs(eta)>1.479){
      eff = 0.5*0.981091*(1.0+TMath::Erf((pt-27.7339)/(2.0*1.44615)));
    }
  }
  return eff;
}
