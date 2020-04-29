#pragma once
#include "Acrylic.h"

class Benchmark
{
public:
	Benchmark() = default;
	~Benchmark() = default;

	void OnUpdate(Acrylic::Timestep ts);

	const uint32_t GetFPS() const { return m_FPS; }
	const uint32_t GetFPSAvg() const { return m_FPSAvg; }
	const uint32_t GetFPSLow1() const { return m_FPSLow1; }
	const uint32_t GetFPSLow01() const { return m_FPSLow01; }

	const float GetFrameTime() const { return m_FrameTime; }
	const float GetAvgFrameTime() const { return m_AvgFrameTime; }
	const float GetAvgLow1() const { return m_Avg1Low; }
	const float GetAvgLow01() const { return m_Avg01Low; }
private:
	std::vector<float> GetLows(std::vector<float>& v, float val);
private:
	std::vector<float> m_FrameTimeData;
	float m_TimePassed = 0.0f;

	float m_FrameTime;
	float m_AvgFrameTime = 0.0f;
	float m_Avg1Low = 0.0f;
	float m_Avg01Low = 0.0f;

	uint32_t m_FPS = 0;
	uint32_t m_FPSAvg = 0;
	uint32_t m_FPSLow1 = 0;
	uint32_t m_FPSLow01 = 0;
};