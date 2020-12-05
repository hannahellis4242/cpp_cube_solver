#include <iostream>
#include <array>
#include <sstream>
#include <optional>

enum class Value{Red,Orange,Yellow,Green,Blue,White};

char show( const Value & value )
{
	switch(value)
	{
		case Value::Red :
			return 'R';
		case Value::Orange :
			return 'O';
		case Value::Yellow :
			return 'Y';
		case Value::Green :
			return 'G';
		case Value::Blue :
			return 'B';
		case Value::White :
			return 'W' ;
	}
	return '-';
}

using Configuration = std::array<Value,54>;

std::optional< int > index( const int row , const int col )
{
	if( row < 3 && col >= 3 && col <= 5 )
	{
		return row *3 + col - 3 ;
	}
	if( row >= 3 && row <= 5  )
	{
		return 9*(row - 3) + col ;
	}
	if( row < 12 && col >= 3 && col <= 5 )
	{
		return 3*(row-6) + col + 33 ;
	}
	return {};
}

std::string show_net(const Configuration & x )
{
	std::stringstream ss ;
	for( int row = 0 ; row < 12 ; ++row )
	{
		for( int col = 0 ; col < 8 ; ++col )
		{
			if( std::optional< int > i = index( row , col ) )
			{
				ss << *i << '\t' ;
			}
			else
			{
				ss << "-" << '\t' ;
			}
		}
		ss << std::endl ;
	}
	return ss.str() ;
	//first 3 rows
	for( int row = 0 ; row < 3 ; ++row )
	{
		ss << std::string(3,' ') ;
		for( int col = 0 ; col < 3 ; ++col )
		{
			ss<< show( x[row*3 + col] );
		}
		ss << std::string(3,' ') << std::endl ;
	}
	//next 3 rows
	for( int row = 3 ; row < 6 ; ++row)
	{
		for( int col = 0 ; col < 9 ; ++col )
		{
			ss << show( x[row*9 + col] );
		}
		ss << std::endl ;
	}
	for( int row = 6 ; row < 12 ; ++row )
	{
		ss << std::string(3,' ');
		for( int col = 0 ; col < 3 ; ++col )
		{
			ss << show( x[3*row + 18 + col] );
		}
		ss << std::string(3,' ') << std::endl ;
	}
	return ss.str() ;
}

Configuration solved()
{
	return {
        Value::White,  //0
        Value::White,  //1
        Value::White,  //2
        Value::White,  //3
        Value::White,  //4
        Value::White,  //5
        Value::White,  //6
        Value::White,  //7
        Value::White,  //8
        Value::Orange, //9
        Value::Orange, //10
        Value::Orange, //11
        Value::Green,  //12
        Value::Green,  //13
        Value::Green,  //14
        Value::Red,    //15
        Value::Red,    //16
        Value::Red,    //17
        Value::Orange, //18
        Value::Orange, //19
        Value::Orange, //20
        Value::Green,  //21
        Value::Green,  //22
        Value::Green,  //23
        Value::Red,    //24
        Value::Red,    //25
        Value::Red,    //26
        Value::Orange, //27
        Value::Orange, //28
        Value::Orange, //29
        Value::Green,  //30
        Value::Green,  //31
        Value::Green,  //32
        Value::Red,    //33
        Value::Red,    //34
        Value::Red,    //35
        Value::Blue,   //36
        Value::Blue,   //37
        Value::Blue,   //38
        Value::Blue,   //39
        Value::Blue,   //40
        Value::Blue,   //41
        Value::Blue,   //42
        Value::Blue,   //43
        Value::Blue,   //44
        Value::White,  //45
        Value::Yellow, //46
        Value::Yellow, //47
        Value::Yellow, //48
        Value::Yellow, //49
        Value::Yellow, //50
        Value::Yellow, //51
        Value::Yellow, //52
        Value::Yellow, //53
	};
}

int main()
{
	std::cout << show_net(solved()) << std::endl ;
	return 0 ;
}
