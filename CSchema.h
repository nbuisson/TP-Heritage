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
// La classe CSchema permet l'interaction avec l'utilisateur dans
// l'application. Elle demande les instruction gêre les elts geo et délègue
// la responsabilité de l'historique à la classe CHistorique
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

    bool OppositeInst(string aInst);
    // Mode d'emploi :
    // Lecture de l'instruction et réalisation de l'instruction inverse
    // Paramètres de l'instruction passé en par aInst
    // Contrat :
    // Commende passée en paramêtre valide car déjà utilisée une fois

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
    // Mode d'emploi :
    // Création d'un cercle, en passent l'instruction courante en paramêtre
    // Renvoie la validité de la création du cercle
    // Contrat :
    // Rien

    bool Rectangle(vector<string> aInst);
    // Mode d'emploi :
    // Création d'un Rectangle, en passent l'instruction courante en paramêtre
    // Renvoie la validité de la création du rectangle
    // Contrat :
    // Rien

    bool Poly(vector<string> aInst,bool line);
    // Mode d'emploi :
    // Création d'un (poly)ligne, en passent l'instruction courante en paramêtre
    // ainqi que le type d'elt géometrique on souhaite créer
    // Renvoie la validité de la création de la (poly)ligne
    // Contrat :
    // Rien

    bool Select(vector<string> aInst);
    // Mode d'emploi :
    // Selection des elts présent dans le rectangle définis par ses 2 sommets opposés
    // passé en paramêtre
    // Contrat :
    // Rien

    bool Load(vector<string> aInst);
    // Mode d'emploi :
    // Création d'un (poly)ligne, en passent l'instruction courante en paramêtre
    // ainqi que le type d'elt géometrique on souhaite créer
    // Renvoie la validité de la création du cercle
    // Contrat :
    // Rien

    bool Save(vector<string> aInst);
    // Mode d'emploi :
    // Sauvegarder les elts présents dans un fichier txt dont le nom est
    // passé en paramêtre. Renvoi si l'écriture à bien était réalisée
    // Contrat :
    // Rien

    bool Move(vector<string> aInst);
    // Mode d'emploi :
    // Déplacement des tous les elts géo selectionés d'un dx et dy passé par paramêtre
    // Renvoi la validité du déplament
    // Contrat :
    // Rien

    bool OppositeMove(vector<string> aInst);

    void UnSelectAll ();
    // Mode d'emploi :
    // Déselectionner la selection actuelle
    // Contrat :
    // Rien

    void Clear(bool all);
    // Mode d'emploi :
    // Suppression des elt selectionné si le flag all est faux
    // Dans le cas échéant suppression de tous les elts
    // Contrat :
    // Rien

    int VectStringToInt (string aString);
    // Mode d'emploi :
    // Conversion d'une string passé par paramêtre en entier
    // Renvoi l'entier convertis
    // Contrat :
    // Rien

    void Count();
    // Mode d'emploi :
    // Affichage du nombre d'elt instancié
    // Contrat :
    // Rien

    void Close();
    // Mode d'emploi :
    // Fermeture du programme
    // Contrat :
    // Rien

//----------------------------------------------------- Attributs prot�g�s
    CHistoric* historic;
    vectFigure* vFigure;
    vector<string>* possibleCmd;
    bool bFinished;

};

//--------------------------- Autres d�finitions d�pendantes de <CSchema>

#endif // CSCHEMA_H_

