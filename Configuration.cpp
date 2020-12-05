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

Configuration top_twist_right(const Configuration &c)
  {
    return {c[2], c[5], c[8], c[1], c[4], c[7], c[0], c[3], c[6], c[53], c[52], c[51],
        c[9], c[10], c[11], c[12], c[13], c[14], c[18], c[19], c[20], c[21], c[22],
        c[23], c[24], c[25], c[26], c[27], c[28], c[29], c[30], c[31], c[32], c[33],
        c[34], c[35], c[36], c[37], c[38], c[39], c[40], c[41], c[42], c[43], c[44],
        c[45], c[46], c[47], c[48], c[49], c[50], c[17], c[16], c[15],
    };
  }
    Configuration top_twist_left(const Configuration &c) {
  return {
          c[6], c[3], c[0], c[7], c[4], c[1], c[8], c[5], c[2], c[12], c[13], c[14],
          c[15], c[16], c[17], c[53], c[52], c[51], c[18], c[19], c[20], c[21], c[22],
          c[23], c[24], c[25], c[26], c[27], c[28], c[29], c[30], c[31], c[32], c[33],
          c[34], c[35], c[36], c[37], c[38], c[39], c[40], c[41], c[42], c[43], c[44],
          c[45], c[46], c[47], c[48], c[49], c[50], c[11], c[10], c[9],
  };
  }
  Configuration front_twist_right(const Configuration &c) {
  return {
          c[0], c[1], c[2], c[3], c[4], c[5], c[29], c[20], c[11], c[9], c[10], c[36],
          c[30], c[21], c[12], c[6], c[16], c[17], c[18], c[19], c[37], c[31], c[22],
          c[13], c[7], c[25], c[26], c[27], c[28], c[38], c[32], c[23], c[14], c[8],
          c[34], c[35], c[15], c[24], c[33], c[39], c[40], c[41], c[42], c[43], c[44],
          c[45], c[46], c[47], c[48], c[49], c[50], c[51], c[52], c[53],
  };
  }
  Configuration front_twist_left(const Configuration &c) {
  return {
          c[0], c[1], c[2], c[3], c[4], c[5], c[15], c[24], c[33], c[9], c[10], c[8],
          c[14], c[23], c[32], c[38], c[16], c[17], c[18], c[19], c[7], c[13], c[22],
          c[31], c[37], c[25], c[26], c[27], c[28], c[6], c[12], c[21], c[30], c[36],
          c[34], c[35], c[11], c[20], c[29], c[39], c[40], c[41], c[42], c[43], c[44],
          c[45], c[46], c[47], c[48], c[49], c[50], c[51], c[52], c[53],
  };
  }
  Configuration right_twist_front(const Configuration &c) {
  return {
          c[0], c[1], c[47], c[3], c[4], c[50], c[6], c[7], c[53], c[9], c[10], c[11],
          c[12], c[13], c[2], c[17], c[26], c[35], c[18], c[19], c[20], c[21], c[22],
          c[5], c[16], c[25], c[34], c[27], c[28], c[29], c[30], c[31], c[8], c[15],
          c[24], c[33], c[36], c[37], c[14], c[39], c[40], c[23], c[42], c[43], c[32],
          c[45], c[46], c[38], c[48], c[49], c[41], c[51], c[52], c[44],
  };
  }
  Configuration right_twist_back(const Configuration &c) {
  return {
          c[0], c[1], c[14], c[3], c[4], c[23], c[6], c[7], c[32], c[9], c[10], c[11],
          c[12], c[13], c[38], c[33], c[24], c[15], c[18], c[19], c[20], c[21], c[22],
          c[41], c[34], c[25], c[16], c[27], c[28], c[29], c[30], c[31], c[44], c[35],
          c[26], c[17], c[36], c[37], c[47], c[39], c[40], c[50], c[42], c[43], c[53],
          c[45], c[46], c[2], c[48], c[49], c[5], c[51], c[52], c[8],
  };
  }
  Configuration bottom_twist_right(const Configuration &c) {
  return {
          c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11],
          c[12], c[13], c[14], c[15], c[16], c[17], c[18], c[19], c[20], c[21], c[22],
          c[23], c[24], c[25], c[26], c[47], c[46], c[45], c[27], c[28], c[29], c[30],
          c[31], c[32], c[42], c[39], c[36], c[43], c[40], c[37], c[44], c[41], c[38],
          c[35], c[34], c[33], c[48], c[49], c[50], c[51], c[52], c[53],
  };
  }
  Configuration bottom_twist_left(const Configuration &c) {
  return {
          c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11],
          c[12], c[13], c[14], c[15], c[16], c[17], c[18], c[19], c[20], c[21], c[22],
          c[23], c[24], c[25], c[26], c[30], c[31], c[32], c[33], c[34], c[35], c[47],
          c[46], c[45], c[38], c[41], c[44], c[37], c[40], c[43], c[36], c[39], c[42],
          c[29], c[28], c[27], c[48], c[49], c[50], c[51], c[52], c[53],
  };
  }
  Configuration back_twist_right(const Configuration &c) {
  return {
          c[27], c[18], c[9], c[3], c[4], c[5], c[6], c[7], c[8], c[42], c[10], c[11],
          c[12], c[13], c[14], c[15], c[16], c[0], c[43], c[19], c[20], c[21], c[22],
          c[23], c[24], c[25], c[1], c[44], c[28], c[29], c[30], c[31], c[32], c[33],
          c[34], c[2], c[36], c[37], c[38], c[39], c[40], c[41], c[35], c[26], c[17],
          c[47], c[50], c[53], c[46], c[49], c[52], c[45], c[48], c[51],
  };
  }
  Configuration back_twist_left(const Configuration &c) {
  return {
          c[17], c[26], c[35], c[3], c[4], c[5], c[6], c[7], c[8], c[2], c[10], c[11],
          c[12], c[13], c[14], c[15], c[16], c[44], c[1], c[19], c[20], c[21], c[22],
          c[23], c[24], c[25], c[43], c[0], c[28], c[29], c[30], c[31], c[32], c[33],
          c[34], c[42], c[36], c[37], c[38], c[39], c[40], c[41], c[9], c[18], c[27],
          c[51], c[48], c[45], c[52], c[49], c[46], c[53], c[50], c[47],
  };
  }
  Configuration left_twist_front(const Configuration &c) {
  return {
          c[45], c[1], c[2], c[48], c[4], c[5], c[51], c[7], c[8], c[27], c[18], c[9],
          c[0], c[13], c[14], c[15], c[16], c[17], c[28], c[19], c[10], c[3], c[22],
          c[23], c[24], c[25], c[26], c[29], c[20], c[11], c[6], c[31], c[32], c[33],
          c[34], c[35], c[12], c[37], c[38], c[21], c[40], c[41], c[30], c[43], c[44],
          c[36], c[46], c[47], c[39], c[49], c[50], c[42], c[52], c[53],
  };
  }
  Configuration left_twist_back(const Configuration &c) {
  return {
          c[12], c[1], c[2], c[21], c[4], c[5], c[30], c[7], c[8], c[11], c[20], c[29],
          c[36], c[13], c[14], c[15], c[16], c[17], c[10], c[19], c[28], c[39], c[22],
          c[23], c[24], c[25], c[26], c[9], c[18], c[27], c[42], c[31], c[32], c[33],
          c[34], c[35], c[45], c[37], c[38], c[48], c[40], c[41], c[51], c[43], c[44],
          c[0], c[46], c[47], c[3], c[49], c[50], c[6], c[52], c[53],
  };
  }
}
