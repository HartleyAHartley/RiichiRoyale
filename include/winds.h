#pragma once
#include "mahjongns.h"

namespace Mahjong {

  enum Wind{
    East,
    South,
    West,
    North
  };

  inline auto WindToStr(Wind s) -> std::string{
    switch(s){
      case East:
        return "East";
      case South:
        return "South";
      case West:
        return "West";
      case North:
        return "North";
      default:
        return "InvalidWind";

    }
  }

};
