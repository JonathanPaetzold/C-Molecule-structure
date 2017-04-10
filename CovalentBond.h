#ifndef COVALENTBOND_H
#define COVALENTBOND_H

#include <Bond.h>

namespace asst10 {

/**
* Class representing a Covalent Bond.  A Covalent bond is a subclass of Bond and has a unique polairty
*/
class CovalentBond : public Bond
{
    public:
        /**
        * Constructs a covalent bond with the given set of atoms
        * @param atoms ,set of atoms to be added
        */
        CovalentBond(std::set<std::shared_ptr<Atom>> atoms);

        /**
        * returns the atoms in this bond
        * @return set of pointers to atoms
        */
        virtual std::set<std::shared_ptr<Atom>> getAtoms() const noexcept;

        /**
        * Returns the polarity of the bond
        * @return double polarity
        */
        virtual double getPolarity() const noexcept;

        /**
        * sets the unique value of the bond's polarity
        * @param x double to be set
        */
        virtual void setValue(double x) noexcept;

    protected:
    private:
        /** set of shared pointers to atoms of the bond. */
        std::set<std::shared_ptr<Atom>> set_;

        /** double polarity of the bond. */
        double polarity_;
};

}

#endif // COVALENTBOND_H
