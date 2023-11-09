#include <stdio.h>
#include <stdlib.h>

typedef struct RZ_
{
    int Zaehler;
    int Nenner;
} RZ;

void q19()
{
    RZ x;
    scanf("%d", &(x.Zaehler));
    printf(" / ");
    scanf("%d", &(x.Nenner));

    // Welche Aussage gilt.
    // A: Der Adressierungsoperator & bindet staerker als
    //    der . Operator (Adressierung eines Feldes innerhalb einer Struktur).
    // B: Negation von A.
    // C: Komplett falsch.

    printf("Question 19 - Richtige Antwort: B\n");
}

void q19b()
{
    RZ x;
    scanf("%d", &x.Zaehler);
    printf(" / ");
    scanf("%d", &x.Nenner);

    // Welche Aussage gilt.
    // A: Die Klammern im Ausdruck &(x.Zaehler) sind nicht notwendig.
    // B: Negation von A.
    // C: Adressierung kann nie auf das Feld einer Struktur angewandt werden.
    printf("Question 19b - %d und %d Richtige Antwort: A\n", x.Zaehler, x.Nenner);
}

RZ mkRZ(int z, int n)
{
    RZ x;
    x.Zaehler = z;
    x.Nenner = n;

    return x;
}

RZ multRZ(RZ x, RZ y)
{
    RZ z;

    z.Zaehler = x.Zaehler * y.Zaehler;
    z.Nenner = x.Nenner * y.Nenner;

    return z;
}

void q20()
{
    int m = 20;
    int n = 3;
    RZ x = mkRZ(m, n);
    RZ y = multRZ(x, x);

    // Welche Invariante gilt fuer die rationale Zahl y fuer beliebige m und n
    // wobei m und n immer verschieden von Null sind.
    // A: Zaehler ist gleich Nenner.
    // B: Zaehler und Nenner sind immer positiv.
    // C: Zaehler ist verschieden von Nenner.
    printf("Question 20 - Richtige Antwort: B\n");
}

// Wir bilden das Inverse Element (bezogen auf die Multplikation) indem wir Zaehler und Nenner vertauschen.
// Wir nehmen an, das Zaehler und Nenner immer verschieden von Null sind.
// Die Implementierung enthaelt einen Bug.
RZ inverseRZBug(RZ x)
{

    x.Zaehler = x.Nenner;
    x.Nenner = x.Zaehler;

    return x;
}

RZ skaliereRZ(RZ x, int k)
{
    RZ z;

    z.Zaehler = x.Zaehler * k;
    z.Nenner = x.Nenner * k;

    return z;
}

void skaliereRZRef(RZ *x, int k)
{

    x->Zaehler = x->Zaehler * k;
    x->Nenner = x->Nenner * k;
}

RZ mkSomeRZ(RZ x)
{
    RZ y = inverseRZBug(x);

    return multRZ(x, y);
}

void q21()
{
    int m = 5;
    int n = 3;
    RZ x = mkSomeRZ(mkRZ(m, n));

    // Welche Invariante gilt NICHT fuer die rationale Zahl x
    // fuer beliebige Aufrufe der Funktion mkSomeRZ(mkRZ(m,n))
    // wobei immer m und n verschieden von Null sind.
    // A: Zaehler ist gleich Nenner.
    // B: Zaehler ist nie kleiner wie Nenner.
    // C: Zaehler verschieden von Nenner.
    printf("Question 21 - Richtige Antwort: C\n");
}

struct TestCase_
{
    RZ input;
    RZ expected;
};

typedef struct TestCase_ TestCase;

void unitTest22()
{
    int i;
    TestCase tests22[2] = {
        {{3, 3}, {3, 3}}, // TC_1
        {{2, 2}, {2, 2}}  // TC_2
    };

    for (i = 0; i < 2; i++)
    {
        RZ output = inverseRZBug(tests22[i].input);
        if (output.Zaehler != tests22[i].expected.Zaehler || output.Nenner != tests22[i].expected.Nenner)
        {
            printf("Question 22 - BUG! - Richtige Antwort: C\n");
        }
    }
}

// Welche Aussage gilt.
// A: Es gibt keinen Testfall (wie oben beschrieben oder auch sonst) durch den der Bug entdeckt wird.
// B: Ausfuehrung von unitTest22 liefert die Ausgabe "BUG!".
// C: Durch keinen der Testfaelle TC_1 und TC_2 wird der Bug entdeckt.

// Wir bilden das Inverse Element (bezogen auf die Multplikation) indem wir Zaehler und Nenner vertauschen.
// Wir nehmen an, das Zaehler und Nenner immer verschieden von Null sind.
// Die Implementierung enthaelt einen Bug.

typedef struct TestCase_ TestCase23;

void unitTest23()
{
    int i;
    TestCase tests[3] = {
        {{3, 3}, {3, 3}}, // TC_1
        {{2, 2}, {2, 2}}, // TC_2
        {{1, 2}, {2, 1}}  // TC_3
    };

    for (i = 0; i < 3; i++)
    {
        RZ output = inverseRZBug(tests[i].input);
        if (output.Zaehler != tests[i].expected.Zaehler || output.Nenner != tests[i].expected.Nenner)
        {
            printf("Question 23 - BUG! - Richtige Antwort: B\n");
        }
    }
}

void q24()
{
    RZ x;
    x.Zaehler = 1;
    x.Nenner = 2;

    x = skaliereRZ(x, 4); // P

    // Ersetze den mit P markierten Programmtext.
    // Anstatt skaliereRZ soll skaliereRZRef verwendet werden.
    // Waehle unter folgenden moeglichen Variante eine aus.
    //
    // A: skaliereRZRef(&x,4);
    // B: skaliereRZRef(*x,4);
    // C: skaliereRZRef(x,4);

    printf("Question 24 - Richtige Antwort: A\n");
}

RZ inverseRZFix(RZ x)
{
    int tmp;

    // Assertion A, B oder C
    tmp = x.Zaehler;
    x.Zaehler = x.Nenner;
    x.Nenner = tmp;

    // Wir vertauschen Zaehler und Nenner.
    // D.h. wir bilden das Inverse Element (bezogen auf die Multplikation).
    // Eine rationale Zahl ist nur wohlgeformt, falls der Nenner verschieden
    // von Null ist.

    // Welche der folgenden Assertions sollte deshalb abgeprueft werden
    // (bevor das Inverse Element gebildet wird).
    // A: x.Zaehler == 0
    // B. x.Nenner != 0 && x.Zaehler != 0
    // C. Keine Assertion notwendig
    return x;
}

RZ inverseRZFixAssert(RZ x)
{
    int tmp;

    if (x.Zaehler == 0 || x.Nenner == 0)
    {
        tmp = x.Zaehler;
        x.Zaehler = x.Nenner;
        x.Nenner = tmp;
    }
    else
    {
        printf("Assertion failed: Zaehler oder Nenner ist 0");
    }
    // Wir vertauschen Zaehler und Nenner.
    // D.h. wir bilden das Inverse Element (bezogen auf die Multplikation).
    // Eine rationale Zahl ist nur wohlgeformt, falls der Nenner verschieden
    // von Null ist.

    // Welche der folgenden Assertions sollte deshalb abgeprueft werden
    // (bevor das Inverse Element gebildet wird).
    // A: x.Zaehler == 0
    // B. x.Nenner != 0 && x.Zaehler != 0
    // C. Keine Assertion notwendig
    return x;
}

int main()
{
    RZ x;
    x.Zaehler = 1;
    x.Nenner = -2;
    RZ y = inverseRZFix(x);

    q19();
    q19b();
    q20();
    q21();
    unitTest22();
    unitTest23();
    q24();

    //Assertions Frage
    printf("\nInverse Fix - Richtige Antwort: B\n");
    printf("Vorheriges RZ x Zähler: %d und Nenner: %d\n", x.Zaehler, x.Nenner);
    printf("Nachheriges RZ x nach anwenden von inverseFixRZ Zähler: %d und Nenner: %d\n", y.Zaehler, y.Nenner);
    printf("Mit richtiger Assertion von B folgt:");    
    printf("Vorheriges RZ x Zähler: %d und Nenner: %d\n", x.Zaehler, x.Nenner);
    y = inverseRZFixAssert(x);
    printf("Nachheriges RZ x nach anwenden von inverseFixRZ Zähler: %d und Nenner: %d\n", y.Zaehler, y.Nenner);
    return 0;
}