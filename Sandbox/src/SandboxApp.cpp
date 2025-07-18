#include <WhatsThisEngine.h>

class Sandbox : public WTE::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

WTE::Application* WTE::CreateApplication()
{
	return new Sandbox();
}