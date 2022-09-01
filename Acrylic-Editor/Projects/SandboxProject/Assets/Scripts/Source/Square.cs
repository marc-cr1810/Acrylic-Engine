using System;
using Acrylic;

namespace Sandbox
{
	public class Square : Entity
	{
		private SpriteRendererComponent Sprite;

		void OnCreate()
		{
			Sprite = GetComponent<SpriteRendererComponent>();
			Sprite.Color = new Vector4(1, 0, 1, 1);
		}

		void OnUpdate(float ts)
		{
			if (Input.IsMouseButtonPressed(MouseCode.ButtonLeft))
				Sprite.Color = new Vector4(1, 0, 0, 1);
			else if (Input.IsMouseButtonPressed(MouseCode.ButtonMiddle))
				Sprite.Color = new Vector4(0, 1, 0, 1);
			else if (Input.IsMouseButtonPressed(MouseCode.ButtonRight))
				Sprite.Color = new Vector4(0, 0, 1, 1);
		}
	}
}
