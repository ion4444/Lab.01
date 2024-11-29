1. Denumirea proiectului: PacMan 
2. Ce reprezintă proiectul:
3. Pac-Man este un joc arcade clasic lansat în 1980. Jocul se desfășoară într-un labirint plin de puncte (mâncare) și diverse obstacole. Jucătorul controlează un personaj rotund, galben (Pac-Man), al cărui scop este să mănânce toate punctele din labirint în timp ce evită să fie prins de fantomele care îl urmăresc. Dacă Pac-Man mănâncă un punct special (power pellet), el poate pentru o perioadă scurtă să "mănânce" fantomele, obținând puncte bonus. Jocul se termină dacă Pac-Man este prins de fantome de prea multe ori. Pac-Man este cunoscut pentru simplitatea și elementul său strategic, fiind unul dintre cele mai populare și recunoscute jocuri video din lume.
Funcția fișierelor Map.hpp, Player.hpp, și Game.hpp:

*. Map.hpp Fișierul Map.hpp definește o clasă responsabilă pentru gestionarea hărții jocului. Constructor Map(): Inițializează harta jocului, adăugând granițele labirintului și mâncarea în spațiile libere. Aceasta creează un spațiu de joc cu o matrice bidimensională (map[height][width]). void drawMap(int playerX, int playerY, int score) const: Desenează harta pe consolă, afișând poziția curentă a jucătorului și punctele de pe hartă. Această funcție utilizează coordonatele jucătorului (playerX, playerY) și afișează scorul curent. bool isWall(int x, int y) const: Verifică dacă o anumită poziție pe hartă este un perete (#). Este folosită pentru a preveni deplasarea jucătorului prin pereți. void setMapElement(int x, int y, char element): Setează un element specific (precum un spațiu gol sau mâncare) la o anumită poziție în matricea hărții. Este folosită, de exemplu, pentru a elimina mâncarea atunci când Pac-Man o consumă.

**.Player.hpp Fișierul Player.hpp definește clasa care gestionează proprietățile și mișcarea jucătorului. Constructor Player(int startX, int startY): Inițializează poziția jucătorului (x, y) și scorul acestuia la începutul jocului. void move(char direction, const Map &map): Controlează mișcarea jucătorului în funcție de direcția specificată (w, a, s, d). Înainte de a actualiza poziția, verifică dacă noua poziție este un perete folosind metoda isWall() a hărții pentru a preveni trecerea prin pereți. void checkFoodCollision(Map &map): Verifică dacă jucătorul a ajuns pe un punct de mâncare pe hartă. Dacă există mâncare la poziția jucătorului, crește scorul și modifică harta pentru a elimina mâncarea.

***.Game.hpp Fișierul Game.hpp definește clasa care coordonează întregul joc, fiind responsabilă pentru logica principală a jocului, interacțiunea dintre harta jocului și jucător. Constructor Game(): Inițializează jocul, harta, și poziția jucătorului, și setează variabila gameOver la false. Aceasta setează starea inițială a jocului. void run(): Este bucla principală a jocului. Aceasta funcție continuă să ruleze până când variabila gameOver devine true. În cadrul buclei: Desenează harta folosind metoda drawMap() din clasa Map. Gestionează intrarea de la utilizator prin metoda handleInput(). Verifică coliziunile jucătorului cu mâncarea și actualizează starea jocului. void handleInput(): Gestionează input-ul utilizatorului folosind _kbhit() și _getch() pentru a detecta apăsările tastelor. Dacă jucătorul apasă x, jocul se oprește (gameOver = true), în caz contrar, actualizează poziția jucătorului folosind metoda move() din clasa Player. bool isGameOver() const: Returnează valoarea variabilei gameOver, indicând dacă jocul s-a terminat sau nu.


Fișierele clasei Map
Antet (map.hpp)
Separarea interfeței clasei Map într-un fișier header independent.
Crearea unui constructor și metode care definesc funcționalitatea clasei.
Definirea unor funcții relevante pentru interacțiunea cu harta.
Implementare (map.cpp)
Implementarea funcțiilor din clasa Map.
Afișarea grafică a hărții utilizând o structură de date vectorială.


Fișierele clasei Painter
Antet (abstract_painter.hpp și painter.hpp)
Crearea unei clase abstracte AbstractPainter cu funcții virtuale pure pentru desenare și scriere de text.
Derivarea clasei Painter din AbstractPainter.
Integrarea bibliotecii SFML pentru suport grafic.
Implementare (painter.cpp)
Implementarea funcțiilor din Painter folosind SFML:
Desenarea de imagini în coordonate definite.
Scrierea de text pe ecran.


Fișierele clasei Player
Antet (player.hpp)
Crearea unei clase Player care include:
Nume pentru identificarea jucătorului.
Funcționalități pentru mișcarea jucătorului.
Implementare (player.cpp)
Implementarea funcționalității de mișcare a jucătorului.
Returnarea numelui jucătorului pentru afișare.


 Fișierul Makefile
Modificări majore:
Adăugarea regulilor pentru:
Compilarea bibliotecilor libmap.a și libpainter.so.
Legarea aplicației principale game cu aceste biblioteci.
Linkarea bibliotecii SFML în aplicație.
Structurarea clară a regulilor pentru compilare și curățare.


Alte modificări
Integrarea bibliotecilor externe
Utilizarea SFML pentru funcționalități grafice (în clasa Painter).
Configurarea corectă a legăturilor către aceste biblioteci.
