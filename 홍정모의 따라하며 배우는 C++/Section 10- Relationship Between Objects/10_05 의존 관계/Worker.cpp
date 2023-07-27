#pragma once

#include "Worker.h"
#include "Timer.h"

// 시간을 재기 위해 Timer class를 사용함
void Worker::doSomething()
{
	Timer timer; // 시작 timer

	// do some work here

	timer.elapsed(); // 끝 timer and 경과기록
}
