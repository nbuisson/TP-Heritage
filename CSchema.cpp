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
    bool bFinished=false;

    while (!bFinished)
    {
		string cmd="";
		getline(cin,cmd);
        if (cmd=="EXIT")
        {
            bFinished=true;
        }
        else
        {
            if (!ReadInstruction(cmd))
            {
				cout<<"ERR "<<cmd<<endl;
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
		if (!VerifySyntax(aInst,3, false))
		{
			return false;
		}

		//CreateCircle(aInst);

    }
	else if(cmdCall=="R")
    {
		if (!VerifySyntax(aInst,4, false))
		{
			return false;
		}


    }
    else if(cmdCall=="L")
    {
		if (!VerifySyntax(aInst,4, false))
		{
			return false;
		}

    }
	else if(cmdCall=="PL")
    {
		if (!VerifySyntax(aInst,-1, false))
		{
			return false;
		}
		//TODO : creation de vecteru de points
    }
    else if(cmdCall=="S")
    {
		if (!VerifySyntax(aInst,4, false))
		{
			return false;
		}
    }
    else if(cmdCall=="DELETE")
    {
		//Clear(false);
    }
    else if(cmdCall=="MOVE")
    {
		if (!VerifySyntax(aInst,2, false))
		{
			return false;
		}
    }
    else if(cmdCall=="LIST")
    {
		ShowList();
    }
    else if(cmdCall=="UNDO")
    {
		//TODO
    }
    else if(cmdCall=="REDO")
    {
		//TODO
    }
    else if(cmdCall=="LOAD")
    {
		if (!VerifySyntax(aInst,0, true))
		{
			return false;
		}
		//TODO
    }
    else if(cmdCall=="SAVE")
    {
		if (!VerifySyntax(aInst,0, true))
		{
			return false;
		}
		//TODO
    }
    else if(cmdCall=="CLEAR")
    {
		//Clear(true);
    }
    else if(cmdCall=="COUNT")
    {

    }
    else
    {
		cout<<"#Invalid cmd"<<endl;
		return false;
    }

}


// TODO : Rechercher la manière de ne pas prendre en compte le point

bool CSchema::VerifySyntax (string aCmd, int aNbInt, bool fileCmd=false)
// Algo : Décomposition de la commande dans les différentes sous commandes
// Vérification du l'extension du fichier est bien du texte
// Vérification que chaque parametre est bien castable en intéger
{
	//Vérifier que la présence d'une extension txt
	if (fileCmd)
	{
		if (aCmd.find(".txt")==-1)
		{
			return false;
		}
	}

	// Vérifier le nombre d'argument
	if (aNbInt!=0 && fileCmd==false)
	{
		// supression de la premiere partie de la commande
		size_t nextSpace = aCmd.find(" ");
		aCmd.erase(0,nextSpace+1);
		int nbRealParameter =0;

		while (aCmd.length()!=0)
		{
			// Extraction du parametre en cours
			string aParameter;
			nextSpace = aCmd.find(" ");
			if (nextSpace!=-1)
			{
				aParameter = aCmd.substr(0,nextSpace+1);
			}
			else
			{
				aParameter = aCmd;
				nextSpace=aCmd.length();
			}
			nbRealParameter++;

			// Vérifier que le paramètre peut être casté en int
			int aIntParameter;
			istringstream buffer (aParameter);
			if (!(buffer>>aIntParameter))
			{
				return false;
			}

			//Supression de l'argument analysé
			aCmd.erase(0,nextSpace+1);
		}

		// Gestion du mauvais nombre de paramêtre
		if (nbRealParameter!=aNbInt && aNbInt!= -1)
		{
			return false;
		}

	}

	return true;
}


void CSchema::AnalyzeError (string aInst)
{

}

/*bool CSchema::CreateCircle(string aInst)
{
	// Création des variable
	istringstream inst (aInst);
	string commande;
	int x;
	int y;
	int radius;

	// Découpage de l'instruction
	inst >> commande >> x >> y >> radius;

	double xMax = (double)x+(double)radius;
	double xMin = (double)x-(double)radius;
	double yMax = (double)y+(double)radius;
	double yMin = (double)y-(double)radius;

	// Gestion du fait que le rayon est en dehors du cadre de travail
	if (xMax>maxInt || xMin<minInt || yMax>maxInt || yMin<minInt)
	{
    CCercle * aCercle = new Ccercle (x,y,radius);
		vectFigure.pushback (CCercle);
		return true;
	}
	else
	{
		return false;
	}
}*/

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

/*void CSchema::Clear(bool all)
// Algorithme :
// Parcourt de la liste et effacer toute les figure ou celles selectionnées
{
	/*vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
		CFigure * actualFigure;
        actualFigure = it;

        it++;
		if (actualFigure->isSelected)
		{
			delete actualFigure;
		}
		else if (all)
		{
			delete actualFigure;
		}
    }

}*/

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

