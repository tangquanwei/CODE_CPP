#ifndef __LIST_H__
#define __LIST_H__
template <class T>
class List {
public:
	/* Init List */
	List() = default;
	/* Create List */
	virtual List& create(unsigned int) = 0;
	/* Print List */
	// friend std::ostream& operator<<(std::ostream& os, List l);
	/* Length */
	virtual unsigned int size() = 0;
	/* Located */
	virtual int indexOf(const T& t) = 0;
	/* Get */
	virtual T& at(unsigned int x) = 0;
	/* Insert */
	virtual void insert(unsigned int i, const T& t) = 0;
	/**
	 * Delete
	 * @param index
	 * @return T or nullptr
	 */
	virtual T& remove(unsigned int i) = 0;
	/**
	 * Empty
	 */
	virtual bool empty() = 0;
	/* Destroy List */
	virtual ~List();
};



#endif