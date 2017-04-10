#include <iostream>

#include "Atom.h"
#include "Molecule.h"
#include "Bond.h"
#include "CovalentBond.h"
#include "IonicBond.h"

using namespace std;
using namespace asst10;

/**
 * \namespace asst10 Design of Atoms Molecules and Bonds.  Atoms and Molecules are constucted as smart pointers with
 * either ionic or covalent bonds.
 */

/**
* main method constructs Atoms Molecules and different Bonds.  The main methods checks to see if
* the methods of these clasess work properly.
*/
int main() {
    // constructs atoms as smart shared pointers
    std::shared_ptr<Atom> carbon1(new Atom("C"));
    std::shared_ptr<Atom> carbon2(new Atom("C"));
    std::shared_ptr<Atom> carbon3(new Atom("C"));
    std::shared_ptr<Atom> carbon4(new Atom("C"));
    std::shared_ptr<Atom> carbon5(new Atom("C"));
    std::shared_ptr<Atom> carbon6(new Atom("C"));
    std::shared_ptr<Atom> hydrogen1(new Atom("H"));
    std::shared_ptr<Atom> hydrogen2(new Atom("H"));
    std::shared_ptr<Atom> hydrogen3(new Atom("H"));
    std::shared_ptr<Atom> hydrogen4(new Atom("H"));
    std::shared_ptr<Atom> hydrogen5(new Atom("H"));
    std::shared_ptr<Atom> hydrogen6(new Atom("H"));
    std::shared_ptr<Atom> hydrogen7(new Atom("H"));
    std::shared_ptr<Atom> hydrogen8(new Atom("H"));
    std::shared_ptr<Atom> oxygen(new Atom("O"));
    std::shared_ptr<Atom> chloride(new Atom("Cl"));
    std::shared_ptr<Atom> sodium(new Atom("Na"));


    // constructs the weak pointers for Molecule to break the cycle
    std::shared_ptr<Molecule> w(new Molecule("Water"));
    std::shared_ptr<Molecule> b(new Molecule("Benzene"));
    std::shared_ptr<Molecule> s(new Molecule("Salt"));
    std::shared_ptr<Molecule> e(new Molecule("Empty"));
    std::weak_ptr<Molecule> water = w;
    std::weak_ptr<Molecule> benzene = b;
    std::weak_ptr<Molecule> salt = s;
    std::weak_ptr<Molecule> empt = e;

    //constructing  the sets of atoms and Bonds
    set<shared_ptr<Atom>> ohBond1 = {hydrogen7, oxygen};
    set<shared_ptr<Atom>> ohBond2 = {hydrogen8, oxygen};
    set<shared_ptr<Atom>> NaClBond = {chloride, sodium};
    set<shared_ptr<Atom>> chBond1 = {carbon1, hydrogen1};
    set<shared_ptr<Atom>> chBond2 = {carbon2, hydrogen2};
    set<shared_ptr<Atom>> chBond3 = {carbon3, hydrogen3};
    set<shared_ptr<Atom>> chBond4 = {carbon4, hydrogen4};
    set<shared_ptr<Atom>> chBond5 = {carbon5, hydrogen5};
    set<shared_ptr<Atom>> chBond6 = {carbon6, hydrogen6};
    set<shared_ptr<Atom>> cBond = {carbon1, carbon2, carbon3, carbon4, carbon5, carbon6};
    std::shared_ptr<CovalentBond> ohBond1C (new CovalentBond(ohBond1));
    std::shared_ptr<CovalentBond> ohBond2C (new CovalentBond(ohBond2));
    std::shared_ptr<IonicBond> NaClBondI (new IonicBond(NaClBond));
    std::shared_ptr<CovalentBond> chBond1C (new CovalentBond(chBond1));
    std::shared_ptr<CovalentBond> chBond2C (new CovalentBond(chBond2));
    std::shared_ptr<CovalentBond> chBond3C (new CovalentBond(chBond3));
    std::shared_ptr<CovalentBond> chBond4C (new CovalentBond(chBond4));
    std::shared_ptr<CovalentBond> chBond5C (new CovalentBond(chBond5));
    std::shared_ptr<CovalentBond> chBond6C (new CovalentBond(chBond6));
    std::shared_ptr<CovalentBond> cBondC (new CovalentBond(cBond));

    //using weak pointers as shared pointers using lock and adding bonds to them
    water.lock()->addBond(ohBond1C);
    water.lock()->addBond(ohBond2C);
    salt.lock()->addBond(NaClBondI);
    benzene.lock()->addBond(cBondC);
    benzene.lock()->addBond(chBond1C);
    benzene.lock()->addBond(chBond2C);
    benzene.lock()->addBond(chBond3C);
    benzene.lock()->addBond(chBond4C);
    benzene.lock()->addBond(chBond5C);
    benzene.lock()->addBond(chBond6C);


    // checking to see that atoms have the right symbols
    cout << endl;
    cout << "carbon's symbol is:" + carbon1->getSymbol() << endl;
    cout << "oxygen's symbol is:" + oxygen->getSymbol() << endl;
    cout << "hydrogen's symbol is:" + hydrogen1->getSymbol() << endl;
    cout << "sodium's symbol is:" + sodium->getSymbol() << endl;
    cout << "chloride's symbol is:" + chloride->getSymbol() << endl;

    // checking to see that Molecules have the right names
    cout << endl;
    cout << "water's name is:" + water.lock()->getName() << endl;
    cout << "salts's name is:" + salt.lock()->getName() << endl;
    cout << "benzene's name is:" + benzene.lock()->getName() << endl;
    cout << "empty's name is:" + empt.lock()->getName() << endl;

    // checking to see that Molecules have the right formula
    cout << "water's formula is:" + water.lock()->getFormula() << endl;
    cout << "salts's formula is:" + salt.lock()->getFormula()  << endl;
    cout << "benzene's formula is:" + benzene.lock()->getFormula()  << endl;
    cout << "empty's formula is:" + empt.lock()->getFormula() << endl;

    // checking to see if an exception is thrown when an atom is in two molecules
    try {
        water.lock()->addBond(NaClBondI);

    }
    catch (domain_error x) {
        cout << x.what() << endl;
    }






}
