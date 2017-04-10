
#include "Atom.h"

#ifndef MOLECULE_H
#define MOLECULE_H

#include <string>
#include <set>
#include "Bond.h"




namespace asst10 {

class Atom;
class Bond;

/**
* Class representing a Molecule using sets.  A molecule has a name and a set of sets of Atoms,
* bonds of atoms can be added to Molecules.
*/
class Molecule :virtual public std::enable_shared_from_this<Molecule>
{
    public:

        /**
        * Constructs a Molecule with the given name
        */
        Molecule(std::string name);


        /**
        * gets the name of the moelcule
        * @return String the name
        */
        std::string getName() const noexcept;

        /**
        * Adds the given bond to the molecule
        * @param bond the bond to be added
        */
        void addBond(std::shared_ptr<Bond> bond);

        /**
        * Gets the set of atoms in the molecule
        * @return the set of atoms
        */
        std::set<std::shared_ptr<Atom>> getAtoms() const noexcept;

        /**
        * Computes the formula for a molecule and returns it
        * @return string of the formula
        */
        std::string getFormula() const noexcept;

        /**
        * Computes the amount of times the atom appears in bonds
        * @return int number of bonds the atom appears in
        */
        int boundCount(std::shared_ptr<Atom> a) const noexcept;

    protected:
    private:
        /** String name of molecule. */
        std::string name_;
        /** Set of Bonds in the Molecule. */
        std::set<std::shared_ptr<Bond>> atoms_;

};

}

#endif // MOLECULE_H
