#include <Acrylic.h>
#include "Acrylic/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace Acrylic
{

	class AcrylicEditor : public Application
	{
	public:
		AcrylicEditor(ApplicationCommandLineArgs args)
			: Application("Acrylic Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~AcrylicEditor()
		{}
	};

	Application* Acrylic::CreateApplication(ApplicationCommandLineArgs args)
	{
		return new AcrylicEditor(args);
	}
}
