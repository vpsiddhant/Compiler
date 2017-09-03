#include<iostream>
#include<string.h>

#define EOF "EOF"
#define INTEGER "INTEGER"
#define PLUS "PLUS"


//THIS IS MADE TO TO CHECK WHETHER THE CHARACTER IS A NUMBER OR NOT
bool isNumber(char value)
{
	int number;
	number = value;
	
	for( int i = 0; i < 10; i ++)
	{
		if ( number == 48 + i)
		{
			return true;
		}
	}
	
	return false;
	
}


class Token
{
	public:
	std::string type;
	char value;
	void set_token(char);
	
};




void Token::set_token(char value1)
{
	value = value1;

	if( value == '+')
	{
		type = PLUS;
	}
	
	else if( isNumber(value) )
	{
		type = INTEGER;
	}
	
	else if( value == '\0')
	{
		type = EOF;	
	}
	
	else
	{
		std::cout << "Error in input";
		return;
	}

	
}



class Interpretor
{
	public:
	//int pos;
	std::string text;
	//Token token;
	Interpretor(std::string);
};

Interpretor::Interpretor(std::string input)
{
	std::string null;
	null = "\0";
	input = input + null;
	Token * obj;
	obj = new Token [input.size()];	
		
	

		for(int i = 0; i < input.size(); i++ )
		{
		obj[i].set_token(input[i]);
		
		}

 	std::cout << obj[0].type;
}



int main()
{
 	std::string input;	
	std::cout << "Enter a string\n";
	std::cin >> input;
	Interpretor obj(input);
	
	return 0;
}
