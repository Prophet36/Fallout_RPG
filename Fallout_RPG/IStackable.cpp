#include "stdafx.h"
#include "IStackable.h"

IStackable::IStackable(int count, int stack) : m_count(count), m_stack(stack)
{
}

int IStackable::setCount(int count)
{
    if (count > m_stack)
    {
        m_count = m_stack;
        return count - m_stack;
    }
    m_count = count;
    return 0;
}
