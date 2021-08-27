#include <Acrylic.h>
#include "Acrylic/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace Acrylic
{

	class AcrylicEditor : public Application
	{
	public:
		AcrylicEditor()
			: Application("Acrylic Editor")
		{
			PushLayer(new EditorLayer());
		}

		~AcrylicEditor()
		{}
	};

	Application* Acrylic::CreateApplication()
	{
		return new AcrylicEditor();
	}
}