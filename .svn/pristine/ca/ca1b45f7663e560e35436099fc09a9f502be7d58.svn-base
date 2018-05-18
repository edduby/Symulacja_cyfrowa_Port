/********************************************//**
* \file   events.h
* \brief  Time event.
* \author Maciej Maciejewski
* \date   2015-04-15
***********************************************/
#ifndef EVENTS_H
#define EVENTS_H
/////////////////////////////////////////////////
/*! \brief Client arrives time event.
*
* This time event implements the actions required when a new client arrives.
*/


class pojawienieSieStatku :public Event
{
public:
	ofstream model_stats;
	//! Constructor.
	pojawienieSieStatku(double in_lambda,int in_seed);
	
	//! Destructor.
	~pojawienieSieStatku(){};

	//! Execute a time event.
	void execute();
private:


	double lambda;	//!< Exponential distribution parameter.
	int seed;
};
/*! \brief Client departure time event.
*
* This time event implements the actions required when a client departures from the service station.
*/
class wyplyniecieZToru : public Event
{
public:

	//! Constructor.
	wyplyniecieZToru(double in_czas,Statek* in_StatekPlynie);
	~wyplyniecieZToru(){};
	//! Execute a time event.
	void execute();

private:

	double czas;	//!< 
	Statek *StatekPlynie;
};


class konczenieObslugi : public Event
{
public:

	//! Constructor.
	konczenieObslugi(double in_czas,Statek* in_statek);

	//! Destructor.
	~konczenieObslugi(){};

	//! Execute a time event.
	void execute();

private:

	double czas;
	Statek *StatekPlynie;
};



class opuszczenieToru : public Event
{
public:

	//! Constructor.
	opuszczenieToru(double in_czas, Statek* in_statek);

	//! Destructor.
	~opuszczenieToru(){};

	//! Execute a time event.
	void execute();

private:

	double czas;
	Statek *StatekPlynie;
	
};




















/////////////////////////////////////////////////
//***********************************************
#endif /*EVENTS_H*/
