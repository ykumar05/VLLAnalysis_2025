//Reco Scale Factors(Electrons): 2022EE
double AnaScript::getScaleFactors_Electrons_Reco_Run3Summer22EE(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9372892379760742;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.951312780380249;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9455876350402832;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9209725856781006;
    if(-1.0<eta && eta<0.0) 
      scale_factor = 0.9865052103996276;
    if(0.0<eta && eta<1.0) 
      scale_factor = 0.9865052103996276;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9209725856781006;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9455876350402832;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.951312780380249;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9372892379760742;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9894707202911376;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9917081594467164;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9949613809585572;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9855061769485474;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9885743856430054;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9861587285995485;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9861587285995485;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9885743856430054;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9855061769485474;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9949613809585572;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9917081594467164;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9894707202911376;
  }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9849587678909302;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9904908537864684;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9698408842086792;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9848232865333556;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.991216242313385;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9887290596961976;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9887290596961976;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.991216242313385;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9848232865333556;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9698408842086792;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9904908537864684;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9849587678909302;
  }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9866523146629332;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0019832849502563;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.038323163986206;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9941419959068298;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.998298406600952;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9957932233810424;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9957932233810424;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.998298406600952;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9941419959068298;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.038323163986206;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0019832849502563;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9866523146629332;
  }
  if(100<pt && pt<1000){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9960200786590576;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9862135052680968;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0194694995880127;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.996940553188324;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9876604080200196;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9939363598823548;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9939363598823548;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9876604080200196;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.996940553188324;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0194694995880127;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9862135052680968;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9960200786590576;
  }
  return scale_factor;
}

//IDIso Scale Factors(Electrons): 2022EE
double AnaScript::getScaleFactors_Electrons_IDIso_Run3Summer22EE(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0915666818618774;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0761135816574097;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.5866097211837769;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.861142098903656;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.8538560271263123;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.8329818844795227;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.8536130785942078;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.1186095476150513;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.074692726135254;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.079148530960083;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.032730221748352;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0119132995605469;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0279672145843506;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.8766274452209473;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9030481576919556;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.8867086172103882;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.8699238896369934;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.019516944885254;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0122443437576294;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.024436116218567;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0169259309768677;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9899636507034302;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0139169692993164;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9195123910903932;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9358153343200684;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.925159513950348;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9149391055107116;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0119104385375977;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.989618182182312;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.012125015258789;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0014948844909668;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9777312874794006;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0364357233047483;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9306355714797974;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9429609775543212;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9353290796279908;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9281134009361268;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.029523253440857;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.977676272392273;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9977717995643616;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.999452531337738;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0169553756713867;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.059453368186951;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 0.9800916910171508;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.98699152469635;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9815250635147096;
    if(0.8<eta && eta<1.444) 
      scale_factor = 0.9914968609809875;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.047389030456543;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.999967873096466;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.990281879901886;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2022EE
double AnaScript::getScaleFactors_Muons_HLT_Run3Summer22EE(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 25<pt && pt<30)
      scale_factor =  0.9623676155167068;
    if( 30<pt && pt<40)
      scale_factor =  0.9727726086254088;
    if( 40<pt && pt<50)
      scale_factor =  0.973393369879028;
    if( 50<pt && pt<60)
      scale_factor =  0.9715034548598794;
    if( 60<pt && pt<120)
      scale_factor =  0.9700705379539204;
    if( 120<pt && pt<3000)
      scale_factor =  0.9727514087884116;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 25<pt && pt<30)
      scale_factor =  0.9594421374615378;
    if( 30<pt && pt<40)
      scale_factor =  0.9702680094009376;
    if( 40<pt && pt<50)
      scale_factor =  0.971289876633616;
    if( 50<pt && pt<60)
      scale_factor =  0.9714138759099296;
    if( 60<pt && pt<120)
      scale_factor =  0.9713443008524542;
    if( 120<pt && pt<3000)
      scale_factor =  0.9622934444137488;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 25<pt && pt<30)
      scale_factor =  0.9701690062541978;
    if( 30<pt && pt<40)
      scale_factor =  0.9738727313313078;
    if( 40<pt && pt<50)
      scale_factor =  0.9740075283446302;
    if( 50<pt && pt<60)
      scale_factor =  0.9736833729445592;
    if( 60<pt && pt<120)
      scale_factor =  0.9753783091014356;
    if( 120<pt && pt<3000)
      scale_factor =  0.972414233377799;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 25<pt && pt<30)
      scale_factor =  0.9750869899481088;
    if( 30<pt && pt<40)
      scale_factor =  0.9737111289708138;
    if( 40<pt && pt<50)
      scale_factor =  0.9706116360513694;
    if( 50<pt && pt<60)
      scale_factor =  0.9683987441675554;
    if( 60<pt && pt<120)
      scale_factor =  0.9629729843466476;
    if( 120<pt && pt<3000)
      scale_factor =  0.9846493095069502;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2022EE
double AnaScript::getScaleFactors_Muons_ID_Run3Summer22EE(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.997561074342956;
    if( 20<pt && pt<25)
      scale_factor =  0.9968733076832657;
    if( 25<pt && pt<30)
      scale_factor =  0.997210808372441;
    if( 30<pt && pt<40)
      scale_factor =  0.9972935771953882;
    if( 40<pt && pt<50)
      scale_factor =  0.9973504260312088;
    if( 50<pt && pt<60)
      scale_factor =  0.9972602120576506;
    if( 60<pt && pt<120)
      scale_factor =  0.9969439481574022;
    if( 120<pt && pt<3000)
      scale_factor =  0.9960486966420556;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.9938512526710918;
    if( 20<pt && pt<25)
      scale_factor =  0.9929677318436212;
    if( 25<pt && pt<30)
      scale_factor =  0.9925035905122268;
    if( 30<pt && pt<40)
      scale_factor =  0.993614335997923;
    if( 40<pt && pt<50)
      scale_factor =  0.9941890821314538;
    if( 50<pt && pt<60)
      scale_factor =  0.9942047427898928;
    if( 60<pt && pt<120)
      scale_factor =  0.9949334898500536;
    if( 120<pt && pt<3000)
      scale_factor =  0.99367135236561;
  }

  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.980269086152311;
    if( 20<pt && pt<25)
      scale_factor =  0.9760357972316868;
    if( 25<pt && pt<30)
      scale_factor =  0.9781480883228922;
    if( 30<pt && pt<40)
      scale_factor =  0.978128683191464;
    if( 40<pt && pt<50)
      scale_factor =  0.9793718335945474;
    if( 50<pt && pt<60)
      scale_factor =  0.979288106325278;
    if( 60<pt && pt<120)
      scale_factor =  0.9786431460238052;
    if( 120<pt && pt<3000)
      scale_factor =  0.982364657977258;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.9548652521731364;
    if( 20<pt && pt<25)
      scale_factor =  0.9506038864736096;
    if( 25<pt && pt<30)
      scale_factor =  0.9476952061866414;
    if( 30<pt && pt<40)
      scale_factor =  0.948658832351822;
    if( 40<pt && pt<50)
      scale_factor =  0.9501556803237736;
    if( 50<pt && pt<60)
      scale_factor =  0.9521849408979014;
    if( 60<pt && pt<120)
      scale_factor =  0.9535543214726218;
    if( 120<pt && pt<3000)
      scale_factor =  0.9326469037790608;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2022EE
double AnaScript::getScaleFactors_Muons_ISO_Run3Summer22EE(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.7986632912255041;
    if( 20<pt && pt<25)
      scale_factor =  0.8404716481442224;
    if( 25<pt && pt<30)
      scale_factor =  0.8776087278131676;
    if( 30<pt && pt<40)
      scale_factor =  0.91444642271939;
    if( 40<pt && pt<50)
      scale_factor =  0.9467466986441944;
    if( 50<pt && pt<60)
      scale_factor =  0.9665789378996542;
    if( 60<pt && pt<120)
      scale_factor =  0.982927030991292;
    if( 120<pt && pt<3000)
      scale_factor =  1.001771738113732;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.7441613038452656;
    if( 20<pt && pt<25)
      scale_factor =  0.7897306488028356;
    if( 25<pt && pt<30)
      scale_factor =  0.8297366284941877;
    if( 30<pt && pt<40)
      scale_factor =  0.8743464409600076;
    if( 40<pt && pt<50)
      scale_factor =  0.9173371836549538;
    if( 50<pt && pt<60)
      scale_factor =  0.9469596108442192;
    if( 60<pt && pt<120)
      scale_factor =  0.974166480189324;
    if( 120<pt && pt<3000)
      scale_factor =  1.0014207658082692;
  }
  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9674620884552674;
    if( 20<pt && pt<25)
      scale_factor =  0.968001806277648;
    if( 25<pt && pt<30)
      scale_factor =  0.9735802682021368;
    if( 30<pt && pt<40)
      scale_factor =  0.9793452375813716;
    if( 40<pt && pt<50)
      scale_factor =  0.9858122214544676;
    if( 50<pt && pt<60)
      scale_factor =  0.99069557482826;
    if( 60<pt && pt<120)
      scale_factor =  0.9948522214725256;
    if( 120<pt && pt<3000)
      scale_factor =  1.000950708960985;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  1.032426065227429;
    if( 20<pt && pt<25)
      scale_factor =  1.0299276707430447;
    if( 25<pt && pt<30)
      scale_factor =  1.0213040750615574;
    if( 30<pt && pt<40)
      scale_factor =  1.013841426104469;
    if( 40<pt && pt<50)
      scale_factor =  1.006579751916438;
    if( 50<pt && pt<60)
      scale_factor =  1.0038893369828452;
    if( 60<pt && pt<120)
      scale_factor =  1.0041572008843618;
    if( 120<pt && pt<3000)
      scale_factor =  1.0052580097261397;
  }
  return scale_factor;
}

