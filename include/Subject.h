#ifndef SUBJECTDEF
#define SUBJECTDEF



#include "Observer.h"
#include <set>


template <typename T>
class Subject
{
protected:
	std::set<Observer<T>*> m_observers = {};

public:

	Subject(void) = default;

	virtual ~Subject();

	Subject(const Subject&) = delete;
	Subject(Subject&&)      = delete;

	Subject& operator=(const Subject&) = delete;
	Subject& operator=(Subject&&)      = delete;

	virtual void notify() const = 0;

	void attachObserver(Observer<T>* o);

	void detatchObserver(Observer<T>* o);

};

template <typename T>
Subject<T>::~Subject()
{

}

template <typename T>
void Subject<T>::attachObserver(Observer<T>* o)
{
	m_observers.emplace(o);
}

template <typename T>
void Subject<T>::detatchObserver(Observer<T>* o)
{
	for(auto& i : m_observers)
	{
		if(i == o)
		{
			m_observers.erase(i);
			return;
		}
	}

};

#endif