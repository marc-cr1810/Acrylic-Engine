
-- Acrylic Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Acrylic/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Acrylic/vendor/yaml-cpp/include"
IncludeDir["GLFW"] = "%{wks.location}/Acrylic/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Acrylic/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Acrylic/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Acrylic/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Acrylic/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Acrylic/vendor/entt/include"
IncludeDir["mono"] = "%{wks.location}/Acrylic/vendor/mono/include"
IncludeDir["Box2D"] = "%{wks.location}/Acrylic/vendor/Box2D/include"
IncludeDir["shaderc"] = "%{wks.location}/Acrylic/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/Acrylic/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["mono"] = "%{wks.location}/Acrylic/vendor/mono/lib/%{cfg.buildcfg}"

Library = {}
Library["mono"] = "%{LibraryDir.mono}/libmono-static-sgen.lib"

Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"