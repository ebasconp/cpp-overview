#pragma once


class IClass
{
public:
	virtual ~IClass() = default;

	virtual void print() const = 0;
};