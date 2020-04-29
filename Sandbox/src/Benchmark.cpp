#include "Benchmark.h"

#include <numeric>

void Benchmark::OnUpdate(Acrylic::Timestep ts)
{
	m_TimePassed += ts;
	m_FrameTime = ts * 1000;
	m_FPS = 1000 / m_FrameTime;

	// Wait a couple of seconds to load
	if (m_TimePassed > 3.0f)
	{
		m_FrameTimeData.push_back(ts * 1000);

		m_AvgFrameTime = std::accumulate(m_FrameTimeData.begin(), m_FrameTimeData.end(), 0.0) / m_FrameTimeData.size();
		std::vector<float> low1 = GetLows(m_FrameTimeData, 2.32);
		m_Avg1Low = std::accumulate(low1.begin(), low1.end(), 0.0) / low1.size();
		std::vector<float> low2 = GetLows(m_FrameTimeData, 3.1);
		m_Avg01Low = std::accumulate(low2.begin(), low2.end(), 0.0) / low2.size();

		if (isnan(m_Avg1Low))
			m_Avg1Low = m_AvgFrameTime;
		if (isnan(m_Avg01Low))
			m_Avg01Low = m_Avg1Low;

		m_FPSAvg = 1000 / m_AvgFrameTime;
		m_FPSLow1 = 1000 / m_Avg1Low;
		m_FPSLow01 = 1000 / m_Avg01Low;
	}
}

std::vector<float> Benchmark::GetLows(std::vector<float>& v, float val)
{
	std::vector<float> result;

	double accum = 0.0;
	std::for_each(std::begin(v), std::end(v), [&](const double d)
	{
		accum += (d - m_AvgFrameTime) * (d - m_AvgFrameTime);
	});

	double stdev = sqrt(accum / (v.size() - 1));

	for (int i = 0; i < v.size(); i++)
	{
		float z = ((v[i] - m_AvgFrameTime) / stdev);
		if (z >= val)
			result.push_back(v[i]);
	}

	return result;
}
