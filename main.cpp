#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include "Joueur.h"
#include "Lettre.h"
#include "Tentative.h"
#include <vector>
#include<algorithm>
#include<string>
using namespace std;

int affiche(vector<int> v)
{
    for (int i=0;i<v.size();i++)
    {
        cout<<i<<endl;
    }
    return 0;
}
string setmotadeviner(){
    int i=rand()%12+1;
ifstream f("fichier.txt");
string m;
for (int j=1; j<i; j++ ) {
	getline(f,m);

}
return m;
}

int main (){
    vector<string> v;
    v.push_back("vert");
    v.push_back("jaune");
    v.push_back("rouge");

	string nom ,mot;
    cout << "BIENVENUE AU ZPAPPING! "<<endl;
    cout << "Vous avez 10 tentatives pour deviner le mot caché."<<endl;
    cout << "Bon courage. Que la force soit avec vous!"<<endl;
	cout << "Veuillez entrer votre Nom :"<<endl;
	cin >> nom ;
	Joueur l(nom);
	string motadeviner;
	motadeviner=setmotadeviner();
	int nbessai=0;bool test=false;
	do{
    cout<<"Le mot commence par la lettre  "<<motadeviner[0]<<endl;
	cout<<"Saisir votre essai numero:"<< nbessai <<endl;

		cin>>mot;
		if (mot==motadeviner){test=true;break;}
    Tentative t(mot);
    if (t.controlesaisie(motadeviner))
        { nbessai++;//essai valid�

     vector<int> green; //recherche des lettres bien plac�es
     for (int i=0;i<10;i++){
            Lettre j(mot[i],i,rouge);
      for (int k=0;k<10;k++){
            Lettre m(motadeviner[k],k,rouge);
            j.Comparer(m);
            if (j.getCouleur()==vert) {green.push_back(k);break;}
     }
     }
     vector<int> yellow;//recherche des lettres mal plac�es
	for (int i=0;i<10;i++)
    {   Lettre j(mot[i],i,rouge);
        //calcul de l'occurence de chaque lettre dans le mot a deviner

        for (int k=0;k<10;k++)
        {if ((!(std::count(green.begin(), green.end(), k)))&&(!(std::count(yellow.begin(), yellow.end(), k))))//k pas dans red
                                {//recherche des jaunes
         Lettre m(motadeviner[k],k,rouge);
         j.Comparer(m);
         if (j.getCouleur()==jaune) {yellow.push_back(k);}
                                }

        }//fin parcours lettre mot a deviner

        if ((std::count(green.begin(), green.end(), i))){j.setCouleur(vert);}
        if ((std::count(yellow.begin(), yellow.end(), i))){j.setCouleur(jaune);}


        cout<<"lettre "<<j.getval()<<" est de couleur "<<v[j.getCouleur()]<<endl;
        yellow.clear();
    }//fin parcours de la lettre lettre
    }//fin parcours de l'essai
    else {cout<<"essayer de nouveau"<<endl;}
	}//fin parcours de tous les essais
	while (nbessai<10);
	if (test) {cout <<"BRAVO !! Vous avez gagné. "<<endl;}
        else {cout<<"Dommage, vous avez perdu."<<endl;}
    int x;
    x=10-nbessai;
	l.setScore(x);

	cout<<"votre score est :"<<x<<endl;
	l.setRecord(x);
	int b=l.getRecord();
	cout<<"votre record est : "<<b<<endl;

	return 0;

}


