#include "nqueens.h"

void NQueens::MP_nqueens(void)
   {
   
   // Feldinitialisierung
   MP_init();

   // Aufruf der Suchfunktion
   MP_try(1);

   }

 void NQueens::MP_try (int VV_zeile /* aktuell bearbeitete Zeile */ )
   {
   
   // Laufvariable
   int PV_spalte = 1;

   // Schleife ueber alle Spalten
   do
      {
      // Abfrage ob "sicherer" Platz fuer Dame
      if (MP_check (VV_zeile, PV_spalte,
                            MV_spalte,
                            MV_li_diag,
                            MV_re_diag))
         {
         // Dame setzten
         MV_schachbrett[VV_zeile - OFFSET_SCHACHBRETT]
                                   [PV_spalte - OFFSET_SCHACHBRETT] = TRUE;
         // Vektoren aktualisieren: Die gesetzte Dame "blockiert" eine
         // Spalte, eine linke und rechte Diagonale 
         MV_spalte[PV_spalte - OFFSET_SPALTE] = FALSE;
         MV_li_diag[VV_zeile + PV_spalte - OFFSET_LI_DIAG] = FALSE;
         MV_re_diag[VV_zeile - PV_spalte - OFFSET_RE_DIAG] = FALSE;
         // Wenn noch nicht alle Zeilen durchprobiert sind, dann
         // rekursiver Funktionsaufruf, sonst Ausgabe
         if (VV_zeile < SIZE_BOARD)
            {
            // rekursiver Funktionsaufruf 
            // fuer naechste Zeile
            MP_try(VV_zeile + 1);
            }
         else
            {
            
            // Ergebnisausgabe
            MP_print();

            }
         //  Dame wieder wegnehmen
         MV_schachbrett[VV_zeile - OFFSET_SCHACHBRETT]
                                   [PV_spalte - OFFSET_SCHACHBRETT] = FALSE;
         //  Vektoren aktualisieren: Die weggenommene Dame "blockiert"
         // die Spalte, rechte und linke Diagonale nicht mehr
         MV_spalte[PV_spalte - OFFSET_SPALTE] = TRUE;
         MV_li_diag[VV_zeile + PV_spalte - OFFSET_LI_DIAG] = TRUE;
         MV_re_diag[VV_zeile - PV_spalte - OFFSET_RE_DIAG] = TRUE;
         }
      else
         {
            // Wenn Platz "unsicher", einfach nix tun 
            // und auf naechste Spalte hoffen !
         };
      // Naechste Spalte anwaehlen
      PV_spalte++;
      }
   while (PV_spalte <= SIZE_BOARD);
   }

 void NQueens::MP_print(void)
   {
   // Laufvariable
   int LV_ii = 0; 
   int LV_jj = 0;
   
   //
   // Ausgabe *einer* Loesung
   // Zeilenweise Ausgabe des Schachbretts
   // "D" fuer gesetzte Dame, "+" fuer leeres Feld
   //
   for (LV_ii=0;LV_ii<SIZE_SCHACHBRETT;LV_ii++)
      {
      for (LV_jj=0;LV_jj<SIZE_SCHACHBRETT;LV_jj++)
         {
         if (MV_schachbrett[LV_ii][LV_jj])
            {
            printf("D ");
            }
         else
            {
            printf("+ ");
            };
         };
      // Schachbrettzeile abschlieáen
      printf("\n");
      };
   // Schachbrett mit Leerzeile abschliessen
   printf ("\n");
   }

 void NQueens::MP_init(void)
   {
   
   // Laufvariable
   int LV_ii = 0;
   int LV_jj = 0;
   
   // Feld-Initialisierung
   for (LV_ii=0; 
        LV_ii<SIZE_SPALTE; LV_ii++)
      {
      MV_spalte[LV_ii] = TRUE;
      }
   for (LV_ii=0; 
        LV_ii<SIZE_LI_DIAG; LV_ii++)
      {
      MV_li_diag[LV_ii] = TRUE;
      }
   for (LV_ii=0; 
        LV_ii<SIZE_RE_DIAG; LV_ii++)
      {
      MV_re_diag[LV_ii] = TRUE;
      }
   for (LV_ii=0; 
        LV_ii<SIZE_SCHACHBRETT; LV_ii++)
      {
      for (LV_jj; 
           LV_jj<SIZE_SCHACHBRETT; 
           LV_jj++)
         {
         MV_schachbrett[LV_ii][LV_jj] = FALSE;
         };
      };
   }

 int NQueens::MP_check(int VV_zeile
                       /* Zeile */,
                       int VV_spalte 
                       /* Spalte */, 
                       int *IV_spalte 
                       /* Feld mit belegten/freien Spalten) */, 
                       int *IV_li_diag 
                       /* Feld mit belegten/freien linken Diagonalen */,
                       int *IV_re_diag 
                       /* Feld mit belegten/freien rechten Diagonalen */)
   {
   // * Berechnung, ob eine Position fuer eine Dame "sicher" ist: 
   // * Spalte, rechte und linke Diagonale muessen noch "frei" sein
   // * Rueckgabewert: 
   // TRUE = Position ist "sicher"
   // FALSE = Position ist "nicht sicher"
   return (IV_spalte[VV_spalte - 
                            OFFSET_SPALTE] && 
          IV_re_diag[VV_zeile -
                             VV_spalte -
                             OFFSET_RE_DIAG] &&
          IV_li_diag[VV_zeile +
                           VV_spalte -
                           OFFSET_LI_DIAG]);
   }



main()
   {
   NQueens *x = new NQueens;
   x->MP_nqueens();
   return 0;
   }
// Ende
