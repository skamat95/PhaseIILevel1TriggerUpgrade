#include"GCT.hh"

#include <iostream>
using namespace std;
int main ()
{

//Give inputs to variables

  uint16_t peakEta_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t peakPhi_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t towerEta_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t towerPhi_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t ClusterET_top[NClustersPerPhi][NCaloLayer2Phi];


  uint16_t peakEta_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t peakPhi_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t towerEta_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t towerPhi_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t ClusterET_bot[NClustersPerPhi][NCaloLayer2Phi];
  
  uint16_t outpeakEta_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outpeakPhi_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outtowerEta_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outtowerPhi_top[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outClusterET_top[NClustersPerPhi][NCaloLayer2Phi];


  uint16_t outpeakEta_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outpeakPhi_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outtowerEta_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outtowerPhi_bot[NClustersPerPhi][NCaloLayer2Phi];
  uint16_t outClusterET_bot[NClustersPerPhi][NCaloLayer2Phi];
  

//For towers
  for(int i = 0; i < NClustersPerPhi ; i++){
    for(int j = 0; j < NCaloLayer2Phi; j++){
      peakEta_top[i][j]=0;
      peakPhi_top[i][j]=0;
      towerEta_top[i][j]=0;
      towerPhi_top[i][j]=0;
      ClusterET_top[i][j]=0;



      peakEta_bot[i][j]=0;
      peakPhi_bot[i][j]=0;
      towerEta_bot[i][j]=0;
      towerPhi_bot[i][j]=0;
      ClusterET_bot[i][j]=0;

    }
  }
  

  peakEta_top[2][3]= 2;
  peakPhi_top[2][3]= 4;
	
  towerEta_top[2][3]=14;
  towerPhi_top[2][3]=3;
  ClusterET_top[2][3]=10;


  peakEta_top[2][4]= 2;
  peakPhi_top[2][4]= 0;

  towerEta_top[2][4]=14;
  towerPhi_top[2][4]=4;  
  ClusterET_top[2][4]=20;


  peakEta_bot[2][3]= 2;
  peakPhi_bot[2][3]= 4;
	
  towerEta_bot[2][3]=14;
  towerPhi_bot[2][3]=3;
  ClusterET_bot[2][3]=10;


  peakEta_bot[2][4]= 2;
  peakPhi_bot[2][4]= 0;

  towerEta_bot[2][4]=14;
  towerPhi_bot[2][4]=4;  
  ClusterET_bot[2][4]=20;



//  peakEta[1][31]= 3;
//  peakPhi[1][31]= 1;
//
//  towerEta[1][31]=28;
//  towerPhi[1][31]=31;  
//  ClusterET[1][31]=30;
//
//
//  peakEta[1][32]= 3;
//  peakPhi[1][32]= 0;
//	
//  towerEta[1][32]=28;
//  towerPhi[1][32]=32;
//  ClusterET[1][32]=40;
//
//

	
	

  if(GCT(peakEta_top,peakPhi_top,towerEta_top,towerPhi_top,ClusterET_top,peakEta_bot,peakPhi_bot,towerEta_bot,towerPhi_bot,ClusterET_bot,outpeakEta_top,outpeakPhi_top,outtowerEta_top,outtowerPhi_top,outClusterET_top,outpeakEta_bot,outpeakPhi_bot,outtowerEta_bot,outtowerPhi_bot,outClusterET_bot))
    {

      for(int i = 0; i < NClustersPerPhi ; i++){
	for(int j = 0; j < NCaloLayer2Phi; j++){

	  std::cout<<" peakEta_top[i][j]: "<<peakEta_top[i][j]<<" and output: "<<outpeakEta_top[i][j]
		   <<" peakPhi_top[i][j]: "<<peakPhi_top[i][j]<<" and output: "<<outpeakPhi_top[i][j]
		   <<" towerEta_top[i][j]:"<<towerEta_top[i][j]<<" and output: "<<outpeakPhi_top[i][j]
		   <<" towerPhi_top[i][j]: "<<towerPhi_top[i][j]<<" and output: "<<outtowerPhi_top[i][j]
		   <<" ClusterET_top[i][j]: "<<ClusterET_top[i][j]<<" and output: "<<outClusterET_top[i][j]
		   <<" peakEta_bot[i][j]: "<<peakEta_bot[i][j]<<" and output: "<<outpeakEta_bot[i][j]
		   <<" peakPhi_bot[i][j]: "<<peakPhi_bot[i][j]<<" and output: "<<outpeakPhi_bot[i][j]
		   <<" towerEta_bot[i][j]:"<<towerEta_bot[i][j]<<" and output: "<<outpeakPhi_bot[i][j]
		   <<" towerPhi_bot[i][j]: "<<towerPhi_bot[i][j]<<" and output: "<<outtowerPhi_bot[i][j]
		   <<" ClusterET_bot[i][j]: "<<ClusterET_bot[i][j]<<" and output: "<<outClusterET_bot[i][j]


		   <<std::endl<<std::endl;
	    }

      }


    }
  else {
    cout << "GCT failed" << endl;
    return 1;
  }
  
  

return 0;
}
