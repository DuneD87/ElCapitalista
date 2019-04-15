
#include "TaulaDinamica.h"

template<class element>
TaulaDinamica<element>::TaulaDinamica() {
    _maxElems = 10; //Inicialment reservem memoria per 10 elements si no s'especifica maxim
    _nElems = 0;
    reservar();
}

template<class element>
TaulaDinamica<element>::TaulaDinamica(int max) {
    _maxElems = max;
    _nElems = 0;
    reservar();
}

template<class element>
bool TaulaDinamica<element>::afegir(element& e) {
    if (_nElems >= _maxElems) ampliar(); //Si el nombre d'elements es igual al nombre maxim d'elements - 1, dupliquem la mida de la taula
    bool trobat = false;
    int pos = 0;
    cercaBinaria(e,pos,trobat);
    if (!trobat) {
        for (int i = _nElems ; i > pos; i--)
            _taula[i] = _taula[i - 1];
        _taula[pos] = e;
        _nElems++;
        return true;
    }
}

template<class element>
void TaulaDinamica<element>::allibera() {
    delete [] _taula;
}

template<class element>
void TaulaDinamica<element>::ampliar() {
    int maxElems = _maxElems*2;
    element * t = new element[maxElems];
    for (int i = 0; i < _nElems; i++) 
        t[i] = _taula[i];
    delete [] _taula;
    _taula = t;
    _maxElems = maxElems;
}

template<class element>
void TaulaDinamica<element>::copia(const TaulaDinamica& t) {
    allibera(); //alliberem memoria primer
    _nElems = t._nElems;
    _maxElems = t._maxElems;
    reservar();//reservem memoria amb nous atributs
    for (int i = 0; i < _nElems; i++)
        _taula[i] = t._taula[i]; // assignem
}

template<class element>
element & TaulaDinamica<element>::eliminar(element& e) {
    //TODO: eliminar element mantenin l'ordre
}

template<class element>
TaulaDinamica<element>& TaulaDinamica<element>::operator=(const TaulaDinamica& t) {
    allibera();
    copia(t);
}

template<class element>
element& TaulaDinamica<element>::operator[](int i) {
    return _taula[i]; //Seg Fault
}

template<class element>
void TaulaDinamica<element>::reservar() {
    _taula = new element[_maxElems];
}

template<class element>
int TaulaDinamica<element>::tamany() const {
    return _nElems;
}

template<class element>
std::string TaulaDinamica<element>::toString() const {

}

template<class element>
TaulaDinamica<element>::~TaulaDinamica() {
    allibera();
}

template<class element>
bool TaulaDinamica<element>::cercar(element& e) {
    bool trobat = false;
    int pos = 0;
    cercaBinaria(e,pos,trobat);
    return trobat;
}

template<class element>
void TaulaDinamica<element>::cercaBinaria(element& e, int& pos, bool& trobat) {
    int esq = 0, dret = _nElems - 1,mig;
    while (!trobat && esq<=dret) {
        mig = (esq + dret) / 2;
        if (e > _taula[mig]) esq = mig + 1;
        else if (e < _taula[mig]) dret = mig - 1;
        else trobat =  true;
    }
    if (!trobat) pos = esq;
    else pos = mig;
}


template class TaulaDinamica<Carta>;