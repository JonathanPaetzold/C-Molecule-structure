#include "Bond.h"

using namespace asst10;
using namespace std;

Bond::Bond() {

}

Bond::Bond(set<std::shared_ptr<Atom>> atoms) : set_(atoms) {

}

set<std::shared_ptr<Atom>> Bond::getAtoms() const noexcept {
    return shared_from_this()->set_;
}

int Bond::getCharge() const noexcept {
    return 0;
}

double Bond::getPolarity() const noexcept {
    return 0.0;
}

void Bond::setValue(double x) noexcept {
    x = 0;
    x = x + 1;
}
