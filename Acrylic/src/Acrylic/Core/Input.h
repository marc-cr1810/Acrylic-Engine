#pragma once

#include "Acrylic/Core/Base.h"
#include "Acrylic/Core/KeyCodes.h"
#include "Acrylic/Core/MouseCodes.h"

namespace Acrylic
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}