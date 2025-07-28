double AnaScript::getScaleFactors_bTagJets_MedWP_Run3Summer23BPix(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  1.0006659209160667;
    if( 30<pt && pt<50)
      scale_factor =  0.9775096148135214;
    if( 50<pt && pt<70)
      scale_factor =  0.966644508506586;
    if( 70<pt && pt<100)
      scale_factor =  0.9640500820316281;
    if( 100<pt && pt<140)
      scale_factor =  0.9676168211605776;
    if( 140<pt && pt<200)
      scale_factor =  0.9731780682102414;
    if( 200<pt && pt<300)
      scale_factor =  0.9955327946316231;
    if( 300<pt && pt<600)
      scale_factor =  1.027933939332208;
    if( 600<pt && pt<1000)
      scale_factor =  1.0964127641955193;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  1.0006659209160667;
    if( 30<pt && pt<50)
      scale_factor =  0.9775096148135214;
    if( 50<pt && pt<70)
      scale_factor =  0.966644508506586;
    if( 70<pt && pt<100)
      scale_factor =  0.9640500820316281;
    if( 100<pt && pt<140)
      scale_factor =  0.9676168211605776;
    if( 140<pt && pt<200)
      scale_factor =  0.9731780682102414;
    if( 200<pt && pt<300)
      scale_factor =  0.9955327946316231;
    if( 300<pt && pt<600)
      scale_factor =  1.027933939332208;
    if( 600<pt && pt<1000)
      scale_factor =  1.0964127641955193;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  1.0006659209160667;
    if( 30<pt && pt<50)
      scale_factor =  0.9775096148135214;
    if( 50<pt && pt<70)
      scale_factor =  0.966644508506586;
    if( 70<pt && pt<100)
      scale_factor =  0.9640500820316281;
    if( 100<pt && pt<140)
      scale_factor =  0.9676168211605776;
    if( 140<pt && pt<200)
      scale_factor =  0.9731780682102414;
    if( 200<pt && pt<300)
      scale_factor =  0.9955327946316231;
    if( 300<pt && pt<600)
      scale_factor =  1.027933939332208;
    if( 600<pt && pt<1000)
      scale_factor =  1.0964127641955193;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_cTagJets_Mis_Run3Summer23BPix(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  1.0006659209160667;
    if( 30<pt && pt<50)
      scale_factor =  0.9775096148135214;
    if( 50<pt && pt<70)
      scale_factor =  0.966644508506586;
    if( 70<pt && pt<100)
      scale_factor =  0.9640500820316281;
    if( 100<pt && pt<140)
      scale_factor =  0.9676168211605776;
    if( 140<pt && pt<200)
      scale_factor =  0.9731780682102414;
    if( 200<pt && pt<300)
      scale_factor =  0.9955327946316231;
    if( 300<pt && pt<600)
      scale_factor =  1.027933939332208;
    if( 600<pt && pt<1000)
      scale_factor =  1.0964127641955193;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  1.0006659209160667;
    if( 30<pt && pt<50)
      scale_factor =  0.9775096148135214;
    if( 50<pt && pt<70)
      scale_factor =  0.966644508506586;
    if( 70<pt && pt<100)
      scale_factor =  0.9640500820316281;
    if( 100<pt && pt<140)
      scale_factor =  0.9676168211605776;
    if( 140<pt && pt<200)
      scale_factor =  0.9731780682102414;
    if( 200<pt && pt<300)
      scale_factor =  0.9955327946316231;
    if( 300<pt && pt<600)
      scale_factor =  1.027933939332208;
    if( 600<pt && pt<1000)
      scale_factor =  1.0964127641955193;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  1.0006659209160667;
    if( 30<pt && pt<50)
      scale_factor =  0.9775096148135214;
    if( 50<pt && pt<70)
      scale_factor =  0.966644508506586;
    if( 70<pt && pt<100)
      scale_factor =  0.9640500820316281;
    if( 100<pt && pt<140)
      scale_factor =  0.9676168211605776;
    if( 140<pt && pt<200)
      scale_factor =  0.9731780682102414;
    if( 200<pt && pt<300)
      scale_factor =  0.9955327946316231;
    if( 300<pt && pt<600)
      scale_factor =  1.027933939332208;
    if( 600<pt && pt<1000)
      scale_factor =  1.0964127641955193;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_LightTagJets_Mis_Run3Summer23BPix(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  1.5086318236312501;
    if( 30<pt && pt<50)
      scale_factor =  1.4957472481535998;
    if( 50<pt && pt<70)
      scale_factor =  1.4788546133184002;
    if( 70<pt && pt<100)
      scale_factor =  1.4582063047426501;
    if( 100<pt && pt<140)
      scale_factor =  1.4301876329471999;
    if( 140<pt && pt<200)
      scale_factor =  1.40701414185;
    if( 200<pt && pt<300)
      scale_factor =  1.3355943187500001;
    if( 300<pt && pt<600)
      scale_factor =  1.2462879936000002;
    if( 600<pt && pt<1000)
      scale_factor =  1.1265945888;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  1.5086318236312501;
    if( 30<pt && pt<50)
      scale_factor =  1.4957472481535998;
    if( 50<pt && pt<70)
      scale_factor =  1.4788546133184002;
    if( 70<pt && pt<100)
      scale_factor =  1.4582063047426501;
    if( 100<pt && pt<140)
      scale_factor =  1.4301876329471999;
    if( 140<pt && pt<200)
      scale_factor =  1.40701414185;
    if( 200<pt && pt<300)
      scale_factor =  1.3355943187500001;
    if( 300<pt && pt<600)
      scale_factor =  1.2462879936000002;
    if( 600<pt && pt<1000)
      scale_factor =  1.1265945888;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  1.5086318236312501;
    if( 30<pt && pt<50)
      scale_factor =  1.4957472481535998;
    if( 50<pt && pt<70)
      scale_factor =  1.4788546133184002;
    if( 70<pt && pt<100)
      scale_factor =  1.4582063047426501;
    if( 100<pt && pt<140)
      scale_factor =  1.4301876329471999;
    if( 140<pt && pt<200)
      scale_factor =  1.40701414185;
    if( 200<pt && pt<300)
      scale_factor =  1.3355943187500001;
    if( 300<pt && pt<600)
      scale_factor =  1.2462879936000002;
    if( 600<pt && pt<1000)
      scale_factor =  1.1265945888;
  }
  return scale_factor;
}
