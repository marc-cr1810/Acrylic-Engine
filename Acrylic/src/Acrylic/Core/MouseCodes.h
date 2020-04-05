#pragma once

namespace Acrylic
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define AC_MOUSE_BUTTON_0      ::Acrylic::Mouse::Button0
#define AC_MOUSE_BUTTON_1      ::Acrylic::Mouse::Button1
#define AC_MOUSE_BUTTON_2      ::Acrylic::Mouse::Button2
#define AC_MOUSE_BUTTON_3      ::Acrylic::Mouse::Button3
#define AC_MOUSE_BUTTON_4      ::Acrylic::Mouse::Button4
#define AC_MOUSE_BUTTON_5      ::Acrylic::Mouse::Button5
#define AC_MOUSE_BUTTON_6      ::Acrylic::Mouse::Button6
#define AC_MOUSE_BUTTON_7      ::Acrylic::Mouse::Button7
#define AC_MOUSE_BUTTON_LAST   ::Acrylic::Mouse::ButtonLast
#define AC_MOUSE_BUTTON_LEFT   ::Acrylic::Mouse::ButtonLeft
#define AC_MOUSE_BUTTON_RIGHT  ::Acrylic::Mouse::ButtonRight
#define AC_MOUSE_BUTTON_MIDDLE ::Acrylic::Mouse::ButtonMiddle
