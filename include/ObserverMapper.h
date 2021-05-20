#ifndef OBSERVERMAPPERDEF
#define OBSERVERMAPPERDEF

#include "Subject.h"
#include "Observer.h"

template <typename T>
class ObserverMapper
{
public:
	void registerObsv(Subject<T>* sub, Observer<T>* obs) const;

	void unregisterObsv(Subject<T>* sub, Observer<T>* obs) const;

};

template <typename T>
void ObserverMapper<T>::registerObsv(Subject<T>* sub, Observer<T>* obs) const
{
	sub->attachObserver(obs);
}

template <typename T>
void ObserverMapper<T>::unregisterObsv(Subject<T>* sub, Observer<T>* obs) const
{
	sub->detatchObserver(obs);
}

#endif