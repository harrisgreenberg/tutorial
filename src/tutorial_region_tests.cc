#include <gtest/gtest.h>

#include "tutorial_region.h"

#include "agent_tests.h"
#include "region_tests.h"

using tutorial::TutorialRegion;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class TutorialRegionTest : public ::testing::Test {
 protected:
  cyclus::TestContext tc_;
  TutorialRegion* src_region_;

  virtual void SetUp() {
    src_region_ = new TutorialRegion(tc_.get());
  }

  virtual void TearDown() {}
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialRegionTest, clone) {
  TutorialRegion* cloned_fac = dynamic_cast<TutorialRegion*> (src_region_->Clone());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialRegionTest, InitialState) {
  // Test things about the initial state of the region here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialRegionTest, Print) {
  EXPECT_NO_THROW(std::string s = src_region_->str());
  // Test TutorialRegion specific aspects of the print method here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialRegionTest, Tick) {
  EXPECT_NO_THROW(src_region_->Tick());
  // Test TutorialRegion specific behaviors of the handleTick function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialRegionTest, Tock) {
  EXPECT_NO_THROW(src_region_->Tock());
  // Test TutorialRegion specific behaviors of the handleTock function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cyclus::Agent* TutorialRegionConstructor(cyclus::Context* ctx) {
  return new TutorialRegion(ctx);
}

// Required to get functionality in cyclus agent unit tests library
#ifndef CYCLUS_AGENT_TESTS_CONNECTED
int ConnectAgentTests();
static int cyclus_agent_tests_connected = ConnectAgentTests();
#define CYCLUS_AGENT_TESTS_CONNECTED cyclus_agent_tests_connected
#endif  // CYCLUS_AGENT_TESTS_CONNECTED

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
INSTANTIATE_TEST_CASE_P(TutorialRegion, RegionTests,
                        ::testing::Values(&TutorialRegionConstructor));
INSTANTIATE_TEST_CASE_P(TutorialRegion, AgentTests,
                        ::testing::Values(&TutorialRegionConstructor));
