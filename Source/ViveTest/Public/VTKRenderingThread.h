// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#pragma once

/**
 * 
 */
class VIVETEST_API VTKRenderingThread : public FRunnable
{
	
	/** Singleton instance, can access the thread any time via static accessor, if it is active! */
	static VTKRenderingThread* Runnable;

	/** Thread to run the worker FRunnable on */
	FRunnableThread* Thread;

	//The actual finding of prime numbers
	int32 FindNextPrimeNumber();

	bool finished;

	//Done?
	bool IsFinished() const
	{
		return finished;
	}

	//~~~ Thread Core Functions ~~~

	//Constructor / Destructor
	VTKRenderingThread();
	virtual ~VTKRenderingThread();

public:
	// Begin FRunnable interface.
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	/** Makes sure this thread has stopped properly */
	void EnsureCompletion();

	static VTKRenderingThread* StaticInit();

	//~~~ Starting and Stopping Thread ~~~

	/** Shuts down the thread. Static so it can easily be called from outside the thread context */
	static void Shutdown();

	static bool IsThreadFinished();

};