
#include "Carta.h"

Carta::Carta() {
    _pal = 'O'; //1 d'ors per defecte ?
    _valor = 1;
}

Carta::Carta(char pal, int valor) {
    _pal = pal;
    _valor = valor;
}

bool Carta::operator>(const Carta& c) const {
    bool esMajor = false;
    if (_valor > 3 && c._valor > 3)
        esMajor = _valor > c._valor;
    else if (_valor > 3 && c._valor < 3)
        esMajor = true;
    else if (_valor < 3 && c._valor > 3)
        esMajor = false;
    else { // son iguals, comparem per pals
        if (_pal == 'B' && c._pal != 'B')
            esMajor = true;
        else if (_pal == 'E' && c._pal != 'B' && c._pal != 'E')
            esMajor = true;
        else if (_pal == 'C' && c._pal == 'O')
            esMajor = true;
    }
    return esMajor;
}

bool Carta::operator<(const Carta& c) const {
    bool esMenor = false;
    esMenor = _valor < c._valor;
    if (_valor == c._valor) {
        if (_pal == 'O' && c._pal != 'O')
            esMenor = true;
        else if (_pal == 'B' && c._pal != 'B' && c._pal != 'O')
            esMenor = true;
        else if (_pal == 'E' && c._pal == 'C')
            esMenor = true;
    }
    return esMenor;
}

std::string Carta::toString() const {
    std::stringstream s;
    s << "[" << _valor << _pal << "]";
    return s.str();
}

int Carta::valor() const {
    return _valor;
}
