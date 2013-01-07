/*************************************************************************
                           CHistoric  -  description
                             -------------------
    d�but                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- R�alisation de la classe <CHistoric> (fichier CHistoric.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CHistoric.h"
#include <vector>
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CHistoric::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//-------------------------------------------- Constructeurs - destructeur


CHistoric::CHistoric ( )
// Algorithme :
// Trivial
{

#ifdef MAP
    cout << "Appel au constructeur de <CHistoric>" << endl;
#endif

    vStack = new vectStack;

    // Postion sur le début de l'itérateur
    it = vStack->begin();

} //----- Fin de CHistoric


CHistoric::~CHistoric ( )
// Algorithme :
// Trivial
{
	it=vStack->begin();

	while (it!=vStack->end())
	{
		//*it.delete(); // TODO : vérifier syntaxe destruction
		it++;
	}

#ifdef MAP
    cout << "Destruction des commandes de l'historique" << endl;
#endif
} //----- Fin de ~CHistoric


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

