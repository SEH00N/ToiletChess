#include "pch.h"
#include "EventMgr.h"
#include "Object.h"
void EventMgr::Update()
{
	for (size_t i = 0; i < m_vecDead.size(); ++i)
	{
		if(m_vecDead[i])
			delete m_vecDead[i];
	}
	m_vecDead.clear();

	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}
	m_vecEvent.clear();

	if (callbacks == true)
	{
		for (size_t i = 0; i < m_vecCallback.size(); ++i)
		{
			if (m_vecCallback[i])
				m_vecCallback[i]();
		}
		m_vecCallback.clear();
		callbacks = false;
	}
}

void EventMgr::DeleteObject(Object* _pObj)
{
	tEvent eve = {};
	eve.eEve = EVENT_TYPE::DELETE_OBJECT;
	eve.Obj = _pObj;
	m_vecEvent.push_back(eve);
}

void EventMgr::DelayCallback(std::function<void()> callback)
{
	tEvent eve = {};
	eve.eEve = EVENT_TYPE::DELAY_FRAME;
	m_vecCallback.push_back(callback);
	m_vecEvent.push_back(eve);
}

void EventMgr::Excute(const tEvent& _eve)
{
	switch (_eve.eEve)
	{
	case EVENT_TYPE::DELETE_OBJECT:
	{
		Object* pDeadObj = _eve.Obj;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;
	case EVENT_TYPE::CREATE_OBJECT:
		break;
	case EVENT_TYPE::SCENE_CHANGE:
		break;
	case EVENT_TYPE::DELAY_FRAME:
		callbacks = true;
		break;
	}
}
