

#include <limits>

#include "Joc.h"

Joc::Joc() {
    //NO UTILITZAT
}

Joc::Joc(unsigned llavor, int nJugadors) {
    _llavor = llavor;
    _nJugadors = nJugadors;
    _nCartes = 48;
    reserva();
}

Joc::~Joc() {
    allibera();
}

void Joc::inicialitzarBaralla() {

    int pos = 0;

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
            _cartes[pos] = carta;
            pos++;
        }
    }

}

void Joc::barrejarBaralla() {
    //Algoritme de fisher-yates

    for (unsigned i = _nCartes - 1; i > 0; i--) {
        unsigned pos = random(i + 1);
        intercanvi(_cartes[pos], _cartes[i]);
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
    for (int i = 1; i <= 4; i++) {
        std::cout<<"ENTRA EL NOM DEL JUGADOR/A " <<i<<":\n";
        std::string nom;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin,nom);
        Jugador j(nom);
        _jugadors[i - 1] = j;
    }
}

void Joc::reserva() {
    _cartes = new Carta[_nCartes]; //Bad alloc
    _jugadors = new Jugador[_nJugadors]; //mes bad alloc
}

void Joc::allibera() {
    delete [] _cartes;
    delete [] _jugadors;
}
