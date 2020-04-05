#pragma once

namespace Acrylic
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define AC_KEY_SPACE           ::Acrylic::Key::Space
#define AC_KEY_APOSTROPHE      ::Acrylic::Key::Apostrophe    /* ' */
#define AC_KEY_COMMA           ::Acrylic::Key::Comma         /* , */
#define AC_KEY_MINUS           ::Acrylic::Key::Minus         /* - */
#define AC_KEY_PERIOD          ::Acrylic::Key::Period        /* . */
#define AC_KEY_SLASH           ::Acrylic::Key::Slash         /* / */
#define AC_KEY_0               ::Acrylic::Key::D0
#define AC_KEY_1               ::Acrylic::Key::D1
#define AC_KEY_2               ::Acrylic::Key::D2
#define AC_KEY_3               ::Acrylic::Key::D3
#define AC_KEY_4               ::Acrylic::Key::D4
#define AC_KEY_5               ::Acrylic::Key::D5
#define AC_KEY_6               ::Acrylic::Key::D6
#define AC_KEY_7               ::Acrylic::Key::D7
#define AC_KEY_8               ::Acrylic::Key::D8
#define AC_KEY_9               ::Acrylic::Key::D9
#define AC_KEY_SEMICOLON       ::Acrylic::Key::Semicolon     /* ; */
#define AC_KEY_EQUAL           ::Acrylic::Key::Equal         /* = */
#define AC_KEY_A               ::Acrylic::Key::A
#define AC_KEY_B               ::Acrylic::Key::B
#define AC_KEY_C               ::Acrylic::Key::C
#define AC_KEY_D               ::Acrylic::Key::D
#define AC_KEY_E               ::Acrylic::Key::E
#define AC_KEY_F               ::Acrylic::Key::F
#define AC_KEY_G               ::Acrylic::Key::G
#define AC_KEY_H               ::Acrylic::Key::H
#define AC_KEY_I               ::Acrylic::Key::I
#define AC_KEY_J               ::Acrylic::Key::J
#define AC_KEY_K               ::Acrylic::Key::K
#define AC_KEY_L               ::Acrylic::Key::L
#define AC_KEY_M               ::Acrylic::Key::M
#define AC_KEY_N               ::Acrylic::Key::N
#define AC_KEY_O               ::Acrylic::Key::O
#define AC_KEY_P               ::Acrylic::Key::P
#define AC_KEY_Q               ::Acrylic::Key::Q
#define AC_KEY_R               ::Acrylic::Key::R
#define AC_KEY_S               ::Acrylic::Key::S
#define AC_KEY_T               ::Acrylic::Key::T
#define AC_KEY_U               ::Acrylic::Key::U
#define AC_KEY_V               ::Acrylic::Key::V
#define AC_KEY_W               ::Acrylic::Key::W
#define AC_KEY_X               ::Acrylic::Key::X
#define AC_KEY_Y               ::Acrylic::Key::Y
#define AC_KEY_Z               ::Acrylic::Key::Z
#define AC_KEY_LEFT_BRACKET    ::Acrylic::Key::LeftBracket   /* [ */
#define AC_KEY_BACKSLASH       ::Acrylic::Key::Backslash     /* \ */
#define AC_KEY_RIGHT_BRACKET   ::Acrylic::Key::RightBracket  /* ] */
#define AC_KEY_GRAVE_ACCENT    ::Acrylic::Key::GraveAccent   /* ` */
#define AC_KEY_WORLD_1         ::Acrylic::Key::World1        /* non-US #1 */
#define AC_KEY_WORLD_2         ::Acrylic::Key::World2        /* non-US #2 */

/* Function keys */
#define AC_KEY_ESCAPE          ::Acrylic::Key::Escape
#define AC_KEY_ENTER           ::Acrylic::Key::Enter
#define AC_KEY_TAB             ::Acrylic::Key::Tab
#define AC_KEY_BACKSPACE       ::Acrylic::Key::Backspace
#define AC_KEY_INSERT          ::Acrylic::Key::Insert
#define AC_KEY_DELETE          ::Acrylic::Key::Delete
#define AC_KEY_RIGHT           ::Acrylic::Key::Right
#define AC_KEY_LEFT            ::Acrylic::Key::Left
#define AC_KEY_DOWN            ::Acrylic::Key::Down
#define AC_KEY_UP              ::Acrylic::Key::Up
#define AC_KEY_PAGE_UP         ::Acrylic::Key::PageUp
#define AC_KEY_PAGE_DOWN       ::Acrylic::Key::PageDown
#define AC_KEY_HOME            ::Acrylic::Key::Home
#define AC_KEY_END             ::Acrylic::Key::End
#define AC_KEY_CAPS_LOCK       ::Acrylic::Key::CapsLock
#define AC_KEY_SCROLL_LOCK     ::Acrylic::Key::ScrollLock
#define AC_KEY_NUM_LOCK        ::Acrylic::Key::NumLock
#define AC_KEY_PRINT_SCREEN    ::Acrylic::Key::PrintScreen
#define AC_KEY_PAUSE           ::Acrylic::Key::Pause
#define AC_KEY_F1              ::Acrylic::Key::F1
#define AC_KEY_F2              ::Acrylic::Key::F2
#define AC_KEY_F3              ::Acrylic::Key::F3
#define AC_KEY_F4              ::Acrylic::Key::F4
#define AC_KEY_F5              ::Acrylic::Key::F5
#define AC_KEY_F6              ::Acrylic::Key::F6
#define AC_KEY_F7              ::Acrylic::Key::F7
#define AC_KEY_F8              ::Acrylic::Key::F8
#define AC_KEY_F9              ::Acrylic::Key::F9
#define AC_KEY_F10             ::Acrylic::Key::F10
#define AC_KEY_F11             ::Acrylic::Key::F11
#define AC_KEY_F12             ::Acrylic::Key::F12
#define AC_KEY_F13             ::Acrylic::Key::F13
#define AC_KEY_F14             ::Acrylic::Key::F14
#define AC_KEY_F15             ::Acrylic::Key::F15
#define AC_KEY_F16             ::Acrylic::Key::F16
#define AC_KEY_F17             ::Acrylic::Key::F17
#define AC_KEY_F18             ::Acrylic::Key::F18
#define AC_KEY_F19             ::Acrylic::Key::F19
#define AC_KEY_F20             ::Acrylic::Key::F20
#define AC_KEY_F21             ::Acrylic::Key::F21
#define AC_KEY_F22             ::Acrylic::Key::F22
#define AC_KEY_F23             ::Acrylic::Key::F23
#define AC_KEY_F24             ::Acrylic::Key::F24
#define AC_KEY_F25             ::Acrylic::Key::F25

/* Keypad */
#define AC_KEY_KP_0            ::Acrylic::Key::KP0
#define AC_KEY_KP_1            ::Acrylic::Key::KP1
#define AC_KEY_KP_2            ::Acrylic::Key::KP2
#define AC_KEY_KP_3            ::Acrylic::Key::KP3
#define AC_KEY_KP_4            ::Acrylic::Key::KP4
#define AC_KEY_KP_5            ::Acrylic::Key::KP5
#define AC_KEY_KP_6            ::Acrylic::Key::KP6
#define AC_KEY_KP_7            ::Acrylic::Key::KP7
#define AC_KEY_KP_8            ::Acrylic::Key::KP8
#define AC_KEY_KP_9            ::Acrylic::Key::KP9
#define AC_KEY_KP_DECIMAL      ::Acrylic::Key::KPDecimal
#define AC_KEY_KP_DIVIDE       ::Acrylic::Key::KPDivide
#define AC_KEY_KP_MULTIPLY     ::Acrylic::Key::KPMultiply
#define AC_KEY_KP_SUBTRACT     ::Acrylic::Key::KPSubtract
#define AC_KEY_KP_ADD          ::Acrylic::Key::KPAdd
#define AC_KEY_KP_ENTER        ::Acrylic::Key::KPEnter
#define AC_KEY_KP_EQUAL        ::Acrylic::Key::KPEqual

#define AC_KEY_LEFT_SHIFT      ::Acrylic::Key::LeftShift
#define AC_KEY_LEFT_CONTROL    ::Acrylic::Key::LeftControl
#define AC_KEY_LEFT_ALT        ::Acrylic::Key::LeftAlt
#define AC_KEY_LEFT_SUPER      ::Acrylic::Key::LeftSuper
#define AC_KEY_RIGHT_SHIFT     ::Acrylic::Key::RightShift
#define AC_KEY_RIGHT_CONTROL   ::Acrylic::Key::RightControl
#define AC_KEY_RIGHT_ALT       ::Acrylic::Key::RightAlt
#define AC_KEY_RIGHT_SUPER     ::Acrylic::Key::RightSuper
#define AC_KEY_MENU            ::Acrylic::Key::Menu
