namespace Acrylic
{
	public class CircleRendererComponent : Component
	{
		public Vector4 Color
		{
			get
			{
				InternalCalls.CircleRendererComponent_GetColor(Entity.ID, out Vector4 color);
				return color;
			}
			set
			{
				InternalCalls.CircleRendererComponent_SetColor(Entity.ID, ref value);
			}
		}

		public float Thickness
		{
			get
			{
				InternalCalls.CircleRendererComponent_GetThickness(Entity.ID, out float thickness);
				return thickness;
			}
			set
			{
				InternalCalls.CircleRendererComponent_SetThickness(Entity.ID, ref value);
			}
		}
	}
}
