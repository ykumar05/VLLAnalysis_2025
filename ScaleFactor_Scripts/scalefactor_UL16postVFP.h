//RecoScaleFactors(Electrons): 2016_postVFP
double AnaScript::getScaleFactors_Electrons_Reco_UL16postVFP(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0152403116226196;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.990312159061432;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.1295620203018188;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9585605263710022;
    if(-1.0<eta && eta<0.0) 
      scale_factor = 1.0240384340286257;
    if(0.0<eta && eta<1.0) 
      scale_factor = 1.0240384340286257;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9585605263710022;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.1295620203018188;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.990312159061432;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0152403116226196;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0353591442108154;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9926931262016296;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.989461362361908;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9876416325569152;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9856704473495485;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.983589768409729;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.983589768409729;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9856997132301332;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9845995903015136;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9763872623443604;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.98860102891922;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.991416335105896;
    }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.020474195480347;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9896265268325806;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9596510529518129;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9867346882820128;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.98578679561615;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9857434034347534;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.984725058078766;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9868020415306092;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9857288599014282;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9589632749557496;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9886831045150756;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9915878176689148;
    }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9732785224914552;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.991256833076477;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9817444086074828;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9766970872879028;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.976673424243927;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.976673424243927;
    if(0.5<eta && eta<1.0) 
      scale_factor =0.9766970872879028 ;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9817444086074828;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.991256833076477;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9732785224914552;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0;
    }
  if(100<pt && pt<1000){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0105262994766235;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9969356656074524;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9988986849784852;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9919354915618896;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9909273982048036;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.986868679523468;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.986868679523468;
    if(0.5<eta && eta<1.0) 
      scale_factor =0.9909273982048036 ;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9919354915618896;
    if(1.444<eta && eta<1.566) 
      scale_factor =0.9988986849784852 ;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9969356656074524;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0105262994766235;
    }
  return scale_factor;
}

//IDIso Scale Factor(Electrons): 2016_postVFP
double AnaScript::getScaleFactors_Electrons_IDIso_UL16postVFP(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0397112369537354;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0204429626464844;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.003610134124756;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9584055542945862;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9655172228813172;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0242633819580078;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.022687554359436;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.015895962715149;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9973154067993164;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9831932783126832;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9647696614265442;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.98505437374115;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9858956336975098;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9878048896789552;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0114285945892334;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.008838415145874;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0011975765228271;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.982206404209137;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9731621742248536;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9859319925308228;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9880383014678956;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9952152967453004;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9962406158447266;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0036144256591797;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0034762620925903;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9828571677207948;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9719416499137878;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9830890893936156;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9862385392189026;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.99190753698349;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9880810379981996;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0270880460739136;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.024608492851257;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0011049509048462;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.0032930374145508;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.0099338293075562;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0100446939468384;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9945295453071594;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0067644119262695;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2016 postVFP
double AnaScript::getScaleFactors_Muons_Reco_UL16postVFP(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  1.056291820381002;
    if( 20<pt && pt<25)
      scale_factor = 0.9627870246357144 ;
    if( 25<pt && pt<30)
      scale_factor = 0.987978023401688 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9992000996873548 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9995367348504244 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9980919725414232 ;
    if( 60<pt && pt<120)
      scale_factor =  0.9853222024574856;
    if( 120<pt && pt<3000)
      scale_factor = 0.9853222024574856 ;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor = 0.8892388955220546 ;
    if( 20<pt && pt<25)
      scale_factor = 1.022054581840318 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9955481975125244 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9991822468718874 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9988601953525188 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9997061366209312 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9927611463643844 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9927611463643844 ;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor = 0.9363650483641645 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9739458317338784 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9987101660679462 ;
    if( 30<pt && pt<40)
      scale_factor = 0.997568576306376 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9986652097641068 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9994639649262176 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9938417669117328 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9938417669117328 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor = 0.945474482343702 ;
    if( 20<pt && pt<25)
      scale_factor = 1.0090118243659676 ;
    if( 25<pt && pt<30)
      scale_factor = 1.0047838836783498 ;
    if( 30<pt && pt<40)
      scale_factor = 1.002353454383219 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9921194306198418 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9890612820855476;
    if( 60<pt && pt<120)
      scale_factor = 1.008307516945261 ;
    if( 120<pt && pt<3000)
      scale_factor = 1.008307516945261 ;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2016 postVFP
double AnaScript::getScaleFactors_Muons_ID_UL16postVFP(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor = 1.0000041738158354 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9990199540731494 ;
    if( 25<pt && pt<30)
      scale_factor = 0.999548660646305 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9992690049961372 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9992537131247722 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9987772239305884 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9988329307945766 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9988329307945766 ;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor = 0.9935125772523964 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9945582990388512 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9963131040992652 ;
    if( 30<pt && pt<40)
      scale_factor = 0.995557465152997 ;
    if( 40<pt && pt<50)
      scale_factor = 0.995849044136711 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9960145401876056;
    if( 60<pt && pt<120)
      scale_factor = 0.9955682146213594 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9955682146213594 ;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor = 0.9952467407300474 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9956863884750184 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9963280270258894 ;
    if( 30<pt && pt<40)
      scale_factor =  0.9963540789044504;
    if( 40<pt && pt<50)
      scale_factor =0.997101761840005  ;
    if( 50<pt && pt<60)
      scale_factor = 0.9967922838866176 ;
    if( 60<pt && pt<120)
      scale_factor =  0.9967515371285344;
    if( 120<pt && pt<3000)
      scale_factor = 0.9967515371285344 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor = 0.9785830351419386 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9768825062950852 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9771488876540624 ;
    if( 30<pt && pt<40)
      scale_factor = 0.978591269895218 ;
    if( 40<pt && pt<50)
      scale_factor =  0.9775049786244718;
    if( 50<pt && pt<60)
      scale_factor = 0.978501128153901 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9759579114670028 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9759579114670028 ;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2016 postVFP
double AnaScript::getScaleFactors_Muons_ISO_UL16postVFP(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.9896638155504588;
    if( 20<pt && pt<25)
      scale_factor =  0.9948288271080996;
    if( 25<pt && pt<30)
      scale_factor = 0.991510525326622 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9956044247397018 ;
    if( 40<pt && pt<50)
      scale_factor = 0.996982924553536 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9971974780479392 ;
    if( 60<pt && pt<120)
      scale_factor =  0.9990199324137672;
    if( 120<pt && pt<3000)
      scale_factor =  0.9990199324137672;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  1.0019934719330423;
    if( 20<pt && pt<25)
      scale_factor =  1.0003741848922898;
    if( 25<pt && pt<30)
      scale_factor =  1.003365985645747;
    if( 30<pt && pt<40)
      scale_factor = 1.0005506260825516 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9979449902609792 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9996145084763732;
    if( 60<pt && pt<120)
      scale_factor = 1.0000428280021068 ;
    if( 120<pt && pt<3000)
      scale_factor = 1.0000428280021068 ;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor = 1.0033017968451217 ;
    if( 20<pt && pt<25)
      scale_factor = 1.0070463673112666 ;
    if( 25<pt && pt<30)
      scale_factor = 1.0051735075912909 ;
    if( 30<pt && pt<40)
      scale_factor = 1.0015919713475052 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9998315341668478 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9988739251057712 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9998786688203968 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9998786688203968 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor = 1.0137764681943071 ;
    if( 20<pt && pt<25)
      scale_factor = 1.010785849114932 ;
    if( 25<pt && pt<30)
      scale_factor = 1.0042843905385197 ;
    if( 30<pt && pt<40)
      scale_factor = 1.003150058119613 ;
    if( 40<pt && pt<50)
      scale_factor = 1.001092172040312 ;
    if( 50<pt && pt<60)
      scale_factor = 1.0010712993352038 ;
    if( 60<pt && pt<120)
      scale_factor = 1.000794927481125 ;
    if( 120<pt && pt<3000)
      scale_factor = 1.000794927481125 ;
  }
  return scale_factor;
}
