#include "Atom.h"

using namespace asst10;
using namespace std;

Atom::Atom(string symbol) : symbol_(symbol), partOf_(nullptr) {

}


string Atom::getSymbol() const noexcept {
    return symbol_;
}

shared_ptr<Molecule> Atom::getMolecule() const noexcept {
    return partOf_;
}

void Atom::setMolecule(shared_ptr<Molecule> m) {

    // checks to see if someone is trying to set the atom to no molecule

    if (m == nullptr) {
        throw domain_error("Cannot set the Atom to not be a part of a molecule ");
    }

    // if the atom isnt a part of a molecule add it to the moelcule
    else if (partOf_ == nullptr) {
        partOf_ = m;
    }
    //if its the same molecule do nothing
    else if(partOf_ == m) {

    }
    // if its a different molecule throw and excpetion
    else {
        throw domain_error("Cannot set the Atom's molecule after it has been set before");
    }
}
