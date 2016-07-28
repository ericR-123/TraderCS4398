/*

  FILE: processCSV.cpp
   
   Darren Rambaud
   July 25, 2016

   The implementation file for processCSV.cpp. The following lines of code
   process a Comma Separated Value (CSV) file.
 
   INVARIANT for processCSV class:
   (1) Values (strings, floats, integers) are imported/parsed from a CSV file
       into a 1D vector of struct objects
   (2) The initial header line of the CSV file is ignored.

*/

//#include "Bar.h"
#include "processCSV.h"
#include <iterator>
#include <fstream>
#include <sstream>

//
// FIXME 
//
processCSV::processCSV() : path("not-set"), delimiter(','), ignore(true)
{
}

//
// FIXME -- insert documentation
//
void processCSV::setIgnoreHeader(bool ignore)
{
   this->ignore = ignore;
}

//
// FIXME -- insert documentation
//
void processCSV::setPath(std::string path)
{
   this->path = path;
}

//
// FIXME -- insert documentation
//
void processCSV::setDelimiter(char delimiter)
{
   this->delimiter = delimiter;
}

//
// FIXME -- insert documentation
// 
std::string const& processCSV::operator[](std::size_t index) const
{
   return p_data[index];
}

//
// FIXME -- insert documentation
//
std::size_t processCSV::size() const
{
   return p_data.size();
}
   
//
// FIXME -- insert documentation
//
void processCSV::readNextRow(std::istream& str)
{
   std::string row;
   std::getline(str, row);

   std::stringstream lineStream(row);
   std::string cell;

   p_data.clear();
           
   while(std::getline(lineStream, cell, this->delimiter)){
      p_data.push_back(cell);
   }
}

//
// FIXME -- insert documentation
// 
float processCSV::conv_float(const std::string& s)
{
   std::stringstream ss(s);
   float convert;
        
   ss >> convert;
   return convert;
}
   
//
// FIXME -- insert documentation
//
int processCSV::conv_int(const std::string& s)
{
   std::stringstream ss(s);
   int convert;
 
   ss >> convert;
   return convert;
}

//
// FIXME -- insert documentation
//
std::istream& operator>>(std::istream& str, processCSV& data)
{
   data.readNextRow(str);
   return str;
}  

//
// FIXME -- insert documentation
// Invariant: Must have valid path set.
std::vector<Bar> processCSV::returnBarVector()
{ //previously (const std::string& path)

   Bar temp;
   std::vector<Bar> actual;

   std::ifstream file(path);
   if (!file){
      std::cerr << "ERROR: Unable to open file " << path << std::endl;
      std::exit(-1);
   }

   processCSV row;
   int counter = 0;
   
    while(file >> row){
       if (counter == 0 && ignore){// ignoring the header line of the .csv file
          ignore = false;
          continue;
       }

       temp.date = row[0]; //pushing data to temp struct
       temp.open = row.conv_float(row[1]);
       temp.high = row.conv_float(row[2]);
       temp.low = row.conv_float(row[3]); 
       temp.close = row.conv_float(row[4]);
       temp.volume = row.conv_int(row[5]);

       actual.push_back(temp);
    }
    
    return actual;
}