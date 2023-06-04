#pragma once

#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>

typedef bool (*Job)(bool*, void*);

struct WorkerData {
	Job func; // function which is being executed ATM. 0 if none
	bool wait; // true, if the process is terminating itself
	bool exit; // true, if no error occured

	void clear() {
		func = 0;
		wait = 0;
		exit = 0;
	}
};

class Worker {
private:
	WorkerData *data;
	
	int shmid;
	pid_t pid;
public:
	Worker()
	{
		pid = 0;
		shmid = shmget(IPC_PRIVATE, sizeof(WorkerData), IPC_CREAT | 0666);
		
		if (shmid == -1) 
			throw std::runtime_error("Failed to create shared memory segment.");

		data = (WorkerData*)shmat(shmid, nullptr, 0);
		if (data == (WorkerData*)-1)
			throw std::runtime_error("Failed to attach shared memory.");

		data->clear();
	}

	~Worker()
	{
		shmctl(shmid, IPC_RMID, nullptr);
		if (data->func) kill(pid, 9);
		//if (kill(pid, 0) == 0) kill(pid, 9);
	}

	bool active()
	{
		return data->func;
	}

	// Tries to run the payload function. Returns true if fails
	bool run(Job payload, void* arg)
	{
		if (active()) return 1;
		data->clear();
		data->func = payload;
		
		pid_t _pid;
		switch(_pid = fork()) {
			case -1:
				throw std::runtime_error("Failed to create a new process.");
				return 1;
			case 0: // child
				data->exit = data->func(&data->wait, arg);
				data->func = 0;
				shmdt(data);
				std::exit(0);
			default: // parent
				pid = _pid;
				return data;
		}
	}

	void stop() {
		if (data->func) data->wait = true;
	}
};
