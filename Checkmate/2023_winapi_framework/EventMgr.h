#pragma once
#include <functional>
class Object;
struct tEvent
{
	EVENT_TYPE eEve; // 이벤트 타입
	Object* Obj;
	OBJECT_GROUP ObjType;
};
class EventMgr
{
	SINGLE(EventMgr);
public:
	void Update();
	void DeleteObject(Object* _pObj);
	void DelayCallback(std::function<void()> callback);
private:
	void Excute(const tEvent& _eve);
private:
	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecDead;
	vector<std::function<void()>> m_vecCallback;
private:
	bool callbacks = false;
};

