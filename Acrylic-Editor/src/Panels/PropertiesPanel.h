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
		template<typename T>
		void DisplayAddComponentEntry(Entity entity, const std::string& entryName);

		void DrawComponents(Entity entity);
	private:
		Ref<Texture2D> m_TransformIcon;
		Ref<Texture2D> m_SpriteRendererIcon;
		Ref<Texture2D> m_CircleRendererIcon;
		Ref<Texture2D> m_CameraIcon;
		Ref<Texture2D> m_Rigidbody2DIcon;
		Ref<Texture2D> m_BoxCollider2DIcon;
		Ref<Texture2D> m_CircleCollider2DIcon;

		bool m_Open = true;
	};
}
