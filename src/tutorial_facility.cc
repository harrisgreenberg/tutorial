#include "tutorial_facility.h"

namespace tutorial {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TutorialFacility::TutorialFacility(cyclus::Context* ctx) : cyclus::Facility(ctx) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string TutorialFacility::str() {
  return Facility::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void TutorialFacility::Tick() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void TutorialFacility::Tock() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructTutorialFacility(cyclus::Context* ctx) {
  return new TutorialFacility(ctx);
}

}  // namespace tutorial
