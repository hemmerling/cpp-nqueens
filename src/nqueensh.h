#ifndef NQUEENS_H
#define NQUEENS_H
/* EasyCASE V6.5 14.06.1999 18:53:14 */
/* nqueensh.h */

#include <stdio.h>

#define FALSE 0
#define TRUE !0

// Groesse des Schachbretts
// SIZE_BOARD x SIZE_BOARD
#define SIZE_BOARD 8   
   
//  Loesung rekursiv finden
void MP_try(int);

// Initialisierung
void MP_init(void);

// Ablaufplan
void MP_nqueens(void);

// Ausgabe der Ergebnisse
void MP_print(void);

// Check, ob Schachbrett-Position "sicher" ist
int MP_check (int, int, int *, int *, int *);

// Feld zur Aufnahme der Information, ob 
// j-te Zeile frei ist
// int MV_spalte[];
#define SIZE_SPALTE SIZE_BOARD
#define OFFSET_SPALTE 1

// Feld zur Aufnahme der Information, ob
// k-te /-Diagonale ist frei 
// MV_li_diag[];
#define SIZE_LI_DIAG (2*SIZE_BOARD-1)
#define OFFSET_LI_DIAG 2

// Feld zur Aufnahme der Information, ob
// k-te \-Diagonale frei ist
// MV_re_diag[];
#define SIZE_RE_DIAG (2*SIZE_BOARD-1)
#define OFFSET_RE_DIAG -(SIZE_BOARD-1)

// Feld zur Aufnahme der Position der Dame */
#define SIZE_SCHACHBRETT SIZE_BOARD
#define OFFSET_SCHACHBRETT 1
// MV_schachbrett[SIZE_SCHACHBRETT]
//               [SIZE_SCHACHBRETT];

#endif
