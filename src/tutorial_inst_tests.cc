#include <gtest/gtest.h>

#include <string>

#include "tutorial_inst.h"

#include "institution_tests.h"
#include "agent_tests.h"

using tutorial::TutorialInst;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class TutorialInstTest : public ::testing::Test {
 protected:
  cyclus::TestContext tc_;
  TutorialInst* src_inst_;

  virtual void SetUp() {
    src_inst_ = new TutorialInst(tc_.get());
  }

  virtual void TearDown() {}
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialInstTest, clone) {
  TutorialInst* cloned_fac = dynamic_cast<TutorialInst*> (src_inst_->Clone());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialInstTest, InitialState) {
  // Test things about the initial state of the inst here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialInstTest, Print) {
  EXPECT_NO_THROW(std::string s = src_inst_->str());
  // Test TutorialInst specific aspects of the print method here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialInstTest, Tick) {
  int time = 1;
  EXPECT_NO_THROW(src_inst_->Tick());
  // Test TutorialInst specific behaviors of the handleTick function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TEST_F(TutorialInstTest, Tock) {
  int time = 1;
  EXPECT_NO_THROW(src_inst_->Tock());
  // Test TutorialInst specific behaviors of the handleTock function here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cyclus::Agent* TutorialInstitutionConstructor(cyclus::Context* ctx) {
  return new TutorialInst(ctx);
}

// Required to get functionality in cyclus agent unit tests library
#ifndef CYCLUS_AGENT_TESTS_CONNECTED
int ConnectAgentTests();
static int cyclus_agent_tests_connected = ConnectAgentTests();
#define CYCLUS_AGENT_TESTS_CONNECTED cyclus_agent_tests_connected
#endif  // CYCLUS_AGENT_TESTS_CONNECTED

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
INSTANTIATE_TEST_CASE_P(TutorialInst, InstitutionTests,
                        ::testing::Values(&TutorialInstitutionConstructor));
INSTANTIATE_TEST_CASE_P(TutorialInst, AgentTests,
                        ::testing::Values(&TutorialInstitutionConstructor));
