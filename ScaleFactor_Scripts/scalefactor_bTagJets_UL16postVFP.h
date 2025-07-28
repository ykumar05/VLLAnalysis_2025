double AnaScript::getScaleFactors_bTagJets_MedWP_UL16postVFP(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.9740263431488866;
    if( 30<pt && pt<50)
      scale_factor =  0.9757661802546029;
    if( 50<pt && pt<70)
      scale_factor =  0.9763278405794318;
    if( 70<pt && pt<100)
      scale_factor =  0.9756356762965536;
    if( 100<pt && pt<140)
      scale_factor =  0.9734584748572837;
    if( 140<pt && pt<200)
      scale_factor =  0.9710701377517904;
    if( 200<pt && pt<300)
      scale_factor =  0.9620675182241363;
    if( 300<pt && pt<600)
      scale_factor =  0.9486070554691469;
    if( 600<pt && pt<1000)
      scale_factor =  0.917817192814847;    
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.9740263431488866;
    if( 30<pt && pt<50)
      scale_factor =  0.9757661802546029;
    if( 50<pt && pt<70)
      scale_factor =  0.9763278405794318;
    if( 70<pt && pt<100)
      scale_factor =  0.9756356762965536;
    if( 100<pt && pt<140)
      scale_factor =  0.9734584748572837;
    if( 140<pt && pt<200)
      scale_factor =  0.9710701377517904;
    if( 200<pt && pt<300)
      scale_factor =  0.9620675182241363;
    if( 300<pt && pt<600)
      scale_factor =  0.9486070554691469;
    if( 600<pt && pt<1000)
      scale_factor =  0.917817192814847;    
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.9740263431488866;
    if( 30<pt && pt<50)
      scale_factor =  0.9757661802546029;
    if( 50<pt && pt<70)
      scale_factor =  0.9763278405794318;
    if( 70<pt && pt<100)
      scale_factor =  0.9756356762965536;
    if( 100<pt && pt<140)
      scale_factor =  0.9734584748572837;
    if( 140<pt && pt<200)
      scale_factor =  0.9710701377517904;
    if( 200<pt && pt<300)
      scale_factor =  0.9620675182241363;
    if( 300<pt && pt<600)
      scale_factor =  0.9486070554691469;
    if( 600<pt && pt<1000)
      scale_factor =  0.917817192814847;    
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_cTagJets_Mis_UL16postVFP(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.9740263431488866;
    if( 30<pt && pt<50)
      scale_factor =  0.9757661802546029;
    if( 50<pt && pt<70)
      scale_factor =  0.9763278405794318;
    if( 70<pt && pt<100)
      scale_factor =  0.9756356762965536;
    if( 100<pt && pt<140)
      scale_factor =  0.9734584748572837;
    if( 140<pt && pt<200)
      scale_factor =  0.9710701377517904;
    if( 200<pt && pt<300)
      scale_factor =  0.9620675182241363;
    if( 300<pt && pt<600)
      scale_factor =  0.9486070554691469;
    if( 600<pt && pt<1000)
      scale_factor =  0.917817192814847;    
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.9740263431488866;
    if( 30<pt && pt<50)
      scale_factor =  0.9757661802546029;
    if( 50<pt && pt<70)
      scale_factor =  0.9763278405794318;
    if( 70<pt && pt<100)
      scale_factor =  0.9756356762965536;
    if( 100<pt && pt<140)
      scale_factor =  0.9734584748572837;
    if( 140<pt && pt<200)
      scale_factor =  0.9710701377517904;
    if( 200<pt && pt<300)
      scale_factor =  0.9620675182241363;
    if( 300<pt && pt<600)
      scale_factor =  0.9486070554691469;
    if( 600<pt && pt<1000)
      scale_factor =  0.917817192814847;    
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.9740263431488866;
    if( 30<pt && pt<50)
      scale_factor =  0.9757661802546029;
    if( 50<pt && pt<70)
      scale_factor =  0.9763278405794318;
    if( 70<pt && pt<100)
      scale_factor =  0.9756356762965536;
    if( 100<pt && pt<140)
      scale_factor =  0.9734584748572837;
    if( 140<pt && pt<200)
      scale_factor =  0.9710701377517904;
    if( 200<pt && pt<300)
      scale_factor =  0.9620675182241363;
    if( 300<pt && pt<600)
      scale_factor =  0.9486070554691469;
    if( 600<pt && pt<1000)
      scale_factor =  0.917817192814847;    
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_LightTagJets_Mis_UL16postVFP(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.8635390112500001;
    if( 30<pt && pt<50)
      scale_factor =  0.7324906708;
    if( 50<pt && pt<70)
      scale_factor =  0.6704593434666667;
    if( 70<pt && pt<100)
      scale_factor =  0.64586460205;
    if( 100<pt && pt<140)
      scale_factor =  0.6437977105333333;
    if( 140<pt && pt<200)
      scale_factor =  0.6535650716666668;
    if( 200<pt && pt<300)
      scale_factor =  0.7087390450000001;
    if( 300<pt && pt<600)
      scale_factor =  0.800244505;
    if( 600<pt && pt<1000)
      scale_factor =  0.9801504325000001;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.8635390112500001;
    if( 30<pt && pt<50)
      scale_factor =  0.7324906708;
    if( 50<pt && pt<70)
      scale_factor =  0.6704593434666667;
    if( 70<pt && pt<100)
      scale_factor =  0.64586460205;
    if( 100<pt && pt<140)
      scale_factor =  0.6437977105333333;
    if( 140<pt && pt<200)
      scale_factor =  0.6535650716666668;
    if( 200<pt && pt<300)
      scale_factor =  0.7087390450000001;
    if( 300<pt && pt<600)
      scale_factor =  0.800244505;
    if( 600<pt && pt<1000)
      scale_factor =  0.9801504325000001;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.8635390112500001;
    if( 30<pt && pt<50)
      scale_factor =  0.7324906708;
    if( 50<pt && pt<70)
      scale_factor =  0.6704593434666667;
    if( 70<pt && pt<100)
      scale_factor =  0.64586460205;
    if( 100<pt && pt<140)
      scale_factor =  0.6437977105333333;
    if( 140<pt && pt<200)
      scale_factor =  0.6535650716666668;
    if( 200<pt && pt<300)
      scale_factor =  0.7087390450000001;
    if( 300<pt && pt<600)
      scale_factor =  0.800244505;
    if( 600<pt && pt<1000)
      scale_factor =  0.9801504325000001;
  }
  return scale_factor;
}
