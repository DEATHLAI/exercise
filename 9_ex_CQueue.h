#include <stack>
#include <stdexcept>
using std::stack;

template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
		while (stack1.size > 0){
			const T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}

	if (stack2.size() == 0)
		throw std::logic_error("queue is empty");

	T head = stack2.pop;
	stack2.pop();

	return head;
}
