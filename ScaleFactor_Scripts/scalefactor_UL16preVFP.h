//RecoScaleFactors(Electrons): 2016 preVFP
double AnaScript::getScaleFactors_Electrons_Reco_UL16preVFP(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0138888359069824;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9903433322906494;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.206501007080078;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 1.0175824165344238;
    if(-1.0<eta && eta<0.0) 
      scale_factor = 1.055690050125122;
    if(0.0<eta && eta<1.0) 
      scale_factor = 1.055690050125122;
    if(1.0<eta && eta<1.444) 
      scale_factor = 1.0175824165344238;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.206501007080078;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9903433322906494;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0138888359069824;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.996791422367096;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9927234649658204;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9575971961021424;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9855967164039612;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9794450402259828;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9752577543258668;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9865979552268982;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9877049326896667;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.989722490310669;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.971563994884491;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9938016533851624;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0;
    }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9915878176689148;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9927685856819152;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9621621370315552;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9867211580276488;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9816138744354248;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9795291423797609;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9877175092697144;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9877800345420836;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9887754917144777;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9751351475715636;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9907597303390504;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9925373196601868;
    }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9883720874786376;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9846311211586;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0121278762817385;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9827761054039;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9766022562980652;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9877426028251648;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9877426028251648;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9766022562980652;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9827761054039;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0121278762817385;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9846311211586;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9883720874786376;

  }
  if(100<pt && pt<1000){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.009584665298462;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0163766145706177;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0143805742263794;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9798183441162108;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9848637580871582;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9898682832717896;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9898682832717896;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9848637580871582;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9798183441162108;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0143805742263794;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0163766145706177;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.009584665298462;
    }
  return scale_factor;
}

//IDIso Scale Factors(Electrons): 2016 preVFP
double AnaScript::getScaleFactors_Electrons_IDIso_UL16preVFP(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0819367170333862;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.065743923187256;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.038673996925354;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9839285612106324;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9912126660346984;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0694184303283691;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor =1.0352113246917725;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0833333730697632;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0307917594909668;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0176870822906494;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9957447052001952;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9723374843597412;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9821428656578064;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0028570890426636;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.009602189064026;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0203487873077393;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0152283906936646;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0120337009429932;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.990407645702362;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9692671298980712;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9799528121948242;
    if(0.8<eta && eta<1.444) 
      scale_factor =0.9927797913551332 ;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0096385478973389;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0114504098892212;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0024067163467407;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.004629611968994;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9896193742752076;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9693182110786438;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9773242473602296;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9884659647941588;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0092915296554563;
    if(2.0<eta && eta<2.4) 
      scale_factor =1.0048367977142334 ;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0160366296768188;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0245535373687744;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0022321939468384;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9889135360717772;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.0011111497879028;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.011135816574097;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9911012053489684;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0346020460128784;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2016 preVFP
double AnaScript::getScaleFactors_Muons_Reco_UL16preVFP(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  1.0446273708660905;
    if( 20<pt && pt<25)
      scale_factor =  0.9405655555018376;
    if( 25<pt && pt<30)
      scale_factor = 0.9998939867138692 ;
    if( 30<pt && pt<40)
      scale_factor =  0.9995277742731352;
    if( 40<pt && pt<50)
      scale_factor =  0.9999352681323206;
    if( 50<pt && pt<60)
      scale_factor = 0.9995078992862044 ;
    if( 60<pt && pt<120)
      scale_factor = 0.99375897804621 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.99375897804621 ;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  1.0361175046804814;
    if( 20<pt && pt<25)
      scale_factor =  0.9923137867078856;
    if( 25<pt && pt<30)
      scale_factor = 0.9983364124577536 ;
    if( 30<pt && pt<40)
      scale_factor = 0.998972512114526 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9997915677286272 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9988593796096642 ;
    if( 60<pt && pt<120)
      scale_factor = 1.0007144177738287 ;
    if( 120<pt && pt<3000)
      scale_factor = 1.0007144177738287 ;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor = 0.9129515796253396 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9658955236931815 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9936254866774044 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9979681231700336 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9993470103425014 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9989902374832634;
    if( 60<pt && pt<120)
      scale_factor = 0.983545090393948 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.983545090393948 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor = 0.9477240389808844 ;
    if( 20<pt && pt<25)
      scale_factor = 0.92859269411554 ;
    if( 25<pt && pt<30)
      scale_factor = 1.0055252510399186 ;
    if( 30<pt && pt<40)
      scale_factor = 0.996450420248231 ;
    if( 40<pt && pt<50)
      scale_factor = 0.992818592569064 ;
    if( 50<pt && pt<60)
      scale_factor = 1.002406180326867 ;
    if( 60<pt && pt<120)
      scale_factor =  0.9956175157367412;
    if( 120<pt && pt<3000)
      scale_factor =  0.9956175157367412;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2016 preVFP
double AnaScript::getScaleFactors_Muons_ID_UL16preVFP(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor = 0.9958995777819518 ;
    if( 20<pt && pt<25)
      scale_factor = 0.997407446293603 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9966900133732628 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9963886027389632 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9963339691909062 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9958585208059144 ;
    if( 60<pt && pt<120)
      scale_factor = 0.995911293220199 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.995911293220199 ;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor = 0.9943616457833304 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9942061202269802 ;
    if( 25<pt && pt<30)
      scale_factor = 0.99363947046918 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9942575420308007 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9947647951586552 ;
    if( 50<pt && pt<60)
      scale_factor =  0.9943155135270608;
    if( 60<pt && pt<120)
      scale_factor = 0.9933211462795392 ;
    if( 120<pt && pt<3000)
      scale_factor =  0.9933211462795392;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor = 0.9944285295926252 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9939925358291593 ;
    if( 25<pt && pt<30)
      scale_factor = 0.994002465208057 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9947471249733232 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9954753870789153 ;
    if( 50<pt && pt<60)
      scale_factor = 0.995042227697235 ;
    if( 60<pt && pt<120)
      scale_factor = 0.995414618581377 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.995414618581377 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor = 0.974452901727927 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9741967439553206 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9745366426282696 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9748921822166626 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9749005301709184 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9748468540075824 ;
    if( 60<pt && pt<120)
      scale_factor =  0.9741452452429542;
    if( 120<pt && pt<3000)
      scale_factor = 0.9741452452429542 ;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2016 preVFP
double AnaScript::getScaleFactors_Muons_ISO_UL16preVFP(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor = 0.9854219941983452 ;
    if( 20<pt && pt<25)
      scale_factor = 0.9873274510709348 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9857570348249912 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9930490361264857 ;
    if( 40<pt && pt<50)
      scale_factor =  0.996406871349816;
    if( 50<pt && pt<60)
      scale_factor = 0.996876679315402 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9986788196912988 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9986788196912988 ;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor = 0.9801483018547148 ;
    if( 20<pt && pt<25)
      scale_factor = 0.987034038637174 ;
    if( 25<pt && pt<30)
      scale_factor = 0.9961324150426912 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9963549633414416 ;
    if( 40<pt && pt<50)
      scale_factor = 0.9970368902923656 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9971575821289996 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9988473955529408 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9988473955529408 ;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor = 0.9972440980735284 ;
    if( 20<pt && pt<25)
      scale_factor = 0.996750888945838 ;
    if( 25<pt && pt<30)
      scale_factor = 1.001137262338288 ;
    if( 30<pt && pt<40)
      scale_factor = 0.9988626071423738 ;
    if( 40<pt && pt<50)
      scale_factor = 0.998769936879404 ;
    if( 50<pt && pt<60)
      scale_factor = 0.998384760194074 ;
    if( 60<pt && pt<120)
      scale_factor = 0.9995753755081986 ;
    if( 120<pt && pt<3000)
      scale_factor = 0.9995753755081986 ;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor = 1.0073108674943814 ;
    if( 20<pt && pt<25)
      scale_factor = 1.0036700117457582 ;
    if( 25<pt && pt<30)
      scale_factor = 1.0050586818252794 ;
    if( 30<pt && pt<40)
      scale_factor = 1.0003546800592864 ;
    if( 40<pt && pt<50)
      scale_factor = 1.0009520269922647 ;
    if( 50<pt && pt<60)
      scale_factor = 0.9998076464435772 ;
    if( 60<pt && pt<120)
      scale_factor = 1.0005662186130682 ;
    if( 120<pt && pt<3000)
      scale_factor = 1.0005662186130682 ;
  }
  return scale_factor;
}
