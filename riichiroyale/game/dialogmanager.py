class DialogManager():
  def __init__(self):
    self.events = dict()
    self.current_page = 0
    self.current_event = None

  def register_dialog_event(self, name):
    self.events[name] = []

  def append_dialog_event(self, name, text):
    self.events[name] += [text]

  def start_event(self, name):
    self.current_event = name
    self.current_page = 0

  def get_current_page(self):
    return self.events[self.current_event][self.current_page]