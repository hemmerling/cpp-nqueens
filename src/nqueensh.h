#ifndef NQUEENSH_H
#define NQUEENSH_H
/**
 *  @package   nqueens
 *  @file      nqueensh.h
 *  @brief     Das 8x8 Damen Problem - Suche nach *allen* Loesungen 
 *             Algorithmus: Cooper, Clancy (S.318)
 *             Made with EasyCASE V6.5 1999-06-14 18:43:31
 *  @author    Rolf Hemmerling <hemmerling@gmx.net>
 *  @version   1.00, 
 *             programming language "Microsoft Visual C++",
 *             development tool chain 
 *             "Microsoft Visual Studio Express 2013 for Windows Desktop"
 *  @date      2015-01-01
 *  @copyright Apache License, Version 2.0
 *
 *  nqueensh.h - Header-Datei fuer 
 *               das 8x8 Damen Problem - Suche nach *allen* Loesungen
 *  
 *  Der define-Parameter SIZE_BOARD 
 *  bestimmt die Groesse des Schachbretts
 *
 *  Copyright 1989-2015 Rolf Hemmerling
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 *  either express or implied.
 *  See the License for the specific language governing permissions
 *  and limitations under the License.
 *
 *  Haupt-Entwicklungszeiten:
 *    1999-03 - 1999-06-08, 1999-06-14
 *    2004-07-13 ( Umstellung auf C++ )
 */
 
#include <stdio.h>

/**
 *  @def      FALSE
 *  @brief    FALSE
 */
#define FALSE 0
/**
 *  @def      TRUE
 *  @brief    TRUE
 */
#define TRUE !0


/**
 *  @def      SIZE_BOARD
 *  @brief    Groesse des Schachbretts =
 *            SIZE_BOARD x SIZE_BOARD
 */
#define SIZE_BOARD 8   
   
/**
 *  @fn       MP_try(int VV_zeile)
 *  @param    VV_zeile	aktuell bearbeitete Zeile
 *	@brief    Loesung rekursiv finden
 */
void MP_try(int VV_zeile);

/**
 *  @fn       MP_init
 *	@brief    Initialisierung
 */
void MP_init(void);

/**
 *  @fn       MP_nqueens
 *	@brief    Ablaufplan
 */
void MP_nqueens(void);

/**
 *  @fn       MP_print
 *	@brief    Ausgabe der Ergebnisse
 */
void MP_print(void);

/**
 *  @fn       MP_check (int VV_zeile, int VV_spalte, int *IV_spalte, 
 *                      int *IV_li_diag, int *IV_re_diag); 
 *  @param    VV_zeile
 *  @param    VV_spalte    
 *  @param    IV_spalte
 *  @param    IV_li_diag
 *  @param    IV_re_diag  
 *  @return   int
 *	@brief    Check, ob Schachbrett-Position "sicher" ist
 */
int MP_check (int VV_zeile, int VV_spalte, int *IV_spalte, 
              int *IV_li_diag, int *IV_re_diag);

/**
 *  @fn       main
 *  @return   int
 *	@brief    Main program
 */
int main();

/**
 *  @def      SIZE_SPALTE
 *  @brief    Spaltengroesse des 
 *            Felds zur Aufnahme der Information, 
 *            ob j-te Zeile frei ist
 *            int MV_spalte[];
 */
#define SIZE_SPALTE SIZE_BOARD
/**
 *  @def      OFFSET_SPALTE
 *  @brief    Offset im Feld zur Aufnahme der Information, 
 *            ob j-te Zeile frei ist
 *            int MV_spalte[];
 */
#define OFFSET_SPALTE 1

/**
 *  @def      SIZE_LI_DIAG
 *  @brief    Groesse des 
 *            Felds zur Aufnahme der Information, ob 
 *            k-te /-Diagonale ist frei 
 *            MV_li_diag[];
 */
#define SIZE_LI_DIAG (2*SIZE_BOARD-1)
/**
 *  @def      OFFSET_LI_DIAG
 *  @brief    Offset im Feld zur Aufnahme der Information, ob 
 *            k-te /-Diagonale ist frei 
 *            MV_li_diag[];
 */
#define OFFSET_LI_DIAG 2

/**
 *  @def      SIZE_RE_DIAG
 *  @brief    Groesse des 
 *            Felds zur Aufnahme der Information, ob
 *            k-te \-Diagonale frei ist
 *            MV_re_diag[];
 */
#define SIZE_RE_DIAG (2*SIZE_BOARD-1)
/**
 *  @def      OFFSET_RE_DIAG
 *  @brief    Offset im Feld zur Aufnahme der Information, ob
 *            k-te \-Diagonale frei ist
 *            MV_re_diag[];
 */
#define OFFSET_RE_DIAG -(SIZE_BOARD-1)

/**
 *  @def      SIZE_SCHACHBRETT
 *  @brief    Groesse des 
 *            Felds zur Aufnahme der Position der Dame
 *            MV_schachbrett[SIZE_SCHACHBRETT]
 *                          [SIZE_SCHACHBRETT];
 */
#define SIZE_SCHACHBRETT SIZE_BOARD
/**
 *  @def      OFFSET_SCHACHBRETT
 *  @brief    Offset im Feld zur Aufnahme der Position der Dame
 *            MV_schachbrett[SIZE_SCHACHBRETT]
 *                          [SIZE_SCHACHBRETT];
 */
#define OFFSET_SCHACHBRETT 1

#endif

