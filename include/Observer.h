#ifndef OBSERVERDEF
#define OBSERVERDEF

template <typename T>
class Observer
{
protected:
	// std::set<Observer*> m_obeservers = {};

public:

	Observer(void) = default;

	virtual ~Observer();

	Observer(const Observer&) = delete;
	Observer(Observer&&)      = delete;

	Observer& operator=(const Observer&) = delete;
	Observer& operator=(Observer&&)      = delete;

	
	virtual void update(const T& s) = 0;

	// void attachObserver(Observer* o);

	// void detatchObserver(Observer* o);

	// void notify() const = 0;

};


template <typename T>
Observer<T>::~Observer()
{

}


#endif