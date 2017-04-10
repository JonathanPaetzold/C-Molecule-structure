#ifndef IONICBOND_H
#define IONICBOND_H

#include <Bond.h>

namespace asst10 {

/**
* Class representing an Ionic Bond.  An Ionic bond is a subclass of Bond and has a unique charge
*/
class IonicBond : public Bond
{
    public:
        /**
        * Constructs an IonicBond with given atoms
        * @param atoms ,set of atoms to be added
        */
        IonicBond(std::set<std::shared_ptr<Atom>> atoms);

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
        * sets the unique value of the bond charge
        * @param x double to be set
        */
        virtual void setValue(double x) noexcept;

    protected:
    private:
        /** set of shared pointers to atoms of the bond. */
        std::set<std::shared_ptr<Atom>> set_;

        /** int charge of the bond. */
        int charge_;
};

}

#endif // IONICBOND_H
