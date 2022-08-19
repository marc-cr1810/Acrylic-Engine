﻿using System;
using Acrylic;

namespace Sandbox
{
	public class Player : Entity
	{
		private TransformComponent Transform;
		private Rigidbody2DComponent Rigidbody;

		void OnCreate()
		{
			Console.WriteLine($"Player.OnCreate - {ID}");

			Transform = GetComponent<TransformComponent>();
			Rigidbody = GetComponent<Rigidbody2DComponent>();
		}

		void OnUpdate(float ts)
		{
			float speed = 15.0f;
			Vector3 velocity = Vector3.Zero;

			if (Input.IsKeyDown(KeyCode.W))
				velocity.Y = 1.0f;
			else if (Input.IsKeyDown(KeyCode.S))
				velocity.Y = -1.0f;

			if (Input.IsKeyDown(KeyCode.A))
				velocity.X = -1.0f;
			else if (Input.IsKeyDown(KeyCode.D))
				velocity.X = 1.0f;

			velocity *= speed * ts;

			Rigidbody.ApplyLinearImpulse(velocity.XY, true);
		}
	}
}
