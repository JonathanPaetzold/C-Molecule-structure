#include "IonicBond.h"


using namespace asst10;
using namespace std;

IonicBond::IonicBond(set<std::shared_ptr<Atom>> atoms) :set_(atoms) {
    //ctor
}

set<std::shared_ptr<Atom>> IonicBond::getAtoms() const noexcept {
    return set_;
}

int IonicBond::getCharge() const noexcept {
    return charge_;
}

void IonicBond::setValue(double x) noexcept {
    //double cast to int
    int y = (int) x;
    charge_ = y;
}


