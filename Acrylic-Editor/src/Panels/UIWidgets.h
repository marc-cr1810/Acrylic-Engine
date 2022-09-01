#pragma once

#include "Acrylic/Core/Base.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

namespace Acrylic {
	namespace UI
	{
		bool DrawVec3Control(const std::string& label, glm::vec3& values, float resetValue = 0.0f, float columnWidth = 100.0f);

		bool DrawTreeNodeWithImage(ImTextureID user_texture_id, const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...);
	}
}
