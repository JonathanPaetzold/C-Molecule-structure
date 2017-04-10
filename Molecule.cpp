#include <string>
#include "Molecule.h"



using namespace asst10;
using namespace std;

Molecule::Molecule(string name) :name_(name) {
}


string Molecule::getName() const noexcept {
    return name_;
}

void Molecule::addBond(shared_ptr<Bond> bond) {
    // adds the given bond to the molecue's set of bonds
    atoms_.insert(bond);
    // sets all the atoms in the bond to this molecule
    for (auto p: bond->getAtoms()) {
        p->setMolecule(shared_from_this());
    }

}

set<shared_ptr<Atom>> Molecule::getAtoms() const noexcept {
    set<shared_ptr<Atom>> outputSet;
    for (auto p: atoms_) {
        for (auto x: p->getAtoms()) {
            outputSet.insert(x);
        }
    }
    return outputSet;
}

string Molecule::getFormula() const noexcept {
    // creates string to help process the data
    string tempstr("");
    string outputString("");
    // get the atoms of the molecule
    set<shared_ptr<Atom>>listA = getAtoms();
    // add all atom symbols into a string
    for (auto p: listA) {
        tempstr.append(p->getSymbol());
    }

    if(this->getAtoms().size() != 0) {


    //counts the number of times a symbol is in the string and appends together the appropriate formula
    char symb = tempstr.at(0);
    outputString += symb;
    int amount = 0;
    for (int index = 0; index < tempstr.length(); ++index) {
        if (tempstr.at(index) != symb) {
            symb = tempstr.at(index);
            // only print a number if the atom count is more than 1
            if (amount > 1) {
                outputString.append(to_string(amount));
            }
            amount = 0;
            outputString += symb;
            --index;
        }
        else {
            amount += 1;
            if(index == tempstr.length() - 1) {
                // only print a number if the atom count is more than 1
                if (amount > 1) {
                    outputString.append(to_string(amount));
                }
            }
        }
    }
    }

    return outputString;

}



