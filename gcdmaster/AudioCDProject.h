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

#ifndef __AUDIOCDPROJECT_H__
#define __AUDIOCDPROJECT_H__

#include <gtkmm.h>

#include "Toc.h"
#include "Project.h"

class SoundIF;
class AudioCDView;
class TocInfoDialog;
class CdTextDialog;
class TocEdit;

class AudioCDProject : public Project
{
public:
    virtual ~AudioCDProject();

    static AudioCDProject* create(Glib::RefPtr<Gtk::Builder>& builder,
                                  int, const char*, TocEdit*, GCDWindow* parent);

    bool appendTrack(const char* file);
    bool appendTracks(std::list<std::string>&);
    bool appendFiles(std::list<std::string>&);
    bool insertFiles(std::list<std::string>&);

    void update(unsigned long level);

protected:
    AudioCDProject(Glib::RefPtr<Gtk::Builder>& builder,
                   int number, const char* name, TocEdit *tocEdit, GCDWindow* parent);

private:
    Gtk::Label label_;

public:
    enum PlayStatus {PLAYING, PAUSED, STOPPED};

    bool            closeProject();
    unsigned long   playPosition();
    unsigned long   getDelay();
    PlayStatus      playStatus() { return playStatus_; }

    // Controls for app bar
    void            cancelEnable(bool);
    sigc::signal0<void> signalCancelClicked;

protected:
    Gtk::Button* buttonPlay_;
    Gtk::Button* buttonStop_;
    Gtk::Button* buttonPause_;

    virtual void on_play_clicked();
    virtual void on_stop_clicked();
    virtual void on_pause_clicked();
    virtual void on_select_clicked();
    virtual void on_zoom_clicked();
    virtual void on_zoom_in_clicked();
    virtual void on_zoom_out_clicked();
    virtual void on_zoom_fit_clicked();
    virtual void on_cancel_clicked();

    virtual void status(const char* msg);
    virtual void errorDialog(const char* msg);
    virtual void progress(double val);
    virtual void fullView();
    virtual void sampleSelect(unsigned long, unsigned long);

    void playStart();
    void playStart(unsigned long start, unsigned long end);
    void playPause();
    void playStop();

    void add_actions();
private:
    TocReader tocReader;

    SoundIF *soundInterface_;
    unsigned long playLength_; // remaining play length
    unsigned long playBurst_;
    unsigned long playPosition_;
    Sample *playBuffer_;
    bool playAbort_;

    bool playCallback();

    Gtk::VBox      vbox_;
    AudioCDView*   audioCDView_;
    TocInfoDialog* tocInfoDialog_;
    CdTextDialog*  cdTextDialog_;
    Glib::RefPtr<Gio::SimpleActionGroup> m_action_group;
    Glib::RefPtr<Gtk::ToggleAction> selectToggle_;
    Glib::RefPtr<Gtk::ToggleAction> zoomToggle_;
    void recordToc2CD();
    void projectInfo();
    void cdTextDialog();

    enum PlayStatus playStatus_;
};
#endif
