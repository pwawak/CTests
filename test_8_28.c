//
// Created by Piotr on 14-Dec-18.
//

/*
 * Napisz funkcje do wykonywania operacji na wektorach:
 *	•	unique - usuwa wszystkie oprócz pierwszego elementy z każdej kolejnej grupy sąsiadujących ze sobą elementów
 *			o tej samej wartości i zwraca długość nowego wektora, a w przypadku podania błędnych danych zwraca wartość -1,
 *	•	adjacent_find - zwraca indeks pierwszej pary sąsiadujących ze sobą elementów o równej wartości.
 *			W przypadku kiedy takie elementy nie wystąpią we wczytanym ciągu, funkcja powinna zwrócić -2,
 *			a w przypadku podania błędnych danych -1,
 *	•	mismatch - funkcja przyjmuje dwa wektory, i zwraca pierwszy numer indeksu, w którym wartości z tablicy
 *			first i second były różne. Dodatkowo do tablicy out zapisane mają zostać wartości tych dwóch elementów
 *			(w komórce 0 wartość z tablicy first, w komórce 1 z tablicy second).
 *			Jeżeli ciągi są takie same funkcja ma zwrócić liczbę spradzonych elementów, a tablicę out wypełnić zerami,
 *			a w przypadku podania błędnych danych -1.
 *
 * int unique(int first[], int size);
 * int adjacent_find(const int first[], int size);
 * int mismatch(const int first[], int size, const int second[], int size2, int out[2]);
 *
 * Napisz program, który pobierze od użytkownika ciągi liczb (nie więcej niż 150 elementów, zakończony 0) i wyświetli
 * po kolei:
 *	•	wektor v1, będący wynikiem zastosowania funkcji unique na wektorze wejściowym,
 *	•	wynik zastosowania funkcji adjacent_find na wektorze wejściowym,
 *	•	wynik zastosowania funkcji mismatch dla wektora v1 i wektora wejściowego.
 *			W przypadku, kiedy wartość zwrócona przez funkcję będzie różna od -1, program ma wypisać w tej samej linii, oddzielone spacjami wartości na jakich różniły się oba wektory.
 *	w przypadku wprowadzenia przez użytkownika błędnych danych program powinien wyświetlić komunikat
 *	Incorrect input i niezwłocznie zakończyć działanie z kodem błędu 1.
 *	W przypadku podania zbyt małej liczby danych program powinien wyświetlić komunikat not enough data available
 *	i zakończyć działanie z kodem błędu 2
 *
 */

