double AnaScript::getScaleFactors_bTagJets_MedWP_Run3Summer22EE(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.9738161207215085;
    if( 30<pt && pt<50)
      scale_factor =  0.9787828870220279;
    if( 50<pt && pt<70)
      scale_factor =  0.9819829334412732;
    if( 70<pt && pt<100)
      scale_factor =  0.9831578571717723;
    if( 100<pt && pt<140)
      scale_factor =  0.9821999134254114;
    if( 140<pt && pt<200)
      scale_factor =  0.9801463744792404;
    if( 200<pt && pt<300)
      scale_factor =  0.9701545773685367;
    if( 300<pt && pt<600)
      scale_factor =  0.9530863327128113;
    if( 600<pt && pt<1000)
      scale_factor =  0.9110367074487933;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
     if( 20<pt && pt<30)
      scale_factor =  0.9738161207215085;
    if( 30<pt && pt<50)
      scale_factor =  0.9787828870220279;
    if( 50<pt && pt<70)
      scale_factor =  0.9819829334412732;
    if( 70<pt && pt<100)
      scale_factor =  0.9831578571717723;
    if( 100<pt && pt<140)
      scale_factor =  0.9821999134254114;
    if( 140<pt && pt<200)
      scale_factor =  0.9801463744792404;
    if( 200<pt && pt<300)
      scale_factor =  0.9701545773685367;
    if( 300<pt && pt<600)
      scale_factor =  0.9530863327128113;
    if( 600<pt && pt<1000)
      scale_factor =  0.9110367074487933;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
     if( 20<pt && pt<30)
      scale_factor =  0.9738161207215085;
    if( 30<pt && pt<50)
      scale_factor =  0.9787828870220279;
    if( 50<pt && pt<70)
      scale_factor =  0.9819829334412732;
    if( 70<pt && pt<100)
      scale_factor =  0.9831578571717723;
    if( 100<pt && pt<140)
      scale_factor =  0.9821999134254114;
    if( 140<pt && pt<200)
      scale_factor =  0.9801463744792404;
    if( 200<pt && pt<300)
      scale_factor =  0.9701545773685367;
    if( 300<pt && pt<600)
      scale_factor =  0.9530863327128113;
    if( 600<pt && pt<1000)
      scale_factor =  0.9110367074487933;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_cTagJets_Mis_Run3Summer22EE(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
     if( 20<pt && pt<30)
      scale_factor =  0.9738161207215085;
    if( 30<pt && pt<50)
      scale_factor =  0.9787828870220279;
    if( 50<pt && pt<70)
      scale_factor =  0.9819829334412732;
    if( 70<pt && pt<100)
      scale_factor =  0.9831578571717723;
    if( 100<pt && pt<140)
      scale_factor =  0.9821999134254114;
    if( 140<pt && pt<200)
      scale_factor =  0.9801463744792404;
    if( 200<pt && pt<300)
      scale_factor =  0.9701545773685367;
    if( 300<pt && pt<600)
      scale_factor =  0.9530863327128113;
    if( 600<pt && pt<1000)
      scale_factor =  0.9110367074487933;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
     if( 20<pt && pt<30)
      scale_factor =  0.9738161207215085;
    if( 30<pt && pt<50)
      scale_factor =  0.9787828870220279;
    if( 50<pt && pt<70)
      scale_factor =  0.9819829334412732;
    if( 70<pt && pt<100)
      scale_factor =  0.9831578571717723;
    if( 100<pt && pt<140)
      scale_factor =  0.9821999134254114;
    if( 140<pt && pt<200)
      scale_factor =  0.9801463744792404;
    if( 200<pt && pt<300)
      scale_factor =  0.9701545773685367;
    if( 300<pt && pt<600)
      scale_factor =  0.9530863327128113;
    if( 600<pt && pt<1000)
      scale_factor =  0.9110367074487933;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
     if( 20<pt && pt<30)
      scale_factor =  0.9738161207215085;
    if( 30<pt && pt<50)
      scale_factor =  0.9787828870220279;
    if( 50<pt && pt<70)
      scale_factor =  0.9819829334412732;
    if( 70<pt && pt<100)
      scale_factor =  0.9831578571717723;
    if( 100<pt && pt<140)
      scale_factor =  0.9821999134254114;
    if( 140<pt && pt<200)
      scale_factor =  0.9801463744792404;
    if( 200<pt && pt<300)
      scale_factor =  0.9701545773685367;
    if( 300<pt && pt<600)
      scale_factor =  0.9530863327128113;
    if( 600<pt && pt<1000)
      scale_factor =  0.9110367074487933;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_LightTagJets_Mis_Run3Summer22EE(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  1.2571695888562964;
    if( 30<pt && pt<50)
      scale_factor =  1.3991514670755234;
    if( 50<pt && pt<70)
      scale_factor =  1.4651483099097105;
    if( 70<pt && pt<100)
      scale_factor =  1.489719281195922;
    if( 100<pt && pt<140)
      scale_factor =  1.4891221769442768;
    if( 140<pt && pt<200)
      scale_factor =  1.4765514358164966;
    if( 200<pt && pt<300)
      scale_factor =  1.414340616579701;
    if( 300<pt && pt<600)
      scale_factor =  1.3250451827160687;
    if( 600<pt && pt<1000)
      scale_factor =  1.238560426579833;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  1.2571695888562964;
    if( 30<pt && pt<50)
      scale_factor =  1.3991514670755234;
    if( 50<pt && pt<70)
      scale_factor =  1.4651483099097105;
    if( 70<pt && pt<100)
      scale_factor =  1.489719281195922;
    if( 100<pt && pt<140)
      scale_factor =  1.4891221769442768;
    if( 140<pt && pt<200)
      scale_factor =  1.4765514358164966;
    if( 200<pt && pt<300)
      scale_factor =  1.414340616579701;
    if( 300<pt && pt<600)
      scale_factor =  1.3250451827160687;
    if( 600<pt && pt<1000)
      scale_factor =  1.238560426579833;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  1.2571695888562964;
    if( 30<pt && pt<50)
      scale_factor =  1.3991514670755234;
    if( 50<pt && pt<70)
      scale_factor =  1.4651483099097105;
    if( 70<pt && pt<100)
      scale_factor =  1.489719281195922;
    if( 100<pt && pt<140)
      scale_factor =  1.4891221769442768;
    if( 140<pt && pt<200)
      scale_factor =  1.4765514358164966;
    if( 200<pt && pt<300)
      scale_factor =  1.414340616579701;
    if( 300<pt && pt<600)
      scale_factor =  1.3250451827160687;
    if( 600<pt && pt<1000)
      scale_factor =  1.238560426579833;
  }
  return scale_factor;
}
