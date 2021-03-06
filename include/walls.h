#pragma once
#include <iosfwd>
#include <vector>
#include <random>
#include "piecetype.h"

namespace Mahjong { 
  class Walls{
  public:
    explicit Walls();
    explicit Walls(std::mt19937& g);
    explicit Walls(std::vector<Piece> wall);
    std::vector<Piece> livingWalls;
    std::vector<Piece> deadWall;
    int doraCount = 1;
    int replacements = 4;
    Piece TakePiece();
    std::vector<Piece> TakeHand();
    Piece TakeReplacementTile();
    std::vector<Piece> GetDoras() const;
    std::vector<Piece> GetUraDoras() const;
    int GetRemainingPieces() const;
  };
}
  
auto operator<<(std::ostream& os, const Mahjong::Walls& walls) -> std::ostream&;
