#include <iostream>
#include <math.h>
using namespace std;

class NbComplexe
{
private:
	float re, im;
public:
	NbComplexe() : re(0), im(0) {}
	NbComplexe(float a, float b) : re(a), im(b) {}
	NbComplexe(const NbComplexe &c)
	{
		re = c.re;
		im = c.im;
	}
	NbComplexe &operator=(const NbComplexe &); // declaration opérateur = 


	friend ostream &operator<<(ostream &f, const NbComplexe &Nb); // déclaration opérateur de flux toujours en friend qui permet d'acceder aux private 
	friend istream &operator>>(istream &f, NbComplexe &c); // déclaration opérateur de flux toujours en friend qui permet d'acceder aux private 

	NbComplexe operator*(const NbComplexe &); // declaration opérateur *

	void saisir()
	{
		cout << "saisir partie réel : " << endl;
		cin >> re;
		cout << "saisir partie immaginaire : " << endl;
		cin >> im;
	}

	void afficher() const
	{
		cout << re << " ";
		if (im >= 0.0)
			cout << "+";
		cout << im << " i";
		cout << endl;
	}

	float module() const
	{
		return sqrt(re * re + im * im);
	}

	bool operator<(const NbComplexe &c)
	{
		return module() < c.module();
	}

	bool estPlusPetit(const NbComplexe &c) const
	{
		return module() < c.module();
	}

};

NbComplexe& NbComplexe::operator=(const NbComplexe &NC) // operateut = return *this obligatoire
{
	re = NC.re;
	im = NC.im;
	return *this;
}

NbComplexe NbComplexe::operator*(const NbComplexe &c) // opérateur * 
{
	return  NbComplexe( re * c.re - im * c.im, im * c.re + re * c.im);
}

ostream &operator<<(ostream& f, const NbComplexe &c) // opérateur <<
{
	f << c.re << " / " << c.im;
	return f;
}

istream &operator>>(istream& f, NbComplexe &c) // opérateur >>
{
	f >> c.re;
	char x;
	f>>x;
	f >> c.im;
	return f;
}

void trierParSelection(NbComplexe *tab, int taille)
{
	NbComplexe minComplexe;
	for (int i = 0; i < taille - 1; i++)
	{
		int indmin = i;
		for (int j = i + 1; j < taille; j++)
		{
			if (tab[j].estPlusPetit(tab[indmin]))
				indmin = j;
		}
		minComplexe = tab[indmin];
		tab[indmin] = tab[i];
		tab[i] = minComplexe;
	}
}

void trierParInsertion(NbComplexe *tab, int taille)
{
	NbComplexe complexeAPlacer;
	for (int i = 1; i < taille; i++)
	{
		complexeAPlacer = tab[i];
		int j = i - 1;
		while (j >= 0 && complexeAPlacer.estPlusPetit(tab[j]))
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = complexeAPlacer;
	}
}

void lirefichier(NbComplexe Tab[], int taille, char * nom_fichier)
{
	FILE * Donnee;
	Donnee = fopen(nom_fichier, "r+");
	int nb = fgets(nom_fichier, 500, Donnee);
}

int main()
{
	int taille;
	cout << "Donner le nombre de complexes: ";
	cin >> taille;
	if (taille <= 0)
		return 0;
	srand((unsigned int)time(NULL));
	NbComplexe *tab = new NbComplexe[taille];
	for (int i = 0; i < taille; i++)
	{
		tab[i] = NbComplexe(
		((rand() % 201) / 10.0) - 10.0,
		((rand() % 201) / 10.0) - 10.0);
		
		cout << "tab[" << i << "]= ";
		cout << "(mod= " << tab[i].module() << ") ";
		tab[i].afficher();
	}
	delete[] tab;
}
