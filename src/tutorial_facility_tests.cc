#include <gtest/gtest.h>

#include "tutorial_facility.h"

#include "agent_tests.h"
#include "context.h"
#include "facility_tests.h"

using tutorial::TutorialFacility;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class TutorialFacilityTest : public ::testing::Test {
 protected:
  cyclus::TestContext tc_;
  TutorialFacility* src_facility_;

  virtual void SetUp() {
    src_facility_ = new TutorialFacility(tc_.get());
  }

  virtual void TearDown() {}
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialFacilityTest, clone) {
  TutorialFacility* cloned_fac =
      dynamic_cast<TutorialFacility*> (src_facility_->Clone());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialFacilityTest, InitialState) {
  // Test things about the initial state of the facility here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialFacilityTest, Print) {
  EXPECT_NO_THROW(std::string s = src_facility_->str());
  // Test TutorialFacility specific aspects of the print method here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialFacilityTest, Tick) {
  ASSERT_NO_THROW(src_facility_->Tick());
  // Test TutorialFacility specific behaviors of the Tick function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialFacilityTest, Tock) {
  EXPECT_NO_THROW(src_facility_->Tock());
  // Test TutorialFacility specific behaviors of the Tock function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cyclus::Agent* TutorialFacilityConstructor(cyclus::Context* ctx) {
  return new TutorialFacility(ctx);
}

// Required to get functionality in cyclus agent unit tests library
#ifndef CYCLUS_AGENT_TESTS_CONNECTED
int ConnectAgentTests();
static int cyclus_agent_tests_connected = ConnectAgentTests();
#define CYCLUS_AGENT_TESTS_CONNECTED cyclus_agent_tests_connected
#endif  // CYCLUS_AGENT_TESTS_CONNECTED

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
INSTANTIATE_TEST_CASE_P(TutorialFac, FacilityTests,
                        ::testing::Values(&TutorialFacilityConstructor));

INSTANTIATE_TEST_CASE_P(TutorialFac, AgentTests,
                        ::testing::Values(&TutorialFacilityConstructor));
