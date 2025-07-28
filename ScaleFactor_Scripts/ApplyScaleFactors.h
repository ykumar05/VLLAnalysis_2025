double AnaScript::LeptonID_SFRun3Summer22(int id, float pt, float eta)
{
  float SF = 1.0;

  if(fabs(id)==13)
    SF = getScaleFactors_Muons_HLT_Run3Summer22(eta,pt)*getScaleFactors_Muons_ID_Run3Summer22(eta,pt)*getScaleFactors_Muons_ISO_Run3Summer22(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_Run3Summer22(eta,pt)*getScaleFactors_Electrons_IDIso_Run3Summer22(eta,pt);

  return SF;
}

double AnaScript::LeptonID_SFRun3Summer22EE(int id, float pt, float eta)
{
  float SF = 1.0;

  if(fabs(id)==13)
    SF = getScaleFactors_Muons_HLT_Run3Summer22EE(eta,pt)*getScaleFactors_Muons_ID_Run3Summer22EE(eta,pt)*getScaleFactors_Muons_ISO_Run3Summer22EE(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_Run3Summer22EE(eta,pt)*getScaleFactors_Electrons_IDIso_Run3Summer22EE(eta,pt);

  return SF;
}

double AnaScript::LeptonID_SFRun3Summer23(int id, float pt, float eta)
{
  float SF = 1.0;

  if(fabs(id)==13)
    SF = getScaleFactors_Muons_HLT_Run3Summer23(eta,pt)*getScaleFactors_Muons_ID_Run3Summer23(eta,pt)*getScaleFactors_Muons_ISO_Run3Summer23(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_Run3Summer23(eta,pt)*getScaleFactors_Electrons_IDIso_Run3Summer23(eta,pt);

  return SF;
}

double AnaScript::LeptonID_SFRun3Summer23BPix(int id, float pt, float eta)
{
  float SF = 1.0;

  if(fabs(id)==13)
    SF = getScaleFactors_Muons_HLT_Run3Summer23BPix(eta,pt)*getScaleFactors_Muons_ID_Run3Summer23BPix(eta,pt)*getScaleFactors_Muons_ISO_Run3Summer23BPix(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_Run3Summer23BPix(eta,pt)*getScaleFactors_Electrons_IDIso_Run3Summer23BPix(eta,pt);

  return SF;
}

double AnaScript::LeptonID_SFUL18(int id, float pt, float eta)
{
  float SF = 1.0;

  if(fabs(id)==13)
    SF = getScaleFactors_Muons_Reco_UL18(eta,pt)*getScaleFactors_Muons_ID_UL18(eta,pt)*getScaleFactors_Muons_ISO_UL18(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_UL18(eta,pt)*getScaleFactors_Electrons_IDIso_UL18(eta,pt);

  return SF;
}

double AnaScript::LeptonID_SFUL17(int id, float pt, float eta)
{
  float SF = 1.0;
  if(fabs(id)==13)
    SF = getScaleFactors_Muons_Reco_UL17(eta,pt)*getScaleFactors_Muons_ID_UL17(eta,pt)*getScaleFactors_Muons_ISO_UL17(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_UL17(eta,pt)*getScaleFactors_Electrons_IDIso_UL17(eta,pt);
  
  return SF;
}

double AnaScript::LeptonID_SFUL16preVFP(int id, float pt, float eta)
{
  float SF = 1.0;
  if(fabs(id)==13)
    SF = getScaleFactors_Muons_Reco_UL16preVFP(eta,pt)*getScaleFactors_Muons_ID_UL16preVFP(eta,pt)*getScaleFactors_Muons_ISO_UL16preVFP(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_UL16preVFP(eta,pt)*getScaleFactors_Electrons_IDIso_UL16preVFP(eta,pt);
  
  return SF;
}

double AnaScript::LeptonID_SFUL16postVFP(int id, float pt, float eta)
{
  float SF = 1.0;
  if(fabs(id)==13)
    SF = getScaleFactors_Muons_Reco_UL16postVFP(eta,pt)*getScaleFactors_Muons_ID_UL16postVFP(eta,pt)*getScaleFactors_Muons_ISO_UL16postVFP(eta, pt);
  if(fabs(id)==11)
    SF = getScaleFactors_Electrons_Reco_UL16postVFP(eta,pt)*getScaleFactors_Electrons_IDIso_UL16postVFP(eta,pt);
  
  return SF;
}

double AnaScript::ZpTFactor_DY_Muons(int MCSample, TLorentzVector v1, TLorentzVector v2){
  float ZpTFactor = 1.0;
  float ZpT = (v1+v2).Pt();
  if(_year == 2018){
    if(MCSample == 1 || MCSample == 2){
      if(ZpT < 5.0)                    ZpTFactor = 1.00283;
      if(5.0 < ZpT && ZpT < 10.0)      ZpTFactor = 1.21282; 
      if(10.0 < ZpT && ZpT < 15.0)     ZpTFactor = 1.26239; 
      if(15.0 < ZpT && ZpT < 20.0)     ZpTFactor = 1.19069; 
      if(20.0 < ZpT && ZpT < 25.0)     ZpTFactor = 1.07375; 
      if(25.0 < ZpT && ZpT < 30.0)     ZpTFactor = 0.92362; 
      if(30.0 < ZpT && ZpT < 40.0)     ZpTFactor = 0.738894; 
      if(40.0 < ZpT && ZpT < 60.0)     ZpTFactor = 0.630054; 
      if(60.0 < ZpT && ZpT < 80.0)     ZpTFactor = 0.591653; 
      if(80.0 < ZpT && ZpT < 100.0)    ZpTFactor = 0.570698; 
      if(100.0 < ZpT && ZpT < 150.0)   ZpTFactor = 0.553823; 
      if(150.0 < ZpT && ZpT < 200.0)   ZpTFactor = 0.542404; 
      if(200.0 < ZpT && ZpT < 250.0)   ZpTFactor = 0.53019; 
      if(250.0 < ZpT && ZpT < 300.0)   ZpTFactor = 0.52336; 
      if(300.0 < ZpT && ZpT < 350.0)   ZpTFactor = 0.527187; 
      if(350.0 < ZpT && ZpT < 400.0)   ZpTFactor = 0.529945; 
      if(400.0 < ZpT && ZpT < 450.0)   ZpTFactor = 0.492612; 
      if(450.0 < ZpT && ZpT < 500.0)   ZpTFactor = 0.507665; 
      if(500.0 < ZpT && ZpT < 600.0)   ZpTFactor = 0.482947; 
      if(600.0 < ZpT && ZpT < 700.0)   ZpTFactor = 0.512503; 
      if(700.0 < ZpT && ZpT < 800.0)   ZpTFactor = 0.459673; 
      if(800.0 < ZpT && ZpT < 900.0)   ZpTFactor = 0.433278; 
      if(900.0 < ZpT && ZpT < 1000.0)  ZpTFactor = 0.415236; 
      if(1000.0 < ZpT && ZpT < 1200.0) ZpTFactor = 0.272256; 
      if(1200.0 < ZpT)                 ZpTFactor = 0.152759; 
    }
  }
  return ZpTFactor;
}

double AnaScript::ZpTFactor_DY_Electrons(int MCSample, TLorentzVector v1, TLorentzVector v2){
  float ZpTFactor = 1.0;
  float ZpT = (v1+v2).Pt();
  if(_year == 2018){
    if(MCSample == 1 || MCSample == 2){
      if(ZpT < 5.0)                    ZpTFactor = 0.895085;
      if(5.0 < ZpT && ZpT < 10.0)      ZpTFactor = 1.0612; 
      if(10.0 < ZpT && ZpT < 15.0)     ZpTFactor = 1.10657; 
      if(15.0 < ZpT && ZpT < 20.0)     ZpTFactor = 1.03777; 
      if(20.0 < ZpT && ZpT < 25.0)     ZpTFactor = 0.924527; 
      if(25.0 < ZpT && ZpT < 30.0)     ZpTFactor = 0.791256; 
      if(30.0 < ZpT && ZpT < 40.0)     ZpTFactor = 0.628439; 
      if(40.0 < ZpT && ZpT < 60.0)     ZpTFactor = 0.535384; 
      if(60.0 < ZpT && ZpT < 80.0)     ZpTFactor = 0.50621; 
      if(80.0 < ZpT && ZpT < 100.0)    ZpTFactor = 0.492904; 
      if(100.0 < ZpT && ZpT < 150.0)   ZpTFactor = 0.48052; 
      if(150.0 < ZpT && ZpT < 200.0)   ZpTFactor = 0.47421; 
      if(200.0 < ZpT && ZpT < 250.0)   ZpTFactor = 0.468038; 
      if(250.0 < ZpT && ZpT < 300.0)   ZpTFactor = 0.449338; 
      if(300.0 < ZpT && ZpT < 350.0)   ZpTFactor = 0.453328; 
      if(350.0 < ZpT && ZpT < 400.0)   ZpTFactor = 0.456985; 
      if(400.0 < ZpT && ZpT < 450.0)   ZpTFactor = 0.442061; 
      if(450.0 < ZpT && ZpT < 500.0)   ZpTFactor = 0.428254; 
      if(500.0 < ZpT && ZpT < 600.0)   ZpTFactor = 0.445792; 
      if(600.0 < ZpT && ZpT < 700.0)   ZpTFactor = 0.279951; 
      if(700.0 < ZpT && ZpT < 800.0)   ZpTFactor = 0.19506; 
      if(800.0 < ZpT && ZpT < 900.0)   ZpTFactor = 0.141101; 
      if(900.0 < ZpT && ZpT < 1000.0)  ZpTFactor = 0.055857; 
      if(1000.0 < ZpT && ZpT < 1200.0) ZpTFactor = 0.00736301; 
      if(1200.0 < ZpT)                 ZpTFactor = -0.068792; 
    }
  }
  return ZpTFactor;
}

double AnaScript::JetReWeighting_DY_Muons(int MCSample, vector<Particle>Jets){
  float JetReWeightingFactor = 1.0;

  if(_year == 2018){
    if(MCSample == 1 || MCSample == 2){
      if((int)Jets.size() == 0)
	JetReWeightingFactor = 1.04877;
      if((int)Jets.size() == 1)
	JetReWeightingFactor = 0.875437;
      if((int)Jets.size() == 2)
	JetReWeightingFactor = 0.712172;
      if((int)Jets.size() == 3)
	JetReWeightingFactor = 0.890771;
      if((int)Jets.size() == 4)
	JetReWeightingFactor = 1.18533;
      if((int)Jets.size() == 5 )
	JetReWeightingFactor = 1.47504;
      if((int)Jets.size() == 6 )
	JetReWeightingFactor = 1.9027;
      if((int)Jets.size() == 7 )
	JetReWeightingFactor = 2.03457;
      if((int)Jets.size() == 8 )
	JetReWeightingFactor = 2.44892;
      if((int)Jets.size() > 8 )
	JetReWeightingFactor = 3.32613;
    }
  }
  return JetReWeightingFactor;
}

double AnaScript::JetReWeighting_DY_Electrons(int MCSample, vector<Particle>Jets){
  float JetReWeightingFactor = 1.0;

  if(_year == 2018){
    if(MCSample == 1 || MCSample == 2){
      if((int)Jets.size() == 0)
	JetReWeightingFactor = 1.05696;
      if((int)Jets.size() == 1)
	JetReWeightingFactor = 0.871122;
      if((int)Jets.size() == 2)
	JetReWeightingFactor = 0.706361;
      if((int)Jets.size() == 3)
	JetReWeightingFactor = 0.866409;
      if((int)Jets.size() == 4)
	JetReWeightingFactor = 1.12701;
      if((int)Jets.size() == 5 )
	JetReWeightingFactor = 1.3936;
      if((int)Jets.size() == 6 )
	JetReWeightingFactor = 1.76994;
      if((int)Jets.size() == 7 )
	JetReWeightingFactor = 1.80327;
      if((int)Jets.size() == 8 )
	JetReWeightingFactor = 2.53967;
      if((int)Jets.size() > 8 )
	JetReWeightingFactor = 1.79033;
    }
  }
  return JetReWeightingFactor;
}


