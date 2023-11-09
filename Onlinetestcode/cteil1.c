#include <stdio.h>

/*

*/

void q1() {
  int x = 1;
  float y = 3;

  printf("%d %f", y, x);
  printf("Richtige Antwort: C");
  // Welche Art von Fehler hat sich eingeschlichen?
  // A: Die Variablennamen sind zu kurz.
  // B: Ein Argument fehlt.
  // C: Typspezifische Konvertierung wird falsch angewandt.
}

void q2() {
  char x[] = "Hallo";

  printf("Richtige Antwort: C");
  // Wie gross ist das Array (Anzahl der Elemente im Array)?
  // A: Variabel.
  // B: 5.
  // C: 6.
}

void q3() {
  char x[] = "Hallo";

  printf("%s", x);     // A
  printf("%c", x[0]);  // B
  printf("%c", x[7]);  // C

  printf("Richtige Antwort: A");
  // Welche Anweisung (A, B oder C) gibt den String "Hallo" auf der Konsole aus?
}

void q4() {
  int i;
  char x[] = "abc";

  for(i = 0; i < 3; i++) {
    // A, B oder C
  }

  printf("Richtige Antwort: B");

  // Ziel ist die Ausgabe des Strings "abc" (genau einmal).
  // Welche Anweisung (A, B oder C) eingefuegt in die for-Schleife erfuellt das Ziel?
  // A: printf("%s", x);  
  // B: printf("%c", x[i]);
  // C: printf("%d", x[i]);
}

void q5() {
  int i;
  char x[] = { 'a', 'b' };

  for(i = 0;               // A
      i < 3;               // B
      i++)
  {
    printf("%c", x[i]);    // C
  }

  // Ziel ist die Ausgabe der Zeichen a und b.
  // In obigem Programmtext befindet sich ein Fehler.
  // Bennen Sie die fehlerhafte Anweisung (A, B oder C).
 
  printf("Richtige Antwort: B");
}

void q6() {
  int j1;
  float f;

  scanf("%d %f", &j1);

  // Welche Art von Fehler hat sich eingeschlichen?
  // A: Die Variablennamen sind zu kurz.
  // B: Ein Argument fehlt.
  // C: Typspezifische Konvertierung wird falsch angewandt. 
  printf("Richtige Antwort: B");

}

void q7() {
  int j;

  scanf("%d", j);

  // Welche Art von Fehler hat sich eingeschlichen?
  // A: Die Variablennamen sind zu kurz.
  // B: Wertuebergabe anstatt Referenzuebergabe.
  // C: Kein Fehler
  printf("Richtige Antwort: B");
}

void q8() {
  int i;             // A

  scanf("%d", &i);   // B
  printf("%d", &i);  // C

  // Ziel ist die Ausgabe des Inhalts von i.
  // Welche Anweisung (A, B oder C) ist fehlerhaft?
  printf("Richtige Antwort: C");

}

void q9() {
  float f = 18 / 10;
  printf("%f", f);

  // Welche Aussage gilt?
  // Obiger Programmtext liefert
  // A: 2
  // B: 0
  // C: Weder 2 noch 0
  printf("Richtige Antwort: C");
}

int main() {
  q1();
  q2();
  q3();
  q4();
  q5();
  q6();
  q7();
  q8();
  q9();
  return 0;
}