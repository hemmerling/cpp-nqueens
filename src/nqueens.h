#ifndef NQUEENS_H
#define NQUEENS_H
#include "nqueensh.h"
/**
 *  @package   nqueens
 *  @file      nqueens.h
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
 *  nqueens.h - Header-Datei fuer 
 *              das 8x8 Damen Problem - Suche nach *allen* Loesungen
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

/**
 *  @class    NQueens
 *	@brief    NQueens
 */
class NQueens
{

  protected:

  /**
   *  @var      MV_spalte 
   *  @brief    Feld zur Aufnahme der Information, 
   *            ob j-te Zeile frei ist
   */
  int MV_spalte[SIZE_SPALTE];

  /**
   *  @var      MV_li_diag
   *  @brief    Feld zur Aufnahme der Information, 
   *            ob k-te /-Diagonale frei ist
   */
  int MV_li_diag[SIZE_LI_DIAG];

  /**
   *  @var      MV_re_diag
   *  @brief    Feld zur Aufnahme der Information, 
   *            ob k-te \-Diagonale frei ist
   */

  int MV_re_diag[SIZE_RE_DIAG];
  /**
   *  @var      MV_schachbrett
   *  @brief    Feld zur Aufnahme der Position der Dame 
   */
  int  MV_schachbrett[SIZE_SCHACHBRETT]
                     [SIZE_SCHACHBRETT];

  public:

  /**
   *  @fn       MP_nqueens
   *  @brief    Hauptprogramm: Feld-Initialisierung, 
   *            Aufruf der Suchfunktion
   */
  void MP_nqueens(void);

  protected:

  /**
   *  @fn       MP_try (int VV_zeile)
   *  @param    VV_zeile aktuell bearbeitete Zeile
   *  @brief    Eigentliche Suchfunktion fuer das N-Damen-Problem,
   *            ruft sich rekursiv auf
   *            Liste benutzter Variablen:
   *            MV_spalte, MV_li_diag, MV_re_diag, MV_schachbrett
   */
  void MP_try (int VV_zeile);

  /**
   *  @fn       MP_print
   *  @brief    Ausdruck *einer* Loesung, d.h. 
   *            einem Schachbrett mit korrekt gesetzten Damen
   *            Liste benutzter Variablen:
   *            MV_spalte, MV_li_diag, MV_re_diag, MV_schachbrett
   */
  void MP_print(void);

  /**
   *  @fn       MP_init
   *  @brief    Initialisierung aller Felder
   *            Liste benutzter Variablen:
   *            MV_spalte, MV_li_diag, MV_re_diag, MV_schachbrett
   *      
   */
  void MP_init(void);
   
  /**
   *  @fn       MP_check
   *  @param    VV_zeile  Zeile 
   *                      zu ueberpruefende Schachbrettposition ( Zeilenindex )
   *  @param    VV_spalte Spalte
   *                      zu ueberpruefende Schachbrettposition ( Spaltenindex )
   *  @param    IV_spalte Feld mit belegten/freien Spalten)
   *                      Feld mit Informationen, ob Spalte schon belegt ist
   *  @param    IV_li_diag Feld mit belegten/freien linken Diagonalen
   *                       Feld mit Informationen, ob linke Diagonale schon belegt ist
   *  @param    IV_re_diag Feld mit belegten/freien rechten Diagonalen
   *                       Feld mit Informationen, ob rechte Diagonale schon belegt ist
   *  @return   TRUE = Position ist "sicher", FALSE = Position ist "nicht sicher"
   *  @brief    Stellt fest, ob eine Position fuer eine Dame "sicher" ist
   */
  int MP_check(int VV_zeile,
               int VV_spalte, 
               int *IV_spalte, 
               int *IV_li_diag, 
               int *IV_re_diag);

};
#endif

