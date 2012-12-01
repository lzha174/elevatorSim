/*
 * Copyright (c) 2012, Joseph Max DeLiso, Daniel Gilbert
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
#include "ElevatorSimStartWindow.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/FL_Input.H>
#include <FL/FL_Button.H>

namespace elevatorSim {

/* public static member initializers */
const char ElevatorSimStartWindow::WINDOW_TITLE[] = "Start";
const int ElevatorSimStartWindow::WINDOW_WIDTH = 300;
const int ElevatorSimStartWindow::WINDOW_HEIGHT = 200;

int ElevatorSimStartWindow::handle(int event) {
   return Fl_Window::handle(event);
}

void ElevatorSimStartWindow::inputAcceptCB(Fl_Window* w, void* userData) {
   if(isDebugBuild()) {
      std::stringstream dbgSS;
      dbgSS << "inputAcceptCB fired with widget ptr " << w << std::endl;
      LOG_INFO( Logger::SUB_FLTK, sstreamToBuffer(dbgSS) );
   }

}

void ElevatorSimStartWindow::inputCancelCB(Fl_Window* w, void* userData) {
   if(isDebugBuild()) {
      std::stringstream dbgSS;
      dbgSS << "inputCancelCB fired with widget ptr " << w << std::endl;
      LOG_INFO( Logger::SUB_FLTK, sstreamToBuffer(dbgSS) );
   }
   
}

/* public methods */
ElevatorSimStartWindow::ElevatorSimStartWindow() :
   Fl_Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {
      elevatorNum = new Fl_Input(100, 20, 140, 30, "# of elevators:");
      floorNum = new Fl_Input(100, 70, 140, 30, "# of floors:");
      seedNum = new Fl_Input(100, 120, 140, 30, "Random seed:");

      inputAccept = new Fl_Button(100, 170, 140, 30, "Accept");
      inputCancel = new Fl_Button(100, 220, 140, 30, "Cancel");
      inputAccept->callback((Fl_Callback*) inputAcceptCB, this);
      inputCancel->callback((Fl_Callback*) inputCancelCB, this);
   
      floorNum->clear_visible_focus();
      seedNum->clear_visible_focus();
      inputCancel->clear_visible_focus();
      inputAccept->clear_visible_focus();

      add(floorNum);
      add(elevatorNum);
      add(seedNum);
      add(inputCancel);
      add(inputAccept);
   
      end();
}

ElevatorSimStartWindow::~ElevatorSimStartWindow() {
   delete inputCancel;
   delete inputAccept;
   
   delete seedNum;
   delete floorNum;
   delete elevatorNum;
}

} /* namespace elevatorSim */