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

#ifndef CLOUDVIEWGLOBALSETTINGSCONTROL_H_
#define CLOUDVIEWGLOBALSETTINGSCONTROL_H_

#include <boost/function.hpp>

#include "wxFB/CloudViewGlobalSettingsControlModel.h"

class CloudViewGlobalSettingsControl : public CloudViewGlobalSettingsControlModel
{
	public:
		CloudViewGlobalSettingsControl(wxWindow* parent, boost::function<void()> notifyRefresh);
		virtual ~CloudViewGlobalSettingsControl();

		bool drawAxes() const { return m_drawAxes; }
		bool drawBBox() const { return m_drawBBox; }
		wxColour backgroundColor() const { return m_backgroundColor; }

		int far() const { return m_far; }
		double zoom() const { return m_zoom; }
		double translation() const { return m_translation; }
		double rotation() const { return m_rotation; }

	private:
		boost::function<void()> m_notifyRefresh;

		void OnOKButton(wxCommandEvent &event);
		void OnApplyButton(wxCommandEvent &event);
		void OnCloseWindow(wxCloseEvent& event);

		void OnBackgroundColor(wxColourPickerEvent& event);
		void OnDisplayAxes(wxCommandEvent &event);
		void OnDisplayBBox(wxCommandEvent &event);

		void refresh() { m_notifyRefresh(); }
		void apply();


		bool m_drawAxes;
		bool m_drawBBox;
		wxColour m_backgroundColor;

		int m_far;
		double m_zoom;
		double m_translation;
		double m_rotation;

		DECLARE_EVENT_TABLE();

};

#endif /* CLOUDVIEWGLOBALSETTINGSCONTROL_H_ */