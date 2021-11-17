#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
//#include"mathlink.h"

class TwoDIsingModel
{
private:
	
	//Sistema
	static const int N = 10; //Tamaño de la malla N x N
	const float J;
	const float T;
	int lattice[N][N];

	//Probabilidades
	double P8 = exp(-8*J/T);
	double P4 = exp(-4*J/T);
	double P0 = exp(0);
	double Pm4 = exp(4*J/T);
	double Pm8 = exp(8*J/T);

	int RandomSpin(int const down = -1, int const up = 1) // Devuelve un valor aleatorio de espín
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 2);
		return (dis(gen) == 1)? down : up;
	}

	int RandomNumber() // Genera un número aleatorio entre 0 y N
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, N); // define the range

		return distr(gen);
	}

	double RandomProbability() // Genera un número aleatorio entre 0 y 1
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0, 1.0);

		return dis(gen);
	}

	int BoundaryIndex(int index) // Función para tomar en cuenta las condiciones de frontera periodicas
	{
		index = index % N;
		index = index + N; // If index is negative, modulus division gives us negative result, so this makes it positive.
		index = index % N; // In case the previous step made index >= n
		return index;
	}

	double dEnergy(int iindex, int jindex) //Calcula el cambio de energía por el flip de algún spin
	{
		int iUp = BoundaryIndex(iindex+1);
		int iDwn = BoundaryIndex(iindex-1);
		int jUp = BoundaryIndex(jindex+1);
		int jDwn = BoundaryIndex(jindex-1);

		double dH = 2*J*lattice[iindex][jindex]*(lattice[iUp][jindex] + lattice[iindex][jUp] + lattice[iDwn][jindex] + lattice[iindex][jDwn]);

		return dH;
	}

	void MetropolisStep()
	{
		//Escogemos dos indices aleatorios
		int ri = RandomNumber();
		int rj = RandomNumber();

		double dE = dEnergy(ri, rj);

		if(dE < 0)
		{
			lattice[ri][rj] = -lattice[ri][rj];
		}

		else if(dE == 8*J)
		{
			
		}

	}

//======== Distintos estados iniciales =========
	void StartRandomLattice() // Matriz aleatoria de -1 y +1
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				lattice[i][j] = RandomSpin();
			}
		}
	}

	void StartAllUpLattice() // Todos los espin +1
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				lattice[i][j] = 1;
			}
		}
	}

	void StartAllDwnLattice() // Todos los spin -1
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				lattice[i][j] = -1;
			}
		}
	}
//========================================

public:

	TwoDIsingModel(const float j, const float t, int r) : J(j), T(t)
	//Crea un estado inicial del sistema. r=1 : lattice aleatoria, r=2 :  todos los spin positivos, r=3 : todos los spins negativos.
	{
		if(r == 1)
		{
			StartRandomLattice();
		}

		if(r == 2)
		{
			StartAllUpLattice();
		}
		
		if(r == 3)
		{
			StartAllDwnLattice();
		}
	}

	void PrintLattice() // Imprime la malla en la terminal
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				std::cout << lattice[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	double Energy() // Calcula la energía del sistema
	{
		double H = 0.0;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				int iUp = BoundaryIndex(i+1);
				int iDwn = BoundaryIndex(i-1);
				int jUp = BoundaryIndex(j+1);
				int jDwn = BoundaryIndex(j-1);

				H += -J*lattice[i][j]*(lattice[iUp][j] + lattice[i][jUp] + lattice[iDwn][j] + lattice[i][jDwn]);

			}
			std::cout << std::endl;
		}
		return H/2;
	}




	// void SentLattice() // Manda la malla a Mathematica
	// {
	// 	MLPutFunction(stdlink, "List", N);
	// 	for (int i = 0; i < N; i++)
	// 	{
	// 		MLPutFunction(stdlink, "List", N);
	// 		for (int j = 0; j < N; j++)
	// 		{
	// 			MLPutInteger(stdlink, lattice[i][j]);
	// 		}
	// 		std::cout << std::endl;
	// 	}
	// 	MLEndPacket(stdlink);
	// }


};