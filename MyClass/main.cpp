#include "main.hpp"

/* pass by reference */
void print(Shape::Circle& c) {
	std::cout << c.getArea() << std::endl;
}
/* pass by pointer */
void print(Shape::Circle* c) {
	std::cout << c->getArea() << std::endl;
}
int main() {
	// unsigned n{3};
	// virt::Shape *p[n]{
	//     new virt::Circle(),
	//     new virt::Rectangle(),
	//     new virt::Triangle()};
	// for (int i = 0; i < n; ++i)
	// {
	//     std::cout << "area = " << p[i]->area() << '\n';
	//     std::cout << "length = " << p[i]->length() << '\n';
	// }
	// delete[] p;
	// virt::Body *q[n]{new virt::Sphere(),
	//                  new virt::Tetrahedron()};
	// std::for_each(q, q + 2, [](virt::Body *b)
	//               {
	//                   std::cout << b->surarea() << '\n';
	//                   std::cout << b->volume() << '\n';
	//               });
	// delete[] q;
	// std::vector<virt::Shape *> v{new virt::Circle(),
	//                              new virt::Rectangle(),
	//                              new virt::Triangle()};
	// for (auto i : v)
	// {
	//     std::cout << i->area() << '\n';
	//     std::cout << i->length() << '\n';
	//     delete i;
	// }

	// for (auto i : v)
	// {
	//     std::cout << i->area() << '\n';
	//     std::cout << i->length() << '\n';

	using namespace Pointer_like_Class;
	SharedPtr<Shape::Circle> sp{ new Shape::Circle(10) };
	std::cout << sp->getArea();


	return 0;
}