#ifndef BOND_H
#define BOND_H

#include <set>
#include <memory>
#include "Molecule.h"


namespace asst10 {

class Atom;

/**
* Class representing a Bond of atoms.  An Bond is an abstract class that has two subclasses Covalent and Ioinc
* Bonds.
*/
class Bond : virtual public std::enable_shared_from_this<Bond>
{
    public:
        /**
        * Constructs a empty bond
        */
        Bond();
        /**
        * Constructs a bond with given atoms
        * @param atoms ,set of atoms to be added
        */
        Bond(std::set<std::shared_ptr<Atom>> atoms);

        /**
        * returns the atoms in this bond
        * @return set of pointers to atoms
        */
        virtual std::set<std::shared_ptr<Atom>> getAtoms() const noexcept;

        /**
        * Returns the charge of the bond
        * @return int charge
        */
        virtual int getCharge() const noexcept;

        /**
        * Returns the polarity of the bond
        * @return double polarity
        */
        virtual double getPolarity() const noexcept;

        /**
        * sets the unique value of the bond charge/polarity
        * @param x double to be set
        */
        virtual void setValue(double x)  noexcept = 0;

    protected:
    private:
        /** set of shared pointers to atoms of the bond. */
        std::set<std::shared_ptr<Atom>> set_;
};
}

#endif // BOND_H
