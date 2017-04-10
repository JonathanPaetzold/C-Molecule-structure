#include "CovalentBond.h"
#include <memory>

using namespace asst10;
using namespace std;

CovalentBond::CovalentBond(set<std::shared_ptr<Atom>> atoms) :set_(atoms) {
    //ctor
}

set<std::shared_ptr<Atom>> CovalentBond::getAtoms() const noexcept {
    return set_;
}

double CovalentBond::getPolarity() const noexcept {
    return polarity_;
}

void CovalentBond::setValue(double x) noexcept {
    polarity_ = x;
}
