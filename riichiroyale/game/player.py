from functools import reduce
from .call import Call, chi_possible, kan_possible, pon_possible

class Player:
  def __init__(self, name, starting_hand=None, discard_pile=None):
    self.name = name
    if starting_hand is None:
      self.hand = []
    else:
      self.hand = starting_hand
    self.melded_hand = []
    if discard_pile is None:
      self.discard_pile = []
    else:
      self.discard_pile = discard_pile
    self.hand_open = False
    self.board = None
    self.riichi_declared = False
    self.calls_avaliable = []
    self.my_turn = False
    self.discarder = None

  def full_hand(self):
    meld_tiles = len(self.melded_hand) * 3
    return self.hand + meld_tiles

  def on_tile_click(self, tile_index, tutorial_state=None):
    if self.my_turn:
      # Discard Tile
      tile = self.hand[tile_index]
      if (tutorial_state is None) or (tutorial_state.next_discard == tile):
        del self.hand[tile_index]
        self.hand.sort()
        self.discard_pile.append(tile)
        self.my_turn = False
        if self.board is None:
          raise "Cannot communicate with board! Is this player registered?"
        self.board.on_discard(self)
        if tutorial_state is not None:
          tutorial_state.discard()

  def on_opponent_discard(self, player, chi_avaliable, ron_available=False):
    if len(player.discard_pile) == 0:
      raise "Player does not have a discard pile even though on_opponent_discard was drawn!"
    tile_discarded = player.discard_pile[-1]
    calls_possible = []
    if chi_avaliable:
      calls_possible += [Call.Chi] if chi_possible(self.hand, tile_discarded) else []
    calls_possible += [Call.Pon] if pon_possible(self.hand, tile_discarded) else []
    calls_possible += [Call.Kan] if kan_possible(self.hand, tile_discarded) else []
    if ron_available:
      calls_possible += [Call.Ron]
    if len(calls_possible) == 0:
      self.calls_avaliable = []
      return False
    self.calls_avaliable = calls_possible
    self.discarder = player
    return True

  def make_decision(self, call):
    self.calls_avaliable = []
    self.board.on_decision(call, self, self.discarder)



  def on_turn(self, board, draw=True):
    self.my_turn = True
    if draw:
      self.hand += board.draw_tile()
