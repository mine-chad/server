/*
 * Copyright (C) 2023 mine-chad
 * This file is part of the Mine-chad project.
 *
 * Mine-chad is free software: you can redistribute it and/or modify it under
 * the terms of the MIT License.
 *
 * Mine-chad is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the MIT License for more details.
 *
 * You should have received a copy of the MIT License along with Mine-chad. If
 * not, see <https://mit-license.org/> or contact the Massachusetts Institute
 * of Technology (MIT) at <tlo-inquiries@mit.edu>.
 */

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
