#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

void ana(int sample=1)
{
  const char *hstfilename, *sumfilename;
  TChain *chain = new TChain("Events");
  AnaScript m_selec;

  //Run3Summer22 Datasets
  if(sample==1){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer22_Output/EGamma/EGamma_C/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22_EMuLike_15May2025_v1_EGamma_EGamma_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2022);
    m_selec.SetSample(1102);
  }
  if(sample==2){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer22_Output/EGamma/EGamma_D/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22_EMuLike_15May2025_v1_EGamma_EGamma_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2022);
    m_selec.SetSample(1103);
  }
  if(sample==3){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer22_Output/Muon/Muon_C/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22_EMuLike_15May2025_v1_Muon_Muon_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2022);
    m_selec.SetSample(1002);
  }
  if(sample==4){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer22_Output/Muon/Muon_D/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22_EMuLike_15May2025_v1_Muon_Muon_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2022);
    m_selec.SetSample(1003);
  }
  
  //Run3Summer22EE DataSets
  if(sample==5){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/cms/store/group/phys_susy/VLLAnalysis_Yash/Run3Summer22EE_Output/EGamma/EGamma_E/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22EE_EMuLike_20May2025_v1_EGamma_EGamma_E_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3022);
    m_selec.SetSample(1102);
  }
  if(sample==6){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/cms/store/group/phys_susy/VLLAnalysis_Yash/Run3Summer22EE_Output/EGamma/EGamma_F/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22EE_EMuLike_20May2025_v1_EGamma_EGamma_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3022);
    m_selec.SetSample(1103);
  }
  if(sample==7){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/cms/store/group/phys_susy/VLLAnalysis_Yash/Run3Summer22EE_Output/EGamma/EGamma_G/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22EE_EMuLike_20May2025_v1_EGamma_EGamma_G_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3022);
    m_selec.SetSample(1104);
  }
  if(sample==8){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/cms/store/group/phys_susy/VLLAnalysis_Yash/Run3Summer22EE_Output/Muon/Muon_E/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22EE_EMuLike_20May2025_v1_Muon_Muon_E_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3022);
    m_selec.SetSample(1002);
  }
  if(sample==9){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/cms/store/group/phys_susy/VLLAnalysis_Yash/Run3Summer22EE_Output/Muon/Muon_F/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22EE_EMuLike_20May2025_v1_Muon_Muon_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3022);
    m_selec.SetSample(1003);
  }
  if(sample==10){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/cms/store/group/phys_susy/VLLAnalysis_Yash/Run3Summer22EE_Output/Muon/Muon_G/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer22EE_EMuLike_20May2025_v1_Muon_Muon_G_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3022);
    m_selec.SetSample(1004);
  }

  //Run3Summer23 Datasets
  if(sample==110){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma0/EGamma0_C-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma0_C-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1102);
  }
  if(sample==111){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma0/EGamma0_C-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma0_C-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1102);
  }
  if(sample==112){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma0/EGamma0_C-v3/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma0_C-v3_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1102);
  }
  if(sample==113){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma0/EGamma0_C-v4/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma0_C-v4_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1102);
  }
  if(sample==114){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma1/EGamma1_C-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma1_C-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1103);
  }
  if(sample==115){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma1/EGamma1_C-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma1_C-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1103);
  }
  if(sample==116){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma1/EGamma1_C-v3/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma1_C-v3_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1103);
  }
  if(sample==117){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/EGamma1/EGamma1_C-v4/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_EGamma_EGamma1_C-v4_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1103);
  }
  if(sample==118){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon0/Muon0_C-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon0_C-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1002);
  }
  if(sample==119){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon0/Muon0_C-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon0_C-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1002);
  }
  if(sample==120){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon0/Muon0_C-v3/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon0_C-v3_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1002);
  }
  if(sample==121){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon0/Muon0_C-v4/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon0_C-v4_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1002);
  }
  if(sample==122){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon1/Muon1_C-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon1_C-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1003);
  }
  if(sample==123){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon1/Muon1_C-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon1_C-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1003);
  }
  if(sample==124){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon1/Muon1_C-v3/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon1_C-v3_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1003);
  }
  if(sample==125){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/Muon1/Muon1_C-v4/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23_EMuLike_11June2025_v1_Muon_Muon1_C-v4_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2023);
    m_selec.SetSample(1003);
  }
  if(sample==140){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23_Output/ZGamma/MLL-50_PTG-10to100/SkimmedFile_1.root");
    //Set names of output files
    hstfilename = "14034282_SkimmedFile_1_data.root";
    m_selec.SetData(0); 
    m_selec.SetYear(2023);
    m_selec.SetSample(949);
  }

  //Run3Summer23BPix Datasets
  if(sample==150){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/EGamma0/EGamma0_D-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_EGamma_EGamma0_D-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1102);
  }
  if(sample==151){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/EGamma0/EGamma0_D-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_EGamma_EGamma0_D-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1102);
  }
  if(sample==152){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/EGamma1/EGamma1_D-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_EGamma_EGamma1_D-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1103);
  }
  if(sample==153){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/EGamma1/EGamma1_D-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_EGamma_EGamma1_D-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1103);
  }
  if(sample==154){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/Muon0/Muon0_D-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_Muon_Muon0_D-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1002);
  }
  if(sample==155){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/Muon0/Muon0_D-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_Muon_Muon0_D-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1002);
  }
  if(sample==156){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/Muon1/Muon1_D-v1/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_Muon_Muon1_D-v1_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1003);
  }
  if(sample==157){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/Muon1/Muon1_D-v2/*.root");
    //Set names of output files
    hstfilename = "VLLRun3Summer23BPix_EMuLike_17June2025_v1_Muon_Muon1_D-v2_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3023);
    m_selec.SetSample(1003);
  }
  if(sample==180){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/Run3Summer23BPix_Output/DYJetsToLL/M50/SkimmedFile_1.root");
    //Set names of output files
    hstfilename = "14001780_SkimmedFile_1_data.root";
    m_selec.SetData(0); 
    m_selec.SetYear(3023);
    m_selec.SetSample(2);
  }

  //RunII_2018 Datasets
  if(sample==19){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/EGamma/EGamma_A/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_EGamma_EGamma_A_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1100);
  }
  if(sample==20){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/EGamma/EGamma_B/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_EGamma_EGamma_B_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1101);
  }
  if(sample==21){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/EGamma/EGamma_C/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_EGamma_EGamma_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1102);
  }
  if(sample==22){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/EGamma/EGamma_D/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_EGamma_EGamma_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1103);
  }
  if(sample==23){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/SingleMuon/SingleMuon_A/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_SingleMuon_SingleMuon_A_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1000);
  }
  if(sample==24){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/SingleMuon/SingleMuon_B/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_SingleMuon_SingleMuon_B_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1001);
  }
  if(sample==25){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/SingleMuon/SingleMuon_C/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_SingleMuon_SingleMuon_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1002);
  }
  if(sample==26){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL18_Output/SingleMuon/SingleMuon_D/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL18_EMuLike_23May2025_v1_SingleMuon_SingleMuon_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2018);
    m_selec.SetSample(1003);
  }

  if(sample==260){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/cms/store/group/phys_susy/VLLAnalysis_Yash/RunII_20UL18_Output/ZZ/ZZTo4L/*");
    //Set names of output files
    hstfilename = "ZZTo4L.root";
    m_selec.SetData(0); 
    m_selec.SetYear(2018);
    m_selec.SetSample(22);
  }

  //RunII_2017 Datasets
  if(sample==27){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleElectron/SingleElectron_B/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleElectron_SingleElectron_B_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1100);
  }
  if(sample==28){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleElectron/SingleElectron_C/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleElectron_SingleElectron_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1101);
  }
  if(sample==29){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleElectron/SingleElectron_D/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleElectron_SingleElectron_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1102);
  }
  if(sample==30){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleElectron/SingleElectron_E/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleElectron_SingleElectron_E_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1103);
  }
  if(sample==31){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleElectron/SingleElectron_F/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleElectron_SingleElectron_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1104);
  }
  if(sample==32){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleMuon/SingleMuon_B/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleMuon_SingleMuon_B_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1000);
  }
  if(sample==33){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleMuon/SingleMuon_C/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleMuon_SingleMuon_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1001);
  }
  if(sample==34){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleMuon/SingleMuon_D/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleMuon_SingleMuon_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1002);
  }
  if(sample==35){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleMuon/SingleMuon_E/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleMuon_SingleMuon_E_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1003);
  }
  if(sample==36){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/SingleMuon/SingleMuon_F/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL17_EMuLike_31May2025_v1_SingleMuon_SingleMuon_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2017);
    m_selec.SetSample(1004);
  }

  if(sample==360){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL17_Output/ZZ/ZZTo4L/SkimmedFile_1.root");
    //Set names of output files
    hstfilename = "13961731_SkimmedFile_1_data.root";
    m_selec.SetData(0); 
    m_selec.SetYear(2017);
    m_selec.SetSample(22);
  }

  //RunII_2016preVFP Datasets
  if(sample==37){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleElectron/SingleElectron_B/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleElectron_SingleElectron_B_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1100);
  }
  if(sample==38){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleElectron/SingleElectron_C/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleElectron_SingleElectron_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1101);
  }
  if(sample==39){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleElectron/SingleElectron_D/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleElectron_SingleElectron_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1102);
  }
  if(sample==40){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleElectron/SingleElectron_E/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleElectron_SingleElectron_E_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1103);
  }
  if(sample==41){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleElectron/SingleElectron_F/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleElectron_SingleElectron_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1104);
  }
  if(sample==42){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleMuon/SingleMuon_B/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleMuon_SingleMuon_B_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1000);
  }
  if(sample==43){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleMuon/SingleMuon_C/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleMuon_SingleMuon_C_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1001);
  }
  if(sample==44){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleMuon/SingleMuon_D/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleMuon_SingleMuon_D_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1002);
  }
  if(sample==45){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleMuon/SingleMuon_E/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleMuon_SingleMuon_E_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1003);
  }
  if(sample==46){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16preVFP_Output/SingleMuon/SingleMuon_F/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16preVFP_EMuLike_15June2025_v2_SingleMuon_SingleMuon_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(2016);
    m_selec.SetSample(1004);
  }

  //RunII_2016postVFP Datasets
  if(sample==47){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16postVFP_Output/SingleElectron/SingleElectron_F/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16postVFP_EMuLike_10June2025_v2_SingleElectron_SingleElectron_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3016);
    m_selec.SetSample(1100);
  }
  if(sample==48){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16postVFP_Output/SingleElectron/SingleElectron_G/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16postVFP_EMuLike_10June2025_v2_SingleElectron_SingleElectron_G_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3016);
    m_selec.SetSample(1101);
  }
  if(sample==49){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16postVFP_Output/SingleElectron/SingleElectron_H/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16postVFP_EMuLike_10June2025_v2_SingleElectron_SingleElectron_H_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3016);
    m_selec.SetSample(1102);
  }
  if(sample==50){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16postVFP_Output/SingleMuon/SingleMuon_F/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16postVFP_EMuLike_10June2025_v2_SingleMuon_SingleMuon_F_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3016);
    m_selec.SetSample(1000);
  }
  if(sample==51){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16postVFP_Output/SingleMuon/SingleMuon_G/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16postVFP_EMuLike_10June2025_v2_SingleMuon_SingleMuon_G_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3016);
    m_selec.SetSample(1001);
  }
  if(sample==52){
    //Add one file to chain. This is the input file.
    chain->Add("/eos/user/y/ykumar/RunII_20UL16postVFP_Output/SingleMuon/SingleMuon_H/*.root");
    //Set names of output files
    hstfilename = "VLLRunII_20UL16postVFP_EMuLike_10June2025_v2_SingleMuon_SingleMuon_H_sample.root";
    m_selec.SetData(1); 
    m_selec.SetYear(3016);
    m_selec.SetSample(1002);
  }
  
  std::cout<<"Output files are "<<hstfilename<<std::endl;
  // Set some more options.. set the output file names.
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetVerbose(1000);
  chain->Process(&m_selec);
  
}
