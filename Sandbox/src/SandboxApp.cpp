#include <Newton.h>

class Sandbox : public Newton::Application 
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}

};

Newton::Application* Newton::CreateApplication()
{
	return new Sandbox();
}