#include "App.h"
#include "SDL.h"
#include "SDL_video.h"
#include "SDL_events.h"

App::App() :
	m_vkInstance(VK_NULL_HANDLE),
	m_vkDevice(VK_NULL_HANDLE)
{
	InitSDL();
	InitVulkan();
}

App::~App()
{
	ShutDownVulkan();
	ShutDownSDL();
}

void App::Run()
{
	while (true) 
	{
		m_event = AppEvent::None;
		HandleSDLEvents();
		if ((m_event & AppEvent::Quit) == AppEvent::Quit) 
		{
			break;
		}
		DrawFrame();
	}
}

void App::InitSDL()
{
	if (!SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
	{
		HandleSDLError();
	}
	m_window = SDL_CreateWindow("App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	if (!m_window)
	{
		// TODO we have a error
	}
}

void App::ShutDownSDL()
{
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = 0;
	}
	SDL_Quit();
}

void App::HandleSDLError()
{
	// TODO
}

void App::InitVulkan()
{
	vk::InstanceCreateInfo instanceInfo;
	// TODO scan for extentions and layers and enable them

	vk::ApplicationInfo appInfo;
	appInfo.setPApplicationName("App");
	appInfo.setApplicationVersion(1);
	appInfo.setPEngineName("App");
	appInfo.setEngineVersion(1);

	instanceInfo.setPApplicationInfo(&appInfo);

	m_vkInstance = &vk::createInstance(instanceInfo);

	/*auto physicalDeviceList = m_vkInstance->enumeratePhysicalDevices();
	for each (auto physicalDevice in physicalDeviceList)
	{
		m_vkPhysicalDevice = physicalDevice;

		vk::DeviceCreateInfo deviceInfo = {};
		// TODO scan for extentions and layers and enable them
		// TODO create Queus
		std::vector<vk::DeviceQueueCreateInfo>* queueInfos = new std::vector<vk::DeviceQueueCreateInfo>();

		vk::DeviceQueueCreateInfo queueInfoGeneral = {};
		queueInfoGeneral.queueCount = 1;
		queueInfoGeneral.queueFamilyIndex = 0;

		queueInfos->push_back(queueInfoGeneral);

		deviceInfo.pQueueCreateInfos = queueInfos;
		deviceInfo.queueCreateInfoCount = queueInfos->size;

		m_vkDevice = physicalDevice.createDevice(deviceInfo);

		delete queueInfos;
	}*/
}

void App::ShutDownVulkan()
{
	/*if (m_vkDevice) 
	{
		m_vkDevice->destroy();
		//delete m_vkDevice;
		m_vkDevice = VK_NULL_HANDLE;
	}
	if (m_vkInstance)
	{
		m_vkInstance->destroy();
		//delete m_vkInstance;
		m_vkInstance = VK_NULL_HANDLE;
	}*/
}

void App::DrawFrame()
{
}

void App::HandleSDLEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT :
			m_event = m_event | AppEvent::Quit;
			break;
		default:
			break;
		}
	}
}
