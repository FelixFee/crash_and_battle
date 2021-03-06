#include "backTimerQueue.h"

bool backTimerQueue::push(timerEvent * p)
{
	if (!p)
		return false;
	wheel.push(p);
}

timerEvent * backTimerQueue::pop()
{
	timerEvent* res = top();
	if (res)
		wheel.pop();
	return res;
}

timerEvent * backTimerQueue::top()
{
	if (size() == 0)
		return nullptr;
	return wheel.top();
}

bool backTimerQueue::countdown()
{
	if (wheel.top()->getTime() == 0)
		return false;
	priority_queue<timerEvent*, vector<timerEvent*>, cmp> temp;
	while (wheel.size() != 0)
	{
		timerEvent* p = wheel.top();
		wheel.pop();
		p->countdown();
		temp.push(p);
	}
	wheel = temp;
	return true;
}
