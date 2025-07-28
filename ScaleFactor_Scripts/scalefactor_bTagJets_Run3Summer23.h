double AnaScript::getScaleFactors_bTagJets_MedWP_Run3Summer23(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.984378497016109;
    if( 30<pt && pt<50)
      scale_factor =  0.9859499332355224;
    if( 50<pt && pt<70)
      scale_factor =  0.9866636173222813;
    if( 70<pt && pt<100)
      scale_factor =  0.9868018803437115;
    if( 100<pt && pt<140)
      scale_factor =  0.9865064879432106;
    if( 140<pt && pt<200)
      scale_factor =  0.9860861277274804;
    if( 200<pt && pt<300)
      scale_factor =  0.9844457638100055;
    if( 300<pt && pt<600)
      scale_factor =  0.9821027765267204;
    if( 600<pt && pt<1000)
      scale_factor =  0.9771893260033672;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.984378497016109;
    if( 30<pt && pt<50)
      scale_factor =  0.9859499332355224;
    if( 50<pt && pt<70)
      scale_factor =  0.9866636173222813;
    if( 70<pt && pt<100)
      scale_factor =  0.9868018803437115;
    if( 100<pt && pt<140)
      scale_factor =  0.9865064879432106;
    if( 140<pt && pt<200)
      scale_factor =  0.9860861277274804;
    if( 200<pt && pt<300)
      scale_factor =  0.9844457638100055;
    if( 300<pt && pt<600)
      scale_factor =  0.9821027765267204;
    if( 600<pt && pt<1000)
      scale_factor =  0.9771893260033672;
    }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.984378497016109;
    if( 30<pt && pt<50)
      scale_factor =  0.9859499332355224;
    if( 50<pt && pt<70)
      scale_factor =  0.9866636173222813;
    if( 70<pt && pt<100)
      scale_factor =  0.9868018803437115;
    if( 100<pt && pt<140)
      scale_factor =  0.9865064879432106;
    if( 140<pt && pt<200)
      scale_factor =  0.9860861277274804;
    if( 200<pt && pt<300)
      scale_factor =  0.9844457638100055;
    if( 300<pt && pt<600)
      scale_factor =  0.9821027765267204;
    if( 600<pt && pt<1000)
      scale_factor =  0.9771893260033672;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_cTagJets_Mis_Run3Summer23(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.984378497016109;
    if( 30<pt && pt<50)
      scale_factor =  0.9859499332355224;
    if( 50<pt && pt<70)
      scale_factor =  0.9866636173222813;
    if( 70<pt && pt<100)
      scale_factor =  0.9868018803437115;
    if( 100<pt && pt<140)
      scale_factor =  0.9865064879432106;
    if( 140<pt && pt<200)
      scale_factor =  0.9860861277274804;
    if( 200<pt && pt<300)
      scale_factor =  0.9844457638100055;
    if( 300<pt && pt<600)
      scale_factor =  0.9821027765267204;
    if( 600<pt && pt<1000)
      scale_factor =  0.9771893260033672;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.984378497016109;
    if( 30<pt && pt<50)
      scale_factor =  0.9859499332355224;
    if( 50<pt && pt<70)
      scale_factor =  0.9866636173222813;
    if( 70<pt && pt<100)
      scale_factor =  0.9868018803437115;
    if( 100<pt && pt<140)
      scale_factor =  0.9865064879432106;
    if( 140<pt && pt<200)
      scale_factor =  0.9860861277274804;
    if( 200<pt && pt<300)
      scale_factor =  0.9844457638100055;
    if( 300<pt && pt<600)
      scale_factor =  0.9821027765267204;
    if( 600<pt && pt<1000)
      scale_factor =  0.9771893260033672;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.984378497016109;
    if( 30<pt && pt<50)
      scale_factor =  0.9859499332355224;
    if( 50<pt && pt<70)
      scale_factor =  0.9866636173222813;
    if( 70<pt && pt<100)
      scale_factor =  0.9868018803437115;
    if( 100<pt && pt<140)
      scale_factor =  0.9865064879432106;
    if( 140<pt && pt<200)
      scale_factor =  0.9860861277274804;
    if( 200<pt && pt<300)
      scale_factor =  0.9844457638100055;
    if( 300<pt && pt<600)
      scale_factor =  0.9821027765267204;
    if( 600<pt && pt<1000)
      scale_factor =  0.9771893260033672;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_LightTagJets_Mis_Run3Summer23(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  1.693561402171875;
    if( 30<pt && pt<50)
      scale_factor =  1.6769324818559999;
    if( 50<pt && pt<70)
      scale_factor =  1.6551041210639998;
    if( 70<pt && pt<100)
      scale_factor =  1.628378686203375;
    if( 100<pt && pt<140)
      scale_factor =  1.592028126912;
    if( 140<pt && pt<200)
      scale_factor =  1.561880044125;
    if( 200<pt && pt<300)
      scale_factor =  1.4683680468749998;
    if( 300<pt && pt<600)
      scale_factor =  1.3494696959999999;
    if( 600<pt && pt<1000)
      scale_factor =  1.1745326079999998;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  1.693561402171875;
    if( 30<pt && pt<50)
      scale_factor =  1.6769324818559999;
    if( 50<pt && pt<70)
      scale_factor =  1.6551041210639998;
    if( 70<pt && pt<100)
      scale_factor =  1.628378686203375;
    if( 100<pt && pt<140)
      scale_factor =  1.592028126912;
    if( 140<pt && pt<200)
      scale_factor =  1.561880044125;
    if( 200<pt && pt<300)
      scale_factor =  1.4683680468749998;
    if( 300<pt && pt<600)
      scale_factor =  1.3494696959999999;
    if( 600<pt && pt<1000)
      scale_factor =  1.1745326079999998;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  1.693561402171875;
    if( 30<pt && pt<50)
      scale_factor =  1.6769324818559999;
    if( 50<pt && pt<70)
      scale_factor =  1.6551041210639998;
    if( 70<pt && pt<100)
      scale_factor =  1.628378686203375;
    if( 100<pt && pt<140)
      scale_factor =  1.592028126912;
    if( 140<pt && pt<200)
      scale_factor =  1.561880044125;
    if( 200<pt && pt<300)
      scale_factor =  1.4683680468749998;
    if( 300<pt && pt<600)
      scale_factor =  1.3494696959999999;
    if( 600<pt && pt<1000)
      scale_factor =  1.1745326079999998;
  }
  return scale_factor;
}
