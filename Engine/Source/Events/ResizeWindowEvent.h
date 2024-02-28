#pragma once

#include "Event.h"

namespace Engine {

	class ResizeWindowEvent : public Event
	{
	public:
		ResizeWindowEvent(int width, int height);
	};

}

