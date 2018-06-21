#include"GCT.hh"

#include <iostream>
using namespace std;
int main ()
{

   //Give inputs to variables
   uint16_t Tower_in[NCaloLayer2Eta][NCaloLayer2Phi_in][EtaDirections];
   uint10_t ClusterET_in[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_in][EtaDirections];
   uint7_t Cluster_TowerID_in[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_in][EtaDirections];
   uint5_t Cluster_EtaPhi_in[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_in][EtaDirections];

   uint16_t Tower_out[NCaloLayer2Eta][NCaloLayer2Phi_out][EtaDirections];
   uint10_t ClusterET_out[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_out][EtaDirections];
   uint7_t Cluster_TowerID_out[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_out][EtaDirections];
   uint5_t Cluster_EtaPhi_out[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_out][EtaDirections];

   //For input
   //For towers
   for(int i = 0; i < NCaloLayer2Eta ; i++){
      for(int j = 0; j < NCaloLayer2Phi_in; j++){
	 for(int k = 0; k < EtaDirections; k++){

	    Tower_in[i][j][k] = 0;

	 }
      }
   }

   //For clusters
   for(int i = 0; i < NCaloLayer2ClustersPerPhi ; i++){
      for(int j = 0; j < NCaloLayer2Phi_in; j++){
	 for(int k = 0; k < EtaDirections; k++){

	    ClusterET_in[i][j][k] = 0;
	    Cluster_TowerID_in[i][j][k] = 9;
	    Cluster_EtaPhi_in[i][j][k] = 7;

	 }
      }
   }

   //Initializing output variables to 0 as well
   //Towers
   for(int i = 0; i < NCaloLayer2Eta ; i++){
      for(int j = 0; j < NCaloLayer2Phi_out; j++){
	 for(int k = 0; k < EtaDirections; k++){

	    Tower_out[i][j][k] = 0;

	 }
      }
   }

   //Clusters
   for(int i = 0; i < NCaloLayer2ClustersPerPhi ; i++){
      for(int j = 0; j < NCaloLayer2Phi_out; j++){
	 for(int k = 0; k < EtaDirections; k++){

	    ClusterET_out[i][j][k] = 0;
	    Cluster_TowerID_out[i][j][k] = 0;
	    Cluster_EtaPhi_out[i][j][k] = 0;

	 }
      }
   }

   ClusterET_in[1][2][0] = 20;
   Cluster_TowerID_in[1][2][0] = 3;
   Cluster_EtaPhi_in[1][2][0] = 4;

   cout << ClusterET_in[1][2][0] << "\t" <<  Cluster_TowerID_in[1][2][0]  <<"\t"<<  Cluster_EtaPhi_in[1][2][0] << endl;

   cout << ClusterET_out[1][0][0] << "\t" <<  Cluster_TowerID_out[1][0][0]  <<"\t"<<  Cluster_EtaPhi_out[1][0][0] << endl;

   ClusterET_in[1][6][0] = 10;
   Cluster_TowerID_in[1][6][0] = 0;
   Cluster_EtaPhi_in[1][6][0] = 0;


   //call the function

   uint16_t ret_val = 0;
   ret_val = GCT(Tower_in, ClusterET_in, Cluster_TowerID_in, Cluster_EtaPhi_in, Tower_out, ClusterET_out, Cluster_TowerID_out, Cluster_EtaPhi_out);

   //print some outputs

   cout << ClusterET_out[1][2][0] << "\t" <<  Cluster_TowerID_out[1][2][0]  <<"\t"<<  Cluster_EtaPhi_out[1][2][0] << endl;

   for(int i = 0; i < NCaloLayer2ClustersPerPhi ; i++){
      for(int j = 0; j < NCaloLayer2Phi_out; j++){
	 for(int k = 0; k < EtaDirections; k++){

	    cout << ClusterET_out << "\t" <<  Cluster_TowerID_out  <<"\t"<<  Cluster_EtaPhi_out << endl;
	    cout << ClusterET_out[i][j][k] << "\t" <<  Cluster_TowerID_out[i][j][k]  <<"\t"<<  Cluster_EtaPhi_out[i][j][k] << endl;

	 }
      }
   }

   return 0;
}
