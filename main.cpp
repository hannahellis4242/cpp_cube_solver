#include <iostream>

#include <sstream>
#include <optional>

#include "cube/Configuration.h"

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

std::string show_net(const cube::Configuration & x )
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

cube::Configuration solved()
{
	return {
        cube::Value::White,  //0
        cube::Value::White,  //1
        cube::Value::White,  //2
        cube::Value::White,  //3
        cube::Value::White,  //4
        cube::Value::White,  //5
        cube::Value::White,  //6
        cube::Value::White,  //7
        cube::Value::White,  //8
        cube::Value::Orange, //9
        cube::Value::Orange, //10
        cube::Value::Orange, //11
        cube::Value::Green,  //12
        cube::Value::Green,  //13
        cube::Value::Green,  //14
        cube::Value::Red,    //15
        cube::Value::Red,    //16
        cube::Value::Red,    //17
        cube::Value::Orange, //18
        cube::Value::Orange, //19
        cube::Value::Orange, //20
        cube::Value::Green,  //21
        cube::Value::Green,  //22
        cube::Value::Green,  //23
        cube::Value::Red,    //24
        cube::Value::Red,    //25
        cube::Value::Red,    //26
        cube::Value::Orange, //27
        cube::Value::Orange, //28
        cube::Value::Orange, //29
        cube::Value::Green,  //30
        cube::Value::Green,  //31
        cube::Value::Green,  //32
        cube::Value::Red,    //33
        cube::Value::Red,    //34
        cube::Value::Red,    //35
        cube::Value::Blue,   //36
        cube::Value::Blue,   //37
        cube::Value::Blue,   //38
        cube::Value::Blue,   //39
        cube::Value::Blue,   //40
        cube::Value::Blue,   //41
        cube::Value::Blue,   //42
        cube::Value::Blue,   //43
        cube::Value::Blue,   //44
        cube::Value::White,  //45
        cube::Value::Yellow, //46
        cube::Value::Yellow, //47
        cube::Value::Yellow, //48
        cube::Value::Yellow, //49
        cube::Value::Yellow, //50
        cube::Value::Yellow, //51
        cube::Value::Yellow, //52
        cube::Value::Yellow, //53
	};
}

int main()
{
	std::cout << show_net(solved()) << std::endl ;
	return 0 ;
}
