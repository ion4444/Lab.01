1. Denumirea proiectului: PacMan 
2. Ce reprezintă proiectul:
3. Pac-Man este un joc arcade clasic lansat în 1980. Jocul se desfășoară într-un labirint plin de puncte (mâncare) și diverse obstacole. Jucătorul controlează un personaj rotund, galben (Pac-Man), al cărui scop este să mănânce toate punctele din labirint în timp ce evită să fie prins de fantomele care îl urmăresc. Dacă Pac-Man mănâncă un punct special (power pellet), el poate pentru o perioadă scurtă să "mănânce" fantomele, obținând puncte bonus. Jocul se termină dacă Pac-Man este prins de fantome de prea multe ori. Pac-Man este cunoscut pentru simplitatea și elementul său strategic, fiind unul dintre cele mai populare și recunoscute jocuri video din lume.
Funcția fișierelor Map.hpp, Player.hpp, și Game.hpp:

*. Map.hpp Fișierul Map.hpp definește o clasă responsabilă pentru gestionarea hărții jocului. Constructor Map(): Inițializează harta jocului, adăugând granițele labirintului și mâncarea în spațiile libere. Aceasta creează un spațiu de joc cu o matrice bidimensională (map[height][width]). void drawMap(int playerX, int playerY, int score) const: Desenează harta pe consolă, afișând poziția curentă a jucătorului și punctele de pe hartă. Această funcție utilizează coordonatele jucătorului (playerX, playerY) și afișează scorul curent. bool isWall(int x, int y) const: Verifică dacă o anumită poziție pe hartă este un perete (#). Este folosită pentru a preveni deplasarea jucătorului prin pereți. void setMapElement(int x, int y, char element): Setează un element specific (precum un spațiu gol sau mâncare) la o anumită poziție în matricea hărții. Este folosită, de exemplu, pentru a elimina mâncarea atunci când Pac-Man o consumă.

**.Player.hpp Fișierul Player.hpp definește clasa care gestionează proprietățile și mișcarea jucătorului. Constructor Player(int startX, int startY): Inițializează poziția jucătorului (x, y) și scorul acestuia la începutul jocului. void move(char direction, const Map &map): Controlează mișcarea jucătorului în funcție de direcția specificată (w, a, s, d). Înainte de a actualiza poziția, verifică dacă noua poziție este un perete folosind metoda isWall() a hărții pentru a preveni trecerea prin pereți. void checkFoodCollision(Map &map): Verifică dacă jucătorul a ajuns pe un punct de mâncare pe hartă. Dacă există mâncare la poziția jucătorului, crește scorul și modifică harta pentru a elimina mâncarea.

***.Game.hpp Fișierul Game.hpp definește clasa care coordonează întregul joc, fiind responsabilă pentru logica principală a jocului, interacțiunea dintre harta jocului și jucător. Constructor Game(): Inițializează jocul, harta, și poziția jucătorului, și setează variabila gameOver la false. Aceasta setează starea inițială a jocului. void run(): Este bucla principală a jocului. Aceasta funcție continuă să ruleze până când variabila gameOver devine true. În cadrul buclei: Desenează harta folosind metoda drawMap() din clasa Map. Gestionează intrarea de la utilizator prin metoda handleInput(). Verifică coliziunile jucătorului cu mâncarea și actualizează starea jocului. void handleInput(): Gestionează input-ul utilizatorului folosind _kbhit() și _getch() pentru a detecta apăsările tastelor. Dacă jucătorul apasă x, jocul se oprește (gameOver = true), în caz contrar, actualizează poziția jucătorului folosind metoda move() din clasa Player. bool isGameOver() const: Returnează valoarea variabilei gameOver, indicând dacă jocul s-a terminat sau nu.

Game.cpp

Utilizarea std::unique_ptr pentru Player:

În lista de jucători (players) acum sunt stocate obiecte de tip Player folosind std::unique_ptr, ceea ce permite gestionarea automată a memoriei pentru obiectele Player. Acest lucru ajută la evitarea scurgerilor de memorie, deoarece fiecare jucător va fi distrus automat la sfârșitul duratei de viață a vectorului.
Utilizarea std::shared_ptr pentru Map:

gameMap este acum un std::shared_ptr, ceea ce permite partajarea hărții între mai multe instanțe ale clasei Game sau alte obiecte care pot necesita acces la aceeași hartă. Acest lucru este util pentru gestionarea resurselor comune într-un mod mai flexibil.
Algoritmul std::for_each:

În funcția run, s-a adăugat un exemplu de utilizare a algoritmului std::for_each pentru a parcurge jucătorii și a apela funcția move() pentru fiecare jucător. Aceasta este o abordare mai funcțională și modernă comparativ cu folosirea unui for tradițional și este un exemplu al utilizării STL.
Lipsa detaliilor funcției move() și getName():

Codul presupune că clasa Player are metodele move() și getName(). Totuși, aceste detalii nu sunt prezente aici, sugerând că sunt definite în fișierul "Player.h".
Constructorul fără parametri pentru Game:

Constructorul inițializează players și gameMap direct în lista de inițializare a constructorului. Acest lucru aduce claritate și eficiență în inițializarea obiectelor.
Aceste schimbări demonstrează o abordare mai modernă și eficientă a gestionării memoriei în C++, utilizând tipuri de date inteligente (std::unique_ptr și std::shared_ptr), alături de utilizarea STL pentru a manipula colecții într-un mod mai funcțional.

MakeFile

Setarea standardului C++ la C++17:

În linia CXXFLAGS = -Wall -g -std=c++17, s-a specificat opțiunea -std=c++17 pentru compilator. Aceasta face ca proiectul să fie compilat cu suport pentru standardul C++17, care aduce funcționalități și optimizări suplimentare față de versiunile anterioare ale limbajului.
Definirea obiectivelor pentru executabil și fișierele sursă:

TARGET este definit ca game, ceea ce înseamnă că executabilul rezultat va avea acest nume.
SRCS este o listă de fișiere sursă .cpp folosite pentru a construi programul. În acest caz, fișierele sunt Game.cpp, Player.cpp, și Map.cpp.
Generarea automată a fișierelor obiect:

OBJS este creat prin înlocuirea extensiei .cpp din SRCS cu .o, producând automat lista fișierelor obiect necesare pentru compilare (Game.o, Player.o, Map.o). Această abordare permite adăugarea de noi fișiere sursă în SRCS fără a modifica alte secțiuni din Makefile.
Regula pentru construirea executabilului:

Linia $(TARGET): $(OBJS) definește o regulă pentru a construi executabilul game din fișierele obiect OBJS.
Comanda $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) folosește compilatorul cu flagurile setate pentru a construi executabilul final.
Regula de compilare pentru fișiere .cpp în fișiere .o:

Regula %.o: %.cpp indică faptul că fiecare fișier .cpp va fi compilat într-un fișier .o corespunzător folosind aceleași flaguri de compilare.
Regula clean:

Comanda clean șterge toate fișierele obiect și executabilul, oferind o modalitate rapidă de a curăța directorul de lucru înainte de o compilare nouă (rm -f $(OBJS) $(TARGET)).
Regula opțională run pentru rularea jocului:

Comanda run compilează și rulează direct executabilul (./$(TARGET)), oferind o metodă rapidă de a testa programul după compilare.
Aceste modificări fac Makefile mai modular și mai ușor de extins sau întreținut pe măsură ce proiectul crește în complexitate.

Map.cpp

Inițializarea unui vector tiles:

În constructorul Map::Map(), a fost inițializat un vector tiles cu valori implicite, folosind un initializer list: {"Grass", "Water", "Mountain"}. Aceasta simulează un set simplu de tipuri de teren pentru hartă, folosind containerul STL std::vector pentru a reprezenta diferitele tipuri de dale.
Metoda displayMap() pentru afișarea hărții:

A fost adăugată metoda displayMap(), care afișează toate dalele din vectorul tiles. Aceasta folosește un for cu const auto& tile, pentru a parcurge fiecare element al vectorului și a-l afișa în consolă.
Aceste schimbări fac ca harta să fie reprezentată într-un mod mai modular, permițând extinderea ușoară a tipurilor de dale. Metoda displayMap() asigură o metodă standardizată de afișare a informațiilor despre hartă, ceea ce poate fi util pentru testare sau pentru interacțiunea cu utilizatorul.

Map.hpp

Schimbările aduse codului în fișierul de antet `Map.h` includ:

1. **Includerea directivei `#pragma once`**:
   - Directiva `#pragma once` a fost adăugată în partea de sus a fișierului pentru a preveni includerea multiplă a acestuia. Aceasta înlocuiește clasicele garduri de protecție `#ifndef`, `#define` și `#endif`, simplificând codul și îmbunătățind performanța compilării.

2. **Definirea clasei `Map` cu două funcții publice**:
   - Constructorul `Map()` a fost declarat, permițând inițializarea obiectelor de tip `Map`.
   - A fost declarată metoda `displayMap() const`, care este responsabilă pentru afișarea conținutului hărții (elementele vectorului `tiles`).

3. **Adăugarea unui membru privat `tiles`**:
   - A fost adăugat membrul privat `tiles` de tip `std::vector<std::string>`, care va conține tipurile de dale (ex.: "Grass", "Water", "Mountain") și va fi folosit pentru a reprezenta structura hărții.

Aceste schimbări structurează clasa `Map` și pregătesc antetul pentru implementarea în fișierul `.cpp`.

Player.cpp

Inițializarea membrului name în constructor:

Constructorul Player::Player(const std::string& name) inițializează membrul name folosind lista de inițializare : name(name). Aceasta permite setarea numelui jucătorului la crearea obiectului Player.
Implementarea metodei move():

Metoda move() afișează un mesaj în consolă, indicând că jucătorul cu numele stocat în name se deplasează. Mesajul este formatat astfel: "name is moving.".
Implementarea metodei getName():

Metoda getName() returnează membrul name, care este numele jucătorului. Aceasta permite accesarea numelui jucătorului de către alte părți ale programului, fără a expune direct variabila membru.
Aceste modificări definesc comportamentul clasei Player, incluzând setarea și accesarea numelui, precum și o acțiune de bază a jucătorului (deplasarea).

Player.hpp

Modificarea constructorului:

Constructorul Player a fost modificat pentru a include cuvântul cheie explicit în fața parametrului. Acest lucru previne conversiile implicite atunci când un obiect Player este creat dintr-un tip care poate fi implicit convertit la un std::string.
Astfel, constructorul este acum mai sigur și necesită apeluri explicite la crearea unui obiect de tip Player.
Modificarea constructorului pentru a accepta doar un std::string:

abstract_painter.hpp

Includerea unui fișier suplimentar:

Fișierul map.hpp este acum inclus cu ajutorul directivei #include "map.hpp". Acest lucru sugerează că fișierul map.hpp conține definițiile necesare pentru a lucra cu clasa Map (probabil definită în acel fișier).
Definirea unei clase abstracte:

A fost introdusă o structură numită AbstractPainter, care este o clasă abstractă ce conține două funcții virtuale pure:
DrawImage, care are rolul de a desena o imagine pe o zonă definită de două puncte (topLeft și bottomRight).
WriteText, care este folosită pentru a scrie un text la o poziție specificată.
Adăugarea unui destructor virtual:

Destructorul virtual ~AbstractPainter() este adăugat pentru a asigura distrugerea corectă a obiectelor derivate din această clasă abstractă. Acesta este esențial într-o clasă abstractă, mai ales atunci când clasele derivate alocă resurse (memorie, fișiere deschise etc.).
Modificarea tipului pentru image în DrawImage:

Tipul pentru parametrul image a fost schimbat la const std::vector<std::vector<char>>&, ceea ce înseamnă că acum funcția DrawImage primește un vector bidimensional de caractere (probabil pentru a reprezenta imaginea).

painter.hpp

Implementarea clasei Painter care extinde AbstractPainter:

Clasa Painter a fost definită ca derivată din AbstractPainter. Astfel, Painter devine o clasă concretă care implementează funcțiile virtuale pure din AbstractPainter.
Implementarea metodei DrawImage:

Funcția DrawImage a fost implementată pentru a desena o imagine între două puncte (date prin coordonatele topLeft și bottomRight). Aceasta acceptă un parametru image de tip std::vector<std::vector<char>>, care reprezintă imaginea (probabil o matrice de caractere, fiecare caracter fiind un pixel).
În cadrul acestei metode, sunt afișate coordonatele de început și final, urmate de afișarea fiecărui caracter din matricea de pixeli pe consolă.
Implementarea metodei WriteText:

Funcția WriteText a fost implementată pentru a scrie un text la o anumită poziție pe bază de coordonate (position.x, position.y). Textul este afișat pe consolă, indicând locația și mesajul.
Includerea fișierului abstract_painter.hpp:

Fișierul abstract_painter.hpp este inclus pentru a putea accesa definițiile din AbstractPainter, deoarece Painter este o clasă derivată din aceasta.
Acestea sunt schimbările principale observate în acest cod, fiind o implementare completă a funcționalităților din clasa abstractă AbstractPainter în clasa Painter


# Game Framework

## Descrierea Proiectului
Acest proiect este o platformă de bază pentru un joc, implementat utilizând C++ și biblioteci externe. Include funcționalități pentru gestionarea unei hărți de joc, manipularea jucătorilor și desenarea graficii.

## Regulile Jocului
1. Fiecare jucător se poate mișca pe hartă, interacționând cu tile-urile disponibile.
2. Tile-urile hărții sunt reprezentate de tipuri predefinite precum iarbă, apă sau munți.
3. Obiectele grafice sunt desenate și afișate utilizând biblioteca SFML.

## Dependențe
- **Compilator:** g++ (compatibil cu C++17)
- **Biblioteci externe:** 
  - [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library) pentru grafică.

## Construirea Aplicației
1. Asigurați-vă că aveți instalate dependințele necesare (SFML).
2. Compilați aplicația utilizând comanda:
   ```bash
   make
