/*************************************************************************
                           CSchema  -  description
                             -------------------
    d�but                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Interface de la classe <CSchema> (fichier CSchema.h) ------
#if ! defined ( CSCHEMA_H_ )
#define CSCHEMA_H_

//--------------------------------------------------- Interfaces utilisees
//#include "CFigure.h"
#include "CHistoric.h"
#include "CFigure.h"
#include <vector>
using namespace std;

//------------------------------------------------------------- Constantes
#define NB_CMD 15
//------------------------------------------------------------------ Types
typedef vector <CFigure*> vectFigure;

//------------------------------------------------------------------------
// Rele de la classe <CSchema>
//
//
//------------------------------------------------------------------------

class CSchema
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void Execute();
    // Mode d'emploi :
    // Execution du programme
    // Contrat :
    // Rien

    bool ReadInstruction (string aInst);
    // Mode d'emploi :
    // Lecture de l'instruction
    // Paramètres de l'instruction passé en par aInst
    // Contrat :
    // Instruction différente de EXIT

	bool VerifySyntax (vector<string> aCmd, int aNbInt, bool fileCmd);
	// Mode d'emploi :
	// Vérification de la syntaxe de la commande (nombre d'arg. valide / validité des arguments)
	// Contrat :
	// Rien

    void ShowList ();
    // Mode d'emploi :
    // Lister les descripteurs des objets
    // Contrat :
    // Rien

//-------------------------------------------- Constructeurs - destructeur
    CSchema ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CSchema ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

    bool Circle(vector<string> aInst);
    bool Rectangle(vector<string> aInst);
    bool Poly(vector<string> aInst,bool line);
    void Select(aVectInst);
    void Clear(bool all);
    int VectStringToInt (string aString);
    void Count();
    void Close();

//----------------------------------------------------- Attributs prot�g�s
    CHistoric* historic;
    vectFigure* vFigure;
    vector<string>* possibleCmd;
    bool bFinished;

};

//--------------------------- Autres d�finitions d�pendantes de <CSchema>

#endif // CSCHEMA_H_

