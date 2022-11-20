#include <iostream>
#include <math.h>
using namespace std;

class NbComplexe
{
protected:
	float re, im;

public:
	void saisir()
	{
		cout << "saisir partie réel : " << endl;
		cin >> re;
		cout << "saisir partie immaginaire : " << endl;
		cin >> im;
	}

	void afficher()
	{
		if (im > 0)
		{
			cout << re << "+" << im << "i" << endl;
		}
		else
		{
			cout << re << "" << im << "i" << endl;
		}
	}

	void module2()
	{
		cout << "Le module du Nombre Complexe est : " << sqrt(re * re + im * im) << endl;
	}
};

int main()
{
	int taille;
	NbComplexe C;
	NbComplexe ComplexeTab;

	cout << "Quel est la taille tu tableau ?" << endl;
	cin >> taille;

	NbComplexe tab[taille];

	for (int i = 0; i < taille; i++)
	{
		tab[i] = A((((rand() % 201) - 100) / 10), (((rand() % 201) - 100) / 10));
	}

	C.saisir();
	cout << "Le Nombre Complexe est : ";
	C.afficher();
	cout << "La taille du nombre Complexe en octet est : " << sizeof(C) << endl;
	C.module2();
	return 0;
}
