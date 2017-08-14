#pragma once
#include "stdafx.h"
#include "SDL_video.h"
#include "vulkan/vulkan.hpp"

enum class AppEvent : std::uint8_t
{
	None = 0,
	Quit = 1 << 0,
}; 
//ENABLE_BITMASK_OPERATORS(AppEvent)
template<>								
struct enable_bitmask_operators<AppEvent>   
{										
	static const bool enable = true;	
};

class App
{
public:
	App();
	~App();

	void Run();
private:
	AppEvent m_event;

	SDL_Window* m_window;

	void InitSDL();
	void ShutDownSDL();
	void HandleSDLError();

	vk::Instance* m_vkInstance;
	vk::PhysicalDevice m_vkPhysicalDevice;
	vk::Device* m_vkDevice;

	void InitVulkan();
	void ShutDownVulkan();

	void DrawFrame();
	void HandleSDLEvents();
};