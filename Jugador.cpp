
#include "Jugador.h"

Jugador::Jugador() {
}

Jugador::Jugador(std::string nom) {
    _nom = nom;
}

void Jugador::afegirCarta(const Carta& c) {
    _ma.inserir(c);
}

void Jugador::eliminarConjuntCartes(int nCartes, int valor) {
    for (int i = 0 ; i < nCartes; i++)
        if (!_ma.esFi())
            if (_ma.elem().valor() == valor)
                _ma.esborrar(_ma.elem());
}

std::string Jugador::toString() const {
    return _nom;
}

