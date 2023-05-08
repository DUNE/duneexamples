#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "canvas/Utilities/InputTag.h"
#include "gallery/Event.h"

#include "TFile.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TStyle.h"
#include "TColor.h"
#include "TMath.h"
#include "TVectorT.h"
#include "TCanvas.h"
#include "/cvmfs/dune.opensciencegrid.org/products/dune/dunedetdataformats/v3_6_1/include/detdataformats/trigger/TriggerCandidateData.hpp"
#include "/cvmfs/dune.opensciencegrid.org/products/dune/dunedaqdataformats/v3_4_1/include/daqdataformats/v3_4_1/SourceID.hpp"
#include "TLegend.h"

using namespace art;
using namespace std;

void trigdump(std::string const& filename="np02_bde_coldbox_run020617_0004_dataflow0_datawriter_0_20230314T182244_decode.root", 
             std::string const& inputtag="pdhdtriggerreader:daq")
{

  gStyle->SetOptStat(0);

  InputTag tag{ inputtag };
  const vector<string> filenames(1, filename);

  for (gallery::Event ev(filenames); !ev.atEnd(); ev.next())
    {
      auto const& evaux = ev.eventAuxiliary();
      std::cout << "Run: " << evaux.run() << " " << "subrun: " << evaux.subRun() << " event: " << evaux.event() << std::endl;
      {
	auto const& tcands = *ev.getValidHandle<std::map<dunedaq::daqdataformats::SourceID, std::vector<dunedaq::detdataformats::trigger::TriggerCandidateData>>>(tag);
	if (!tcands.empty())
	  {
	    std::cout << "trigger candidate map size: " << tcands.size() << std::endl;
	    for (const auto &tcm : tcands)
	      {
		std::cout << " Source ID version: " << tcm.first.version << " subsystem: " << tcm.first.subsystem << " id: " << tcm.first.id << std::endl;
		std::cout << " Trigger Candidate Data size: " << tcm.second.size() << endl;
		for (size_t i=0; i< tcm.second.size(); ++i)
		  {
		    std::cout << "   TC data version: " << tcm.second.at(i).version << " time_start " << tcm.second.at(i).time_start << std::endl;
		    std::cout << "   TC data time_end: " << tcm.second.at(i).version << " time_candidate " << tcm.second.at(i).time_candidate << std::endl;
		    std::cout << "   TC type: " << (int) tcm.second.at(i).type << " Algorithm: " << (int) tcm.second.at(i).algorithm << std::endl << std::endl; 
		  }
	      }
	  }
      }
  }
}
