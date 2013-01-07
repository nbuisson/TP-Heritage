/*************************************************************************
                           CSchema  -  description
                             -------------------
    d�but                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- R�alisation de la classe <CSchema> (fichier CSchema.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CSchema.h"
//#include "CFigure.h"
#include "CHistoric.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type CSchema::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void CSchema::Execute()
// Algorithme :
// Execution de la fonction tant que la commande n'est pas EXIT
// Appel de la commande
{
    bool bFinished=false;
    string cmd;

    while (!bFinished)
    {
        cin>>cmd;
        if (cmd=="EXIT")
        {
            bFinished=true;
        }
        else
        {
            if (!ReadInstruction(cmd))
            {
                AnalyzeError(cmd);
            }
        }
    }
} //----- Fin de execute

bool CSchema::ReadInstruction (string aInst)
{

	// Découpage de l'appel dans une varialbe à part
	size_t nextSpace = aInst.find(" ");
	if (nextSpace == 0)
	{
		nextSpace=aInst.length();
	}

	string cmdCall = aInst.substr(0, nextSpace);

	if(cmdCall=="C")
    {

    }
	else if(cmdCall=="R")
    {

    }
    else if(cmdCall=="L")
    {
    }
	else if(cmdCall=="PL")
    {
    }
    else if(cmdCall=="S")
    {
    }
    else if(cmdCall=="DELETE")
    {
    }
    else if(cmdCall=="MOVE")
    {
    }
    else if(cmdCall=="LIST")
    {
    }
    else if(cmdCall=="UNDO")
    {
    }
    else if(cmdCall=="REDO")
    {
    }
    else if(cmdCall=="LOAD")
    {
    }
    else if(cmdCall=="SAVE")
    {
    }
    else if(cmdCall=="CLEAR")
    {
    }
    else if(cmdCall=="COUNT")
    {
    }
    else
    {
    }
	return false;
}

bool CSchema::VerifySyntax (string aCmd, int aNbInt=0, bool fileCmd=false)
{
	if (fileCmd)
	{
		// Vérification du format du fichier

	}
}

void CSchema::ShowList ()
// Algorithme :
// Afficher la liste des elts
{
	/*
    vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
        it->GetCreator();
        it++;
    }*/
}

void CSchema::AnalyzeError (string aInst)
{

}


//-------------------------------------------- Constructeurs - destructeur
CSchema::CSchema ( )
// Algorithme :
// Trivial
{
   // vFigure = new vectFigure;
    historic = new CHistoric;

    Execute();
} //----- Fin de CSchema


CSchema::~CSchema ( )
// Algorithme :
// Trvial
{
    // Supression des elts de l'historic proprement
    delete historic;

    // Supression des figure
    //delete vFigure;

} //----- Fin de ~CSchema


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

