#include <stdio.h>

/*

void q9() {
  float f = 18 / 10;
  printf("%f", f);

  // Welche Aussage gilt?
  // Obiger Programmtext liefert
  // A: 2
  // B: 0
  // C: Weder 2 noch 0


}
*/
/*
struct position {
  int x;
  float y;
};

void f(struct position p) {
  p.x = 0;

}
void q10() {
  struct position p1 = {1, 2.0};

  f(p1);

  printf("%d", p1.x);

  // Welche Ausgabe liefert obige printf Anweisung.
  // A: 0
  // B: 2
  // C: 1
}

*/
/*
typedef struct RZ_ {
    int Zaehler;
    int Nenner;
} RZ;

void q19b() {
  RZ x;
  scanf("%d", &x.Zaehler);
  printf(" / ");
  scanf("%d", &x.Nenner);
  printf("%d und %d", x.Zaehler, x.Nenner);
  // Welche Aussage gilt.
  // A: Die Klammern im Ausdruck &(x.Zaehler) sind nicht notwendig.
  // B: Negation von A.
  // C: Adressierung kann nie auf das Feld einer Struktur angewandt werden.
}
*/
typedef struct RZ_ {
    int Zaehler;
    int Nenner;
} RZ;

// Wir bilden das Inverse Element (bezogen auf die Multplikation) indem wir Zaehler und Nenner vertauschen.
// Wir nehmen an, das Zaehler und Nenner immer verschieden von Null sind.
// Die Implementierung enthaelt einen Bug.
RZ inverseRZBug(RZ x) {

  x.Zaehler = x.Nenner;
  x.Nenner = x.Zaehler;

  return x;
}
struct TestCase_ {
  RZ input;
  RZ expected;

};

typedef struct TestCase_ TestCase;

void unitTest23() {
  int i;
  TestCase tests[3] = {
    {{3,3}, {3,3}},  // TC_1
    {{2,2}, {2,2}},  // TC_2
    {{1,2}, {2,1}}   // TC_3
  };

  for(i=0; i<3; i++) {
    RZ output = inverseRZBug(tests[i].input);
    if(output.Zaehler != tests[i].expected.Zaehler || output.Nenner != tests[i].expected.Nenner) {
      printf("\n BUG!");
    }

  }

}

int main() {
  unitTest23();
  return 0;
}