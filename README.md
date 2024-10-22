1. Denumirea proiectului: PacMan 
2. Ce reprezintă proiectul:
3. Pac-Man este un joc arcade clasic lansat în 1980. Jocul se desfășoară într-un labirint plin de puncte (mâncare) și diverse obstacole. Jucătorul controlează un personaj rotund, galben (Pac-Man), al cărui scop este să mănânce toate punctele din labirint în timp ce evită să fie prins de fantomele care îl urmăresc. Dacă Pac-Man mănâncă un punct special (power pellet), el poate pentru o perioadă scurtă să "mănânce" fantomele, obținând puncte bonus. Jocul se termină dacă Pac-Man este prins de fantome de prea multe ori. Pac-Man este cunoscut pentru simplitatea și elementul său strategic, fiind unul dintre cele mai populare și recunoscute jocuri video din lume.
Funcția fișierelor Map.hpp, Map.cpp Player.hpp,Player.cpp și Game.hpp, Game.cpp, abstract_painter.hpp, painter,hpp, ,gitignore.

Fișierul .gitignore este folosit pentru a specifica fișierele și directoarele pe care dorești să le excluzi din controlul versiunilor în Git. Git va ignora aceste fișiere și nu le va urmări sau include în commits. Structura ta de .gitignore are rolul de a ignora fișierele comune care nu sunt necesare în istoricul unui proiect software.

Iată ce face fiecare regulă din fișierul tău .gitignore:

*.o: Ignoră toate fișierele obiect (fișiere binare generate după compilarea codului sursă C/C++).
*~: Ignoră fișierele de backup generate de editori (unele editoare creează fișiere temporare sau de backup cu sufixul ~).
game: Ignoră fișierul executabil numit game (fișierul binar rezultat după compilare).
*.log, *.out, *.aux, *.tmp: Ignoră fișierele de depanare sau temporare, cum ar fi jurnalele (.log), ieșirile de la rularea programelor (.out), fișiere auxiliare (.aux), și fișiere temporare (.tmp).
temp/, tmp/: Ignoră directoarele temporare numite temp și tmp, dacă acestea există și sunt generate de aplicație.
build/: Ignoră directorul build, care ar putea conține fișiere intermediare sau rezultate din compilare, produse de un sistem de build (ex: Makefile).

Fișierul Game.cpp definește implementarea clasei Game, care este probabil responsabilă pentru gestionarea logicii și stării unui joc. Iată o detaliere a fiecărei secțiuni din acest fișier:

Include-ul fișierului de antet:

cpp

#include "Game.hpp"
Acest include permite folosirea declarațiilor din fișierul Game.hpp, care conține definiția clasei Game.

Constructorul fără parametri:

cpp

Game::Game() : gameMap(), player(), gameOver(false) {}
Acest constructor inițializează membrii clasei Game. Se folosesc inițializatori pentru gameMap și player, iar gameOver este setat la false, indicând că jocul nu este terminat la început.

Constructorul de copiere:

cpp

Game::Game(const Game& other) : gameMap(other.gameMap), player(other.player), gameOver(other.gameOver) {}
Acesta este constructorul care permite crearea unei noi instanțe de Game ca o copie a unui alt obiect Game. Copiază starea jocului (gameMap, player, și gameOver) dintr-un alt obiect Game.

Operatorul de atribuire:

cpp

Game& Game::operator=(const Game& other) {
    if (this != &other) {
        gameMap = other.gameMap;
        player = other.player;
        gameOver = other.gameOver;
    }
    return *this;
}
Acest operator permite atribuirea valorilor de la un alt obiect Game către obiectul curent. Dacă instanța curentă este diferită de other, membrii săi sunt actualizați cu valorile din other.

Operatorul de comparație pentru egalitate:

cpp

bool Game::operator==(const Game& other) const {
    return gameMap == other.gameMap && player == other.player && gameOver == other.gameOver;
}
Acest operator compară două obiecte Game și verifică dacă sunt egale, adică dacă gameMap, player și gameOver au aceleași valori.

Bucla principală a jocului:

cpp

void Game::run() {
    // Implementare buclă principală
}
Această metodă este locul unde s-ar implementa bucla principală a jocului. De obicei, bucla principală controlează desfășurarea jocului, actualizările și desenarea.

Gestionarea input-ului jucătorului:

cpp
void Game::handleInput() {
    // Implementare gestionare input
}
Metoda handleInput ar trebui să gestioneze intrările din partea jucătorului, cum ar fi comenzile de la tastatură sau mouse.

Verificarea stării jocului:

cpp

bool Game::isGameOver() const {
    return gameOver;
}
Această metodă returnează starea jocului (gameOver), indicând dacă jocul s-a terminat sau nu.

Operatorul de intrare:

cpp

std::istream& operator>>(std::istream& in, Game& game) {
    in >> game.gameMap >> game.player;
    return in;
}
Acest operator permite citirea stării jocului (harta jocului și jucătorul) dintr-un flux de intrare (de exemplu, fișier sau tastatură).

Operatorul de ieșire:

cpp

std::ostream& operator<<(std::ostream& out, const Game& game) {
    out << game.gameMap << " " << game.player;
    return out;
}
Acest operator permite afișarea stării jocului (harta și jucătorul) într-un flux de ieșire, cum ar fi un fișier sau consola.

În concluzie:
Clasa Game implementează logica de bază a unui joc, incluzând gestionarea stării jocului, copierea și compararea instanțelor, manipularea intrărilor jucătorului și interacțiunile cu fluxuri de intrare și ieșire. Funcțiile sunt declarate în fișierul de antet (Game.hpp), iar implementarea lor este realizată în fișierul Game.cpp.


Fișierul Game.hpp definește clasa Game, asigurându-se că sunt incluse toate declarațiile necesare pentru implementarea logicii jocului. Este un fișier de antet (header file) care declară membrii și funcțiile clasei Game, fără a include implementările acestora, care sunt plasate în fișierul sursă Game.cpp.

Funcționalitatea fișierului Game.hpp:
Directivele de preprocesor #ifndef, #define, și #endif:

cpp

#ifndef GAME_HPP
#define GAME_HPP
Aceste directive de preprocesor previn includerea multiplă a fișierului în proiect. Dacă fișierul a fost deja inclus, GAME_HPP este definit și fișierul nu mai este inclus din nou. Acest lucru previne erorile de redefinire.

Include-urile:

cpp

#include "Map.hpp"
#include "Player.hpp"
#include <iostream>
Map.hpp și Player.hpp sunt fișiere de antet care declară clasele Map și Player, ce sunt utilizate ca membri în clasa Game.
#include <iostream> este necesar pentru utilizarea fluxurilor de intrare și ieșire (std::istream și std::ostream), care sunt folosite în funcțiile de citire și afișare a obiectelor Game.
Clasa Game:

cpp

class Game {
private:
    Map gameMap;
    Player player;
    bool gameOver;
Membrii privați ai clasei includ:

gameMap: un obiect de tip Map, reprezentând harta jocului.
player: un obiect de tip Player, reprezentând jucătorul.
gameOver: un bool care indică dacă jocul s-a încheiat sau nu.
Membrii publici ai clasei:

Constructori:

cpp

Game();
Game(const Game& other);
Game(): Constructor implicit, care inițializează jocul.
Game(const Game& other): Constructor de copiere, care permite crearea unui nou obiect Game ca o copie a altui obiect Game.
Operatori:

cpp

Game& operator=(const Game& other);
bool operator==(const Game& other) const;
Operatorul de atribuire (operator=): Permite atribuirea valorilor unui alt obiect Game către obiectul curent.
Operatorul de comparație (operator==): Verifică dacă două obiecte Game sunt egale, comparând membrii lor (gameMap, player, gameOver).
Funcții pentru logica jocului:

cpp

void run();
void handleInput();
bool isGameOver() const;
run(): Este bucla principală a jocului, care va conține logica de rulare continuă.
handleInput(): Gestionează input-ul jucătorului (comenzi de la tastatură sau alte dispozitive).
isGameOver(): Verifică dacă jocul s-a terminat, returnând valoarea lui gameOver.
Operatorii de intrare/ieșire:

cpp

friend std::istream& operator>>(std::istream& in, Game& game);
friend std::ostream& operator<<(std::ostream& out, const Game& game);
Acești operatori permit citirea și afișarea obiectului Game:

operator>>: Permite citirea stării jocului dintr-un flux de intrare (std::istream).
operator<<: Permite afișarea stării jocului într-un flux de ieșire (std::ostream).
Directive de închidere a preprocesorului:

cpp

#endif

Fișierul Game.hpp definește structura clasei Game, declarând membrii săi (harta jocului, jucătorul și starea jocului) și metodele esențiale pentru funcționarea jocului. Implementarea completă a acestor metode și operatori se face ulterior în fișierul sursă Game.cpp. Acesta oferă o separare clară între declarații și implementări, așa cum este standard în programarea C++.



Acesta este un fișier **Makefile**, folosit pentru automatizarea procesului de compilare și gestionare a dependențelor în proiecte C++ (sau alte limbaje). Structura acestui fișier indică cum se vor compila fișierele sursă `.cpp` în fișiere obiect `.o` și cum se va genera executabilul final al jocului.


Setarea variabilelor pentru compilator și opțiuni de compilare**:
   ```makefile
   CXX = g++
   CXXFLAGS = -Wall -g
   ```
   - **`CXX`** definește compilatorul care va fi folosit, în acest caz, `g++` (compilatorul pentru C++).
   - **`CXXFLAGS`** setează opțiunile de compilare:
     - `-Wall`: Activează toate mesajele de avertizare, ajutând la detectarea problemelor în cod.
     - `-g`: Include informații de depanare în fișierele binare pentru a facilita debugging-ul.

Definirea executabilului țintă**:
   ```makefile
   TARGET = game
   ```
   - **`TARGET`** este numele fișierului executabil rezultat după compilare. În acest caz, numele jocului va fi `game`.

Lista fișierelor sursă**:
   ```makefile
   SRCS = Game.cpp Player.cpp Map.cpp
   ```
   - **`SRCS`** conține toate fișierele sursă `.cpp` care vor fi compilate.
Generarea automată a fișierelor obiect**:
   ```makefile
   OBJS = $(SRCS:.cpp=.o)
   ```
   - **`OBJS`** este lista fișierelor obiect (`.o`), generate automat din fișierele sursă. Regula folosește o substituție pentru a înlocui extensia `.cpp` cu `.o`.

Regula pentru a construi executabilul**:
   ```makefile
   $(TARGET): $(OBJS)
   	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
   ```
   - Această regulă specifică cum să fie construit executabilul **`TARGET`** (adică `game`), folosind fișierele obiect **`OBJS`**.
   - **`$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)`**: Comanda invocă compilatorul (`g++`) cu opțiunile de compilare și creează fișierul executabil (`game`) din fișierele obiect (`.o`).

Regula pentru compilarea fișierelor `.cpp` în `.o`**:
   ```makefile
   %.o: %.cpp
   	$(CXX) $(CXXFLAGS) -c $< -o $@
   ```
   - Aceasta este o regulă generică care compilează fiecare fișier `.cpp` într-un fișier obiect `.o`.
   - **`$<`** reprezintă fișierul sursă `.cpp` curent.
   - **`$@`** reprezintă fișierul obiect `.o` curent.

Regula `clean` pentru ștergerea fișierelor generate**:
   ```makefile
   clean:
   	rm -f $(OBJS) $(TARGET)
   ```
   - Această regulă este folosită pentru a curăța directorul de fișierele obiect și executabilele generate în urma compilării.
   - **`rm -f $(OBJS) $(TARGET)`**: Șterge fișierele obiect și executabilul (`game`).

Regula `run` pentru a rula jocul**:
   ```makefile
   run: $(TARGET)
   	./$(TARGET)
   ```
   - Aceasta este o regulă opțională care compilează și rulează jocul.
   - După ce executabilul `game` este creat, comanda **`./$(TARGET)`** va lansa jocul.


Acest **Makefile** descrie un proces de compilare simplu și eficient pentru un proiect de joc C++. El definește cum să fie transformate fișierele sursă în fișiere obiect și apoi cum să fie creat executabilul final, având și reguli utile pentru curățare și rulare a jocului.


Acesta este un fișier de implementare pentru clasa **Map**, folosită pentru a reprezenta harta unui joc. Fiecare funcție din acest fișier gestionează aspecte legate de harta jocului, cum ar fi inițializarea, afișarea, manipularea și verificarea diferitelor elemente ale hărții.


Constructorul `Map` (implicit)**:
   ```cpp
   Map::Map() {
       for (int i = 0; i < height; ++i) {
           for (int j = 0; j < width; ++j) {
               if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                   map[i][j] = '#';  // Ziduri de margine
               } else {
                   map[i][j] = ' ';  // Spațiu gol
               }
           }
       }
   }
   ```
   - Constructorul implicit inițializează harta cu spații goale (`' '`) în interior și ziduri (`'#'`) pe margini.

Constructorul de copiere**:
   ```cpp
   Map::Map(const Map& other) {
       for (int i = 0; i < height; ++i) {
           for (int j = 0; j < width; ++j) {
               map[i][j] = other.map[i][j];
           }
       }
   }
   ```
   - Constructorul de copiere copiază fiecare element din harta unui alt obiect de tip **Map**.

Operatorul de atribuire**:
   ```cpp
   Map& Map::operator=(const Map& other) {
       if (this != &other) {
           for (int i = 0; i < height; ++i) {
               for (int j = 0; j < width; ++j) {
                   map[i][j] = other.map[i][j];
               }
           }
       }
       return *this;
   }
   ```
   - Acest operator asigură copierea profundă a hărții atunci când un obiect **Map** este atribuit altuia.

Operatorul de comparație `==`**:
   ```cpp
   bool Map::operator==(const Map& other) const {
       for (int i = 0; i < height; ++i) {
           for (int j = 0; j < width; ++j) {
               if (map[i][j] != other.map[i][j]) {
                   return false;
               }
           }
       }
       return true;
   }
   ```
   - Compară două obiecte **Map** pentru a verifica dacă sunt identice, element cu element.

Funcția `drawMap`**:
   ```cpp
   void Map::drawMap(int playerX, int playerY, int score) const {
       std::cout << "Score: " << score << std::endl;
       for (int i = 0; i < height; ++i) {
           for (int j = 0; j < width; ++j) {
               if (i == playerX && j == playerY) {
                   std::cout << 'P';  // Afișează poziția jucătorului
               } else {
                   std::cout << map[i][j];
               }
           }
           std::cout << std::endl;
       }
   }
   ```
   - Afișează harta în consolă, incluzând poziția jucătorului (reprezentată prin caracterul `'P'`) și scorul.

Funcția `isWall`**:
   ```cpp
   bool Map::isWall(int x, int y) const {
       if (x < 0 || x >= height || y < 0 || y >= width) {
           return true;  // Ieșirea din limite este considerată zid
       }
       return map[x][y] == '#';  // Verifică dacă poziția este un zid
   }
   ```
   - Verifică dacă o poziție specificată pe hartă este un zid (`'#'`). Dacă coordonatele sunt în afara hărții, poziția este tratată ca zid.

Funcția `setMapElement`**:
   ```cpp
   void Map::setMapElement(int x, int y, char element) {
       if (x >= 0 && x < height && y >= 0 && y < width) {
           map[x][y] = element;  // Setează un element în coordonatele date
       }
   }
   ```
   - Permite setarea unui element specific la o anumită poziție pe hartă, verificând limitele hărții.

Operatorul de intrare `>>`**:
   ```cpp
   std::istream& operator>>(std::istream& in, Map& map) {
       for (int i = 0; i < Map::height; ++i) {
           for (int j = 0; j < Map::width; ++j) {
               in >> map.map[i][j];
           }
       }
       return in;
   }
   ```
   - Permite citirea unei hărți dintr-un flux de intrare, cum ar fi un fișier sau consola.

Operatorul de ieșire `<<`**:
   ```cpp
   std::ostream& operator<<(std::ostream& out, const Map& map) {
       for (int i = 0; i < Map::height; ++i) {
           for (int j = 0; j < Map::width; ++j) {
               out << map.map[i][j];
           }
           out << std::endl;
       }
       return out;
   }
   ```
   - Permite afișarea unei hărți într-un flux de ieșire, cum ar fi consola sau un fișier.

### În concluzie:
Această implementare a clasei **Map** definește cum să fie inițializată, copiată, afișată și manipulată o hartă de joc. Elementele esențiale sunt incluse, precum verificarea zidurilor și afișarea poziției jucătorului. Operatorii de intrare și ieșire fac codul mai flexibil pentru lucrul cu fluxuri (input/output), ceea ce este util în dezvoltarea jocurilor.


Acesta este fișierul de antet pentru clasa **Map**. El conține declarațiile membrilor și funcțiilor publice și private ale clasei **Map** care sunt implementate în fișierul de cod sursă. Clasa **Map** definește o hartă pentru joc, sub forma unei matrice de caractere, cu funcționalități de manipulare și afișare.


Atribute private**:
   ```cpp
   static const int width = 20;  // Lățimea hărții
   static const int height = 10; // Înălțimea hărții
   char map[height][width];      // Harta este o matrice de caractere
   ```
   - Harta jocului este o matrice de caractere cu dimensiuni fixe: 20 de coloane și 10 rânduri.
   - `width` și `height` sunt constante care definesc dimensiunile hărții.
   - `map` este o matrice bidimensională de caractere care reprezintă elementele hărții, cum ar fi zidurile și spațiile goale.

Constructori**:
   - **Constructor implicit**: Inițializează harta cu spații goale și ziduri pe margini.
   ```cpp
   Map();
   ```
   - **Constructor de copiere**: Creează o copie a unui obiect **Map** existent.
   ```cpp
   Map(const Map& other);
   ```

Operatorul de atribuire**:
   ```cpp
   Map& operator=(const Map& other);
   ```
   - Permite atribuirea unui obiect **Map** către altul. Asigură copierea profundă a elementelor matricei.

Operatorul de comparație egalitate**:
   ```cpp
   bool operator==(const Map& other) const;
   ```
   - Compară două hărți pentru a verifica dacă sunt identice (element cu element).

Funcțiile publice**:
   - **`drawMap`**: Desenează harta în consola terminalului, afișând și poziția jucătorului și scorul.
   ```cpp
   void drawMap(int playerX, int playerY, int score) const;
   ```

   - **`isWall`**: Verifică dacă o anumită poziție de pe hartă este un zid (`'#'`).
   ```cpp
   bool isWall(int x, int y) const;
   ```

   - **`setMapElement`**: Modifică un element specific de pe hartă la coordonatele date.
   ```cpp
   void setMapElement(int x, int y, char element);
   ```

Operatorii de intrare/ieșire**:
   - **Operatorul `>>` (intrare)**: Permite citirea hărții dintr-un flux de intrare (de exemplu, dintr-un fișier sau consolă).
   ```cpp
   friend std::istream& operator>>(std::istream& in, Map& map);
   ```

   - **Operatorul `<<` (ieșire)**: Permite scrierea hărții într-un flux de ieșire (de exemplu, afișarea în consolă sau scrierea într-un fișier).
   ```cpp
   friend std::ostream& operator<<(std::ostream& out, const Map& map);
   ```

Acest fișier **Map.hpp** definește interfața clasei **Map**. Clasa oferă metode pentru inițializarea, desenarea, verificarea și manipularea elementelor hărții jocului. Totodată, include operatori pentru compararea, citirea și scrierea hărților, facilitând lucrul cu fluxuri de intrare/ieșire și gestionând corect copierea obiectelor **Map**.


Acesta este fișierul de implementare pentru clasa **Player**, care gestionează jucătorul într-un joc. Clasa definește funcționalități legate de poziționarea, mișcarea și scorul jucătorului, precum și interacțiunea cu harta jocului.


Constructorul de inițializare**:
   ```cpp
   Player::Player(int startX, int startY) : x(startX), y(startY), score(0) {}
   ```
   - Inițializează jucătorul la o poziție dată (`startX`, `startY`) și setează scorul inițial la 0.

Constructorul de copiere**:
   ```cpp
   Player::Player(const Player& other) : x(other.x), y(other.y), score(other.score) {}
   ```
   - Creează o copie a unui obiect **Player** existent, copiază poziția și scorul.

Operatorul de atribuire**:
   ```cpp
   Player& Player::operator=(const Player& other) {
       if (this != &other) {
           x = other.x;
           y = other.y;
           score = other.score;
       }
       return *this;
   }
   ```
   - Permite atribuirea unui obiect **Player** altuia. Copiază poziția și scorul.

Operatorul de comparație egalitate**:
   ```cpp
   bool Player::operator==(const Player& other) const {
       return (x == other.x) && (y == other.y) && (score == other.score);
   }
   ```
   - Compară doi jucători pentru a vedea dacă au aceeași poziție și același scor.

Funcția de mutare a jucătorului**:
   ```cpp
   void Player::move(char direction, const Map &map) {
       int newX = x;
       int newY = y;
   
       switch (direction) {
           case 'w': newX--; break;  // Mutați în sus
           case 'a': newY--; break;  // Mutați la stânga
           case 's': newX++; break;  // Mutați în jos
           case 'd': newY++; break;  // Mutați la dreapta
           default:
               std::cout << "Direcție invalidă!" << std::endl;
               return;
       }
   
       if (!map.isWall(newX, newY)) {
           x = newX;
           y = newY;
       } else {
           std::cout << "Ai lovit un zid! Nu poți să te muți acolo." << std::endl;
       }
   }
   ```
   - Permite jucătorului să se mute în funcție de direcția primită (`w`, `a`, `s`, `d`).
   - Verifică dacă noua poziție nu este un zid, folosind funcția `isWall` din clasa **Map**.
   - Dacă poziția este un zid, jucătorul nu se va putea muta acolo.

Funcția de coliziune cu hrana**:
   ```cpp
   void Player::checkFoodCollision(Map &map) {
       if (map.map[x][y] == 'F') {
           score += 10;
           map.setMapElement(x, y, ' ');
           std::cout << "Hrana colectată! Scor: " << score << std::endl;
       }
   }
   ```
   - Verifică dacă jucătorul a ajuns pe o poziție care conține hrana (`'F'`).
   - Dacă da, scorul jucătorului crește cu 10 puncte, iar hrana este eliminată de pe hartă.

Operatorul de intrare**:
   ```cpp
   std::istream& operator>>(std::istream& in, Player& player) {
       in >> player.x >> player.y >> player.score;
       return in;
   }
   ```
   - Permite citirea poziției și scorului jucătorului dintr-un flux de intrare (de exemplu, dintr-un fișier sau consola).

Operatorul de ieșire**:
   ```cpp
   std::ostream& operator<<(std::ostream& out, const Player& player) {
       out << "Player Position: (" << player.getX() << ", " << player.getY() << ") Score: " << player.getScore();
       return out;
   }
   ```
   - Permite afișarea poziției și scorului jucătorului într-un flux de ieșire (cum ar fi consola).

Clasa **Player** gestionează mișcarea jucătorului pe hartă, interacțiunea cu obiectele de pe hartă (cum ar fi hrana), și păstrează scorul. Implementarea permite gestionarea inputului pentru mutări și coliziuni, și oferă operatori pentru citirea și afișarea informațiilor despre 
jucător.


Acesta este fișierul de antet pentru clasa **Player**, care definește jucătorul și funcționalitățile sale în cadrul unui joc. Fișierul **Player.hpp** declară variabilele și metodele publice și private care vor fi implementate ulterior în **Player.cpp**.


Variabile private**:
   ```cpp
   private:
       int x;       // Coordonata x a jucătorului
       int y;       // Coordonata y a jucătorului
       int score;   // Scorul jucătorului
   ```
   - **x** și **y** sunt coordonatele jucătorului pe hartă.
   - **score** păstrează scorul acumulat de jucător pe parcursul jocului.

Constructor pentru inițializarea poziției jucătorului**:
   ```cpp
   Player(int startX, int startY);
   ```
   - Inițializează jucătorul cu pozițiile de început date (startX și startY) și scorul inițial la 0.

Constructor de copiere**:
   ```cpp
   Player(const Player& other);
   ```
   - Copiază un obiect **Player** existent, transferând coordonatele și scorul.

Operator de atribuire**:
   ```cpp
   Player& operator=(const Player& other);
   ```
   - Permite atribuirea unui alt obiect **Player**, copiază poziția și scorul doar dacă nu este același obiect.

Operator de comparație egalitate**:
   ```cpp
   bool operator==(const Player& other) const;
   ```
   - Compară doi jucători și returnează `true` dacă au aceeași poziție și același scor.

Metoda de mutare a jucătorului**:
   ```cpp
   void move(char direction, const Map &map);
   ```
   - Mută jucătorul pe hartă în funcție de direcția de input (`w`, `a`, `s`, `d`).
   - Verifică dacă mutarea este validă, adică dacă jucătorul nu lovește un zid.

Metoda de verificare a coliziunii cu hrana**:
   ```cpp
   void checkFoodCollision(Map &map);
   ```
   - Verifică dacă jucătorul se află pe o celulă de hartă care conține hrană și, dacă da, actualizează scorul și îndepărtează hrana.

Funcții de acces**:
   ```cpp
   int getX() const { return x; }
   int getY() const { return y; }
   int getScore() const { return score; }
   ```
   - Aceste funcții permit accesul la coordonatele și scorul jucătorului. Ele sunt marcate ca `const` pentru a garanta că nu vor modifica obiectul.

Clasa **Player** din acest fișier antet declară funcționalități legate de mișcare, coliziune și gestionarea scorului pentru jucător. Metodele de acces permit obținerea coordonatelor și a scorului, iar operatorii de copiere, atribuire și egalitate asigură o gestionare corectă a instanțelor clasei **Player**.

Acesta este fișierul de antet pentru clasa abstractă **AbstractPainter**. Fișierul **AbstractPainter.hpp** definește o interfață de bază pentru orice clasă derivată care va implementa metodele de desenare a unei imagini și scrierea unui text. Această structură este concepută pentru a fi extinsă de alte clase, permițând polimorfismul în cadrul aplicației.


Include fișierul `map.hpp`**:
   ```cpp
   #include "map.hpp"
   ```
   - Se include fișierul **map.hpp**, probabil pentru a avea acces la definiția clasei **Point** (care poate reprezenta un punct cu coordonate pe hartă sau pe o suprafață de desen).

Clasa abstractă `AbstractPainter`**:
   ```cpp
   struct AbstractPainter {
   ```
   - Este o clasă abstractă, ceea ce înseamnă că nu poate fi instanțiată direct, ci trebuie să fie derivată de alte clase care vor implementa metodele sale.

Metode virtuale pure**:
   ```cpp
   virtual void DrawImage(Point topLeft, Point bottomRight, char** image) = 0;
   virtual void WriteText(Point position, char* text) = 0;
   ```
   - **DrawImage**: Funcție virtuală pură care trebuie implementată în clasa derivată. Ea va permite desenarea unei imagini într-o zonă delimitată de coordonatele **topLeft** (stânga sus) și **bottomRight** (dreapta jos).
   - **WriteText**: Funcție virtuală pură care va permite scrierea unui text la poziția specificată de **position**.
   - Faptul că aceste funcții sunt **virtuale pure** (`= 0`) le face să fie obligatorii de implementat în orice clasă derivată.

Destructor virtual**:
   ```cpp
   virtual ~AbstractPainter() = default;
   ```
   - Destructorul este definit ca virtual și implicit (`= default`), pentru a permite distrugerea corectă a obiectelor derivate, chiar și atunci când sunt manipulate prin intermediul pointerilor la clasa de bază **AbstractPainter**.

Clasa **AbstractPainter** servește ca interfață pentru alte clase care vor implementa metodele de desenare a unei imagini și de scriere a unui text. Definind aceste funcții ca **virtuale pure**, fișierul sugerează că diverse implementări (cum ar fi desenarea într-o fereastră grafică, o hartă, sau pe un ecran ASCII) pot fi realizate de diferite clase derivate. Polimorfismul este cheia în acest design, permițând manipularea diferitelor tipuri de **Painter** fără a cunoaște detaliile de implementare specifice fiecăruia.

Acesta este un fișier de antet pentru clasa **Painter**, care extinde clasa abstractă **AbstractPainter**. Clasa **Painter** implementează metodele virtuale pure definite în **AbstractPainter**, asigurându-se că orice instanță a acestei clase va oferi funcționalități pentru desenarea de imagini și scrierea de text.


Include fișierul `abstract_painter.hpp`**:
   ```cpp
   #include "abstract_painter.hpp"
   ```
   - Se include fișierul de antet care definește clasa abstractă **AbstractPainter**. Acesta este necesar pentru ca **Painter** să moștenească și să implementeze metodele acestei clase abstracte.

Clasa `Painter`**:
   ```cpp
   class Painter : public AbstractPainter {
   ```
   - **Painter** extinde **AbstractPainter**, ceea ce înseamnă că va trebui să implementeze toate metodele virtuale pure definite în clasa de bază. În acest caz, **DrawImage** și **WriteText** sunt metodele care trebuie implementate.

Metodele suprascrise**:
   ```cpp
   virtual void DrawImage(Point topLeft, Point bottomRight, char** image) override;
   virtual void WriteText(Point position, char* text) override;
   ```
   - **DrawImage**: Această metodă va primi două puncte, **topLeft** (coordonatele stânga sus) și **bottomRight** (coordonatele dreapta jos), împreună cu o imagine sub formă de matrice de caractere (**char**). Implementarea acestei funcții va permite desenarea imaginii între acele coordonate.
   - **WriteText**: Această metodă va primi un punct de referință (**position**) și un text (**text**) pe care îl va afișa în poziția respectivă. Implementarea va afișa textul într-un mod specific.

Suprascrierea (`override`)**:
   - Ambele metode sunt marcate cu `override`, ceea ce asigură că acestea sunt implementări corecte ale metodelor virtuale din clasa de bază **AbstractPainter**.

Clasa **Painter** implementează interfața definită de **AbstractPainter**, oferind detalii despre cum să desenezi o imagine și cum să afișezi textul. În implementarea completă a funcțiilor **DrawImage** și **WriteText**, clasa va gestiona logica de desenare grafică, fie pe un ecran, fie într-un alt mediu. 

Acest fișier definește doar interfața clasei, iar implementările funcțiilor ar trebui să fie detaliate în fișierul sursă asociat (de obicei **Painter.cpp**).
