#pragma once

#ifdef WTE_PLATFORM_WINDOWS
	
extern WTE::Application* WTE::CreateApplication();

int main(int argc, char** argv) {
	WTE::Log::Init();
	WTE_CORE_INFO("What's this Engine Initialized!");
	auto app = WTE::CreateApplication();
	app->Run();
	delete app;
}

#endif  
