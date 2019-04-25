

#include "Joc.h"

Joc::Joc() {
    //NO UTILITZAT
}

Joc::Joc(unsigned llavor, int nBaralles) {
    _llavor = llavor;
    _nBaralles = nBaralles;
    _nCartes = _nBaralles * 48;
    _cartes = new Carta[_nCartes]; //Bad alloc
}

Joc::~Joc() {
    //metode privat allibera? de moment ho deixem aixi
    delete [] _cartes;
}

void Joc::inicialitzarBaralla() {

    int pos = 0;
    for (int i = 0; i < _nBaralles; i++) { //per cada baralla
        for (int j = 0; j < 4; j++) { //per cada pal
            for (int k = 1; k <= 12; k++) { //per cada valor
                char pal;
                int valor = k;

                switch (j) {
                    case 0:
                        pal = 'O';
                        break;
                    case 1:
                        pal = 'C';
                        break;
                    case 2:
                        pal = 'E';
                        break;
                    case 3:
                        pal = 'B';
                        break;
                }
                Carta carta(pal, valor, 0);
                _cartes[pos] = carta;
                pos++;
            }
        }
    }
}

void Joc::barrejarBaralla() {
    //Algoritme de fisher-yates
    
    for (unsigned i = _nCartes - 1; i > 0; i--) {
        unsigned pos = random(i + 1);
        intercanvi(_cartes[pos],_cartes[i]);
    }
}

unsigned Joc::random(unsigned i) {
    _llavor = a * _llavor + c;
    unsigned randN = (( _llavor / 32) % m) % i;
    return randN;
}

void Joc::intercanvi(Carta& a, Carta& b) {
    Carta aux = b;
    b = a;
    a = aux;
}
