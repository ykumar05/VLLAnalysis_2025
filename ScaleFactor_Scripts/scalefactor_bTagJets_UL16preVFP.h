double AnaScript::getScaleFactors_bTagJets_MedWP_UL16preVFP(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.9973199796684669;
    if( 30<pt && pt<50)
      scale_factor =  0.9960854563465826;
    if( 50<pt && pt<70)
      scale_factor =  0.9944348404862913;
    if( 70<pt && pt<100)
      scale_factor =  0.9923641670362914;
    if( 100<pt && pt<140)
      scale_factor =  0.989451315699134;
    if( 140<pt && pt<200)
      scale_factor =  0.9869415777702947;
    if( 200<pt && pt<300)
      scale_factor =  0.9784879070520077;
    if( 300<pt && pt<600)
      scale_factor =  0.9655481022208018;
    if( 600<pt && pt<1000)
      scale_factor =  0.92943712325938;    
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.9973199796684669;
    if( 30<pt && pt<50)
      scale_factor =  0.9960854563465826;
    if( 50<pt && pt<70)
      scale_factor =  0.9944348404862913;
    if( 70<pt && pt<100)
      scale_factor =  0.9923641670362914;
    if( 100<pt && pt<140)
      scale_factor =  0.989451315699134;
    if( 140<pt && pt<200)
      scale_factor =  0.9869415777702947;
    if( 200<pt && pt<300)
      scale_factor =  0.9784879070520077;
    if( 300<pt && pt<600)
      scale_factor =  0.9655481022208018;
    if( 600<pt && pt<1000)
      scale_factor =  0.92943712325938;    
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.9973199796684669;
    if( 30<pt && pt<50)
      scale_factor =  0.9960854563465826;
    if( 50<pt && pt<70)
      scale_factor =  0.9944348404862913;
    if( 70<pt && pt<100)
      scale_factor =  0.9923641670362914;
    if( 100<pt && pt<140)
      scale_factor =  0.989451315699134;
    if( 140<pt && pt<200)
      scale_factor =  0.9869415777702947;
    if( 200<pt && pt<300)
      scale_factor =  0.9784879070520077;
    if( 300<pt && pt<600)
      scale_factor =  0.9655481022208018;
    if( 600<pt && pt<1000)
      scale_factor =  0.92943712325938;    
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_cTagJets_Mis_UL16preVFP(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.9973199796684669;
    if( 30<pt && pt<50)
      scale_factor =  0.9960854563465826;
    if( 50<pt && pt<70)
      scale_factor =  0.9944348404862913;
    if( 70<pt && pt<100)
      scale_factor =  0.9923641670362914;
    if( 100<pt && pt<140)
      scale_factor =  0.989451315699134;
    if( 140<pt && pt<200)
      scale_factor =  0.9869415777702947;
    if( 200<pt && pt<300)
      scale_factor =  0.9784879070520077;
    if( 300<pt && pt<600)
      scale_factor =  0.9655481022208018;
    if( 600<pt && pt<1000)
      scale_factor =  0.92943712325938;    
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.9973199796684669;
    if( 30<pt && pt<50)
      scale_factor =  0.9960854563465826;
    if( 50<pt && pt<70)
      scale_factor =  0.9944348404862913;
    if( 70<pt && pt<100)
      scale_factor =  0.9923641670362914;
    if( 100<pt && pt<140)
      scale_factor =  0.989451315699134;
    if( 140<pt && pt<200)
      scale_factor =  0.9869415777702947;
    if( 200<pt && pt<300)
      scale_factor =  0.9784879070520077;
    if( 300<pt && pt<600)
      scale_factor =  0.9655481022208018;
    if( 600<pt && pt<1000)
      scale_factor =  0.92943712325938;    
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.9973199796684669;
    if( 30<pt && pt<50)
      scale_factor =  0.9960854563465826;
    if( 50<pt && pt<70)
      scale_factor =  0.9944348404862913;
    if( 70<pt && pt<100)
      scale_factor =  0.9923641670362914;
    if( 100<pt && pt<140)
      scale_factor =  0.989451315699134;
    if( 140<pt && pt<200)
      scale_factor =  0.9869415777702947;
    if( 200<pt && pt<300)
      scale_factor =  0.9784879070520077;
    if( 300<pt && pt<600)
      scale_factor =  0.9655481022208018;
    if( 600<pt && pt<1000)
      scale_factor =  0.92943712325938;    
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_LightTagJets_Mis_UL16preVFP(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  1.4415005474437501;
    if( 30<pt && pt<50)
      scale_factor =  1.4084120494560002;
    if( 50<pt && pt<70)
      scale_factor =  1.3927668012760002;
    if( 70<pt && pt<100)
      scale_factor =  1.386676428214456;
    if( 100<pt && pt<140)
      scale_factor =  1.386541965104;
    if( 140<pt && pt<200)
      scale_factor =  1.3895547079750001;
    if( 200<pt && pt<300)
      scale_factor =  1.406767584375;
    if( 300<pt && pt<600)
      scale_factor =  1.4390376456;
    if( 600<pt && pt<1000)
      scale_factor =  1.5338593324000003;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  1.4415005474437501;
    if( 30<pt && pt<50)
      scale_factor =  1.4084120494560002;
    if( 50<pt && pt<70)
      scale_factor =  1.3927668012760002;
    if( 70<pt && pt<100)
      scale_factor =  1.386676428214456;
    if( 100<pt && pt<140)
      scale_factor =  1.386541965104;
    if( 140<pt && pt<200)
      scale_factor =  1.3895547079750001;
    if( 200<pt && pt<300)
      scale_factor =  1.406767584375;
    if( 300<pt && pt<600)
      scale_factor =  1.4390376456;
    if( 600<pt && pt<1000)
      scale_factor =  1.5338593324000003;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  1.4415005474437501;
    if( 30<pt && pt<50)
      scale_factor =  1.4084120494560002;
    if( 50<pt && pt<70)
      scale_factor =  1.3927668012760002;
    if( 70<pt && pt<100)
      scale_factor =  1.386676428214456;
    if( 100<pt && pt<140)
      scale_factor =  1.386541965104;
    if( 140<pt && pt<200)
      scale_factor =  1.3895547079750001;
    if( 200<pt && pt<300)
      scale_factor =  1.406767584375;
    if( 300<pt && pt<600)
      scale_factor =  1.4390376456;
    if( 600<pt && pt<1000)
      scale_factor =  1.5338593324000003;
  }
  return scale_factor;
}
