#ifndef GCT_hh
#define GCT_hh

#include "ap_int.h"

#define uint10_t ap_uint<10>
#define uint7_t ap_uint<7>
#define uint5_t ap_uint<5>

#include <stdint.h>
const uint16_t NCaloLayer1Cards = 18;//1/2 eta
const uint16_t NCaloLayer1Eta = 17;//1/2 eta
const uint16_t NCaloLayer1Phi = 4;
const uint16_t NCrystalsPerEtaPhi = 5;

//According to one Layer 2 card
const uint16_t NCaloLayer2Eta = 17; //17*2
const uint16_t NCaloLayer2Phi_in = 28; //6*4 + 2 on either side
const uint16_t NCaloLayer2Phi_out = 24; //6*4 as output per card

const uint16_t EtaDirections = 2;
const uint16_t NCaloPhiRegionsPerCard = 6;
const uint16_t NCaloLayer2ClustersPerCard = 12;
const uint16_t NCaloLayer2ClustersPerPhi = 3;

const uint16_t NCaloLayer2ExtraPhi = 2;

int GCT(uint16_t Tower_in[NCaloLayer2Eta][NCaloLayer2Phi_in][EtaDirections],
      uint10_t ClusterET_in[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_in][EtaDirections],
      uint7_t Cluster_TowerID_in[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_in][EtaDirections],
      uint5_t Cluster_EtaPhi_in[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_in][EtaDirections],
      uint16_t Tower_out[NCaloLayer2Eta][NCaloLayer2Phi_out][EtaDirections],
      uint10_t ClusterET_out[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_out][EtaDirections],
      uint7_t Cluster_TowerID_out[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_out][EtaDirections],
      uint5_t Cluster_EtaPhi_out[NCaloLayer2ClustersPerPhi][NCaloLayer2Phi_out][EtaDirections]);



int stitch_on_left(uint10_t current_cluster_ET_in, uint16_t tower_num, uint16_t crystal_num,
      uint10_t ClusterET_in[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint7_t Cluster_TowerID_in[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint5_t Cluster_EtaPhi_in[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint10_t ClusterET_out[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint7_t Cluster_TowerID_out[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint5_t Cluster_EtaPhi_out[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint10_t &current_cluster_ET_out);

int stitch_on_right(uint10_t current_cluster_ET_in, uint16_t tower_num, uint16_t crystal_num,
      uint10_t ClusterET_in[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint7_t Cluster_TowerID_in[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint5_t Cluster_EtaPhi_in[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint10_t ClusterET_out[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint7_t Cluster_TowerID_out[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint5_t Cluster_EtaPhi_out[NCaloLayer2ClustersPerPhi][NCaloLayer1Phi],
      uint10_t &current_cluster_ET_out);

int ifExists_tower(uint7_t element, uint7_t *Array, int num, bool &out);
int ifExists_crystal(uint5_t element, uint5_t *Array, int num, bool &out);
int ifExists_tower_eta(uint7_t element, uint7_t *Array, int num, bool &out);
int ifExists_tower_search(uint7_t element, uint7_t *Array, int num, int expected_rem, bool &out);
int ifExists_crystal_search(uint5_t element, uint5_t Array[5], int num, int expected_rem, bool &out);

#endif
