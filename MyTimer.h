#ifndef MYTIMER_H_
#define MYTIMER_H_

class MyTimer
{
	public :
		MyTimer (void);
		int start (void);
		int stop (void);
		int restart (void);
		uint32_t getValue (void);

	private :
		unsigned long base_value;
		unsigned long last_value;
		uint32_t stopped;
};

#endif /* MYTIMER_H_ */
