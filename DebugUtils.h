#pragma once
#include <ctime>

static int tic=0,toc=0,debugOn=0;
#define step() if(debugOn)    {  toc=tic;tic=clock(); toc==0?0:printf("Elapsed: %d\n",double(tic-toc)/CLOCKS_PER_SEC); } 
#define pause() if(debugOn)   { system("pause"); }
#define pri(_ii)  if(debugOn) { printf("%d\n",_ii); }
#define prf(_dd)  if(debugOn) { printf("%f\n",_dd); } 
#define prs(_ss)  if(debugOn) { printf(_ss); } 
#define PILL_DEBUG extern int tic,toc,debugOn;
#define debugMode(__open)  debugOn=__open;