#ifndef ATOM_H
#define ATOM_H
#include <string>
#include <stdexcept>
#include "Molecule.h"




namespace asst10 {

/**
* Class representing an Atom.  An Atom has a symbol to represent which atom it is and can
* be set to a molecule.
*/
class Atom
{
    public:
        /**
        * Constructs an Atom with the given symbol
        */
        Atom(std::string symbol);

        /**
        * Returns the symbol of the atom
        * @return String the symbol
        */
        std::string getSymbol() const noexcept;

        /**
        * Returns the Molecule the atom is assigned to
        * @return Molecule assigned too
        */
        std::shared_ptr<Molecule> getMolecule() const noexcept;

        /**

        * Sets the Atom in to a molecule
        * @param Molecule the molecule this atom will be added to
        * @throw DomainError if the setter tries to set it to no molecule or if it tries to change the molecule it belongs to
        */
        void setMolecule(std::shared_ptr<Molecule> m);

    protected:
    private:
        /** String symbol. */
        std::string symbol_;
        /** Molecule this atom belongs to. */
        std::shared_ptr<Molecule> partOf_;



};

}

#endif // ATOM_H
