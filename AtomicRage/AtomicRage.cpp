// AtomicRage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "App.h"


int main()
{
	App* app = new App();

	app->Run();

	delete app;
}

