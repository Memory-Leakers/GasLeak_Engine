#ifndef _TIMER_H_
#define _TIMER_H_

#include "Globals.h"
#include "SDL/include/SDL.h"

class Timer
{
private:

	float mStartTicks;
	float mElapsedTicks;
	float mDeltaTime;
	float mTimeScale;
	float lastTime = 0;

public:

	Timer()
	{
		Reset();
		mTimeScale = 1.0f;
	}

	~Timer()
	{
	}

	void Reset()
	{
		mStartTicks = SDL_GetTicks();
		mElapsedTicks = 0;
		mDeltaTime = 0.0f;
	}

	float getDeltaTime()
	{
		return mDeltaTime;
	}

	void setTimeScale(float t)
	{
		mTimeScale = t;
	}

	float getTimeScale()
	{
		return mTimeScale;
	}

	float getExecuteTime(bool second = false)
	{
		if (second)
		{
			return  (SDL_GetTicks() - (SDL_GetTicks() % 1000)) * 0.001f;
		}

		return SDL_GetTicks();
	}

	float Update()
	{
		float frame2frame = SDL_GetTicks() - lastTime;
		lastTime = SDL_GetTicks();

		mElapsedTicks = SDL_GetTicks() - mStartTicks;
		mDeltaTime = mElapsedTicks * 0.001f;

		//printf("Frame2Frame : %f\tElapsedTicks : %f\tStart Ticks: %f\n", frame2frame, mElapsedTicks, mStartTicks);

		return (frame2frame * 0.001f);
	}

};

#endif
