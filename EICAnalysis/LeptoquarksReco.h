#ifndef __LeptoquarksReco_H__
#define __LeptoquarksReco_H__

/* Fun4All includes */
#include <fun4all/SubsysReco.h>

/* STL includes */
#include <math.h>
#include <map>

class TNtuple;
class TFile;

class PHCompositeNode;
class CaloRawTowerEval;

class LeptoquarksReco : public SubsysReco
{

public:

  LeptoquarksReco(std::string filename);

  int
  Init(PHCompositeNode*);
  int
  process_event(PHCompositeNode*);
  int
  End(PHCompositeNode*);

  void
  set_beam_energies( float beam_electron , float beam_proton )
  {
    _ebeam_E = fabs( beam_electron );
    _pbeam_E = fabs( beam_proton );
  }

  void
  set_reco_jet_collection( std::string newname )
  {
    _jetcolname = newname;
  }

private:

  bool _verbose;

  int _ievent;
  int _total_pass;

  std::string _filename;
  TFile *_tfile;

  /* output tree and variables */
  TNtuple* _ntp_leptoquark;
  TNtuple* _ntp_jet;
  TNtuple* _ntp_track;

  /* beam energies electron and proton */
  float _ebeam_E;
  float _pbeam_E;

  /** name of jet collection */
  std::string _jetcolname;

  /* CaloRawTowerEvaluators to access tru particle info for
   * given towers */
  std::map< std::string, CaloRawTowerEval* > _map_towereval;
};

#endif // __LeptoquarksReco_H__
