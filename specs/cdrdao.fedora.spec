Name:		cdrdao
Summary:	A Disk-At-Once (DAO) Audio CD writer and GUI editor
Version:	1.1.9pre1
Release:	1
License:	GPL
Group:		Applications/Multimedia
BuildRoot:      %{_builddir}/%{name}-buildroot
Source:		%{name}-%{version}.tar.gz

Requires:	lame >= 3

BuildRequires:	lame-devel >= 3
BuildRequires:	gtkmm2-devel >= 2.2.0
BuildRequires:	libgnomeuimm2-devel >= 2.0
BuildRequires:  libsigc++-devel

%description

Writes audio CD-Rs in disc-at-once (DAO) mode allowing control over
pre-gaps (length down to 0, nonzero audio data) and sub-channel
information like ISRC codes. All data that is written to the disc must
be specified with a text file. Audio data may be in WAVE or raw
format.

%package gcdmaster
Summary:        The Gnome2/GTK2 GUI front-end to cdrdao
Group:          Applications/Multimedia
Requires:	gtkmm2 >= 2.2.0
Requires:	libgnomeuimm2 >= 2.0
Requires:	GConf2 >= 2.0.0
Requires:       libsigc++

%description gcdmaster
Gcdmaster is a GNOME2 GUI front-end to cdrdao that makes it easy to
visualize and manipulate audio information before burning it onto
CD. Its features include: cut/copy/paste of sound samples, track marks
edition and silence insertion.

%prep
%setup -q

%build

%configure

make %{?_smp_mflags}

%makeinstall

%clean
[ -n "$RPM_BUILD_ROOT" -a "$RPM_BUILD_ROOT" != / ] && rm -rf $RPM_BUILD_ROOT

%post

%files
%defattr(-, root, root)
%doc AUTHORS COPYING CREDITS ChangeLog INSTALL README NEWS README.PlexDAE README.Win32
%{_bindir}/cdrdao
%{_datadir}/cdrdao/*
%{_bindir}/toc2cddb
%{_bindir}/toc2cue
%{_bindir}/cue2toc
%{_bindir}/toc2mp3
%{_mandir}/man1/cdrdao.1
%{_mandir}/man1/cue2toc.1

%files gcdmaster
%{_bindir}/gcdmaster
%{_datadir}/applications/gcdmaster.desktop
%{_datadir}/pixmaps/gcdmaster.png
%{_mandir}/man1/gcdmaster.1