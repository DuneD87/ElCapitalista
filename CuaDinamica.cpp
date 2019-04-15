
#include "CuaDinamica.h"

template<class element>
CuaDinamica<element>::CuaDinamica() {
    _primer=_darrer=NULL;
}
template<class element>
CuaDinamica<element>::CuaDinamica(const CuaDinamica& orig) {
    _primer=_darrer=NULL;
    copia(orig);
}

template<class element>
CuaDinamica<element>::~CuaDinamica() {
    allibera();
}

template<class element>
void CuaDinamica<element>::Desencua() {
    Node *aux = _primer;
    if (_primer == _darrer) //Nomes tenim un element
        _primer = _darrer = NULL;
    else
        _primer = _primer->seguent;
    delete aux;
}

template<class element>
void CuaDinamica<element>::Encua(const element& e) {
    Node *p = new Node; //bad alloc
    p->dada = e; p->seguent = NULL;
    if (esBuida())
        _primer=_darrer=p;
    else {//nomes hi ha un element
        _darrer->seguent = p;
        _darrer = p;
    }
    
}

template<class element>
element CuaDinamica<element>::Primer() const {
    return _primer->dada;
}

template<class element>
void CuaDinamica<element>::allibera() {
    
    if (_primer != NULL) {
        Node *p = _primer->seguent;
        while (p != NULL) {
            
            Node *q = p;
            p = p->seguent;
            delete q;
        }
        delete _primer;
        _primer=_darrer=NULL;
    }
}

template<class element>
void CuaDinamica<element>::copia(const CuaDinamica& o) {
    allibera(); //Alliberem memoria primer.
    
    Node *p = o._primer; 
    while (p != NULL) {
        Encua(p->dada);
        p = p->seguent;
    }
    
}

template<class element>
bool CuaDinamica<element>::esBuida() const {
    return _primer == NULL;
}

template<class element>
CuaDinamica<element>& CuaDinamica<element>::operator=(const CuaDinamica& o) {
    if (this != &o) {
        allibera();
        copia(o);
    }
    return *this;
}

template class CuaDinamica<Carta>;