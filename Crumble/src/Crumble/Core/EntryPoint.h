#pragma once

#ifdef CR_PLATFORM_WINDOWS

extern Crumble::Application* Crumble::CreateApplication();

int main(int argc, char** argv)
{
	Crumble::Log::Init();
	CR_CORE_WARN("Initialized Log!");
	int a = 5;
	CR_INFO("Hello! Var={0}", a);

	auto app = Crumble::CreateApplication();
	app->Run();
	delete app;
}

#endif