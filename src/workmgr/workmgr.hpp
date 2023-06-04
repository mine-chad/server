#pragma once

#include "worker.hpp"
#include <chrono>
#include <list>

#define THREADLIMIT_DEFAULT	5

class WorkMgr {
private:
	std::list<Worker> workers;
public:
	WorkMgr()
	{
		workers.resize(THREADLIMIT_DEFAULT);
	}
	// Retrieves the current thread limit value.
	int threadLimit()
	{
		return workers.size();
	}

	// Sets the thread limit to control the maximum number of threads that can be created.
	// * `lim`: The desired thread limit value.
	void setThreadLimit(int lim)
	{
		workers.resize(lim);
	}

	// Goes through the list and executes the functions
	void run(const std::list<std::pair<Job, void*>>& todo)
	{
		auto it = todo.begin();
		while (it != todo.end()) {
			for (auto &j : workers) {
				if (it == todo.end()) break;
				if (!j.active()) {
					j.run(it->first, it->second);
					it++;
				}
			std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
			}
		}
		
		// Wait till all workers will have their jobs finished
		for (auto &j : workers) {
			j.join();
		}
	}
};
