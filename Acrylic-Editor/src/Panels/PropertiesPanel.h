#pragma once

#include "Acrylic/Core/Base.h"
#include "Acrylic/Scene/Entity.h"

#include "Acrylic/Renderer/Texture.h"

namespace Acrylic
{
	class PropertiesPanel
	{
	public:
		PropertiesPanel();

		void OnImGuiRender(const Entity& context);

		void Open() { m_Open = true; }
	private:
		void DrawComponents(Entity entity);
	private:
		Ref<Texture2D> m_TransformIcon;
		Ref<Texture2D> m_SpriteRendererIcon;
		Ref<Texture2D> m_CircleRendererIcon;
		Ref<Texture2D> m_CameraIcon;

		bool m_Open = true;
	};
}
