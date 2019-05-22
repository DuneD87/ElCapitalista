
#include "Jugador.h"

Jugador::Jugador() {
}

Jugador::Jugador(std::string nom) {
    _nom = nom;
}

void Jugador::afegirCarta(const Carta& c) {

    _ma.afegir(c);
}

void Jugador::eliminarConjuntCartes(int nCartes, int valor, PilaCartes & p) {
    int nCartesEliminades = 0;
    for (int i = 0; i < _ma.tamany(); i++)
        if (_ma.elem(i).valor() == valor && nCartesEliminades < nCartes) {
            std::cout<<_ma.elem(i).toString();
            p.empila(_ma.elem(i));
            _ma.eliminar(_ma.elem(i));
            nCartesEliminades++;
        }
}

std::string Jugador::toString() const {
    return _nom;
}

bool Jugador::teCartesRepetides(int nCartes, int valor) {
    int n = 0;
                    
    for (int i = 0; i < nCartes; i++) {
        //Mirem si existeixen n cartes amb el valor donat
        for (int j = 0 ; j < _ma.tamany(); j++) {
            if (_ma.elem(j).valor() == valor)
                n++;
        }
    }
    
    return n >= nCartes;
}

bool Jugador::quedenCartes() const {
    return _ma.tamany() > 0;
}

void Jugador::mostrarMa() const {
    std::cout<<_ma.toString()<<'\n';
}
