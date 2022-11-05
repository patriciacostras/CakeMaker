# CakeMaker
Endless cakes! The story that never ends…
Aplicaţia simulează un aparat de făcut prăjitură automat cu resurse nelimitate. Rolul lui principal este să servească clientul cu prăjitura dorită. În altă ordine de idei clientul va avea un meniu principal care îi va oferi clientului anumite posibilităţi de selecţie. Vom urmări mai jos arhitectura completă a aplicaţiei noastre.
Rețineți că aplicația simulează crearea de prăjituri la comandă….nelimitat 😊.
Se identifică următoarele componente:

● Command Panel - această componentă este interfaţa cu clientul, dat fiind că este o simulare această va fi CLI (command line interface). El va conţine toate funcţiile necesare pentru a satisface dorinţele clientului.

● Command Taker - această componentă preia comanda de la CommandPanel. El comunică, CakeMaker and CarouselOfCakes.

○ Functionalitatea lui CommandTaker este aceea de a onora comenzile date de client. El le administrează conform funcţionalităţii lui, şi anume: în momentul în care primeşte o comandă de la CommandPanel. Onorarea comenzii constă în verificarea cum că produsul se află în CarouselOfCakes (mini storage), dacă aceasta există, va fi eliminat din carousel of Cakes şi îi va distribuii clientului. În cazul în care nu se află în CarouselOfCakes, acesta îl va interoga pe CakeMaker cerându-i să onoreze comanda.

● CarouselOfCakes - acesta este un storage de prăjituri. Are o capacitate maximă de 12 prăjituri. El va accepta doar elemente de tipul Prăjitura. Acest aspect în vom aborda mai târziu în proiect.
● CakeMaker - este cel care face prajitura. El realizează o prăjitură într-un interval specificat in reteta.

CommandPanel
- atributele clasei: lista de reţete şi componenta CommandPanel
- functionalităţi:
- showProducts(): va afişa toate produsele care sunt disponibile pentru cumpărare
- selectProduct(name: string): va selecta produsul dorit din meniu şi îl va transmite mai departe lui CommandTaker pentru a fi preluată comanda.
- selectProduct(name: string, nrOfProducts: int): supraîncarcată metoda de mai sus fiind precizat şi cantitatea produsului dorit.
- showProductsInCarousel(): va afişa în consolă ce va produse sunt în depozitul circular.
CommandTaker
- atributele clasei: CarouselOfCakes – cel ce detine cele mai cumparate prajituri, CakeMaker-ul cel ce face prijiturile, CakeRecipe – lista cu prajituri gata facute.
- funcţionalităţi:
- takeCommand(recipe: CakeRecipe): Cake - preia comanda de la CommandPanel si o trimite mai departe CakeMaker-ului. Inainte El mai face o verificare daca prajitura se afla in CarouselOfCakes, dacă acolo se află produsul dorit atunci se va lua direct de acolo.
- takeCommand(recipe: CakeRecipe, nrOfCakes): Array[Cake] - preia comanda în cazul în care sunt mai multe. Dacă se cere o cantitate de produse atunci se va cere direct CakeMaker-ului.
- getCakesFromCarousel(): Array[Cake] - returnează lista de prăjituri ce se află în CarouselOfCakes.
- checkCarouselOfCakes(): bool - verifică capacitatea curentă din CarouselOfCakes.
- refillCarousel():void - dacă capacitatea din Carousel este mică, această metodă îi va cere lui CakeMaker să facă atâtea prăjituri câte sunt necesare pentru a umple CarouselOfCakes la maxim.
CakeMaker
- atributele clasei: -
- funcţiile clasei:
- takeCommand(recipe: RecipeCake): Cake - această metodă simulează crearea unei prăjituri şi anume pentru fiecare reţetă primită, această aşteaptă 5 secunde, după care ajunge să returneze un obiect de tip Cake. Din reţetă va prelua numele.
![image](https://user-images.githubusercontent.com/104904530/200133009-d2d69545-20e6-44e5-9cd0-03afb106816f.png)

![image](https://user-images.githubusercontent.com/104904530/200133129-c5951e96-0d78-46c4-ac8d-3cf9298ae761.png)
