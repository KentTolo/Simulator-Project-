#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<bitset>

using namespace std;

// Structure to represent MIPS opcodes
struct OPCODE
{
    string opcodeStr;
    bitset<6> opcodeInt;
};

// Structure to represent MIPS registers
struct RegProfile  
{
    string registers;   // Format: $r1, $s2, $t2
    bitset<5> regAddress;   // Format: 00110
};

int main()
{
    // Initializing MIPS opcodes
    OPCODE ADD { "add", bitset<6>(0b000000) };
    OPCODE DIV { "div", bitset<6>(0b000001) };
    OPCODE BRANCH { "branch", bitset<6>(0b000100) };
    OPCODE JUMP { "jump", bitset<6>(0b001000) };
    OPCODE LOAD { "load", bitset<6>(0b010000) };
    OPCODE AND { "and", bitset<6>(0b000010) };
  
    // Creating an array of opcodes
    OPCODE arrayOp[6] = { ADD, DIV, BRANCH, JUMP, LOAD, AND };

    // Initializing MIPS registers
    RegProfile t0 { "$t0,", bitset<5>(0b00001) };
    RegProfile t1 { "$t1,", bitset<5>(0b00010) };
    RegProfile t2 { "$t2,", bitset<5>(0b00011) };
    RegProfile t3 { "$t3,", bitset<5>(0b00100) };
    RegProfile s0 { "$s0,", bitset<5>(0b00101) };
    RegProfile s1 { "$s1,", bitset<5>(0b00110) };
    RegProfile s2 { "$s2,", bitset<5>(0b00111) };
    RegProfile s3 { "$s3,", bitset<5>(0b01000) };
    RegProfile v0 { "$v0,", bitset<5>(0b01001) };
    RegProfile v1 { "$v1,", bitset<5>(0b01010) };
    RegProfile a0 { "$a0,", bitset<5>(0b01100) };
    RegProfile a1 { "$a1,", bitset<5>(0b01101) };
    RegProfile a2 { "$a2,", bitset<5>(0b01110) };
    RegProfile a3 { "$a3,", bitset<5>(0b01110) };
    RegProfile zero { "$zero,", bitset<5>(0b01111)};
    
    // Creating an array of registers
    RegProfile arrayReg[14] = { t0, t1, t2, t3, s0, s1, s2 , s3 , v0, v1, a0, a1, a3, zero}; 
  
  	
    ifstream in_file("mipsinstruction.txt"); // read from file

    if (!in_file.is_open())
    {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    string readString;

    while (getline(in_file, readString)) // read from input stream in_file and store into string readString
    {
        istringstream iss(readString); // treat string as an input stream

        string command, operand1, operand2, operand3;
        bitset<6> temp0;
        bitset<5> temp1, temp2, temp3;
        if (getline(iss, command, ' ') && getline(iss, operand1, ' ') && getline(iss, operand2, ' ') && getline(iss, operand3))
        {
          	// Find the corresponding opcode for the command
          	for(int i = 0; i< 6; i++)
            {
            	if(command == arrayOp[i].opcodeStr)
              {
                temp0 = arrayOp[i].opcodeInt;
							}
            }
            
          	// Find the corresponding register address for operand1
          	for(int l = 0; l< 14; l++)
            {
            	if(operand1 == arrayReg[l].registers)
              {
                 temp1 = arrayReg[l].regAddress;
							}
            }
          
          	// Find the corresponding register address for operand2
          	for(int r = 0; r< 14; r++)
            {
            	if(operand2 == arrayReg[r].registers)
              {
                temp2= arrayReg[r].regAddress;
							}
            }
          
          	// Find the corresponding register address for operand3
          	for(int t = 0; t< 14; t++)
            {
            	if(operand3 == arrayReg[t].registers)
              {
                temp3 = arrayReg[t].regAddress;
							}
            }

            // Print the opcode and register addresses
            cout << " opcode "<<  " rs \t" << " rt "<<"\trd "<<endl;
            cout << temp0 << " | "<< temp1 << " | "<<temp2 << " | "<<temp3 <<endl;
          	
        }
        else
        {
            cerr << "Error parsing line: " << readString << endl;
        }
    }

    in_file.close();

    return 0;
}
