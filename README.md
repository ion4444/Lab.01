1. Denumirea proiectului: PacMan 
2. Ce reprezintă proiectul:
3. Pac-Man este un joc arcade clasic lansat în 1980. Jocul se desfășoară într-un labirint plin de puncte (mâncare) și diverse obstacole. Jucătorul controlează un personaj rotund, galben (Pac-Man), al cărui scop este să mănânce toate punctele din labirint în timp ce evită să fie prins de fantomele care îl urmăresc. Dacă Pac-Man mănâncă un punct special (power pellet), el poate pentru o perioadă scurtă să "mănânce" fantomele, obținând puncte bonus. Jocul se termină dacă Pac-Man este prins de fantome de prea multe ori. Pac-Man este cunoscut pentru simplitatea și elementul său strategic, fiind unul dintre cele mai populare și recunoscute jocuri video din lume.
Funcția fișierelor Map.hpp, Player.hpp, și Game.hpp:

*. Map.hpp Fișierul Map.hpp definește o clasă responsabilă pentru gestionarea hărții jocului. Constructor Map(): Inițializează harta jocului, adăugând granițele labirintului și mâncarea în spațiile libere. Aceasta creează un spațiu de joc cu o matrice bidimensională (map[height][width]). void drawMap(int playerX, int playerY, int score) const: Desenează harta pe consolă, afișând poziția curentă a jucătorului și punctele de pe hartă. Această funcție utilizează coordonatele jucătorului (playerX, playerY) și afișează scorul curent. bool isWall(int x, int y) const: Verifică dacă o anumită poziție pe hartă este un perete (#). Este folosită pentru a preveni deplasarea jucătorului prin pereți. void setMapElement(int x, int y, char element): Setează un element specific (precum un spațiu gol sau mâncare) la o anumită poziție în matricea hărții. Este folosită, de exemplu, pentru a elimina mâncarea atunci când Pac-Man o consumă.

**.Player.hpp Fișierul Player.hpp definește clasa care gestionează proprietățile și mișcarea jucătorului. Constructor Player(int startX, int startY): Inițializează poziția jucătorului (x, y) și scorul acestuia la începutul jocului. void move(char direction, const Map &map): Controlează mișcarea jucătorului în funcție de direcția specificată (w, a, s, d). Înainte de a actualiza poziția, verifică dacă noua poziție este un perete folosind metoda isWall() a hărții pentru a preveni trecerea prin pereți. void checkFoodCollision(Map &map): Verifică dacă jucătorul a ajuns pe un punct de mâncare pe hartă. Dacă există mâncare la poziția jucătorului, crește scorul și modifică harta pentru a elimina mâncarea.

***.Game.hpp Fișierul Game.hpp definește clasa care coordonează întregul joc, fiind responsabilă pentru logica principală a jocului, interacțiunea dintre harta jocului și jucător. Constructor Game(): Inițializează jocul, harta, și poziția jucătorului, și setează variabila gameOver la false. Aceasta setează starea inițială a jocului. void run(): Este bucla principală a jocului. Aceasta funcție continuă să ruleze până când variabila gameOver devine true. În cadrul buclei: Desenează harta folosind metoda drawMap() din clasa Map. Gestionează intrarea de la utilizator prin metoda handleInput(). Verifică coliziunile jucătorului cu mâncarea și actualizează starea jocului. void handleInput(): Gestionează input-ul utilizatorului folosind _kbhit() și _getch() pentru a detecta apăsările tastelor. Dacă jucătorul apasă x, jocul se oprește (gameOver = true), în caz contrar, actualizează poziția jucătorului folosind metoda move() din clasa Player. bool isGameOver() const: Returnează valoarea variabilei gameOver, indicând dacă jocul s-a terminat sau nu.
.gitignore :
*.o: Ignoră toate fișierele obiect generate din fișierele .cpp (extensia .o).
game: Ignoră executabilul generat (în acest caz, game).
*~: Ignoră fișierele de backup temporare pe care unele editoare de text le generează.
 Game.cpp
Include implementarea metodelor din clasa Game definită în fișierul .hpp.
Constructorul Game inițializează variabilele gameMap, player, și setează gameOver la false.
Metoda run() este bucla principală a jocului care continuă până când jocul se termină.
Metoda handleInput() gestionează intrările jucătorului.
Metoda isGameOver() verifică dacă jocul s-a terminat.
  Map.cpp 
Constructorul Map(): Inițializează harta jocului cu spații goale ' ' în mijloc și pereți ('#') pe margini.
drawMap(): Desenează harta la consolă, afișând poziția jucătorului cu P și scorul curent.
isWall(): Verifică dacă poziția specificată este un perete, returnând true dacă elementul este un perete ('#') sau dacă poziția este în afara limitelor hărții.
setMapElement(): Setează un element specific (cum ar fi un obiect sau un obstacol) în poziția specificată de coordonatele (x, y).
  Player.cpp
Constructorul Player::Player(): Inițializează poziția jucătorului (x, y) și scorul la 0.
move(): În funcție de direcția primită (caracterele 'w', 'a', 's', 'd' pentru deplasarea sus, stânga, jos, dreapta), se calculează noua poziție a jucătorului. Dacă noua poziție nu este un perete, jucătorul se deplasează acolo.
checkFoodCollision(): Verifică dacă jucătorul a colizionat cu mâncare, reprezentată pe hartă prin simbolul 'F'. Dacă da, scorul este crescut cu 10, iar mâncarea este eliminată de pe hartă (schimbând elementul de la coordonatele respective în spațiu gol ' ').
