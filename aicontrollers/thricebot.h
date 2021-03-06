#pragma once
#include <string>
#include <vector>
#include <event.h>
#include <playercontroller.h>
#include <piecetype.h>
#include <winds.h>

struct handTile
{
  Mahjong::Piece piece;
  float weight;
};

class ThriceBot : public Mahjong::PlayerController
{
	public:
	  auto Name() -> std::string;
	  auto GameStart(int _playerID) -> void;
	  auto RoundStart(std::vector<Mahjong::Piece> hand, Mahjong::Wind seatWind, Mahjong::Wind prevalentWind) -> void;
	  auto ReceiveEvent(Mahjong::Event e) -> void;
	  auto RetrieveDecision() -> Mahjong::Event;
	private:
	  //private functions
	  void assignweights(void);
	  Mahjong::Piece popDiscard(void);
	  handTile assignTileWeight(handTile);
	  void checkDiscard(void);
	  bool checkTile(Mahjong::Piece);
	  //instance vars
	  std::vector<handTile> hand;
	  int discarded[256] = {};
	  Mahjong::Event lastEvent;
	  Mahjong::Wind swind;
	  Mahjong::Wind pwind;
      int pid;
};
