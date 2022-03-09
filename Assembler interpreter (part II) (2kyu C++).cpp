#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

static void setReg(unordered_map<string, int>& regs, const string name, const int value)
{
    regs[name] = value;
}

static int getReg(unordered_map<string, int>& regs, const string name)
{
    return regs[name];
}

vector<string> split(const string& _string) 
{
    vector<string> splited_string;
    string word = "";
    
    for (const char letter : _string) {
        if (letter == ' ') {
            splited_string.push_back(word);
            word = "";
        } else {
            word += letter;
        }
    }
      
    if (word != "") 
        splited_string.push_back(word);
  
    return splited_string;
}

bool isDigit (const string& _string)
{
    for (const char& letter : _string) {
        if (!(('0' <= letter and letter <= '9') or letter == '-' or letter == '+'))
            return false;
    }
  
    return true;
}

int toInt(const string& _string)
{
    bool sign = true;
    int number = 0;
  
    for (const char& digit : _string) {
        if (digit == '-') {
            sign = false;
        } else {
            number *= 10;
            number += (int)(digit - '0');
        }
    }
  
    return sign ? number : -number;
}

int toInt(const int& _int) 
{
  return _int;
}

unordered_map<string, int> assembler(const vector<string>& program)
{
  unordered_map<string, int> _register;
  unsigned long command_line = 0;
  
  vector<vector<string>> parsed_program;
  
  for (const string& str : program) {
      parsed_program.push_back( split(str) );
  }
  
  while (true) {
    
      if (command_line >= program.size() or program.size() == 0 or command_line < 0)
          break;
    
      vector<string> split_command = parsed_program[command_line];
      
      if (split_command[0] == "mov") {
          if (isDigit(split_command[2])) {
              setReg(_register, split_command[1], toInt(split_command[2]));
          } else {
              setReg(_register, split_command[1], getReg(_register, split_command[2]));
          }
        
          command_line++;
      } else if (split_command[0] == "inc") {
          setReg(_register, split_command[1], getReg(_register, split_command[1]) + 1);
        
          command_line++;
      } else if (split_command[0] == "dec") {
          setReg(_register, split_command[1], getReg(_register, split_command[1]) - 1);
        
          command_line++;
      } else if (split_command[0] == "jnz") {
          if ( isDigit(split_command[1]) and isDigit(split_command[2]) ) {
              if (toInt(split_command[1])) {
                  command_line += toInt(split_command[2]);
              } else {
                  command_line++;
              }
          } else if (isDigit(split_command[1])) {
              if (toInt(split_command[1])) {
                  command_line += getReg(_register, split_command[2]);
              } else {
                  command_line++;
              }
          } else if (isDigit(split_command[2])) {
              if (getReg(_register, split_command[1])) {
                  command_line += toInt(split_command[2]);
              } else {
                  command_line++;
              }
          } else {
              if (getReg(_register, split_command[1])) {
                  command_line += getReg(_register, split_command[2]);
              } else {
                  command_line++;
              }
          }
      }
    
  }
  
  return _register;
}
