
#include "PilaCartes.h"

PilaCartes::PilaCartes() {
    _cim = NULL;
}

PilaCartes::PilaCartes(const PilaCartes& orig) {
    copia(orig);
}

PilaCartes::~PilaCartes() {
    allibera();
}

void PilaCartes::allibera() {
    while (_cim != NULL)
        desempila();
}

Carta PilaCartes::cim() const {
    return _cim->valor;
}

void PilaCartes::copia(const PilaCartes& orig) {
    while (orig._cim != NULL)
        empila(orig._cim->valor);
}

void PilaCartes::desempila() {
    Node *aux = _cim;
    _cim = _cim->seg;
    delete aux;
}

void PilaCartes::empila(const Carta& c) {
    Node *p = new Node;
    p->valor = c; p->seg = _cim;
    _cim = p;
}

PilaCartes& PilaCartes::operator=(const PilaCartes& orig) {
    if (this != &orig) {
        allibera();
        copia(orig);
    }
    return *this;
}

bool PilaCartes::buida() {
    return _cim == NULL;
}

void PilaCartes::mostrarCartes() const {
    Node *aux = _cim;
    int n = 0;
    while (aux != NULL && n < 10) {
        std::cout<<aux->valor.toString();
        n++;
        aux = aux->seg;
    }
}

