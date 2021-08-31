#pragma once

namespace Acrylic
{
	class ViewportPanel
	{
	public:
		ViewportPanel();

		void OnImGuiRender();

		void Open() { m_Open = true; }
	private:
		bool m_Open = true;
	};
}
