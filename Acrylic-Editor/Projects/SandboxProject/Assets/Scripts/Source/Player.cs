﻿using System;
using Acrylic;

namespace Sandbox
{
	public class Player : Entity
	{
		public float Speed = 15.0f;
		public Vector3 Vec3 = new Vector3(1.5f, 1.0f, 0.4f);

		private Entity CameraEntity;

		private TransformComponent Transform;
		private Rigidbody2DComponent Rigidbody;

		void OnCreate()
		{
			CameraEntity = GetEntityByTag("Camera");

			Transform = GetComponent<TransformComponent>();
			Rigidbody = GetComponent<Rigidbody2DComponent>();
		}

		void OnUpdate(float ts)
		{
			Vector3 velocity = Vector3.Zero;

			if (Input.IsKeyDown(KeyCode.W))
				velocity.Y = 1.0f;
			else if (Input.IsKeyDown(KeyCode.S))
				velocity.Y = -1.0f;

			if (Input.IsKeyDown(KeyCode.A))
				velocity.X = -1.0f;
			else if (Input.IsKeyDown(KeyCode.D))
				velocity.X = 1.0f;

			if (CameraEntity != null)
			{
				Camera camera  = CameraEntity.As<Camera>();

				if (Input.IsKeyDown(KeyCode.Q))
					camera.DistanceFromPlayer += 2.0f * ts;
				else if (Input.IsKeyDown(KeyCode.E))
					camera.DistanceFromPlayer -= 2.0f * ts;
			}

			velocity *= Speed * ts;

			Rigidbody.ApplyLinearImpulse(velocity.XY, true);
		}
	}
}
