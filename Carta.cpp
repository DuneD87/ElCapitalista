
#include "Carta.h"

Carta::Carta() {
    _pal = 'O'; //1 d'ors per defecte ?
    _valor = 1;
}

Carta::Carta(int pal, int valor) {
    _pal = pal;
    _valor = valor;
}

bool Carta::operator>(const Carta& c) const {
    bool esMajor = false;
    if (_valor > 2 && c._valor > 2) {  // els dos son ems grans que 2
        esMajor = _valor > c._valor;
        if (_valor == c._valor)
            esMajor = _pal > c._pal;
    }else if (_valor <= 2 && c._valor > 2)
        esMajor = true;
    else if (_valor > 2 && c._valor <= 2)
        esMajor = false;
    else if (_valor <= 2 && c._valor <= 2) {
        esMajor = _valor > c._valor;
        if (_valor == c._valor)
            esMajor = _pal > c._pal;
    }
    
    return esMajor;
}

bool Carta::operator<(const Carta& c) const {
    bool esMajor = false;
    if (_valor > 2 && c._valor > 2) {  // els dos son ems grans que 2
        esMajor = _valor < c._valor;
        if (_valor == c._valor)
            esMajor = _pal < c._pal;
    }else if (_valor <= 2 && c._valor > 2)
        esMajor = false;
    else if (_valor > 2 && c._valor <= 2)
        esMajor = true;
    else if (_valor <= 2 && c._valor <= 2) {
        esMajor = _valor < c._valor;
        if (_valor == c._valor)
            esMajor = _pal < c._pal;
    }
    return esMajor;
}

std::string Carta::toString() const {
    std::stringstream s;
    char pal[4] = {'O', 'C', 'E', 'B'};
    s << "[" << _valor << pal[_pal] << "]";
    return s.str();
}

int Carta::valor() const {
    return _valor;
}

int Carta::pal() const {
    return _pal;
}
