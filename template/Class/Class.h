/**
 * @file Class.h
 */
#ifndef CLASS_H
#define CLASS_H

class ClassName
{
	public:
		explicit ClassName();
		virtual ~ClassName();

	private:
		ClassName(const ClassName&);
		ClassName& operator=(const ClassName&);
};


#endif
