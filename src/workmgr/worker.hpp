#pragma once

#include <sys/wait.h>
#include <sys/shm.h>
#include <iostream>
#include <thread>

typedef struct WorkerData WorkerData;
typedef void (*Job)(WorkerData*, void*);

struct WorkerData {
	bool wait; // true, if the process is terminating itself
	bool exit; // true, if no error occured

	WorkerData() {
		wait = 0;
		exit = 0;
	}
};

class Worker {
private:
	WorkerData data;
	std::thread th;
	Job func; // function which is being executed ATM. 0 if none
public:
	Worker() {
		data = WorkerData();
	}

	~Worker() {
		stop();
		join();
	}

	bool active() {
		return func;
	}

	// Tries to run the payload function. Returns true if fails
	void run(Job payload, void* arg)
	{
		if (active()) throw std::runtime_error("Worker is busy.");
		data = WorkerData();
		
		func = payload;
		th = std::thread(func, &data, arg);
		func = 0;
	}

	void join() {
		if (th.joinable()) th.join();
	}

	void stop() {
		if (func) data.wait = true;
	}
};
