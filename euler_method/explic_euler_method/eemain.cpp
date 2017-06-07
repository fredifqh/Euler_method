#include <unistd.h>
#include <bits/stdc++.h>
#include "eeuler.hpp"

using namespace std;

void showhelpinfo(char *s);

int main(int argc, char *argv[])

{
	int option;
	
	if(argc != 9)
	{
		showhelpinfo(argv[0]);
		exit(1);
	}
	double p = 0, x = 0, t0 = 0, t = 0;

 	/*La cadena "dhvf:c::" indica que d, h y v no tienen argumentos, f tiene un
        argumento requerido (por eso los dos puntos 'f:') y c tiene un argumento opcional
        (de ahi los dobles dos puntos 'c::')*/

	while ((option = getopt(argc, argv, "hp:x:a:b:")) != EOF){  
	switch (option) {
			case 'h':
        		showhelpinfo(argv[0]);
        	return 1;
			case 'p' :  p = atof(optarg);
			break;
			case 'x' :  x = atof(optarg);
			break;
			case 'a' :  t0 = atof(optarg);
			break;
			case 'b' :  t = atof(optarg); 
			break;
        	default: showhelpinfo(argv[0]);
            break; 
        }
    } 
	cout.precision(5); //for precision
    cout.setf(ios::fixed);
	
// ################### main part #####################################
	vector<vector<double> > m = eeuler(p, x, t0, t); // Calling eeuler function
     for (unsigned int i = 0; i < m.size(); i++) { // i para fila             
         for (unsigned int j = 0; j < m[i].size(); j++) // j para columna
             cout << m[i][j] << '\t';    
         cout << endl;
     }
// ###################################################################
return 0;
}

void showhelpinfo(char *s)
{
	cout<<"Usage:   "<<s<<" [-option] [argument]"<<endl;
	cout<<"option:  "<<"-h  show help information"<<endl;
	cout<<"         "<<"-p  size of step"<<endl;
	cout<<"         "<<"-x  initial condition"<<endl;
	cout<<"         "<<"-a  interval initial value"<<endl;
	cout<<"         "<<"-b  interval final value"<<endl;
	cout<<"example: "<<s<<" -p num -x num -a num -b num"<<endl;
}