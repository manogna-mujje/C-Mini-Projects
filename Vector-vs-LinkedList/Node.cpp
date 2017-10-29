#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(const long the_value)
{
	value = the_value;
	next = nullptr;
	constructor_count++;
}

Node::Node(const Node& other)
{
	value = other.value;
	next = other.next;
	copy_count++;
}

Node::~Node()
{
	destructor_count++;
}

long Node::get_value() const
{
	return value;
}

void Node::set_value(long val)
{
	value = val ;
}

long Node::get_constructor_count()
{
	return constructor_count;
}

long Node::get_copy_count()
{
	return copy_count;
}

long Node::get_destructor_count()
{
	return destructor_count;
}

void Node::reset()
{
	constructor_count = 0;
	copy_count = 0;
	destructor_count= 0;
}

bool Node::operator ==(const Node& other) const
{
	return (value == other.value && next == other.next);
}

bool Node::operator  >(const Node& other) const
{
	return(value > other.value);
}

long Node::constructor_count = 0;

long Node::copy_count = 0;

long Node::destructor_count = 0;

