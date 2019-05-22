
#include "Joc.h"

Joc::Joc() {
    //NO UTILITZAT
}

Joc::Joc(unsigned llavor, int nJugadors) {
    _llavor = llavor;
    _nJugadors = nJugadors;
    //_nCartes = 48;
    reserva();
}

Joc::~Joc() {
    allibera();
}

void Joc::inicialitzarBaralla(int nBaralles) {
    int pos = 0;
    _nCartes = nBaralles * 48;
    _nBaralles = nBaralles;
    Carta cartes[_nCartes];
    for (int i = 0; i < _nBaralles; i++) {
        for (int j = 0; j < 4; j++) { //per cada pal
            for (int k = 1; k <= 12; k++) { //per cada valor
                int valor = k;
                Carta carta(j, valor);
                cartes[pos] = carta;
                pos++;
            }
        }
    }
    //Algoritme de fisher-yates
    for (unsigned i = _nCartes - 1; i > 0; i--) {
        unsigned pos = random(i + 1);
        intercanvi(cartes[pos], cartes[i]);
    }
    int j = _nJugadors - 1; //posicio del jugador
    for (int i = 0; i < _nCartes; i++) { //per cada carta
        if (j < 0) j = _nJugadors - 1; //comencem per l'ultim jugador
        _jugadors[j].afegirCarta(cartes[i]);
        j--;
    }
}


unsigned Joc::random(unsigned i) {
    _llavor = a * _llavor + c;
    unsigned randN = ((_llavor / 32) % m) % i;
    return randN;
}

void Joc::intercanvi(Carta& a, Carta& b) {
    Carta aux = b;
    b = a;
    a = aux;
}

void Joc::inicialitzarJugadors() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 1; i <= _nJugadors; i++) {
        std::cout << "ENTRA EL NOM DEL JUGADOR/A " << i << ":\n";
        std::string nom;
        std::getline(std::cin, nom);
        Jugador j(nom);
        _jugadors[i - 1] = j;
    }
}

void Joc::reserva() {
    _jugadors = new Jugador[_nJugadors]; //mes bad alloc
}

void Joc::allibera() {
    delete [] _jugadors;
}

void Joc::ronda() {
    //Mirem si tos els jugadors tenen cartes..
    int jugadorsFi = _nJugadors;
    int torn = 0;
    int tornAnterior = _nJugadors + 1;
    while (jugadorsFi != 0) {
        if (torn < jugadorsFi) {
            
            if (_jugadors[torn].quedenCartes()) {
                if (tornAnterior != torn) {
                    std::cout<<"- TORN DEL JUGADOR/A "<<_jugadors[torn].toString()<<" -\nMA:\n";
                    _jugadors[torn].mostrarMa();
                }
                tornAnterior = torn;
                std::cout<<"QUINES CARTES VOLS TIRAR?\n";
                int n,c;
                std::cin>>n>>c;
                if (n > 0) {
                    if (_jugadors[torn].teCartesRepetides(n,c)) {
                        std::cout<<"TIRADA: ";
                        _jugadors[torn].eliminarConjuntCartes(n,c,_descartades);
                        std::cout<<"\n";
                        if (c == 2) {
                            std::cout<<"- TORN DEL JUGADOR/A "<<_jugadors[torn].toString()<<"\n";
                            std::cout<<"EL JUGADOR/A "<<_jugadors[torn].toString()<<" INICIA TORN.\n";
                            _jugadors[torn].mostrarMa();
                            torn--;
                        }
                    } else {
                        std::cout<<"ERROR. EL JUGADOR NO TE AQUESTES CARTES\n";
                        torn--;
                    }
                } else if (n == 0) {
                    std::cout<<"EL JUGADOR/A "<<_jugadors[torn].toString()<<" PASSA.\n";
                } else {
                    std::cout<<"DARRERES CARTES TIRADES:\n";
                    _descartades.mostrarCartes();
                    std::cout<<"\n";
                    torn--;
                }
            } else {
                jugadorsFi--;
            }
            torn++;
        } else {
            torn = 0;//tornem a començar
        }
    }
}
