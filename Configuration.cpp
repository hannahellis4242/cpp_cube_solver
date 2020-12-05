#include "Configuration.h"
#include <sstream>

namespace cube
{
  std::string show_net(const Configuration & x )
  {
  	std::stringstream ss ;
  	ss << "-\t-\t-\t" << show( x[0] ) << '\t' << show( x[1] ) << '\t' << show( x[2] ) << "\t-\t-\t-\n";
  	ss << "-\t-\t-\t" << show( x[3] ) << '\t' << show( x[4] ) << '\t' << show( x[5] ) << "\t-\t-\t-\n";
  	ss << "-\t-\t-\t" << show( x[6] ) << '\t' << show( x[7] ) << '\t' << show( x[8] ) << "\t-\t-\t-\n";

  	ss << show( x[9] ) << '\t' << show( x[10] ) << '\t' << show( x[11] ) << '\t'
  		 << show( x[12] ) << '\t' << show( x[13] ) << '\t' << show( x[14] ) << '\t'
  		 << show( x[15] ) << '\t' << show( x[16] ) << '\t' << show( x[17] ) << '\n';
  	ss << show( x[18] ) << '\t' << show( x[19] ) << '\t' << show( x[20] ) << '\t'
  		 << show( x[21] ) << '\t' << show( x[22] ) << '\t' << show( x[23] ) << '\t'
  		 << show( x[24] ) << '\t' << show( x[25] ) << '\t' << show( x[26] ) << '\n';
  	ss << show( x[27] ) << '\t' << show( x[28] ) << '\t' << show( x[29] ) << '\t'
  	 	 << show( x[30] ) << '\t' << show( x[31] ) << '\t' << show( x[32] ) << '\t'
  	 	 << show( x[33] ) << '\t' << show( x[34] ) << '\t' << show( x[35] ) << '\n';

  	ss << "-\t-\t-\t" << show( x[36] ) << '\t' << show( x[37] ) << '\t' << show( x[38] ) << "\t-\t-\t-\n";
  	ss << "-\t-\t-\t" << show( x[39] ) << '\t' << show( x[40] ) << '\t' << show( x[41] ) << "\t-\t-\t-\n";
  	ss << "-\t-\t-\t" << show( x[42] ) << '\t' << show( x[43] ) << '\t' << show( x[44] ) << "\t-\t-\t-\n";

  	ss << "-\t-\t-\t" << show( x[45] ) << '\t' << show( x[46] ) << '\t' << show( x[47] ) << "\t-\t-\t-\n";
  	ss << "-\t-\t-\t" << show( x[48] ) << '\t' << show( x[49] ) << '\t' << show( x[50] ) << "\t-\t-\t-\n";
  	ss << "-\t-\t-\t" << show( x[51] ) << '\t' << show( x[52] ) << '\t' << show( x[53] ) << "\t-\t-\t-\n";

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
}
