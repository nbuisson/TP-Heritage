/*************************************************************************
                           CCircle  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Realisation de la classe <CCircle> (fichier CCircle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CCircle.h"
#include "CFigure.h"
#include "CPoint.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type CCircle::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode

bool CCircle::Move(int dX, int dY)
// Algorithme :
//
{
    int maxLim = numeric_limits<int>::max();
    int minLim = numeric_limits<int>::min();

    bool tempIsSelected = isSelected;   // Stockage de la valeur actuelle de isSelected

    bool ok = center.Move(dX, dY);

    // On vérifie si le cercle déplacé est compris dans le rectangle de l'aire de dessin
    // via la fonction isSelected
    Select(minLim, minLim, maxLim, maxLim);

    //TODO : enlever la trace
    cout << "isSelected : " << isSelected << " ; ok : " << ok << endl;
    int tempX; int tempY; center.GetXY(tempX, tempY);
    cout << "x : " << tempX << " ; y : " << tempY << endl;

    if (isSelected && ok)
    {
        // Si le cercle est dans les limites, on rétablie isSelected à sa valeur d'origne
        // et on renvoie "true"
        isSelected = tempIsSelected;
        return true;
    }
    else if ((not isSelected) && ok)
    {
        // Si le déplacement du centre est bon mais que le cercle n'est plus compris dans
        // la zone de dessin, on annule le déplacement
        center.Move(-dX, -dY);
    }

    // Remise de isSelected à sa valeur initiale et renvoie de "false" si déplacement impossible
    isSelected = tempIsSelected;
    return false;
} //----- Fin de Methode


void CCircle::Select(int x1, int y1, int x2, int y2)
// Algorithme :
//
{
	if(center.IsSelected(x1, y1, x2, y2))
	{
		// Rectangle rX1, rY1; rX2, rY2 (défini par le coin supérieur gauche et inférieur droit)
		// contenant le cercle
		double rX1;
		double rX2;
		double rY1;
		double rY2;
		center.Distance(-rayon, rayon, rX1, rY1);
		center.Distance(rayon, -rayon, rX2, rY2);

		// Min et max entre x1, x2 et y1, y2
		int xmin = min(x1,x2);
		int xmax = max(x1,x2);
		int ymin = min(y1,y2);
		int ymax = max(y1,y2);

		// Si les deux points du rectangle contenant le cercle sont dans
		// le rectangle défini par xmin, xmax, ymin, ymax -> ok
		if ((xmin<=rX1 && xmax>=rX1 && ymin<=rY1 && ymax>=rY1) && (xmin<=rX2 && xmax>=rX2 && ymin<=rY2 && ymax>=rY2))
		{
			isSelected = true;
		}
		else
		{
			isSelected = false;
		}
	}
} //----- Fin de Methode


string CCircle::GetCreator()
{
    string cmd;

	int centerX;
	int centerY;
	center.GetXY(centerX, centerY);

	stringstream intToStr;
	intToStr << centerX << " " << centerY << " " << rayon << endl;

	cmd += "C ";
	cmd += intToStr.str();

	return cmd;
}


//------------------------------------------------- Surcharge d'operateurs
/*CCircle & CCircle::operator = ( const CCircle & unCCircle )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
CCircle::CCircle ( const CCircle & unCCircle ) : center(unCCircle.center)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CCircle>" << endl;
#endif
    rayon = unCCircle.rayon;
} //----- Fin de CCircle (constructeur de copie)


/*CCircle::CCircle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CCircle>" << endl;
#endif
} //----- Fin de CCircle*/


CCircle::~CCircle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CCircle>" << endl;
#endif
} //----- Fin de ~CCircle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

