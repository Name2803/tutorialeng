#include "tutorialengCore/Application.hpp"
#include "tutorialengCore/Log.hpp"
#include "tutorialengCore/Window.hpp"

#include <iostream>

namespace Tutorialeng {

    Application::Application()
    {
		LOG_INFO("Start Application");
    }

	Application::~Application()
	{
		LOG_INFO("Close Application");
	}

	int Application::start(unsigned int window_width, unsigned int window_height, const char* title) {
        
		m_pWindow = std::make_unique<Window>(title, window_width, window_height);
		m_pWindow->set_event_callback(
			[](Event& event)
			{
				LOG_INFO("[EVENT] Chang size to {0}x{1}", event.width, event.height);
			}
		);

		while (true)
		{
			m_pWindow->on_update();
			on_update();
		}

        return 0;
	}
}