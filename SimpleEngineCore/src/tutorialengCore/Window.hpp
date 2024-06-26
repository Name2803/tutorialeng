#pragma once

#include "tutorialengCore/Event.hpp"

#include <string>
#include <functional>


struct GLFWwindow;

namespace Tutorialeng {

	class Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		Window(std::string title, const unsigned int width, const unsigned int height);
		~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

		//called each frame
		void on_update();
		unsigned int get_width() const { return m_data.width; }
 		unsigned int get_height() const { return m_data.height; }

		void set_event_callback(const EventCallbackFn& callback)
		{
			m_data.eventCallbackFn = callback;
		}

	private:
		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			EventCallbackFn eventCallbackFn;
		};

		int init();
		void shutdown();

		GLFWwindow* m_pWindow = nullptr;
		WindowData m_data;
	};
}