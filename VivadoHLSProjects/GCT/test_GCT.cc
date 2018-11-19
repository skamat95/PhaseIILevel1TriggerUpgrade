#include"GCT.hh"

#include <iostream>
using namespace std;

//For making the input map links and the input file
bool writeLinkMapGCT(uint16_t peakEta_top[NClustersPerPhi][NCaloLayer2Phi],
		 uint16_t peakPhi_top[NClustersPerPhi][NCaloLayer2Phi],
		 uint16_t towerEta_top[NClustersPerPhi][NCaloLayer2Phi],
		 uint16_t towerPhi_top[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t ClusterET_top[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t peakEta_bot[NClustersPerPhi][NCaloLayer2Phi],
		 uint16_t peakPhi_bot[NClustersPerPhi][NCaloLayer2Phi],
		 uint16_t towerEta_bot[NClustersPerPhi][NCaloLayer2Phi],
		 uint16_t towerPhi_bot[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t ClusterET_bot[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outpeakEta_top[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outpeakPhi_top[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outtowerEta_top[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outtowerPhi_top[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outClusterET_top[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outpeakEta_bot[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outpeakPhi_bot[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outtowerEta_bot[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outtowerPhi_bot[NClustersPerPhi][NCaloLayer2Phi],
	         uint16_t outClusterET_bot[NClustersPerPhi][NCaloLayer2Phi]) {
  // This code is to write suitable mapping of inputs to signals in the CTP7_HLS project from Ales
  // Block 1 of User Code
  int  iEta = 0;
  int iPhi = 0;
  int count, link, loBit, hiBit;
  static FILE *f1;
  f1 = fopen("link_data_map_GCT.txt","w");

  for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
	  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {

				  fprintf(f1, "peakEta_top_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "peakPhi_top_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "towerEta_top_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "towerPhi_top_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "ClusterET_top_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "peakEta_bot_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "peakPhi_bot_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "towerEta_bot_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "towerPhi_bot_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
				  fprintf(f1, "ClusterET_bot_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);
	  }
  }

int jEta = 0;
int jPhi = 0;
  for(jEta = 0; jEta < NClustersPerPhi; jEta++) {
  	  for(jPhi = 0; jPhi < NCaloLayer2Phi; jPhi++) {

				fprintf(f1, "outpeakEta_top_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outpeakPhi_top_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outtowerEta_top_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outtowerPhi_top_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outClusterET_top_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outpeakEta_bot_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outpeakPhi_bot_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outtowerEta_bot_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outtowerPhi_bot_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);
				fprintf(f1, "outClusterET_bot_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", jEta, jPhi);

  	  	  }
  	  }




  // Block 2

  for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
  	  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {


  				fprintf(f1, "signal peakEta_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
  				fprintf(f1, "signal peakPhi_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
  				fprintf(f1, "signal towerEta_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
  				fprintf(f1, "signal towerPhi_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
  				fprintf(f1, "signal ClusterET_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
  				fprintf(f1, "signal peakEta_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
				fprintf(f1, "signal peakPhi_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
				fprintf(f1, "signal towerEta_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
				fprintf(f1, "signal towerPhi_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);
				fprintf(f1, "signal ClusterET_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi);

  	  }
    }


  for(jEta = 0; jEta < NClustersPerPhi; jEta++) {
  	  for(jPhi = 0; jPhi < NCaloLayer2Phi; jPhi++) {


  				fprintf(f1, "signal outpeakEta_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
  				fprintf(f1, "signal outpeakPhi_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
  				fprintf(f1, "signal outtowerEta_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
  				fprintf(f1, "signal outtowerPhi_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
  				fprintf(f1, "signal outClusterET_top_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
  				fprintf(f1, "signal outpeakEta_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
				fprintf(f1, "signal outpeakPhi_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
				fprintf(f1, "signal outtowerEta_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
				fprintf(f1, "signal outtowerPhi_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);
				fprintf(f1, "signal outClusterET_bot_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", jEta, jPhi);

  	  }
    }

  // Block 3

    for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
    	  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {

    				  fprintf(f1, "peakEta_top_%d_%d => peakEta_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);
    				  fprintf(f1, "peakPhi_top_%d_%d => peakPhi_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);
    				  fprintf(f1, "towerEta_top_%d_%d => towerEta_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);
    				  fprintf(f1, "towerPhi_top_%d_%d => towerPhi_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);
    				  fprintf(f1, "ClusterET_top_%d_%d => ClusterET_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);
    				  fprintf(f1, "peakEta_bot_%d_%d => peakEta_bot_%d_%d,\n", iEta, iPhi, iEta, iPhi);
					  fprintf(f1, "peakPhi_top_%d_%d => peakPhi_bot_%d_%d,\n", iEta, iPhi, iEta, iPhi);
					  fprintf(f1, "towerEta_top_%d_%d => towerEta_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);
					  fprintf(f1, "towerPhi_top_%d_%d => towerPhi_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);
					  fprintf(f1, "ClusterET_top_%d_%d => ClusterET_top_%d_%d,\n", iEta, iPhi, iEta, iPhi);

    	  }
      }

    for(jEta = 0; jEta < NClustersPerPhi; jEta++) {
		  for(jPhi = 0; jPhi < NCaloLayer2Phi; jPhi++) {

					  fprintf(f1, "outpeakEta_top_%d_%d => outpeakEta_top_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outpeakPhi_top_%d_%d => outpeakPhi_top_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outtowerEta_top_%d_%d => outtowerEta_top_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outtowerPhi_top_%d_%d => outtowerPhi_top_%d_%d,\n", jEta, iPhi, jEta, jPhi);
					  fprintf(f1, "outClusterET_top_%d_%d => outClusterET_top_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outpeakEta_bot_%d_%d => outpeakEta_bot_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outpeakPhi_top_%d_%d => outpeakPhi_bot_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outtowerEta_top_%d_%d => outtowerEta_top_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outtowerPhi_top_%d_%d => outtowerPhi_top_%d_%d,\n", jEta, jPhi, jEta, jPhi);
					  fprintf(f1, "outClusterET_top_%d_%d => outClusterET_top_%d_%d,\n", jEta, jPhi, jEta, jPhi);

		  }
	  }




  // Block 4

      int temp1 = 0;

      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
      	  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {

      				// Each link can carry 192-bits, or 12x16-bits of data
      				    // Each iRgn needs 16 bits

      				    link = (temp1 / 12);
      				    loBit = (temp1 % 12) * 16;
      				    hiBit = loBit + 15;

      				  fprintf(f1, "peakEta_top_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
      				  temp1++;

      	  }
        }

      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
      	  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
      				    link = (temp1 / 12);
      				    loBit = (temp1 % 12) * 16;
      				    hiBit = loBit + 15;

      				  fprintf(f1, "peakPhi_top_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
      				  temp1++;

      	  }
        }
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "towerEta_top_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
		 }
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "towerPhi_top_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
	  }
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "ClusterET_top_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
	  }

      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "peakEta_bot_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
	  }
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "peakPhi_bot_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
     	}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "towerEta_bot_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "towerPhi_bot_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp1 / 12);
						loBit = (temp1 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "ClusterET_bot_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, link, hiBit, loBit);
					  temp1++;
		  }
		}
      //output links
      int temp2 = 0;
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outpeakEta_top_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outpeakPhi_top_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outtowerEta_top_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outtowerPhi_top_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outClusterET_top_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outpeakEta_bot_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outpeakPhi_bot_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outtowerEta_bot_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outtowerPhi_bot_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}
      for(iEta = 0; iEta < NClustersPerPhi; iEta++) {
		  for(iPhi = 0; iPhi < NCaloLayer2Phi; iPhi++) {
						link = (temp2 / 12);
						loBit = (temp2 % 12) * 16;
						hiBit = loBit + 15;

					  fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= outClusterET_bot_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
					  temp2++;
		  }
		}





  return true;
}


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

  //printing link map file
  bool success_link_map = false;
  success_link_map = writeLinkMapGCT(peakEta_top,peakPhi_top,towerEta_top,towerPhi_top,ClusterET_top,peakEta_bot,peakPhi_bot,towerEta_bot,towerPhi_bot,ClusterET_bot,outpeakEta_top,outpeakPhi_top,outtowerEta_top,outtowerPhi_top,outClusterET_top,outpeakEta_bot,outpeakPhi_bot,outtowerEta_bot,outtowerPhi_bot,outClusterET_bot);
	

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
