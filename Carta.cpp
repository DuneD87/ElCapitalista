
#include "Carta.h"

Carta::Carta() {
    _pal = 'O'; //1 d'ors per defecte ?
    _valor = 1;
}

Carta::Carta(char pal, int valor,int ordre) {
    _pal = pal;
    _valor = valor;
    _ordre = ordre;
}

bool Carta::operator>(const Carta& c) const {
    bool esMenor = false;
    if (_ordre == 1) {
        esMenor = _valor > c._valor;
        if (_valor == c._valor) {
            if (_pal == 'B' && c._pal != 'B')
                esMenor = true;
            else if (_pal == 'E' && c._pal != 'B' && c._pal != 'E')
                esMenor = true;
            else if (_pal == 'C' && c._pal == 'O')
                esMenor = true;
        }
    } else {
        if (_pal == 'B' && c._pal != 'B')
            esMenor = true;
        else if (_pal == 'E' && c._pal != 'B' && c._pal != 'E')
            esMenor = true;
        else if (_pal == 'C' && c._pal == 'O')
            esMenor = true;
        else if (_pal == _pal)
            esMenor = _valor > c._valor;
    }
    return esMenor;
}

bool Carta::operator<(const Carta& c) const {
    bool esMajor = false;
    if (_ordre == 1) {
        esMajor = _valor < c._valor;
        if (_valor == c._valor) {
            if (_pal == 'O' && c._pal != 'O')
                esMajor = true;
            else if (_pal == 'B' && c._pal != 'B' && c._pal != 'O')
                esMajor = true;
            else if (_pal == 'E' && c._pal == 'C')
                esMajor = true;
        }
    } else {
        if (_pal == 'O' && c._pal != 'O')
            esMajor = true;
        else if (_pal == 'B' && c._pal != 'B' && c._pal != 'O')
            esMajor = true;
        else if (_pal == 'E' && c._pal == 'C')
            esMajor = true;
        else if (_pal == _pal)
            esMajor = _valor < c._valor;
    }
    return esMajor;
}

std::string Carta::toString() const {
    std::string s = "[" + std::to_string(_valor) + _pal + "]";
    return s;
}

void Carta::setOrdre(int ordre) {
    _ordre = ordre;
}

int Carta::valor() const {
    return _valor;
}
