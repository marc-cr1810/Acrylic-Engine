using System;
using Acrylic;

namespace Sandbox
{
	public class Camera : Entity
	{
		public float DistanceFromPlayer = 5.0f;

		private Entity Player;

		void OnCreate()
		{
			Player = GetEntityByTag("Player");
		}

		void OnUpdate(float ts)
		{
			if (Player != null)
				Translation = new Vector3(Player.Translation.XY, DistanceFromPlayer);

			float speed = 3.0f;
			Vector3 velocity = Vector3.Zero;
			Vector3 rotation = Vector3.Zero;

			if (Input.IsKeyDown(KeyCode.Up))
				velocity.Y = 1.0f;
			else if (Input.IsKeyDown(KeyCode.Down))
				velocity.Y = -1.0f;

			if (Input.IsKeyDown(KeyCode.Left))
				velocity.X = -1.0f;
			else if (Input.IsKeyDown(KeyCode.Right))
				velocity.X = 1.0f;

			velocity *= speed;
			rotation *= speed;

			Vector3 translation = Translation;
			translation += velocity * ts;
			Translation = translation;

			Vector3 rot = Rotation;
			rot += rotation * ts;
			Rotation = rot;
		}
	}
}
