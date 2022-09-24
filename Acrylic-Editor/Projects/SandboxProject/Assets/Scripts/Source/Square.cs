using System;
using Acrylic;

namespace Sandbox
{
	public class Square : Entity
	{
		public Vector2 Vec2 = new Vector2(0.2f, 0.7f);
		public Vector3 Vec3 = new Vector3(0.5f, 0.5f, 0.0f);
		public Vector4 Vec4 = new Vector4(0.8f, 0.3f, 0.6f, 1.0f);

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
