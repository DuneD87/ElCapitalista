/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LlistaOrdenada.cpp
 * Author: drive
 * 
 * Created on 2 / d’abril / 2019, 17:06
 */

#include "LlistaOrdenada.h"

template<class element>
LlistaOrdenada<element>::LlistaOrdenada() {
    _inici = NULL;
    _nElems = 0;
}

template<class element>
LlistaOrdenada<element>::LlistaOrdenada(const LlistaOrdenada& orig) {
    copia(orig);
}

template<class element>
LlistaOrdenada<element>::~LlistaOrdenada() {
    allibera();
}

template<class element>
bool LlistaOrdenada<element>::esBuida() const {
    return _inici == NULL;
}

template<class element>
element LlistaOrdenada<element>::esborrar(const element& e) {

    Node *p = _inici, *ant = p;
    element c;
    bool trobat = false; //No tenim repetits
    while (p != NULL && !trobat) {
        if (p->dada == e) {
            c = p->dada;
            if (p != _inici) {
                ant->seg = p->seg;
                delete p;
                p = ant->seg;
            } else {
                delete p;
                _inici = ant->seg;
            }
            _nElems--;
            trobat = true;
        
        } else {
            ant = p;
            p = p->seg;
        }
    }
   
    return c;
}

template<class element>
bool LlistaOrdenada<element>::existeix(const element& e) const {
    bool existeix = false;
    Node *p = _inici;
    while (p != NULL && p->dada <= e) {
        existeix = p->dada == e;
        p = p->seg;
    }
    return existeix;
}

template<class element>
void LlistaOrdenada<element>::inserir(const element& e) {
    Node *q = new Node; //bad alloc
    q->dada = e;
    if (_inici == NULL) { //Llista buida 
        _inici = q;
        _inici->seg = NULL;
    } else { //Llista amb almenys un element
        Node *p = _inici, *ant = NULL;
        while (p != NULL && p->dada < e) {
            ant = p; // Anterior es actual
            p = p->seg; // avancem
        }
        if (ant == NULL) { //Nomes hi ha un element i sera mes petit, ja que 'p' no haura avançat
            q->seg = _inici;
            _inici = q;
        } else {
            ant->seg = q;
            q->seg = p;
        }
    }

}

template<class element>
int LlistaOrdenada<element>::nElements() const {
    return _nElems;
}

template<class element>
LlistaOrdenada<element>& LlistaOrdenada<element>::operator=(const LlistaOrdenada& o) {
    if (this != &o) {
        allibera();
        copia(o);
    }
    return *this;
}

template<class element>
std::string LlistaOrdenada<element>::toString() const {
    std::stringstream s;
    if (!esBuida()) {
        s << _inici->dada.toString();
        Node *p = _inici->seg;
        while (p != NULL) {
            s << p->dada.toString();
            p = p->seg;
        }
    }
    return s.str();
}

template<class element>
void LlistaOrdenada<element>::allibera() {
    if (!esBuida()) {
        Node *p = _inici->seg;
        while (p != NULL) {
            Node *aux = p->seg;
            delete p;
            p = aux;
        }
        delete _inici;
        _inici = NULL;
    }
}

template<class element>
void LlistaOrdenada<element>::copia(const LlistaOrdenada& o) {
    Node *p = o._inici;
    while (p != NULL) {
        inserir(p->dada);
        p = p->seg;
    }
}

template class LlistaOrdenada<Carta>;