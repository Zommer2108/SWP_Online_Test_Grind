#include <stdio.h>
#include <stdlib.h>

struct position
{
    int x;
    float y;
};

void f(struct position p)
{
    p.x = 0;
}
void q10()
{
    struct position p1 = {1, 2.0};

    f(p1);

    printf("%d\n", p1.x);

    // Welche Ausgabe liefert obige printf Anweisung.
    // A: 0
    // B: 2
    // C: 1
    printf("Richtige Antwort: C\n");
}

/*struct position
{
    int x;
    float y;
};
*/
struct position g(struct position p)
{
    struct position q;

    q = p;
    q.x++;

    return q;
}

void q10b()
{
    struct position p1 = {1, 2.0};

    p1 = g(p1);

    printf("%d\n", p1.x);

    // Welche Ausgabe liefert obige printf Anweisung.
    // A: 0
    // B: 2
    // C: 1

    printf("Richtige Antwort: B\n");
}

/*struct position
{
    int x;
    float y;
};*/

void h(struct position *p)
{
    (*p).x = 0;
}

void q11()
{
    struct position p1 = {1, 2.0};

    h(&p1);

    printf("%d\n", p1.x);

    // Welche Ausgabe liefert obige printf Anweisung.
    // A: 0
    // B: 2
    // C: 1
    printf("Richtige Antwort: A\n");
}

/*struct position
{
    int x;
    float y;
};
*/
/*void h(struct position *p)
{
    (*p).x = 0;
}*/

void q11b()
{
    struct position p1 = {1, 2.0};

    // h(p1);

    // Obiger auskommentierter Programmtext ist fehlerhaft. Wieso?
    // A: Der Variablenname ist zu lang.
    // B: Funktion h erwartet eine Referenz und nicht einen Wert.
    // C: Eine Referenz verweist auf einen Wert.
    printf("Richtige Antwort: B\n");
}

/*struct position
{
    int x;
    float y;
};*/

void q12()
{
    struct position p = {1, 2.0};
    struct position *q = &p;

    (*q).y = 3.0;

    // Welche der folgenden Anweisungen ist aequivalent zu obiger Zuweisung.
    // A: *q.y = 3.0;
    // B: q*y = 3.0;
    // C: q->y = 3.0;

    printf("Richtige Antwort: C\n");
}

void q13()
{
    int a[] = {1, 2, 3, 4};
    int j;
    int *q;

    for (j = 0; j < 4; j++)
    {
        a[j] = 0;
    }

    // Welche der folgenden Anweisung entspricht der Zuweisung a[j] = 0;
    // A: a[j] = j;
    // B: a+j = 0;
    // C: *(a+j) = 0;
    printf("Richtige Antwort: C\n");
}

void q13b()
{
    int a[] = {1, 2, 3, 4};
    int j;
    int *q;

    for (j = 0; j < 4; j++, q++)
    {
        *q = 0;
    }

    // Obige Schleife setzt alle Elemente im Array auf 0.
    // Es fehlt die Initalisierung von q.
    // Welche der folgenden Anweisungen beschreibt die korrekte Initialisierung von q.
    // A: q = &a[0];
    // B: a = q;
    // C: q = &a;

    printf("Richtige Antwort: A\n");
}

/*struct position
{
    int x;
    float y;
};*/

void q14()
{
    struct position *p = malloc(sizeof(struct position));

    // Welche der folgenden Aussagen ist falsch.
    // A: Variable p wird auf dem Stack verwaltet.
    // B: Struktur vom Typ position wird auf dem Heap verwaltet.
    // C: Alle Daten liegen auf dem Stack.

    printf("Richtige Antwort: C\n");
}

/*struct position
{
    int x;
    float y;
};*/

void q14b()
{
    struct position *p = malloc(sizeof(struct position));

    // Die Funktion hat ein Speicherleck. Wieso?
    // A: Speicher belegt von Variable p muss explizit freigegeben werden.
    // B: Es gibt kein Speicherleck hier.
    // C: Der von der Struktur position angelegte Speicher muss freigegeben werden.

    printf("Richtige Antwort: C\n");
}

struct pointer
{
    void *ptr;
};

void q15()
{
    int i = 5;
    struct pointer p;
    p.ptr = &i;

    //

    printf("%d", *((int *)(p.ptr)));

    // Welche Aussage gilt bezogen auf obigen Programmtext.
    // A: Die Ausgabe liefert 5.
    // B: Keine Ausgabe.
    // C: Der Compiler akzeptiert das Programm nicht.
    printf("Richtige Antwort: A");
}

void mapInt(int *p, int len, int (*f)(int))
{
    int i;
    for (i = 0; i < len; i++)
        p[i] = (*f)(p[i]);
}

int inc(int x)
{
    return x + 1;
}

void q16()
{
    int a[] = {1, 2, 3};

    mapInt(a,     // A
           4,     // B
           &inc); // C

    // In obigem Aufruf von mapInt hat sich ein Fehler eingeschlichen.
    // Benennen Sie die fehlerhafte Stelle (A, B oder C).

    printf("Richtige Antwort: B\n");
}

char *find(char *p, char c)
{
    while (*p != c)
    {
        p++;
    }
    return p;
}

void q17()
{
    char b[] = "12345";

    printf("%s", find(b, '3'));

    // Welche Ausgabe liefert obige Anweisung.
    // A: "345"
    // B: "12"
    // C: Keine Ausgabe.

    printf("Richtige Antwort: A\n");
}

char *find2(char *p, char c)
{
    char *q = p;

    while (*p != c)
    {
        p++;
    }
    *p = '\0';

    return q;
}

void q18()
{
    char b[] = "abc";

    printf("%s", find2(b, 'b'));

    // Welche Ausgabe liefert obige Anweisung.
    // A: "345"
    // B: "bc"
    // C: "a"
    printf("Richtige Antwort: C\n");
}

int main()
{
    q10();
    q10b();
    q11();
    q11b();
    q12();
    q13();
    q13b();
    q14();
    q14b();
    q15();
    q16();
    q17();
    q18();
    return 0;
}