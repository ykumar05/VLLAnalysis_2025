double AnaScript::getScaleFactors_bTagJets_MedWP_Run3Summer22(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.9655021046152189;
    if( 30<pt && pt<50)
      scale_factor =  0.9634147240215534;
    if( 50<pt && pt<70)
      scale_factor =  0.961069557268016;
    if( 70<pt && pt<100)
      scale_factor =  0.9586017966921623;
    if( 100<pt && pt<140)
      scale_factor =  0.9557107125468958;
    if( 140<pt && pt<200)
      scale_factor =  0.9535888437796509;
    if( 200<pt && pt<300)
      scale_factor =  0.9479470774650262;
    if( 300<pt && pt<600)
      scale_factor =  0.941739993447408;
    if( 600<pt && pt<1000)
      scale_factor =  0.9306895461263189;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.9655021046152189;
    if( 30<pt && pt<50)
      scale_factor =  0.9634147240215534;
    if( 50<pt && pt<70)
      scale_factor =  0.961069557268016;
    if( 70<pt && pt<100)
      scale_factor =  0.9586017966921623;
    if( 100<pt && pt<140)
      scale_factor =  0.9557107125468958;
    if( 140<pt && pt<200)
      scale_factor =  0.9535888437796509;
    if( 200<pt && pt<300)
      scale_factor =  0.9479470774650262;
    if( 300<pt && pt<600)
      scale_factor =  0.941739993447408;
    if( 600<pt && pt<1000)
      scale_factor =  0.9306895461263189;
    }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.9655021046152189;
    if( 30<pt && pt<50)
      scale_factor =  0.9634147240215534;
    if( 50<pt && pt<70)
      scale_factor =  0.961069557268016;
    if( 70<pt && pt<100)
      scale_factor =  0.9586017966921623;
    if( 100<pt && pt<140)
      scale_factor =  0.9557107125468958;
    if( 140<pt && pt<200)
      scale_factor =  0.9535888437796509;
    if( 200<pt && pt<300)
      scale_factor =  0.9479470774650262;
    if( 300<pt && pt<600)
      scale_factor =  0.941739993447408;
    if( 600<pt && pt<1000)
      scale_factor =  0.9306895461263189;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_cTagJets_Mis_Run3Summer22(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  0.9655021046152189;
    if( 30<pt && pt<50)
      scale_factor =  0.9634147240215534;
    if( 50<pt && pt<70)
      scale_factor =  0.961069557268016;
    if( 70<pt && pt<100)
      scale_factor =  0.9586017966921623;
    if( 100<pt && pt<140)
      scale_factor =  0.9557107125468958;
    if( 140<pt && pt<200)
      scale_factor =  0.9535888437796509;
    if( 200<pt && pt<300)
      scale_factor =  0.9479470774650262;
    if( 300<pt && pt<600)
      scale_factor =  0.941739993447408;
    if( 600<pt && pt<1000)
      scale_factor =  0.9306895461263189;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  0.9655021046152189;
    if( 30<pt && pt<50)
      scale_factor =  0.9634147240215534;
    if( 50<pt && pt<70)
      scale_factor =  0.961069557268016;
    if( 70<pt && pt<100)
      scale_factor =  0.9586017966921623;
    if( 100<pt && pt<140)
      scale_factor =  0.9557107125468958;
    if( 140<pt && pt<200)
      scale_factor =  0.9535888437796509;
    if( 200<pt && pt<300)
      scale_factor =  0.9479470774650262;
    if( 300<pt && pt<600)
      scale_factor =  0.941739993447408;
    if( 600<pt && pt<1000)
      scale_factor =  0.9306895461263189;
    }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  0.9655021046152189;
    if( 30<pt && pt<50)
      scale_factor =  0.9634147240215534;
    if( 50<pt && pt<70)
      scale_factor =  0.961069557268016;
    if( 70<pt && pt<100)
      scale_factor =  0.9586017966921623;
    if( 100<pt && pt<140)
      scale_factor =  0.9557107125468958;
    if( 140<pt && pt<200)
      scale_factor =  0.9535888437796509;
    if( 200<pt && pt<300)
      scale_factor =  0.9479470774650262;
    if( 300<pt && pt<600)
      scale_factor =  0.941739993447408;
    if( 600<pt && pt<1000)
      scale_factor =  0.9306895461263189;
  }
  return scale_factor;
}
double AnaScript::getScaleFactors_LightTagJets_Mis_Run3Summer22(float eta, float pt){
  double scale_factor = 1.0;

  if(fabs(eta)<0.8){
    if( 20<pt && pt<30)
      scale_factor =  1.1392299732651925;
    if( 30<pt && pt<50)
      scale_factor =  1.1808704443711942;
    if( 50<pt && pt<70)
      scale_factor =  1.2170659142266405;
    if( 70<pt && pt<100)
      scale_factor =  1.2427309032632727;
    if( 100<pt && pt<140)
      scale_factor =  1.2573035735037987;
    if( 140<pt && pt<200)
      scale_factor =  1.2583335074568647;
    if( 200<pt && pt<300)
      scale_factor =  1.2292741485307712;
    if( 300<pt && pt<600)
      scale_factor =  1.1666826701513222;
    if( 600<pt && pt<1000)
      scale_factor =  1.1221238278906878;
  }
  
  else if(0.8<fabs(eta) && fabs(eta)<1.6){
    if( 20<pt && pt<30)
      scale_factor =  1.1392299732651925;
    if( 30<pt && pt<50)
      scale_factor =  1.1808704443711942;
    if( 50<pt && pt<70)
      scale_factor =  1.2170659142266405;
    if( 70<pt && pt<100)
      scale_factor =  1.2427309032632727;
    if( 100<pt && pt<140)
      scale_factor =  1.2573035735037987;
    if( 140<pt && pt<200)
      scale_factor =  1.2583335074568647;
    if( 200<pt && pt<300)
      scale_factor =  1.2292741485307712;
    if( 300<pt && pt<600)
      scale_factor =  1.1666826701513222;
    if( 600<pt && pt<1000)
      scale_factor =  1.1221238278906878;
  }
  
  else if(1.6<fabs(eta) && fabs(eta)<2.5){
    if( 20<pt && pt<30)
      scale_factor =  1.1392299732651925;
    if( 30<pt && pt<50)
      scale_factor =  1.1808704443711942;
    if( 50<pt && pt<70)
      scale_factor =  1.2170659142266405;
    if( 70<pt && pt<100)
      scale_factor =  1.2427309032632727;
    if( 100<pt && pt<140)
      scale_factor =  1.2573035735037987;
    if( 140<pt && pt<200)
      scale_factor =  1.2583335074568647;
    if( 200<pt && pt<300)
      scale_factor =  1.2292741485307712;
    if( 300<pt && pt<600)
      scale_factor =  1.1666826701513222;
    if( 600<pt && pt<1000)
      scale_factor =  1.1221238278906878;
  }
  return scale_factor;
}
