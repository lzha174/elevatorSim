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

#include "Elevator.hpp"
#include "Building.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/test/detail/unit_test_parameters.hpp>
#include <fstream>

namespace elevatorSim {

struct BuildingFixture {

   static Building* testBuilding;
   static const int testStoryCount = 10;
   static const int testElevCount = 1;

   BuildingFixture();
   ~BuildingFixture();
};

Building* BuildingFixture::testBuilding = NULL;

BuildingFixture::BuildingFixture() {
   testBuilding = new Building(testStoryCount, testElevCount);
}

BuildingFixture::~BuildingFixture() {
   delete testBuilding;
}

} /* namespace elevatorSim */

BOOST_AUTO_TEST_SUITE( building_integration_tests )

BOOST_FIXTURE_TEST_CASE( 
   building_initialization_test, 
   elevatorSim::BuildingFixture ) {
      BOOST_REQUIRE_EQUAL(
         BuildingFixture::testBuilding->getStories(),
         BuildingFixture::testStoryCount );

      BOOST_REQUIRE_EQUAL(
         BuildingFixture::testBuilding->getMaxElev(),
         BuildingFixture::testElevCount );
}

BOOST_FIXTURE_TEST_CASE( 
   building_another_test, elevatorSim::BuildingFixture ) {
    BOOST_REQUIRE_EQUAL(1, 1); /* TODO: stub */
}

BOOST_AUTO_TEST_SUITE_END()
