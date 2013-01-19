/*************************************************************************
                           CLine  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Realisation de la classe <CLine> (fichier CLine.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme

#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CLine.h"
#include "CPolyLine.h"
#include "CFigure.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type CLine::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


string CLine::GetCreator()
// Algorithme :
//
{
	string cmd;
	cmd += "L ";
	int xN;
	int yN;
	VectPoint::iterator itPoint = vPoint->begin();
	for( ; itPoint != vPoint->end() ; itPoint++)
	{
		(*itPoint)->GetXY(xN, yN);
		cmd += xN;
		cmd += " ";
		cmd += yN;
		cmd += " ";
	}
	cmd.replace(cmd.length()-1, 1, "");
	return cmd;
}


//------------------------------------------------- Surcharge d'operateurs
/*CLine & CLine::operator = (const CLine & unCLine)
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
/*CLine::CLine (const CLine & unCLine)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CLine>" << endl;
#endif
} //----- Fin de CLine (constructeur de copie)*/


/*CLine::CLine()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CLine>" << endl;
#endif
} //----- Fin de CLine*/


CLine::~CLine ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CLine>" << endl;
#endif
} //----- Fin de ~CLine


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

