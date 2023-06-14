LAB02

Napisz program szyfrujący tekst wprowadzany przez użytkownika. W tym celu przygotuj tablicę dwuwymiarową A o wymiarze 5 na 5 przechowującą wartości typu `char`, oraz tablicę jednowymiarową B, przechowującą wskaźniki do zmiennych typu `char`. Do tablicy B wpisz wartości `NULL`, a do tablicy A wpisz litery alfabetu (z pominięciem liter zawierających znaki diakrytyczne: ą, ć, ę, ł, ń, ó, ś, ź, ż).
Następnie wczytaj od użytkownika ciąg znaków bez spacji, reprezentujący dowolny napis składający się tylko ze znaków z tablicy A, którego długość nie jest większa niż długość tablicy jednowymiarowej B. Zakładamy przy tym, że dane wprowadzane przez użytkownika są zawsze poprawne co do ich wartości i rozmiaru. Napis wczytaj poleceniem `scanf` do pomocniczej tablicy. Następnie dla każdej kolejnej litery wczytanego napisu znajdź w tablicy A komórkę, przechowującą tę literę, po czym adres znalezionej komórki w A zapisz w kolejnej komórce tablicy B. Po zakończeniu tablica B powinna zawierać wskaźniki do odpowiednich komórek tablicy A z kolejnymi literami wprowadzonego napisu. Jeżeli długość tablicy B jest większa niż długość wczytanego słowa, pozostałe komórki tablicy B przechowują wartość `NULL`.

Wypisz w oknie konsoli napis podany przez użytkownika korzystając tylko z tablicy B, tj. za pomocą wskaźników z B sięgaj do odpowiednich komórek w A i wypisz ich zawartość kolejno na ekranie.

Następnie zaszyfruj napis poprzez przestawienie wartości w wierszach tablicy A. Przykładowe przestawienie to przesunięcia wartości: z wiersza 1 do 2, z 2 do 3, z 3 do 4, z 4 do 5, a z 5 do 1.
Po przestawieniu wierszy ponownie wypisz w oknie konsoli napis korzystając ze wskaźników z tabeli B.

Na koniec przywróć w tablicy właściwy porządek wierszy i jeszcze raz korzystając z tablicy B wypisz napis, tym razem w postaci odszyfrowanej.

LAB03

Zadeklaruj strukturalny typ danych, który będzie zawierał dwa pola: napis oraz liczba całkowita. W funkcji `main` zadeklaruj lokalną tablicę o niewielkiej długości (np. 5), zawierającą elementy typu takiego, jak zdefiniowana wcześniej struktura.

Następnie napisz funkcję, która jako argument wywołania przyjmuje tę tablicę. Kod funkcji sprawdza, czy w każdej z komórek tablicy pole liczbowe nie zawiera wartości mniejszej (ale dodatniej) od długości napisu przechowywanego w drugim polu. Jeżeli tak, skraca napis do długości takiej, jak wartość w polu liczbowym. W przeciwnym przypadku pozostawia napis niezmieniony. Takie sprawdzenie i skracanie wykonuje się dla wszystkich komórek tablicy. Po przejrzeniu całej tablicy funkcja zwraca liczbę skróceń, jakie rzeczywiście zostały wykonane.

Napisz w funkcji `main` kod, który pozwala użytkownikowi wprowadzić wartości do obydwu pól w każdej z komórek tej tablicy. W `main`, poniżej kodu wprowadzającego dane umieść wywołanie funkcji skracającej napisy w tablicy, przy czym argumentem wywołania jest tablica, do której dane zostały właśnie przez użytkownika wprowadzone. Na koniec dopisz kod wyświetlający nową zawartość tablicy (w kolejnych wierszach pary: liczba i napis) oraz zwróconą przez funkcję liczbę faktycznie wykonanych skróceń.

LAB04

Napisz program, który będzie wczytywał dane z jednego pliku tekstowego i zmienione zapisywał do drugiego. W tym celu:

1.  Zadeklaruj strukturalny typ danych `struct para` zdefiniowany tak, że zmienna takiego typu może przechowywać dwie wartości: napis oraz liczbę. W funkcji `main` zadeklaruj lokalną tablicę o długości 5, zawierającą elementy typu `struct para`.
2.  Napisz funkcję `wiersz`, która będzie odczytywała dane z wiersza w otwartym pliku. W wierszu zapisane są kolejno: nr indeksu studenta, nazwisko i ocena. Funkcja odczytuje dane z jednego wiersza, następnie ignoruje odczytany nr indeksu a do komórki tablicy wpisuje w odpowiednich polach tylko nazwisko i ocenę. Przyjmij, że w pliku może być dowolna liczba wierszy (jest możliwe również, że plik jest pusty), ale nie większa niż rozmiar tablicy. Przyjmij też, że dane w pliku są zawsze poprawne, tj. wiersz zawsze zawiera trójkę prawidłowych napisów w tej samej kolejności: numer, nazwisko i ocena.  
    Nagłówek funkcji ma wyglądać tak:  
    `int wiersz(FILE* f, struct para *p)`  
    gdzie `f` to wskaźnik do otwartego pliku, natomiast `p` to wskaźnik do komórki tablicy, do której mają zostać zapisane dane z jednego odczytanego wiersza pliku. Funkcja zwraca wartość zero, jeżeli odczyt zakończył się pomyślnie, a wartość 1, jeżeli nie udało się odczytać kolejnej porcji danych ze względu na koniec pliku.
3.  W funkcji `main` pobierz od użytkownika nazwę pliku z danymi oraz nazwę pliku wyjściowego. Otwórz plik z danymi w trybie do odczytu, a plik wynikowy w trybie do zapisu. Następnie w pętli za pomocą funkcji `wiersz` odczytaj kolejne wiersze pliku zapisując dane w kolejnych komórkach tablicy. Każdą odczytaną komórkę tablicy zapisz od razu do pliku wynikowego tak, aby w kolejnych wierszach pliku znalazły się pary: nazwisko i ocena. Uwaga: nazwisko należy zapisać do pliku w postaci zaszyfrowanej, tj. należy zastąpić wszystkie samogłoski znakiem '*’. Jeżeli nie wszystkie komórki tablicy zostały zapełnione danymi, zapisz do pliku tylko tyle, ile zostało odczytanych z pliku wejściowego. Po zakończeniu pętli zamknij pliki, wyświetl w oknie konsoli zawartość tablicy i zakończ działanie funkcji `main`.
4.  Przygotuj sobie odpowiedni plik tekstowy z prawidłowymi danymi w kilku wierszach i umieść go we właściwym folderze. Następnie przetestuj program.

Do obsługi plików wykorzystaj funkcje: `fopen`, `fclose`, `fprintf`, `fscanf` i `feof`. Wszystkie z biblioteki: `stdio.h`.

LAB05

Napisz funkcję `bin2int`, która jako argument przyjmuje wskaźnik do tablicy znaków (np. `char* t`) przechowującej liczbę zapisaną w postaci binarnej w taki sposób, że pierwszym znakiem musi być zawsze '1′, tj. np. `1001`, `100`, `10101111`, `1110010`, itp., i która zwróci wartość typu `int` odpowiadającą podanej liczbie binarnej (np. dla `1001` będzie to wartość `9`).

Następnie napisz program, który:

1.  Do dwuwymiarowej tablicy dynamicznej podobnej do tej prezentowanej na slajdach 127 i 128, wykład 4, ale przechowującej dane typu `char` i o wymiarach _m_ wierszy na _n_ kolumn (_m_ i _n_ podane przez użytkownika), wczyta z pliku tekstowego kilka liczb zapisanych w postaci binarnej. W każdym wierszu pliku znajduje się jedna liczba zapisana w taki sposób, że pierwszą cyfrą musi być zawsze 1, tj. np. `1001`, `100`, `10101111`, `1110010`, itp. Tak zapisane liczby mogą mieć różną liczbę znaków, ale nie większą niż _n_-1. W każdym wierszu tablicy przechowywana będzie jedna wczytana liczba. Przyjmij, że liczba wierszy w pliku nie jest znana, ale nie większa niż _m_, tak aby było wiadomo, że dane zmieszczą się w tablicy.
2.  Po zakończeniu wczytywania wywoła dla każdego ciągu binarnego z tablicy funkcję `bin2int`, która zwróci wartość typu `int` odpowiadającą podanej liczbie binarnej. Zwrócona wartość na być wypisana w oknie konsoli.
3.  Posortuje wczytane ciągi binarne w taki sposób, aby liczby całkowite reprezentowane przez ciągi były uporządkowane malejąco. Przemieszczenia ciągów binarnych nie dokonuj poprzez kopiowanie wartości z jednych tablic dynamicznych do drugich, ale poprzez zamianę położeń wartości wskaźników do dynamicznych tablic przechowujących ciągi binarne. To ważne: aby zmienić porządek, nie wykonuj żadnych alokacji nowych tablic dynamicznych, a jedynie zamieniaj adresy w komórkach tablicy wskaźników. Zastosuj dowolne sortowanie, np. _sortowanie przez wybór_. Uwaga: przygotuj swój program również na sytuację, kiedy plik z liczbami był pusty.
4.  Po zakończeniu przestawiania jeszcze raz wypisze w oknie konsoli wartości liczbowe dla wszystkich ciągów binarnych w tablicy ułożonych wg nowego porządku korzystając z funkcji `bin2int`.

LAB06

Przeprowadzono pomiary temperatury w terenie za pomocą czterech czujników temperatury w okresie od 10 lutego do 12 marca. Pomiary były wykonywane przez każdy z czujników co około 5 min. Mierzone wartości zostały zapisane w pliku ( [[do pobrania]](https://ktrojanowski.blog.uksw.edu.pl/files/edu/temp-na-zewn.txt "temp-na-zewn.txt") – _aby zapisać plik na dysk lokalny użyj prawego przycisku myszki i wybierz opcję „Zapisz element docelowy jako..” lub „zapisz link jako..”_). Plik zawiera listę rekordów, gdzie rekord to kolekcja kilku dowolnych wartości, każda ściśle określonego typu, występujących w ustalonej, zawsze tej samej kolejności (zobacz też [Wikipedia](https://pl.wikipedia.org/wiki/Rekord_(informatyka))). Każdy rekord w pliku reprezentuje pojedynczy pomiar i składa się z czterech wartości zapisanych w jednym wierszu pliku: nr pomiaru, nr czujnika, data i czas, oraz zmierzona temperatura, które rozdzielone są znakiem spacji.

W funkcji `main` pobierz od użytkownika nazwę pliku z danymi, otwórz ten plik w trybie do odczytu, a następnie wczytaj zawartość pliku do **listy dynamicznej jednokierunkowej**. Po zakończeniu czytania zamknij plik. Przyjmij, że dane w pliku są zawsze poprawne, tj. wiersz zawsze zawiera czwórkę prawidłowych napisów w tej samej kolejności.

Typ danych do przechowywania jednego rekordu ma następującą budowę:

```
struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
};
```

Następnie rozdziel elementy z wczytanej listy na cztery listy dynamiczne jednokierunkowe, po jednej liście dla każdego z czujników. W tym celu zadeklaruj cztery nowe głowy list, tj. wskaźniki typu `struct pomiar*`, po czym przejrzyj kolejno wszystkie elementy, sprawdź z jakiego czujnika pochodzi pomiar i przenieś ten element do listy właściwej dla tego czujnika. Nie alokuj nowych zmiennych dynamicznych reprezentujących pomiary i nie kopiuj żadnych danych, a jedynie wyjmuj elementy z jednej listy i dodawaj do jednej z pozostałych czterech. Na koniec działania lista źródłowa powinna być pusta.

Wypisz w oknie konsoli, ile pomiarów pochodzi z każdego z czujników, tj. jakie są rozmiary każdej z list.

Zapisz powstałe cztery listy do czterech plików o nazwach zaczynających się od tego samego ciągu znaków. W tym celu najpierw pobierz od użytkownika początek nazwy plików do zapisu, następnie dla każdego z plików dodaj do jego nazwy na jej końcu cyferkę odpowiadają numerowi czujnika i dodaj „.txt” (przykład: użytkownik podał „abc”, pliki nazywają się „abc1.txt”, abc2.txt”, „abc3.txt” i „abc4.txt”). Zapisz do każdego z plików zawartość odpowiadającej mu listy w takim samym formacie jaki miał plik wejściowy.

Po zakończeniu zapisywania zamknij pliki, usuń elementy z list i zakończ działanie programu.

Pobierz plik tekstowy z danymi wejściowymi i umieść go we właściwym katalogu. Do obsługi plików wykorzystaj funkcje `fopen`, `fclose`, `fprintf`, `fscanf` i `feof` (lub odpowiadających im wersji bezpiecznych). Wszystkie z biblioteki: `stdio.h`.

LAB07

Przeprowadzono pomiary temperatury w terenie za pomocą czterech czujników temperatury w okresie od 10 lutego do 12 marca. Pomiary były wykonywane przez każdy z czujników co około 5 min. Mierzone wartości zostały zapisane w pliku ( [[do pobrania]](https://ktrojanowski.blog.uksw.edu.pl/files/edu/temp-na-zewn.txt "temp-na-zewn.txt") – _aby zapisać plik na dysk lokalny użyj prawego przycisku myszki i wybierz opcję „Zapisz element docelowy jako..” lub „zapisz link jako..”_). Plik zawiera listę rekordów, gdzie rekord to kolekcja kilku dowolnych wartości, każda ściśle określonego typu, występujących w ustalonej, zawsze tej samej kolejności. Każdy rekord w pliku reprezentuje pojedynczy pomiar i składa się z czterech wartości zapisanych w jednym wierszu pliku: nr pomiaru, nr czujnika, data i czas, oraz zmierzona temperatura, które rozdzielone są znakiem spacji.

W funkcji `main` pobierz od użytkownika nazwę pliku z danymi, otwórz ten plik w trybie do odczytu, a następnie wczytaj zawartość pliku do **listy dynamicznej dwukierunkowej**. Po zakończeniu czytania zamknij plik. Przyjmij, że dane w pliku są zawsze poprawne, tj. wiersz zawsze zawiera czwórkę prawidłowych napisów w tej samej kolejności.

Typ danych do przechowywania jednego rekordu ma następującą budowę:

```
struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
	struct pomiar *poprz;
};
```

Następnie rozdziel elementy z wczytanej listy na cztery listy dynamiczne dwukierunkowe, po jednej liście dla każdego z czujników. W tym celu zadeklaruj cztery nowe głowy list, tj. wskaźniki typu `struct pomiar*`, po czym przejrzyj kolejno wszystkie elementy, sprawdź z jakiego czujnika pochodzi pomiar i przenieś ten element do listy właściwej dla tego czujnika. Nie alokuj nowych zmiennych dynamicznych reprezentujących pomiary i nie kopiuj żadnych danych, a jedynie wyjmuj elementy z jednej listy i dodawaj do jednej z pozostałych czterech poprzez działanie na wartościach pól `nast` i `poprz`. Na koniec działania lista źródłowa powinna być pusta.

Wypisz w oknie konsoli, ile pomiarów pochodzi z każdego z czujników, tj. jakie są rozmiary każdej z list oraz jakie są wartości najwyższej i najniższej zmierzonej temperatury dla każdego z czujników.

Zapisz powstałe cztery listy do czterech plików o nazwach zaczynających się od tego samego ciągu znaków. W tym celu najpierw pobierz od użytkownika początek nazwy plików do zapisu, następnie dla każdego z plików dodaj do jego nazwy na jej końcu cyferkę odpowiadają numerowi czujnika i dodaj „.txt” (przykład: użytkownik podał „abc”, pliki nazywają się „abc1.txt”, abc2.txt”, „abc3.txt” i „abc4.txt”). Zapisz do każdego z plików zawartość odpowiadającej mu listy w takim samym formacie jaki miał plik wejściowy.

Po zakończeniu zapisywania zamknij pliki, usuń elementy z list i zakończ działanie programu.

Pobierz plik tekstowy z danymi wejściowymi i umieść go we właściwym katalogu. Do obsługi plików wykorzystaj funkcje `fopen`, `fclose`, `fprintf`, `fscanf` i `feof` (lub odpowiadających im wersji bezpiecznych). Wszystkie z biblioteki: `stdio.h`.

LAB08

Napisz program, który pobiera od użytkownika jego nick oraz niewielką liczbę naturalną. Umieść w kodzie asercję, która sprawdza czy liczba jest rzeczywiście naturalna. Następnie program przystępuje do testu zręczności użytkownika: losuje literę występującą na klawiaturze (nie losuje cyfr, znaków interpunkcyjnych, matematycznych i pozostałych „symboli”) i wypisuje ją w oknie konsoli, po czym oczekuje na naciśnięcie przez użytkownika klawisza odpowiadającego wypisanej literze. Wtedy natychmiast losuje następną literę, wypisuje w oknie konsoli i ponownie czeka na reakcję użytkownika. Jeżeli użytkownik się pomylił, również natychmiast losuje i wypisuje kolejną literę. Program wykonuje test tyle razy, ile wynosiła pobrana liczba naturalna.

Po zakończeniu testu wyświetlany jest czas trwania testu (liczony od wypisania pierwszej litery aż do ostatniej odpowiedzi użytkownika) i liczba trafnych odpowiedzi. Do pomiaru czasu użyj funkcji `time` i `difftime`. Dodatkowo zostaje otwarty plik txt o nazwie takiej jak podany nick, tj. „_nick_.txt” i do niego w kolejnym wierszu są dopisywane uzyskane wyniki (czas i liczba trafień). Jeżeli takiego pliku jeszcze nie ma, program wypisuje w oknie konsoli komunikat o tym, że taki plik jest właśnie zakładany. W komunikacie podana jest pełna ścieżka do folderu, w którym plik zostanie utworzony wraz z jego nazwą. _Hint: pełną ścieżkę do bieżącego folderu można pobrać z_ `argv[0]`.

Każda akcja jest odnotowywana w pliku „log.txt”: pobranie nicka i liczby naturalnej, wypisanie litery na ekranie, odpowiedź użytkownika (wraz z informacją, czy była poprawna). Każdy wpis w pliku „log.txt” zaczyna się od daty i czasu dokonania wpisu z dokładnością do sekund. Następnie wypisywany jest komunikat o zdarzeniu. Plik „log.txt” należy otwierać tak, aby nie stracić jego dotychczasowej zawartości i aby nowe informacje były dołączane na końcu.

Uwagi:

1.  Zaproponuj własny sposób sprawdzenia, czy plik o podanej nazwie istnieje. Następnie napisz funkcję, która jako argument wywołania przyjmuje nazwę pliku, a zwraca wartość zero, jeżeli pliku nie ma, oraz 1 – jeżeli istnieje. Użyj tej funkcji do sprawdzenia, czy plik „_nick_.txt” istnieje.
2.  Do sprawdzania błędów związanych z dostępem do pliku „log.txt” wykorzystaj stałą `errno`, a do generowania komunikatów – funkcje `strerror` i `perror`. Wszelkie komunikaty o sytuacjach błędnych, jakie wystąpiły w trakcie pracy programu związane np. z dostępem do plików, wysyłaj do standardowego strumienia dla komunikatów o błędach `stderr`.

LAB09

Zaprojektuj klasę, reprezentującą figurę na płaszczyźnie: trapez równoramienny.

Zaproponuj zestaw pól dla tej klasy, pozwalający na jednoznaczne określenie jej położenia na płaszczyźnie względem początku układu współrzędnych oraz jednoznacznie określający jej rozmiary (np. długości boków, podstawy, itd.). Dla uproszczenia przyjmij, że trapez jest zawsze rysowany w określonej pozycji, np. podstawą równolegle do osi X. Projektując zestaw pól postaraj się zminimalizować ich liczbę, dobierając je tak, aby pozostałe brakujące wartości dało się wyznaczyć. _Np. gdyby to dotyczyło kwadratu, to do określenia położenia wystarczą współrzędne jednego z wierzchołków, np. lewy-dolny, a do określenia rozmiarów – długość jednego boku. Za pomocą tych wartości jesteśmy już w stanie łatwo wyznaczyć w kwadracie współrzędne wszystkich pozostałych wierzchołków oraz długości pozostałych boków._

Zbiór pól reprezentujących położenie trapezu powinien być rozłączny ze zbiorem pól reprezentujących jego rozmiary, tak aby ewentualne operacje zmiany położenia nie obejmowały modyfikacji pól rozmiaru, a np. skalowanie nie modyfikowało pól położenia. _Gdyby to dotyczyło kwadratu, to np. zbiór pól reprezentujących dwa wierzchołki, lewy-dolny i lewy-górny stanowi zły model. Mimo, że pozwala w pełni opisać kwadrat, jednak długość boku jest ukryta w danych o położeniu wierzchołków, więc operacja skalowania rozmiaru modyfikowałaby położenie jednego z wierzchołków._

Wszystkie pola mają być niedostępne z zewnątrz (zadeklarowane jako `private`).

Do klasy dodaj trzy metody zadeklarowane jako publiczne:

1.  Pierwsza – ma ustalać położenie i rozmiary figury, tj. modyfikować wartości pól opisujących położenie i rozmiar. Nowe wartości dla pól powinny być podawane w argumentach wywołania metody. Metoda powinna kontrolować poprawność wartości podawanych w argumentach wywołania i jeżeli są nieprawidłowe (np. ujemne długości boków) powinna je zastępować bezpiecznymi wartościami domyślnymi.
2.  Druga – powinna wypisywać wartości wszystkich pól figury w oknie konsoli oraz dodatkowo wypisywać aktualne współrzędne wszystkich jej wierzchołków i długości boków wyliczone na podstawie wartości pól.
3.  Trzecia – powinna wyrażać przekształcenie symetrii osiowej względem prostej opisanej równaniem _x=n_, tj. jako argument powinna przyjmować wartość rzeczywistą _n_, a w swoim działaniu powinna przeliczyć wszystkie wartości tych i tylko tych pól, które są odpowiedzialne za położenie tak, aby w rezultacie tego działania przyjęły one wartości określające położenie figury po przekształceniu.

Napisz program, który w funkcji `main` deklaruje obiekt typu `trapez`, po czym:

1.  inicjalizuje go wartościami pobranymi od użytkownika, tak aby powstał prawidłowy trapez, korzystając z metody nr 1,
2.  wywołuje na rzecz tego obiektu metodę nr 2 wypisującą wszystkie pola i współrzędne w oknie konsoli,
3.  prosi użytkownika o podanie argumentu dla metody symetrii osiowej i wywołuje na rzecz tego obiektu metodę nr 3,
4.  ponownie wywołuje na rzecz tego obiektu metodę wypisującą wszystkie pola i współrzędne w oknie konsoli, aby zobaczyć nowe położenie figury,
5.  ponownie wywołuje na rzecz tego obiektu metodę symetrii osiowej z tym samym argumentem co poprzednio,
6.  a na koniec jeszcze raz wywołuje metodę wypisującą wszystkie pola i współrzędne w oknie konsoli, aby sprawdzić, czy figura wróciła na swoje miejsce.

LAB10

Do klasy `MojaKlasa` ([https://ktrojanowski.blog.uksw.edu.pl/programowanie-obiektowe/kody-programow-po/](https://ktrojanowski.blog.uksw.edu.pl/programowanie-obiektowe/kody-programow-po/): Program #6) dodaj pole `nast`, tak aby można było tworzyć listę dynamiczną jednokierunkową obiektów typu `MojaKlasa`.

Następnie zaprojektuj nową klasę `Wykladowca`, która zawiera pole typu `MojaKlasa*` wskazujące na listę dynamiczną jednokierunkową. Pole to ma pełnić rolę głowy dynamicznej listy grup studenckich przypisanych do danego wykładowcy. Klasa `Wykladowca` może też zawierać inne pola, jeżeli okażą się potrzebne.

Do klasy `Wykladowca` dodaj konstruktory:

1.  **konstruktor domyślny**, inicjalizujący obiekt tak, aby lista dynamiczna była pusta.
2.  **konstruktor z argumentem** reprezentującym nazwę pliku tekstowego. Plik zawiera listę kilku adresów e-mail. Konstruktor tworzy jeden obiekt dynamiczny typu `MojaKlasa`, do którego zostają zapisane adresy e-mail odczytane z pliku. Następnie obiekt ten jest dołączany do listy dynamicznej.
3.  **konstruktor kopiujący**, który tworzy kopię listy dynamicznej z obiektu podanego w argumencie wywołania.

oraz destruktor, który zwalnia wszystkie dynamicznie zaalokowane zasoby.

Do klasy `Wykladowca` dodaj metodę `dodaj_klase` dodającą nowy obiekt do listy dynamicznej. Argumentem wywołania metody jest nazwa pliku tekstowego z listą adresów mailowych. W metodzie tworzony jest nowy obiekt dynamiczny typu `MojaKlasa`, zapisywane są w nim adresy mailowe ze wskazanego pliku, a na koniec obiekt jest dołączany do listy.

Do klasy `Wykladowca` dodaj też metodę `wypisz`, która wypisuje w oknie konsoli wszystkie grupy studenckie przypisane do danego wykładowcy, tj. dla każdego elementu listy dynamicznej wypisuje wszystkie zapisane w nim niepuste adresy mailowe.

Zademonstruj działanie napisanego kodu: w funkcji `main` utwórz obiekty dynamiczne typu `Wykladowca` z wykorzystaniem wszystkich trzech konstruktorów, do wybranego z wykładowców dodaj kilka nowych grup studenckich (metodą `dodaj_klase`), po czym dla każdego z wykładowców wywołaj metodę `wypisz`. Na koniec usuń obiekty dynamiczne typu `Wykladowca`, przy czym z pomocą debuggera upewnij się, że destruktor za każdym razem prawidłowo zwolnił wszystkie dynamicznie zaalokowane zasoby.

Przygotuj odpowiedź na pytanie prowadzącego: _ile razy w napisanym programie zostały wywołane konstruktory, które i w których miejscach kodu to nastąpiło. A ile razy zostały wywołane destruktory?_

LAB11

Zaprojektuj i zaimplementuj trzy klasy, które na zajęciach 11 posłużą jako klasy bazowe. Klasy reprezentują pojęcia:

1.  **samochód** – zawiera pola przechowujące cechy wspólne dla wszystkich samochodów (cena, rodzaj silnika).
2.  **urządzenie optyczne** – zawiera pola przechowujące cechy wspólne dla wszystkich takich urządzeń (zoom, waga).
3.  **osoba na uczelni** – zawiera pola przechowujące cechy wspólne dla wszystkich takich osób (imię i nazwisko, adres e-mail).

Wszystkie pola klasy bazowej powinny być zadeklarowane jako `public`. Mimo to, dla każdego z pól powinny istnieć odpowiednie _get_ery i _set_ery, aby na zajęciach laboratoryjnych prawa dostępu do tych pól mogły być zmieniane na bardziej ograniczające. Ponadto każda klasa musi mieć metodę `wypisz`, która wypisze w oknie konsoli wartości wszystkich pól obiektu w sposób graficznie przystępny dla użytkownika.

Do wszystkich klas zaprojektuj po trzy konstruktory: konstruktor domyślny inicjalizujący wszystkie pola obiektu rozsądnymi wartościami domyślnymi, konstruktor kopiujący oraz konstruktor z argumentami przechowującymi wartości dla inicjalizacji wszystkich pól.

Dodatkowo każda klasa bazowa powinna mieć jeszcze pole `nast`, zadeklarowane jako `public` i zawierające wskaźnik typu takiego jak klasa bazowa. Tym sposobem obiekty klasy bazowej będą mogły być wykorzystane jako elementy listy dynamicznej jednokierunkowej.

Zademonstruj poprawność działania zaprojektowanych klas, pisząc w funkcji `main` kod, budujący dla każdego z typów danych listę dynamiczną jednokierunkową zawierającą 5 elementów. Do tworzenia elementów listy użyj konstruktorów domyślnych. Po utworzeniu każdej z list wywołaj metodę `wypisz` na rzecz każdego z elementów listy. Na koniec usuń wszystkie listy.

LAB12

Do klasy bazowej wybranej do realizacji na lab. 11 (reprezentującej samochód albo urządzenie optyczne albo osobę na uczelni) dodaj przeciążony operator `+=` jako metodę należącą do klasy. Zaproponuj własną logikę sumowania obiektów (np. gdyby to było sumowanie kwadratów, to wynikiem sumowania może być kwadrat, którego pole jest sumą pól składników sumy, albo którego bok ma długość równą sumie długości boków składników sumy). Korzystając z kodu wejściówki na lab. 11 utwórz listę dynamiczną zawierającą 5 elementów typu klasy bazowej, po czym zsumuj je korzystając z napisanego operatora. Na koniec wywołaj metodę `wypisz` na rzecz obiektu przechowującego wartość sumy.

LAB13

Do klasy bazowej wybranej do realizacji na lab. 11 dodaj przynajmniej dwie metody czysto wirtualne. Następnie w dwóch klasach dziedziczących po tej klasie bazowej zaimplementuj odpowiednie wersje tych dwóch metod. W funkcji `main` utwórz jedną listę dynamiczną składającą się z obiektów obydwu typów klas dziedziczących (możesz wykorzystać kod rozwiązania zadania z lab. 11). Na przykładzie tej listy zademonstruj polimorfizm metod deklarowanych w bazowej jako czysto wirtualne (np. posługując się wskaźnikiem do typu bazowego wywołaj dla wszystkich obiektów w liście te czysto wirtualne metody, demonstrując w ten sposób ich różne działanie w zależności od typu obiektu).

LAB14

Napisz klasę reprezentującą kontener typu **zbiór z powtórzeniami**. Jest to struktura danych, w której nowe dane dopisywane są zawsze, nawet jeżeli wielokrotnie dodawana jest ta sama wartość, a porządek danych nie jest ustalony i może być dowolny. Kontener przechowuje obiekty typu `string` (dodaj w nagłówku pliku instrukcję `#include <string>`).

Do przechowywania danych w kontenerze wykorzystaj dowolną, najkorzystniejszą twoim zdaniem strukturę danych (np. dynamicznie zaalokowana tablica, albo lista dynamiczna..). Zobacz, jak został zaimplementowany kontener typu Tablica na slajdach 266-268 wykładu 12 oraz pełny kod tej klasy na stronie www (w sekcji: Program #11):  
[https://ktrojanowski.blog.uksw.edu.pl/programowanie-obiektowe/kody-programow-po/](https://ktrojanowski.blog.uksw.edu.pl/programowanie-obiektowe/kody-programow-po/)  
i ewentualnie skorzystaj z tych składowych, które uznasz za użyteczne.

Kontener powinien udostępniać metody: `insert` i `remove`, które odpowiednio dodają lub usuwają dane do lub z kontenera. Wartość podana w argumencie wywołania metody `remove` identyfikuje dane do usunięcia. W przypadku podania wartości, która występuje w kontenerze wielokrotnie, za jednym wywołaniem `remove` usuwane są od razu wszystkie duplikaty. Natomiast jeżeli użytkownik zażąda usunięcia wartości, która nie jest przechowywana w kontenerze, nie dzieje się nic. Dodaj też do kontenera metodę `exists`, która zwraca `true`, jeżeli wartość, podana w argumencie wywołania, występuje w kontenerze w przynajmniej jednym egzemplarzu, natomiast `false` – w przeciwnym przypadku.

Zademonstruj poprawne działanie kontenera, dodając do niego oraz odejmując kilka elementów i sprawdzając ich obecność w kontenerze, oraz na koniec usuwając cały, niepusty kontener.
