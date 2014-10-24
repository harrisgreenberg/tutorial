#include "tutorial_facility.h"

namespace tutorial {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TutorialFacility::TutorialFacility(cyclus::Context* ctx) : cyclus::Facility(ctx) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string TutorialFacility::str() {
  return Facility::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void TutorialFacility::Tick() {
  LOG(cyclus::LEV_INFO1,"tutorial_storage") << "Hello...";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void TutorialFacility::Tock() {
  LOG(cyclus::LEV_INFO1,"tutorial_storage") << " World";
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructTutorialFacility(cyclus::Context* ctx) {
  return new TutorialFacility(ctx);
}

}  // namespace tutorial
