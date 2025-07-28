//Reco Scale Factors(Electrons): 2023BPix
double AnaScript::getScaleFactors_Electrons_Reco_Run3Summer23BPix(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-5.0<eta && eta<-1.566) 
      scale_factor = 0.9830318093299866;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.88045734167099;
    if(-1.444<eta && eta<0.0) 
      scale_factor = 0.936859965324402;
    if(0.0<eta && eta<1.444) 
      scale_factor = 0.936859965324402;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.88045734167099;
    if(1.566<eta && eta<5.0) 
      scale_factor = 0.9830318093299866;
  }
  if(20<pt && pt<45){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9859724640846252;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9872605800628662;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9859594106674194;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.98576021194458;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9899689555168152;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9811012148857116;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9802803993225098;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9871419072151184;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9866459369659424;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.969846487045288;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9871737360954284;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9812944531440736;
  }
    
  if(45<pt && pt<75){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9789695739746094;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9880531430244446;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9512194991111756;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9850122928619384;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9920988082885742;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9825088381767272;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9855627417564392;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9909089207649232;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9831142425537108;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9619876146316528;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9871301054954528;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.9763807654380798;
  }

  if(75<pt && pt<100){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 0.9766610860824584;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9965050220489502;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 0.9856089949607848;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9930408596992492;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 1.0023562908172607;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.9830819964408876;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.9946765899658204;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9991899132728576;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9866015911102296;
    if(1.444<eta && eta<1.566) 
      scale_factor = 0.9133431315422058;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9761082530021667;
    if(2.0<eta && eta<5.0) 
      scale_factor = 1.0020817518234253;
  }
  if(100<pt && pt<1000){
    if(-5.0<eta && eta<-2.1) 
      scale_factor = 1.0058331489562988;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.976474106311798;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0180515050888062;
    if(-1.444<eta && eta<-1.0) 
      scale_factor = 0.9725404381752014;
    if(-1.0<eta && eta<-0.5) 
      scale_factor = 0.9725217819213868;
    if(-0.5<eta && eta<0.0) 
      scale_factor = 0.973000168800354;
    if(0.0<eta && eta<0.5) 
      scale_factor = 0.998676896095276;
    if(0.5<eta && eta<1.0) 
      scale_factor = 0.9836124777793884;
    if(1.0<eta && eta<1.444) 
      scale_factor = 0.9842883348464966;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.067878246307373;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0008312463760376;
    if(2.0<eta && eta<5.0) 
      scale_factor = 0.8911266922950745;
  }
  return scale_factor;
}

//IDIso Scale Factors(Electrons): 2023BPix
double AnaScript::getScaleFactors_Electrons_IDIso_Run3Summer23BPix(float eta, float pt){
  double scale_factor = 1.0;
  
  if(10<pt && pt<20){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0657953023910522;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.0590742826461792;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.321366548538208;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.1440956592559814;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.0516879558563232;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.0666395425796509;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.121354341506958;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.3599563837051392;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0721850395202637;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.082150101661682;
  }

  if(20<pt && pt<35){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0225098133087158;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.006280541419983;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.060415267944336;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0669004917144775;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.0238410234451294;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.0240023136138916;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.051579833030701;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0399434566497805;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9996089935302734;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0165655612945557;
  }

  if(35<pt && pt<50){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0049782991409302;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9785689115524292;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0523377656936646;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0314241647720337;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.007158279418945;
    if(0.0<eta && eta<0.8) 
      scale_factor = 1.004800796508789;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0253825187683103;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.039756417274475;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.9843441247940063;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0033693313598633;
  }

  if(50<pt && pt<100){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 0.9946956038475036;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 0.9729434251785278;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0580912828445437;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.0104994773864746;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 0.9917070865631104;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9968529343605042;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0077332258224487;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.029884696006775;
    if(1.566<eta && eta<2.0) 
      scale_factor = 0.970619797706604;
    if(2.0<eta && eta<2.4) 
      scale_factor = 0.9895769953727722;
  }

  if(100<pt && pt<1000){
    if(-2.4<eta && eta<-2.1) 
      scale_factor = 1.0277438163757324;
    if(-2.1<eta && eta<-1.566) 
      scale_factor = 1.023235321044922;
    if(-1.566<eta && eta<-1.444) 
      scale_factor = 1.0960993766784668;
    if(-1.444<eta && eta<-0.8) 
      scale_factor = 1.024950623512268;
    if(-0.8<eta && eta<0.0) 
      scale_factor = 1.0016549825668335;
    if(0.0<eta && eta<0.8) 
      scale_factor = 0.9954872727394104;
    if(0.8<eta && eta<1.444) 
      scale_factor = 1.0171668529510498;
    if(1.444<eta && eta<1.566) 
      scale_factor = 1.0634411573410034;
    if(1.566<eta && eta<2.0) 
      scale_factor = 1.0252838134765625;
    if(2.0<eta && eta<2.4) 
      scale_factor = 1.0166937112808228;
  }
  return scale_factor;
}

//RecoScaleFactors(Muons): 2023BPix
double AnaScript::getScaleFactors_Muons_HLT_Run3Summer23BPix(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 25<pt && pt<30)
      scale_factor =  0.9586828908621908;
    if( 30<pt && pt<40)
      scale_factor =  0.9688992737864444;
    if( 40<pt && pt<50)
      scale_factor =  0.9696618619299242;
    if( 50<pt && pt<60)
      scale_factor =  0.9695587775819332;
    if( 60<pt && pt<120)
      scale_factor =  0.9661620712996752;
    if( 120<pt && pt<3000)
      scale_factor =  0.966990260124626;
    
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 25<pt && pt<30)
      scale_factor =  0.9830556427973624;
    if( 30<pt && pt<40)
      scale_factor =  0.9815682279459572;
    if( 40<pt && pt<50)
      scale_factor =  0.9802722628941593;
    if( 50<pt && pt<60)
      scale_factor =  0.977726555443316;
    if( 60<pt && pt<120)
      scale_factor =  0.9791430737541454;
    if( 120<pt && pt<3000)
      scale_factor =  0.9748122903849278;
  }

  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 25<pt && pt<30)
      scale_factor =  0.9972975779257603;
    if( 30<pt && pt<40)
      scale_factor =  1.0030381428659876;
    if( 40<pt && pt<50)
      scale_factor =  1.0041629139430177;
    if( 50<pt && pt<60)
      scale_factor =  1.0039300025511475;
    if( 60<pt && pt<120)
      scale_factor =  1.0001833957220754;
    if( 120<pt && pt<3000)
      scale_factor =  1.0192471256379996;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 25<pt && pt<30)
      scale_factor =  0.9784139491391168;
    if( 30<pt && pt<40)
      scale_factor =  0.9958784039263592;
    if( 40<pt && pt<50)
      scale_factor =  1.0038266851996531;
    if( 50<pt && pt<60)
      scale_factor =  1.0056227429693765;
    if( 60<pt && pt<120)
      scale_factor =  1.0094250560599738;
    if( 120<pt && pt<3000)
      scale_factor =  1.0874524823019684;
  }
  return scale_factor;
}

//IDScaleFactors(Muons): 2023BPix
double AnaScript::getScaleFactors_Muons_ID_Run3Summer23BPix(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  0.997966103846451;
    if( 20<pt && pt<25)
      scale_factor =  0.9968809384348912;
    if( 25<pt && pt<30)
      scale_factor =  0.9983328563707634;
    if( 30<pt && pt<40)
      scale_factor =  0.9985253518805228;
    if( 40<pt && pt<50)
      scale_factor =  0.9984500190985436;
    if( 50<pt && pt<60)
      scale_factor =  0.997936191963492;
    if( 60<pt && pt<120)
      scale_factor =  0.9984822510738008;
    if( 120<pt && pt<3000)
      scale_factor =  1.0014186217688412;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  0.9920608672513654;
    if( 20<pt && pt<25)
      scale_factor =  0.994258958427092;
    if( 25<pt && pt<30)
      scale_factor =  0.993884180407214;
    if( 30<pt && pt<40)
      scale_factor =  0.9942172532954237;
    if( 40<pt && pt<50)
      scale_factor =  0.9945501868196348;
    if( 50<pt && pt<60)
      scale_factor =  0.9958025036640372;
    if( 60<pt && pt<120)
      scale_factor =  0.9954509252766208;
    if( 120<pt && pt<3000)
      scale_factor =  0.9928085138456164;
  }

  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  0.9956276019136722;
    if( 20<pt && pt<25)
      scale_factor =  0.9962787340987264;
    if( 25<pt && pt<30)
      scale_factor =  0.997668077149066;
    if( 30<pt && pt<40)
      scale_factor =  0.9967093483463376;
    if( 40<pt && pt<50)
      scale_factor =  0.9977351883409028;
    if( 50<pt && pt<60)
      scale_factor =  0.9979100798988616;
    if( 60<pt && pt<120)
      scale_factor =  0.9985187756390292;
    if( 120<pt && pt<3000)
      scale_factor =  0.9989702538592972;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  0.9962208586736618;
    if( 20<pt && pt<25)
      scale_factor =  0.9936886272306616;
    if( 25<pt && pt<30)
      scale_factor =  0.990316368674978;
    if( 30<pt && pt<40)
      scale_factor =  0.9888106736289638;
    if( 40<pt && pt<50)
      scale_factor =  0.990189857507642;
    if( 50<pt && pt<60)
      scale_factor =  0.9874356453231444;
    if( 60<pt && pt<120)
      scale_factor =  0.9912491070745968;
    if( 120<pt && pt<3000)
      scale_factor =  1.0147672509521397;
  }
  return scale_factor;
}

//IsoScaleFactors(Muons): 2023BPix
double AnaScript::getScaleFactors_Muons_ISO_Run3Summer23BPix(float eta, float pt){
  double scale_factor=1.0;

  if(fabs(eta)<0.9){
    if( 15<pt && pt<20)
      scale_factor =  1.025841530055183;
    if( 20<pt && pt<25)
      scale_factor =  1.0309752222394208;
    if( 25<pt && pt<30)
      scale_factor =  1.0253903852983526;
    if( 30<pt && pt<40)
      scale_factor =  1.012716552425318;
    if( 40<pt && pt<50)
      scale_factor =  1.0061545249216477;
    if( 50<pt && pt<60)
      scale_factor =  1.0030274833251729;
    if( 60<pt && pt<120)
      scale_factor =  1.0025382373978675;
    if( 120<pt && pt<3000)
      scale_factor =  1.0005886676303712;
  }
  
  else if(0.9<fabs(eta) && fabs(eta)<1.2){
    if( 15<pt && pt<20)
      scale_factor =  1.0576134825221837;
    if( 20<pt && pt<25)
      scale_factor =  1.0461756172190837;
    if( 25<pt && pt<30)
      scale_factor =  1.0391740840224364;
    if( 30<pt && pt<40)
      scale_factor =  1.0184114366113863;
    if( 40<pt && pt<50)
      scale_factor =  1.008911730278425;
    if( 50<pt && pt<60)
      scale_factor =  1.0039071065506755;
    if( 60<pt && pt<120)
      scale_factor =  1.002235651155891;
    if( 120<pt && pt<3000)
      scale_factor =  1.008696709590277;
  }
  
  else if(1.2<fabs(eta) && fabs(eta)<2.1){
    if( 15<pt && pt<20)
      scale_factor =  1.043603942117105;
    if( 20<pt && pt<25)
      scale_factor =  1.034565775211587;
    if( 25<pt && pt<30)
      scale_factor =  1.0242540755427034;
    if( 30<pt && pt<40)
      scale_factor =  1.012143661373752;
    if( 40<pt && pt<50)
      scale_factor =  1.0051016706940872;
    if( 50<pt && pt<60)
      scale_factor =  1.0022817547455898;
    if( 60<pt && pt<120)
      scale_factor =  0.999894370944025;
    if( 120<pt && pt<3000)
      scale_factor =  1.005933395805835;
  }
  
  else if(2.1<fabs(eta) && fabs(eta)<2.4){
    if( 15<pt && pt<20)
      scale_factor =  1.0282193421225891;
    if( 20<pt && pt<25)
      scale_factor =  1.0306593198654923;
    if( 25<pt && pt<30)
      scale_factor =  1.01308211678879;
    if( 30<pt && pt<40)
      scale_factor =  1.010862262820016;
    if( 40<pt && pt<50)
      scale_factor =  1.0046079336311822;
    if( 50<pt && pt<60)
      scale_factor =  1.0031440117393635;
    if( 60<pt && pt<120)
      scale_factor =  1.0021064375024418;
    if( 120<pt && pt<3000)
      scale_factor =  1.0071798393602067;
  }
  return scale_factor;
}

