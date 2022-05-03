#ifndef COORDSYS_H_INCLUDED
#define COORDSYS_H_INCLUDED

class CoordinateSystem
{
    private:
    int m_map[19][19];
    int m_result[19][19];

    public:
    CoordinateSystem();
    void SetCoord(int x, int y);
    int* GetResults();
};

#endif
