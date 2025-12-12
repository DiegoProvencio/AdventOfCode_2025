#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int contarBotones(const string& line) 
{
    int c1 = line.find((char)((int)123));
    int count = 0;
    for (int i = 0; i < c1; i++) 
    {
        if (line[i] == '(')
            count++;
    }
    return count;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	string line;
    double total = 0; 
    while (getline(cin, line))
    {
    	// SACO JOLTAGE
    	vector<int> joltage;
    	string j;

		size_t c1 = line.find('{');
		size_t c2 = line.find('}');
		
	    j = line.substr(c1 + 1, c2 - c1 - 1);
	    
	    for (char& c : j) // Quito espacios
    		if (c == ',') c = ' ';
    		
	    stringstream jj(j);
	    int a;
	    while(jj >> a)
	    	joltage.push_back(a);
		
		// SACO LOS BOTONES
		int n = contarBotones(line);
		
		stringstream ss(line);
        vector<vector<int>> boton(n, vector<int>(joltage.size(), 0));
        
        string basura;
        ss >> basura;
        
        string l;
        int cont = 0;
        while (ss >> l)
        {
        	if (l[0] == '{')
        		break;
        		
            l = l.substr(1, l.size() - 2);
            
            for (char& c : l)
    			if (c == ',') c = ' ';

            stringstream bb(l);
            
            while(bb >> a)
            	boton[cont][a] = 1;
            
            cont++;
        } // FIN LECTURA DE BOTONES
		
		n = boton.size();
		int m = joltage.size();
		
		MatrixXd A(n, m);
		
		for (int i = 0; i < n; i++)
		    for (int j = 0; j < m; j++)
		        A(i,j) = boton[i][j];
		
		VectorXd B(m);
		for (int i = 0; i < m; i++)
			B(i) = joltage[i];
			
		MatrixXd AT = A.transpose();
		VectorXd x = AT.colPivHouseholderQr().solve(B);
		x = x.cwiseMax(0);
		    
	    //cout << x << " ";
	    //cout << endl;
	    total = total + x.sum();
	    //cout << "Suma de x: " << x.sum() << endl;
    }

    cout << "TOTAL: " << total;

    return 0;
}
