#ifndef __SPY_H__
#define __SPY_H__
#include <string>
#include <fstream>


class Spy {
public:
	//big 7 pointer_member
	Spy(int id, std::string& name, int gender, float credit, int dep);
	Spy(const Spy&);
	Spy(const Spy*);
	Spy(Spy&&)noexcept;// for vector
	Spy& operator=(const Spy&);
	Spy& operator=(const Spy*); // copy assign pass by pointer
	Spy& operator=(Spy&&) noexcept; //move assign
	void ShowInfo() const;
	[[nodiscard]] virtual std::string GetDepName() const; // virtual
	friend std::ostream& operator<<(std::ostream&, const Spy*); // 对象名写错了 :(
	void* operator new(size_t size); // 重载 new 
	void operator delete(void* p);	// 重载 delete
	virtual ~Spy();
	//attr
	int m_id{ 0 };		 //编号
	int m_gender{ 0 };	 //性别
	int m_dep_id{ 0 };	 //部门id
	float m_credit{ 0 }; //诚信度
	std::string m_name;	 //名字
};


class Undergraduate final : public Spy {
	using Spy::Spy;

public:
	[[nodiscard]] std::string GetDepName() const override; // 提醒有返回值
};


class Postgraduate final : public Spy {
	using Spy::Spy;

public:
	[[nodiscard]] std::string GetDepName() const override;
};

#endif
