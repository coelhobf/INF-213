#ifndef RANGE_H
#define RANGE_H

class RangeIterator
{
    friend class Range;

private:
    int num;

public:
    int operator*() { return num; }
    int operator*() const { return num; }
    RangeIterator operator++() { return ++num; }
    bool operator!=(const RangeIterator &other);

    RangeIterator(int a): num(a) { }
};

class Range
{
public:
    friend RangeIterator;
	typedef RangeIterator iterator;

	Range(int a, int b): first(a), last(b) { }

	iterator begin() { return iterator(first); }
	iterator end() { return iterator(last+1); }

private:
	int first;
	int last;
};

bool RangeIterator::operator!=(const RangeIterator &other)
{
    return num != (*other);
}

#endif