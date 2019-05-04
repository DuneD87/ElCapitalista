
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
                Carta carta(pal, valor);
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

}
