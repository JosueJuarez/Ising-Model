#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
//#include"mathlink.h"

class TwoDIsingModel
{
private:
	
	static const int N = 2; //Tamaño de la malla N x N
	const float J;
	int lattice[N][N];

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

	void StartRandomLattice()
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				lattice[i][j] = RandomSpin();
			}
		}
	}

	void StartAllUpLattice()
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				lattice[i][j] = 1;
			}
		}
	}

	void StartAllDwnLattice()
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				lattice[i][j] = -1;
			}
		}
	}


public:

	TwoDIsingModel(const float j, int r) : J(j)
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

	float Energy() // Calcula la energía del sistema
	{
		float H = 0.0;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				//H += -J*lattice[i][j]*(lattice[(i+1)%N][j] + lattice[i][(j+1)%N] + lattice[(i-1)%N][j] + lattice[i][(j-1)%N]);
				H += -J*lattice[i][j];
				//std::cout << i << " " << j << "";
				std::cout << i << " " << (j-1)%N << "";
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