#include <Acrylic.h>
#include "Acrylic/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace Acrylic
{

	class AcrylicEditor : public Application
	{
	public:
		AcrylicEditor(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}

		~AcrylicEditor()
		{}
	};

	Application* Acrylic::CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "Acrylic Editor";
		spec.CommandLineArgs = args;

		return new AcrylicEditor(spec);
	}
}
