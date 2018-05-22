/*  cdrdao - write audio CD-Rs in disc-at-once mode
 *
 *  Copyright (C) 2000  Andreas Mueller <mueller@daneb.ping.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __GCDMASTER_H__
#define __GCDMASTER_H__

#include <gtkmm.h>

#include <list>

class BlankCDDialog;
#include "Project.h"
#include "BlankCDDialog.h"
#include "ProjectChooser.h"

/* 
 * Main GCDMaster application
 */

class GCDMaster : public Gtk::Application
{
public:
  GCDMaster();

  static Glib::RefPtr<GCDMaster> create();

  void newChooserWindow();

private:
  gint project_number_;
  Gtk::ApplicationWindow* window_;
  Gtk::Notebook* notebook_;

  // Override default signal handlers.
  void on_startup() override;
  void on_activate() override;
  void on_action_quit();
  void on_action_preferences();

//  bool closeProject();
//  void closeChooser();
//  bool on_delete_event(GdkEventAny* e);
//bool openNewProject(const char*);
//void openProject();
  /* void newAudioCDProject2(); */
  /* void newAudioCDProject(const char *name, TocEdit *tocEdit, */
  /*                        const char* tracks = NULL); */
  /* void newDuplicateCDProject(); */
  /* void newDumpCDProject(); */

  /* void update(unsigned long level); */

  /* void configureDevices(); */
  /* void configurePreferences(); */
  /* void blankCDRW(); */

  /* void registerStockIcons(); */

  /* static void appClose(); */

  static std::list<GCDMaster *> apps;

//  Project* project_;
  ProjectChooser* chooser_;

  /* BlankCDDialog blankCDDialog_; */

  /* Gtk::Notebook notebook_; */

  /* Glib::RefPtr<Gtk::UIManager> m_refUIManager; */
  /* Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup; */

  /* //Gnome::UI::AppBar* statusbar_;   */
  /* Gtk::ProgressBar* progressbar_;   */
  /* Gtk::Button* progressButton_;   */
  /* //Gnome::UI::About* about_; */

  /* //Glib::RefPtr<Gnome::Glade::Xml> m_refPreferencesXml; */

  /* Gtk::FileChooserDialog* readFileSelector_; */
  /* void createMenus(); */
  /* void createStatusbar(); */
  /* void aboutDialog(); */
};

#endif