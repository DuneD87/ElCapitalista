
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
    _classificacio = new int[_nJugadors];
}

void Joc::allibera() {
    delete [] _jugadors;
    delete [] _classificacio;
}

void Joc::intercanvi(Carta& a, Carta& b) {
    Carta aux = a;
    a = b;
    b = aux;
}

bool Joc::esMesGran(int x, int y) const {
    bool esMajor = false;
    if (y == 0) {
        esMajor = true;
    } else {
        if (x <= 2 && y > 2) esMajor = true;
        else if (x > 2 && y <= 2) esMajor = false;
        else esMajor = x > y;
    }
    return esMajor;
}

void Joc::iniciTorn(int torn, int& nAnterior, int& cAnterior, int &hanPasat) {
    if (_jugadors[torn].quedenCartes()) {
        std::cout << "- TORN DEL JUGADOR/A " << _jugadors[torn].toString() << "\n";
        std::cout << "EL JUGADOR/A " << _jugadors[torn].toString() << " INICIA TORN.\n";
        std::cout << "MA:\n";
        _jugadors[torn].mostrarMa();
        nAnterior = 0;
        cAnterior = 0;
        hanPasat = 0;
    }
}

void Joc::ronda() {
    //Mirem si tos els jugadors tenen cartes..
    int jugadorsFi = 0;
    int torn = 0;
    int tornAnterior = _nJugadors + 1;
    int hanPasat = 0;
    int nAnterior = 0, cartaAnterior = 0;
    bool totsPasats = false;
    while (jugadorsFi < _nJugadors - 1) {
        if (torn < _nJugadors) {
            if (hanPasat >= _nJugadors - 1 - jugadorsFi) {
                iniciTorn(torn,nAnterior,cartaAnterior,hanPasat);
                totsPasats = true;
            }
            if (_jugadors[torn].quedenCartes()) {
                if (tornAnterior != torn && !totsPasats) {
                    std::cout << "- TORN DEL JUGADOR/A " << _jugadors[torn].toString() << " -\nMA:\n";
                    _jugadors[torn].mostrarMa();
                }
                tornAnterior = torn;
                std::cout << "QUINES CARTES VOLS TIRAR?\n";
                int n = 0, c = 0;
                std::cin >> n>>c;
                if (_jugadors[torn].teCartesRepetides(n, c)) {
                    if (n > 0 && n >= nAnterior && esMesGran(c, cartaAnterior)) {
                        hanPasat = 0;
                        totsPasats = false;
                        std::cout << "TIRADA: ";
                        _jugadors[torn].eliminarConjuntCartes(n, c, _descartades);
                        std::cout << "\n";
                        nAnterior = n;
                        cartaAnterior = c;
                        if (c == 2) {
                            iniciTorn(torn,nAnterior,cartaAnterior,hanPasat);
                            torn--;
                        } else if (!_jugadors[torn].quedenCartes()) {
                            std::cout << "EL JUGADOR/A " << _jugadors[torn].toString() << " HA FINALITZAT EN LA POSICIO " << jugadorsFi + 1 << ".\n";
                            _classificacio[jugadorsFi] = torn;
                            jugadorsFi++;
                            
                        }   
                        
                    } else if (n == 0) {
                        hanPasat++;
                        std::cout << "EL JUGADOR/A " << _jugadors[torn].toString() << " PASSA.\n";
                    } else if (n < 0) {
                        std::cout << "DARRERES CARTES TIRADES:\n";
                        _descartades.mostrarCartes();
                        std::cout << "\n";
                        torn--;
                    } else {
                        std::cout << "ERROR. AMB AQUESTA TIRADA NO SUPERES LES CARTES ACTUALS\n";
                        torn--;
                    }

                } else {
                    std::cout << "ERROR. EL JUGADOR NO TE AQUESTES CARTES\n";
                    torn--;
                }
            }

            torn++;

        } else {
            torn = 0; //tornem a començar
        }

    }
    for (int i = 0; i < _nJugadors; i++)
        if (_jugadors[i].quedenCartes())
            _classificacio[jugadorsFi] = i;
}

void Joc::mostrarClassificacio() const {
    std::cout << "CLASSIFICACIO FINAL:\n";
    for (int i = 0; i < _nJugadors; i++) {
        if (i == 0) {
            std::cout << "REI: " << _jugadors[_classificacio[i]].toString() << '\n';
        } else if (i < _nJugadors / 2) {
            std::cout << "NOBLE: " << _jugadors[_classificacio[i]].toString() << '\n';
        } else if (i >= _nJugadors / 2 && i < _nJugadors - 1) {
            std::cout << "VASSALL: " << _jugadors[_classificacio[i]].toString() << '\n';
        } else if (i == _nJugadors - 1) {
            std::cout << "ESCLAU: " << _jugadors[_classificacio[i]].toString() << '\n';
        }
    }
}

