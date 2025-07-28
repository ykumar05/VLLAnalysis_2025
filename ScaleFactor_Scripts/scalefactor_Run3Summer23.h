//Reco Scale Factors(Electrons): 2023
double AnaScript::getScaleFactors_Electrons_Reco_Run3Summer23(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-1.566) 
      scale_factor = 1.002013921737671;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9448058009147644;
    if(-1.444<eta && eta<0.0)
      scale_factor = 0.9593743681907654;
    if(0.0<eta && eta<1.444) 
      scale_factor = 0.9593743681907654;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9448058009147644;
    if(1.566<eta && eta<5.0) 
      scale_factor = 1.002013921737671;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9878551363945008;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9881659746170044;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9804474711418152;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9836859107017516;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9867085814476012;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9855876564979552;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9860972762107848;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9897868633270264;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9835033416748048;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9624840617179872;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9891653656959534;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9886786937713624;
  }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9823207855224608;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9856106042861938;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9689275026321412;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9852641820907592;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9900880455970764;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9866377711296082;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9877758622169496;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9906696677207948;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9825631380081176;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9469662308692932;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9875930547714232;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9831823706626892;
  }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.008711338043213;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.99896240234375;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0686622858047483;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.998181402683258;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9950242042541504;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9918562769889832;
    if(0.0<eta && eta<0.5) 
      scale_factor = 1.007282853126526;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9976749420166016;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.987789750099182;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9902239441871644;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.995021402835846;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9868254065513612;
  }
  if(100<pt && pt<1000){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9891854524612428;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.002086162567139;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9443423748016356;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9750937819480896;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9818872213363647;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9980607628822328;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9835193753242492;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9649794101715088;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9871637225151062;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0824551582336426;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.981825590133667;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9529044032096864;
  }
  return scale_factor;
}

//IDIso Scale Factors(Electrons): 2023
double AnaScript::getScaleFactors_Electrons_IDIso_Run3Summer23(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0808364152908323;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0807476043701172;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.2828022241592407;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.115926742553711;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.031864881515503;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.0353773832321167;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.1113526821136477;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.261657476425171;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.1011452674865725;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.085526704788208;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.014715313911438;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9992642402648926;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0947349071502686;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0443042516708374;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.012643575668335;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.0106289386749268;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.043727159500122;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0417747497558594;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0101652145385742;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0138002634048462;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0005384683609009;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.983189046382904;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0604256391525269;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.017080545425415;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9995703101158142;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.00053071975708;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.016231894493103;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.04359769821167;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.985749125480652;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0000808238983154;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9915986061096193;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9712851047515868;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0560725927352903;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0037914514541626;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9922433495521544;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9886257648468018;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0042484998703003;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.038817286491394;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.975236177444458;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.981745719909668;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0020017623901367;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0202029943466189;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0991957187652588;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.008522629737854;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.005959391593933;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.001017928123474;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0078858137130735;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0866053104400637;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0085474252700806;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0233049392700195;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2023
double AnaScript::getScaleFactors_Muons_HLT_Run3Summer23(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 25<pt && pt<30)
      scale_factor =  0.9621258341164732;
    if( 30<pt && pt<40)
      scale_factor =  0.9708400229952664;
    if( 40<pt && pt<50)
      scale_factor =  0.9709579202794552;
    if( 50<pt && pt<60)
      scale_factor =  0.9691166468332338;
    if( 60<pt && pt<120)
      scale_factor =  0.9671603317794364;
    if( 120<pt && pt<3000)
      scale_factor =  0.965916707927833;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 25<pt && pt<30)
      scale_factor =  0.9856732411194468;
    if( 30<pt && pt<40)
      scale_factor =  0.982755624110954;
    if( 40<pt && pt<50)
      scale_factor =  0.982627097364872;
    if( 50<pt && pt<60)
      scale_factor =  0.9804961780165348;
    if( 60<pt && pt<120)
      scale_factor =  0.9761382124605203;
    if( 120<pt && pt<3000)
      scale_factor =  0.9722615714977952;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 25<pt && pt<30)
      scale_factor =  0.9851385937437684;
    if( 30<pt && pt<40)
      scale_factor =  0.9980669541687724;
    if( 40<pt && pt<50)
      scale_factor =  1.001179970575341;
    if( 50<pt && pt<60)
      scale_factor =  1.0038402333303524;
    if( 60<pt && pt<120)
      scale_factor =  1.0003974768442816;
    if( 120<pt && pt<3000)
      scale_factor =  1.0050898436651223;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 25<pt && pt<30)
      scale_factor =  0.9520972779546116;
    if( 30<pt && pt<40)
      scale_factor =  0.9799295370746898;
    if( 40<pt && pt<50)
      scale_factor =  0.989107111131376;
    if( 50<pt && pt<60)
      scale_factor =  0.9940151933513643;
    if( 60<pt && pt<120)
      scale_factor =  1.0002547540220084;
    if( 120<pt && pt<3000)
      scale_factor =  1.0327361214165234;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2023
double AnaScript::getScaleFactors_Muons_ID_Run3Summer23(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.9993257100618244;
    if( 20<pt && pt<25)
      scale_factor =  0.9978473144362296;
    if( 25<pt && pt<30)
      scale_factor =  0.998288933727595;
    if( 30<pt && pt<40)
      scale_factor =  0.9982244333006256;
    if( 40<pt && pt<50)
      scale_factor =  0.998482159100856;
    if( 50<pt && pt<60)
      scale_factor =  0.998592463685229;
    if( 60<pt && pt<120)
      scale_factor =  0.9985839608742098;
    if( 120<pt && pt<3000)
      scale_factor =  0.9985420821623068;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.9916352923244658;
    if( 20<pt && pt<25)
      scale_factor =  0.9911960764514964;
    if( 25<pt && pt<30)
      scale_factor =  0.9933951258903824;
    if( 30<pt && pt<40)
      scale_factor =  0.9941466087303944;
    if( 40<pt && pt<50)
      scale_factor =  0.994799737912613;
    if( 50<pt && pt<60)
      scale_factor =  0.9934478456173532;
    if( 60<pt && pt<120)
      scale_factor =  0.995825942301389;
    if( 120<pt && pt<3000)
      scale_factor =  0.9944011959001982;
  }

  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9968290983831284;
    if( 20<pt && pt<25)
      scale_factor =  0.9963082362195907;
    if( 25<pt && pt<30)
      scale_factor =  0.9962507570772984;
    if( 30<pt && pt<40)
      scale_factor =  0.996392108068774;
    if( 40<pt && pt<50)
      scale_factor =  0.997206600017751;
    if( 50<pt && pt<60)
      scale_factor =  0.997625740209688;
    if( 60<pt && pt<120)
      scale_factor =  0.9983301686184624;
    if( 120<pt && pt<3000)
      scale_factor =  0.998913825655372;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.975903126163201;
    if( 20<pt && pt<25)
      scale_factor =  0.9758926331791644;
    if( 25<pt && pt<30)
      scale_factor =  0.9762525132065444;
    if( 30<pt && pt<40)
      scale_factor =  0.976563956600619;
    if( 40<pt && pt<50)
      scale_factor =  0.9728680088005566;
    if( 50<pt && pt<60)
      scale_factor =  0.973487965949456;
    if( 60<pt && pt<120)
      scale_factor =  0.9705748257028004;
    if( 120<pt && pt<3000)
      scale_factor =  0.9981302659996446;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2023
double AnaScript::getScaleFactors_Muons_ISO_Run3Summer23(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  1.0319460820757302;
    if( 20<pt && pt<25)
      scale_factor =  1.018370622435032;
    if( 25<pt && pt<30)
      scale_factor =  1.0095551861305785;
    if( 30<pt && pt<40)
      scale_factor =  1.0080055259968503;
    if( 40<pt && pt<50)
      scale_factor =  1.0037600878153188;
    if( 50<pt && pt<60)
      scale_factor =  1.0015660688885548;
    if( 60<pt && pt<120)
      scale_factor =  1.0001468063171517;
    if( 120<pt && pt<3000)
      scale_factor =  0.9990308897805584;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  1.0363080972075862;
    if( 20<pt && pt<25)
      scale_factor =  1.0313698194345875;
    if( 25<pt && pt<30)
      scale_factor =  1.0262527749638917;
    if( 30<pt && pt<40)
      scale_factor =  1.0112429418940148;
    if( 40<pt && pt<50)
      scale_factor =  1.005017695837449;
    if( 50<pt && pt<60)
      scale_factor =  1.0022299262256087;
    if( 60<pt && pt<120)
      scale_factor =  1.0013632777288042;
    if( 120<pt && pt<3000)
      scale_factor =  1.0065277259957432;
  }
  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  1.0475553575865797;
    if( 20<pt && pt<25)
      scale_factor =  1.0298032506528774;
    if( 25<pt && pt<30)
      scale_factor =  1.0273714929915398;
    if( 30<pt && pt<40)
      scale_factor =  1.0135474295530489;
    if( 40<pt && pt<50)
      scale_factor =  1.0054951747136485;
    if( 50<pt && pt<60)
      scale_factor =  1.0016025156146455;
    if( 60<pt && pt<120)
      scale_factor =  0.9992974210721624;
    if( 120<pt && pt<3000)
      scale_factor =  1.0083744962546473;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  1.0294116198778689;
    if( 20<pt && pt<25)
      scale_factor =  1.0232862291454037;
    if( 25<pt && pt<30)
      scale_factor =  1.0163674973328412;
    if( 30<pt && pt<40)
      scale_factor =  1.009485485231278;
    if( 40<pt && pt<50)
      scale_factor =  1.0041472181663125;
    if( 50<pt && pt<60)
      scale_factor =  1.0010059988097677;
    if( 60<pt && pt<120)
      scale_factor =  1.002631621605045;
    if( 120<pt && pt<3000)
      scale_factor =  1.0045489386611235;
  }
  return scale_factor;
}

