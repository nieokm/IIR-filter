#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
std::vector<double> x;
std::vector<double> y;


//functions that behave like array z[ind], but return 0 for ind<0
double y_ (int ind) {
	if(ind<0) {return 0;}
	else { return y[ind];}
}

double x_ (int ind) {
	if(ind<0) {return 0;}
	else { return x[ind];}
}


//filter function
void filter(const std::vector<double> &x, const std::vector<double> b, const std::vector<double> a) {


	for(int i=0; i < x.size(); i++) {
		y.push_back(0);
		//add b*x
		for(int j=0; j < b.size(); j++)
			y[i]+=b[j]*x_(i-j);
		//add a*y
		for(int j=0; j < a.size(); j++)
			y[i]-=a[j]*y_(i-j-1);
	}
	
	//write down to a file
	std::ofstream outputFile("output.txt");
	for(int i=0;i<y.size();i++)
		outputFile<<y[i]<<"\n";
	
}


int main()
{
	//write down params a,b
	std::cout << "Difference equation of the filter has the form y[n]=b0*x[n]+...+bp*x[n-p]-a1*y[n-1]-...-aq*y[n-q]\n" << std::endl;
	std::vector<double> b;
	std::vector<double> a;
	std::string line;
	double number;
	std::cout << "Write down 'b' vector:" << std::endl;
	std::getline(std::cin, line);
	std::istringstream stream_b(line);
	while (stream_b >> number)
        b.push_back(number);
    line.clear();
    
	std::cout << "Write down 'a' vector:" << std::endl;
	std::getline(std::cin, line);
	std::istringstream stream_a(line);
	while (stream_a >> number) 
        a.push_back(number); 
    line.clear();
    
    
    //open file and create vector x
    std::ifstream inputFile("input.txt");
    
    if (inputFile) {
    	double value;
    	
    	while(inputFile >> value) 
    		x.push_back(value);
		}
	else {
		std::cout << "Error reading input.txt";
		return 0;
	}	
		
	filter(x,b,a);
    
	return 0;
}
