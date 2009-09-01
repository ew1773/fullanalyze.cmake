/***********************************************************************

This file is part of the FullAnalyze project source files.

FullAnalyze is an open source software for handling, visualizing and 
processing lidar data (waveforms and point clouds). FullAnalyze is 
distributed under the CeCILL-B licence. See Licence_CeCILL-B_V1-en.txt 
or http://www.cecill.info for more details.


Homepage: 

	http://fullanalyze.sourceforge.net
	
Copyright:
	
	Institut Geographique National & CEMAGREF (2009)

Author: 

	Adrien Chauve
	
	

This software is governed by the CeCILL-B license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL-B
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-B license and that you accept its terms.
 
***********************************************************************/

#include <stdexcept>
#include <wx/wx.h>
#include <wx/statusbr.h>

#include "gui/MainFrame.h"


#ifdef __LINUX__
#include <locale.h>
#endif

class MyApp : public wxApp
{
public:
private:
	bool OnInit();
	bool InitFrame();

	MainFrame *m_mainFrameDock;

};

IMPLEMENT_APP(MyApp)


bool MyApp::InitFrame()
{

	wxInitAllImageHandlers();

	m_mainFrameDock = new MainFrame;

	return true;
}

bool MyApp::OnInit()
{
#ifdef __LINUX__
setlocale (LC_ALL,"POSIX");
#endif

	try
	{
		if ( InitFrame() )
			m_mainFrameDock->Show();
		else
			exit(0);


	}
	catch( std::exception &e )
	{
		wxString message;
		message << wxString(e.what(), *wxConvCurrent);
		wxMessageBox( message );
	}
	catch( ... )
	{
		wxMessageBox( _("Unhandled exception ...") );
	}

	return true;
}
