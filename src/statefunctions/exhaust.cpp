#include "event.h"
#include "gamestate.h"
#include "statefunctions.h"
#include "hands.h"
using namespace Mahjong;

auto Mahjong::Exhaust(GameState& state) -> GameState& {
  int winningPlayers[4] = {};  
  int totalWinners = 0;
  for(int i = 0; i < 4; i++){
    // im taking the liberty to ignore the rule
    // that if your wait is a piece you have four
    // of you're then not in tenpai
    // shouldn't matter much
    // message Alice for complains
    if(state.hands[i].riichi || !isInTenpai13Pieces(state.hands[i].live).empty()){ 
      winningPlayers[i] = true;
      totalWinners++;
    }
  }
  state.counters++;
  if(!winningPlayers[state.roundNum%4]){
    state.roundNum++;
  }
  if(totalWinners < 4 && totalWinners > 0){
    for(int i = 0; i < 4; i++){
      if(winningPlayers[i]){
        state.scores[i] = 3000/totalWinners;
      }else{
        switch(totalWinners){
          case 1:
            state.scores[i] = -1000;
            break;
          case 2:
            state.scores[i] = -1500;
            break;
          case 3:
            state.scores[i] = -3000;
            break;
          default:
            break;
        }
      }
      if(state.hands[i].riichi){
        state.scores[i] -= 1000;
      }
    }
  }
  state.nextState = RoundEnd;
  return state;
}
