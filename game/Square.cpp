#include "Square.h"
Square::Square()
{
	Column = 0;
	Row = 0 ;
}
Square::~Square()
{

}
void Square::ChangeSquare(int c, int r)
{
	Column=c;
	Row=r;
}
Square::Square(int c, int r)
{
	Column=c;
	Row=r;
}
int Square::GetColumn()
{
	return Column;
}
int Square::GetRow()
{
	return Row;
}