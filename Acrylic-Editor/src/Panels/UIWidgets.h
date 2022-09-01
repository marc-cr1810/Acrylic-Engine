#pragma once

#include "Acrylic/Core/Base.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

namespace Acrylic {
	namespace UI
	{
		bool DrawVec2Control(const std::string& label, glm::vec2& values, float resetValue = 0.0f, float columnWidth = 75.0f);
		bool DrawVec3Control(const std::string& label, glm::vec3& values, float resetValue = 0.0f, float columnWidth = 75.0f);
		bool DrawVec4Control(const std::string& label, glm::vec4& values, float resetValue = 0.0f, float columnWidth = 75.0f);

		bool DrawTreeNodeWithImage(ImTextureID user_texture_id, const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...);
	}
}
