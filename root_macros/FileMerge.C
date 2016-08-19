// FileMerge.C
// 
// M H Wood, Canisius College
//
// Notes: ROOT macro to merge histogram and tree files
//
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
gROOT->Reset();

void FileMerge(char *flist, char *outFile){

  char inFile[200]; // input file from flist

  TFileMerger *fm = new TFileMerger(); // create TFileMerger object

  // open output file and check for errors
  if(fm->OutputFile(outFile)){
    cout<<"Output file "<<outFile<<" created."<<endl;
  }else{
    cout<<"Error creating output file "<<outFile<<endl;
    exit(0);
  }

  ifstream fin(flist); // open file list
  while(fin>>inFile){ 
    fm->AddFile(inFile); // add file to TFileMerger object
  }

  // merge files and check for errors
  if(fm->Merge()){
    cout<<"Successful file merger!!!"<<endl;
  }else{
    cout<<"Failed file merger!!!"<<endl;
  }
}
