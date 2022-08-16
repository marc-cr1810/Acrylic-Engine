#pragma once

#include <stdint.h>

namespace Acrylic
{
	// "UUID" (universally unique identifier) or GUID is (usually) a 128-bit integer
	// used to "uniquely" identify information. In Acrylic, even though we use the term
	// GUID and UUID, at the moment we're simply using a randomly generated 64-bit
	// integer, as the possibility of a clash is low enough for now.
	// This may change in the future.
	class UUID
	{
	public:
		UUID();
		UUID(uint64_t uuid);
		UUID(const UUID&) = default;

		operator uint64_t() const { return m_UUID; }
	private:
		uint64_t m_UUID;
	};

}

namespace std {
	template <typename T> struct hash;

	template<>
	struct hash<Acrylic::UUID>
	{
		std::size_t operator()(const Acrylic::UUID& uuid) const
		{
			return (uint64_t)uuid;
		}
	};
}
