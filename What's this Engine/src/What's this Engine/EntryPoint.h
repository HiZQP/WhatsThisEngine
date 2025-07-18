#pragma once

#ifdef WTE_PLATFORM_WINDOWS
	
extern WTE::Application* WTE::CreateApplication();

int main(int argc, char** argv) {
	auto app = WTE::CreateApplication();
	app->Run();
	delete app;
}

#endif  
