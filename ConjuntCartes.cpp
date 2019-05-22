
#include "ConjuntCartes.h"

ConjuntCartes::ConjuntCartes() {
    _maxElems = 10; //Inicialment reservem memoria per 10 Cartas si no s'especifica maxim
    _nElems = 0;
    reservar();
}

ConjuntCartes::ConjuntCartes(int max) {
    _maxElems = max;
    _nElems = 0;
    reservar();
}

void ConjuntCartes::afegir(const Carta& e) {
    if (_nElems >= _maxElems) ampliar(); //Si el nombre d'Cartas es igual al nombre maxim d'Cartas - 1, dupliquem la mida de la taula
    bool trobat = false;
    int pos = 0;
    cercaBinaria(e, pos, trobat);
    for (int i = _nElems; i > pos; i--)
        _taula[i] = _taula[i - 1];
    _taula[pos] = e;
    _nElems++;
}

void ConjuntCartes::allibera() {
    delete [] _taula;
}

void ConjuntCartes::ampliar() {
    int maxElems = _maxElems * 2;
    Carta * t = new Carta[maxElems];
    for (int i = 0; i < _nElems; i++)
        t[i] = _taula[i];
    delete [] _taula;
    _taula = t;
    _maxElems = maxElems;
}

void ConjuntCartes::copia(const ConjuntCartes& t) {
    allibera(); //alliberem memoria primer
    _nElems = t._nElems;
    _maxElems = t._maxElems;
    reservar(); //reservem memoria amb nous atributs
    for (int i = 0; i < _nElems; i++)
        _taula[i] = t._taula[i]; // assignem
}

void ConjuntCartes::eliminar(const Carta& e) {
    int pos = 0;
    bool trobat = false;
    cercaBinaria(e,pos,trobat);
    for (int i = pos; i < _nElems - 1; i++)
        _taula[i] = _taula[i + 1];
    _nElems--;
}

ConjuntCartes& ConjuntCartes::operator=(const ConjuntCartes& t) {
    allibera();
    copia(t);
}

Carta& ConjuntCartes::elem(int j) {
    return _taula[j];
}


void ConjuntCartes::reservar() {
    _taula = new Carta[_maxElems];
}

int ConjuntCartes::tamany() const {
    return _nElems;
}

std::string ConjuntCartes::toString() const {
    std::string res;
    for (int i = 0; i < _nElems; i++)
        res = res + _taula[i].toString();
    return res;
}

ConjuntCartes::~ConjuntCartes() {
    allibera();
}

bool ConjuntCartes::cercar(const Carta& e) {
    bool trobat = false;
    int pos = 0;
    cercaBinaria(e, pos, trobat);
    return trobat;
}

void ConjuntCartes::cercaBinaria(const Carta& e, int& pos, bool& trobat) {
    int esq = 0, dret = _nElems - 1, mig;
    while (!trobat && esq <= dret) {
        mig = (esq + dret) / 2;
        if (e > _taula[mig]) esq = mig + 1;
        else if (e < _taula[mig]) dret = mig - 1;
        else trobat = true;
    }
    if (!trobat) pos = esq;
    else pos = mig;
}


