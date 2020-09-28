#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/grid.h>
#include <gtkmm/checkbutton.h>
#include <vector>

#include "walls.h"

class MainWindow : public Gtk::Window
{

public:
  MainWindow();
  virtual ~MainWindow();

protected:
  //Signal handlers:
  void on_button_clicked();

  Walls walls;

  //Member widgets:
  Gtk::Grid grid;
  Gtk::Button button;
  std::vector<Gtk::Image> imageArray;
  Glib::RefPtr<Gdk::Pixbuf> front;
  Gtk::CheckButton sortButton;
};
