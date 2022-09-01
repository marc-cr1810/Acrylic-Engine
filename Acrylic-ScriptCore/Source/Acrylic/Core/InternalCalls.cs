using System;
using System.Runtime.CompilerServices;

namespace Acrylic
{
	public static class InternalCalls
	{
		#region Entity

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static bool Entity_HasComponent(ulong entityID, Type componentType);

		#endregion

		#region TransformComponent

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void TransformComponent_GetTranslation(ulong entityID, out Vector3 translation);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void TransformComponent_SetTranslation(ulong entityID, ref Vector3 translation);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void TransformComponent_GetRotation(ulong entityID, out Vector3 rotation);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void TransformComponent_SetRotation(ulong entityID, ref Vector3 rotation);

		#endregion

		#region SpriteRendererComponent

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void SpriteRendererComponent_GetColor(ulong entityID, out Vector4 color);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void SpriteRendererComponent_SetColor(ulong entityID, ref Vector4 color);

		#endregion

		#region CircleRendererComponent

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void CircleRendererComponent_GetColor(ulong entityID, out Vector4 color);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void CircleRendererComponent_SetColor(ulong entityID, ref Vector4 color);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void CircleRendererComponent_GetThickness(ulong entityID, out float thickness);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void CircleRendererComponent_SetThickness(ulong entityID, ref float thickness);

		#endregion

		#region Rigidbody2DComponent

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void Rigidbody2DComponent_ApplyLinearImpulse(ulong entityID, ref Vector2 impulse, ref Vector2 point, bool wake);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void Rigidbody2DComponent_ApplyLinearImpulseToCenter(ulong entityID, ref Vector2 impulse, bool wake);

		#endregion

		#region Input

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static bool Input_IsKeyDown(KeyCode keycode);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static bool Input_IsMouseButtonPressed(MouseCode button);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void Input_GetMousePosition(out Vector2 position);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void Input_GetMouseX(out float xPosition);

		[MethodImplAttribute(MethodImplOptions.InternalCall)]
		internal extern static void Input_GetMouseY(out float yPosition);

		#endregion
	}
}
