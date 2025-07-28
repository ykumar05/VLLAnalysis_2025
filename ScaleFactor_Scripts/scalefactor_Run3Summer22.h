//Reco Scale Factors(Electrons): 2022
double AnaScript::getScaleFactors_Electrons_Reco_Run3Summer22(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0030765533447266;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9079503417015076;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.7930880784988403;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9176207780838012;
    if(-1.0<eta && eta<0.0) 
      scale_factor = 0.8346001505851746;
    if(0.0<eta && eta<1.0) 
      scale_factor = 0.8346001505851746;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9176207780838012;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.7930880784988403;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9079503417015076;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0030765533447266;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9916660785675048;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9915667176246644;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0013121366500854;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.988800585269928;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9912850260734558;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9899967312812804;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9899967312812804;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9912850260734558;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.988800585269928;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0013121366500854;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9915667176246644;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9916660785675048;
  }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9906820058822632;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.99161696434021;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9719863533973694;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9904730916023254;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.99298894405365;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9899146556854248;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9899146556854248;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.99298894405365;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9904730916023254;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9719863533973694;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.99161696434021;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9906820058822632;
  }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9774878025054932;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9763971567153932;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0244228839874268;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9927586913108826;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9879266023635864;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9893608689308168;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9893608689308168;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9879266023635864;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9927586913108826;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0244228839874268;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9763971567153932;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9774878025054932;
  }
  if(100<pt && pt<1000){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9819217324256896;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9778780937194824;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.001950740814209;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9820126891136168;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9957142472267152;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.985642671585083;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.985642671585083;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9957142472267152;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9820126891136168;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.001950740814209;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9778780937194824;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9819217324256896;
  }
  return scale_factor;
}

//IDIso Scale Factors(Electrons): 2022
double AnaScript::getScaleFactors_Electrons_IDIso_Run3Summer22(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0355587005615234;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.012273192405701;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0793638229370115;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9581530690193176;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9977340698242188;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9348284006118774;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9520316123962402;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.1617189645767212;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0382626056671145;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.026786208152771;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9968543648719788;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.98770672082901;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0390616655349731;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9495647549629213;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9704270362854004;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9640677571296692;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.938588559627533;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.963303804397583;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9788777232170104;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9847609400749208;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9945716857910156;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9775808453559875;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.00307035446167;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9638331532478333;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9751390814781188;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9687882661819458;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9607123732566832;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9934831261634828;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9780535101890564;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9870863556861876;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9898059368133544;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9715616703033448;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0253740549087524;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.960373878479004;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9687591195106506;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9646034836769104;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9603594541549684;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0161834955215454;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9719422459602356;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9777079820632936;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9887202382087708;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9909942150115968;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0895615816116333;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0009709596633911;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9840625524520874;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.984474003314972;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9970199465751648;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9685735702514648;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.982017993927002;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9834773540496826;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2022
double AnaScript::getScaleFactors_Muons_HLT_Run3Summer22(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 25<pt && pt<30)
      scale_factor =  0.9778855415279756;
    if( 30<pt && pt<40)
      scale_factor =  0.9810129289367224;
    if( 40<pt && pt<50)
      scale_factor =  0.9804505419782396;
    if( 50<pt && pt<60)
      scale_factor =  0.9778274102212736;
    if( 60<pt && pt<120)
      scale_factor =  0.9768086281977956;
    if( 120<pt && pt<3000)
      scale_factor =  0.9776929327490804;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 25<pt && pt<30)
      scale_factor =  0.9717689219363028;
    if( 30<pt && pt<40)
      scale_factor =  0.974869883948331;
    if( 40<pt && pt<50)
      scale_factor =  0.9741974500912162;
    if( 50<pt && pt<60)
      scale_factor =  0.9727877337316236;
    if( 60<pt && pt<120)
      scale_factor =  0.96831628041056;
    if( 120<pt && pt<3000)
      scale_factor =  0.9820558404398806;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 25<pt && pt<30)
      scale_factor =  0.9479305551643828;
    if( 30<pt && pt<40)
      scale_factor =  0.9593625243100424;
    if( 40<pt && pt<50)
      scale_factor =  0.9612023005611312;
    if( 50<pt && pt<60)
      scale_factor =  0.9605061546287889;
    if( 60<pt && pt<120)
      scale_factor =  0.9578042591165168;
    if( 120<pt && pt<3000)
      scale_factor =  0.9590018147523666;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 25<pt && pt<30)
      scale_factor =  0.84570190858844;
    if( 30<pt && pt<40)
      scale_factor =  0.8799291748570023;
    if( 40<pt && pt<50)
      scale_factor =  0.9080376216556691;
    if( 50<pt && pt<60)
      scale_factor =  0.9193316092462588;
    if( 60<pt && pt<120)
      scale_factor =  0.9302606522598584;
    if( 120<pt && pt<3000)
      scale_factor =  0.9643871704159996;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2022
double AnaScript::getScaleFactors_Muons_ID_Run3Summer22(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.996594666054228;
    if( 20<pt && pt<25)
      scale_factor =  0.9971732066380248;
    if( 25<pt && pt<30)
      scale_factor =  0.9979084696932952;
    if( 30<pt && pt<40)
      scale_factor =  0.9977101461749242;
    if( 40<pt && pt<50)
      scale_factor =  0.9975883472142756;
    if( 50<pt && pt<60)
      scale_factor =  0.9975850789429236;
    if( 60<pt && pt<120)
      scale_factor =  0.9979015912090448;
    if( 120<pt && pt<3000)
      scale_factor =  0.9994503981453868;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.99561307953011;
    if( 20<pt && pt<25)
      scale_factor =  0.993278128366022;
    if( 25<pt && pt<30)
      scale_factor =  0.9951766356553664;
    if( 30<pt && pt<40)
      scale_factor =  0.994519377152232;
    if( 40<pt && pt<50)
      scale_factor =  0.9953357404115448;
    if( 50<pt && pt<60)
      scale_factor =  0.9956046687448308;
    if( 60<pt && pt<120)
      scale_factor =  0.9957426498561972;
    if( 120<pt && pt<3000)
      scale_factor =  0.9928422492054554;
  }

  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9927741155564296;
    if( 20<pt && pt<25)
      scale_factor =  0.9934825062350086;
    if( 25<pt && pt<30)
      scale_factor =  0.9930485762045822;
    if( 30<pt && pt<40)
      scale_factor =  0.9927849134786172;
    if( 40<pt && pt<50)
      scale_factor =  0.9932989226930516;
    if( 50<pt && pt<60)
      scale_factor =  0.993530148647914;
    if( 60<pt && pt<120)
      scale_factor =  0.9930336987491296;
    if( 120<pt && pt<3000)
      scale_factor =  0.9986445384177282;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.9910685358756004;
    if( 20<pt && pt<25)
      scale_factor =  0.9830416347980871;
    if( 25<pt && pt<30)
      scale_factor =  0.9806433583044314;
    if( 30<pt && pt<40)
      scale_factor =  0.981385919748576;
    if( 40<pt && pt<50)
      scale_factor =  0.9835972306699832;
    if( 50<pt && pt<60)
      scale_factor =  0.9855181499006486;
    if( 60<pt && pt<120)
      scale_factor =  0.9844673403345436;
    if( 120<pt && pt<3000)
      scale_factor =  0.9847849338358956;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2022
double AnaScript::getScaleFactors_Muons_ISO_Run3Summer22(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.9811793281840216;
    if( 20<pt && pt<25)
      scale_factor =  0.9878986068216188;
    if( 25<pt && pt<30)
      scale_factor =  0.9878810043525824;
    if( 30<pt && pt<40)
      scale_factor =  0.9947200070454004;
    if( 40<pt && pt<50)
      scale_factor =  0.9966386009882088;
    if( 50<pt && pt<60)
      scale_factor =  0.9964757333127492;
    if( 60<pt && pt<120)
      scale_factor =  0.9986261457613894;
    if( 120<pt && pt<3000)
      scale_factor =  1.0059338624826688;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.9628713291773462;
    if( 20<pt && pt<25)
      scale_factor =  0.978164193320083;
    if( 25<pt && pt<30)
      scale_factor =  0.981030089731186;
    if( 30<pt && pt<40)
      scale_factor =  0.9841466315160592;
    if( 40<pt && pt<50)
      scale_factor =  0.9904819480367268;
    if( 50<pt && pt<60)
      scale_factor =  0.993272177863133;
    if( 60<pt && pt<120)
      scale_factor =  0.9959268894013272;
    if( 120<pt && pt<3000)
      scale_factor =  1.0038350431068437;
  }
  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9711325250388084;
    if( 20<pt && pt<25)
      scale_factor =  0.9802681383662922;
    if( 25<pt && pt<30)
      scale_factor =  0.9860315865528246;
    if( 30<pt && pt<40)
      scale_factor =  0.990218208000474;
    if( 40<pt && pt<50)
      scale_factor =  0.9940823697798598;
    if( 50<pt && pt<60)
      scale_factor =  0.996102999064948;
    if( 60<pt && pt<120)
      scale_factor =  0.9982619418809624;
    if( 120<pt && pt<3000)
      scale_factor =  1.0099364904351842;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.9815042165074224;
    if( 20<pt && pt<25)
      scale_factor =  1.0022313361543185;
    if( 25<pt && pt<30)
      scale_factor =  0.9954527176526276;
    if( 30<pt && pt<40)
      scale_factor =  0.9998945470572485;
    if( 40<pt && pt<50)
      scale_factor =  1.0001431143583128;
    if( 50<pt && pt<60)
      scale_factor =  0.9994477308594882;
    if( 60<pt && pt<120)
      scale_factor =  1.001176588545743;
    if( 120<pt && pt<3000)
      scale_factor =  1.006445117698621;
  }
  return scale_factor;
}

