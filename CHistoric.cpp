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
#include <sstream>
#include <fstream>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CHistoric.h"
#include <vector>
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void CHistoric::AddHistoric (string aInst)
// Algorithme :
// Recherche si la commande est une commande qui modifie l'état des elts
// Ajout simple si la commande est une commande dite simple
// Si la commande est complexe, il faut réaliser la lecture du fichier
// dans le but d'enregister les commandes
{
    stringstream buf (aInst);
    string frontChar;
    buf >> frontChar;

    if (frontChar=="C" || frontChar=="R" || frontChar=="L" || frontChar=="PL" || frontChar=="CLEAR" || frontChar=="MOVE" || frontChar=="DELETE")
    {
        vectCommande * currentCmd = new vectCommande;
        currentCmd->push_back(aInst);

        vStack->push_back(currentCmd);
    }

    else if( frontChar == "LOAD" )
    {
        string fileName;
        buf>>fileName;

        ifstream myFile (fileName.c_str());
        if(myFile.is_open())
        {
            vectCommande * currentCmd = new vectCommande;
            string buf;
            while(myFile.good())
            {
                getline(myFile,buf);
                currentCmd->push_back(aInst);
            }
            vStack->push_back(currentCmd);
            myFile.close();
        }
    }

    if (vStack->size()>20)
    {
        vStack->erase(vStack->begin());
    }
}

bool CHistoric::Undo ()
{
    if(vStack->empty())
    {
        cout<<"# No instruction to undo"<<endl;
        return false;
    }
    else
    {

    }
}

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
		it=vStack->erase(it);
	}

#ifdef MAP
    cout << "Destruction des commandes de l'historique" << endl;
#endif
} //----- Fin de ~CHistoric


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

