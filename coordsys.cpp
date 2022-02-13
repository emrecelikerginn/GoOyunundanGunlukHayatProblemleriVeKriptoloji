#include "headers/coordsys.h"

CoordinateSystem::CoordinateSystem()
{
    for (int y = 0; y < 19; y++)
    {
        for (int x = 0; x < 19; x++)
        {
            m_map[y][x] = 0;
            m_result[y][x] = 0;
        }
    }
}

void CoordinateSystem::SetCoord(int x, int y)
{
    m_map[y][x] = 1;
}

int* CoordinateSystem::GetResults()
{
    int *ptr = new int(4000), size = 1;

    for (int y = 0; y < 19; y++)
    {
        for (int x = 0; x < 19; x++)
        {
            if (m_map[y][x] == 1)
            {
                if (m_map[y+1][x] == 0 && m_result[y+1][x] == 0 && y < 18)
                {
                    m_result[y+1][x] = 1;
                    *(ptr + size++) = x;
                    *(ptr + size++) = y+1;
                }

                if (m_map[y-1][x] == 0 && m_result[y-1][x] == 0 && y > 0)
                {
                    m_result[y-1][x] = 1;
                    *(ptr + size++) = x;
                    *(ptr + size++) = y-1;
                }

                if (m_map[y][x+1] == 0 && m_result[y][x+1] == 0 && x < 18)
                {
                    m_result[y][x+1] = 1;
                    *(ptr + size++) = x+1;
                    *(ptr + size++) = y;
                }

                if (m_map[y][x-1] == 0 && m_result[y][x-1] == 0 && x > 0)
                {
                    m_result[y][x-1] = 1;
                    *(ptr + size++) = x-1;
                    *(ptr + size++) = y;
                }
            }
        }
    }

    *ptr = size;
    return ptr;
}