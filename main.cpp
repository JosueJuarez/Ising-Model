//#include"mathlink.h"
#include"2DIsingModel.h"

// TwoDIsingModel *Model = nullptr;

//  void create_IsingModel()
//  {
//  	if (Model != nullptr)
//  		delete Model;

//  	Model = new TwoDIsingModel();
//  }

//  void sent_lattice()
//  {
//      return Model->SentLattice();
//  }

int main()
{
	TwoDIsingModel test = TwoDIsingModel(1.2, 100.0, 2);
	test.PrintLattice();

	float prueba = test.Energy();
	std::cout << "La energía es:" << ' ';
	std::cout << prueba << ' ';

	return 0;
}

//  #if _WIN32

//  #include <windows.h>
//  extern HWND MLInitializeIcon( HINSTANCE hinstCurrent, int nCmdShow);

//  int PASCAL WinMain( HINSTANCE hinstCurrent, HINSTANCE hinstPrevious, LPSTR lpszCmdLine, int nCmdShow)
//  {
//  	char buff[512];
//  	char * buff_start = buff;
//  	char * argv[32];
//  	char ** argv_end = argv + 32;

//  	hinstPrevious = hinstPrevious; /* suppress warning */

//  	if( !MLInitializeIcon( hinstCurrent, nCmdShow)) return 1;
//  	MLScanString( argv, &argv_end, &lpszCmdLine, &buff_start);
//  	return MLMain( (int)(argv_end - argv), argv);
//  }

//  #else

//  int main(int argc, char* argv[])
//  {
//  	return MLMain(argc, argv);
//  }

//  #endif


