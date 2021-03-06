#pragma once

#include "Acrylic/Core/Layer.h"

#include "Acrylic/Events/ApplicationEvent.h"
#include "Acrylic/Events/KeyEvent.h"
#include "Acrylic/Events/MouseEvent.h"

namespace Acrylic
{

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	};

}