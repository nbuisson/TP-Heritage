/*************************************************************************
                           CHistoric  -  description
                             -------------------
    d�but                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson et pmdartus
*************************************************************************/

//---------- R�alisation de la classe <CHistoric> (fichier CHistoric.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>
#include <sstream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "CHistoric.h"
#include "CSchema.h"
#include <vector>
using namespace std;

//------------------------------------------------------------- Constantes

//#define MAP

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void CHistoric::AddHistoric (string aInst)
// Algorithme :
// Recherche si la commande est une commande qui modifie l'état des elts
// Ajout simple si la commande est une commande dite simple
// Si la commande est complexe, il faut réaliser la lecture du fichier
// dans le but d'enregister les commandes
{
    //Init variables
    stringstream buf (aInst);
    string frontChar;
    buf >> frontChar;

    // Exploitation des commandes simples
    if (frontChar=="C" || frontChar=="R" || frontChar=="L" || frontChar=="PL" || frontChar=="MOVE" || frontChar == "LOAD")
    {
        while (it!=vStack->end())
        {
            it = vStack->erase(it);
        }

        vectCommande * currentCmd = new vectCommande;

        if( frontChar == "LOAD" )
        {
            string fileName;
            buf>>fileName;

            ifstream myFile (fileName.c_str());
            if(myFile.is_open())
            {
                string buf;
                while(myFile.good())
                {
                    getline(myFile,buf);
                    if (!buf.empty() && buf[0]!='#')
                    {
                        currentCmd->push_back(buf);
                    }
                }
                myFile.close();
            }
        }
        else
        {
            currentCmd->push_back(aInst);
        }

        vStack->push_back(currentCmd);
        it=vStack->end();
    }

    // Vérifier l'éat des la pile de commande
    if (vStack->size()>20)
    {
        vStack->erase(vStack->begin());
    }
}

void CHistoric::AddDelInst (vector<string> *aInst)
{
    while (it!=vStack->end())
    {
        it = vStack->erase(it);
    }
    aInst->insert(aInst->begin(),"DEL");
    vStack->push_back(aInst);
    it=vStack->end();

    // Vérifier l'éat des la pile de commande
    if (vStack->size()>20)
    {
        vStack->erase(vStack->begin());
    }
}

bool CHistoric::Undo ()
{
    if(it==vStack->begin())
    {
        cout<<"# No instruction to undo"<<endl;
        return false;
    }
    else
    {
        it--;

        #ifdef MAP
        DisplayHist ();
        #endif

        CSchema *mySchema;
        mySchema = CSchema::getInstance();

        // Invert operation
        vectCommande::iterator itCmd = (*it)->begin();
        if (*itCmd=="DEL")
        {
            itCmd++;
            while (itCmd!=(*it)->end())
            {
                mySchema->ReadInstruction(*itCmd);
                itCmd++;
            }
        }
        else
        {
            while (itCmd!=(*it)->end())
            {
                mySchema->OppositeInst(*itCmd);
                itCmd++;
            }
        }
        return true;
    }
}

bool CHistoric::Redo ()
{
    if(it == vStack->end())
    {
        cout<<"# No instruction to redo"<<endl;
        return false;
    }
    else
    {
        #ifdef MAP
        DisplayHist ();
        #endif

        CSchema *mySchema;
        mySchema = CSchema::getInstance();

        // Invert operation
        vectCommande::iterator itCmd = (*it)->begin();
        if (*itCmd=="DEL")
        {
            itCmd++;
            while (itCmd!=(*it)->end())
            {
                mySchema->OppositeInst(*itCmd);
                itCmd++;
            }

        }
        else
        {
            while (itCmd!=(*it)->end())
            {
                mySchema->ReadInstruction(*itCmd);
                itCmd++;
            }
        }

        it++;
        return true;
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

void CHistoric::DisplayHist()
//Algo : affichage de la pile de commande jusqu'à l'endroit ou la pile
//est actuellement
{
    cout<<"Il reste dans la pile :"<<endl;
    vectStack::iterator itPrint = vStack->begin();
    while (itPrint!=vStack->end())
    {
        if (it==itPrint)
        {
            cout<<"-> "<<endl;
        }
        vectCommande::iterator itCmd = (*itPrint)->begin();
        while (itCmd!=(*itPrint)->end())
        {
            cout<<(*itCmd)<<" ";
            itCmd++;
        }
        cout<<endl;
        cout<<endl;
        itPrint++;
    }
}

