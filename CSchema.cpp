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
#include <limits>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//------------------------------------------------------ Include personnel
#include "CSchema.h"
#include "CFigure.h"
#include "CCircle.h"
#include "CHistoric.h"


//------------------------------------------------------------- Constantes
const int maxInt = numeric_limits<int>::max();
const int minInt = numeric_limits<int>::min();

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void CSchema::Execute()
// Algorithme :
// Execution de la fonction tant que la commande n'est pas EXIT
// Appel de la commande
{
    while (!bFinished)
    {
		string cmd="";
		getline(cin,cmd);
        if(!ReadInstruction(cmd))
        {
            cout<<"ERR "<<cmd<<endl;
        }
        else
        {
            cout<<"OK "<<cmd<<endl;
        }
    }
} //----- Fin de execute

bool CSchema::ReadInstruction (string aInst)
{
    vector<string> aVectInst;

    if(aInst.empty())
    {
        cout<<"#No instruction to do !"<<endl;
        return false;
    }

    else
    {
        //Cmd splitting
        stringstream tempString (aInst);
        string buffer;
        while (tempString>>buffer)
        {
            aVectInst.push_back(buffer);
        }

        int cmdChoise=-1;
        for(int i = 0; i<NB_CMD && cmdChoise==-1; i++)
        {
            if ((aVectInst.front())==(possibleCmd->at(i)))
            {
                cmdChoise=i;
            }
        }

        switch (cmdChoise)
        {
            case 0:
			  	return Circle(aVectInst);
				break;
			case 1:
				//return Rectangle(aVectInst);
				break;
			case 2:
				//return Line(aVectInst);
				break;
			case 3:
				//return PolyLine(aVectInst);
				break;
			case 4:
				//return Select(aVectInst);
				break;
			case 5:
				Clear(false);
				return true;
				break;
			case 6:
				//return Move(aVectInst);
				break;
			case 7:
				ShowList();
				return true;
				break;
			case 8:
				//return Undo();
				break;
			case 9:
				//return Redo();
				break;
			case 10:
				//return Load(aVectInst);
				break;
			case 11:
				//return Save(aVectInst);
				break;
			case 12:
				Clear(true);
				return true;
				break;
			case 13:
				Count();
				return true;
				break;
			case 14:
				Close();
				break;
			default:
				cout << "# Unknown instruction" << endl;
				return false;
				break;
        }
        return false;
    }

}


// TODO : Rechercher la manière de ne pas prendre en compte le point

bool CSchema::VerifySyntax (vector<string> aCmd, int aNbInt, bool fileCmd=false)
// Algo : Décomposition de la commande dans les différentes sous commandes
// Vérification du l'extension du fichier est bien du texte
// Vérification que chaque parametre est bien castable en intéger
{
    //Vérif du Nb de paramètres
    if (aCmd.size()!= aNbInt+1 && aNbInt!=-1)
    {
        return false;
    }

    //Vérifier que la présence d'une extension txt
	if (fileCmd)
	{
		if ((aCmd[1]).find(".txt")==-1)
		{
			return false;
		}
	}

	// Vérification que tous les arguments sont des nombres
	if (aNbInt!=0 && fileCmd==false)
	{
		for (int i=1 ; i<aCmd.size(); i++)
		{
            int aIntParameter;
            istringstream buffer (aCmd[i]);
            if (!(buffer>>aIntParameter))
            {
                return false;
            }
		}

	}

	return true;
}

bool CSchema::Circle(vector<string> aInst)
{
    if (!VerifySyntax(aInst,3, false))
    {
        cout<<"#Wrong parameter(s)"<<endl;
        return false;
    }

    int x = VectStringToInt(aInst[1]);
    int y = VectStringToInt(aInst [2]);
    int radius = VectStringToInt(aInst [3]);

	double xMax = (double)x+(double)radius;
	double xMin = (double)x-(double)radius;
	double yMax = (double)y+(double)radius;
	double yMin = (double)y-(double)radius;

	// Gestion du fait que le rayon est en dehors du cadre de travail
	if (xMax>maxInt || xMin<minInt || yMax>maxInt || yMin<minInt)
	{
		cout<<"#Wrong parameter(s)"<<endl;
		return false;
	}
	else
	{
	    CCircle * aCircle = new CCircle (x,y,radius);
		vFigure->push_back(aCircle);
		return true;
	}
	return true;
}

void CSchema::ShowList ()
// Algorithme :
// Afficher la liste des elts
{
    vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
        cout<<(*it)->GetCreator()<<endl;
        it++;
    }
}

int CSchema::VectStringToInt (string aString)
{
    stringstream aStreamString (aString);
    int aInt;
    aStreamString>>aInt;
    return aInt;
}

void CSchema::Clear(bool all)
// Algorithme :
// Parcourt de la liste et effacer toute les figure ou celles selectionnées
{
	vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
		if ((*it)->isSelected)
		{
			it = vFigure->erase(it);
		}
		else if (all)
		{
			it = vFigure->erase(it);
		}
    }

}

void CSchema::Count()
// Algo : trivial
{
    cout<<vFigure->size()<<endl;
}

void CSchema::Close ()
{
    Clear(true);
    exit(0);
}

//-------------------------------------------- Constructeurs - destructeur
CSchema::CSchema ( )
// Algorithme :
// Trivial
{
    vFigure = new vectFigure;
    historic = new CHistoric;

    std::string strArr[] = {"C","R","L","PL","S","DELETE","MOVE","LIST","UNDO","REDO", "LOAD", "SAVE", "CLEAR", "COUNT", "EXIT"};
    possibleCmd = new std::vector<std::string>(strArr, strArr + NB_CMD);

    bFinished=false;

    Execute();
} //----- Fin de CSchema


CSchema::~CSchema ( )
// Algorithme :
// Trvial
{
    // Supression des elts de l'historic proprement
    delete historic;

    // Supression des figure
    delete vFigure;

} //----- Fin de ~CSchema


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

