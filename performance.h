#pragma once
#include <chrono>
#include <iostream>
#include <fstream>
#if defined(_WIN32)
	#include <Windows.h>
	#include <psapi.h>
#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
	#include <unistd.h>
#endif

class Performance {
public:
	Performance() {
		startTimepoint = std::chrono::high_resolution_clock::now();
	}
	~Performance() {
		Stop();
		process_mem_usage();
	}

	void Stop() {
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimepoint);
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint);

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		auto ms = duration * 0.001;
		auto s = ms * 0.001;
		std::cout << duration << "us (" << ms << "ms) \n";
	}
	void process_mem_usage()
	{
		#if defined (_WIN32)
			PROCESS_MEMORY_COUNTERS mem;
			GetProcessMemoryInfo(GetCurrentProcess(), &mem, sizeof(mem));
			std::cout << "Memory use " << (size_t)info.WorkingSetSize / (t_size)1024 << "kB\n";
		#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
			int tSize = 0, resident = 0;
			std::ifstream buffer("/proc/self/statm");
			buffer >> tSize >> resident;
			buffer.close();

			long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024;
			double rss = resident * page_size_kb;
			std::cout << "Memory use " << rss << "kB\n";
		#endif
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint;
};