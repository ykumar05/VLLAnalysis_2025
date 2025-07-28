import os

class CondorJob(object):

    def __init__(self):
        pass

    def setup(self):
        
        with open('runJobsCondor_simulation.sh','w') as exec_file:
            exec_file.write("#!/bin/bash"+"\n"+
                    "export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch" +"\n"+
                    "export COIN_FULL_INDIRECT_RENDERING=1"+"\n"+
                    "echo $VO_CMS_SW_DIR"+"\n"+
                    "source $VO_CMS_SW_DIR/cmsset_default.sh"+"\n"+
                    "cd /home/work/ykumar1/CMSSW_10_3_1/src"+"\n"+
                    "eval `scramv1 runtime -sh`"+"\n"+
                    "root -q -b -l "+os.path.abspath(self.codedir)+"/runana.C\(\"$1\",\"$2\",\"$3\",\"$4\",\"$5\",\"$6\",\"$7\",\"$8\"\)"
            )
            exec_file.close()

            with open('runana.C','w') as runanafile:
                runanafile.write('#include <TROOT.h>'+'\n'+
                     '#include <TChain.h>'+'\n'+
                     '#include <TFile.h>'+'\n'+
                     '#include <TString.h>'+'\n'+
                     'void runana(TString ifname="input_file" , TString ofname="outputfile" , TString data="data", TString year="year", TString lep="lep", TString era="era", TString MC="mc", TString flag="flag")'+'\n'+
                     '{'+'\n'+
                     'TString anastring =".x '+os.path.abspath(self.codedir)+'/anaCond_Run3.C(\\""+ifname+"\\",\\""+ofname+"\\",\\""+data+"\\",\\""+year+"\\",\\""+lep+"\\",\\""+era+"\\",\\""+MC+"\\",\\""+flag+"\\")";'+'\n'+
                     'gSystem->Load("'+os.path.abspath(self.codedir)+'/AnaScript_C.so");'+'\n'+
                     'gROOT->ProcessLine(anastring);'+'\n'+
                     '}'
                )
                
                
                runanafile.close()

                print("...........runana.C file written..........")
