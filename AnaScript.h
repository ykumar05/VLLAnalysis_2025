#ifndef AnaScript_h
#define AnaScript_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <set>
#include <utility>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

#include <vector>
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
#include "TLorentzVector.h"
#include <fstream>
#include <iostream>
#include "TString.h"
#include <bitset>
#include <time.h>


class AnaScript : public TSelector {
  public:
  bool _run3; //Initialize it in the Init() method. Default = False.

 private:  
  //for Run3(v12 and Above)
  /*using iterator      = Int_t;
    using int_or_char   = UChar_t;
    using int_or_short  = Short_t;
    using int_or_ushort = UShort_t;*/
  
  //for Run2(Till v11): Run3Summer22 Data is v11
  using iterator     = UInt_t;
  using int_or_char  = Int_t;
  using int_or_short = Int_t;
  using int_or_ushort = Int_t;
  
 public :
  TTreeReader     fReader;
  TTreeReader     fReader_Run2;
  TTreeReader     fReader_Run3;
  TTreeReader     fReader_MC;
  TTreeReader     fReader_Data;
  TTreeReader     fReader_Run2_MC;
  TTreeReader     fReader_Run3_MC;
  TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

  // Readers to access the data (delete the ones you do not need).                                                    
  TTreeReaderValue<UInt_t> run =             {fReader, "run"};
  TTreeReaderValue<UInt_t> luminosityBlock = {fReader, "luminosityBlock"};
  TTreeReaderValue<ULong64_t> event =        {fReader, "event"};

  //Electrons
  TTreeReaderValue<iterator> nElectron =                    {fReader, "nElectron"};
  TTreeReaderArray<Float_t> Electron_dxy =                  {fReader, "Electron_dxy"};
  TTreeReaderArray<Float_t> Electron_dxyErr =               {fReader, "Electron_dxyErr"};
  TTreeReaderArray<Float_t> Electron_dz =                   {fReader, "Electron_dz"};
  TTreeReaderArray<Float_t> Electron_dzErr =                {fReader, "Electron_dzErr"};
  TTreeReaderArray<Float_t> Electron_eta =                  {fReader, "Electron_eta"};
  TTreeReaderArray<Float_t> Electron_hoe =                  {fReader, "Electron_hoe"};
  TTreeReaderArray<Float_t> Electron_ip3d =                 {fReader, "Electron_ip3d"};
  TTreeReaderArray<Float_t> Electron_mass =                 {fReader, "Electron_mass"};
  TTreeReaderArray<Float_t> Electron_pfRelIso03_all =       {fReader, "Electron_pfRelIso03_all"};
  TTreeReaderArray<Float_t> Electron_pfRelIso03_chg =       {fReader, "Electron_pfRelIso03_chg"};
  TTreeReaderArray<Float_t> Electron_phi =                  {fReader, "Electron_phi"};
  TTreeReaderArray<Float_t> Electron_pt =                   {fReader, "Electron_pt"};
  TTreeReaderArray<Float_t> Electron_sip3d =                {fReader, "Electron_sip3d"};
  TTreeReaderArray<Int_t> Electron_charge =                 {fReader, "Electron_charge"};
  TTreeReaderArray<int_or_char> Electron_cutBased =         {fReader, "Electron_cutBased"};
  TTreeReaderArray<int_or_short> Electron_jetIdx =          {fReader, "Electron_jetIdx"};
  TTreeReaderArray<Int_t> Electron_pdgId =                  {fReader, "Electron_pdgId"};
  TTreeReaderArray<Int_t> Electron_vidNestedWPBitmap =      {fReader, "Electron_vidNestedWPBitmap"};
  TTreeReaderArray<Int_t> Electron_vidNestedWPBitmapHEEP =  {fReader, "Electron_vidNestedWPBitmapHEEP"};
  TTreeReaderArray<Bool_t> Electron_cutBased_HEEP =         {fReader, "Electron_cutBased_HEEP"};
  TTreeReaderArray<Bool_t> Electron_isPFcand =              {fReader, "Electron_isPFcand"};
  TTreeReaderArray<UChar_t> Electron_seedGain =             {fReader, "Electron_seedGain"};
  TTreeReaderArray<int_or_short>   Electron_genPartIdx =    {fReader_MC, "Electron_genPartIdx"};
  
  //Jet
  TTreeReaderValue<iterator> nJet =                 {fReader, "nJet"};
  TTreeReaderArray<int_or_char> Jet_jetId =         {fReader, "Jet_jetId"};
  TTreeReaderArray<UChar_t> Jet_nConstituents =     {fReader, "Jet_nConstituents"};
  TTreeReaderArray<int_or_char> Jet_nElectrons =    {fReader, "Jet_nElectrons"};
  TTreeReaderArray<int_or_char> Jet_nMuons =        {fReader, "Jet_nMuons"};
  TTreeReaderArray<Float_t> Jet_btagDeepFlavB =     {fReader, "Jet_btagDeepFlavB"};
  TTreeReaderArray<Float_t> Jet_btagDeepFlavCvB =   {fReader, "Jet_btagDeepFlavCvB"};
  TTreeReaderArray<Float_t> Jet_btagDeepFlavCvL =   {fReader, "Jet_btagDeepFlavCvL"};
  TTreeReaderArray<Float_t> Jet_btagDeepFlavQG =    {fReader, "Jet_btagDeepFlavQG"};
  TTreeReaderArray<Float_t> Jet_eta =               {fReader, "Jet_eta"};
  TTreeReaderArray<Float_t> Jet_mass =              {fReader, "Jet_mass"};
  TTreeReaderArray<Float_t> Jet_muEF =              {fReader, "Jet_muEF"};
  TTreeReaderArray<Float_t> Jet_muonSubtrFactor =   {fReader, "Jet_muonSubtrFactor"};
  TTreeReaderArray<Float_t> Jet_neEmEF =            {fReader, "Jet_neEmEF"};
  TTreeReaderArray<Float_t> Jet_neHEF =             {fReader, "Jet_neHEF"};
  TTreeReaderArray<Float_t> Jet_phi =               {fReader, "Jet_phi"};
  TTreeReaderArray<Float_t> Jet_pt =                {fReader, "Jet_pt"};
  TTreeReaderArray<int_or_char> Jet_hadronFlavour = {fReader_MC, "Jet_hadronFlavour"};

  //MET
  TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaX = {fReader, "MET_MetUnclustEnUpDeltaX"};
  TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaY = {fReader, "MET_MetUnclustEnUpDeltaY"};
  TTreeReaderValue<Float_t> MET_covXX =                {fReader, "MET_covXX"};
  TTreeReaderValue<Float_t> MET_covXY =                {fReader, "MET_covXY"};
  TTreeReaderValue<Float_t> MET_covYY =                {fReader, "MET_covYY"};
  TTreeReaderValue<Float_t> MET_phi =                  {fReader, "MET_phi"};
  TTreeReaderValue<Float_t> MET_pt =                   {fReader, "MET_pt"};
  TTreeReaderValue<Float_t> MET_significance =         {fReader, "MET_significance"};
  TTreeReaderValue<Float_t> MET_sumEt =                {fReader, "MET_sumEt"};
  TTreeReaderValue<Float_t> MET_sumPtUnclustered =     {fReader, "MET_sumPtUnclustered"};

  //Muons
  TTreeReaderValue<iterator> nMuon =                 {fReader, "nMuon"};
  TTreeReaderArray<int_or_short> Muon_jetIdx =       {fReader, "Muon_jetIdx"};
  TTreeReaderArray<UChar_t> Muon_highPtId =          {fReader, "Muon_highPtId"};
  TTreeReaderArray<Bool_t> Muon_highPurity =         {fReader, "Muon_highPurity"};
  TTreeReaderArray<Bool_t> Muon_inTimeMuon =         {fReader, "Muon_inTimeMuon"};
  TTreeReaderArray<Bool_t> Muon_isGlobal =           {fReader, "Muon_isGlobal"};
  TTreeReaderArray<Bool_t> Muon_isPFcand =           {fReader, "Muon_isPFcand"};
  TTreeReaderArray<Bool_t> Muon_isStandalone =       {fReader, "Muon_isStandalone"};
  TTreeReaderArray<Bool_t> Muon_isTracker =          {fReader, "Muon_isTracker"};
  TTreeReaderArray<Bool_t> Muon_looseId =            {fReader, "Muon_looseId"};
  TTreeReaderArray<Bool_t> Muon_mediumId =           {fReader, "Muon_mediumId"};
  TTreeReaderArray<Bool_t> Muon_mediumPromptId =     {fReader, "Muon_mediumPromptId"};
  TTreeReaderArray<Int_t> Muon_charge =              {fReader, "Muon_charge"};
  TTreeReaderArray<Int_t> Muon_pdgId =               {fReader, "Muon_pdgId"};
  TTreeReaderArray<Float_t> Muon_dxy =               {fReader, "Muon_dxy"};
  TTreeReaderArray<Float_t> Muon_dxyErr =            {fReader, "Muon_dxyErr"};
  TTreeReaderArray<Float_t> Muon_dxybs =             {fReader, "Muon_dxybs"};
  TTreeReaderArray<Float_t> Muon_dz =                {fReader, "Muon_dz"};
  TTreeReaderArray<Float_t> Muon_dzErr =             {fReader, "Muon_dzErr"};
  TTreeReaderArray<Float_t> Muon_eta =               {fReader, "Muon_eta"};
  TTreeReaderArray<Float_t> Muon_ip3d =              {fReader, "Muon_ip3d"};
  TTreeReaderArray<Float_t> Muon_mass =              {fReader, "Muon_mass"};
  TTreeReaderArray<Float_t> Muon_miniPFRelIso_all =  {fReader, "Muon_miniPFRelIso_all"};
  TTreeReaderArray<Float_t> Muon_miniPFRelIso_chg =  {fReader, "Muon_miniPFRelIso_chg"};
  TTreeReaderArray<Float_t> Muon_pfRelIso03_all =    {fReader, "Muon_pfRelIso03_all"};
  TTreeReaderArray<Float_t> Muon_pfRelIso03_chg =    {fReader, "Muon_pfRelIso03_chg"};
  TTreeReaderArray<Float_t> Muon_pfRelIso04_all =    {fReader, "Muon_pfRelIso04_all"};
  TTreeReaderArray<Float_t> Muon_phi =               {fReader, "Muon_phi"};
  TTreeReaderArray<Float_t> Muon_pt =                {fReader, "Muon_pt"};
  TTreeReaderArray<Float_t> Muon_ptErr =             {fReader, "Muon_ptErr"};
  TTreeReaderArray<Float_t> Muon_sip3d =             {fReader, "Muon_sip3d"};
  TTreeReaderArray<int_or_short> Muon_genPartIdx =   {fReader_MC, "Muon_genPartIdx"};
  
  //PuppiMET
  TTreeReaderValue<Float_t> PuppiMET_phi =                {fReader, "PuppiMET_phi"};
  TTreeReaderValue<Float_t> PuppiMET_phiJERDown =         {fReader, "PuppiMET_phiJERDown"};
  TTreeReaderValue<Float_t> PuppiMET_phiJERUp =           {fReader, "PuppiMET_phiJERUp"};
  TTreeReaderValue<Float_t> PuppiMET_phiJESDown =         {fReader, "PuppiMET_phiJESDown"};
  TTreeReaderValue<Float_t> PuppiMET_phiJESUp =           {fReader, "PuppiMET_phiJESUp"};
  TTreeReaderValue<Float_t> PuppiMET_phiUnclusteredDown = {fReader, "PuppiMET_phiUnclusteredDown"};
  TTreeReaderValue<Float_t> PuppiMET_phiUnclusteredUp =   {fReader, "PuppiMET_phiUnclusteredUp"};
  TTreeReaderValue<Float_t> PuppiMET_pt =                 {fReader, "PuppiMET_pt"};
  TTreeReaderValue<Float_t> PuppiMET_ptJERDown =          {fReader, "PuppiMET_ptJERDown"};
  TTreeReaderValue<Float_t> PuppiMET_ptJERUp =            {fReader, "PuppiMET_ptJERUp"};
  TTreeReaderValue<Float_t> PuppiMET_ptJESDown =          {fReader, "PuppiMET_ptJESDown"};
  TTreeReaderValue<Float_t> PuppiMET_ptJESUp =            {fReader, "PuppiMET_ptJESUp"};
  TTreeReaderValue<Float_t> PuppiMET_ptUnclusteredDown =  {fReader, "PuppiMET_ptUnclusteredDown"};
  TTreeReaderValue<Float_t> PuppiMET_ptUnclusteredUp =    {fReader, "PuppiMET_ptUnclusteredUp"};
  TTreeReaderValue<Float_t> PuppiMET_sumEt =              {fReader, "PuppiMET_sumEt"};

  //TrigObj
  TTreeReaderValue<iterator>  nTrigObj =              {fReader, "nTrigObj"};
  TTreeReaderArray<Float_t> TrigObj_pt =              {fReader, "TrigObj_pt"};
  TTreeReaderArray<Float_t> TrigObj_eta =             {fReader, "TrigObj_eta"};
  TTreeReaderArray<Float_t> TrigObj_phi =             {fReader, "TrigObj_phi"};
  TTreeReaderArray<Float_t> TrigObj_l1pt =            {fReader, "TrigObj_l1pt"};
  TTreeReaderArray<Float_t> TrigObj_l1pt_2 =          {fReader, "TrigObj_l1pt_2"};
  TTreeReaderArray<Float_t> TrigObj_l2pt =            {fReader, "TrigObj_l2pt"};
  TTreeReaderArray<int_or_ushort>   TrigObj_id =      {fReader, "TrigObj_id"};
  TTreeReaderArray<Int_t>   TrigObj_l1iso =           {fReader, "TrigObj_l1iso"};
  TTreeReaderArray<int_or_short>   TrigObj_l1charge = {fReader, "TrigObj_l1charge"};
  TTreeReaderArray<Int_t>   TrigObj_filterBits =      {fReader, "TrigObj_filterBits"};

  //_______________________________________________________________________
    
  //GenJet (read using fReader_MC)
  TTreeReaderValue<iterator>  nGenJet =                 {fReader_MC, "nGenJet"};
  TTreeReaderArray<Float_t> GenJet_eta =                {fReader_MC, "GenJet_eta"};
  TTreeReaderArray<Float_t> GenJet_mass =               {fReader_MC, "GenJet_mass"};
  TTreeReaderArray<Float_t> GenJet_phi =                {fReader_MC, "GenJet_phi"};
  TTreeReaderArray<Float_t> GenJet_pt =                 {fReader_MC, "GenJet_pt"};

  //GenParticles (read using fReader_MC)
  TTreeReaderValue<iterator>  nGenPart =                    {fReader_MC, "nGenPart"};
  TTreeReaderArray<Float_t> GenPart_eta =                   {fReader_MC, "GenPart_eta"};
  TTreeReaderArray<Float_t> GenPart_mass =                  {fReader_MC, "GenPart_mass"};
  TTreeReaderArray<Float_t> GenPart_phi =                   {fReader_MC, "GenPart_phi"};
  TTreeReaderArray<Float_t> GenPart_pt =                    {fReader_MC, "GenPart_pt"};
  TTreeReaderArray<int_or_short> GenPart_genPartIdxMother = {fReader_MC, "GenPart_genPartIdxMother"};
  TTreeReaderArray<Int_t> GenPart_pdgId =                   {fReader_MC, "GenPart_pdgId"};
  TTreeReaderArray<Int_t> GenPart_status =                  {fReader_MC, "GenPart_status"};
  TTreeReaderArray<int_or_ushort> GenPart_statusFlags =     {fReader_MC, "GenPart_statusFlags"};

  //GenMET
  TTreeReaderValue<Float_t> GenMET_phi =         {fReader_MC, "GenMET_phi"};
  TTreeReaderValue<Float_t> GenMET_pt =          {fReader_MC, "GenMET_pt"};

  //btagWeight
  TTreeReaderValue<Float_t> btagWeight_DeepCSVB = {fReader_Run2_MC, "btagWeight_DeepCSVB"};
  
  //_________________________________________________________________________
  
  //Flags:
  TTreeReaderValue<Bool_t> Flag_HBHENoiseFilter =                    {fReader, "Flag_HBHENoiseFilter"};
  TTreeReaderValue<Bool_t> Flag_HBHENoiseIsoFilter =                 {fReader, "Flag_HBHENoiseIsoFilter"};
  TTreeReaderValue<Bool_t> Flag_CSCTightHaloFilter =                 {fReader, "Flag_CSCTightHaloFilter"};
  TTreeReaderValue<Bool_t> Flag_CSCTightHaloTrkMuUnvetoFilter =      {fReader, "Flag_CSCTightHaloTrkMuUnvetoFilter"};
  TTreeReaderValue<Bool_t> Flag_CSCTightHalo2015Filter =             {fReader, "Flag_CSCTightHalo2015Filter"};
  TTreeReaderValue<Bool_t> Flag_globalTightHalo2016Filter =          {fReader, "Flag_globalTightHalo2016Filter"};
  TTreeReaderValue<Bool_t> Flag_globalSuperTightHalo2016Filter =     {fReader, "Flag_globalSuperTightHalo2016Filter"};
  TTreeReaderValue<Bool_t> Flag_HcalStripHaloFilter =                {fReader, "Flag_HcalStripHaloFilter"};
  TTreeReaderValue<Bool_t> Flag_hcalLaserEventFilter =               {fReader, "Flag_hcalLaserEventFilter"};
  TTreeReaderValue<Bool_t> Flag_EcalDeadCellTriggerPrimitiveFilter = {fReader, "Flag_EcalDeadCellTriggerPrimitiveFilter"};
  TTreeReaderValue<Bool_t> Flag_EcalDeadCellBoundaryEnergyFilter =   {fReader, "Flag_EcalDeadCellBoundaryEnergyFilter"};
  TTreeReaderValue<Bool_t> Flag_ecalBadCalibFilter =                 {fReader, "Flag_ecalBadCalibFilter"};
  TTreeReaderValue<Bool_t> Flag_goodVertices =                       {fReader, "Flag_goodVertices"};
  TTreeReaderValue<Bool_t> Flag_eeBadScFilter =                      {fReader, "Flag_eeBadScFilter"};
  TTreeReaderValue<Bool_t> Flag_ecalLaserCorrFilter =                {fReader, "Flag_ecalLaserCorrFilter"};
  TTreeReaderValue<Bool_t> Flag_trkPOGFilters =                      {fReader, "Flag_trkPOGFilters"};
  TTreeReaderValue<Bool_t> Flag_chargedHadronTrackResolutionFilter = {fReader, "Flag_chargedHadronTrackResolutionFilter"};
  TTreeReaderValue<Bool_t> Flag_muonBadTrackFilter =                 {fReader, "Flag_muonBadTrackFilter"};
  TTreeReaderValue<Bool_t> Flag_BadChargedCandidateFilter =          {fReader, "Flag_BadChargedCandidateFilter"};
  TTreeReaderValue<Bool_t> Flag_BadPFMuonFilter =                    {fReader, "Flag_BadPFMuonFilter"};
  TTreeReaderValue<Bool_t> Flag_BadPFMuonDzFilter =                  {fReader, "Flag_BadPFMuonDzFilter"};
  TTreeReaderValue<Bool_t> Flag_hfNoisyHitsFilter =                  {fReader, "Flag_hfNoisyHitsFilter"};
  TTreeReaderValue<Bool_t> Flag_BadChargedCandidateSummer16Filter =  {fReader, "Flag_BadChargedCandidateSummer16Filter"};
  TTreeReaderValue<Bool_t> Flag_BadPFMuonSummer16Filter =            {fReader, "Flag_BadPFMuonSummer16Filter"};
  TTreeReaderValue<Bool_t> Flag_trkPOG_manystripclus53X =            {fReader, "Flag_trkPOG_manystripclus53X"};
  TTreeReaderValue<Bool_t> Flag_trkPOG_toomanystripclus53X =         {fReader, "Flag_trkPOG_toomanystripclus53X"};
  TTreeReaderValue<Bool_t> Flag_trkPOG_logErrorTooManyClusters =     {fReader, "Flag_trkPOG_logErrorTooManyClusters"};
  TTreeReaderValue<Bool_t> Flag_METFilters =                         {fReader, "Flag_METFilters"};

  //Run2 only:
  /*TTreeReaderValue<Float_t> fixedGridRhoFastjetAll =                  {fReader_Run2, "fixedGridRhoFastjetAll"};
    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentral =              {fReader_Run2, "fixedGridRhoFastjetCentral"};
    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralCalo =          {fReader_Run2, "fixedGridRhoFastjetCentralCalo"};
    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralChargedPileUp = {fReader_Run2, "fixedGridRhoFastjetCentralChargedPileUp"};
    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralNeutral =       {fReader_Run2, "fixedGridRhoFastjetCentralNeutral"};
    TTreeReaderArray<Float_t> Photon_pfRelIso03_all =                   {fReader_Run2, "Photon_pfRelIso03_all"};
    TTreeReaderArray<Float_t> Photon_pfRelIso03_chg =                   {fReader_Run2, "Photon_pfRelIso03_chg"};

    //Run3 only:
    TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetAll =                  {fReader_Run3, "Rho_fixedGridRhoFastjetAll"};
    TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentral =              {fReader_Run3, "Rho_fixedGridRhoFastjetCentral"};
    TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralCalo =          {fReader_Run3, "Rho_fixedGridRhoFastjetCentralCalo"};
    TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralChargedPileUp = {fReader_Run3, "Rho_fixedGridRhoFastjetCentralChargedPileUp"};
    TTreeReaderValue<Float_t> Rho_fixedGridRhoFastjetCentralNeutral =       {fReader_Run3, "Rho_fixedGridRhoFastjetCentralNeutral"};
    TTreeReaderArray<Float_t> Photon_pfRelIso03_all_quadratic =             {fReader_Run3, "Photon_pfRelIso03_all_quadratic"};
    TTreeReaderArray<Float_t> Photon_pfRelIso03_chg_quadratic =             {fReader_Run3, "Photon_pfRelIso03_chg_quadratic"};

    TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetAll                  = nullptr;
    TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentral              = nullptr;
    TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentralCalo          = nullptr;
    TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentralChargedPileUp = nullptr;
    TTreeReaderValue<Float_t>* ptr_fixedGridRhoFastjetCentralNeutral       = nullptr;
    TTreeReaderArray<Float_t>* ptr_Photon_pfRelIso03_all                   = nullptr;
    TTreeReaderArray<Float_t>* ptr_Photon_pfRelIso03_chg                   = nullptr;*/
  
  //GenWeight
  TTreeReaderValue<Float_t> Generator_weight   = {fReader_MC, "Generator_weight"};

  //PileUp
  TTreeReaderValue<Float_t> Pileup_nTrueInt = {fReader_MC, "Pileup_nTrueInt"};
  TTreeReaderValue<Int_t> Pileup_nPU        = {fReader_MC, "Pileup_nPU"};

  //HLT paths that we are intereted in:
  /*TTreeReaderValue<Bool_t> HLT_IsoMu24 =           {fReader, "HLT_IsoMu24"};
    TTreeReaderValue<Bool_t> HLT_Ele32_WPTight_Gsf = {fReader, "HLT_Ele32_WPTight_Gsf"};
    TTreeReaderValue<Bool_t> HLT_Ele32_WPTight_Gsf = {fReader, "HLT_Ele32_WPTight_Gsf"};
    TTreeReaderValue<Bool_t> HLT_IsoMu27 =           {fReader, "HLT_IsoMu27"};
    TTreeReaderValue<Bool_t> HLT_Ele32_WPTight_Gsf_L1DoubleEG = {fReader, "HLT_Ele32_WPTight_Gsf_L1DoubleEG"};
    TTreeReaderValue<Bool_t> HLT_IsoMu24 =           {fReader, "HLT_IsoMu24"};
    TTreeReaderValue<Bool_t> HLT_IsoTkMu24 =         {fReader, "HLT_IsoTkMu24"};
    TTreeReaderValue<Bool_t> HLT_Ele27_WPTight_Gsf = {fReader, "HLT_Ele27_WPTight_Gsf"};*/
  
  AnaScript(TTree * /*tree*/ =0) { }
  virtual ~AnaScript() { }
  virtual Int_t   Version() const { return 2; }
  virtual void    Begin(TTree *tree);
  virtual void    SlaveBegin(TTree *tree);
  virtual void    Init(TTree *tree);
  virtual Bool_t  Notify();
  virtual Bool_t  Process(Long64_t entry);
  virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  virtual void    SetOption(const char *option) { fOption = option; }
  virtual void    SetObject(TObject *obj) { fObject = obj; }
  virtual void    SetInputList(TList *input) { fInput = input; }
  virtual TList  *GetOutputList() const { return fOutput; }
  virtual void    SlaveTerminate();
  virtual void    Terminate();

  //User defined functions are declared here
  void SetHstFileName(const char *HstFileName){ _HstFileName = HstFileName;}
  void SetSumFileName(const char *SumFileName){ _SumFileName = SumFileName;}
  void SetSkimFileName(const char *SkimFileName){ _SkimFileName = SkimFileName;}
  void SetSample(int sample){_sample=sample;}
  void SetLep(int lep){_lep=lep;}
  void SetVerbose(int verbose){ _verbosity = verbose; }
  void SetData(int data){_data=data;}
  void SetYear(int year){_year = year;}
  void SetEra(TString era){_era=era;}
  void SetMCwt(int mcwt){_mcwt=mcwt;}
  void SetFlag(TString flag){_flag=flag;}
  void BookHistograms();

  float delta_phi(float phi1, float phi2);
  int   MotherID(int partindex, int momindex);
  float transv_mass(float lepE, float lepphi, float met, float metphi);

  void createLightLeptons();
  void createSignalArrays();
  void GenMuon();
  void GenZ();
  void GenElectron();
  void GenPhoton();
  void GenJets();
  void createTaus();
  void createJets();
  void createMisIDJets();
  void TriggerDef();
  void CR_WZ();
  void CR_DY();
  void CR_ZZ();
  void CR_ZG();
  void CR_MisID();
  void CR_MisID_4L();
  void CR_Test();
    
  void SortGenObjects();
  void SortVLL();
  void SortRecoObjects();
  int  getOSSFN();
  int  getOSSFN_DY();
  float getInvMass(TLorentzVector a,TLorentzVector b);
  bool  isOSSF(int i, int j);
  float OSSFMass(int i, int j);
  float OSSFMass_MisId(int i, int j);
  bool  IsGenMuonMatched(TLorentzVector t);
  bool  IsGenPhotonMatched(TLorentzVector t);
  bool  IsGenElectronMatched(TLorentzVector t);
  bool  IsGenLightLeptonMatched(TLorentzVector t);
 
public:
  struct Hists {
    //Histograms are declared here.
    TH1F *nevt;
    TH1F *acceptance[5];
    TH1F *decayMode[5];
    TH1F *triggerRes[5];
    TH1F *SF[10];
    TH1F *count[10];

    //Histogram Declaration for final states
    TH1F *hist_l3[100];
    TH1F *hist_l4[100];
    TH1F *hist_l2SS[100];
    TH1F *hist_l12j[100];
    TH1F *hist_l3_Bin1[100];
    TH1F *hist_l4_Bin1[100];
    TH1F *hist_l3_Bin2[100];
    TH1F *hist_l4_Bin2[100];
    TH1F *hist_l3_Bin3[100];
    TH1F *hist_l4_Bin3[100];
    TH1F *hist_l3_Bin4[100];
    TH1F *hist_l4_Bin4[100];
    
    //Object level hists:
    TH1F *mu[20];
    TH1F *ele[20];
    TH1F *jet[20];
    TH1F *llep[20];
    TH1F *dR[10];
    TH1F *momid[10];
    TH1F *met[10];
    TH1F *lt[2];
    TH1F *lt_met[2];
    TH1F *genpltmu[10];
    TH1F *genpltele[10];
    TH1F *genpltZ[10];
    TH1F *vll[10];
    TH1F *vln[10];
    //Control Region Plots
    TH1F *WZ_CR[100];
    TH1F *ZZ_CR[100];
    TH1F *DY_CR[50];
    TH1F *ZG_CR[50];
    TH1F *WZ_corr[10];
    TH1F *ZZ_corr[10];
    TH1F *DY_corr[10];
    TH1F *ZG_corr[10];
    TH1F *MisId_PromptRate_Data[25];
    TH1F *MisId_PromptRate_MC[25];
    TH1F *MisId_FakeRate_Data[25];
    TH1F *MisId_FakeRate_MC[25];
    TH1F *MisID_CR[50];
    TH1F *Test_CR[50];
  };

  struct Particle {
    TLorentzVector v;
    int id;
    int ind;
    int flavor;
    int charge;
    int momid;
    int status;
    int pdgid;
    float sip3d;
    float reliso03;
    float reliso04;
    vector<int> dauind; //indices of the daughters (GenPart only)
    vector<int> dauid; //pdgid of the daughters (GenPart only)
    int decaymode; //For VLL, 0-stable, 1-W, 2-Z, 3-Higgs
    int hadronflavor;
  };
  
  //Functions that involve the 'Particle' type objects:
  void SortPt(vector<Particle> part);
  bool clean_from_array(Particle target, vector<Particle> array, float dRcut);

  //Boson Pt SF
  double ZpTFactor_DY_Muons(int MCSample, TLorentzVector v1, TLorentzVector v2);
  double JetReWeighting_DY_Muons(int MCSample, vector<Particle>Jets);
  double ZpTFactor_DY_Electrons(int MCSample, TLorentzVector v1, TLorentzVector v2);
  double JetReWeighting_DY_Electrons(int MCSample, vector<Particle>Jets);

  /*******************************************************************************
   *                               BTagging SF                                   *
   *******************************************************************************/
  //2022
  float  bTagSFRun3Summer2022(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_Run3Summer22(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_Run3Summer22(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_Run3Summer22(float eta, float pt);

  //2022EE
  float  bTagSFRun3Summer2022EE(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_Run3Summer22EE(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_Run3Summer22EE(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_Run3Summer22EE(float eta, float pt);

  //2023
  float  bTagSFRun3Summer2023(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_Run3Summer23(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_Run3Summer23(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_Run3Summer23(float eta, float pt);

  //2023BPix
  float  bTagSFRun3Summer2023BPix(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_Run3Summer23BPix(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_Run3Summer23BPix(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_Run3Summer23BPix(float eta, float pt);

  //2018
  float  bTagSF2018(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_UL18(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_UL18(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_UL18(float eta, float pt);
  
  //2017
  float  bTagSF2017(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_UL17(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_UL17(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_UL17(float eta, float pt);

  //2016preVFP
  float  bTagSF2016preVFP(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_UL16preVFP(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_UL16preVFP(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_UL16preVFP(float eta, float pt);

  //2016postVFP
  float  bTagSF2016postVFP(int MCSample, vector<Particle>Jet);
  double getScaleFactors_bTagJets_MedWP_UL16postVFP(float eta, float pt);
  double getScaleFactors_cTagJets_Mis_UL16postVFP(float eta, float pt);
  double getScaleFactors_LightTagJets_Mis_UL16postVFP(float eta, float pt);

  /*****************************************************************************************
   *                                   Lepton SF                                           *
   *****************************************************************************************/
  //2022: Lepton SF
  double getScaleFactors_Electrons_Reco_Run3Summer22(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_Run3Summer22(float eta, float pt);
  double getScaleFactors_Muons_HLT_Run3Summer22(float eta, float pt);
  double getScaleFactors_Muons_ID_Run3Summer22(float eta, float pt);
  double getScaleFactors_Muons_ISO_Run3Summer22(float eta, float pt);
  double LeptonID_SFRun3Summer22(int id, float pt, float eta);

  //2022EE: Lepton SF
  double getScaleFactors_Electrons_Reco_Run3Summer22EE(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_Run3Summer22EE(float eta, float pt);
  double getScaleFactors_Muons_HLT_Run3Summer22EE(float eta, float pt);
  double getScaleFactors_Muons_ID_Run3Summer22EE(float eta, float pt);
  double getScaleFactors_Muons_ISO_Run3Summer22EE(float eta, float pt);
  double LeptonID_SFRun3Summer22EE(int id, float pt, float eta);

  //2023: Lepton SF
  double getScaleFactors_Electrons_Reco_Run3Summer23(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_Run3Summer23(float eta, float pt);
  double getScaleFactors_Muons_HLT_Run3Summer23(float eta, float pt);
  double getScaleFactors_Muons_ID_Run3Summer23(float eta, float pt);
  double getScaleFactors_Muons_ISO_Run3Summer23(float eta, float pt);
  double LeptonID_SFRun3Summer23(int id, float pt, float eta);

  //2023BPix: Lepton SF
  double getScaleFactors_Electrons_Reco_Run3Summer23BPix(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_Run3Summer23BPix(float eta, float pt);
  double getScaleFactors_Muons_HLT_Run3Summer23BPix(float eta, float pt);
  double getScaleFactors_Muons_ID_Run3Summer23BPix(float eta, float pt);
  double getScaleFactors_Muons_ISO_Run3Summer23BPix(float eta, float pt);
  double LeptonID_SFRun3Summer23BPix(int id, float pt, float eta);

  //2018: Lepton SF
  double getScaleFactors_Electrons_Reco_UL18(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_UL18(float eta, float pt);
  double getScaleFactors_Muons_Reco_UL18(float eta, float pt);
  double getScaleFactors_Muons_ID_UL18(float eta, float pt);
  double getScaleFactors_Muons_ISO_UL18(float eta, float pt);
  double LeptonID_SFUL18(int id, float pt, float eta);

  //2017: Lepton SF
  double getScaleFactors_Electrons_Reco_UL17(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_UL17(float eta, float pt);
  double getScaleFactors_Muons_Reco_UL17(float eta, float pt);
  double getScaleFactors_Muons_ID_UL17(float eta, float pt);
  double getScaleFactors_Muons_ISO_UL17(float eta, float pt);
  double LeptonID_SFUL17(int id, float pt, float eta);

  //2016preVFP: Lepton SF
  double getScaleFactors_Electrons_Reco_UL16preVFP(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_UL16preVFP(float eta, float pt);
  double getScaleFactors_Muons_Reco_UL16preVFP(float eta, float pt);
  double getScaleFactors_Muons_ID_UL16preVFP(float eta, float pt);
  double getScaleFactors_Muons_ISO_UL16preVFP(float eta, float pt);
  double LeptonID_SFUL16preVFP(int id, float pt, float eta);

  //2016postVFP: Lepton SF
  double getScaleFactors_Electrons_Reco_UL16postVFP(float eta, float pt);
  double getScaleFactors_Electrons_IDIso_UL16postVFP(float eta, float pt);
  double getScaleFactors_Muons_Reco_UL16postVFP(float eta, float pt);
  double getScaleFactors_Muons_ID_UL16postVFP(float eta, float pt);
  double getScaleFactors_Muons_ISO_UL16postVFP(float eta, float pt);
  double LeptonID_SFUL16postVFP(int id, float pt, float eta);

  /**************************************************************************************************
   *                                    Trigger Fit Functions                                       *
   **************************************************************************************************/
  //SingleMuon
  float TriggEff2016preVFPMC_IsoMu24( float pt, float eta);
  float TriggEff2016preVFPData_IsoMu24(int id, float pt, float eta);
  float TriggEff2016postVFPMC_IsoMu24( float pt, float eta);
  float TriggEff2016postVFPData_IsoMu24(int id, float pt, float eta);
  float TriggEff2017MC_IsoMu27( float pt, float eta);
  float TriggEff2017Data_IsoMu27(int id, float pt, float eta);
  float TriggEff2018MC_IsoMu24( float pt, float eta);
  float TriggEff2018Data_IsoMu24(int id, float pt, float eta);
  float TriggEff2022Data_IsoMu24(int id, float pt, float eta);
  float TriggEff2022EEData_IsoMu24(int id, float pt, float eta);
  float TriggEff2023Data_IsoMu24(int id, float pt, float eta);
  float TriggEff2023BPixData_IsoMu24(int id, float pt, float eta);

  //SingleElectron
  float TriggEff2016preVFPMC_Ele27_WPTight_Gsf( float pt, float eta);
  float TriggEff2016preVFPData_Ele27_WPTight_Gsf(int id, float pt, float eta);
  float TriggEff2016postVFPMC_Ele27_WPTight_Gsf( float pt, float eta);
  float TriggEff2016postVFPData_Ele27_WPTight_Gsf(int id, float pt, float eta);
  float TriggEff2017MC_Ele32_WPTight_Gsf( float pt, float eta);
  float TriggEff2017Data_Ele32_WPTight_Gsf(int id, float pt, float eta);
  float TriggEff2018MC_Ele32_WPTight_Gsf(float pt, float eta);
  float TriggEff2018Data_Ele32_WPTight_Gsf(int id, float pt, float eta);
  float TriggEff2022Data_Ele32_WPTight_Gsf(int id, float pt, float eta);
  float TriggEff2022EEData_Ele32_WPTight_Gsf(int id, float pt, float eta);
  float TriggEff2023Data_Ele32_WPTight_Gsf(int id, float pt, float eta);
  float TriggEff2023BPixData_Ele32_WPTight_Gsf(int id, float pt, float eta);
  
  //Integrated Trigger Efficiency
  float TriggEff2023BPixData(int id, float pt, float eta);
  float TriggEff2023Data(int id, float pt, float eta);
  float TriggEff2022EEData(int id, float pt, float eta);
  float TriggEff2022Data(int id, float pt, float eta);
  float TriggEff2018MC(int id, float pt, float eta);
  float TriggEff2018Data(int id, float pt, float eta);
  float TriggEff2017MC(int id, float pt, float eta);
  float TriggEff2017Data(int id, float pt, float eta);
  float TriggEff2016preVFPMC(int id, float pt, float eta);
  float TriggEff2016preVFPData(int id, float pt, float eta);
  float TriggEff2016postVFPMC(int id, float pt, float eta);
  float TriggEff2016postVFPData(int id, float pt, float eta);

  /**************************************************************************************************
   *                                        Prompt/Fake Rates                                       *
   **************************************************************************************************/
  //Prompt and Fake Rates: 2023BPix
  double PromptRate_Run3Summer23BPix(int id, float pt, float eta, string sample);
  double PromptRateMixed_Run3Summer23BPix(int id, float pt, float eta);
  double FakeRate_Run3Summer23BPix(int id, float pt, float eta, string sample);
  double FakeRate_RT_Run3Summer23BPix(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_Run3Summer23BPix(int id, TLorentzVector v1, TLorentzVector v2);

  //Prompt and Fake Rates: 2023
  double PromptRate_Run3Summer23(int id, float pt, float eta, string sample);
  double PromptRateMixed_Run3Summer23(int id, float pt, float eta);
  double FakeRate_Run3Summer23(int id, float pt, float eta, string sample);
  double FakeRate_RT_Run3Summer23(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_Run3Summer23(int id, TLorentzVector v1, TLorentzVector v2);

  //Prompt and Fake Rates: 2022EE
  double PromptRate_Run3Summer22EE(int id, float pt, float eta, string sample);
  double PromptRateMixed_Run3Summer22EE(int id, float pt, float eta);
  double FakeRate_Run3Summer22EE(int id, float pt, float eta, string sample);
  double FakeRate_RT_Run3Summer22EE(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_Run3Summer22EE(int id, TLorentzVector v1, TLorentzVector v2);

  //Prompt and Fake Rates: 2022
  double PromptRate_Run3Summer22(int id, float pt, float eta, string sample);
  double PromptRateMixed_Run3Summer22(int id, float pt, float eta);
  double FakeRate_Run3Summer22(int id, float pt, float eta, string sample);
  double FakeRate_RT_Run3Summer22(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_Run3Summer22(int id, TLorentzVector v1, TLorentzVector v2);

  //Prompt and Fake Rates: 2018
  double PromptRate_UL18(int id, float pt, float eta, string sample);
  double PromptRateMixed_UL18(int id, float pt, float eta);
  double FakeRate_UL18(int id, float pt, float eta, string sample);
  double FakeRate_RT_UL18(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_UL18(int id, TLorentzVector v1, TLorentzVector v2);

  //Prompt and Fake Rates: 2017
  double PromptRate_UL17(int id, float pt, float eta, string sample);
  double PromptRateMixed_UL17(int id, float pt, float eta);
  double FakeRate_UL17(int id, float pt, float eta, string sample);
  double FakeRate_RT_UL17(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_UL17(int id, TLorentzVector v1, TLorentzVector v2);

  //Prompt and Fake Rates: 2016preVFP
  double PromptRate_UL16preVFP(int id, float pt, float eta, string sample);
  double PromptRateMixed_UL16preVFP(int id, float pt, float eta);
  double FakeRate_UL16preVFP(int id, float pt, float eta, string sample);
  double FakeRate_RT_UL16preVFP(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_UL16preVFP(int id, TLorentzVector v1, TLorentzVector v2);

  //Prompt and Fake Rates: 2016postVFP
  double PromptRate_UL16postVFP(int id, float pt, float eta, string sample);
  double PromptRateMixed_UL16postVFP(int id, float pt, float eta);
  double FakeRate_UL16postVFP(int id, float pt, float eta, string sample);
  double FakeRate_RT_UL16postVFP(int id, TLorentzVector v1, TLorentzVector v2, string sample);
  double FakeRateMixed_UL16postVFP(int id, TLorentzVector v1, TLorentzVector v2);

  int    electronCustomID(Int_t bitmap,int quality, int skipCut);

  //Recoil
  double DeltaPhi(TLorentzVector v1, TLorentzVector v2);
  double TransverseProjection(TLorentzVector p1, TLorentzVector p2);
  double Projection(TLorentzVector p1, TLorentzVector p2);

  //RunNumber and Lumis                                                                                               
  void loadGoodLumis(const std::string& filename);
  bool isGoodLumi(int run, int lumi);


protected:
  Hists h;

private:
  //Global variables go here. Make them global only if necessary.
  TFile *_HstFile, *_SkimFile;
  TTree *tree,*skimTree;
  const char *_HstFileName;
  const char *_SumFileName;
  const char *_SkimFileName;

  //Defining Integers
  int  _verbosity,_exclude,_sample;
  int  nEvtTotal,nEvtRan,nEvtTrigger,nEvtBad,nEvtSkim;
  int  _data, _lep, _year,_mcwt;
  int  n_l2OS, n_l2SS, n_l3, n_l4, n_l12j;

  //Defining Booleans
  bool evt_trigger, passTrigger, GoodEvt, GoodEvt2016, GoodEvt2017, GoodEvt2018, GoodEvt3016, GoodEvt2022, GoodEvt2023, GoodEvt3022, GoodEvt3023, triggerRes, trigger2016, trigger2017, trigger2018, trigger2022, trigger3022, trigger2023, trigger3023;
  bool is_l2OS_event, is_l2SS_event, is_l3_event, is_l3_MisID_event, is_l4_MisID_event, is_l4_event, is_l12j_event;
  bool veto_WZ, veto_ZZ, veto_MisID, veto_ZG, veto_Test;

  //Defining Floats
  float  metpt, metphi,evwt,prob,evtwt,prob1,puppimetpt,puppimetphi;
  float  LT, HT, ST, LT_PuppiMET;
  float  LT_MisID, HT_MisID, ST_MisID, LT_PuppiMET_MisID;

  //Defining Strings
  TString _era, _flag;

  //Defining Vectors
  vector<float>    MassArray_3L, TransverseMassArray_3L;
  vector<float>    MassArray_4L, MassArray_pT, MassArray_2LOS, MassArray_2e2mu, MassArray_chosen, MassArray_unchosen;
  vector<Particle> pairing1, pairing2, pairing3;
  vector<Particle> genMuon, genElectron, genZ, genLightLepton, genVLLDoublet, genVLLNuDoublet, genJets, genPhoton;
  vector<Particle> Muon, Electron, LightLepton, Photon, Tau, Jets, bJets, looseMuon, looseEle, loosellep, loosetau, LooseLep, MisIDJets, MisIDbJets, MisIDMuon;
  vector<Particle> vllep, vlnu;

  //For signal:
  bool bad_event;
  
  time_t start, end;
  
  ClassDef(AnaScript,0);

};

#endif

#ifdef AnaScript_cxx
void AnaScript::Init(TTree *tree)
{  
  //Decide whether to Run on Run2 or Run3
  _run3 = false;
  //_run3 = true;
  
  //Setting up the fReaders:
  fReader.SetTree(tree);
  if(_run3)
    fReader_Run3.SetTree(tree);
  else
    fReader_Run2.SetTree(tree);
  
  if(_data == 0){    
    fReader_MC.SetTree(tree);
    if(!_run3) 
      fReader_Run2_MC.SetTree(tree);
    else
      fReader_Run3_MC.SetTree(tree);
  }
  
  // Assigning address to the pointers for variables that have different names in Run2 and Run3.
  // These pointers need to be dereferenced twice to extract the value.
  /*if(_run3){
    ptr_fixedGridRhoFastjetAll =                  &Rho_fixedGridRhoFastjetAll;
    ptr_fixedGridRhoFastjetCentral =              &Rho_fixedGridRhoFastjetCentral;
    ptr_fixedGridRhoFastjetCentralCalo =          &Rho_fixedGridRhoFastjetCentralCalo;
    ptr_fixedGridRhoFastjetCentralChargedPileUp = &Rho_fixedGridRhoFastjetCentralChargedPileUp;
    ptr_fixedGridRhoFastjetCentralNeutral =       &Rho_fixedGridRhoFastjetCentralNeutral;
    ptr_Photon_pfRelIso03_all =                   &Photon_pfRelIso03_all_quadratic;
    ptr_Photon_pfRelIso03_chg =                   &Photon_pfRelIso03_chg_quadratic;
    }
    else{
    ptr_fixedGridRhoFastjetAll =                  &fixedGridRhoFastjetAll;
    ptr_fixedGridRhoFastjetCentral =              &fixedGridRhoFastjetCentral;
    ptr_fixedGridRhoFastjetCentralCalo =          &fixedGridRhoFastjetCentralCalo;
    ptr_fixedGridRhoFastjetCentralChargedPileUp = &fixedGridRhoFastjetCentralChargedPileUp;
    ptr_fixedGridRhoFastjetCentralNeutral =       &fixedGridRhoFastjetCentralNeutral;
    ptr_Photon_pfRelIso03_all =                   &Photon_pfRelIso03_all;
    ptr_Photon_pfRelIso03_chg =                   &Photon_pfRelIso03_chg;
    }*/
}

Bool_t AnaScript::Notify()
{
  return kTRUE;
}


#endif 
