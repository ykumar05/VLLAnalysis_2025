#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>
void runana(TString ifname="input_file" , TString ofname="outputfile" , TString data="data", TString year="year", TString lep="lep", TString era="era", TString MC="mc", TString flag="flag")
{
TString anastring =".x /afs/cern.ch/user/y/ykumar/Work/MyAnalysis/AnalyzerCode/anaCond_Run3.C(\""+ifname+"\",\""+ofname+"\",\""+data+"\",\""+year+"\",\""+lep+"\",\""+era+"\",\""+MC+"\",\""+flag+"\")";
gSystem->Load("/afs/cern.ch/user/y/ykumar/Work/MyAnalysis/AnalyzerCode/AnaScript_C.so");
gROOT->ProcessLine(anastring);
}