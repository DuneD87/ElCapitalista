
#include "Jugador.h"

Jugador::Jugador() {
}

Jugador::Jugador(std::string nom) {
    _nom = nom;
}

void Jugador::afegirCarta(const Carta& c) {
    _ma.afegir(c);
}

void Jugador::eliminarConjuntCartes(int nCartes, int valor) {
    for (int i = 0; i < nCartes; i++)
        if (_ma[i].valor() == valor)
            _ma.eliminar(_ma[i]);
}

std::string Jugador::toString() const {
    return _nom;
}

bool Jugador::teCartes(int nCartes, int valor) {
    int n = 0;
    for (int i = 0; i < nCartes; i++) {
        //Mirem si existeixen n cartes amb el valor donat
        
    }
}
