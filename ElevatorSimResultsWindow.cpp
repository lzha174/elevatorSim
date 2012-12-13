/*
 * Copyright (c) 2012, Joseph Max DeLiso
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the FreeBSD Project.
 */

#include "ElevatorSim.hpp"
#include "ElevatorSimResultsWindow.hpp"
#include "SimulationState.hpp"
#include "Logger.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <Fl/Fl_Chart.H>

#include <boost/lexical_cast.hpp>
#include <fstream>

namespace elevatorSim {

/* public static member initializers */
const char ElevatorSimResultsWindow::WINDOW_TITLE[] = "Simulation Report";
const int ElevatorSimResultsWindow::WINDOW_WIDTH = 512;
const int ElevatorSimResultsWindow::WINDOW_HEIGHT = 316;
const int ElevatorSimResultsWindow::CHART_BORDER_WIDTH = 10;
const int ElevatorSimResultsWindow::CHART_BORDER_HEIGHT = 25;
const char ElevatorSimResultsWindow::CHART_TITLE[] =
   "Entrances and Exits over time";

/* public methods */
ElevatorSimResultsWindow::ElevatorSimResultsWindow() :
            Fl_Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {

   resultsChart = new Fl_Chart(
      CHART_BORDER_WIDTH,
      CHART_BORDER_HEIGHT,
      WINDOW_WIDTH - 2 * CHART_BORDER_WIDTH,
      WINDOW_HEIGHT - 2 * CHART_BORDER_HEIGHT,
      CHART_TITLE);

   resultsChart->type(FL_SPIKE_CHART);



   /* TODO: loop over SimulationState.getEntrancesExits... */

   resultsChart->autosize(1);

   resizable(*resultsChart);
   end();
}

int ElevatorSimResultsWindow::handle(int event) {
   if(isDebugBuild()) {
      std::stringstream dbgSS;
      dbgSS << event << std::endl;
      LOG_INFO( Logger::SUB_FLTK, sstreamToBuffer(dbgSS) );
   }

   return Fl_Window::handle(event);
}

ElevatorSimResultsWindow::~ElevatorSimResultsWindow() {
   delete resultsChart;

   if(isDebugBuild()) {
      std::stringstream dbgSS;
      dbgSS << "finished destroying results window @ " << this << std::endl;
      LOG_INFO( Logger::SUB_MEMORY, sstreamToBuffer(dbgSS) );
   }
}

} /* namespace elevatorSim */
