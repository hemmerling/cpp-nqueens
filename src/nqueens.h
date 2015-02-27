#include "nqueensh.h"

/**
  *  Das 8x8 Damen Problem.
  *  Suche nach *allen* Loesungen
  *  Algorithmus: Cooper, Clancy (S.318)
  *  Made with EasyCASE V6.5 1999-06-14 18:43:31
  *  @Date: 1999-06-08, 2004-07-13 ( Umstellung auf C++ )
  *  @author Rolf Hemmerling
  *  @version 1.00
  *  @Parameter: #-Konstante SIZE_BOARD, bestimmt die Groesse des Schachbretts
  */
class NQueens
{

  protected:

  /**
    *  Feld zur Aufnahme der Information, ob j-te Zeile frei ist
    */
  int MV_spalte[SIZE_SPALTE];

  /**
    *  Feld zur Aufnahme der Information, ob k-te /-Diagonale frei ist
    */
  int MV_li_diag[SIZE_LI_DIAG];

  /**
    *  Feld zur Aufnahme der Information, ob k-te \-Diagonale frei ist
    */
  int MV_re_diag[SIZE_RE_DIAG];

  /**
    *  Feld zur Aufnahme der Position der Dame 
    */
  int  MV_schachbrett[SIZE_SCHACHBRETT]
                     [SIZE_SCHACHBRETT];

  public:

  /**
    *  Hauptprogramm: Feld-Initialisierung, Aufruf der Suchfunktion
    *  @Date: 1999-06-08
    *  @Author: Rolf Hemmerling
    *  @version 1.00
    */
  void MP_nqueens(void);

  protected:

  /**
    *  Eigentliche Suchfunktion fuer das N-Damen-Problem,
    *  ruft sich rekursiv auf
    *  Liste benutzter Variablen:
    *  MV_spalte, MV_li_diag, MV_re_diag, MV_schachbrett
    *  @Date: 1999-06-08
    *  @Author: Rolf Hemmerling
    *  @version 1.00
    *  @param VV_zeile aktuell bearbeitete Zeile
    */
  void MP_try (int VV_zeile /* aktuell bearbeitete Zeile */ );

  /**
    *  Ausdruck *einer* Loesung, d.h. einem Schachbrett mit korrekt gesetzten Damen
    *  Liste benutzter Variablen:
    *  MV_spalte, MV_li_diag, MV_re_diag, MV_schachbrett
    *  @Date: 1999-06-08
    *  @Author: Rolf Hemmerling
    *  @version 1.00
    */
  void MP_print(void);

  /**
    *  Initialisierung aller Felder
    *  Liste benutzter Variablen:
    *  MV_spalte, MV_li_diag, MV_re_diag, MV_schachbrett
    *  @Date: 1999-06-08
    *  @Author: Rolf Hemmerling
    *  @version 1.00
    */
  void MP_init(void);
   
  /**
    *  Stellt fest, ob eine Position fuer eine Dame "sicher" ist
    *  @Date: 1999-06-08
    *  @Author: Rolf Hemmerling
    *  @version 1.01 (korregierter Algorithmus)
    *  @param VV_zeile zu ueberpruefende Schachbrettposition ( Zeilenindex )
    *  @param VV_spalte zu ueberpruefende Schachbrettposition ( Spaltenindex )
    *  @param IV_spalte Feld mit Informationen, ob Spalte schon belegt ist
    *  @param IV_li_diag Feld mit Informationen, ob linke Diagonale schon belegt ist
    *  @param IV_re_diag Feld mit Informationen, ob rechte Diagonale schon belegt ist
    *  @return TRUE = Position ist "sicher", FALSE = Position ist "nicht sicher"
    */
  int MP_check(int VV_zeile
               /* Zeile */,
               int VV_spalte 
               /* Spalte */, 
               int *IV_spalte 
               /* Feld mit belegten/freien Spalten) */, 
               int *IV_li_diag 
               /* Feld mit belegten/freien linken Diagonalen */,
               int *IV_re_diag 
               /* Feld mit belegten/freien rechten Diagonalen */);

};
