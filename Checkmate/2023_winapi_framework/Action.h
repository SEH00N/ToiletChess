#pragma once
#include <functional>
#include<vector>
template <typename T>
class Action
{
public:
	Action();
	~Action();

private:
	std::vector<std::function<void(T)>> events;

public:
	void Invoke(T item);
	void RegisterEvent(std::function<void(T)> event);
	void UnregisterEvent(std::function<void(T)> event);
};

template<typename T>
inline Action<T>::Action()
{
}

template<typename T>
inline Action<T>::~Action()
{
	for (auto i = events.begin(); i != events.end(); ++i)
		i = events.erase(i);

	events.clear();
}

template<typename T>
inline void Action<T>::Invoke(T item)
{
	for (auto i = events.begin(); i != events.end(); ++i)
		i(item);
}

template<typename T>
inline void Action<T>::RegisterEvent(std::function<void(T)> event)
{
	events.push_back(event);
}

template<typename T>
inline void Action<T>::UnregisterEvent(std::function<void(T)> event)
{
	auto iter = events.find(event);
	if (iter != events.end())
		events.erase(iter);
}
