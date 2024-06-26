#pragma once

#include <memory>

namespace Tutorialeng {
	
	class Application {
	public:
		Application();
		virtual ~Application();

		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		virtual int start(unsigned int window_width, unsigned int window_height, const char* title);

		//called each frame
		virtual void on_update() {}

	private:
		std::unique_ptr<class Window> m_pWindow;
	};
}