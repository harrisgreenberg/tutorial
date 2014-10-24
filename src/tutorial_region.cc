#include "tutorial_region.h"

using tutorial::TutorialRegion;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TutorialRegion::TutorialRegion(cyclus::Context* ctx) : cyclus::Region(ctx) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TutorialRegion::~TutorialRegion() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string TutorialRegion::str() {
  return Region::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructTutorialRegion(cyclus::Context* ctx) {
  return new TutorialRegion(ctx);
}
