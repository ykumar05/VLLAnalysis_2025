#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

void anaCond_Run3( TString ifname , TString ofname, TString data, TString year, TString lep, TString era, TString MC, TString flag)
{
  gROOT->Time();  
  const char *hstfilename;
  TChain *chain = new TChain("Events");
  AnaScript m_selec;
  TString input = ifname;
  bool manual = input.EndsWith(".root");
  bool single=false;
  if(!manual) {
    input += "/*.root";
  }
  chain->Add(input);	
  hstfilename = ofname;  
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetVerbose(1);

  //Checking whether it is MC or Data
  if(data=="0")
    m_selec.SetData(0); 
  if(data=="1")
    m_selec.SetData(1); 

  //Setting the year
  if(year=="2022")
    m_selec.SetYear(2022);
  if(year=="2023")
    m_selec.SetYear(2023);
  if(year=="3022")
    m_selec.SetYear(3022);
  if(year=="3023")
    m_selec.SetYear(3023);
  if(year=="2018")
    m_selec.SetYear(2018);
  if(year=="2017")
    m_selec.SetYear(2017);
  if(year=="2016")
    m_selec.SetYear(2016);
  if(year=="3016")
    m_selec.SetYear(3016);

  //Setting the era
  m_selec.SetEra(era);

  //Setting whether it is SingleMuon or Single Electron
  if(lep=="el")
    m_selec.SetLep(0);
  if(lep=="mu")
    m_selec.SetLep(1);

  //cout<<"Set the options"<<endl;
  if(data=="0"){
    int _sample = -1;
    TString _flag = ""; 
    
    //DYJetsToLL
    if(MC=="DYJetsToLL_M10to50"){
      _sample = 1;
      _flag= "DY";
    }
    if(MC=="DYJetsToLL_M50"){
      _sample = 2;
      _flag = "DY";
    }
    
    //Rare
    if(MC=="Rare_THQ"){
      _sample = 10;
      _flag= "rare";
    }
    if(MC=="Rare_THW"){
      _sample = 11;
      _flag= "rare";
    }
    if(MC=="Rare_TTTT"){
      _sample = 12;
      _flag= "rare";
    }
    if(MC=="Rare_TTWH"){
      _sample = 13;
      _flag= "rare";
    }
    if(MC=="Rare_TTWW"){
      _sample = 14;
      _flag= "rare";
    }
    if(MC=="Rare_TTWZ"){
      _sample = 15;
      _flag= "rare";
    }
    if(MC=="Rare_TTZH"){
      _sample = 16;
      _flag= "rare";
    }
    if(MC=="Rare_TTZZ"){
      _sample = 17;
      _flag= "rare";
    }
    
    //ZZ
    if(MC=="ZZ_ZZTo2Q2L"){
      _sample = 20;
      _flag = "zz";
    }
    if(MC=="ZZ_ZZTo2Q2Nu"){
      _sample = 21;
      _flag = "zz";
    }
    if(MC=="ZZ_ZZTo4L"){
      _sample = 22;
      _flag = "zz";
    }
    if(MC=="ZZ_ZZTo2L2Nu"){
      _sample = 23;
      _flag = "zz";
    }
    if(MC=="ZZ_GluGluToContinToZZTo4e"){
      _sample = 24;
      _flag = "zz";
    }
    if(MC=="ZZ_GluGluToContinToZZTo4mu"){
      _sample = 25;
      _flag = "zz";
    }
    if(MC=="ZZ_GluGluToContinToZZTo2e2mu"){
      _sample = 26;
      _flag = "zz";
    }
    
    //WZ
    if(MC=="WZ_WZTo2Q2L"){
      _sample = 30;
      _flag = "wz";
    }
    if(MC=="WZ_WZTo3LNu"){
      _sample = 31;
      _flag = "wz";
    }
    if(MC=="WZ_WZTo1L1Nu2Q"){
      _sample = 32;
      _flag = "wz";
    }
    
    //WW
    if(MC=="WW_WWTo1L1Nu2Q"){
      _sample = 40;
      _flag = "ww";
    }
    if(MC=="WW_WWTo2L2Nu"){
      _sample = 41;
      _flag = "ww";
    }

    //Single Top
    /*if(MC=="SingleTop_TBbarQ_t-channel"){
      _sample = 50;
      _flag = "st";
      }
      if(MC=="SingleTop_TBbartoLplusNuBbar-s-channel"){
      _sample = 51;
      _flag = "st";
      }
      if(MC=="SingleTop_TQbarto2Q-t-channel"){
      _sample = 52;
      _flag = "st";
      }
      if(MC=="SingleTop_TQbartoLNu-t-channel"){
      _sample = 53;
      _flag = "st";
      }
      if(MC=="SingleTop_TbarBQ_t-channel"){
      _sample = 54;
      _flag = "st";
      }
      if(MC=="SingleTop_TbarBtoLminusNuB-s-channel"){
      _sample = 55;
      _flag = "st";
      }
      if(MC=="SingleTop_TbarQto2Q-t-channel"){
      _sample = 56;
      _flag = "st";
      }
      if(MC=="SingleTop_TbarQtoLNu-t-channel"){
      _sample = 57;
      _flag = "st";
      }
      if(MC=="SingleTop_TWminusto2L2Nu"){
      _sample = 58;
      _flag = "st";
      }
      if(MC=="SingleTop_TWminustoLNu2Q"){
      _sample = 59;
      _flag = "st";
      }
      if(MC=="SingleTop_TbarWplusto2L2Nu"){
      _sample = 590;
      _flag = "st";
      }
      if(MC=="SingleTop_TbarWplustoLNu2Q"){
      _sample = 591;
      _flag = "st";
      }*/

    //Single Top
    if(MC=="SingleTop_t-channel_Top"){
      _sample = 50;
      _flag = "st";
    }
    if(MC=="SingleTop_t-channel_AntiTop"){
      _sample = 51;
      _flag = "st";
    }
    if(MC=="SingleTop_s-channel_LeptonDecays"){ 
      _sample = 52;
      _flag = "st";
    }
    if(MC=="SingleTop_tW_AntiTop"){
      _sample = 53;
      _flag = "st";
    }
    if(MC=="SingleTop_tW_Top"){
      _sample = 54;
      _flag = "st";
    }

    //TTbar
    if(MC=="TTBar_TTTo2L2Nu"){
      _sample = 60;
      _flag = "ttbar";
    }
    if(MC=="TTBar_TTToLNu2Q"){
      _sample = 61;
      _flag = "ttbar";
    }
    
    //TTZ
    if(MC=="TTZ_TTZToLL"){
      _sample = 80;
      _flag = "ttz";
    }

    //TTW
    if(MC=="TTW_TTWToLNu"){
      _sample = 81;
      _flag = "ttw";
    }

    //TTZ_MLL-4to50
    if(MC=="TTZ_TTLL_MLL-4to50"){
      _sample = 82;
      _flag = "ttz";
    }

    //TTZ_MLL-50
    if(MC=="TTZ_TTLL_MLL-50"){
      _sample = 83;
      _flag = "ttz";
    }

    //WWW
    if(MC=="WWW_Inclusive"){
      _sample = 90;
      _flag = "www";
    }

    //WWZ
    if(MC=="WWZ_Inclusive"){
      _sample = 91;
      _flag = "wwz";
    }

    //WZZ
    if(MC=="WZZ_Inclusive"){
      _sample = 92;
      _flag = "wzz";
    }

    //ZZZ
    if(MC=="ZZZ_Inclusive"){
      _sample = 93;
      _flag = "zzz";
    }

    //ZGamma
    if(MC=="ZGamma_ZGToLLG_01J"){
      _sample = 94;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-4to50_PTG-10to100"){
      _sample = 940;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-4to50_PTG-100to200"){
      _sample = 941;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-4to50_PTG-200"){
      _sample = 942;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-50_PTG-10to50"){
      _sample = 943;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-50_PTG-50to100"){
      _sample = 944;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-50_PTG-100to200"){
      _sample = 945;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-50_PTG-200to400"){
      _sample = 946;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-50_PTG-400to600"){
      _sample = 947;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-50_PTG-600"){
      _sample = 948;
      _flag = "zgamma";
    }
    if(MC=="ZGamma_MLL-50_PTG-10to100"){
      _sample = 949;
      _flag = "zgamma";
    }

    //Higgs
    /*if(MC=="Higgs_GluGluHtoZZ"){
      _sample = 100;
      _flag = "higgs";
      }
      if(MC=="Higgs_VBFHto2Z"){
      _sample = 101;
      _flag = "higgs";
      }
      if(MC=="Higgs_WminusH_Hto2Z"){
      _sample = 102;
      _flag = "higgs";
      }
      if(MC=="Higgs_WplusH_Hto2Z"){
      _sample = 103;
      _flag = "higgs";
      }
      if(MC=="Higgs_TTH_Hto2B"){
      _sample = 104;
      _flag = "higgs";
      }
      if(MC=="Higgs_TTH_Hto2Mu"){
      _sample = 105;
      _flag = "higgs";
      }
      if(MC=="Higgs_TTH_Hto2Z"){
      _sample = 106;
      _flag = "higgs";
      }
      if(MC=="Higgs_GluGluZH"){
      _sample = 107;
      _flag = "higgs";
      }*/
    
    if(MC=="Higgs_bbH_HToZZTo4L"){
      _sample = 100;
      _flag = "higgs";
    }
    if(MC=="Higgs_GluGluHToZZTo4L"){
      _sample = 101;
      _flag = "higgs";
    }
    if(MC=="Higgs_GluGluToZH_HToZZTo4L"){
      _sample = 102;
      _flag = "higgs";
    }
    if(MC=="Higgs_GluGluZH_HToWW_ZTo2L"){
      _sample = 103;
      _flag = "higgs";
    }
    if(MC=="Higgs_ttHToNonbb"){
      _sample = 104;
      _flag = "higgs";
    }
    if(MC=="Higgs_VBF_HToZZTo4L"){
      _sample = 105;
      _flag = "higgs";
    }
    if(MC=="Higgs_VHToNonbb"){
      _sample = 106;
      _flag = "higgs";
    }

    m_selec.SetSample(_sample);
    m_selec.SetFlag(_flag);
  }
  
  if(data == "1"){
    int _sample = -1;
    TString _flag = ""; 
    
    //SampleNumbering: Data
    if(year == "2017"){
      if(MC=="SingleMuon_SingleMuon_B"){
	_sample = 1000;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_C"){
	_sample = 1001;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_D"){
	_sample = 1002;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_E"){
	_sample = 1003;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_F"){
	_sample = 1004;
	_flag = "singlemuon";
      }
      if(MC=="EGamma_EGamma_B"){
	_sample = 1100;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_C"){
	_sample = 1101;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_D"){
	_sample = 1102;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_E"){
	_sample = 1103;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_F"){
	_sample = 1104;
	_flag = "egamma";
      }
    }  

    if(year == "2018"){
      if(MC=="SingleMuon_SingleMuon_A"){
	_sample = 1000;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_B"){
	_sample = 1001;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_C"){
	_sample = 1002;
	_flag = "singlemuon";
      }
      if(MC=="SingleMuon_SingleMuon_D"){
	_sample = 1003;
	_flag = "singlemuon";
      }
      if(MC=="EGamma_EGamma_A"){
	_sample = 1100;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_B"){
	_sample = 1101;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_C"){
	_sample = 1102;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_D"){
	_sample = 1103;
	_flag = "egamma";
      }
    }  
    
    if(year == "2022"){
      if(MC=="SingleMuon_Muon_C"){
	_sample = 1002;
	_flag = "singlemuon";
      }
      if(MC=="Muon_Muon_D"){
	_sample = 1003;
	_flag = "singlemuon";
      }
      if(MC=="EGamma_EGamma_C"){
	_sample = 1102;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_D"){
	_sample = 1103;
	_flag = "egamma";
      }
    }  

    if(year == "3022"){
      if(MC=="Muon_Muon_E"){
	_sample = 1002;
	_flag = "singlemuon";
      }
      if(MC=="Muon_Muon_F"){
	_sample = 1003;
	_flag = "singlemuon";
      }
      if(MC=="Muon_Muon_G"){
	_sample = 1004;
	_flag = "singlemuon";
      }
      if(MC=="EGamma_EGamma_E"){
	_sample = 1102;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_F"){
	_sample = 1103;
	_flag = "egamma";
      }
      if(MC=="EGamma_EGamma_G"){
	_sample = 1104;
	_flag = "egamma";
      }
    }  
    m_selec.SetSample(_sample);
    m_selec.SetFlag(_flag);
  }
  
  chain->Process(&m_selec);
  gROOT->Time();
}
