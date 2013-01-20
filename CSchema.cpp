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
#include <fstream>


using namespace std;

//------------------------------------------------------ Include personnel
#include "CSchema.h"
#include "CFigure.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CPolyLine.h"
#include "CPoint.h"
#include "CLine.h"
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
            historic->AddHistoric(cmd);
        }
    }
} //----- Fin de execute

bool CSchema::ReadInstruction (string aInst)
// Algorithme :
// Vérification de la validité de la commande en comparant les
// instructions éxistances avec l'instruction en cours, puis appel
// de la fonction adéquate
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
				return Rectangle(aVectInst);
				break;
			case 2:
				return Poly(aVectInst,true);
				break;
			case 3:
				return Poly(aVectInst,false);
				break;
			case 4:
				return Select(aVectInst);
				break;
			case 5:
				Clear(false);
				return true;
				break;
			case 6:
				return Move(aVectInst);
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
				return Load(aVectInst);
				break;
			case 11:
				return Save(aVectInst);
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
            else if (aIntParameter>maxInt || aIntParameter<minInt)
            {
                return false;
            }
		}

	}

	return true;
}

bool CSchema::Circle(vector<string> aInst)
// Algo : Création d'un cercle
// Vérification de la validité des paramètre (nb de paramètres, castable en entier,
// pas de dépassement mémoire), puis l'ajouter dans la liste
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
}

bool CSchema::Rectangle(vector<string> aInst)
// Algo : Création d'un Rectangle
// Vérification de la validité des paramètre (nb de paramètres, castable en entier,
// pas de dépassement mémoire), puis l'ajouter dans la liste
{
    if (!VerifySyntax(aInst,4, false))
    {
        cout<<"#Wrong parameter(s)"<<endl;
        return false;
    }

    int x1 = VectStringToInt(aInst[1]);
    int y1 = VectStringToInt(aInst [2]);
    int x2 = VectStringToInt(aInst [3]);
    int y2 = VectStringToInt(aInst [4]);

    CRectangle * aRectangle = new CRectangle (x1,y1,x2,y2);
    vFigure->push_back(aRectangle);
    return true;
}

bool CSchema::Poly(vector<string> aInst,bool line)
// Algo : Création d'une (poly)ligne
// Vérification de la validité des paramètre (nb de paramètres, castable en entier,
// pas de dépassement mémoire), puis l'ajouter dans la liste
{
    // Choix entre ligne et ployligne
    int aNbPoint = -1;
    if (line)
    {
        aNbPoint = 4;
    }

    // Vérif syntaxe
    if (!VerifySyntax(aInst, aNbPoint, false) || (aNbPoint==-1 && (aInst.size()-1)%4!=0))
    {
        cout<<"#Wrong parameter(s)"<<endl;
        return false;
    }

    // Création du vecteur de points
    VectPoint * aVectPoint = new VectPoint;
    for (int i=1; i < aInst.size(); i+=2)
    {
        CPoint * aPoint = new CPoint (VectStringToInt(aInst[i]),VectStringToInt(aInst[i+1]));
        aVectPoint->push_back(aPoint);
    }

    if (line)
    {
        CLine * aLine = new CLine (aVectPoint);
        vFigure->push_back(aLine);
    }
    else
    {
        CPolyLine * aPoly = new CPolyLine (aVectPoint);
        vFigure->push_back(aPoly);
    }
    return true;
}

bool CSchema::Move(vector<string> aInst)
// Algo : Déplacement des différents points
// Parcourt de la liste et déplacement des points pour les elt sélectionnés
// Si un déplacement n'est pas possible : annulation des déplacements précédents
{
    if (!VerifySyntax(aInst,2, false))
    {
        cout<<"#Wrong parameter(s)"<<endl;
        return false;
    }

    bool bMovePossible = true;
    vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end() && bMovePossible)
    {
        if ((*it)->GetisSelected())
        {
            bMovePossible=(*it)->Move(VectStringToInt(aInst[1]),VectStringToInt(aInst[2]));
        }
        it++;
    }

    if (bMovePossible)
    {
        return true;
    }
    else
    {
        vectFigure::iterator itRedo = it;
        while(it!=vFigure->begin())
        {
            (*it)->Move(-VectStringToInt(aInst[1]),-VectStringToInt(aInst[2]));
            it--;
        }
        cout<<"# Invalid Move"<<endl;
        return false;
    }
    }

void CSchema::ShowList ()
// Algorithme :
// Trivial
{
    vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
        cout<<(*it)->GetCreator()<<endl;
        it++;
    }
}

void CSchema::UnSelectAll ()
// Algorithme :
// Trivial
{
  vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
        (*it)->Unselect();
        it++;
    }
}

bool CSchema::Select(vector<string> aInst)
// Algorithme :
// Vérification des paramètre puis déselection de la précédente sélection
// Nouvelle sélection grâce à un parcourt du tableau
{
    if (!VerifySyntax(aInst,4, false))
    {
        cout<<"#Wrong parameter(s)"<<endl;
        return false;
    }

    UnSelectAll();


    int x1 = VectStringToInt(aInst[1]);
    int y1 = VectStringToInt(aInst [2]);
    int x2 = VectStringToInt(aInst [3]);
    int y2 = VectStringToInt(aInst [4]);

    int nbSelected = 0;

    vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
        (*it)->Select(x1,y1,x2,y2);
        if ((*it)->GetisSelected())
        {
            nbSelected++;
        }
        it++;
    }

    cout<<nbSelected<<endl;
    return true;
}

int CSchema::VectStringToInt (string aString)
// Algorithme :
// Trivial
{
    stringstream aStreamString (aString);
    int aInt;
    aStreamString>>aInt;
    return aInt;
}

bool CSchema::Load(vector<string> aInst)
// Algorithme :
//
{
    if (!VerifySyntax(aInst,1, true))
    {
        cout<<"#Wrong parameter(s)"<<endl;
        return false;
    }

    ifstream myFile (aInst[1].c_str());
    if(!myFile.is_open())
    {
        cout<<"# Impossible to open :"<<aInst[1]<<endl;
    }
    else
    {
        vector<string> * StackCmd = new vector<string>;
        string buf;
        while(myFile.good())
        {
            getline(myFile,buf);
            StackCmd->push_back(buf);
        }
        myFile.close();
    }
}

bool CSchema::Save(vector<string> aInst)
// Algorithme :
// Récupartion des constructeur des elts présent dans la liste
// Ecriture de de ces constructeur dans un fichier
{
    if (!VerifySyntax(aInst,1, true))
    {
        cout<<"#Wrong parameter(s)"<<endl;
        return false;
    }

    ofstream myFile (aInst[1].c_str(), ios::trunc);
    if(!myFile.is_open())
    {
        cout<<"# Impossible to open :"<<aInst[1]<<endl;
        return false;
    }
    else
    {
        vectFigure::iterator it = vFigure->begin();
        while (it!=vFigure->end())
        {
            myFile<<(*it)->GetCreator()<<endl;
            it++;
        }
        myFile.close();
        return true;
    }
}

void CSchema::Clear(bool all)
// Algorithme :
// Parcourt de la liste et effacer toute les figure ou celles selectionnées
{
    int nbDelete=0;
	vectFigure::iterator it = vFigure->begin();
    while (it!=vFigure->end())
    {
		if ((*it)->GetisSelected())
		{
			it = vFigure->erase(it);
			nbDelete++;
		}
		else if (all)
		{
			it = vFigure->erase(it);
			nbDelete++;
		}
		else
		{
		    it++;
		}
    }
    cout<<nbDelete<<endl;
}

void CSchema::Count()
// Algo : trivial
{
    cout<<vFigure->size()<<endl;
}

void CSchema::Close ()
// Algo : trivial
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

