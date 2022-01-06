#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{

	int liczby[100];
	string ciagi[100];


	fstream plik;
	plik.open("pary.txt", ios::in);

	int linia = 0;
	while (linia < 100)
	{
		int liczba;
		string ciag;
		plik >> liczba;

		liczby[linia] = liczba;
		plik >> ciag;
		ciagi[linia] = ciag;

		linia++;
	}

	plik.close();

	//4.1
	 for (int i = 0; i < 100; i++)
	 {
		 bool parzysta = false;

		 if (liczby[i] % 2 == 0)
		 {
			 parzysta = true;
		 }

		 if (parzysta)
		 {

			 //cout << "\n" << liczby[i] << " ";

			 //j to pierwsza (najmniejsza) liczba ppierwsza ktora moze byc pasujaca do p[ary zeby byla suma
			 for (int j = 1; j < liczby[i]; j++)
			 {

				 bool pierwsza = true;
				 for (int k = 2; k < j; k++)
				 {
					 if (j % k == 0)
					 {
						 pierwsza = false;
						 break;
					 }
				 }

				 if (pierwsza)
				 {
					 int dopelniajaca = liczby[i] - j; //dopelniajaca to liczba dopielniajaca do sumy, musi bnyc terz pierwsza
					 bool pierwsza1 = true;
					 for (int k = 2; k < dopelniajaca; k++)
					 {
						 if (dopelniajaca % k == 0)
						 {
							 pierwsza1 = false;
							 break;
						 }
					 }

					 if (pierwsza1)
					 {
						 cout << liczby[i] << " " << j << " " << dopelniajaca << "\n";
						 break;
					 }
					 //cout << j << " ";
				 }

			
			 }

		 }

	 }

	//	cout << liczby[i] << " - " << (parzysta ? "Parzysta" : "Nieparzysta") << "\n";

	return 0;
}


